/* Copyright (c) 2018 - present, VE Software Inc. All rights reserved
 *
 * This source code is licensed under Apache 2.0 License
 *  (found in the LICENSE.Apache file in the root directory)
 */

#include "meta/processors/CreateSpaceProcessor.h"

namespace nebula {
namespace meta {

void CreateSpaceProcessor::process(const cpp2::CreateSpaceReq& req) {
    guard_ = std::make_unique<std::lock_guard<std::mutex>>(
                                    BaseProcessor<cpp2::ExecResp>::lock_);
    auto spaceRet = spaceExist(req.get_space_name());
    if (spaceRet.ok()) {
        resp_.set_id(to(spaceRet.value(), IDType::SPACE));
        resp_.set_code(cpp2::ErrorCode::E_SPACE_EXISTED);
        onFinished();
        return;
    }
    CHECK_EQ(Status::SpaceNotFound(), spaceRet.status());
    auto ret = allHosts();
    if (!ret.ok()) {
        resp_.set_code(cpp2::ErrorCode::E_NO_HOSTS);
        onFinished();
        return;
    }
    auto spaceId = autoIncrementId();
    auto hosts = ret.value();
    auto replicaFactor = req.get_replica_factor();
    std::vector<kvstore::KV> data;
    data.emplace_back(MetaUtils::spaceKey(spaceId),
                      MetaUtils::spaceVal(req.get_parts_num(),
                                          replicaFactor,
                                          req.get_space_name()));
    for (auto partId = 1; partId <= req.get_parts_num(); partId++) {
        auto partHosts = pickHosts(partId, hosts, replicaFactor);
        data.emplace_back(MetaUtils::partKey(spaceId, partId),
                          MetaUtils::partVal(partHosts));
    }
    resp_.set_code(cpp2::ErrorCode::SUCCEEDED);
    resp_.set_id(to(spaceId, IDType::SPACE));
    doPut(std::move(data));
}

std::vector<nebula::cpp2::HostAddr>
CreateSpaceProcessor::pickHosts(PartitionID partId,
                                const std::vector<nebula::cpp2::HostAddr>& hosts,
                                int32_t replicaFactor) {
    auto startIndex = partId;
    std::vector<nebula::cpp2::HostAddr> pickedHosts;
    for (decltype(replicaFactor) i = 0; i < replicaFactor; i++) {
        pickedHosts.emplace_back(hosts[startIndex++ % hosts.size()]);
    }
    return pickedHosts;
}

}  // namespace meta
}  // namespace nebula

nebula_add_library(
    graph_obj OBJECT
    GraphFlags.cpp
    GraphService.cpp
    SessionManager.cpp
    PasswordAuthenticator.cpp
    ExecutionEngine.cpp
    ExecutionContext.cpp
    PermissionCheck.cpp
    ExecutionPlan.cpp
    Executor.cpp
    TraverseExecutor.cpp
    SequentialExecutor.cpp
    UseExecutor.cpp
    GoExecutor.cpp
    PipeExecutor.cpp
    CreateEdgeExecutor.cpp
    AlterEdgeExecutor.cpp
    DescribeEdgeExecutor.cpp
    CreateTagExecutor.cpp
    AlterTagExecutor.cpp
    DropTagExecutor.cpp
    DropEdgeExecutor.cpp
    DescribeTagExecutor.cpp
    InsertVertexExecutor.cpp
    UpdateVertexExecutor.cpp
    InsertEdgeExecutor.cpp
    CreateEdgeIndexExecutor.cpp
    DropEdgeIndexExecutor.cpp
    DescribeEdgeIndexExecutor.cpp
    RebuildEdgeIndexExecutor.cpp
    CreateTagIndexExecutor.cpp
    DropTagIndexExecutor.cpp
    DescribeTagIndexExecutor.cpp
    RebuildTagIndexExecutor.cpp
    UpdateEdgeExecutor.cpp
    AssignmentExecutor.cpp
    InterimResult.cpp
    VariableHolder.cpp
    CreateSpaceExecutor.cpp
    DropSpaceExecutor.cpp
    DescribeSpaceExecutor.cpp
    ShowExecutor.cpp
    YieldExecutor.cpp
    DownloadExecutor.cpp
    OrderByExecutor.cpp
    IngestExecutor.cpp
    ConfigExecutor.cpp
    BalanceExecutor.cpp
    SchemaHelper.cpp
    FetchVerticesExecutor.cpp
    FetchEdgesExecutor.cpp
    FetchExecutor.cpp
    SetExecutor.cpp
    MatchExecutor.cpp
    DeleteVerticesExecutor.cpp
    DeleteEdgesExecutor.cpp
    FindPathExecutor.cpp
    LimitExecutor.cpp
    GroupByExecutor.cpp
    ReturnExecutor.cpp
    CreateSnapshotExecutor.cpp
    DropSnapshotExecutor.cpp
    AdminJobExecutor.cpp
    LookupExecutor.cpp
    UserExecutor.cpp
    PrivilegeExecutor.cpp
)
nebula_add_subdirectory(test)


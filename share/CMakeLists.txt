message("-- Installing share/workspaces")
install (DIRECTORY
    workspaces
    DESTINATION ${AU4_SHARE_NAME}${AU4_INSTALL_NAME}
    PATTERN ".*" EXCLUDE
    )
message("   to ${AU4_SHARE_NAME}${AU4_INSTALL_NAME}")

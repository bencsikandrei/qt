# Directories variables

# project binary dir
set(PROJECT_BIN_DIR $ENV{PROJECT_BINARY_DIR})
if(NOT PROJECT_BIN_DIR)
    set(PROJECT_BIN_DIR bin)
endif()

# resources directory
set(PROJECT_RESOURCE_DIR resources)

# qml directory
set(PROJECT_QML_DIR qml)

# qml destination directory
set(PROJECT_QML_DEST_DIR ${PROJECT_BIN_DIR}/${PROJECT_RESOURCE_DIR})

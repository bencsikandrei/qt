file(GLOB SRCS *.cpp)

ADD_EXECUTABLE(testposition ${SRCS})

TARGET_LINK_LIBRARIES(testposition
    common
    libgtest
    libgmock
)

add_test(NAME testposition
         COMMAND testposition)

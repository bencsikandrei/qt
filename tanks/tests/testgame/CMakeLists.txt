file(GLOB SRCS *.cpp)

ADD_EXECUTABLE(testtank ${SRCS})

TARGET_LINK_LIBRARIES(testtank
    game
    common
    libgtest
    libgmock
)

add_test(NAME testtank
         COMMAND testtank)

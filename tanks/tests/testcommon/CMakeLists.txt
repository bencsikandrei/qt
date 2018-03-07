file(GLOB SRCS *.cpp)

set(libs
        common
)
add_unit_test(testposition ${libs})

set(libs
    common
)
add_unit_test(testvector2d ${libs})

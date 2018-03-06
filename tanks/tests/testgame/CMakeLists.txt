file(GLOB SRCS *.cpp)

set(libs
    game
    common
    )
add_unit_test(testtank ${libs})

set(libs
    game
    common
    )
add_unit_test(testbullet ${libs})

set(libs
    game
    common
    )
add_unit_test(testscore ${libs})

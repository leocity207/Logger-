include(GoogleTest)

add_executable(log_test 
    main.cpp
    log_test.cpp
)

gtest_add_tests(TARGET      log_test
                TEST_SUFFIX .noArgs
                TEST_LIST   noArgsTests
)

target_link_libraries(
  log_test
  GTest::gtest_main
  log
  utils
  system
)
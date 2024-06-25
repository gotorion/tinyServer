add_executable(test_utility test_task_queue.cpp)

message("------ Target: test_utility")

target_link_libraries(test_utility 
    utility 
    GTest::gtest_main
)
include(GoogleTest)
gtest_discover_tests(test_utility)
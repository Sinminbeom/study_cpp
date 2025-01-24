cmake_minimum_required(VERSION 3.10)
project(study_cpp)

# C++ 표준 설정
set(CMAKE_CXX_STANDARD 17)

# Debug 모드 설정
set(CMAKE_BUILD_TYPE Debug)

# 디렉터리 설정
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(TEST_DIR ${CMAKE_SOURCE_DIR}/test)

# 소스 파일
set(SRC_FILES
    ${SRC_DIR}/core/task_queue/task_queue.cpp
    ${SRC_DIR}/core/calculator/calculator.h
)

# Include 디렉터리
include_directories(${SRC_DIR})

# Main 실행 파일
add_executable(${PROJECT_NAME} test.cpp ${SRC_FILES})

# Google Test 설정
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Calculator 테스트
add_executable(CalculatorTest
    ${TEST_DIR}/core/calculator/calculator_test.cpp
    ${SRC_FILES}
)

# TaskQueue 테스트
add_executable(TaskQueueTest
    ${TEST_DIR}/core/task_queue/task_queue_test.cpp
    ${SRC_FILES}
)

# Google Test와 링크
target_link_libraries(CalculatorTest ${GTEST_LIBRARIES} pthread)
target_link_libraries(TaskQueueTest ${GTEST_LIBRARIES} pthread)

# 테스트 등록
enable_testing()
add_test(NAME CalculatorUnitTest COMMAND CalculatorTest)
add_test(NAME TaskQueueUnitTest COMMAND TaskQueueTest)

#include "core/task_queue/task_queue.h"
#include <gtest/gtest.h>
#include <iostream>

// 테스트 케이스: TaskQueue 생성 및 기본 동작
TEST(TaskQueueTest, AddAndExecuteTasks) {
    TaskQueue queue;

    // Task 추가
    queue.AddTask([]() { std::cout << "Task 1 executed.\n"; });
    queue.AddTask([]() { std::cout << "Task 2 executed.\n"; });
    queue.AddTask([]() { std::cout << "Task 3 executed.\n"; });

    // Task 하나씩 실행
    testing::internal::CaptureStdout();
    queue.ExecuteNextTask();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Task 1 executed.\n");

    // 남은 Task 개수 확인
    EXPECT_FALSE(queue.IsEmpty());
}

// 테스트 케이스: 모든 Task 실행
TEST(TaskQueueTest, ExecuteAllTasks) {
    TaskQueue queue;

    // Task 추가
    queue.AddTask([]() { std::cout << "Task A executed.\n"; });
    queue.AddTask([]() { std::cout << "Task B executed.\n"; });

    // 모든 Task 실행
    testing::internal::CaptureStdout();
    queue.ExecuteAll();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Task A executed.\nTask B executed.\n");

    // TaskQueue가 비었는지 확인
    EXPECT_TRUE(queue.IsEmpty());
}

// 사용자 정의 main 함수
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


/*
// 테스트 케이스: 비어있는 Queue 동작 확인
TEST(TaskQueueTest, EmptyQueueBehavior) {
    TaskQueue queue;

    // 비어있는 Queue에서 Task 실행 시도
    EXPECT_NO_THROW(queue.ExecuteNextTask());
    EXPECT_NO_THROW(queue.ExecuteAll());

    TaskQueue queue;

    // Add tasks to the queue
    queue.AddTask([]() { std::cout << "Task 1 executed.\n"; });
    queue.AddTask([]() { std::cout << "Task 2 executed.\n"; });
    queue.AddTask([]() { std::cout << "Task 3 executed.\n"; });

    // Execute tasks
    std::cout << "Executing tasks one by one:\n";
    while (!queue.IsEmpty()) {
        queue.ExecuteNextTask();
    }

    // Re-add tasks
    queue.AddTask([]() { std::cout << "New Task 1 executed.\n"; });
    queue.AddTask([]() { std::cout << "New Task 2 executed.\n"; });

    std::cout << "\nExecuting all tasks at once:\n";
    queue.ExecuteAll();
}
*/

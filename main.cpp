#include "core/task_queue/task_queue.h"
#include <iostream>
#include <string>
#include <memory>

#pragma region IN_OUT_DEFINITIONS

#define OUT

void Compute(const int* input_data, OUT int* output_result) {
    if (input_data && output_result) {
        *output_result = (*input_data) * 2;
    }
}

void Update(OUT int* value) {
    if (value) {
        *value += 10;
    }
}

#define DTO struct

DTO UserDTO {
    std::string name_;
    int age_;

    UserDTO(const std::string& name, int age) : name_(name), age_(age) {}
};

void ProcessUser(const std::shared_ptr<UserDTO>& user) {
    user->name_ = "ShinMinBeom";
    user->age_ += 1;
}

#pragma endregion

int main() {

    int* nums = new int[5];

    return 0;

    /*
    std::shared_ptr<UserDTO> user = std::make_shared<UserDTO>("mbshin", 30);

    ProcessUser(user);

    std::cout << "Name: " << user->name_ << ", Age: " << user->age_ << std::endl;    

    */

    /*
    int input = 5;
    int result = 0;

    Compute(&input, &result);
    std::cout << "Compute result: " << result << std::endl;

    Update(&result);
    std::cout << "Updated result: " << result << std::endl;
    */

    /*
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
    */

}
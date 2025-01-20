#include "task_queue.h"
#include <iostream>
#include <stdexcept>

void TaskQueue::AddTask(const std::function<void()>& task) {
    tasks.push_back(task);
}

void TaskQueue::ExecuteNextTask() {
    if (tasks.empty()) {
        // throw std::runtime_error("No tasks in the queue to execute.");
        return;
    }
    auto task = tasks.front();
    task();
    tasks.erase(tasks.begin());
}

bool TaskQueue::IsEmpty() const {
    return tasks.empty();
}

size_t TaskQueue::Size() const {
    return tasks.size();
}

void TaskQueue::Clear() {
    tasks.clear();
}

void TaskQueue::ExecuteAll() {
    while (!tasks.empty()) {
        ExecuteNextTask();
    }
}
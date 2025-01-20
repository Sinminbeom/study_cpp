// Copyright [2025] <mbshin>

#ifndef CPP_STUDY_SRC_CORE_TASK_QUEUE_TASK_QUEUE_H_
#define CPP_STUDY_SRC_CORE_TASK_QUEUE_TASK_QUEUE_H_

#include <vector>
#include <functional>

#define Interface class

Interface ITaskQueue {
 public:
    virtual void AddTask(const std::function<void()>& task) = 0;
    virtual void ExecuteNextTask() = 0;
    virtual bool IsEmpty() const = 0;
    virtual size_t Size() const = 0;
    virtual void Clear() = 0;
    virtual void ExecuteAll() = 0;
};

class TaskQueue: public ITaskQueue {
 private:
    std::vector<std::function<void()>> tasks;

 public:
    void AddTask(const std::function<void()>& task);
    void ExecuteNextTask();
    bool IsEmpty() const;
    size_t Size() const;
    void Clear();
    void ExecuteAll();
};

#endif  // CPP_STUDY_SRC_CORE_TASK_QUEUE_TASK_QUEUE_H_

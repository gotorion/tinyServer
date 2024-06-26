#include "task_queue.h"
#include <iostream>
namespace TinyServer::Utility {

TaskQueue::TaskQueue(std::size_t queueSize) : size_(queueSize), taskQueue_() {
  std::cout << "size_ = " << size_ << std::endl;
}

void TaskQueue::PushTask(Task&& task) {
  std::unique_lock lock(mutex_);
  std::cout << size_ << " " << taskQueue_.size() << std::endl;
  while (Full()) {
    std::cout << "Full wait" << std::endl;
    notFull_.wait(lock);
  }
  taskQueue_.push(task);
  notEmpty_.notify_one();
}

std::optional<Task> TaskQueue::PopTask() {
  std::unique_lock lock(mutex_);
  while (Empty() && !isExit_) {
    // when WakeUp method was called, if we just notify all, running thread found no task then will block on next loop
    // so we need to tell threads thats we are going to exit, there is no need to block
    notEmpty_.wait(lock);
  }
  if (isExit_) {
    return std::nullopt;
  }
  auto task = taskQueue_.front();
  taskQueue_.pop();
  notFull_.notify_one();
  return task;
}

void TaskQueue::WakeUp() {
  isExit_ = true;
  notEmpty_.notify_all();
}

bool TaskQueue::Empty() {
  return taskQueue_.empty();
}

bool TaskQueue::Full() {
  return taskQueue_.size() == size_;
}

}  // namespace TinyServer::Utility

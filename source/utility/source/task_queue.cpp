#include "task_queue.h"
namespace TinyServer::Utility {
void TaskQueue::PushTask(Task&& task) {
  std::unique_lock lock(mutex_);
  taskQueue_.push(task);
}

Task TaskQueue::PopTask() {
  std::unique_lock lock(mutex_);
  auto task = taskQueue_.front();
  taskQueue_.pop();
  return task;
}

bool TaskQueue::Empty() {
  std::unique_lock lock(mutex_);
  return taskQueue_.empty();
}

}  // namespace TinyServer::Utility

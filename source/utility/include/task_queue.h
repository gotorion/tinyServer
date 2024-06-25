#ifndef _TASK_QUEUE_H_
#define _TASK_QUEUE_H_
#include <condition_variable>
#include <functional>
#include <mutex>
#include <queue>

namespace TinyServer::Utility {

using Task = std::function<void()>;

class TaskQueue {
 public:
  explicit TaskQueue() = default;
  ~TaskQueue() = default;

 public:
  void PushTask(Task&& task);
  Task PopTask();
  bool Empty();

 private:
  std::mutex mutex_;
  std::condition_variable cv_;
  std::queue<Task> taskQueue_;
};

}  // namespace TinyServer::Utility
#endif
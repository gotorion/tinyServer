#ifndef _TASK_QUEUE_H_
#define _TASK_QUEUE_H_
#include <condition_variable>
#include <functional>
#include <mutex>
#include <optional>
#include <queue>

namespace TinyServer::Utility {

using Task = std::function<void()>;

class TaskQueue {
 public:
  explicit TaskQueue() = default;
  TaskQueue(std::size_t queSize);
  ~TaskQueue() = default;

 public:
  void PushTask(Task&& task);
  std::optional<Task> PopTask();
  bool Empty();
  bool Full();
  void WakeUp();

 private:
  std::size_t size_;
  std::mutex mutex_{};
  std::condition_variable notEmpty_{};
  std::condition_variable notFull_{};
  std::queue<Task> taskQueue_{};
  bool isExit_{false};
};

}  // namespace TinyServer::Utility
#endif
#ifndef _THREAD_POOL_H_
#define _THREAD_POOL_H_
#include <thread>
#include <vector>
#include "task_queue.h"
namespace server::pool {
class ThreadPool {
 public:
  ThreadPool(std::size_t threadNum, std::size_t queueSize);
  ~ThreadPool();

  void Start();
  void Stop();
  void PushTask(Task&& task);

 private:
  void DoTask();

 private:
  std::vector<std::thread> threads_;
  TaskQueue taskQueue_;
  bool isExit_;
};

}  // namespace server::pool

#endif
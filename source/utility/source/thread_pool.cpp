#include "thread_pool.h"
namespace TinyServer::Utility {

ThreadPool::ThreadPool(std::size_t threadNum, std::size_t queueSize)
    : threads_(), taskQueue_(TaskQueue(queueSize)), isExit_{false} {
  threads_.reserve(threadNum);
}

void ThreadPool::Start() {
  for (std::size_t idx = 0; idx < threads_.capacity(); ++idx) {
    threads_.push_back(std::thread{&ThreadPool::DoTask, this});
  }
}

void ThreadPool::PushTask(Task&& task) {
  taskQueue_.PushTask(std::move(task));
}

void ThreadPool::DoTask() {
  while (!isExit_) {
    auto task = taskQueue_.PopTask();
    if (task) {
      task.value()();
    }
  }
}

void ThreadPool::Stop() {
  while (!taskQueue_.Empty()) {
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }

  isExit_ = true;
  // maybe thread was block on PopTask before isExit set true so here we need wake them all
  taskQueue_.WakeUp();
  for (auto& thread : threads_) {
    if (thread.joinable()) {
      thread.join();
    }
  }
}

}  // namespace TinyServer::Utility
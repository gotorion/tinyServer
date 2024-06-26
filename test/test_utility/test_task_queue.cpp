#include <gtest/gtest.h>
#include "task_queue.h"

using TinyServer::Utility::Task;
using TinyServer::Utility::TaskQueue;

TEST(TestTaskQueue, PushTask) {
  TaskQueue queue(10);
  auto task = [&]() -> void {
  };
  queue.PushTask(task);

  EXPECT_FALSE(queue.Empty());
}

TEST(TestTaskQueue, PopTask) {
  TaskQueue queue;
  Task task = []() -> void {
  };
  queue.PushTask(std::move(task));
  queue.PopTask();

  EXPECT_TRUE(queue.Empty());
}
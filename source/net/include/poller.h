#pragma once
#ifndef _EPOLL_H_
#define _EPOLL_H_
namespace tiny::server::net {

class Poller {
 public:
  void add_fd(int fd);
  void delelete_fd(int fd);

 private:
};

}  // namespace tiny::server::net
#endif

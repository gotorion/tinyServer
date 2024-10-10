#include "socket.h"
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

namespace tiny::server::net {
Socket::Socket() {
  fd_ = ::socket(AF_INET, SOCK_STREAM, 0);
  if (fd_ < 0) {
    ::perror("Socket error");
  }
}

Socket::Socket(int fd) : fd_(fd) {}

Socket::~Socket() {
  ::close(fd_);
}

int Socket::get_fd() const {
  return fd_;
}

}  // namespace tiny::server::net

#include "socket.h"
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

namespace TinyServer::Net {
Socket::Socket() {
  sockfd_ = ::socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd_ < 0) {
    ::perror("Socket error");
  }
}

Socket::Socket(int fd) : sockfd_(fd) {}

Socket::~Socket() {
  ::close(sockfd_);
}

}  // namespace TinyServer::Net
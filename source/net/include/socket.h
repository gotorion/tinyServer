#ifndef _SOCKET_H_
#define _SOCKET_H_
#include <string>
namespace tiny::server::net {
class Socket {
 public:
  explicit Socket();
  explicit Socket(int fd);
  virtual ~Socket();

 public:
  int get_fd() const;

 private:
  int fd_{};
};

}  // namespace tiny::server::net
#endif
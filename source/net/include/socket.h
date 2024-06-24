#ifndef _SOCKET_H_
#define _SOCKET_H_
namespace TinyServer::Net {
class Socket {
public:
  explicit Socket();
  explicit Socket(int fd);
  ~Socket();

private:
  int sockfd_;
};

} // namespace TinyServer::Net
#endif
#ifndef SERVER_H_
#define SERVER_H_
#pragma once

namespace udp {

#define BUFSIZE 512

class server { 
public:

	struct recvbuf {
		char buf[BUFSIZE];
	};

	explicit server(
			unsigned int listen_port)
		:
		listen_port_(listen_port)
		,sock_(-1)
   	{}


	bool init();
	bool cleanup();

	bool receive(recvbuf* out);


private:
	unsigned int listen_port_;  // Port to listen on 

	int sock_;					// Fd to socket created.

};


} // namespace
#endif

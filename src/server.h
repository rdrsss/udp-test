#ifndef SERVER_H_
#define SERVER_H_
#pragma once

namespace udp {

class server { 
public:
	explicit server(
			unsigned int listen_port, 
			unsigned int buf_len) : 
		listen_port_(listen_port)
		,buffer_len_(buf_len)
		,sock_(-1)
   	{}


	bool init();
	bool cleanup();

	bool receive(char* buf, unsigned int buf_len);


private:
	unsigned int listen_port_;  // Port to listen on 
	unsigned int buffer_len_;	// Buffer length to receive on.

	int sock_;					// Fd to socket created.

};


} // namespace
#endif

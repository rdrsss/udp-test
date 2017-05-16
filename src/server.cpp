
#include "server.h"

#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>

namespace udp {

bool server::init() {
	// Create socket
	sock_ = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (sock_ == -1) {
		// TODO :: log error
		return false;
	}
		
	// Setup socket address
	sockaddr_in addr;
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = listen_port_;
	// TODO :: if address is given to bind to 
	addr.sin_addr.s_addr = htonl(INADDR_ANY);

	// Bind to socket
	if(bind(sock_, reinterpret_cast<sockaddr*>(&addr), sizeof(addr)) == -1) {
		// TODO :: log error
		return false;
	}

	return true;
}

bool server::cleanup() {
	if (close(sock_) == -1) {
		// TODO :: log error
		return false;
	}

	return true;
}


bool server::receive(char* buf, unsigned int buf_len) {
	if (sock_ == -1) 
		return false;


	
	return true;
}


} // namespace


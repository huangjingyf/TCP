// Note:TCPClient
// Author:huangjingyf
// Time:2019-11-15
#pragma once
#include <string>
#include <vector>
namespace Hikvsion
{
    namespace Net
    {
		typedef int(*TCPClientGetBodyLengthCallback)(const std::string& str_head);

        // client connection parameter
        struct TcpClientConnectParam
        {
            std::string str_server_ip;
            unsigned short u_server_port = 0;

			bool ssl = false;
			// timeout
            int connection_timeout = 3000;
            int send_timeout = 3000;
            int receive_timeout = 3000;
        };

		struct TcpClientReplayParam
		{
			TCPClientGetBodyLengthCallback tcp_client_getbody_length; // get body based on header 
			std::string str_head; //  OUT
			std::string str_body; //  OUT
		};


        // send data to server and wait reply
        int SyncTcpClientSend(TcpClientReplayParam& reply_data, const std::string& str_send_data, const TcpClientConnectParam& client_param);

		int SyncTcpClientSend(TcpClientReplayParam& reply_data, const std::vector<std::string>& str_send_data, const TcpClientConnectParam& client_param);

		// send data, no wait
		int AysnTcpClientSend(const std::string& str_send_data, const TcpClientConnectParam& client_param);

    }
}

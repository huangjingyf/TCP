// solved tcp sticky packet problem
#pragma once
#include <string>
namespace Hikvision
{
	namespace Net
	{
		typedef int(*TCPServerGetBodyLengthCallback)(const std::string& str_head);

		struct TCPCallBackParam
		{
			// out
			int param_type = 0; // 0-data, 1-connect, 2-disconnect
			long server_hand = 0; // server handle
			std::string str_header; // data header
			std::string str_body; // data body
			std::string client_ip;// client ip address

			// in, the user can set str_reply, the API will send the string to client auto					 
			std::string str_reply; // 
		};


		// tcp server callback
		// if you want to send data back to client, setthe str_reply
		typedef void(*SyncTCPServerCallback)(TCPCallBackParam& call_back_param, void* ptr_user_data);

		// start parameter
		struct TcpServerParam
		{
			std::string str_bind_ip = "0.0.0.0";
			unsigned short u_bind_port = 0;
			SyncTCPServerCallback sync_tcp_server_callback;
			
			int head_len = 0; 
			TCPServerGetBodyLengthCallback getbody_length;

			void* ptr_user_data;
		};

		// start server
		// the first time, the API will call getbody_length callback function
		// you will receive header depends on the head_len
		// you need return the body length based on header data
		// then the API will call the sync_tcp_server_callback function 
		// give you then body and header
		// if you want to reply data to cilent, set str_reply is enough, don't need tcp::send
		long SyncTcpStartServer(const TcpServerParam& tcp_server_param);

		// stop server
		int SyncTcpStopServer(long server_handle);
	}
}


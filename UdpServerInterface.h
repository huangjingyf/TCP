// Note:UDPServer对外接口层
#pragma once

#include <cstring>
#include <string>
namespace Bee
{
    namespace Net
    {
		// 
		struct UDPCallBackParam
		{
			int param_type = 0; // 0:data，1:connected，2:disconnect
			long server_hand = 0; // server handle
			std::string str_body; // body
			std::string client_ip;// client address
			int client_port = 0; // client port

			// IN
			std::string str_reply; // reply to client, set empty if don't need reply data to client
		};
		

		typedef void(*UdpServerCallback)(UDPCallBackParam& call_back_param,  void* ptr_user_data);

		// 启动server参数，后续可以增加部分参数做拆包规则
		struct UdpServerParam
		{
			std::string str_bind_ip="0.0.0.0";
			unsigned short u_bind_port = 0;
			UdpServerCallback udb_server_callback;
			void* ptr_user_data;
		};
       
        // start udp server
		long SyncUdpStartServer(const UdpServerParam& tcp_server_param);

        // stop udp server
        int SyncUdpStopServer(long server_handle);
    }
}


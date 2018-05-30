//Server is in the STE and receives requests from the Client
//Basically the reverse of the traditional use of client and server

#include "communication_information.h"
#include "sp_ste_server.h"

int main(int argc, char** argv)
{
   run_rpc_server(COMMUNICATION_ADDRESS);
   //run_rpc_server("0.0.0.0:50051");

   return 0;
}


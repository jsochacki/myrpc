//Client is in the controller and issues requests to the server
//Basically the reverse of the traditional use of client and server

#include "sp_ste_client.h"
#include "rpc_structures.h"
#include "communication_information.h"

int main(int argc, char** argv)
{
   sp_ste_control_class_client
      client_object(
         grpc::CreateChannel(COMMUNICATION_ADDRESS,
                             grpc::InsecureChannelCredentials()
                            )
                   );

   std::cout << "client saw server say ther area " << client_object.loopback()
             << " parameters" <<std::endl;

   return 0;
}

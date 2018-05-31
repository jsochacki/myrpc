//Client is in the controller and issues requests to the server
//Basically the reverse of the traditional use of client and server

#include "communication_information.h"
#include "sp_ste_client.h"
#include "sp_ste_typedefs.h"

int main(int argc, char** argv)
{
   std::string filename("/root/Desktop/git/myrpc/Eclipse/grpc/Debug/testfile.txt");

   SPSingleMeasurementParams teststruct;

   std::cout << std::boolalpha << teststruct.load_config_file(filename) << std::endl;

   sp_ste_control_class_client
      client_object(
         grpc::CreateChannel(COMMUNICATION_ADDRESS,
                             grpc::InsecureChannelCredentials()
                            )
                   );

   std::cout << "client saw server say there are " << client_object.loopback(teststruct)
             << " parameters" <<std::endl;

   return 0;
}

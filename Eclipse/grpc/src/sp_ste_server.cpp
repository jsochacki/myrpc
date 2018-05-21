
#include "sp_ste_server.h"
#include "rpc_structures.h"

////I have no constructor at this point
//sp_ste_control_class_server::sp_ste_control_class_server(const //}

grpc::Status
   sp_ste_control_class_server::loopback(grpc::ServerContext *context,
                                  const sp::ste::set_parameters *values_received,
                                  sp::ste::parameter_values *values_returned)
{
   sp::ste::num_params local_num_params = values_received->num_params();
   int parameter_state_count = local_num_params.state_count();

   std::cout << "there are " << parameter_state_count << " Parameters!" << std::endl;
   std::cout << "and type is " << local_num_params.GetTypeName() << std::endl;

   values_returned->mutable_num_params()->set_state_count(parameter_state_count);

   return grpc::Status::OK;
}

void run_rpc_server(const char *ip_address_to_listen_on)
{
   std::string sp_ste_rpc_server_ip_address_to_listen_on(ip_address_to_listen_on);

   sp_ste_control_class_server sp_ste_cc_object;

   grpc::ServerBuilder server_construction_object;

   server_construction_object.\
      AddListeningPort(sp_ste_rpc_server_ip_address_to_listen_on,
                       grpc::InsecureServerCredentials());

   server_construction_object.RegisterService(&sp_ste_cc_object);

   std::unique_ptr<grpc::Server> sp_ste_control_server(server_construction_object.BuildAndStart());

   std::cout << "sp ste server listening on port "
             << ip_address_to_listen_on << std::endl;

   sp_ste_control_server->Wait();
}

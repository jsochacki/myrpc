//Server is in the STE and receives requests from the Client
//Basically the reverse of the traditional use of client and server

#include <iostream>
#include <memory>
#include <string>

#include <grpcpp/grpcpp.h>

/*
#include <grpcpp/server.h>
#include <grpcpp/server_builder.h>
#include <grpcpp/server_context.h>
#include <grpcpp/security/server_credentials.h>
*/

#include "sp_ste.grpc.pb.h"

class sp_ste_control_class final : public sp::ste::sp_ste_control::Service
{
   public:
      //I have no constructor at this point
      //explicit sp_ste_control_class(const std::string &db);
      grpc::Status
         loopback(grpc::ServerContext *context,
                  const sp::ste::set_parameters *values_received,
                  sp::ste::parameter_values *values_returned)
         override;
//      grpc::Status
//         check_current_values(grpc::ServerContext *context,
//                              const sp::ste::null_message *null_value,
//                              sp::ste::parameter_values *current_values)
//         override;
//      grpc::Status
//         issue_new_values_and_read_old(grpc::ServerContext *context,
//                                       const sp::ste::set_parameters *new_parameters_to_set,
//                                       sp::ste::parameter_values *old_values)
//         override;
//      grpc::Status
//         issue_new_values_and_read_new(grpc::ServerContext *context,
//                                       const sp::ste::set_parameters *new_parameters_to_set,
//                                       sp::ste::parameter_values *new_values)
//         override;
};

void run_rpc_server(std::string *);

////I have no constructor at this point
//sp_ste_control_class::sp_ste_control_class(const std::string &db)
//{
//}

grpc::Status
   sp_ste_control_class::loopback(grpc::ServerContext *context,
                                  const sp::ste::set_parameters *values_received,
                                  sp::ste::parameter_values *values_returned)
{
   auto local_num_params = values_received->num_params();
   //TODO change type of auto later for correc ttype
   auto parameter_count = local_num_params.count();

   std::cout << "there are " << parameter_count << " Parameters!" << std::endl;
   std::cout << "and type is " << local_num_params.GetTypeName() << std::endl;

   return grpc::Status::OK;
}

void run_rpc_server(const char *ip_address_to_listen_on)
{
   std::string sp_ste_rpc_server_ip_address_to_listen_on(ip_address_to_listen_on);

   sp_ste_control_class sp_ste_cc_object;

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

void foo(const char *ip_address_to_listen_on)
{
   std::string sp_ste_rpc_server_ip_address_to_listen_on(ip_address_to_listen_on);//ip_address_to_listen_on);
   std::cout << "the cpp value in the function of s is " << sp_ste_rpc_server_ip_address_to_listen_on << std::endl;
}

int main(int argc, char** argv) {
   run_rpc_server("dns:///localhost:1234");
   //run_rpc_server("0.0.0.0:50051");

}

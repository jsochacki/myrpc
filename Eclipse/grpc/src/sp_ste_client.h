#ifndef SP_STE_CLIENT_H_
#define SP_STE_CLIENT_H_

#include <iostream>
#include <memory>
#include <string>

#include <grpcpp/grpcpp.h>

#include "sp_ste.grpc.pb.h"

class sp_ste_control_class_client final : public sp::ste::sp_ste_control::Service
{
   public:
      //Needs a constructor to make the stub for communication
      explicit
         sp_ste_control_class_client(
            std::shared_ptr<grpc::Channel> channel) :
               __stub(sp::ste::sp_ste_control::NewStub(channel)) {};
      int loopback();
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
   private:
      std::unique_ptr<sp::ste::sp_ste_control::Stub> __stub;
};


#endif /* SP_STE_CLIENT_H_ */

#ifndef SP_STE_CLIENT_H_
#define SP_STE_CLIENT_H_

#include <iostream>
#include <memory>
#include <string>

#include <fstream>

#include <grpcpp/grpcpp.h>

#include "sp_ste.grpc.pb.h"
#include "sp_ste_typedefs.h"

void set_remote_from_local(SPSingleMeasurementParams &, sp::ste::set_parameters &);

class sp_ste_control_class_client final : public sp::ste::sp_ste_control::Service
{
   public:
      //Needs a constructor to make the stub for communication
      explicit
         sp_ste_control_class_client(
            std::shared_ptr<grpc::Channel> channel) :
               stub_(sp::ste::sp_ste_control::NewStub(channel)) {};
      int loopback(SPSingleMeasurementParams &);
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
      std::unique_ptr<sp::ste::sp_ste_control::Stub> stub_;
};

#endif /* SP_STE_CLIENT_H_ */

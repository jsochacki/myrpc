#ifndef SP_STE_CLIENT_H_
#define SP_STE_CLIENT_H_

#include <iostream>
#include <memory>
#include <string>

#include <fstream>

#include <grpcpp/grpcpp.h>

#include "sp_ste.grpc.pb.h"
#include "sp_ste_typedefs.h"

void set_outgoing(SPSingleMeasurementParams &, sp::ste::set_parameters &);

class sp_ste_control_class_client final : public sp::ste::sp_ste_control::Service
{
   public:
      //Needs a constructor to make the stub for communication
      explicit
         sp_ste_control_class_client(
            std::shared_ptr<grpc::Channel> channel) :
               stub_(sp::ste::sp_ste_control::NewStub(channel)) {};
      void loopback(SPSingleMeasurementParams &);
//      SPSingleMeasurementParams check_current_values(SPSingleMeasurementParams &) override;
//      SPSingleMeasurementParams issue_new_values_and_read_old(SPSingleMeasurementParams &) override;
//      SPSingleMeasurementParams issue_new_values_and_read_new(SPSingleMeasurementParams &) override;
   private:
      std::unique_ptr<sp::ste::sp_ste_control::Stub> stub_;
};

bool parse_status(grpc::Status &&);

void parse_remote_status_error(grpc::Status &&);

#endif /* SP_STE_CLIENT_H_ */

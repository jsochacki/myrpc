#ifndef SP_STE_SERVER_H_
#define SP_STE_SERVER_H_

#include <iostream>
#include <memory>
#include <string>

#include <grpcpp/grpcpp.h>

#include "sp_ste.grpc.pb.h"

#include "sp_ste_typedefs.h"

void set_local_from_remote(
         SPSingleMeasurementParams &,
         sp::ste::sp_ste_rx_parameters_single_measurement &,
         sp::ste::sp_ste_tx_parameters_single_measurement &);

void set_remote_from_local(
         SPSingleMeasurementParams &,
         sp::ste::sp_ste_rx_parameters_single_measurement &,
         sp::ste::sp_ste_tx_parameters_single_measurement &);

void display_local_rpcd_struct_values(SPSingleMeasurementParams &);

class sp_ste_control_class_server final : public sp::ste::sp_ste_control::Service
{
   public:
      //I have no constructor at this point
      //explicit sp_ste_control_class_server(const std::string &db);
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

void run_rpc_server(const char *);


#endif /* SP_STE_SERVER_H_ */

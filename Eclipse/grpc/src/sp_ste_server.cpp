
#include "sp_ste_server.h"

#include "sp_ste_typedefs.h"

////I have no constructor at this point
//sp_ste_control_class_server::sp_ste_control_class_server(const //}

grpc::Status
   sp_ste_control_class_server::loopback(grpc::ServerContext *context,
                                  const sp::ste::set_parameters *values_received,
                                  sp::ste::parameter_values *values_returned)
{
   sp::ste::sp_ste_rx_parameters_single_measurement rx_input_parameters = values_received->rx_params();

   SPSingleMeasurementParams teststruct;

   teststruct.fft_length_a = rx_input_parameters.fft_length_a();
   teststruct.fft_length_b = rx_input_parameters.fft_length_b();
   teststruct.fft_batches_a = rx_input_parameters.fft_batches_a();
   teststruct.fft_batches_b = rx_input_parameters.fft_batches_b();
   teststruct.decimation = rx_input_parameters.decimation();
   teststruct.num_rx_samples = rx_input_parameters.num_rx_samples();
   teststruct.rx_rot_freq_hz = rx_input_parameters.rx_rot_freq_hz();
   teststruct.save_iq = rx_input_parameters.save_iq();
   teststruct.fft_a_enable = rx_input_parameters.fft_a_enable();
   teststruct.fft_b_enable = rx_input_parameters.fft_b_enable();
   teststruct.parameter_estimate_enable = rx_input_parameters.parameter_estimate_enable();
   teststruct.rx_file_base_name = rx_input_parameters.filebasename();
   teststruct.filename_fft_a = rx_input_parameters.filename_fft_a();
   teststruct.filename_fft_b = rx_input_parameters.filename_fft_b();
   teststruct.filename_rx_samples = rx_input_parameters.filename_rx_samples();
   teststruct.next_rx_start_time = rx_input_parameters.next_rx_start_time();

   std::cout << "the values are " << std::endl;
   std::cout << teststruct.fft_length_a << std::endl;
   std::cout << teststruct.fft_length_b << std::endl;
   std::cout << teststruct.fft_batches_a << std::endl;
   std::cout << teststruct.fft_batches_b << std::endl;
   std::cout << teststruct.decimation << std::endl;
   std::cout << teststruct.num_rx_samples << std::endl;
   std::cout << teststruct.rx_rot_freq_hz << std::endl;


   values_returned->mutable_hdr()->set_module("the good one");

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


#include "sp_ste_server.h"

#include "sp_ste_typedefs.h"

////I have no constructor at this point
//sp_ste_control_class_server::sp_ste_control_class_server(const //}

extern SPSingleMeasurementParams teststruct;

void sp_ste_control_class_server::set_local_from_remote(
         SPSingleMeasurementParams &local_struct_ref,
         sp::ste::sp_ste_rx_parameters_single_measurement &rx_input_parameters,
         sp::ste::sp_ste_tx_parameters_single_measurement &tx_input_parameters)
{
   local_struct_ref.fft_length_a = rx_input_parameters.fft_length_a();
   local_struct_ref.fft_length_b = rx_input_parameters.fft_length_b();
   local_struct_ref.fft_batches_a = rx_input_parameters.fft_batches_a();
   local_struct_ref.fft_batches_b = rx_input_parameters.fft_batches_b();
   local_struct_ref.decimation = rx_input_parameters.decimation();
   local_struct_ref.num_rx_samples = rx_input_parameters.num_rx_samples();
   local_struct_ref.rx_rot_freq_hz = rx_input_parameters.rx_rot_freq_hz();
   local_struct_ref.save_iq = rx_input_parameters.save_iq();
   local_struct_ref.fft_a_enable = rx_input_parameters.fft_a_enable();
   local_struct_ref.fft_b_enable = rx_input_parameters.fft_b_enable();
   local_struct_ref.parameter_estimate_enable = rx_input_parameters.parameter_estimate_enable();
   local_struct_ref.rx_file_base_name = rx_input_parameters.filebasename();
   local_struct_ref.filename_fft_a = rx_input_parameters.filename_fft_a();
   local_struct_ref.filename_fft_b = rx_input_parameters.filename_fft_b();
   local_struct_ref.filename_rx_samples = rx_input_parameters.filename_rx_samples();
   local_struct_ref.next_rx_start_time = rx_input_parameters.next_rx_start_time();

   local_struct_ref.num_tx_samples_total = tx_input_parameters.num_tx_samples_total();
   local_struct_ref.num_tx_samples_per_batch = tx_input_parameters.num_tx_samples_per_batch();
   local_struct_ref.tx_freq1_hz = tx_input_parameters.tx_freq1_hz();
   local_struct_ref.tx_phase1_rot = tx_input_parameters.tx_phase1_rot();
   local_struct_ref.tx_freq2_hz = tx_input_parameters.tx_freq2_hz();
   local_struct_ref.tx_phase2_rot = tx_input_parameters.tx_phase2_rot();
   local_struct_ref.gain1 = tx_input_parameters.gain1();
   local_struct_ref.gain2 = tx_input_parameters.gain2();
   local_struct_ref.gain3 = tx_input_parameters.gain3();
   local_struct_ref.awgn_enable = tx_input_parameters.awgn_enable();
   local_struct_ref.notch_enable = tx_input_parameters.notch_enable();
   local_struct_ref.tx_file_base_name = tx_input_parameters.filebasename();
   local_struct_ref.filename_tx_samples = tx_input_parameters.filename_tx_samples();
   local_struct_ref.next_tx_start_time = tx_input_parameters.next_tx_start_time();
   local_struct_ref.tx_idle_pattern = static_cast<IdlePatterns>(tx_input_parameters.tx_idle_pattern());
}

void sp_ste_control_class_server::set_remote_from_local(
         SPSingleMeasurementParams &local_struct_ref,
         sp::ste::sp_ste_rx_parameters_single_measurement *rx_output_parameters,
         sp::ste::sp_ste_tx_parameters_single_measurement *tx_output_parameters)
{
   rx_output_parameters->set_fft_length_a(local_struct_ref.fft_length_a);
   rx_output_parameters->set_fft_length_b(local_struct_ref.fft_length_b);
   rx_output_parameters->set_fft_batches_a(local_struct_ref.fft_batches_a);
   rx_output_parameters->set_fft_batches_b(local_struct_ref.fft_batches_b);
   rx_output_parameters->set_decimation(local_struct_ref.decimation);
   rx_output_parameters->set_num_rx_samples(local_struct_ref.num_rx_samples);
   rx_output_parameters->set_rx_rot_freq_hz(local_struct_ref.rx_rot_freq_hz);
   rx_output_parameters->set_save_iq(local_struct_ref.save_iq);
   rx_output_parameters->set_fft_a_enable(local_struct_ref.fft_a_enable);
   rx_output_parameters->set_fft_b_enable(local_struct_ref.fft_b_enable);
   rx_output_parameters->set_parameter_estimate_enable(local_struct_ref.parameter_estimate_enable);
   rx_output_parameters->set_filebasename(local_struct_ref.rx_file_base_name);
   rx_output_parameters->set_filename_fft_a(local_struct_ref.filename_fft_a);
   rx_output_parameters->set_filename_fft_b(local_struct_ref.filename_fft_b);
   rx_output_parameters->set_filename_rx_samples(local_struct_ref.filename_rx_samples);
   rx_output_parameters->set_next_rx_start_time(local_struct_ref.next_rx_start_time);

   tx_output_parameters->set_num_tx_samples_total(local_struct_ref.num_tx_samples_total);
   tx_output_parameters->set_num_tx_samples_per_batch(local_struct_ref.num_tx_samples_per_batch);
   tx_output_parameters->set_tx_freq1_hz(local_struct_ref.tx_freq1_hz);
   tx_output_parameters->set_tx_phase1_rot(local_struct_ref.tx_phase1_rot);
   tx_output_parameters->set_tx_freq2_hz(local_struct_ref.tx_freq2_hz);
   tx_output_parameters->set_tx_phase2_rot(local_struct_ref.tx_phase2_rot);
   tx_output_parameters->set_gain1(local_struct_ref.gain1);
   tx_output_parameters->set_gain2(local_struct_ref.gain2);
   tx_output_parameters->set_gain3(local_struct_ref.gain3);
   tx_output_parameters->set_awgn_enable(local_struct_ref.awgn_enable);
   tx_output_parameters->set_notch_enable(local_struct_ref.notch_enable);
   tx_output_parameters->set_filebasename(local_struct_ref.tx_file_base_name);
   tx_output_parameters->set_filename_tx_samples(local_struct_ref.filename_tx_samples);
   tx_output_parameters->set_next_tx_start_time(local_struct_ref.next_tx_start_time);
   tx_output_parameters->set_tx_idle_pattern(static_cast<sp::ste::TxIdlePattern>(local_struct_ref.tx_idle_pattern));
}


void sp_ste_control_class_server::display_local_rpcd_struct_values(SPSingleMeasurementParams &local_struct_ref)
{
   std::cout << "the SPSingleMeasurementParams struct values are " << std::endl;
   std::cout << local_struct_ref.fft_length_a << std::endl;
   std::cout << local_struct_ref.fft_length_b << std::endl;
   std::cout << local_struct_ref.fft_batches_a << std::endl;
   std::cout << local_struct_ref.fft_batches_b << std::endl;
   std::cout << local_struct_ref.decimation << std::endl;
   std::cout << local_struct_ref.num_rx_samples << std::endl;
   std::cout << local_struct_ref.rx_rot_freq_hz << std::endl;
   std::cout << local_struct_ref.save_iq << std::endl;
   std::cout << local_struct_ref.fft_a_enable << std::endl;
   std::cout << local_struct_ref.fft_b_enable << std::endl;
   std::cout << local_struct_ref.parameter_estimate_enable << std::endl;
   std::cout << local_struct_ref.rx_file_base_name << std::endl;
   std::cout << local_struct_ref.filename_fft_a << std::endl;
   std::cout << local_struct_ref.filename_fft_b << std::endl;
   std::cout << local_struct_ref.filename_rx_samples << std::endl;
   std::cout << local_struct_ref.next_rx_start_time << std::endl;

   std::cout << local_struct_ref.num_tx_samples_total << std::endl;
   std::cout << local_struct_ref.num_tx_samples_per_batch << std::endl;
   std::cout << local_struct_ref.tx_freq1_hz << std::endl;
   std::cout << local_struct_ref.tx_phase1_rot << std::endl;
   std::cout << local_struct_ref.tx_freq2_hz << std::endl;
   std::cout << local_struct_ref.tx_phase2_rot << std::endl;
   std::cout << local_struct_ref.gain1 << std::endl;
   std::cout << local_struct_ref.gain2 << std::endl;
   std::cout << local_struct_ref.gain3 << std::endl;
   std::cout << local_struct_ref.awgn_enable << std::endl;
   std::cout << local_struct_ref.notch_enable << std::endl;
   std::cout << local_struct_ref.tx_file_base_name << std::endl;
   std::cout << local_struct_ref.filename_tx_samples << std::endl;
   std::cout << local_struct_ref.next_tx_start_time << std::endl;
   std::cout << local_struct_ref.tx_idle_pattern << std::endl;
}


grpc::Status
   sp_ste_control_class_server::loopback(grpc::ServerContext *context,
                                  const sp::ste::set_parameters *values_received,
                                  sp::ste::parameter_values *values_returned)
{
   sp::ste::sp_ste_rx_parameters_single_measurement rx_input_parameters = values_received->rx_params();
   sp::ste::sp_ste_tx_parameters_single_measurement tx_input_parameters = values_received->tx_params();

   sp::ste::sp_ste_rx_parameters_single_measurement *rx_output_parameters = values_returned->mutable_rx_params();
   sp::ste::sp_ste_tx_parameters_single_measurement *tx_output_parameters = values_returned->mutable_tx_params();

   SPSingleMeasurementParams local_struct;

   set_local_from_remote(local_struct, rx_input_parameters, tx_input_parameters);

   set_remote_from_local(local_struct, rx_output_parameters, tx_output_parameters);

   display_local_rpcd_struct_values(local_struct);

   //values_returned->mutable_hdr()->set_module("loopback");
   //grpc::Status status(grpc::StatusCode::UNIMPLEMENTED, "this is not yet implemented", "find more workers");
   //return status;

   return grpc::Status::OK;
}

grpc::Status
   sp_ste_control_class_server::check_current_values(grpc::ServerContext *context,
                                       const sp::ste::null_message *null_value,
                                       sp::ste::parameter_values *values_returned)
{

   sp::ste::sp_ste_rx_parameters_single_measurement *rx_output_parameters = values_returned->mutable_rx_params();
   sp::ste::sp_ste_tx_parameters_single_measurement *tx_output_parameters = values_returned->mutable_tx_params();

   set_remote_from_local(teststruct, rx_output_parameters, tx_output_parameters);

   display_local_rpcd_struct_values(teststruct);

   return grpc::Status::OK;
}

grpc::Status
   sp_ste_control_class_server::issue_new_values_and_read_old(
                                 grpc::ServerContext *context,
                                 const sp::ste::set_parameters *values_received,
                                 sp::ste::parameter_values *values_returned)
{
   sp::ste::sp_ste_rx_parameters_single_measurement rx_input_parameters = values_received->rx_params();
   sp::ste::sp_ste_tx_parameters_single_measurement tx_input_parameters = values_received->tx_params();

   sp::ste::sp_ste_rx_parameters_single_measurement *rx_output_parameters = values_returned->mutable_rx_params();
   sp::ste::sp_ste_tx_parameters_single_measurement *tx_output_parameters = values_returned->mutable_tx_params();

   //SPSingleMeasurementParams teststruct;

   set_remote_from_local(teststruct, rx_output_parameters, tx_output_parameters);

   set_local_from_remote(teststruct, rx_input_parameters, tx_input_parameters);

   display_local_rpcd_struct_values(teststruct);

   //values_returned->mutable_hdr()->set_module("loopback");
   //grpc::Status status(grpc::StatusCode::UNIMPLEMENTED, "this is not yet implemented", "find more workers");
   //return status;

   return grpc::Status::OK;
}

grpc::Status
   sp_ste_control_class_server::issue_new_values_and_read_new(
                                 grpc::ServerContext *context,
                                 const sp::ste::set_parameters *values_received,
                                 sp::ste::parameter_values *values_returned)
{
   sp::ste::sp_ste_rx_parameters_single_measurement rx_input_parameters = values_received->rx_params();
   sp::ste::sp_ste_tx_parameters_single_measurement tx_input_parameters = values_received->tx_params();

   sp::ste::sp_ste_rx_parameters_single_measurement *rx_output_parameters = values_returned->mutable_rx_params();
   sp::ste::sp_ste_tx_parameters_single_measurement *tx_output_parameters = values_returned->mutable_tx_params();

   //SPSingleMeasurementParams teststruct;

   set_local_from_remote(teststruct, rx_input_parameters, tx_input_parameters);

   set_remote_from_local(teststruct, rx_output_parameters, tx_output_parameters);

   display_local_rpcd_struct_values(teststruct);

   //values_returned->mutable_hdr()->set_module("loopback");
   //grpc::Status status(grpc::StatusCode::UNIMPLEMENTED, "this is not yet implemented", "find more workers");
   //return status;

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

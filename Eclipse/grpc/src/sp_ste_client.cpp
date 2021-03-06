
#include "sp_ste_client.h"
//#include "sp_ste_typedefs.h"

void sp_ste_control_class_client::set_outgoing(
         SPSingleMeasurementParams &local_struct_ref,
         sp::ste::set_parameters &output_parameters)
{
   output_parameters.mutable_rx_params()->set_fft_length_a(local_struct_ref.fft_length_a);
   output_parameters.mutable_rx_params()->set_fft_length_b(local_struct_ref.fft_length_b);
   output_parameters.mutable_rx_params()->set_fft_batches_a(local_struct_ref.fft_batches_a);
   output_parameters.mutable_rx_params()->set_fft_batches_b(local_struct_ref.fft_batches_b);
   output_parameters.mutable_rx_params()->set_decimation(local_struct_ref.decimation);
   output_parameters.mutable_rx_params()->set_num_rx_samples(local_struct_ref.num_rx_samples);
   output_parameters.mutable_rx_params()->set_rx_rot_freq_hz(local_struct_ref.rx_rot_freq_hz);
   output_parameters.mutable_rx_params()->set_save_iq(local_struct_ref.save_iq);
   output_parameters.mutable_rx_params()->set_fft_a_enable(local_struct_ref.fft_a_enable);
   output_parameters.mutable_rx_params()->set_fft_b_enable(local_struct_ref.fft_b_enable);
   output_parameters.mutable_rx_params()->set_parameter_estimate_enable(local_struct_ref.parameter_estimate_enable);
   output_parameters.mutable_rx_params()->set_filebasename(local_struct_ref.rx_file_base_name);
   output_parameters.mutable_rx_params()->set_filename_fft_a(local_struct_ref.filename_fft_a);
   output_parameters.mutable_rx_params()->set_filename_fft_b(local_struct_ref.filename_fft_b);
   output_parameters.mutable_rx_params()->set_filename_rx_samples(local_struct_ref.filename_rx_samples);
   output_parameters.mutable_rx_params()->set_next_rx_start_time(local_struct_ref.next_rx_start_time);

   output_parameters.mutable_tx_params()->set_num_tx_samples_total(local_struct_ref.num_tx_samples_total);
   output_parameters.mutable_tx_params()->set_num_tx_samples_per_batch(local_struct_ref.num_tx_samples_per_batch);
   output_parameters.mutable_tx_params()->set_tx_freq1_hz(local_struct_ref.tx_freq1_hz);
   output_parameters.mutable_tx_params()->set_tx_phase1_rot(local_struct_ref.tx_phase1_rot);
   output_parameters.mutable_tx_params()->set_tx_freq2_hz(local_struct_ref.tx_freq2_hz);
   output_parameters.mutable_tx_params()->set_tx_phase2_rot(local_struct_ref.tx_phase2_rot);
   output_parameters.mutable_tx_params()->set_gain1(local_struct_ref.gain1);
   output_parameters.mutable_tx_params()->set_gain2(local_struct_ref.gain2);
   output_parameters.mutable_tx_params()->set_gain3(local_struct_ref.gain3);
   output_parameters.mutable_tx_params()->set_awgn_enable(local_struct_ref.awgn_enable);
   output_parameters.mutable_tx_params()->set_notch_enable(local_struct_ref.notch_enable);
   output_parameters.mutable_tx_params()->set_filebasename(local_struct_ref.tx_file_base_name);
   output_parameters.mutable_tx_params()->set_filename_tx_samples(local_struct_ref.filename_tx_samples);
   output_parameters.mutable_tx_params()->set_next_tx_start_time(local_struct_ref.next_tx_start_time);
   output_parameters.mutable_tx_params()->set_tx_idle_pattern(static_cast<sp::ste::TxIdlePattern>(local_struct_ref.tx_idle_pattern));
}

void sp_ste_control_class_client::update_local(
         SPSingleMeasurementParams &local_struct_ref,
         sp::ste::parameter_values &return_values)
{
   local_struct_ref.fft_length_a = return_values.rx_params().fft_length_a();
   local_struct_ref.fft_length_b = return_values.rx_params().fft_length_b();
   local_struct_ref.fft_batches_a = return_values.rx_params().fft_batches_a();
   local_struct_ref.fft_batches_b = return_values.rx_params().fft_batches_b();
   local_struct_ref.decimation = return_values.rx_params().decimation();
   local_struct_ref.num_rx_samples = return_values.rx_params().num_rx_samples();
   local_struct_ref.rx_rot_freq_hz = return_values.rx_params().rx_rot_freq_hz();
   local_struct_ref.save_iq = return_values.rx_params().save_iq();
   local_struct_ref.fft_a_enable = return_values.rx_params().fft_a_enable();
   local_struct_ref.fft_b_enable = return_values.rx_params().fft_b_enable();
   local_struct_ref.parameter_estimate_enable = return_values.rx_params().parameter_estimate_enable();
   local_struct_ref.rx_file_base_name = return_values.rx_params().filebasename();
   local_struct_ref.filename_fft_a = return_values.rx_params().filename_fft_a();
   local_struct_ref.filename_fft_b = return_values.rx_params().filename_fft_b();
   local_struct_ref.filename_rx_samples = return_values.rx_params().filename_rx_samples();
   local_struct_ref.next_rx_start_time = return_values.rx_params().next_rx_start_time();

   local_struct_ref.num_tx_samples_total = return_values.tx_params().num_tx_samples_total();
   local_struct_ref.num_tx_samples_per_batch = return_values.tx_params().num_tx_samples_per_batch();
   local_struct_ref.tx_freq1_hz = return_values.tx_params().tx_freq1_hz();
   local_struct_ref.tx_phase1_rot = return_values.tx_params().tx_phase1_rot();
   local_struct_ref.tx_freq2_hz = return_values.tx_params().tx_freq2_hz();
   local_struct_ref.tx_phase2_rot = return_values.tx_params().tx_phase2_rot();
   local_struct_ref.gain1 = return_values.tx_params().gain1();
   local_struct_ref.gain2 = return_values.tx_params().gain2();
   local_struct_ref.gain3 = return_values.tx_params().gain3();
   local_struct_ref.awgn_enable = return_values.tx_params().awgn_enable();
   local_struct_ref.notch_enable = return_values.tx_params().notch_enable();
   local_struct_ref.tx_file_base_name = return_values.tx_params().filebasename();
   local_struct_ref.filename_tx_samples = return_values.tx_params().filename_tx_samples();
   local_struct_ref.next_tx_start_time = return_values.tx_params().next_tx_start_time();
   local_struct_ref.tx_idle_pattern = static_cast<IdlePatterns>(return_values.tx_params().tx_idle_pattern());
}

bool sp_ste_control_class_client::parse_status(grpc::Status &&status)
{
   if (status.ok())
   {
      std::cout << "message transmission successful" << std::endl;
      return false;
   }
   else
   {
      parse_remote_status_error(std::forward<grpc::Status>(status));
      return true;
   }
}


void sp_ste_control_class_client::parse_remote_status_error(grpc::Status &&status)
{
   std::cerr << status.error_code()
             << ": " << status.error_message()
             << ": " << status.error_details()
             << std::endl;
}

void sp_ste_control_class_client::loopback(SPSingleMeasurementParams &parameters)
{
   grpc::ClientContext context;

   sp::ste::set_parameters values_to_send;

   sp::ste::parameter_values return_values;

   set_outgoing(parameters, values_to_send);

   if(parse_status(stub_->loopback(&context, values_to_send, &return_values)))
   {
      std::cerr << "rpc failed, std cerr error was written" << std::endl;
      exit(1);
   }
   else
   {
      update_local(parameters, return_values);
   }
}

SPSingleMeasurementParams sp_ste_control_class_client::check_current_values(void)
{
   grpc::ClientContext context;

   sp::ste::null_message null_value;

   sp::ste::parameter_values return_values;

   if(parse_status(stub_->check_current_values(&context, null_value, &return_values)))
   {
      std::cerr << "rpc failed, std cerr error was written" << std::endl;
      exit(1);
   }
   else
   {
      SPSingleMeasurementParams return_struct;
      update_local(return_struct, return_values);
      return return_struct;
   }
}
SPSingleMeasurementParams sp_ste_control_class_client::issue_new_values_and_read_old(SPSingleMeasurementParams &parameters)
{
   grpc::ClientContext context;

   sp::ste::set_parameters values_to_send;

   sp::ste::parameter_values return_values;

   set_outgoing(parameters, values_to_send);

   if(parse_status(stub_->issue_new_values_and_read_old(&context, values_to_send, &return_values)))
   {
      std::cerr << "rpc failed, std cerr error was written" << std::endl;
      exit(1);
   }
   else
   {
      SPSingleMeasurementParams return_struct;
      update_local(return_struct, return_values);
      return return_struct;
   }
}
SPSingleMeasurementParams sp_ste_control_class_client::issue_new_values_and_read_new(SPSingleMeasurementParams &parameters)
{
   grpc::ClientContext context;

   sp::ste::set_parameters values_to_send;

   sp::ste::parameter_values return_values;

   set_outgoing(parameters, values_to_send);

   if(parse_status(stub_->issue_new_values_and_read_new(&context, values_to_send, &return_values)))
   {
      std::cerr << "rpc failed, std cerr error was written" << std::endl;
      exit(1);
   }
   else
   {
      SPSingleMeasurementParams return_struct;
      update_local(return_struct, return_values);
      return return_struct;
   }
}



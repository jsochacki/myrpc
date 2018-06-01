
#include "sp_ste_client.h"
//#include "sp_ste_typedefs.h"

void set_remote_from_local(
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

int sp_ste_control_class_client::loopback(SPSingleMeasurementParams &parameters)
{
   grpc::ClientContext context;

   sp::ste::set_parameters values_to_send;

   sp::ste::parameter_values return_values;

   set_remote_from_local(parameters, values_to_send);

//   values_to_send.mutable_state_parameters()->\
//            set_fft_a_enable(sp::ste::state::ENABLED);

   grpc::Status status = stub_->loopback(&context, values_to_send, &return_values);

   if (status.ok())
   {
      return 1;
   }
   else
   {
     std::cout << status.error_code() << ": " << status.error_message()
               << std::endl;
     return 0;
   }
}

//int
//   sp_ste_control_class_client::loopback()
//{
//   grpc::ClientContext context;
//
//   sp::ste::set_parameters values_to_send;
//
//   sp::ste::parameter_values return_values;
//
//   values_to_send.mutable_num_params()->set_state_count(6);
//
//   values_to_send.mutable_state_parameters()->\
//            set_save_iq(sp::ste::state::ON);
//   values_to_send.mutable_state_parameters()->\
//            set_parameter_estimate_enable(sp::ste::state::ENABLED);
//   values_to_send.mutable_state_parameters()->\
//            set_awgn_enable(sp::ste::state::ENABLED);
//   values_to_send.mutable_state_parameters()->\
//            set_notch_enable(sp::ste::state::ENABLED);
//   values_to_send.mutable_state_parameters()->\
//            set_fft_a_enable(sp::ste::state::ENABLED);
//   values_to_send.mutable_state_parameters()->\
//            set_fft_a_enable(sp::ste::state::ENABLED);
//
//   grpc::Status status = stub_->loopback(&context, values_to_send, &return_values);
//
//   if (status.ok())
//   {
//      return (return_values.num_params().state_count());
//   }
//   else
//   {
//     std::cout << status.error_code() << ": " << status.error_message()
//               << std::endl;
//     return 0;
//   }
//}



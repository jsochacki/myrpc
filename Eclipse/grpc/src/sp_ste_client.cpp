
#include "sp_ste_client.h"
//#include "sp_ste_typedefs.h"

int sp_ste_control_class_client::loopback(SPSingleMeasurementParams &parameters)
{
   grpc::ClientContext context;

   sp::ste::set_parameters values_to_send;

   sp::ste::parameter_values return_values;

   values_to_send.mutable_rx_params()->set_fft_length_a(parameters.fft_length_a);
   values_to_send.mutable_rx_params()->set_fft_length_b(parameters.fft_length_b);
   values_to_send.mutable_rx_params()->set_fft_batches_a(parameters.fft_batches_a);
   values_to_send.mutable_rx_params()->set_fft_batches_b(parameters.fft_batches_b);
   values_to_send.mutable_rx_params()->set_decimation(parameters.decimation);
   values_to_send.mutable_rx_params()->set_num_rx_samples(parameters.num_rx_samples);
   values_to_send.mutable_rx_params()->set_rx_rot_freq_hz(parameters.rx_rot_freq_hz);
   values_to_send.mutable_rx_params()->set_save_iq(parameters.save_iq);
   values_to_send.mutable_rx_params()->set_fft_a_enable(parameters.fft_a_enable);
   values_to_send.mutable_rx_params()->set_fft_b_enable(parameters.fft_b_enable);
   values_to_send.mutable_rx_params()->set_parameter_estimate_enable(parameters.parameter_estimate_enable);
   values_to_send.mutable_rx_params()->set_filebasename(parameters.rx_file_base_name);
   values_to_send.mutable_rx_params()->set_filename_fft_a(parameters.filename_fft_a);
   values_to_send.mutable_rx_params()->set_filename_fft_b(parameters.filename_fft_b);
   values_to_send.mutable_rx_params()->set_filename_rx_samples(parameters.filename_rx_samples);
   values_to_send.mutable_rx_params()->set_next_rx_start_time(parameters.next_rx_start_time);

   values_to_send.mutable_tx_params()->set_num_tx_samples_total(parameters.num_tx_samples_total);
   values_to_send.mutable_tx_params()->set_num_tx_samples_per_batch(parameters.num_tx_samples_per_batch);
   values_to_send.mutable_tx_params()->set_tx_freq1_hz(parameters.tx_freq1_hz);
   values_to_send.mutable_tx_params()->set_tx_phase1_rot(parameters.tx_phase1_rot);
   values_to_send.mutable_tx_params()->set_tx_freq2_hz(parameters.tx_freq2_hz);
   values_to_send.mutable_tx_params()->set_tx_phase2_rot(parameters.tx_phase2_rot);
   values_to_send.mutable_tx_params()->set_gain1(parameters.gain1);
   values_to_send.mutable_tx_params()->set_gain2(parameters.gain2);
   values_to_send.mutable_tx_params()->set_gain3(parameters.gain3);
   values_to_send.mutable_tx_params()->set_awgn_enable(parameters.awgn_enable);
   values_to_send.mutable_tx_params()->set_notch_enable(parameters.notch_enable);
   values_to_send.mutable_tx_params()->set_filebasename(parameters.tx_file_base_name);
   values_to_send.mutable_tx_params()->set_filename_tx_samples(parameters.filename_tx_samples);
   values_to_send.mutable_tx_params()->set_next_tx_start_time(parameters.next_tx_start_time);
   values_to_send.mutable_tx_params()->set_tx_idle_pattern(static_cast<sp::ste::TxIdlePattern>(parameters.tx_idle_pattern));

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



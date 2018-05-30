
#include "sp_ste_client.h"
//#include "sp_ste_typedefs.h"

int sp_ste_control_class_client::loopback(SPSingleMeasurementParams &parameters)
{
   grpc::ClientContext context;

   sp::ste::set_parameters values_to_send;

   sp::ste::parameter_values return_values;

   values_to_send.mutable_rx()->set_fft_length_a(parameters.fft_length_a);
   values_to_send.mutable_rx()->set_fft_length_b(parameters.fft_length_b);
   values_to_send.mutable_rx()->set_fft_batches_a(parameters.fft_batches_a);
   values_to_send.mutable_rx()->set_fft_batches_b(parameters.fft_batches_b);
   values_to_send.mutable_rx()->set_decimation(parameters.decimation);
   values_to_send.mutable_rx()->set_num_rx_samples(parameters.num_rx_samples);
   values_to_send.mutable_rx()->set_rx_rot_freq_hz(parameters.rx_rot_freq_Hz);
   values_to_send.mutable_rx()->set_save_iq(parameters.save_iq);
   values_to_send.mutable_rx()->set_fft_a_enable(parameters.fft_a_enable);
   values_to_send.mutable_rx()->set_fft_b_enable(parameters.fft_b_enable);
   values_to_send.mutable_rx()->set_parameter_estimate_enable(parameters.parameter_estimate_enable);
   values_to_send.mutable_rx()->set_filename_fft_a(parameters.filename_fft_a);
   values_to_send.mutable_rx()->set_filename_fft_b(parameters.filename_fft_b);
   values_to_send.mutable_rx()->set_filename_rx_samples(parameters.filename_rx_samples);
   values_to_send.mutable_rx()->set_nextrxstarttime(parameters.nextRxStartTime);

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



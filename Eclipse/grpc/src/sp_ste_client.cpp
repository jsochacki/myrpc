
#include "sp_ste_client.h"
#include "rpc_structures.h"

int
   sp_ste_control_class_client::loopback()
{
   grpc::ClientContext context;

   sp::ste::set_parameters values_to_send;

   sp::ste::parameter_values return_values;

   values_to_send.mutable_num_params()->set_state_count(6);

   values_to_send.mutable_state_parameters()->\
            set_save_iq(sp::ste::state::ON);
   values_to_send.mutable_state_parameters()->\
            set_parameter_estimate_enable(sp::ste::state::ENABLED);
   values_to_send.mutable_state_parameters()->\
            set_awgn_enable(sp::ste::state::ENABLED);
   values_to_send.mutable_state_parameters()->\
            set_notch_enable(sp::ste::state::ENABLED);
   values_to_send.mutable_state_parameters()->\
            set_fft_a_enable(sp::ste::state::ENABLED);
   values_to_send.mutable_state_parameters()->\
            set_fft_a_enable(sp::ste::state::ENABLED);

   grpc::Status status = __stub->loopback(&context, values_to_send, &return_values);

   if (status.ok())
   {
      return (return_values.num_params().state_count());
   }
   else
   {
     std::cout << status.error_code() << ": " << status.error_message()
               << std::endl;
     return 0;
   }
}


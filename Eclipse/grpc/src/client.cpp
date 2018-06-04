//Client is in the controller and issues requests to the server
//Basically the reverse of the traditional use of client and server

#include "communication_information.h"
#include "sp_ste_client.h"
#include "sp_ste_typedefs.h"

int main(int argc, char** argv)
{
   std::string filename("/root/Desktop/git/myrpc/Eclipse/grpc/src/testfile.txt");

   SPSingleMeasurementParams teststruct, returnstruct;

   std::cout << std::boolalpha << teststruct.load_config_file(filename) << std::endl;

   sp_ste_control_class_client
      client_object(
         grpc::CreateChannel(COMMUNICATION_ADDRESS,
                             grpc::InsecureChannelCredentials()
                            )
                   );

   client_object.loopback(teststruct);
   returnstruct = client_object.check_current_values();
   returnstruct = client_object.issue_new_values_and_read_old(teststruct);
//   returnstruct = client_object.check_current_values();
//   returnstruct = client_object.issue_new_values_and_read_new(teststruct);

   std::cout << "the SPSingleMeasurementParams struct values are " << std::endl;
   std::cout << teststruct.fft_length_a << std::endl;
   std::cout << teststruct.fft_length_b << std::endl;
   std::cout << teststruct.fft_batches_a << std::endl;
   std::cout << teststruct.fft_batches_b << std::endl;
   std::cout << teststruct.decimation << std::endl;
   std::cout << teststruct.num_rx_samples << std::endl;
   std::cout << teststruct.rx_rot_freq_hz << std::endl;
   std::cout << teststruct.save_iq << std::endl;
   std::cout << teststruct.fft_a_enable << std::endl;
   std::cout << teststruct.fft_b_enable << std::endl;
   std::cout << teststruct.parameter_estimate_enable << std::endl;
   std::cout << teststruct.rx_file_base_name << std::endl;
   std::cout << teststruct.filename_fft_a << std::endl;
   std::cout << teststruct.filename_fft_b << std::endl;
   std::cout << teststruct.filename_rx_samples << std::endl;
   std::cout << teststruct.next_rx_start_time << std::endl;

   std::cout << teststruct.num_tx_samples_total << std::endl;
   std::cout << teststruct.num_tx_samples_per_batch << std::endl;
   std::cout << teststruct.tx_freq1_hz << std::endl;
   std::cout << teststruct.tx_phase1_rot << std::endl;
   std::cout << teststruct.tx_freq2_hz << std::endl;
   std::cout << teststruct.tx_phase2_rot << std::endl;
   std::cout << teststruct.gain1 << std::endl;
   std::cout << teststruct.gain2 << std::endl;
   std::cout << teststruct.gain3 << std::endl;
   std::cout << teststruct.awgn_enable << std::endl;
   std::cout << teststruct.notch_enable << std::endl;
   std::cout << teststruct.tx_file_base_name << std::endl;
   std::cout << teststruct.filename_tx_samples << std::endl;
   std::cout << teststruct.next_tx_start_time << std::endl;
   std::cout << teststruct.tx_idle_pattern << std::endl;

   std::cout << "the returnstruct struct values are " << std::endl;
   std::cout << returnstruct.fft_length_a << std::endl;
   std::cout << returnstruct.fft_length_b << std::endl;
   std::cout << returnstruct.fft_batches_a << std::endl;
   std::cout << returnstruct.fft_batches_b << std::endl;
   std::cout << returnstruct.decimation << std::endl;
   std::cout << returnstruct.num_rx_samples << std::endl;
   std::cout << returnstruct.rx_rot_freq_hz << std::endl;
   std::cout << returnstruct.save_iq << std::endl;
   std::cout << returnstruct.fft_a_enable << std::endl;
   std::cout << returnstruct.fft_b_enable << std::endl;
   std::cout << returnstruct.parameter_estimate_enable << std::endl;
   std::cout << returnstruct.rx_file_base_name << std::endl;
   std::cout << returnstruct.filename_fft_a << std::endl;
   std::cout << returnstruct.filename_fft_b << std::endl;
   std::cout << returnstruct.filename_rx_samples << std::endl;
   std::cout << returnstruct.next_rx_start_time << std::endl;

   std::cout << returnstruct.num_tx_samples_total << std::endl;
   std::cout << returnstruct.num_tx_samples_per_batch << std::endl;
   std::cout << returnstruct.tx_freq1_hz << std::endl;
   std::cout << returnstruct.tx_phase1_rot << std::endl;
   std::cout << returnstruct.tx_freq2_hz << std::endl;
   std::cout << returnstruct.tx_phase2_rot << std::endl;
   std::cout << returnstruct.gain1 << std::endl;
   std::cout << returnstruct.gain2 << std::endl;
   std::cout << returnstruct.gain3 << std::endl;
   std::cout << returnstruct.awgn_enable << std::endl;
   std::cout << returnstruct.notch_enable << std::endl;
   std::cout << returnstruct.tx_file_base_name << std::endl;
   std::cout << returnstruct.filename_tx_samples << std::endl;
   std::cout << returnstruct.next_tx_start_time << std::endl;
   std::cout << returnstruct.tx_idle_pattern << std::endl;

   return 0;
}

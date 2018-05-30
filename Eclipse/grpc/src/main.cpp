
#include "sp_ste_typedefs.h"

int main(int argc, char **argv)
{

   std::string filename("/root/Desktop/git/myrpc/Eclipse/grpc/Debug/testfile.txt");

   SPSingleMeasurementParams teststruct;

   std::cout << std::boolalpha << teststruct.load_config_file(filename) << std::endl;

   std::cout << "element " << teststruct.fft_batches_a
             << std::endl;
   std::cout << "element " << teststruct.filename_fft_a
             << std::endl;
   std::cout << "element " << teststruct.decimation
             << std::endl;
   std::cout << "element " << teststruct.gain3
             << std::endl;

   return 0;
}

//Server is in the STE and receives requests from the Client
//Basically the reverse of the traditional use of client and server

#include <iostream>
#include <memory>
#include <string>

#include <grpc/grpc.h>

#include "sp_ste.grpc.pb.h"

class sp_ste_control_class final : public sp::ste::sp_ste_control::Service
{

};

int main(void)
{
    return 0;
}

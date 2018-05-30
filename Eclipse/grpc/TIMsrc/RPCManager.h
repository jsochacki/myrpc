#pragma once



#include <vector>
#include <map>
#include <memory>

#include "TestBedWorker.h"
#include "ModuleStructs.h"
#include "CommonCtrlService.h"

#include <grpc++/grpc++.h>

namespace TestBed
{
   /* Handles all RPC requests/replies. Synchronous for now. Extend TestBedWorker to be included in thread launch. */
   class RPCManager : public TestBedWorker
   {
       public:
           RPCManager() = delete;
           RPCManager(RPCConfig *_cfg) : TestBedWorker::TestBedWorker("RPCManager", _cfg->core)
               { cfg = *_cfg; workerName = "RPCManager"; }
           virtual ~RPCManager() {}
           virtual int Init() {return 0;}
           virtual void TearDown() {}
           virtual int Run(); /* DPDK callback */
           void AddRPCService(std::shared_ptr<::grpc::Service> s);
           void AddCommonService(std::shared_ptr<::grpc::Service> s);
           void AddRPCServices(std::vector<std::shared_ptr<::grpc::Service>> &_services) { services = _services; }
           void ShutDown() { if (server) server->Shutdown(); }
       private:
           RPCConfig cfg;
           std::unique_ptr<grpc::Server> server;
           std::vector<std::shared_ptr<::grpc::Service>> services;
   };

};

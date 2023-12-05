// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: dsloadbalancer.proto

#include "dsloadbalancer.pb.h"
#include "dsloadbalancer.grpc.pb.h"

#include <functional>
#include <grpcpp/support/async_stream.h>
#include <grpcpp/support/async_unary_call.h>
#include <grpcpp/impl/channel_interface.h>
#include <grpcpp/impl/client_unary_call.h>
#include <grpcpp/support/client_callback.h>
#include <grpcpp/support/message_allocator.h>
#include <grpcpp/support/method_handler.h>
#include <grpcpp/impl/rpc_service_method.h>
#include <grpcpp/support/server_callback.h>
#include <grpcpp/impl/server_callback_handlers.h>
#include <grpcpp/server_context.h>
#include <grpcpp/impl/service_type.h>
#include <grpcpp/support/sync_stream.h>
namespace dsloadbalancer {

static const char* SystemService_method_names[] = {
  "/dsloadbalancer.SystemService/Put",
  "/dsloadbalancer.SystemService/Get",
  "/dsloadbalancer.SystemService/SendPing",
  "/dsloadbalancer.SystemService/handleTask",
};

std::unique_ptr< SystemService::Stub> SystemService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< SystemService::Stub> stub(new SystemService::Stub(channel, options));
  return stub;
}

SystemService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_Put_(SystemService_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::CLIENT_STREAMING, channel)
  , rpcmethod_Get_(SystemService_method_names[1], options.suffix_for_stats(),::grpc::internal::RpcMethod::SERVER_STREAMING, channel)
  , rpcmethod_SendPing_(SystemService_method_names[2], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_handleTask_(SystemService_method_names[3], options.suffix_for_stats(),::grpc::internal::RpcMethod::CLIENT_STREAMING, channel)
  {}

::grpc::ClientWriter< ::dsloadbalancer::KVPair>* SystemService::Stub::PutRaw(::grpc::ClientContext* context, ::dsloadbalancer::BulkPutResponse* response) {
  return ::grpc::internal::ClientWriterFactory< ::dsloadbalancer::KVPair>::Create(channel_.get(), rpcmethod_Put_, context, response);
}

void SystemService::Stub::async::Put(::grpc::ClientContext* context, ::dsloadbalancer::BulkPutResponse* response, ::grpc::ClientWriteReactor< ::dsloadbalancer::KVPair>* reactor) {
  ::grpc::internal::ClientCallbackWriterFactory< ::dsloadbalancer::KVPair>::Create(stub_->channel_.get(), stub_->rpcmethod_Put_, context, response, reactor);
}

::grpc::ClientAsyncWriter< ::dsloadbalancer::KVPair>* SystemService::Stub::AsyncPutRaw(::grpc::ClientContext* context, ::dsloadbalancer::BulkPutResponse* response, ::grpc::CompletionQueue* cq, void* tag) {
  return ::grpc::internal::ClientAsyncWriterFactory< ::dsloadbalancer::KVPair>::Create(channel_.get(), cq, rpcmethod_Put_, context, response, true, tag);
}

::grpc::ClientAsyncWriter< ::dsloadbalancer::KVPair>* SystemService::Stub::PrepareAsyncPutRaw(::grpc::ClientContext* context, ::dsloadbalancer::BulkPutResponse* response, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncWriterFactory< ::dsloadbalancer::KVPair>::Create(channel_.get(), cq, rpcmethod_Put_, context, response, false, nullptr);
}

::grpc::ClientReader< ::dsloadbalancer::KVPair>* SystemService::Stub::GetRaw(::grpc::ClientContext* context, const ::dsloadbalancer::BulkGetRequest& request) {
  return ::grpc::internal::ClientReaderFactory< ::dsloadbalancer::KVPair>::Create(channel_.get(), rpcmethod_Get_, context, request);
}

void SystemService::Stub::async::Get(::grpc::ClientContext* context, const ::dsloadbalancer::BulkGetRequest* request, ::grpc::ClientReadReactor< ::dsloadbalancer::KVPair>* reactor) {
  ::grpc::internal::ClientCallbackReaderFactory< ::dsloadbalancer::KVPair>::Create(stub_->channel_.get(), stub_->rpcmethod_Get_, context, request, reactor);
}

::grpc::ClientAsyncReader< ::dsloadbalancer::KVPair>* SystemService::Stub::AsyncGetRaw(::grpc::ClientContext* context, const ::dsloadbalancer::BulkGetRequest& request, ::grpc::CompletionQueue* cq, void* tag) {
  return ::grpc::internal::ClientAsyncReaderFactory< ::dsloadbalancer::KVPair>::Create(channel_.get(), cq, rpcmethod_Get_, context, request, true, tag);
}

::grpc::ClientAsyncReader< ::dsloadbalancer::KVPair>* SystemService::Stub::PrepareAsyncGetRaw(::grpc::ClientContext* context, const ::dsloadbalancer::BulkGetRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncReaderFactory< ::dsloadbalancer::KVPair>::Create(channel_.get(), cq, rpcmethod_Get_, context, request, false, nullptr);
}

::grpc::Status SystemService::Stub::SendPing(::grpc::ClientContext* context, const ::dsloadbalancer::PingMessage& request, ::dsloadbalancer::PingResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::dsloadbalancer::PingMessage, ::dsloadbalancer::PingResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_SendPing_, context, request, response);
}

void SystemService::Stub::async::SendPing(::grpc::ClientContext* context, const ::dsloadbalancer::PingMessage* request, ::dsloadbalancer::PingResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::dsloadbalancer::PingMessage, ::dsloadbalancer::PingResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_SendPing_, context, request, response, std::move(f));
}

void SystemService::Stub::async::SendPing(::grpc::ClientContext* context, const ::dsloadbalancer::PingMessage* request, ::dsloadbalancer::PingResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_SendPing_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::dsloadbalancer::PingResponse>* SystemService::Stub::PrepareAsyncSendPingRaw(::grpc::ClientContext* context, const ::dsloadbalancer::PingMessage& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::dsloadbalancer::PingResponse, ::dsloadbalancer::PingMessage, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_SendPing_, context, request);
}

::grpc::ClientAsyncResponseReader< ::dsloadbalancer::PingResponse>* SystemService::Stub::AsyncSendPingRaw(::grpc::ClientContext* context, const ::dsloadbalancer::PingMessage& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncSendPingRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::ClientWriter< ::dsloadbalancer::TaskInfo>* SystemService::Stub::handleTaskRaw(::grpc::ClientContext* context, ::dsloadbalancer::Result* response) {
  return ::grpc::internal::ClientWriterFactory< ::dsloadbalancer::TaskInfo>::Create(channel_.get(), rpcmethod_handleTask_, context, response);
}

void SystemService::Stub::async::handleTask(::grpc::ClientContext* context, ::dsloadbalancer::Result* response, ::grpc::ClientWriteReactor< ::dsloadbalancer::TaskInfo>* reactor) {
  ::grpc::internal::ClientCallbackWriterFactory< ::dsloadbalancer::TaskInfo>::Create(stub_->channel_.get(), stub_->rpcmethod_handleTask_, context, response, reactor);
}

::grpc::ClientAsyncWriter< ::dsloadbalancer::TaskInfo>* SystemService::Stub::AsynchandleTaskRaw(::grpc::ClientContext* context, ::dsloadbalancer::Result* response, ::grpc::CompletionQueue* cq, void* tag) {
  return ::grpc::internal::ClientAsyncWriterFactory< ::dsloadbalancer::TaskInfo>::Create(channel_.get(), cq, rpcmethod_handleTask_, context, response, true, tag);
}

::grpc::ClientAsyncWriter< ::dsloadbalancer::TaskInfo>* SystemService::Stub::PrepareAsynchandleTaskRaw(::grpc::ClientContext* context, ::dsloadbalancer::Result* response, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncWriterFactory< ::dsloadbalancer::TaskInfo>::Create(channel_.get(), cq, rpcmethod_handleTask_, context, response, false, nullptr);
}

SystemService::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      SystemService_method_names[0],
      ::grpc::internal::RpcMethod::CLIENT_STREAMING,
      new ::grpc::internal::ClientStreamingHandler< SystemService::Service, ::dsloadbalancer::KVPair, ::dsloadbalancer::BulkPutResponse>(
          [](SystemService::Service* service,
             ::grpc::ServerContext* ctx,
             ::grpc::ServerReader<::dsloadbalancer::KVPair>* reader,
             ::dsloadbalancer::BulkPutResponse* resp) {
               return service->Put(ctx, reader, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      SystemService_method_names[1],
      ::grpc::internal::RpcMethod::SERVER_STREAMING,
      new ::grpc::internal::ServerStreamingHandler< SystemService::Service, ::dsloadbalancer::BulkGetRequest, ::dsloadbalancer::KVPair>(
          [](SystemService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::dsloadbalancer::BulkGetRequest* req,
             ::grpc::ServerWriter<::dsloadbalancer::KVPair>* writer) {
               return service->Get(ctx, req, writer);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      SystemService_method_names[2],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< SystemService::Service, ::dsloadbalancer::PingMessage, ::dsloadbalancer::PingResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](SystemService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::dsloadbalancer::PingMessage* req,
             ::dsloadbalancer::PingResponse* resp) {
               return service->SendPing(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      SystemService_method_names[3],
      ::grpc::internal::RpcMethod::CLIENT_STREAMING,
      new ::grpc::internal::ClientStreamingHandler< SystemService::Service, ::dsloadbalancer::TaskInfo, ::dsloadbalancer::Result>(
          [](SystemService::Service* service,
             ::grpc::ServerContext* ctx,
             ::grpc::ServerReader<::dsloadbalancer::TaskInfo>* reader,
             ::dsloadbalancer::Result* resp) {
               return service->handleTask(ctx, reader, resp);
             }, this)));
}

SystemService::Service::~Service() {
}

::grpc::Status SystemService::Service::Put(::grpc::ServerContext* context, ::grpc::ServerReader< ::dsloadbalancer::KVPair>* reader, ::dsloadbalancer::BulkPutResponse* response) {
  (void) context;
  (void) reader;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status SystemService::Service::Get(::grpc::ServerContext* context, const ::dsloadbalancer::BulkGetRequest* request, ::grpc::ServerWriter< ::dsloadbalancer::KVPair>* writer) {
  (void) context;
  (void) request;
  (void) writer;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status SystemService::Service::SendPing(::grpc::ServerContext* context, const ::dsloadbalancer::PingMessage* request, ::dsloadbalancer::PingResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status SystemService::Service::handleTask(::grpc::ServerContext* context, ::grpc::ServerReader< ::dsloadbalancer::TaskInfo>* reader, ::dsloadbalancer::Result* response) {
  (void) context;
  (void) reader;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace dsloadbalancer


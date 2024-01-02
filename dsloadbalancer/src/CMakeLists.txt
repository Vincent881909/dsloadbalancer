cmake_minimum_required(VERSION 3.15)

# Project
project(dsloadbalancer)

# Protobuf
set(protobuf_MODULE_COMPATIBLE TRUE)
find_package(Protobuf CONFIG REQUIRED)
message(STATUS "Using protobuf ${protobuf_VERSION}")

# Protobuf-compiler
set(_PROTOBUF_PROTOC $<TARGET_FILE:protobuf::protoc>)

# gRPC
find_package(gRPC CONFIG REQUIRED)
message(STATUS "Using gRPC ${gRPC_VERSION}")
set(_GRPC_GRPCPP gRPC::grpc++)
set(_GRPC_CPP_PLUGIN_EXECUTABLE $<TARGET_FILE:gRPC::grpc_cpp_plugin>)

# Proto file
get_filename_component(dsloadbalancer_proto "dsloadbalancer.proto" ABSOLUTE)
get_filename_component(dsloadbalancer_proto_path "${dsloadbalancer_proto}" PATH)

# Generated sources
set(dsloadbalancer_proto_srcs "${CMAKE_CURRENT_BINARY_DIR}/dsloadbalancer.pb.cc")
set(dsloadbalancer_proto_hdrs "${CMAKE_CURRENT_BINARY_DIR}/dsloadbalancer.pb.h")
set(dsloadbalancer_grpc_srcs "${CMAKE_CURRENT_BINARY_DIR}/dsloadbalancer.grpc.pb.cc")
set(dsloadbalancer_grpc_hdrs "${CMAKE_CURRENT_BINARY_DIR}/dsloadbalancer.grpc.pb.h")
add_custom_command(
      OUTPUT "${dsloadbalancer_proto_srcs}" "${dsloadbalancer_proto_hdrs}" "${dsloadbalancer_grpc_srcs}" "${dsloadbalancer_grpc_hdrs}"
      COMMAND ${_PROTOBUF_PROTOC}
      ARGS --grpc_out "${CMAKE_CURRENT_BINARY_DIR}"
        --cpp_out "${CMAKE_CURRENT_BINARY_DIR}"
        -I "${dsloadbalancer_proto_path}"
        --plugin=protoc-gen-grpc="${_GRPC_CPP_PLUGIN_EXECUTABLE}"
        "${dsloadbalancer_proto}"
      DEPENDS "${dsloadbalancer_proto}")

# Include generated *.pb.h files
include_directories("${CMAKE_CURRENT_BINARY_DIR}")

# Each .cpp file in your project
set(SOURCE_FILES
    "Application.cpp"
    "StorageCoordinator.cpp"
    "StorageNode.cpp"
    "WorkerNode.cpp"
    "WorkloadCoordinator.cpp"
    "main.cpp"
    "generateData.cpp"
    "threadPool.cpp"
)

# Include your header files directory
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# List of source files that have main functions and need executables
set(MAIN_FILES
    "StorageNode.cpp"
    "WorkerNode.cpp"
    "main.cpp"
    "generateData.cpp"
)

# Targets
foreach(_source_file ${SOURCE_FILES})
    get_filename_component(_target_name "${_source_file}" NAME_WE) # Get the target name from the .cpp filename

    # Check if this source file is in the list of files that need an executable
    list(FIND MAIN_FILES "${_source_file}" _index)
    if(${_index} GREATER -1)
        add_executable(${_target_name} "${_source_file}"
            ${dsloadbalancer_proto_srcs}
            ${dsloadbalancer_grpc_srcs})
        target_link_libraries(${_target_name}
            ${_GRPC_GRPCPP}
            ${_PROTOBUF_LIBPROTOBUF})
    endif()
endforeach()

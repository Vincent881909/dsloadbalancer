# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.27.8/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.27.8/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/vincentkohm/Documents/UBC/416/Capstone/dsloadbalancer/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/vincentkohm/Documents/UBC/416/Capstone/dsloadbalancer/src/cmake/build

# Include any dependencies generated for this target.
include CMakeFiles/client.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/client.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/client.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/client.dir/flags.make

dsloadbalancer.pb.cc: /Users/vincentkohm/Documents/UBC/416/Capstone/dsloadbalancer/src/dsloadbalancer.proto
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/vincentkohm/Documents/UBC/416/Capstone/dsloadbalancer/src/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating dsloadbalancer.pb.cc, dsloadbalancer.pb.h, dsloadbalancer.grpc.pb.cc, dsloadbalancer.grpc.pb.h"
	/Users/vincentkohm/.local/bin/protoc-23.4.0 --grpc_out /Users/vincentkohm/Documents/UBC/416/Capstone/dsloadbalancer/src/cmake/build --cpp_out /Users/vincentkohm/Documents/UBC/416/Capstone/dsloadbalancer/src/cmake/build -I /Users/vincentkohm/Documents/UBC/416/Capstone/dsloadbalancer/src --plugin=protoc-gen-grpc="/Users/vincentkohm/.local/bin/grpc_cpp_plugin" /Users/vincentkohm/Documents/UBC/416/Capstone/dsloadbalancer/src/dsloadbalancer.proto

dsloadbalancer.pb.h: dsloadbalancer.pb.cc
	@$(CMAKE_COMMAND) -E touch_nocreate dsloadbalancer.pb.h

dsloadbalancer.grpc.pb.cc: dsloadbalancer.pb.cc
	@$(CMAKE_COMMAND) -E touch_nocreate dsloadbalancer.grpc.pb.cc

dsloadbalancer.grpc.pb.h: dsloadbalancer.pb.cc
	@$(CMAKE_COMMAND) -E touch_nocreate dsloadbalancer.grpc.pb.h

CMakeFiles/client.dir/client.cpp.o: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/client.cpp.o: /Users/vincentkohm/Documents/UBC/416/Capstone/dsloadbalancer/src/client.cpp
CMakeFiles/client.dir/client.cpp.o: CMakeFiles/client.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/vincentkohm/Documents/UBC/416/Capstone/dsloadbalancer/src/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/client.dir/client.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/client.dir/client.cpp.o -MF CMakeFiles/client.dir/client.cpp.o.d -o CMakeFiles/client.dir/client.cpp.o -c /Users/vincentkohm/Documents/UBC/416/Capstone/dsloadbalancer/src/client.cpp

CMakeFiles/client.dir/client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/client.dir/client.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vincentkohm/Documents/UBC/416/Capstone/dsloadbalancer/src/client.cpp > CMakeFiles/client.dir/client.cpp.i

CMakeFiles/client.dir/client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/client.dir/client.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vincentkohm/Documents/UBC/416/Capstone/dsloadbalancer/src/client.cpp -o CMakeFiles/client.dir/client.cpp.s

CMakeFiles/client.dir/dsloadbalancer.pb.cc.o: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/dsloadbalancer.pb.cc.o: dsloadbalancer.pb.cc
CMakeFiles/client.dir/dsloadbalancer.pb.cc.o: CMakeFiles/client.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/vincentkohm/Documents/UBC/416/Capstone/dsloadbalancer/src/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/client.dir/dsloadbalancer.pb.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/client.dir/dsloadbalancer.pb.cc.o -MF CMakeFiles/client.dir/dsloadbalancer.pb.cc.o.d -o CMakeFiles/client.dir/dsloadbalancer.pb.cc.o -c /Users/vincentkohm/Documents/UBC/416/Capstone/dsloadbalancer/src/cmake/build/dsloadbalancer.pb.cc

CMakeFiles/client.dir/dsloadbalancer.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/client.dir/dsloadbalancer.pb.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vincentkohm/Documents/UBC/416/Capstone/dsloadbalancer/src/cmake/build/dsloadbalancer.pb.cc > CMakeFiles/client.dir/dsloadbalancer.pb.cc.i

CMakeFiles/client.dir/dsloadbalancer.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/client.dir/dsloadbalancer.pb.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vincentkohm/Documents/UBC/416/Capstone/dsloadbalancer/src/cmake/build/dsloadbalancer.pb.cc -o CMakeFiles/client.dir/dsloadbalancer.pb.cc.s

CMakeFiles/client.dir/dsloadbalancer.grpc.pb.cc.o: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/dsloadbalancer.grpc.pb.cc.o: dsloadbalancer.grpc.pb.cc
CMakeFiles/client.dir/dsloadbalancer.grpc.pb.cc.o: CMakeFiles/client.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/vincentkohm/Documents/UBC/416/Capstone/dsloadbalancer/src/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/client.dir/dsloadbalancer.grpc.pb.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/client.dir/dsloadbalancer.grpc.pb.cc.o -MF CMakeFiles/client.dir/dsloadbalancer.grpc.pb.cc.o.d -o CMakeFiles/client.dir/dsloadbalancer.grpc.pb.cc.o -c /Users/vincentkohm/Documents/UBC/416/Capstone/dsloadbalancer/src/cmake/build/dsloadbalancer.grpc.pb.cc

CMakeFiles/client.dir/dsloadbalancer.grpc.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/client.dir/dsloadbalancer.grpc.pb.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vincentkohm/Documents/UBC/416/Capstone/dsloadbalancer/src/cmake/build/dsloadbalancer.grpc.pb.cc > CMakeFiles/client.dir/dsloadbalancer.grpc.pb.cc.i

CMakeFiles/client.dir/dsloadbalancer.grpc.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/client.dir/dsloadbalancer.grpc.pb.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vincentkohm/Documents/UBC/416/Capstone/dsloadbalancer/src/cmake/build/dsloadbalancer.grpc.pb.cc -o CMakeFiles/client.dir/dsloadbalancer.grpc.pb.cc.s

# Object files for target client
client_OBJECTS = \
"CMakeFiles/client.dir/client.cpp.o" \
"CMakeFiles/client.dir/dsloadbalancer.pb.cc.o" \
"CMakeFiles/client.dir/dsloadbalancer.grpc.pb.cc.o"

# External object files for target client
client_EXTERNAL_OBJECTS =

client: CMakeFiles/client.dir/client.cpp.o
client: CMakeFiles/client.dir/dsloadbalancer.pb.cc.o
client: CMakeFiles/client.dir/dsloadbalancer.grpc.pb.cc.o
client: CMakeFiles/client.dir/build.make
client: /Users/vincentkohm/.local/lib/libgrpc++.a
client: /Users/vincentkohm/.local/lib/libgrpc.a
client: /Users/vincentkohm/.local/lib/libre2.a
client: /Users/vincentkohm/.local/lib/libupb_json_lib.a
client: /Users/vincentkohm/.local/lib/libupb_textformat_lib.a
client: /Users/vincentkohm/.local/lib/libupb_collections_lib.a
client: /Users/vincentkohm/.local/lib/libupb.a
client: /Users/vincentkohm/.local/lib/libutf8_range_lib.a
client: /Users/vincentkohm/.local/lib/libz.a
client: /Users/vincentkohm/.local/lib/libcares.a
client: /Users/vincentkohm/.local/lib/libgpr.a
client: /Users/vincentkohm/.local/lib/libabsl_random_distributions.a
client: /Users/vincentkohm/.local/lib/libabsl_random_seed_sequences.a
client: /Users/vincentkohm/.local/lib/libabsl_random_internal_pool_urbg.a
client: /Users/vincentkohm/.local/lib/libabsl_random_internal_randen.a
client: /Users/vincentkohm/.local/lib/libabsl_random_internal_randen_hwaes.a
client: /Users/vincentkohm/.local/lib/libabsl_random_internal_randen_hwaes_impl.a
client: /Users/vincentkohm/.local/lib/libabsl_random_internal_randen_slow.a
client: /Users/vincentkohm/.local/lib/libabsl_random_internal_platform.a
client: /Users/vincentkohm/.local/lib/libabsl_random_internal_seed_material.a
client: /Users/vincentkohm/.local/lib/libabsl_random_seed_gen_exception.a
client: /Users/vincentkohm/.local/lib/libssl.a
client: /Users/vincentkohm/.local/lib/libcrypto.a
client: /Users/vincentkohm/.local/lib/libaddress_sorting.a
client: /Users/vincentkohm/.local/lib/libprotobuf.a
client: /Users/vincentkohm/.local/lib/libabsl_statusor.a
client: /Users/vincentkohm/.local/lib/libabsl_log_internal_check_op.a
client: /Users/vincentkohm/.local/lib/libabsl_leak_check.a
client: /Users/vincentkohm/.local/lib/libabsl_die_if_null.a
client: /Users/vincentkohm/.local/lib/libabsl_log_internal_conditions.a
client: /Users/vincentkohm/.local/lib/libabsl_log_internal_message.a
client: /Users/vincentkohm/.local/lib/libabsl_log_internal_nullguard.a
client: /Users/vincentkohm/.local/lib/libabsl_examine_stack.a
client: /Users/vincentkohm/.local/lib/libabsl_log_internal_format.a
client: /Users/vincentkohm/.local/lib/libabsl_log_internal_proto.a
client: /Users/vincentkohm/.local/lib/libabsl_log_internal_log_sink_set.a
client: /Users/vincentkohm/.local/lib/libabsl_log_sink.a
client: /Users/vincentkohm/.local/lib/libabsl_log_entry.a
client: /Users/vincentkohm/.local/lib/libabsl_flags.a
client: /Users/vincentkohm/.local/lib/libabsl_flags_internal.a
client: /Users/vincentkohm/.local/lib/libabsl_flags_marshalling.a
client: /Users/vincentkohm/.local/lib/libabsl_flags_reflection.a
client: /Users/vincentkohm/.local/lib/libabsl_flags_config.a
client: /Users/vincentkohm/.local/lib/libabsl_flags_program_name.a
client: /Users/vincentkohm/.local/lib/libabsl_flags_private_handle_accessor.a
client: /Users/vincentkohm/.local/lib/libabsl_flags_commandlineflag.a
client: /Users/vincentkohm/.local/lib/libabsl_flags_commandlineflag_internal.a
client: /Users/vincentkohm/.local/lib/libabsl_log_initialize.a
client: /Users/vincentkohm/.local/lib/libabsl_log_globals.a
client: /Users/vincentkohm/.local/lib/libabsl_log_internal_globals.a
client: /Users/vincentkohm/.local/lib/libabsl_raw_hash_set.a
client: /Users/vincentkohm/.local/lib/libabsl_hash.a
client: /Users/vincentkohm/.local/lib/libabsl_city.a
client: /Users/vincentkohm/.local/lib/libabsl_low_level_hash.a
client: /Users/vincentkohm/.local/lib/libabsl_hashtablez_sampler.a
client: /Users/vincentkohm/.local/lib/libabsl_status.a
client: /Users/vincentkohm/.local/lib/libabsl_cord.a
client: /Users/vincentkohm/.local/lib/libabsl_cordz_info.a
client: /Users/vincentkohm/.local/lib/libabsl_cord_internal.a
client: /Users/vincentkohm/.local/lib/libabsl_cordz_functions.a
client: /Users/vincentkohm/.local/lib/libabsl_exponential_biased.a
client: /Users/vincentkohm/.local/lib/libabsl_cordz_handle.a
client: /Users/vincentkohm/.local/lib/libabsl_crc_cord_state.a
client: /Users/vincentkohm/.local/lib/libabsl_crc32c.a
client: /Users/vincentkohm/.local/lib/libabsl_crc_internal.a
client: /Users/vincentkohm/.local/lib/libabsl_crc_cpu_detect.a
client: /Users/vincentkohm/.local/lib/libabsl_bad_optional_access.a
client: /Users/vincentkohm/.local/lib/libabsl_str_format_internal.a
client: /Users/vincentkohm/.local/lib/libabsl_strerror.a
client: /Users/vincentkohm/.local/lib/libabsl_synchronization.a
client: /Users/vincentkohm/.local/lib/libabsl_stacktrace.a
client: /Users/vincentkohm/.local/lib/libabsl_symbolize.a
client: /Users/vincentkohm/.local/lib/libabsl_debugging_internal.a
client: /Users/vincentkohm/.local/lib/libabsl_demangle_internal.a
client: /Users/vincentkohm/.local/lib/libabsl_graphcycles_internal.a
client: /Users/vincentkohm/.local/lib/libabsl_kernel_timeout_internal.a
client: /Users/vincentkohm/.local/lib/libabsl_malloc_internal.a
client: /Users/vincentkohm/.local/lib/libabsl_time.a
client: /Users/vincentkohm/.local/lib/libabsl_civil_time.a
client: /Users/vincentkohm/.local/lib/libabsl_time_zone.a
client: /Users/vincentkohm/.local/lib/libabsl_bad_variant_access.a
client: /Users/vincentkohm/.local/lib/libutf8_validity.a
client: /Users/vincentkohm/.local/lib/libabsl_strings.a
client: /Users/vincentkohm/.local/lib/libabsl_int128.a
client: /Users/vincentkohm/.local/lib/libabsl_string_view.a
client: /Users/vincentkohm/.local/lib/libabsl_throw_delegate.a
client: /Users/vincentkohm/.local/lib/libabsl_strings_internal.a
client: /Users/vincentkohm/.local/lib/libabsl_base.a
client: /Users/vincentkohm/.local/lib/libabsl_spinlock_wait.a
client: /Users/vincentkohm/.local/lib/libabsl_raw_logging_internal.a
client: /Users/vincentkohm/.local/lib/libabsl_log_severity.a
client: CMakeFiles/client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/vincentkohm/Documents/UBC/416/Capstone/dsloadbalancer/src/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable client"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/client.dir/build: client
.PHONY : CMakeFiles/client.dir/build

CMakeFiles/client.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/client.dir/cmake_clean.cmake
.PHONY : CMakeFiles/client.dir/clean

CMakeFiles/client.dir/depend: dsloadbalancer.grpc.pb.cc
CMakeFiles/client.dir/depend: dsloadbalancer.grpc.pb.h
CMakeFiles/client.dir/depend: dsloadbalancer.pb.cc
CMakeFiles/client.dir/depend: dsloadbalancer.pb.h
	cd /Users/vincentkohm/Documents/UBC/416/Capstone/dsloadbalancer/src/cmake/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/vincentkohm/Documents/UBC/416/Capstone/dsloadbalancer/src /Users/vincentkohm/Documents/UBC/416/Capstone/dsloadbalancer/src /Users/vincentkohm/Documents/UBC/416/Capstone/dsloadbalancer/src/cmake/build /Users/vincentkohm/Documents/UBC/416/Capstone/dsloadbalancer/src/cmake/build /Users/vincentkohm/Documents/UBC/416/Capstone/dsloadbalancer/src/cmake/build/CMakeFiles/client.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/client.dir/depend

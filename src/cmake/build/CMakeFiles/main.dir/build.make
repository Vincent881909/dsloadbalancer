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
include CMakeFiles/main.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/main.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.dir/flags.make

dsloadbalancer.pb.cc: /Users/vincentkohm/Documents/UBC/416/Capstone/dsloadbalancer/src/dsloadbalancer.proto
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/vincentkohm/Documents/UBC/416/Capstone/dsloadbalancer/src/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating dsloadbalancer.pb.cc, dsloadbalancer.pb.h, dsloadbalancer.grpc.pb.cc, dsloadbalancer.grpc.pb.h"
	/Users/vincentkohm/.local/bin/protoc-23.4.0 --grpc_out /Users/vincentkohm/Documents/UBC/416/Capstone/dsloadbalancer/src/cmake/build --cpp_out /Users/vincentkohm/Documents/UBC/416/Capstone/dsloadbalancer/src/cmake/build -I /Users/vincentkohm/Documents/UBC/416/Capstone/dsloadbalancer/src --plugin=protoc-gen-grpc="/Users/vincentkohm/.local/bin/grpc_cpp_plugin" /Users/vincentkohm/Documents/UBC/416/Capstone/dsloadbalancer/src/dsloadbalancer.proto

dsloadbalancer.pb.h: dsloadbalancer.pb.cc
	@$(CMAKE_COMMAND) -E touch_nocreate dsloadbalancer.pb.h

dsloadbalancer.grpc.pb.cc: dsloadbalancer.pb.cc
	@$(CMAKE_COMMAND) -E touch_nocreate dsloadbalancer.grpc.pb.cc

dsloadbalancer.grpc.pb.h: dsloadbalancer.pb.cc
	@$(CMAKE_COMMAND) -E touch_nocreate dsloadbalancer.grpc.pb.h

CMakeFiles/main.dir/main.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/main.cpp.o: /Users/vincentkohm/Documents/UBC/416/Capstone/dsloadbalancer/src/main.cpp
CMakeFiles/main.dir/main.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/vincentkohm/Documents/UBC/416/Capstone/dsloadbalancer/src/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/main.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/main.cpp.o -MF CMakeFiles/main.dir/main.cpp.o.d -o CMakeFiles/main.dir/main.cpp.o -c /Users/vincentkohm/Documents/UBC/416/Capstone/dsloadbalancer/src/main.cpp

CMakeFiles/main.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vincentkohm/Documents/UBC/416/Capstone/dsloadbalancer/src/main.cpp > CMakeFiles/main.dir/main.cpp.i

CMakeFiles/main.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vincentkohm/Documents/UBC/416/Capstone/dsloadbalancer/src/main.cpp -o CMakeFiles/main.dir/main.cpp.s

CMakeFiles/main.dir/dsloadbalancer.pb.cc.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/dsloadbalancer.pb.cc.o: dsloadbalancer.pb.cc
CMakeFiles/main.dir/dsloadbalancer.pb.cc.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/vincentkohm/Documents/UBC/416/Capstone/dsloadbalancer/src/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/main.dir/dsloadbalancer.pb.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/dsloadbalancer.pb.cc.o -MF CMakeFiles/main.dir/dsloadbalancer.pb.cc.o.d -o CMakeFiles/main.dir/dsloadbalancer.pb.cc.o -c /Users/vincentkohm/Documents/UBC/416/Capstone/dsloadbalancer/src/cmake/build/dsloadbalancer.pb.cc

CMakeFiles/main.dir/dsloadbalancer.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/dsloadbalancer.pb.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vincentkohm/Documents/UBC/416/Capstone/dsloadbalancer/src/cmake/build/dsloadbalancer.pb.cc > CMakeFiles/main.dir/dsloadbalancer.pb.cc.i

CMakeFiles/main.dir/dsloadbalancer.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/dsloadbalancer.pb.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vincentkohm/Documents/UBC/416/Capstone/dsloadbalancer/src/cmake/build/dsloadbalancer.pb.cc -o CMakeFiles/main.dir/dsloadbalancer.pb.cc.s

CMakeFiles/main.dir/dsloadbalancer.grpc.pb.cc.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/dsloadbalancer.grpc.pb.cc.o: dsloadbalancer.grpc.pb.cc
CMakeFiles/main.dir/dsloadbalancer.grpc.pb.cc.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/vincentkohm/Documents/UBC/416/Capstone/dsloadbalancer/src/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/main.dir/dsloadbalancer.grpc.pb.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/dsloadbalancer.grpc.pb.cc.o -MF CMakeFiles/main.dir/dsloadbalancer.grpc.pb.cc.o.d -o CMakeFiles/main.dir/dsloadbalancer.grpc.pb.cc.o -c /Users/vincentkohm/Documents/UBC/416/Capstone/dsloadbalancer/src/cmake/build/dsloadbalancer.grpc.pb.cc

CMakeFiles/main.dir/dsloadbalancer.grpc.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/dsloadbalancer.grpc.pb.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vincentkohm/Documents/UBC/416/Capstone/dsloadbalancer/src/cmake/build/dsloadbalancer.grpc.pb.cc > CMakeFiles/main.dir/dsloadbalancer.grpc.pb.cc.i

CMakeFiles/main.dir/dsloadbalancer.grpc.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/dsloadbalancer.grpc.pb.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vincentkohm/Documents/UBC/416/Capstone/dsloadbalancer/src/cmake/build/dsloadbalancer.grpc.pb.cc -o CMakeFiles/main.dir/dsloadbalancer.grpc.pb.cc.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/main.cpp.o" \
"CMakeFiles/main.dir/dsloadbalancer.pb.cc.o" \
"CMakeFiles/main.dir/dsloadbalancer.grpc.pb.cc.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

main: CMakeFiles/main.dir/main.cpp.o
main: CMakeFiles/main.dir/dsloadbalancer.pb.cc.o
main: CMakeFiles/main.dir/dsloadbalancer.grpc.pb.cc.o
main: CMakeFiles/main.dir/build.make
main: /Users/vincentkohm/.local/lib/libgrpc++.a
main: /Users/vincentkohm/.local/lib/libgrpc.a
main: /Users/vincentkohm/.local/lib/libre2.a
main: /Users/vincentkohm/.local/lib/libupb_json_lib.a
main: /Users/vincentkohm/.local/lib/libupb_textformat_lib.a
main: /Users/vincentkohm/.local/lib/libupb_collections_lib.a
main: /Users/vincentkohm/.local/lib/libupb.a
main: /Users/vincentkohm/.local/lib/libutf8_range_lib.a
main: /Users/vincentkohm/.local/lib/libz.a
main: /Users/vincentkohm/.local/lib/libcares.a
main: /Users/vincentkohm/.local/lib/libgpr.a
main: /Users/vincentkohm/.local/lib/libabsl_random_distributions.a
main: /Users/vincentkohm/.local/lib/libabsl_random_seed_sequences.a
main: /Users/vincentkohm/.local/lib/libabsl_random_internal_pool_urbg.a
main: /Users/vincentkohm/.local/lib/libabsl_random_internal_randen.a
main: /Users/vincentkohm/.local/lib/libabsl_random_internal_randen_hwaes.a
main: /Users/vincentkohm/.local/lib/libabsl_random_internal_randen_hwaes_impl.a
main: /Users/vincentkohm/.local/lib/libabsl_random_internal_randen_slow.a
main: /Users/vincentkohm/.local/lib/libabsl_random_internal_platform.a
main: /Users/vincentkohm/.local/lib/libabsl_random_internal_seed_material.a
main: /Users/vincentkohm/.local/lib/libabsl_random_seed_gen_exception.a
main: /Users/vincentkohm/.local/lib/libssl.a
main: /Users/vincentkohm/.local/lib/libcrypto.a
main: /Users/vincentkohm/.local/lib/libaddress_sorting.a
main: /Users/vincentkohm/.local/lib/libprotobuf.a
main: /Users/vincentkohm/.local/lib/libabsl_statusor.a
main: /Users/vincentkohm/.local/lib/libabsl_log_internal_check_op.a
main: /Users/vincentkohm/.local/lib/libabsl_leak_check.a
main: /Users/vincentkohm/.local/lib/libabsl_die_if_null.a
main: /Users/vincentkohm/.local/lib/libabsl_log_internal_conditions.a
main: /Users/vincentkohm/.local/lib/libabsl_log_internal_message.a
main: /Users/vincentkohm/.local/lib/libabsl_log_internal_nullguard.a
main: /Users/vincentkohm/.local/lib/libabsl_examine_stack.a
main: /Users/vincentkohm/.local/lib/libabsl_log_internal_format.a
main: /Users/vincentkohm/.local/lib/libabsl_log_internal_proto.a
main: /Users/vincentkohm/.local/lib/libabsl_log_internal_log_sink_set.a
main: /Users/vincentkohm/.local/lib/libabsl_log_sink.a
main: /Users/vincentkohm/.local/lib/libabsl_log_entry.a
main: /Users/vincentkohm/.local/lib/libabsl_flags.a
main: /Users/vincentkohm/.local/lib/libabsl_flags_internal.a
main: /Users/vincentkohm/.local/lib/libabsl_flags_marshalling.a
main: /Users/vincentkohm/.local/lib/libabsl_flags_reflection.a
main: /Users/vincentkohm/.local/lib/libabsl_flags_config.a
main: /Users/vincentkohm/.local/lib/libabsl_flags_program_name.a
main: /Users/vincentkohm/.local/lib/libabsl_flags_private_handle_accessor.a
main: /Users/vincentkohm/.local/lib/libabsl_flags_commandlineflag.a
main: /Users/vincentkohm/.local/lib/libabsl_flags_commandlineflag_internal.a
main: /Users/vincentkohm/.local/lib/libabsl_log_initialize.a
main: /Users/vincentkohm/.local/lib/libabsl_log_globals.a
main: /Users/vincentkohm/.local/lib/libabsl_log_internal_globals.a
main: /Users/vincentkohm/.local/lib/libabsl_raw_hash_set.a
main: /Users/vincentkohm/.local/lib/libabsl_hash.a
main: /Users/vincentkohm/.local/lib/libabsl_city.a
main: /Users/vincentkohm/.local/lib/libabsl_low_level_hash.a
main: /Users/vincentkohm/.local/lib/libabsl_hashtablez_sampler.a
main: /Users/vincentkohm/.local/lib/libabsl_status.a
main: /Users/vincentkohm/.local/lib/libabsl_cord.a
main: /Users/vincentkohm/.local/lib/libabsl_cordz_info.a
main: /Users/vincentkohm/.local/lib/libabsl_cord_internal.a
main: /Users/vincentkohm/.local/lib/libabsl_cordz_functions.a
main: /Users/vincentkohm/.local/lib/libabsl_exponential_biased.a
main: /Users/vincentkohm/.local/lib/libabsl_cordz_handle.a
main: /Users/vincentkohm/.local/lib/libabsl_crc_cord_state.a
main: /Users/vincentkohm/.local/lib/libabsl_crc32c.a
main: /Users/vincentkohm/.local/lib/libabsl_crc_internal.a
main: /Users/vincentkohm/.local/lib/libabsl_crc_cpu_detect.a
main: /Users/vincentkohm/.local/lib/libabsl_bad_optional_access.a
main: /Users/vincentkohm/.local/lib/libabsl_str_format_internal.a
main: /Users/vincentkohm/.local/lib/libabsl_strerror.a
main: /Users/vincentkohm/.local/lib/libabsl_synchronization.a
main: /Users/vincentkohm/.local/lib/libabsl_stacktrace.a
main: /Users/vincentkohm/.local/lib/libabsl_symbolize.a
main: /Users/vincentkohm/.local/lib/libabsl_debugging_internal.a
main: /Users/vincentkohm/.local/lib/libabsl_demangle_internal.a
main: /Users/vincentkohm/.local/lib/libabsl_graphcycles_internal.a
main: /Users/vincentkohm/.local/lib/libabsl_kernel_timeout_internal.a
main: /Users/vincentkohm/.local/lib/libabsl_malloc_internal.a
main: /Users/vincentkohm/.local/lib/libabsl_time.a
main: /Users/vincentkohm/.local/lib/libabsl_civil_time.a
main: /Users/vincentkohm/.local/lib/libabsl_time_zone.a
main: /Users/vincentkohm/.local/lib/libabsl_bad_variant_access.a
main: /Users/vincentkohm/.local/lib/libutf8_validity.a
main: /Users/vincentkohm/.local/lib/libabsl_strings.a
main: /Users/vincentkohm/.local/lib/libabsl_int128.a
main: /Users/vincentkohm/.local/lib/libabsl_string_view.a
main: /Users/vincentkohm/.local/lib/libabsl_throw_delegate.a
main: /Users/vincentkohm/.local/lib/libabsl_strings_internal.a
main: /Users/vincentkohm/.local/lib/libabsl_base.a
main: /Users/vincentkohm/.local/lib/libabsl_spinlock_wait.a
main: /Users/vincentkohm/.local/lib/libabsl_raw_logging_internal.a
main: /Users/vincentkohm/.local/lib/libabsl_log_severity.a
main: CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/vincentkohm/Documents/UBC/416/Capstone/dsloadbalancer/src/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main.dir/build: main
.PHONY : CMakeFiles/main.dir/build

CMakeFiles/main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main.dir/clean

CMakeFiles/main.dir/depend: dsloadbalancer.grpc.pb.cc
CMakeFiles/main.dir/depend: dsloadbalancer.grpc.pb.h
CMakeFiles/main.dir/depend: dsloadbalancer.pb.cc
CMakeFiles/main.dir/depend: dsloadbalancer.pb.h
	cd /Users/vincentkohm/Documents/UBC/416/Capstone/dsloadbalancer/src/cmake/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/vincentkohm/Documents/UBC/416/Capstone/dsloadbalancer/src /Users/vincentkohm/Documents/UBC/416/Capstone/dsloadbalancer/src /Users/vincentkohm/Documents/UBC/416/Capstone/dsloadbalancer/src/cmake/build /Users/vincentkohm/Documents/UBC/416/Capstone/dsloadbalancer/src/cmake/build /Users/vincentkohm/Documents/UBC/416/Capstone/dsloadbalancer/src/cmake/build/CMakeFiles/main.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/main.dir/depend


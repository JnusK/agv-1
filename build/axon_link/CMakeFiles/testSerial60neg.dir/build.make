# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/eee/agv/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/eee/agv/build

# Include any dependencies generated for this target.
include axon_link/CMakeFiles/testSerial60neg.dir/depend.make

# Include the progress variables for this target.
include axon_link/CMakeFiles/testSerial60neg.dir/progress.make

# Include the compile flags for this target's objects.
include axon_link/CMakeFiles/testSerial60neg.dir/flags.make

axon_link/CMakeFiles/testSerial60neg.dir/src/testSerial60neg.cpp.o: axon_link/CMakeFiles/testSerial60neg.dir/flags.make
axon_link/CMakeFiles/testSerial60neg.dir/src/testSerial60neg.cpp.o: /home/eee/agv/src/axon_link/src/testSerial60neg.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/eee/agv/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object axon_link/CMakeFiles/testSerial60neg.dir/src/testSerial60neg.cpp.o"
	cd /home/eee/agv/build/axon_link && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/testSerial60neg.dir/src/testSerial60neg.cpp.o -c /home/eee/agv/src/axon_link/src/testSerial60neg.cpp

axon_link/CMakeFiles/testSerial60neg.dir/src/testSerial60neg.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testSerial60neg.dir/src/testSerial60neg.cpp.i"
	cd /home/eee/agv/build/axon_link && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/eee/agv/src/axon_link/src/testSerial60neg.cpp > CMakeFiles/testSerial60neg.dir/src/testSerial60neg.cpp.i

axon_link/CMakeFiles/testSerial60neg.dir/src/testSerial60neg.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testSerial60neg.dir/src/testSerial60neg.cpp.s"
	cd /home/eee/agv/build/axon_link && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/eee/agv/src/axon_link/src/testSerial60neg.cpp -o CMakeFiles/testSerial60neg.dir/src/testSerial60neg.cpp.s

axon_link/CMakeFiles/testSerial60neg.dir/src/testSerial60neg.cpp.o.requires:

.PHONY : axon_link/CMakeFiles/testSerial60neg.dir/src/testSerial60neg.cpp.o.requires

axon_link/CMakeFiles/testSerial60neg.dir/src/testSerial60neg.cpp.o.provides: axon_link/CMakeFiles/testSerial60neg.dir/src/testSerial60neg.cpp.o.requires
	$(MAKE) -f axon_link/CMakeFiles/testSerial60neg.dir/build.make axon_link/CMakeFiles/testSerial60neg.dir/src/testSerial60neg.cpp.o.provides.build
.PHONY : axon_link/CMakeFiles/testSerial60neg.dir/src/testSerial60neg.cpp.o.provides

axon_link/CMakeFiles/testSerial60neg.dir/src/testSerial60neg.cpp.o.provides.build: axon_link/CMakeFiles/testSerial60neg.dir/src/testSerial60neg.cpp.o


# Object files for target testSerial60neg
testSerial60neg_OBJECTS = \
"CMakeFiles/testSerial60neg.dir/src/testSerial60neg.cpp.o"

# External object files for target testSerial60neg
testSerial60neg_EXTERNAL_OBJECTS =

/home/eee/agv/devel/lib/axon_link/testSerial60neg: axon_link/CMakeFiles/testSerial60neg.dir/src/testSerial60neg.cpp.o
/home/eee/agv/devel/lib/axon_link/testSerial60neg: axon_link/CMakeFiles/testSerial60neg.dir/build.make
/home/eee/agv/devel/lib/axon_link/testSerial60neg: /home/eee/agv/devel/lib/libcereal_port.so
/home/eee/agv/devel/lib/axon_link/testSerial60neg: /home/eee/agv/devel/lib/libserial.so
/home/eee/agv/devel/lib/axon_link/testSerial60neg: /opt/ros/kinetic/lib/libtf.so
/home/eee/agv/devel/lib/axon_link/testSerial60neg: /opt/ros/kinetic/lib/libtf2_ros.so
/home/eee/agv/devel/lib/axon_link/testSerial60neg: /opt/ros/kinetic/lib/libactionlib.so
/home/eee/agv/devel/lib/axon_link/testSerial60neg: /opt/ros/kinetic/lib/libmessage_filters.so
/home/eee/agv/devel/lib/axon_link/testSerial60neg: /opt/ros/kinetic/lib/libroscpp.so
/home/eee/agv/devel/lib/axon_link/testSerial60neg: /usr/lib/x86_64-linux-gnu/libboost_signals.so
/home/eee/agv/devel/lib/axon_link/testSerial60neg: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
/home/eee/agv/devel/lib/axon_link/testSerial60neg: /opt/ros/kinetic/lib/libxmlrpcpp.so
/home/eee/agv/devel/lib/axon_link/testSerial60neg: /opt/ros/kinetic/lib/libtf2.so
/home/eee/agv/devel/lib/axon_link/testSerial60neg: /opt/ros/kinetic/lib/libroscpp_serialization.so
/home/eee/agv/devel/lib/axon_link/testSerial60neg: /opt/ros/kinetic/lib/librosconsole.so
/home/eee/agv/devel/lib/axon_link/testSerial60neg: /opt/ros/kinetic/lib/librosconsole_log4cxx.so
/home/eee/agv/devel/lib/axon_link/testSerial60neg: /opt/ros/kinetic/lib/librosconsole_backend_interface.so
/home/eee/agv/devel/lib/axon_link/testSerial60neg: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
/home/eee/agv/devel/lib/axon_link/testSerial60neg: /usr/lib/x86_64-linux-gnu/libboost_regex.so
/home/eee/agv/devel/lib/axon_link/testSerial60neg: /opt/ros/kinetic/lib/librostime.so
/home/eee/agv/devel/lib/axon_link/testSerial60neg: /opt/ros/kinetic/lib/libcpp_common.so
/home/eee/agv/devel/lib/axon_link/testSerial60neg: /usr/lib/x86_64-linux-gnu/libboost_system.so
/home/eee/agv/devel/lib/axon_link/testSerial60neg: /usr/lib/x86_64-linux-gnu/libboost_thread.so
/home/eee/agv/devel/lib/axon_link/testSerial60neg: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
/home/eee/agv/devel/lib/axon_link/testSerial60neg: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
/home/eee/agv/devel/lib/axon_link/testSerial60neg: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
/home/eee/agv/devel/lib/axon_link/testSerial60neg: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/eee/agv/devel/lib/axon_link/testSerial60neg: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so
/home/eee/agv/devel/lib/axon_link/testSerial60neg: axon_link/CMakeFiles/testSerial60neg.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/eee/agv/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/eee/agv/devel/lib/axon_link/testSerial60neg"
	cd /home/eee/agv/build/axon_link && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testSerial60neg.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
axon_link/CMakeFiles/testSerial60neg.dir/build: /home/eee/agv/devel/lib/axon_link/testSerial60neg

.PHONY : axon_link/CMakeFiles/testSerial60neg.dir/build

axon_link/CMakeFiles/testSerial60neg.dir/requires: axon_link/CMakeFiles/testSerial60neg.dir/src/testSerial60neg.cpp.o.requires

.PHONY : axon_link/CMakeFiles/testSerial60neg.dir/requires

axon_link/CMakeFiles/testSerial60neg.dir/clean:
	cd /home/eee/agv/build/axon_link && $(CMAKE_COMMAND) -P CMakeFiles/testSerial60neg.dir/cmake_clean.cmake
.PHONY : axon_link/CMakeFiles/testSerial60neg.dir/clean

axon_link/CMakeFiles/testSerial60neg.dir/depend:
	cd /home/eee/agv/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/eee/agv/src /home/eee/agv/src/axon_link /home/eee/agv/build /home/eee/agv/build/axon_link /home/eee/agv/build/axon_link/CMakeFiles/testSerial60neg.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : axon_link/CMakeFiles/testSerial60neg.dir/depend


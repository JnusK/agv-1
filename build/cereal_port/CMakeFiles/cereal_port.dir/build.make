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
CMAKE_SOURCE_DIR = /home/eee/lingfei_ws/agv/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/eee/lingfei_ws/agv/build

# Include any dependencies generated for this target.
include cereal_port/CMakeFiles/cereal_port.dir/depend.make

# Include the progress variables for this target.
include cereal_port/CMakeFiles/cereal_port.dir/progress.make

# Include the compile flags for this target's objects.
include cereal_port/CMakeFiles/cereal_port.dir/flags.make

cereal_port/CMakeFiles/cereal_port.dir/src/CerealPort.cpp.o: cereal_port/CMakeFiles/cereal_port.dir/flags.make
cereal_port/CMakeFiles/cereal_port.dir/src/CerealPort.cpp.o: /home/eee/lingfei_ws/agv/src/cereal_port/src/CerealPort.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/eee/lingfei_ws/agv/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object cereal_port/CMakeFiles/cereal_port.dir/src/CerealPort.cpp.o"
	cd /home/eee/lingfei_ws/agv/build/cereal_port && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cereal_port.dir/src/CerealPort.cpp.o -c /home/eee/lingfei_ws/agv/src/cereal_port/src/CerealPort.cpp

cereal_port/CMakeFiles/cereal_port.dir/src/CerealPort.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cereal_port.dir/src/CerealPort.cpp.i"
	cd /home/eee/lingfei_ws/agv/build/cereal_port && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/eee/lingfei_ws/agv/src/cereal_port/src/CerealPort.cpp > CMakeFiles/cereal_port.dir/src/CerealPort.cpp.i

cereal_port/CMakeFiles/cereal_port.dir/src/CerealPort.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cereal_port.dir/src/CerealPort.cpp.s"
	cd /home/eee/lingfei_ws/agv/build/cereal_port && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/eee/lingfei_ws/agv/src/cereal_port/src/CerealPort.cpp -o CMakeFiles/cereal_port.dir/src/CerealPort.cpp.s

cereal_port/CMakeFiles/cereal_port.dir/src/CerealPort.cpp.o.requires:

.PHONY : cereal_port/CMakeFiles/cereal_port.dir/src/CerealPort.cpp.o.requires

cereal_port/CMakeFiles/cereal_port.dir/src/CerealPort.cpp.o.provides: cereal_port/CMakeFiles/cereal_port.dir/src/CerealPort.cpp.o.requires
	$(MAKE) -f cereal_port/CMakeFiles/cereal_port.dir/build.make cereal_port/CMakeFiles/cereal_port.dir/src/CerealPort.cpp.o.provides.build
.PHONY : cereal_port/CMakeFiles/cereal_port.dir/src/CerealPort.cpp.o.provides

cereal_port/CMakeFiles/cereal_port.dir/src/CerealPort.cpp.o.provides.build: cereal_port/CMakeFiles/cereal_port.dir/src/CerealPort.cpp.o


# Object files for target cereal_port
cereal_port_OBJECTS = \
"CMakeFiles/cereal_port.dir/src/CerealPort.cpp.o"

# External object files for target cereal_port
cereal_port_EXTERNAL_OBJECTS =

/home/eee/lingfei_ws/agv/devel/lib/libcereal_port.so: cereal_port/CMakeFiles/cereal_port.dir/src/CerealPort.cpp.o
/home/eee/lingfei_ws/agv/devel/lib/libcereal_port.so: cereal_port/CMakeFiles/cereal_port.dir/build.make
/home/eee/lingfei_ws/agv/devel/lib/libcereal_port.so: cereal_port/CMakeFiles/cereal_port.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/eee/lingfei_ws/agv/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library /home/eee/lingfei_ws/agv/devel/lib/libcereal_port.so"
	cd /home/eee/lingfei_ws/agv/build/cereal_port && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cereal_port.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
cereal_port/CMakeFiles/cereal_port.dir/build: /home/eee/lingfei_ws/agv/devel/lib/libcereal_port.so

.PHONY : cereal_port/CMakeFiles/cereal_port.dir/build

cereal_port/CMakeFiles/cereal_port.dir/requires: cereal_port/CMakeFiles/cereal_port.dir/src/CerealPort.cpp.o.requires

.PHONY : cereal_port/CMakeFiles/cereal_port.dir/requires

cereal_port/CMakeFiles/cereal_port.dir/clean:
	cd /home/eee/lingfei_ws/agv/build/cereal_port && $(CMAKE_COMMAND) -P CMakeFiles/cereal_port.dir/cmake_clean.cmake
.PHONY : cereal_port/CMakeFiles/cereal_port.dir/clean

cereal_port/CMakeFiles/cereal_port.dir/depend:
	cd /home/eee/lingfei_ws/agv/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/eee/lingfei_ws/agv/src /home/eee/lingfei_ws/agv/src/cereal_port /home/eee/lingfei_ws/agv/build /home/eee/lingfei_ws/agv/build/cereal_port /home/eee/lingfei_ws/agv/build/cereal_port/CMakeFiles/cereal_port.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : cereal_port/CMakeFiles/cereal_port.dir/depend


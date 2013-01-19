# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/gael/emokit_test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gael/emokit_test

# Include any dependencies generated for this target.
include examples/emokit_osc/CMakeFiles/emokit_osc.dir/depend.make

# Include the progress variables for this target.
include examples/emokit_osc/CMakeFiles/emokit_osc.dir/progress.make

# Include the compile flags for this target's objects.
include examples/emokit_osc/CMakeFiles/emokit_osc.dir/flags.make

examples/emokit_osc/CMakeFiles/emokit_osc.dir/emokit_osc.cpp.o: examples/emokit_osc/CMakeFiles/emokit_osc.dir/flags.make
examples/emokit_osc/CMakeFiles/emokit_osc.dir/emokit_osc.cpp.o: examples/emokit_osc/emokit_osc.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/gael/emokit_test/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object examples/emokit_osc/CMakeFiles/emokit_osc.dir/emokit_osc.cpp.o"
	cd /home/gael/emokit_test/examples/emokit_osc && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/emokit_osc.dir/emokit_osc.cpp.o -c /home/gael/emokit_test/examples/emokit_osc/emokit_osc.cpp

examples/emokit_osc/CMakeFiles/emokit_osc.dir/emokit_osc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/emokit_osc.dir/emokit_osc.cpp.i"
	cd /home/gael/emokit_test/examples/emokit_osc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/gael/emokit_test/examples/emokit_osc/emokit_osc.cpp > CMakeFiles/emokit_osc.dir/emokit_osc.cpp.i

examples/emokit_osc/CMakeFiles/emokit_osc.dir/emokit_osc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/emokit_osc.dir/emokit_osc.cpp.s"
	cd /home/gael/emokit_test/examples/emokit_osc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/gael/emokit_test/examples/emokit_osc/emokit_osc.cpp -o CMakeFiles/emokit_osc.dir/emokit_osc.cpp.s

examples/emokit_osc/CMakeFiles/emokit_osc.dir/emokit_osc.cpp.o.requires:
.PHONY : examples/emokit_osc/CMakeFiles/emokit_osc.dir/emokit_osc.cpp.o.requires

examples/emokit_osc/CMakeFiles/emokit_osc.dir/emokit_osc.cpp.o.provides: examples/emokit_osc/CMakeFiles/emokit_osc.dir/emokit_osc.cpp.o.requires
	$(MAKE) -f examples/emokit_osc/CMakeFiles/emokit_osc.dir/build.make examples/emokit_osc/CMakeFiles/emokit_osc.dir/emokit_osc.cpp.o.provides.build
.PHONY : examples/emokit_osc/CMakeFiles/emokit_osc.dir/emokit_osc.cpp.o.provides

examples/emokit_osc/CMakeFiles/emokit_osc.dir/emokit_osc.cpp.o.provides.build: examples/emokit_osc/CMakeFiles/emokit_osc.dir/emokit_osc.cpp.o

# Object files for target emokit_osc
emokit_osc_OBJECTS = \
"CMakeFiles/emokit_osc.dir/emokit_osc.cpp.o"

# External object files for target emokit_osc
emokit_osc_EXTERNAL_OBJECTS =

bin/emokit_osc: examples/emokit_osc/CMakeFiles/emokit_osc.dir/emokit_osc.cpp.o
bin/emokit_osc: examples/emokit_osc/CMakeFiles/emokit_osc.dir/build.make
bin/emokit_osc: lib/liboscpack.a
bin/emokit_osc: lib/libemokit.a
bin/emokit_osc: /usr/local/lib/libfftw3.a
bin/emokit_osc: /usr/lib/libmcrypt.so
bin/emokit_osc: /usr/local/lib/libhidapi-hidraw.so
bin/emokit_osc: examples/emokit_osc/CMakeFiles/emokit_osc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../../bin/emokit_osc"
	cd /home/gael/emokit_test/examples/emokit_osc && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/emokit_osc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/emokit_osc/CMakeFiles/emokit_osc.dir/build: bin/emokit_osc
.PHONY : examples/emokit_osc/CMakeFiles/emokit_osc.dir/build

examples/emokit_osc/CMakeFiles/emokit_osc.dir/requires: examples/emokit_osc/CMakeFiles/emokit_osc.dir/emokit_osc.cpp.o.requires
.PHONY : examples/emokit_osc/CMakeFiles/emokit_osc.dir/requires

examples/emokit_osc/CMakeFiles/emokit_osc.dir/clean:
	cd /home/gael/emokit_test/examples/emokit_osc && $(CMAKE_COMMAND) -P CMakeFiles/emokit_osc.dir/cmake_clean.cmake
.PHONY : examples/emokit_osc/CMakeFiles/emokit_osc.dir/clean

examples/emokit_osc/CMakeFiles/emokit_osc.dir/depend:
	cd /home/gael/emokit_test && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gael/emokit_test /home/gael/emokit_test/examples/emokit_osc /home/gael/emokit_test /home/gael/emokit_test/examples/emokit_osc /home/gael/emokit_test/examples/emokit_osc/CMakeFiles/emokit_osc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/emokit_osc/CMakeFiles/emokit_osc.dir/depend

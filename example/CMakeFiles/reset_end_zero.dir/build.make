# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/prodefi/innfos-cpp-sdk/example

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/prodefi/innfos-cpp-sdk/example

# Include any dependencies generated for this target.
include CMakeFiles/reset_end_zero.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/reset_end_zero.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/reset_end_zero.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/reset_end_zero.dir/flags.make

CMakeFiles/reset_end_zero.dir/src/mytest/reset_end_zero.cpp.o: CMakeFiles/reset_end_zero.dir/flags.make
CMakeFiles/reset_end_zero.dir/src/mytest/reset_end_zero.cpp.o: src/mytest/reset_end_zero.cpp
CMakeFiles/reset_end_zero.dir/src/mytest/reset_end_zero.cpp.o: CMakeFiles/reset_end_zero.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/prodefi/innfos-cpp-sdk/example/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/reset_end_zero.dir/src/mytest/reset_end_zero.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/reset_end_zero.dir/src/mytest/reset_end_zero.cpp.o -MF CMakeFiles/reset_end_zero.dir/src/mytest/reset_end_zero.cpp.o.d -o CMakeFiles/reset_end_zero.dir/src/mytest/reset_end_zero.cpp.o -c /home/prodefi/innfos-cpp-sdk/example/src/mytest/reset_end_zero.cpp

CMakeFiles/reset_end_zero.dir/src/mytest/reset_end_zero.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/reset_end_zero.dir/src/mytest/reset_end_zero.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/prodefi/innfos-cpp-sdk/example/src/mytest/reset_end_zero.cpp > CMakeFiles/reset_end_zero.dir/src/mytest/reset_end_zero.cpp.i

CMakeFiles/reset_end_zero.dir/src/mytest/reset_end_zero.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/reset_end_zero.dir/src/mytest/reset_end_zero.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/prodefi/innfos-cpp-sdk/example/src/mytest/reset_end_zero.cpp -o CMakeFiles/reset_end_zero.dir/src/mytest/reset_end_zero.cpp.s

# Object files for target reset_end_zero
reset_end_zero_OBJECTS = \
"CMakeFiles/reset_end_zero.dir/src/mytest/reset_end_zero.cpp.o"

# External object files for target reset_end_zero
reset_end_zero_EXTERNAL_OBJECTS =

bin/reset_end_zero: CMakeFiles/reset_end_zero.dir/src/mytest/reset_end_zero.cpp.o
bin/reset_end_zero: CMakeFiles/reset_end_zero.dir/build.make
bin/reset_end_zero: CMakeFiles/reset_end_zero.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/prodefi/innfos-cpp-sdk/example/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bin/reset_end_zero"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/reset_end_zero.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/reset_end_zero.dir/build: bin/reset_end_zero
.PHONY : CMakeFiles/reset_end_zero.dir/build

CMakeFiles/reset_end_zero.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/reset_end_zero.dir/cmake_clean.cmake
.PHONY : CMakeFiles/reset_end_zero.dir/clean

CMakeFiles/reset_end_zero.dir/depend:
	cd /home/prodefi/innfos-cpp-sdk/example && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/prodefi/innfos-cpp-sdk/example /home/prodefi/innfos-cpp-sdk/example /home/prodefi/innfos-cpp-sdk/example /home/prodefi/innfos-cpp-sdk/example /home/prodefi/innfos-cpp-sdk/example/CMakeFiles/reset_end_zero.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/reset_end_zero.dir/depend


# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pi/solution/basis

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/solution/basis

# Include any dependencies generated for this target.
include source/console/readlines/CMakeFiles/_console_readlines.dir/depend.make

# Include the progress variables for this target.
include source/console/readlines/CMakeFiles/_console_readlines.dir/progress.make

# Include the compile flags for this target's objects.
include source/console/readlines/CMakeFiles/_console_readlines.dir/flags.make

source/console/readlines/CMakeFiles/_console_readlines.dir/main.cpp.o: source/console/readlines/CMakeFiles/_console_readlines.dir/flags.make
source/console/readlines/CMakeFiles/_console_readlines.dir/main.cpp.o: source/console/readlines/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/solution/basis/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object source/console/readlines/CMakeFiles/_console_readlines.dir/main.cpp.o"
	cd /home/pi/solution/basis/source/console/readlines && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/_console_readlines.dir/main.cpp.o -c /home/pi/solution/basis/source/console/readlines/main.cpp

source/console/readlines/CMakeFiles/_console_readlines.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/_console_readlines.dir/main.cpp.i"
	cd /home/pi/solution/basis/source/console/readlines && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/solution/basis/source/console/readlines/main.cpp > CMakeFiles/_console_readlines.dir/main.cpp.i

source/console/readlines/CMakeFiles/_console_readlines.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/_console_readlines.dir/main.cpp.s"
	cd /home/pi/solution/basis/source/console/readlines && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/solution/basis/source/console/readlines/main.cpp -o CMakeFiles/_console_readlines.dir/main.cpp.s

# Object files for target _console_readlines
_console_readlines_OBJECTS = \
"CMakeFiles/_console_readlines.dir/main.cpp.o"

# External object files for target _console_readlines
_console_readlines_EXTERNAL_OBJECTS =

output/_console_readlines: source/console/readlines/CMakeFiles/_console_readlines.dir/main.cpp.o
output/_console_readlines: source/console/readlines/CMakeFiles/_console_readlines.dir/build.make
output/_console_readlines: output/libaqua.so
output/_console_readlines: output/libapex.so
output/_console_readlines: output/libacme.so
output/_console_readlines: source/console/readlines/CMakeFiles/_console_readlines.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pi/solution/basis/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../../output/_console_readlines"
	cd /home/pi/solution/basis/source/console/readlines && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/_console_readlines.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
source/console/readlines/CMakeFiles/_console_readlines.dir/build: output/_console_readlines

.PHONY : source/console/readlines/CMakeFiles/_console_readlines.dir/build

source/console/readlines/CMakeFiles/_console_readlines.dir/clean:
	cd /home/pi/solution/basis/source/console/readlines && $(CMAKE_COMMAND) -P CMakeFiles/_console_readlines.dir/cmake_clean.cmake
.PHONY : source/console/readlines/CMakeFiles/_console_readlines.dir/clean

source/console/readlines/CMakeFiles/_console_readlines.dir/depend:
	cd /home/pi/solution/basis && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/solution/basis /home/pi/solution/basis/source/console/readlines /home/pi/solution/basis /home/pi/solution/basis/source/console/readlines /home/pi/solution/basis/source/console/readlines/CMakeFiles/_console_readlines.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : source/console/readlines/CMakeFiles/_console_readlines.dir/depend


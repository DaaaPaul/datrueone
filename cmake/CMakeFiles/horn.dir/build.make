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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/paulpeng/Programs/datrueone

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/paulpeng/Programs/datrueone/cmake

# Include any dependencies generated for this target.
include CMakeFiles/horn.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/horn.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/horn.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/horn.dir/flags.make

CMakeFiles/horn.dir/horn.cpp.o: CMakeFiles/horn.dir/flags.make
CMakeFiles/horn.dir/horn.cpp.o: /Users/paulpeng/Programs/datrueone/horn.cpp
CMakeFiles/horn.dir/horn.cpp.o: CMakeFiles/horn.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/paulpeng/Programs/datrueone/cmake/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/horn.dir/horn.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/horn.dir/horn.cpp.o -MF CMakeFiles/horn.dir/horn.cpp.o.d -o CMakeFiles/horn.dir/horn.cpp.o -c /Users/paulpeng/Programs/datrueone/horn.cpp

CMakeFiles/horn.dir/horn.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/horn.dir/horn.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/paulpeng/Programs/datrueone/horn.cpp > CMakeFiles/horn.dir/horn.cpp.i

CMakeFiles/horn.dir/horn.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/horn.dir/horn.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/paulpeng/Programs/datrueone/horn.cpp -o CMakeFiles/horn.dir/horn.cpp.s

# Object files for target horn
horn_OBJECTS = \
"CMakeFiles/horn.dir/horn.cpp.o"

# External object files for target horn
horn_EXTERNAL_OBJECTS =

horn: CMakeFiles/horn.dir/horn.cpp.o
horn: CMakeFiles/horn.dir/build.make
horn: CMakeFiles/horn.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/paulpeng/Programs/datrueone/cmake/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable horn"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/horn.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/horn.dir/build: horn
.PHONY : CMakeFiles/horn.dir/build

CMakeFiles/horn.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/horn.dir/cmake_clean.cmake
.PHONY : CMakeFiles/horn.dir/clean

CMakeFiles/horn.dir/depend:
	cd /Users/paulpeng/Programs/datrueone/cmake && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/paulpeng/Programs/datrueone /Users/paulpeng/Programs/datrueone /Users/paulpeng/Programs/datrueone/cmake /Users/paulpeng/Programs/datrueone/cmake /Users/paulpeng/Programs/datrueone/cmake/CMakeFiles/horn.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/horn.dir/depend


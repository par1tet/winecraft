# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /home/par1tet/reps/winecraft

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/par1tet/reps/winecraft/build

# Include any dependencies generated for this target.
include CMakeFiles/winecraft.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/winecraft.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/winecraft.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/winecraft.dir/flags.make

CMakeFiles/winecraft.dir/src/main.cpp.o: CMakeFiles/winecraft.dir/flags.make
CMakeFiles/winecraft.dir/src/main.cpp.o: /home/par1tet/reps/winecraft/src/main.cpp
CMakeFiles/winecraft.dir/src/main.cpp.o: CMakeFiles/winecraft.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/par1tet/reps/winecraft/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/winecraft.dir/src/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/winecraft.dir/src/main.cpp.o -MF CMakeFiles/winecraft.dir/src/main.cpp.o.d -o CMakeFiles/winecraft.dir/src/main.cpp.o -c /home/par1tet/reps/winecraft/src/main.cpp

CMakeFiles/winecraft.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/winecraft.dir/src/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/par1tet/reps/winecraft/src/main.cpp > CMakeFiles/winecraft.dir/src/main.cpp.i

CMakeFiles/winecraft.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/winecraft.dir/src/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/par1tet/reps/winecraft/src/main.cpp -o CMakeFiles/winecraft.dir/src/main.cpp.s

# Object files for target winecraft
winecraft_OBJECTS = \
"CMakeFiles/winecraft.dir/src/main.cpp.o"

# External object files for target winecraft
winecraft_EXTERNAL_OBJECTS =

winecraft: CMakeFiles/winecraft.dir/src/main.cpp.o
winecraft: CMakeFiles/winecraft.dir/build.make
winecraft: CMakeFiles/winecraft.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/par1tet/reps/winecraft/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable winecraft"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/winecraft.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/winecraft.dir/build: winecraft
.PHONY : CMakeFiles/winecraft.dir/build

CMakeFiles/winecraft.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/winecraft.dir/cmake_clean.cmake
.PHONY : CMakeFiles/winecraft.dir/clean

CMakeFiles/winecraft.dir/depend:
	cd /home/par1tet/reps/winecraft/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/par1tet/reps/winecraft /home/par1tet/reps/winecraft /home/par1tet/reps/winecraft/build /home/par1tet/reps/winecraft/build /home/par1tet/reps/winecraft/build/CMakeFiles/winecraft.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/winecraft.dir/depend


# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.1.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.1.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\user\Desktop\Github\study\ACCELERATED

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\user\Desktop\Github\study\ACCELERATED\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/score7.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/score7.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/score7.dir/flags.make

CMakeFiles/score7.dir/chap5/score7.cpp.obj: CMakeFiles/score7.dir/flags.make
CMakeFiles/score7.dir/chap5/score7.cpp.obj: ../chap5/score7.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\user\Desktop\Github\study\ACCELERATED\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/score7.dir/chap5/score7.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\score7.dir\chap5\score7.cpp.obj -c C:\Users\user\Desktop\Github\study\ACCELERATED\chap5\score7.cpp

CMakeFiles/score7.dir/chap5/score7.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/score7.dir/chap5/score7.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\user\Desktop\Github\study\ACCELERATED\chap5\score7.cpp > CMakeFiles\score7.dir\chap5\score7.cpp.i

CMakeFiles/score7.dir/chap5/score7.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/score7.dir/chap5/score7.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\user\Desktop\Github\study\ACCELERATED\chap5\score7.cpp -o CMakeFiles\score7.dir\chap5\score7.cpp.s

# Object files for target score7
score7_OBJECTS = \
"CMakeFiles/score7.dir/chap5/score7.cpp.obj"

# External object files for target score7
score7_EXTERNAL_OBJECTS =

score7.exe: CMakeFiles/score7.dir/chap5/score7.cpp.obj
score7.exe: CMakeFiles/score7.dir/build.make
score7.exe: CMakeFiles/score7.dir/linklibs.rsp
score7.exe: CMakeFiles/score7.dir/objects1.rsp
score7.exe: CMakeFiles/score7.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\user\Desktop\Github\study\ACCELERATED\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable score7.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\score7.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/score7.dir/build: score7.exe

.PHONY : CMakeFiles/score7.dir/build

CMakeFiles/score7.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\score7.dir\cmake_clean.cmake
.PHONY : CMakeFiles/score7.dir/clean

CMakeFiles/score7.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\user\Desktop\Github\study\ACCELERATED C:\Users\user\Desktop\Github\study\ACCELERATED C:\Users\user\Desktop\Github\study\ACCELERATED\cmake-build-debug C:\Users\user\Desktop\Github\study\ACCELERATED\cmake-build-debug C:\Users\user\Desktop\Github\study\ACCELERATED\cmake-build-debug\CMakeFiles\score7.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/score7.dir/depend

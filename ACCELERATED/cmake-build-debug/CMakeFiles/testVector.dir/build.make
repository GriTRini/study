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
include CMakeFiles/testVector.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/testVector.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/testVector.dir/flags.make

CMakeFiles/testVector.dir/chap5/testVector.cpp.obj: CMakeFiles/testVector.dir/flags.make
CMakeFiles/testVector.dir/chap5/testVector.cpp.obj: ../chap5/testVector.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\user\Desktop\Github\study\ACCELERATED\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/testVector.dir/chap5/testVector.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\testVector.dir\chap5\testVector.cpp.obj -c C:\Users\user\Desktop\Github\study\ACCELERATED\chap5\testVector.cpp

CMakeFiles/testVector.dir/chap5/testVector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testVector.dir/chap5/testVector.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\user\Desktop\Github\study\ACCELERATED\chap5\testVector.cpp > CMakeFiles\testVector.dir\chap5\testVector.cpp.i

CMakeFiles/testVector.dir/chap5/testVector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testVector.dir/chap5/testVector.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\user\Desktop\Github\study\ACCELERATED\chap5\testVector.cpp -o CMakeFiles\testVector.dir\chap5\testVector.cpp.s

# Object files for target testVector
testVector_OBJECTS = \
"CMakeFiles/testVector.dir/chap5/testVector.cpp.obj"

# External object files for target testVector
testVector_EXTERNAL_OBJECTS =

testVector.exe: CMakeFiles/testVector.dir/chap5/testVector.cpp.obj
testVector.exe: CMakeFiles/testVector.dir/build.make
testVector.exe: CMakeFiles/testVector.dir/linklibs.rsp
testVector.exe: CMakeFiles/testVector.dir/objects1.rsp
testVector.exe: CMakeFiles/testVector.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\user\Desktop\Github\study\ACCELERATED\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable testVector.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\testVector.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/testVector.dir/build: testVector.exe

.PHONY : CMakeFiles/testVector.dir/build

CMakeFiles/testVector.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\testVector.dir\cmake_clean.cmake
.PHONY : CMakeFiles/testVector.dir/clean

CMakeFiles/testVector.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\user\Desktop\Github\study\ACCELERATED C:\Users\user\Desktop\Github\study\ACCELERATED C:\Users\user\Desktop\Github\study\ACCELERATED\cmake-build-debug C:\Users\user\Desktop\Github\study\ACCELERATED\cmake-build-debug C:\Users\user\Desktop\Github\study\ACCELERATED\cmake-build-debug\CMakeFiles\testVector.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/testVector.dir/depend


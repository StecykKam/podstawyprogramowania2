# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/kamil/Pulpit/Lab/podstawyprogramowania2/lab_7

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kamil/Pulpit/Lab/podstawyprogramowania2/lab_7/build

# Include any dependencies generated for this target.
include src/CMakeFiles/lab_7.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/lab_7.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/lab_7.dir/flags.make

src/CMakeFiles/lab_7.dir/main.cpp.o: src/CMakeFiles/lab_7.dir/flags.make
src/CMakeFiles/lab_7.dir/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kamil/Pulpit/Lab/podstawyprogramowania2/lab_7/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/lab_7.dir/main.cpp.o"
	cd /home/kamil/Pulpit/Lab/podstawyprogramowania2/lab_7/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab_7.dir/main.cpp.o -c /home/kamil/Pulpit/Lab/podstawyprogramowania2/lab_7/src/main.cpp

src/CMakeFiles/lab_7.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab_7.dir/main.cpp.i"
	cd /home/kamil/Pulpit/Lab/podstawyprogramowania2/lab_7/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kamil/Pulpit/Lab/podstawyprogramowania2/lab_7/src/main.cpp > CMakeFiles/lab_7.dir/main.cpp.i

src/CMakeFiles/lab_7.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab_7.dir/main.cpp.s"
	cd /home/kamil/Pulpit/Lab/podstawyprogramowania2/lab_7/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kamil/Pulpit/Lab/podstawyprogramowania2/lab_7/src/main.cpp -o CMakeFiles/lab_7.dir/main.cpp.s

# Object files for target lab_7
lab_7_OBJECTS = \
"CMakeFiles/lab_7.dir/main.cpp.o"

# External object files for target lab_7
lab_7_EXTERNAL_OBJECTS =

src/lab_7: src/CMakeFiles/lab_7.dir/main.cpp.o
src/lab_7: src/CMakeFiles/lab_7.dir/build.make
src/lab_7: src/CMakeFiles/lab_7.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kamil/Pulpit/Lab/podstawyprogramowania2/lab_7/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable lab_7"
	cd /home/kamil/Pulpit/Lab/podstawyprogramowania2/lab_7/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab_7.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/lab_7.dir/build: src/lab_7

.PHONY : src/CMakeFiles/lab_7.dir/build

src/CMakeFiles/lab_7.dir/clean:
	cd /home/kamil/Pulpit/Lab/podstawyprogramowania2/lab_7/build/src && $(CMAKE_COMMAND) -P CMakeFiles/lab_7.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/lab_7.dir/clean

src/CMakeFiles/lab_7.dir/depend:
	cd /home/kamil/Pulpit/Lab/podstawyprogramowania2/lab_7/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kamil/Pulpit/Lab/podstawyprogramowania2/lab_7 /home/kamil/Pulpit/Lab/podstawyprogramowania2/lab_7/src /home/kamil/Pulpit/Lab/podstawyprogramowania2/lab_7/build /home/kamil/Pulpit/Lab/podstawyprogramowania2/lab_7/build/src /home/kamil/Pulpit/Lab/podstawyprogramowania2/lab_7/build/src/CMakeFiles/lab_7.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/lab_7.dir/depend


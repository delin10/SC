# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /home/delinoz/dev/Tools/clion-2019.1/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/delinoz/dev/Tools/clion-2019.1/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/delinoz/Documents/CLion/SC

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/delinoz/Documents/CLion/SC/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SC.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SC.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SC.dir/flags.make

CMakeFiles/SC.dir/main.cpp.o: CMakeFiles/SC.dir/flags.make
CMakeFiles/SC.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/delinoz/Documents/CLion/SC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SC.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SC.dir/main.cpp.o -c /home/delinoz/Documents/CLion/SC/main.cpp

CMakeFiles/SC.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SC.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/delinoz/Documents/CLion/SC/main.cpp > CMakeFiles/SC.dir/main.cpp.i

CMakeFiles/SC.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SC.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/delinoz/Documents/CLion/SC/main.cpp -o CMakeFiles/SC.dir/main.cpp.s

CMakeFiles/SC.dir/src/Utils.cpp.o: CMakeFiles/SC.dir/flags.make
CMakeFiles/SC.dir/src/Utils.cpp.o: ../src/Utils.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/delinoz/Documents/CLion/SC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SC.dir/src/Utils.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SC.dir/src/Utils.cpp.o -c /home/delinoz/Documents/CLion/SC/src/Utils.cpp

CMakeFiles/SC.dir/src/Utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SC.dir/src/Utils.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/delinoz/Documents/CLion/SC/src/Utils.cpp > CMakeFiles/SC.dir/src/Utils.cpp.i

CMakeFiles/SC.dir/src/Utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SC.dir/src/Utils.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/delinoz/Documents/CLion/SC/src/Utils.cpp -o CMakeFiles/SC.dir/src/Utils.cpp.s

CMakeFiles/SC.dir/src/SNLLex.cpp.o: CMakeFiles/SC.dir/flags.make
CMakeFiles/SC.dir/src/SNLLex.cpp.o: ../src/SNLLex.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/delinoz/Documents/CLion/SC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/SC.dir/src/SNLLex.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SC.dir/src/SNLLex.cpp.o -c /home/delinoz/Documents/CLion/SC/src/SNLLex.cpp

CMakeFiles/SC.dir/src/SNLLex.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SC.dir/src/SNLLex.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/delinoz/Documents/CLion/SC/src/SNLLex.cpp > CMakeFiles/SC.dir/src/SNLLex.cpp.i

CMakeFiles/SC.dir/src/SNLLex.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SC.dir/src/SNLLex.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/delinoz/Documents/CLion/SC/src/SNLLex.cpp -o CMakeFiles/SC.dir/src/SNLLex.cpp.s

CMakeFiles/SC.dir/src/structures.cpp.o: CMakeFiles/SC.dir/flags.make
CMakeFiles/SC.dir/src/structures.cpp.o: ../src/structures.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/delinoz/Documents/CLion/SC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/SC.dir/src/structures.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SC.dir/src/structures.cpp.o -c /home/delinoz/Documents/CLion/SC/src/structures.cpp

CMakeFiles/SC.dir/src/structures.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SC.dir/src/structures.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/delinoz/Documents/CLion/SC/src/structures.cpp > CMakeFiles/SC.dir/src/structures.cpp.i

CMakeFiles/SC.dir/src/structures.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SC.dir/src/structures.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/delinoz/Documents/CLion/SC/src/structures.cpp -o CMakeFiles/SC.dir/src/structures.cpp.s

CMakeFiles/SC.dir/src/StringUtils.cpp.o: CMakeFiles/SC.dir/flags.make
CMakeFiles/SC.dir/src/StringUtils.cpp.o: ../src/StringUtils.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/delinoz/Documents/CLion/SC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/SC.dir/src/StringUtils.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SC.dir/src/StringUtils.cpp.o -c /home/delinoz/Documents/CLion/SC/src/StringUtils.cpp

CMakeFiles/SC.dir/src/StringUtils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SC.dir/src/StringUtils.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/delinoz/Documents/CLion/SC/src/StringUtils.cpp > CMakeFiles/SC.dir/src/StringUtils.cpp.i

CMakeFiles/SC.dir/src/StringUtils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SC.dir/src/StringUtils.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/delinoz/Documents/CLion/SC/src/StringUtils.cpp -o CMakeFiles/SC.dir/src/StringUtils.cpp.s

# Object files for target SC
SC_OBJECTS = \
"CMakeFiles/SC.dir/main.cpp.o" \
"CMakeFiles/SC.dir/src/Utils.cpp.o" \
"CMakeFiles/SC.dir/src/SNLLex.cpp.o" \
"CMakeFiles/SC.dir/src/structures.cpp.o" \
"CMakeFiles/SC.dir/src/StringUtils.cpp.o"

# External object files for target SC
SC_EXTERNAL_OBJECTS =

SC: CMakeFiles/SC.dir/main.cpp.o
SC: CMakeFiles/SC.dir/src/Utils.cpp.o
SC: CMakeFiles/SC.dir/src/SNLLex.cpp.o
SC: CMakeFiles/SC.dir/src/structures.cpp.o
SC: CMakeFiles/SC.dir/src/StringUtils.cpp.o
SC: CMakeFiles/SC.dir/build.make
SC: CMakeFiles/SC.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/delinoz/Documents/CLion/SC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable SC"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SC.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SC.dir/build: SC

.PHONY : CMakeFiles/SC.dir/build

CMakeFiles/SC.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SC.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SC.dir/clean

CMakeFiles/SC.dir/depend:
	cd /home/delinoz/Documents/CLion/SC/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/delinoz/Documents/CLion/SC /home/delinoz/Documents/CLion/SC /home/delinoz/Documents/CLion/SC/cmake-build-debug /home/delinoz/Documents/CLion/SC/cmake-build-debug /home/delinoz/Documents/CLion/SC/cmake-build-debug/CMakeFiles/SC.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SC.dir/depend


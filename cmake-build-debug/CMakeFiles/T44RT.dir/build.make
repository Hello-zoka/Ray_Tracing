# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/yurij/Documents/zoka/Прога/T44RT

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/yurij/Documents/zoka/Прога/T44RT/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/T44RT.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/T44RT.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/T44RT.dir/flags.make

CMakeFiles/T44RT.dir/Ray_tracing_main.cpp.o: CMakeFiles/T44RT.dir/flags.make
CMakeFiles/T44RT.dir/Ray_tracing_main.cpp.o: ../Ray_tracing_main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yurij/Documents/zoka/Прога/T44RT/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/T44RT.dir/Ray_tracing_main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/T44RT.dir/Ray_tracing_main.cpp.o -c /Users/yurij/Documents/zoka/Прога/T44RT/Ray_tracing_main.cpp

CMakeFiles/T44RT.dir/Ray_tracing_main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/T44RT.dir/Ray_tracing_main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yurij/Documents/zoka/Прога/T44RT/Ray_tracing_main.cpp > CMakeFiles/T44RT.dir/Ray_tracing_main.cpp.i

CMakeFiles/T44RT.dir/Ray_tracing_main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/T44RT.dir/Ray_tracing_main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yurij/Documents/zoka/Прога/T44RT/Ray_tracing_main.cpp -o CMakeFiles/T44RT.dir/Ray_tracing_main.cpp.s

CMakeFiles/T44RT.dir/materials.cpp.o: CMakeFiles/T44RT.dir/flags.make
CMakeFiles/T44RT.dir/materials.cpp.o: ../materials.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yurij/Documents/zoka/Прога/T44RT/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/T44RT.dir/materials.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/T44RT.dir/materials.cpp.o -c /Users/yurij/Documents/zoka/Прога/T44RT/materials.cpp

CMakeFiles/T44RT.dir/materials.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/T44RT.dir/materials.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yurij/Documents/zoka/Прога/T44RT/materials.cpp > CMakeFiles/T44RT.dir/materials.cpp.i

CMakeFiles/T44RT.dir/materials.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/T44RT.dir/materials.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yurij/Documents/zoka/Прога/T44RT/materials.cpp -o CMakeFiles/T44RT.dir/materials.cpp.s

# Object files for target T44RT
T44RT_OBJECTS = \
"CMakeFiles/T44RT.dir/Ray_tracing_main.cpp.o" \
"CMakeFiles/T44RT.dir/materials.cpp.o"

# External object files for target T44RT
T44RT_EXTERNAL_OBJECTS =

T44RT: CMakeFiles/T44RT.dir/Ray_tracing_main.cpp.o
T44RT: CMakeFiles/T44RT.dir/materials.cpp.o
T44RT: CMakeFiles/T44RT.dir/build.make
T44RT: CMakeFiles/T44RT.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/yurij/Documents/zoka/Прога/T44RT/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable T44RT"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/T44RT.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/T44RT.dir/build: T44RT

.PHONY : CMakeFiles/T44RT.dir/build

CMakeFiles/T44RT.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/T44RT.dir/cmake_clean.cmake
.PHONY : CMakeFiles/T44RT.dir/clean

CMakeFiles/T44RT.dir/depend:
	cd /Users/yurij/Documents/zoka/Прога/T44RT/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/yurij/Documents/zoka/Прога/T44RT /Users/yurij/Documents/zoka/Прога/T44RT /Users/yurij/Documents/zoka/Прога/T44RT/cmake-build-debug /Users/yurij/Documents/zoka/Прога/T44RT/cmake-build-debug /Users/yurij/Documents/zoka/Прога/T44RT/cmake-build-debug/CMakeFiles/T44RT.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/T44RT.dir/depend


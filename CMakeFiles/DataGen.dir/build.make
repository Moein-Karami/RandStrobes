# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.27.4/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.27.4/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/C/codes/Moein-RandStrobes/RandStrobes

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/C/codes/Moein-RandStrobes/RandStrobes

# Include any dependencies generated for this target.
include CMakeFiles/DataGen.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/DataGen.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/DataGen.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DataGen.dir/flags.make

CMakeFiles/DataGen.dir/Src/DataGenerators/RandomDataGenerator.cpp.o: CMakeFiles/DataGen.dir/flags.make
CMakeFiles/DataGen.dir/Src/DataGenerators/RandomDataGenerator.cpp.o: Src/DataGenerators/RandomDataGenerator.cpp
CMakeFiles/DataGen.dir/Src/DataGenerators/RandomDataGenerator.cpp.o: CMakeFiles/DataGen.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/C/codes/Moein-RandStrobes/RandStrobes/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DataGen.dir/Src/DataGenerators/RandomDataGenerator.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DataGen.dir/Src/DataGenerators/RandomDataGenerator.cpp.o -MF CMakeFiles/DataGen.dir/Src/DataGenerators/RandomDataGenerator.cpp.o.d -o CMakeFiles/DataGen.dir/Src/DataGenerators/RandomDataGenerator.cpp.o -c /Users/C/codes/Moein-RandStrobes/RandStrobes/Src/DataGenerators/RandomDataGenerator.cpp

CMakeFiles/DataGen.dir/Src/DataGenerators/RandomDataGenerator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/DataGen.dir/Src/DataGenerators/RandomDataGenerator.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/C/codes/Moein-RandStrobes/RandStrobes/Src/DataGenerators/RandomDataGenerator.cpp > CMakeFiles/DataGen.dir/Src/DataGenerators/RandomDataGenerator.cpp.i

CMakeFiles/DataGen.dir/Src/DataGenerators/RandomDataGenerator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/DataGen.dir/Src/DataGenerators/RandomDataGenerator.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/C/codes/Moein-RandStrobes/RandStrobes/Src/DataGenerators/RandomDataGenerator.cpp -o CMakeFiles/DataGen.dir/Src/DataGenerators/RandomDataGenerator.cpp.s

# Object files for target DataGen
DataGen_OBJECTS = \
"CMakeFiles/DataGen.dir/Src/DataGenerators/RandomDataGenerator.cpp.o"

# External object files for target DataGen
DataGen_EXTERNAL_OBJECTS =

build/libDataGen.a: CMakeFiles/DataGen.dir/Src/DataGenerators/RandomDataGenerator.cpp.o
build/libDataGen.a: CMakeFiles/DataGen.dir/build.make
build/libDataGen.a: CMakeFiles/DataGen.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/C/codes/Moein-RandStrobes/RandStrobes/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library build/libDataGen.a"
	$(CMAKE_COMMAND) -P CMakeFiles/DataGen.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DataGen.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DataGen.dir/build: build/libDataGen.a
.PHONY : CMakeFiles/DataGen.dir/build

CMakeFiles/DataGen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DataGen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DataGen.dir/clean

CMakeFiles/DataGen.dir/depend:
	cd /Users/C/codes/Moein-RandStrobes/RandStrobes && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/C/codes/Moein-RandStrobes/RandStrobes /Users/C/codes/Moein-RandStrobes/RandStrobes /Users/C/codes/Moein-RandStrobes/RandStrobes /Users/C/codes/Moein-RandStrobes/RandStrobes /Users/C/codes/Moein-RandStrobes/RandStrobes/CMakeFiles/DataGen.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/DataGen.dir/depend


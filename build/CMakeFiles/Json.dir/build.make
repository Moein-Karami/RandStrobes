# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /mnt2/Moein-K/Sahlin/RandStrobes

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt2/Moein-K/Sahlin/RandStrobes/build

# Include any dependencies generated for this target.
include CMakeFiles/Json.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Json.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Json.dir/flags.make

CMakeFiles/Json.dir/Src/Json/jsoncpp.cpp.o: CMakeFiles/Json.dir/flags.make
CMakeFiles/Json.dir/Src/Json/jsoncpp.cpp.o: ../Src/Json/jsoncpp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt2/Moein-K/Sahlin/RandStrobes/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Json.dir/Src/Json/jsoncpp.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Json.dir/Src/Json/jsoncpp.cpp.o -c /mnt2/Moein-K/Sahlin/RandStrobes/Src/Json/jsoncpp.cpp

CMakeFiles/Json.dir/Src/Json/jsoncpp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Json.dir/Src/Json/jsoncpp.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt2/Moein-K/Sahlin/RandStrobes/Src/Json/jsoncpp.cpp > CMakeFiles/Json.dir/Src/Json/jsoncpp.cpp.i

CMakeFiles/Json.dir/Src/Json/jsoncpp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Json.dir/Src/Json/jsoncpp.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt2/Moein-K/Sahlin/RandStrobes/Src/Json/jsoncpp.cpp -o CMakeFiles/Json.dir/Src/Json/jsoncpp.cpp.s

CMakeFiles/Json.dir/Src/Json/jsoncpp.cpp.o.requires:

.PHONY : CMakeFiles/Json.dir/Src/Json/jsoncpp.cpp.o.requires

CMakeFiles/Json.dir/Src/Json/jsoncpp.cpp.o.provides: CMakeFiles/Json.dir/Src/Json/jsoncpp.cpp.o.requires
	$(MAKE) -f CMakeFiles/Json.dir/build.make CMakeFiles/Json.dir/Src/Json/jsoncpp.cpp.o.provides.build
.PHONY : CMakeFiles/Json.dir/Src/Json/jsoncpp.cpp.o.provides

CMakeFiles/Json.dir/Src/Json/jsoncpp.cpp.o.provides.build: CMakeFiles/Json.dir/Src/Json/jsoncpp.cpp.o


# Object files for target Json
Json_OBJECTS = \
"CMakeFiles/Json.dir/Src/Json/jsoncpp.cpp.o"

# External object files for target Json
Json_EXTERNAL_OBJECTS =

build/libJson.a: CMakeFiles/Json.dir/Src/Json/jsoncpp.cpp.o
build/libJson.a: CMakeFiles/Json.dir/build.make
build/libJson.a: CMakeFiles/Json.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt2/Moein-K/Sahlin/RandStrobes/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library build/libJson.a"
	$(CMAKE_COMMAND) -P CMakeFiles/Json.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Json.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Json.dir/build: build/libJson.a

.PHONY : CMakeFiles/Json.dir/build

CMakeFiles/Json.dir/requires: CMakeFiles/Json.dir/Src/Json/jsoncpp.cpp.o.requires

.PHONY : CMakeFiles/Json.dir/requires

CMakeFiles/Json.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Json.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Json.dir/clean

CMakeFiles/Json.dir/depend:
	cd /mnt2/Moein-K/Sahlin/RandStrobes/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt2/Moein-K/Sahlin/RandStrobes /mnt2/Moein-K/Sahlin/RandStrobes /mnt2/Moein-K/Sahlin/RandStrobes/build /mnt2/Moein-K/Sahlin/RandStrobes/build /mnt2/Moein-K/Sahlin/RandStrobes/build/CMakeFiles/Json.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Json.dir/depend


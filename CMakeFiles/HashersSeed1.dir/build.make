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
CMAKE_BINARY_DIR = /mnt2/Moein-K/Sahlin/RandStrobes

# Include any dependencies generated for this target.
include CMakeFiles/HashersSeed1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/HashersSeed1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/HashersSeed1.dir/flags.make

CMakeFiles/HashersSeed1.dir/Src/Hashers/SeedBasedHashers/SeedBasedHasher.cpp.o: CMakeFiles/HashersSeed1.dir/flags.make
CMakeFiles/HashersSeed1.dir/Src/Hashers/SeedBasedHashers/SeedBasedHasher.cpp.o: Src/Hashers/SeedBasedHashers/SeedBasedHasher.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt2/Moein-K/Sahlin/RandStrobes/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/HashersSeed1.dir/Src/Hashers/SeedBasedHashers/SeedBasedHasher.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/HashersSeed1.dir/Src/Hashers/SeedBasedHashers/SeedBasedHasher.cpp.o -c /mnt2/Moein-K/Sahlin/RandStrobes/Src/Hashers/SeedBasedHashers/SeedBasedHasher.cpp

CMakeFiles/HashersSeed1.dir/Src/Hashers/SeedBasedHashers/SeedBasedHasher.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HashersSeed1.dir/Src/Hashers/SeedBasedHashers/SeedBasedHasher.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt2/Moein-K/Sahlin/RandStrobes/Src/Hashers/SeedBasedHashers/SeedBasedHasher.cpp > CMakeFiles/HashersSeed1.dir/Src/Hashers/SeedBasedHashers/SeedBasedHasher.cpp.i

CMakeFiles/HashersSeed1.dir/Src/Hashers/SeedBasedHashers/SeedBasedHasher.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HashersSeed1.dir/Src/Hashers/SeedBasedHashers/SeedBasedHasher.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt2/Moein-K/Sahlin/RandStrobes/Src/Hashers/SeedBasedHashers/SeedBasedHasher.cpp -o CMakeFiles/HashersSeed1.dir/Src/Hashers/SeedBasedHashers/SeedBasedHasher.cpp.s

CMakeFiles/HashersSeed1.dir/Src/Hashers/SeedBasedHashers/SeedBasedHasher.cpp.o.requires:

.PHONY : CMakeFiles/HashersSeed1.dir/Src/Hashers/SeedBasedHashers/SeedBasedHasher.cpp.o.requires

CMakeFiles/HashersSeed1.dir/Src/Hashers/SeedBasedHashers/SeedBasedHasher.cpp.o.provides: CMakeFiles/HashersSeed1.dir/Src/Hashers/SeedBasedHashers/SeedBasedHasher.cpp.o.requires
	$(MAKE) -f CMakeFiles/HashersSeed1.dir/build.make CMakeFiles/HashersSeed1.dir/Src/Hashers/SeedBasedHashers/SeedBasedHasher.cpp.o.provides.build
.PHONY : CMakeFiles/HashersSeed1.dir/Src/Hashers/SeedBasedHashers/SeedBasedHasher.cpp.o.provides

CMakeFiles/HashersSeed1.dir/Src/Hashers/SeedBasedHashers/SeedBasedHasher.cpp.o.provides.build: CMakeFiles/HashersSeed1.dir/Src/Hashers/SeedBasedHashers/SeedBasedHasher.cpp.o


# Object files for target HashersSeed1
HashersSeed1_OBJECTS = \
"CMakeFiles/HashersSeed1.dir/Src/Hashers/SeedBasedHashers/SeedBasedHasher.cpp.o"

# External object files for target HashersSeed1
HashersSeed1_EXTERNAL_OBJECTS =

build/libHashersSeed1.a: CMakeFiles/HashersSeed1.dir/Src/Hashers/SeedBasedHashers/SeedBasedHasher.cpp.o
build/libHashersSeed1.a: CMakeFiles/HashersSeed1.dir/build.make
build/libHashersSeed1.a: CMakeFiles/HashersSeed1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt2/Moein-K/Sahlin/RandStrobes/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library build/libHashersSeed1.a"
	$(CMAKE_COMMAND) -P CMakeFiles/HashersSeed1.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/HashersSeed1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/HashersSeed1.dir/build: build/libHashersSeed1.a

.PHONY : CMakeFiles/HashersSeed1.dir/build

CMakeFiles/HashersSeed1.dir/requires: CMakeFiles/HashersSeed1.dir/Src/Hashers/SeedBasedHashers/SeedBasedHasher.cpp.o.requires

.PHONY : CMakeFiles/HashersSeed1.dir/requires

CMakeFiles/HashersSeed1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/HashersSeed1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/HashersSeed1.dir/clean

CMakeFiles/HashersSeed1.dir/depend:
	cd /mnt2/Moein-K/Sahlin/RandStrobes && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt2/Moein-K/Sahlin/RandStrobes /mnt2/Moein-K/Sahlin/RandStrobes /mnt2/Moein-K/Sahlin/RandStrobes /mnt2/Moein-K/Sahlin/RandStrobes /mnt2/Moein-K/Sahlin/RandStrobes/CMakeFiles/HashersSeed1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/HashersSeed1.dir/depend


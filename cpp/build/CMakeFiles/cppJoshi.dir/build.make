# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.22.0/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.22.0/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/bernardocohen/repos/cppJoshi/cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/bernardocohen/repos/cppJoshi/cpp/build

# Include any dependencies generated for this target.
include CMakeFiles/cppJoshi.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/cppJoshi.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/cppJoshi.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cppJoshi.dir/flags.make

CMakeFiles/cppJoshi.dir/src/random.cpp.o: CMakeFiles/cppJoshi.dir/flags.make
CMakeFiles/cppJoshi.dir/src/random.cpp.o: ../src/random.cpp
CMakeFiles/cppJoshi.dir/src/random.cpp.o: CMakeFiles/cppJoshi.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bernardocohen/repos/cppJoshi/cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cppJoshi.dir/src/random.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cppJoshi.dir/src/random.cpp.o -MF CMakeFiles/cppJoshi.dir/src/random.cpp.o.d -o CMakeFiles/cppJoshi.dir/src/random.cpp.o -c /Users/bernardocohen/repos/cppJoshi/cpp/src/random.cpp

CMakeFiles/cppJoshi.dir/src/random.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cppJoshi.dir/src/random.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bernardocohen/repos/cppJoshi/cpp/src/random.cpp > CMakeFiles/cppJoshi.dir/src/random.cpp.i

CMakeFiles/cppJoshi.dir/src/random.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cppJoshi.dir/src/random.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bernardocohen/repos/cppJoshi/cpp/src/random.cpp -o CMakeFiles/cppJoshi.dir/src/random.cpp.s

CMakeFiles/cppJoshi.dir/src/simpleMC.cpp.o: CMakeFiles/cppJoshi.dir/flags.make
CMakeFiles/cppJoshi.dir/src/simpleMC.cpp.o: ../src/simpleMC.cpp
CMakeFiles/cppJoshi.dir/src/simpleMC.cpp.o: CMakeFiles/cppJoshi.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bernardocohen/repos/cppJoshi/cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/cppJoshi.dir/src/simpleMC.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cppJoshi.dir/src/simpleMC.cpp.o -MF CMakeFiles/cppJoshi.dir/src/simpleMC.cpp.o.d -o CMakeFiles/cppJoshi.dir/src/simpleMC.cpp.o -c /Users/bernardocohen/repos/cppJoshi/cpp/src/simpleMC.cpp

CMakeFiles/cppJoshi.dir/src/simpleMC.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cppJoshi.dir/src/simpleMC.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bernardocohen/repos/cppJoshi/cpp/src/simpleMC.cpp > CMakeFiles/cppJoshi.dir/src/simpleMC.cpp.i

CMakeFiles/cppJoshi.dir/src/simpleMC.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cppJoshi.dir/src/simpleMC.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bernardocohen/repos/cppJoshi/cpp/src/simpleMC.cpp -o CMakeFiles/cppJoshi.dir/src/simpleMC.cpp.s

CMakeFiles/cppJoshi.dir/src/payoff.cpp.o: CMakeFiles/cppJoshi.dir/flags.make
CMakeFiles/cppJoshi.dir/src/payoff.cpp.o: ../src/payoff.cpp
CMakeFiles/cppJoshi.dir/src/payoff.cpp.o: CMakeFiles/cppJoshi.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bernardocohen/repos/cppJoshi/cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/cppJoshi.dir/src/payoff.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cppJoshi.dir/src/payoff.cpp.o -MF CMakeFiles/cppJoshi.dir/src/payoff.cpp.o.d -o CMakeFiles/cppJoshi.dir/src/payoff.cpp.o -c /Users/bernardocohen/repos/cppJoshi/cpp/src/payoff.cpp

CMakeFiles/cppJoshi.dir/src/payoff.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cppJoshi.dir/src/payoff.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bernardocohen/repos/cppJoshi/cpp/src/payoff.cpp > CMakeFiles/cppJoshi.dir/src/payoff.cpp.i

CMakeFiles/cppJoshi.dir/src/payoff.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cppJoshi.dir/src/payoff.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bernardocohen/repos/cppJoshi/cpp/src/payoff.cpp -o CMakeFiles/cppJoshi.dir/src/payoff.cpp.s

CMakeFiles/cppJoshi.dir/src/doubleDigital.cpp.o: CMakeFiles/cppJoshi.dir/flags.make
CMakeFiles/cppJoshi.dir/src/doubleDigital.cpp.o: ../src/doubleDigital.cpp
CMakeFiles/cppJoshi.dir/src/doubleDigital.cpp.o: CMakeFiles/cppJoshi.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bernardocohen/repos/cppJoshi/cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/cppJoshi.dir/src/doubleDigital.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cppJoshi.dir/src/doubleDigital.cpp.o -MF CMakeFiles/cppJoshi.dir/src/doubleDigital.cpp.o.d -o CMakeFiles/cppJoshi.dir/src/doubleDigital.cpp.o -c /Users/bernardocohen/repos/cppJoshi/cpp/src/doubleDigital.cpp

CMakeFiles/cppJoshi.dir/src/doubleDigital.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cppJoshi.dir/src/doubleDigital.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bernardocohen/repos/cppJoshi/cpp/src/doubleDigital.cpp > CMakeFiles/cppJoshi.dir/src/doubleDigital.cpp.i

CMakeFiles/cppJoshi.dir/src/doubleDigital.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cppJoshi.dir/src/doubleDigital.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bernardocohen/repos/cppJoshi/cpp/src/doubleDigital.cpp -o CMakeFiles/cppJoshi.dir/src/doubleDigital.cpp.s

CMakeFiles/cppJoshi.dir/src/powerOptions.cpp.o: CMakeFiles/cppJoshi.dir/flags.make
CMakeFiles/cppJoshi.dir/src/powerOptions.cpp.o: ../src/powerOptions.cpp
CMakeFiles/cppJoshi.dir/src/powerOptions.cpp.o: CMakeFiles/cppJoshi.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bernardocohen/repos/cppJoshi/cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/cppJoshi.dir/src/powerOptions.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cppJoshi.dir/src/powerOptions.cpp.o -MF CMakeFiles/cppJoshi.dir/src/powerOptions.cpp.o.d -o CMakeFiles/cppJoshi.dir/src/powerOptions.cpp.o -c /Users/bernardocohen/repos/cppJoshi/cpp/src/powerOptions.cpp

CMakeFiles/cppJoshi.dir/src/powerOptions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cppJoshi.dir/src/powerOptions.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bernardocohen/repos/cppJoshi/cpp/src/powerOptions.cpp > CMakeFiles/cppJoshi.dir/src/powerOptions.cpp.i

CMakeFiles/cppJoshi.dir/src/powerOptions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cppJoshi.dir/src/powerOptions.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bernardocohen/repos/cppJoshi/cpp/src/powerOptions.cpp -o CMakeFiles/cppJoshi.dir/src/powerOptions.cpp.s

# Object files for target cppJoshi
cppJoshi_OBJECTS = \
"CMakeFiles/cppJoshi.dir/src/random.cpp.o" \
"CMakeFiles/cppJoshi.dir/src/simpleMC.cpp.o" \
"CMakeFiles/cppJoshi.dir/src/payoff.cpp.o" \
"CMakeFiles/cppJoshi.dir/src/doubleDigital.cpp.o" \
"CMakeFiles/cppJoshi.dir/src/powerOptions.cpp.o"

# External object files for target cppJoshi
cppJoshi_EXTERNAL_OBJECTS =

libcppJoshi.dylib: CMakeFiles/cppJoshi.dir/src/random.cpp.o
libcppJoshi.dylib: CMakeFiles/cppJoshi.dir/src/simpleMC.cpp.o
libcppJoshi.dylib: CMakeFiles/cppJoshi.dir/src/payoff.cpp.o
libcppJoshi.dylib: CMakeFiles/cppJoshi.dir/src/doubleDigital.cpp.o
libcppJoshi.dylib: CMakeFiles/cppJoshi.dir/src/powerOptions.cpp.o
libcppJoshi.dylib: CMakeFiles/cppJoshi.dir/build.make
libcppJoshi.dylib: CMakeFiles/cppJoshi.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/bernardocohen/repos/cppJoshi/cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX shared library libcppJoshi.dylib"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cppJoshi.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cppJoshi.dir/build: libcppJoshi.dylib
.PHONY : CMakeFiles/cppJoshi.dir/build

CMakeFiles/cppJoshi.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cppJoshi.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cppJoshi.dir/clean

CMakeFiles/cppJoshi.dir/depend:
	cd /Users/bernardocohen/repos/cppJoshi/cpp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/bernardocohen/repos/cppJoshi/cpp /Users/bernardocohen/repos/cppJoshi/cpp /Users/bernardocohen/repos/cppJoshi/cpp/build /Users/bernardocohen/repos/cppJoshi/cpp/build /Users/bernardocohen/repos/cppJoshi/cpp/build/CMakeFiles/cppJoshi.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cppJoshi.dir/depend


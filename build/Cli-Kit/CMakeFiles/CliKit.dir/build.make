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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/konstantinos/Documents/Github_Repos/Cli_Pomodoro

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/konstantinos/Documents/Github_Repos/Cli_Pomodoro/build

# Include any dependencies generated for this target.
include Cli-Kit/CMakeFiles/CliKit.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Cli-Kit/CMakeFiles/CliKit.dir/compiler_depend.make

# Include the progress variables for this target.
include Cli-Kit/CMakeFiles/CliKit.dir/progress.make

# Include the compile flags for this target's objects.
include Cli-Kit/CMakeFiles/CliKit.dir/flags.make

Cli-Kit/CMakeFiles/CliKit.dir/src/text/text.cpp.o: Cli-Kit/CMakeFiles/CliKit.dir/flags.make
Cli-Kit/CMakeFiles/CliKit.dir/src/text/text.cpp.o: ../Cli-Kit/src/text/text.cpp
Cli-Kit/CMakeFiles/CliKit.dir/src/text/text.cpp.o: Cli-Kit/CMakeFiles/CliKit.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/konstantinos/Documents/Github_Repos/Cli_Pomodoro/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Cli-Kit/CMakeFiles/CliKit.dir/src/text/text.cpp.o"
	cd /home/konstantinos/Documents/Github_Repos/Cli_Pomodoro/build/Cli-Kit && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Cli-Kit/CMakeFiles/CliKit.dir/src/text/text.cpp.o -MF CMakeFiles/CliKit.dir/src/text/text.cpp.o.d -o CMakeFiles/CliKit.dir/src/text/text.cpp.o -c /home/konstantinos/Documents/Github_Repos/Cli_Pomodoro/Cli-Kit/src/text/text.cpp

Cli-Kit/CMakeFiles/CliKit.dir/src/text/text.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CliKit.dir/src/text/text.cpp.i"
	cd /home/konstantinos/Documents/Github_Repos/Cli_Pomodoro/build/Cli-Kit && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/konstantinos/Documents/Github_Repos/Cli_Pomodoro/Cli-Kit/src/text/text.cpp > CMakeFiles/CliKit.dir/src/text/text.cpp.i

Cli-Kit/CMakeFiles/CliKit.dir/src/text/text.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CliKit.dir/src/text/text.cpp.s"
	cd /home/konstantinos/Documents/Github_Repos/Cli_Pomodoro/build/Cli-Kit && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/konstantinos/Documents/Github_Repos/Cli_Pomodoro/Cli-Kit/src/text/text.cpp -o CMakeFiles/CliKit.dir/src/text/text.cpp.s

Cli-Kit/CMakeFiles/CliKit.dir/src/menu/menu.cpp.o: Cli-Kit/CMakeFiles/CliKit.dir/flags.make
Cli-Kit/CMakeFiles/CliKit.dir/src/menu/menu.cpp.o: ../Cli-Kit/src/menu/menu.cpp
Cli-Kit/CMakeFiles/CliKit.dir/src/menu/menu.cpp.o: Cli-Kit/CMakeFiles/CliKit.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/konstantinos/Documents/Github_Repos/Cli_Pomodoro/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object Cli-Kit/CMakeFiles/CliKit.dir/src/menu/menu.cpp.o"
	cd /home/konstantinos/Documents/Github_Repos/Cli_Pomodoro/build/Cli-Kit && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Cli-Kit/CMakeFiles/CliKit.dir/src/menu/menu.cpp.o -MF CMakeFiles/CliKit.dir/src/menu/menu.cpp.o.d -o CMakeFiles/CliKit.dir/src/menu/menu.cpp.o -c /home/konstantinos/Documents/Github_Repos/Cli_Pomodoro/Cli-Kit/src/menu/menu.cpp

Cli-Kit/CMakeFiles/CliKit.dir/src/menu/menu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CliKit.dir/src/menu/menu.cpp.i"
	cd /home/konstantinos/Documents/Github_Repos/Cli_Pomodoro/build/Cli-Kit && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/konstantinos/Documents/Github_Repos/Cli_Pomodoro/Cli-Kit/src/menu/menu.cpp > CMakeFiles/CliKit.dir/src/menu/menu.cpp.i

Cli-Kit/CMakeFiles/CliKit.dir/src/menu/menu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CliKit.dir/src/menu/menu.cpp.s"
	cd /home/konstantinos/Documents/Github_Repos/Cli_Pomodoro/build/Cli-Kit && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/konstantinos/Documents/Github_Repos/Cli_Pomodoro/Cli-Kit/src/menu/menu.cpp -o CMakeFiles/CliKit.dir/src/menu/menu.cpp.s

Cli-Kit/CMakeFiles/CliKit.dir/src/menu/menu_utils.cpp.o: Cli-Kit/CMakeFiles/CliKit.dir/flags.make
Cli-Kit/CMakeFiles/CliKit.dir/src/menu/menu_utils.cpp.o: ../Cli-Kit/src/menu/menu_utils.cpp
Cli-Kit/CMakeFiles/CliKit.dir/src/menu/menu_utils.cpp.o: Cli-Kit/CMakeFiles/CliKit.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/konstantinos/Documents/Github_Repos/Cli_Pomodoro/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object Cli-Kit/CMakeFiles/CliKit.dir/src/menu/menu_utils.cpp.o"
	cd /home/konstantinos/Documents/Github_Repos/Cli_Pomodoro/build/Cli-Kit && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Cli-Kit/CMakeFiles/CliKit.dir/src/menu/menu_utils.cpp.o -MF CMakeFiles/CliKit.dir/src/menu/menu_utils.cpp.o.d -o CMakeFiles/CliKit.dir/src/menu/menu_utils.cpp.o -c /home/konstantinos/Documents/Github_Repos/Cli_Pomodoro/Cli-Kit/src/menu/menu_utils.cpp

Cli-Kit/CMakeFiles/CliKit.dir/src/menu/menu_utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CliKit.dir/src/menu/menu_utils.cpp.i"
	cd /home/konstantinos/Documents/Github_Repos/Cli_Pomodoro/build/Cli-Kit && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/konstantinos/Documents/Github_Repos/Cli_Pomodoro/Cli-Kit/src/menu/menu_utils.cpp > CMakeFiles/CliKit.dir/src/menu/menu_utils.cpp.i

Cli-Kit/CMakeFiles/CliKit.dir/src/menu/menu_utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CliKit.dir/src/menu/menu_utils.cpp.s"
	cd /home/konstantinos/Documents/Github_Repos/Cli_Pomodoro/build/Cli-Kit && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/konstantinos/Documents/Github_Repos/Cli_Pomodoro/Cli-Kit/src/menu/menu_utils.cpp -o CMakeFiles/CliKit.dir/src/menu/menu_utils.cpp.s

Cli-Kit/CMakeFiles/CliKit.dir/src/animations/animations.cpp.o: Cli-Kit/CMakeFiles/CliKit.dir/flags.make
Cli-Kit/CMakeFiles/CliKit.dir/src/animations/animations.cpp.o: ../Cli-Kit/src/animations/animations.cpp
Cli-Kit/CMakeFiles/CliKit.dir/src/animations/animations.cpp.o: Cli-Kit/CMakeFiles/CliKit.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/konstantinos/Documents/Github_Repos/Cli_Pomodoro/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object Cli-Kit/CMakeFiles/CliKit.dir/src/animations/animations.cpp.o"
	cd /home/konstantinos/Documents/Github_Repos/Cli_Pomodoro/build/Cli-Kit && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Cli-Kit/CMakeFiles/CliKit.dir/src/animations/animations.cpp.o -MF CMakeFiles/CliKit.dir/src/animations/animations.cpp.o.d -o CMakeFiles/CliKit.dir/src/animations/animations.cpp.o -c /home/konstantinos/Documents/Github_Repos/Cli_Pomodoro/Cli-Kit/src/animations/animations.cpp

Cli-Kit/CMakeFiles/CliKit.dir/src/animations/animations.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CliKit.dir/src/animations/animations.cpp.i"
	cd /home/konstantinos/Documents/Github_Repos/Cli_Pomodoro/build/Cli-Kit && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/konstantinos/Documents/Github_Repos/Cli_Pomodoro/Cli-Kit/src/animations/animations.cpp > CMakeFiles/CliKit.dir/src/animations/animations.cpp.i

Cli-Kit/CMakeFiles/CliKit.dir/src/animations/animations.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CliKit.dir/src/animations/animations.cpp.s"
	cd /home/konstantinos/Documents/Github_Repos/Cli_Pomodoro/build/Cli-Kit && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/konstantinos/Documents/Github_Repos/Cli_Pomodoro/Cli-Kit/src/animations/animations.cpp -o CMakeFiles/CliKit.dir/src/animations/animations.cpp.s

# Object files for target CliKit
CliKit_OBJECTS = \
"CMakeFiles/CliKit.dir/src/text/text.cpp.o" \
"CMakeFiles/CliKit.dir/src/menu/menu.cpp.o" \
"CMakeFiles/CliKit.dir/src/menu/menu_utils.cpp.o" \
"CMakeFiles/CliKit.dir/src/animations/animations.cpp.o"

# External object files for target CliKit
CliKit_EXTERNAL_OBJECTS =

Cli-Kit/libCliKit.a: Cli-Kit/CMakeFiles/CliKit.dir/src/text/text.cpp.o
Cli-Kit/libCliKit.a: Cli-Kit/CMakeFiles/CliKit.dir/src/menu/menu.cpp.o
Cli-Kit/libCliKit.a: Cli-Kit/CMakeFiles/CliKit.dir/src/menu/menu_utils.cpp.o
Cli-Kit/libCliKit.a: Cli-Kit/CMakeFiles/CliKit.dir/src/animations/animations.cpp.o
Cli-Kit/libCliKit.a: Cli-Kit/CMakeFiles/CliKit.dir/build.make
Cli-Kit/libCliKit.a: Cli-Kit/CMakeFiles/CliKit.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/konstantinos/Documents/Github_Repos/Cli_Pomodoro/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX static library libCliKit.a"
	cd /home/konstantinos/Documents/Github_Repos/Cli_Pomodoro/build/Cli-Kit && $(CMAKE_COMMAND) -P CMakeFiles/CliKit.dir/cmake_clean_target.cmake
	cd /home/konstantinos/Documents/Github_Repos/Cli_Pomodoro/build/Cli-Kit && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CliKit.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Cli-Kit/CMakeFiles/CliKit.dir/build: Cli-Kit/libCliKit.a
.PHONY : Cli-Kit/CMakeFiles/CliKit.dir/build

Cli-Kit/CMakeFiles/CliKit.dir/clean:
	cd /home/konstantinos/Documents/Github_Repos/Cli_Pomodoro/build/Cli-Kit && $(CMAKE_COMMAND) -P CMakeFiles/CliKit.dir/cmake_clean.cmake
.PHONY : Cli-Kit/CMakeFiles/CliKit.dir/clean

Cli-Kit/CMakeFiles/CliKit.dir/depend:
	cd /home/konstantinos/Documents/Github_Repos/Cli_Pomodoro/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/konstantinos/Documents/Github_Repos/Cli_Pomodoro /home/konstantinos/Documents/Github_Repos/Cli_Pomodoro/Cli-Kit /home/konstantinos/Documents/Github_Repos/Cli_Pomodoro/build /home/konstantinos/Documents/Github_Repos/Cli_Pomodoro/build/Cli-Kit /home/konstantinos/Documents/Github_Repos/Cli_Pomodoro/build/Cli-Kit/CMakeFiles/CliKit.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Cli-Kit/CMakeFiles/CliKit.dir/depend


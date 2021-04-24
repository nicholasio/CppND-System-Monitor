# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_SOURCE_DIR = /home/nicholas_io/udacity/cpp/CppND-System-Monitor

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nicholas_io/udacity/cpp/CppND-System-Monitor

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/nicholas_io/udacity/cpp/CppND-System-Monitor/CMakeFiles /home/nicholas_io/udacity/cpp/CppND-System-Monitor/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/nicholas_io/udacity/cpp/CppND-System-Monitor/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named monitor

# Build rule for target.
monitor: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 monitor
.PHONY : monitor

# fast build rule for target.
monitor/fast:
	$(MAKE) -f CMakeFiles/monitor.dir/build.make CMakeFiles/monitor.dir/build
.PHONY : monitor/fast

src/format.o: src/format.cpp.o

.PHONY : src/format.o

# target to build an object file
src/format.cpp.o:
	$(MAKE) -f CMakeFiles/monitor.dir/build.make CMakeFiles/monitor.dir/src/format.cpp.o
.PHONY : src/format.cpp.o

src/format.i: src/format.cpp.i

.PHONY : src/format.i

# target to preprocess a source file
src/format.cpp.i:
	$(MAKE) -f CMakeFiles/monitor.dir/build.make CMakeFiles/monitor.dir/src/format.cpp.i
.PHONY : src/format.cpp.i

src/format.s: src/format.cpp.s

.PHONY : src/format.s

# target to generate assembly for a file
src/format.cpp.s:
	$(MAKE) -f CMakeFiles/monitor.dir/build.make CMakeFiles/monitor.dir/src/format.cpp.s
.PHONY : src/format.cpp.s

src/linux_parser.o: src/linux_parser.cpp.o

.PHONY : src/linux_parser.o

# target to build an object file
src/linux_parser.cpp.o:
	$(MAKE) -f CMakeFiles/monitor.dir/build.make CMakeFiles/monitor.dir/src/linux_parser.cpp.o
.PHONY : src/linux_parser.cpp.o

src/linux_parser.i: src/linux_parser.cpp.i

.PHONY : src/linux_parser.i

# target to preprocess a source file
src/linux_parser.cpp.i:
	$(MAKE) -f CMakeFiles/monitor.dir/build.make CMakeFiles/monitor.dir/src/linux_parser.cpp.i
.PHONY : src/linux_parser.cpp.i

src/linux_parser.s: src/linux_parser.cpp.s

.PHONY : src/linux_parser.s

# target to generate assembly for a file
src/linux_parser.cpp.s:
	$(MAKE) -f CMakeFiles/monitor.dir/build.make CMakeFiles/monitor.dir/src/linux_parser.cpp.s
.PHONY : src/linux_parser.cpp.s

src/main.o: src/main.cpp.o

.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) -f CMakeFiles/monitor.dir/build.make CMakeFiles/monitor.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i

.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) -f CMakeFiles/monitor.dir/build.make CMakeFiles/monitor.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s

.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) -f CMakeFiles/monitor.dir/build.make CMakeFiles/monitor.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

src/ncurses_display.o: src/ncurses_display.cpp.o

.PHONY : src/ncurses_display.o

# target to build an object file
src/ncurses_display.cpp.o:
	$(MAKE) -f CMakeFiles/monitor.dir/build.make CMakeFiles/monitor.dir/src/ncurses_display.cpp.o
.PHONY : src/ncurses_display.cpp.o

src/ncurses_display.i: src/ncurses_display.cpp.i

.PHONY : src/ncurses_display.i

# target to preprocess a source file
src/ncurses_display.cpp.i:
	$(MAKE) -f CMakeFiles/monitor.dir/build.make CMakeFiles/monitor.dir/src/ncurses_display.cpp.i
.PHONY : src/ncurses_display.cpp.i

src/ncurses_display.s: src/ncurses_display.cpp.s

.PHONY : src/ncurses_display.s

# target to generate assembly for a file
src/ncurses_display.cpp.s:
	$(MAKE) -f CMakeFiles/monitor.dir/build.make CMakeFiles/monitor.dir/src/ncurses_display.cpp.s
.PHONY : src/ncurses_display.cpp.s

src/process.o: src/process.cpp.o

.PHONY : src/process.o

# target to build an object file
src/process.cpp.o:
	$(MAKE) -f CMakeFiles/monitor.dir/build.make CMakeFiles/monitor.dir/src/process.cpp.o
.PHONY : src/process.cpp.o

src/process.i: src/process.cpp.i

.PHONY : src/process.i

# target to preprocess a source file
src/process.cpp.i:
	$(MAKE) -f CMakeFiles/monitor.dir/build.make CMakeFiles/monitor.dir/src/process.cpp.i
.PHONY : src/process.cpp.i

src/process.s: src/process.cpp.s

.PHONY : src/process.s

# target to generate assembly for a file
src/process.cpp.s:
	$(MAKE) -f CMakeFiles/monitor.dir/build.make CMakeFiles/monitor.dir/src/process.cpp.s
.PHONY : src/process.cpp.s

src/processor.o: src/processor.cpp.o

.PHONY : src/processor.o

# target to build an object file
src/processor.cpp.o:
	$(MAKE) -f CMakeFiles/monitor.dir/build.make CMakeFiles/monitor.dir/src/processor.cpp.o
.PHONY : src/processor.cpp.o

src/processor.i: src/processor.cpp.i

.PHONY : src/processor.i

# target to preprocess a source file
src/processor.cpp.i:
	$(MAKE) -f CMakeFiles/monitor.dir/build.make CMakeFiles/monitor.dir/src/processor.cpp.i
.PHONY : src/processor.cpp.i

src/processor.s: src/processor.cpp.s

.PHONY : src/processor.s

# target to generate assembly for a file
src/processor.cpp.s:
	$(MAKE) -f CMakeFiles/monitor.dir/build.make CMakeFiles/monitor.dir/src/processor.cpp.s
.PHONY : src/processor.cpp.s

src/system.o: src/system.cpp.o

.PHONY : src/system.o

# target to build an object file
src/system.cpp.o:
	$(MAKE) -f CMakeFiles/monitor.dir/build.make CMakeFiles/monitor.dir/src/system.cpp.o
.PHONY : src/system.cpp.o

src/system.i: src/system.cpp.i

.PHONY : src/system.i

# target to preprocess a source file
src/system.cpp.i:
	$(MAKE) -f CMakeFiles/monitor.dir/build.make CMakeFiles/monitor.dir/src/system.cpp.i
.PHONY : src/system.cpp.i

src/system.s: src/system.cpp.s

.PHONY : src/system.s

# target to generate assembly for a file
src/system.cpp.s:
	$(MAKE) -f CMakeFiles/monitor.dir/build.make CMakeFiles/monitor.dir/src/system.cpp.s
.PHONY : src/system.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... monitor"
	@echo "... src/format.o"
	@echo "... src/format.i"
	@echo "... src/format.s"
	@echo "... src/linux_parser.o"
	@echo "... src/linux_parser.i"
	@echo "... src/linux_parser.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
	@echo "... src/ncurses_display.o"
	@echo "... src/ncurses_display.i"
	@echo "... src/ncurses_display.s"
	@echo "... src/process.o"
	@echo "... src/process.i"
	@echo "... src/process.s"
	@echo "... src/processor.o"
	@echo "... src/processor.i"
	@echo "... src/processor.s"
	@echo "... src/system.o"
	@echo "... src/system.i"
	@echo "... src/system.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system


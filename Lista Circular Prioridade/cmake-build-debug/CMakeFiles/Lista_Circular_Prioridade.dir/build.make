# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /opt/clion-2018.2.5/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2018.2.5/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/vinicius/Área de Trabalho/Códigos/Lista Circular Prioridade"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/vinicius/Área de Trabalho/Códigos/Lista Circular Prioridade/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Lista_Circular_Prioridade.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Lista_Circular_Prioridade.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lista_Circular_Prioridade.dir/flags.make

CMakeFiles/Lista_Circular_Prioridade.dir/main.cpp.o: CMakeFiles/Lista_Circular_Prioridade.dir/flags.make
CMakeFiles/Lista_Circular_Prioridade.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/vinicius/Área de Trabalho/Códigos/Lista Circular Prioridade/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Lista_Circular_Prioridade.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Lista_Circular_Prioridade.dir/main.cpp.o -c "/home/vinicius/Área de Trabalho/Códigos/Lista Circular Prioridade/main.cpp"

CMakeFiles/Lista_Circular_Prioridade.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lista_Circular_Prioridade.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/vinicius/Área de Trabalho/Códigos/Lista Circular Prioridade/main.cpp" > CMakeFiles/Lista_Circular_Prioridade.dir/main.cpp.i

CMakeFiles/Lista_Circular_Prioridade.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lista_Circular_Prioridade.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/vinicius/Área de Trabalho/Códigos/Lista Circular Prioridade/main.cpp" -o CMakeFiles/Lista_Circular_Prioridade.dir/main.cpp.s

# Object files for target Lista_Circular_Prioridade
Lista_Circular_Prioridade_OBJECTS = \
"CMakeFiles/Lista_Circular_Prioridade.dir/main.cpp.o"

# External object files for target Lista_Circular_Prioridade
Lista_Circular_Prioridade_EXTERNAL_OBJECTS =

Lista_Circular_Prioridade: CMakeFiles/Lista_Circular_Prioridade.dir/main.cpp.o
Lista_Circular_Prioridade: CMakeFiles/Lista_Circular_Prioridade.dir/build.make
Lista_Circular_Prioridade: CMakeFiles/Lista_Circular_Prioridade.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/vinicius/Área de Trabalho/Códigos/Lista Circular Prioridade/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Lista_Circular_Prioridade"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Lista_Circular_Prioridade.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lista_Circular_Prioridade.dir/build: Lista_Circular_Prioridade

.PHONY : CMakeFiles/Lista_Circular_Prioridade.dir/build

CMakeFiles/Lista_Circular_Prioridade.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Lista_Circular_Prioridade.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Lista_Circular_Prioridade.dir/clean

CMakeFiles/Lista_Circular_Prioridade.dir/depend:
	cd "/home/vinicius/Área de Trabalho/Códigos/Lista Circular Prioridade/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/vinicius/Área de Trabalho/Códigos/Lista Circular Prioridade" "/home/vinicius/Área de Trabalho/Códigos/Lista Circular Prioridade" "/home/vinicius/Área de Trabalho/Códigos/Lista Circular Prioridade/cmake-build-debug" "/home/vinicius/Área de Trabalho/Códigos/Lista Circular Prioridade/cmake-build-debug" "/home/vinicius/Área de Trabalho/Códigos/Lista Circular Prioridade/cmake-build-debug/CMakeFiles/Lista_Circular_Prioridade.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Lista_Circular_Prioridade.dir/depend


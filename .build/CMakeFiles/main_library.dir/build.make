# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_SOURCE_DIR = /home/ezz/Clinic-System

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ezz/Clinic-System/.build

# Include any dependencies generated for this target.
include CMakeFiles/main_library.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/main_library.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/main_library.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main_library.dir/flags.make

CMakeFiles/main_library.dir/src/person.cpp.o: CMakeFiles/main_library.dir/flags.make
CMakeFiles/main_library.dir/src/person.cpp.o: /home/ezz/Clinic-System/src/person.cpp
CMakeFiles/main_library.dir/src/person.cpp.o: CMakeFiles/main_library.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ezz/Clinic-System/.build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/main_library.dir/src/person.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main_library.dir/src/person.cpp.o -MF CMakeFiles/main_library.dir/src/person.cpp.o.d -o CMakeFiles/main_library.dir/src/person.cpp.o -c /home/ezz/Clinic-System/src/person.cpp

CMakeFiles/main_library.dir/src/person.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main_library.dir/src/person.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ezz/Clinic-System/src/person.cpp > CMakeFiles/main_library.dir/src/person.cpp.i

CMakeFiles/main_library.dir/src/person.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main_library.dir/src/person.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ezz/Clinic-System/src/person.cpp -o CMakeFiles/main_library.dir/src/person.cpp.s

CMakeFiles/main_library.dir/src/doctor.cpp.o: CMakeFiles/main_library.dir/flags.make
CMakeFiles/main_library.dir/src/doctor.cpp.o: /home/ezz/Clinic-System/src/doctor.cpp
CMakeFiles/main_library.dir/src/doctor.cpp.o: CMakeFiles/main_library.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ezz/Clinic-System/.build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/main_library.dir/src/doctor.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main_library.dir/src/doctor.cpp.o -MF CMakeFiles/main_library.dir/src/doctor.cpp.o.d -o CMakeFiles/main_library.dir/src/doctor.cpp.o -c /home/ezz/Clinic-System/src/doctor.cpp

CMakeFiles/main_library.dir/src/doctor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main_library.dir/src/doctor.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ezz/Clinic-System/src/doctor.cpp > CMakeFiles/main_library.dir/src/doctor.cpp.i

CMakeFiles/main_library.dir/src/doctor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main_library.dir/src/doctor.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ezz/Clinic-System/src/doctor.cpp -o CMakeFiles/main_library.dir/src/doctor.cpp.s

CMakeFiles/main_library.dir/src/patient.cpp.o: CMakeFiles/main_library.dir/flags.make
CMakeFiles/main_library.dir/src/patient.cpp.o: /home/ezz/Clinic-System/src/patient.cpp
CMakeFiles/main_library.dir/src/patient.cpp.o: CMakeFiles/main_library.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ezz/Clinic-System/.build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/main_library.dir/src/patient.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main_library.dir/src/patient.cpp.o -MF CMakeFiles/main_library.dir/src/patient.cpp.o.d -o CMakeFiles/main_library.dir/src/patient.cpp.o -c /home/ezz/Clinic-System/src/patient.cpp

CMakeFiles/main_library.dir/src/patient.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main_library.dir/src/patient.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ezz/Clinic-System/src/patient.cpp > CMakeFiles/main_library.dir/src/patient.cpp.i

CMakeFiles/main_library.dir/src/patient.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main_library.dir/src/patient.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ezz/Clinic-System/src/patient.cpp -o CMakeFiles/main_library.dir/src/patient.cpp.s

CMakeFiles/main_library.dir/src/Medcin.cpp.o: CMakeFiles/main_library.dir/flags.make
CMakeFiles/main_library.dir/src/Medcin.cpp.o: /home/ezz/Clinic-System/src/Medcin.cpp
CMakeFiles/main_library.dir/src/Medcin.cpp.o: CMakeFiles/main_library.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ezz/Clinic-System/.build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/main_library.dir/src/Medcin.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main_library.dir/src/Medcin.cpp.o -MF CMakeFiles/main_library.dir/src/Medcin.cpp.o.d -o CMakeFiles/main_library.dir/src/Medcin.cpp.o -c /home/ezz/Clinic-System/src/Medcin.cpp

CMakeFiles/main_library.dir/src/Medcin.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main_library.dir/src/Medcin.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ezz/Clinic-System/src/Medcin.cpp > CMakeFiles/main_library.dir/src/Medcin.cpp.i

CMakeFiles/main_library.dir/src/Medcin.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main_library.dir/src/Medcin.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ezz/Clinic-System/src/Medcin.cpp -o CMakeFiles/main_library.dir/src/Medcin.cpp.s

CMakeFiles/main_library.dir/src/Order.cpp.o: CMakeFiles/main_library.dir/flags.make
CMakeFiles/main_library.dir/src/Order.cpp.o: /home/ezz/Clinic-System/src/Order.cpp
CMakeFiles/main_library.dir/src/Order.cpp.o: CMakeFiles/main_library.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ezz/Clinic-System/.build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/main_library.dir/src/Order.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main_library.dir/src/Order.cpp.o -MF CMakeFiles/main_library.dir/src/Order.cpp.o.d -o CMakeFiles/main_library.dir/src/Order.cpp.o -c /home/ezz/Clinic-System/src/Order.cpp

CMakeFiles/main_library.dir/src/Order.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main_library.dir/src/Order.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ezz/Clinic-System/src/Order.cpp > CMakeFiles/main_library.dir/src/Order.cpp.i

CMakeFiles/main_library.dir/src/Order.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main_library.dir/src/Order.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ezz/Clinic-System/src/Order.cpp -o CMakeFiles/main_library.dir/src/Order.cpp.s

CMakeFiles/main_library.dir/src/OrderItem.cpp.o: CMakeFiles/main_library.dir/flags.make
CMakeFiles/main_library.dir/src/OrderItem.cpp.o: /home/ezz/Clinic-System/src/OrderItem.cpp
CMakeFiles/main_library.dir/src/OrderItem.cpp.o: CMakeFiles/main_library.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ezz/Clinic-System/.build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/main_library.dir/src/OrderItem.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main_library.dir/src/OrderItem.cpp.o -MF CMakeFiles/main_library.dir/src/OrderItem.cpp.o.d -o CMakeFiles/main_library.dir/src/OrderItem.cpp.o -c /home/ezz/Clinic-System/src/OrderItem.cpp

CMakeFiles/main_library.dir/src/OrderItem.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main_library.dir/src/OrderItem.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ezz/Clinic-System/src/OrderItem.cpp > CMakeFiles/main_library.dir/src/OrderItem.cpp.i

CMakeFiles/main_library.dir/src/OrderItem.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main_library.dir/src/OrderItem.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ezz/Clinic-System/src/OrderItem.cpp -o CMakeFiles/main_library.dir/src/OrderItem.cpp.s

CMakeFiles/main_library.dir/src/Stock.cpp.o: CMakeFiles/main_library.dir/flags.make
CMakeFiles/main_library.dir/src/Stock.cpp.o: /home/ezz/Clinic-System/src/Stock.cpp
CMakeFiles/main_library.dir/src/Stock.cpp.o: CMakeFiles/main_library.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ezz/Clinic-System/.build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/main_library.dir/src/Stock.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main_library.dir/src/Stock.cpp.o -MF CMakeFiles/main_library.dir/src/Stock.cpp.o.d -o CMakeFiles/main_library.dir/src/Stock.cpp.o -c /home/ezz/Clinic-System/src/Stock.cpp

CMakeFiles/main_library.dir/src/Stock.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main_library.dir/src/Stock.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ezz/Clinic-System/src/Stock.cpp > CMakeFiles/main_library.dir/src/Stock.cpp.i

CMakeFiles/main_library.dir/src/Stock.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main_library.dir/src/Stock.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ezz/Clinic-System/src/Stock.cpp -o CMakeFiles/main_library.dir/src/Stock.cpp.s

CMakeFiles/main_library.dir/src/admin.cpp.o: CMakeFiles/main_library.dir/flags.make
CMakeFiles/main_library.dir/src/admin.cpp.o: /home/ezz/Clinic-System/src/admin.cpp
CMakeFiles/main_library.dir/src/admin.cpp.o: CMakeFiles/main_library.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ezz/Clinic-System/.build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/main_library.dir/src/admin.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main_library.dir/src/admin.cpp.o -MF CMakeFiles/main_library.dir/src/admin.cpp.o.d -o CMakeFiles/main_library.dir/src/admin.cpp.o -c /home/ezz/Clinic-System/src/admin.cpp

CMakeFiles/main_library.dir/src/admin.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main_library.dir/src/admin.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ezz/Clinic-System/src/admin.cpp > CMakeFiles/main_library.dir/src/admin.cpp.i

CMakeFiles/main_library.dir/src/admin.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main_library.dir/src/admin.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ezz/Clinic-System/src/admin.cpp -o CMakeFiles/main_library.dir/src/admin.cpp.s

CMakeFiles/main_library.dir/src/Medical_Insurance.cpp.o: CMakeFiles/main_library.dir/flags.make
CMakeFiles/main_library.dir/src/Medical_Insurance.cpp.o: /home/ezz/Clinic-System/src/Medical_Insurance.cpp
CMakeFiles/main_library.dir/src/Medical_Insurance.cpp.o: CMakeFiles/main_library.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ezz/Clinic-System/.build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/main_library.dir/src/Medical_Insurance.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main_library.dir/src/Medical_Insurance.cpp.o -MF CMakeFiles/main_library.dir/src/Medical_Insurance.cpp.o.d -o CMakeFiles/main_library.dir/src/Medical_Insurance.cpp.o -c /home/ezz/Clinic-System/src/Medical_Insurance.cpp

CMakeFiles/main_library.dir/src/Medical_Insurance.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main_library.dir/src/Medical_Insurance.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ezz/Clinic-System/src/Medical_Insurance.cpp > CMakeFiles/main_library.dir/src/Medical_Insurance.cpp.i

CMakeFiles/main_library.dir/src/Medical_Insurance.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main_library.dir/src/Medical_Insurance.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ezz/Clinic-System/src/Medical_Insurance.cpp -o CMakeFiles/main_library.dir/src/Medical_Insurance.cpp.s

CMakeFiles/main_library.dir/src/Medical_Specialization.cpp.o: CMakeFiles/main_library.dir/flags.make
CMakeFiles/main_library.dir/src/Medical_Specialization.cpp.o: /home/ezz/Clinic-System/src/Medical_Specialization.cpp
CMakeFiles/main_library.dir/src/Medical_Specialization.cpp.o: CMakeFiles/main_library.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ezz/Clinic-System/.build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/main_library.dir/src/Medical_Specialization.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main_library.dir/src/Medical_Specialization.cpp.o -MF CMakeFiles/main_library.dir/src/Medical_Specialization.cpp.o.d -o CMakeFiles/main_library.dir/src/Medical_Specialization.cpp.o -c /home/ezz/Clinic-System/src/Medical_Specialization.cpp

CMakeFiles/main_library.dir/src/Medical_Specialization.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main_library.dir/src/Medical_Specialization.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ezz/Clinic-System/src/Medical_Specialization.cpp > CMakeFiles/main_library.dir/src/Medical_Specialization.cpp.i

CMakeFiles/main_library.dir/src/Medical_Specialization.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main_library.dir/src/Medical_Specialization.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ezz/Clinic-System/src/Medical_Specialization.cpp -o CMakeFiles/main_library.dir/src/Medical_Specialization.cpp.s

CMakeFiles/main_library.dir/src/appointment.cpp.o: CMakeFiles/main_library.dir/flags.make
CMakeFiles/main_library.dir/src/appointment.cpp.o: /home/ezz/Clinic-System/src/appointment.cpp
CMakeFiles/main_library.dir/src/appointment.cpp.o: CMakeFiles/main_library.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ezz/Clinic-System/.build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/main_library.dir/src/appointment.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main_library.dir/src/appointment.cpp.o -MF CMakeFiles/main_library.dir/src/appointment.cpp.o.d -o CMakeFiles/main_library.dir/src/appointment.cpp.o -c /home/ezz/Clinic-System/src/appointment.cpp

CMakeFiles/main_library.dir/src/appointment.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main_library.dir/src/appointment.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ezz/Clinic-System/src/appointment.cpp > CMakeFiles/main_library.dir/src/appointment.cpp.i

CMakeFiles/main_library.dir/src/appointment.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main_library.dir/src/appointment.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ezz/Clinic-System/src/appointment.cpp -o CMakeFiles/main_library.dir/src/appointment.cpp.s

CMakeFiles/main_library.dir/src/other.cpp.o: CMakeFiles/main_library.dir/flags.make
CMakeFiles/main_library.dir/src/other.cpp.o: /home/ezz/Clinic-System/src/other.cpp
CMakeFiles/main_library.dir/src/other.cpp.o: CMakeFiles/main_library.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ezz/Clinic-System/.build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/main_library.dir/src/other.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main_library.dir/src/other.cpp.o -MF CMakeFiles/main_library.dir/src/other.cpp.o.d -o CMakeFiles/main_library.dir/src/other.cpp.o -c /home/ezz/Clinic-System/src/other.cpp

CMakeFiles/main_library.dir/src/other.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main_library.dir/src/other.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ezz/Clinic-System/src/other.cpp > CMakeFiles/main_library.dir/src/other.cpp.i

CMakeFiles/main_library.dir/src/other.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main_library.dir/src/other.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ezz/Clinic-System/src/other.cpp -o CMakeFiles/main_library.dir/src/other.cpp.s

CMakeFiles/main_library.dir/src/prescription.cpp.o: CMakeFiles/main_library.dir/flags.make
CMakeFiles/main_library.dir/src/prescription.cpp.o: /home/ezz/Clinic-System/src/prescription.cpp
CMakeFiles/main_library.dir/src/prescription.cpp.o: CMakeFiles/main_library.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ezz/Clinic-System/.build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/main_library.dir/src/prescription.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main_library.dir/src/prescription.cpp.o -MF CMakeFiles/main_library.dir/src/prescription.cpp.o.d -o CMakeFiles/main_library.dir/src/prescription.cpp.o -c /home/ezz/Clinic-System/src/prescription.cpp

CMakeFiles/main_library.dir/src/prescription.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main_library.dir/src/prescription.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ezz/Clinic-System/src/prescription.cpp > CMakeFiles/main_library.dir/src/prescription.cpp.i

CMakeFiles/main_library.dir/src/prescription.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main_library.dir/src/prescription.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ezz/Clinic-System/src/prescription.cpp -o CMakeFiles/main_library.dir/src/prescription.cpp.s

# Object files for target main_library
main_library_OBJECTS = \
"CMakeFiles/main_library.dir/src/person.cpp.o" \
"CMakeFiles/main_library.dir/src/doctor.cpp.o" \
"CMakeFiles/main_library.dir/src/patient.cpp.o" \
"CMakeFiles/main_library.dir/src/Medcin.cpp.o" \
"CMakeFiles/main_library.dir/src/Order.cpp.o" \
"CMakeFiles/main_library.dir/src/OrderItem.cpp.o" \
"CMakeFiles/main_library.dir/src/Stock.cpp.o" \
"CMakeFiles/main_library.dir/src/admin.cpp.o" \
"CMakeFiles/main_library.dir/src/Medical_Insurance.cpp.o" \
"CMakeFiles/main_library.dir/src/Medical_Specialization.cpp.o" \
"CMakeFiles/main_library.dir/src/appointment.cpp.o" \
"CMakeFiles/main_library.dir/src/other.cpp.o" \
"CMakeFiles/main_library.dir/src/prescription.cpp.o"

# External object files for target main_library
main_library_EXTERNAL_OBJECTS =

libmain_library.a: CMakeFiles/main_library.dir/src/person.cpp.o
libmain_library.a: CMakeFiles/main_library.dir/src/doctor.cpp.o
libmain_library.a: CMakeFiles/main_library.dir/src/patient.cpp.o
libmain_library.a: CMakeFiles/main_library.dir/src/Medcin.cpp.o
libmain_library.a: CMakeFiles/main_library.dir/src/Order.cpp.o
libmain_library.a: CMakeFiles/main_library.dir/src/OrderItem.cpp.o
libmain_library.a: CMakeFiles/main_library.dir/src/Stock.cpp.o
libmain_library.a: CMakeFiles/main_library.dir/src/admin.cpp.o
libmain_library.a: CMakeFiles/main_library.dir/src/Medical_Insurance.cpp.o
libmain_library.a: CMakeFiles/main_library.dir/src/Medical_Specialization.cpp.o
libmain_library.a: CMakeFiles/main_library.dir/src/appointment.cpp.o
libmain_library.a: CMakeFiles/main_library.dir/src/other.cpp.o
libmain_library.a: CMakeFiles/main_library.dir/src/prescription.cpp.o
libmain_library.a: CMakeFiles/main_library.dir/build.make
libmain_library.a: CMakeFiles/main_library.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ezz/Clinic-System/.build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Linking CXX static library libmain_library.a"
	$(CMAKE_COMMAND) -P CMakeFiles/main_library.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main_library.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main_library.dir/build: libmain_library.a
.PHONY : CMakeFiles/main_library.dir/build

CMakeFiles/main_library.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main_library.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main_library.dir/clean

CMakeFiles/main_library.dir/depend:
	cd /home/ezz/Clinic-System/.build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ezz/Clinic-System /home/ezz/Clinic-System /home/ezz/Clinic-System/.build /home/ezz/Clinic-System/.build /home/ezz/Clinic-System/.build/CMakeFiles/main_library.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main_library.dir/depend


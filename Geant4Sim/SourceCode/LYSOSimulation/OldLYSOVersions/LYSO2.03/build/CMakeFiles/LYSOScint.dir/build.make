# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/Luc/Documents/Research/ScintillatorStudies/geant4sim/Versions/LYSO2.02

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Luc/Documents/Research/ScintillatorStudies/geant4sim/Versions/LYSO2.02/build

# Include any dependencies generated for this target.
include CMakeFiles/LYSOScint.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/LYSOScint.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LYSOScint.dir/flags.make

CMakeFiles/LYSOScint.dir/LYSOScint.cc.o: CMakeFiles/LYSOScint.dir/flags.make
CMakeFiles/LYSOScint.dir/LYSOScint.cc.o: ../LYSOScint.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Luc/Documents/Research/ScintillatorStudies/geant4sim/Versions/LYSO2.02/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/LYSOScint.dir/LYSOScint.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LYSOScint.dir/LYSOScint.cc.o -c /Users/Luc/Documents/Research/ScintillatorStudies/geant4sim/Versions/LYSO2.02/LYSOScint.cc

CMakeFiles/LYSOScint.dir/LYSOScint.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LYSOScint.dir/LYSOScint.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Luc/Documents/Research/ScintillatorStudies/geant4sim/Versions/LYSO2.02/LYSOScint.cc > CMakeFiles/LYSOScint.dir/LYSOScint.cc.i

CMakeFiles/LYSOScint.dir/LYSOScint.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LYSOScint.dir/LYSOScint.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Luc/Documents/Research/ScintillatorStudies/geant4sim/Versions/LYSO2.02/LYSOScint.cc -o CMakeFiles/LYSOScint.dir/LYSOScint.cc.s

CMakeFiles/LYSOScint.dir/LYSOScint.cc.o.requires:

.PHONY : CMakeFiles/LYSOScint.dir/LYSOScint.cc.o.requires

CMakeFiles/LYSOScint.dir/LYSOScint.cc.o.provides: CMakeFiles/LYSOScint.dir/LYSOScint.cc.o.requires
	$(MAKE) -f CMakeFiles/LYSOScint.dir/build.make CMakeFiles/LYSOScint.dir/LYSOScint.cc.o.provides.build
.PHONY : CMakeFiles/LYSOScint.dir/LYSOScint.cc.o.provides

CMakeFiles/LYSOScint.dir/LYSOScint.cc.o.provides.build: CMakeFiles/LYSOScint.dir/LYSOScint.cc.o


CMakeFiles/LYSOScint.dir/src/ScintActionInitialization.cc.o: CMakeFiles/LYSOScint.dir/flags.make
CMakeFiles/LYSOScint.dir/src/ScintActionInitialization.cc.o: ../src/ScintActionInitialization.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Luc/Documents/Research/ScintillatorStudies/geant4sim/Versions/LYSO2.02/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/LYSOScint.dir/src/ScintActionInitialization.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LYSOScint.dir/src/ScintActionInitialization.cc.o -c /Users/Luc/Documents/Research/ScintillatorStudies/geant4sim/Versions/LYSO2.02/src/ScintActionInitialization.cc

CMakeFiles/LYSOScint.dir/src/ScintActionInitialization.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LYSOScint.dir/src/ScintActionInitialization.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Luc/Documents/Research/ScintillatorStudies/geant4sim/Versions/LYSO2.02/src/ScintActionInitialization.cc > CMakeFiles/LYSOScint.dir/src/ScintActionInitialization.cc.i

CMakeFiles/LYSOScint.dir/src/ScintActionInitialization.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LYSOScint.dir/src/ScintActionInitialization.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Luc/Documents/Research/ScintillatorStudies/geant4sim/Versions/LYSO2.02/src/ScintActionInitialization.cc -o CMakeFiles/LYSOScint.dir/src/ScintActionInitialization.cc.s

CMakeFiles/LYSOScint.dir/src/ScintActionInitialization.cc.o.requires:

.PHONY : CMakeFiles/LYSOScint.dir/src/ScintActionInitialization.cc.o.requires

CMakeFiles/LYSOScint.dir/src/ScintActionInitialization.cc.o.provides: CMakeFiles/LYSOScint.dir/src/ScintActionInitialization.cc.o.requires
	$(MAKE) -f CMakeFiles/LYSOScint.dir/build.make CMakeFiles/LYSOScint.dir/src/ScintActionInitialization.cc.o.provides.build
.PHONY : CMakeFiles/LYSOScint.dir/src/ScintActionInitialization.cc.o.provides

CMakeFiles/LYSOScint.dir/src/ScintActionInitialization.cc.o.provides.build: CMakeFiles/LYSOScint.dir/src/ScintActionInitialization.cc.o


CMakeFiles/LYSOScint.dir/src/ScintCalorHit.cc.o: CMakeFiles/LYSOScint.dir/flags.make
CMakeFiles/LYSOScint.dir/src/ScintCalorHit.cc.o: ../src/ScintCalorHit.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Luc/Documents/Research/ScintillatorStudies/geant4sim/Versions/LYSO2.02/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/LYSOScint.dir/src/ScintCalorHit.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LYSOScint.dir/src/ScintCalorHit.cc.o -c /Users/Luc/Documents/Research/ScintillatorStudies/geant4sim/Versions/LYSO2.02/src/ScintCalorHit.cc

CMakeFiles/LYSOScint.dir/src/ScintCalorHit.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LYSOScint.dir/src/ScintCalorHit.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Luc/Documents/Research/ScintillatorStudies/geant4sim/Versions/LYSO2.02/src/ScintCalorHit.cc > CMakeFiles/LYSOScint.dir/src/ScintCalorHit.cc.i

CMakeFiles/LYSOScint.dir/src/ScintCalorHit.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LYSOScint.dir/src/ScintCalorHit.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Luc/Documents/Research/ScintillatorStudies/geant4sim/Versions/LYSO2.02/src/ScintCalorHit.cc -o CMakeFiles/LYSOScint.dir/src/ScintCalorHit.cc.s

CMakeFiles/LYSOScint.dir/src/ScintCalorHit.cc.o.requires:

.PHONY : CMakeFiles/LYSOScint.dir/src/ScintCalorHit.cc.o.requires

CMakeFiles/LYSOScint.dir/src/ScintCalorHit.cc.o.provides: CMakeFiles/LYSOScint.dir/src/ScintCalorHit.cc.o.requires
	$(MAKE) -f CMakeFiles/LYSOScint.dir/build.make CMakeFiles/LYSOScint.dir/src/ScintCalorHit.cc.o.provides.build
.PHONY : CMakeFiles/LYSOScint.dir/src/ScintCalorHit.cc.o.provides

CMakeFiles/LYSOScint.dir/src/ScintCalorHit.cc.o.provides.build: CMakeFiles/LYSOScint.dir/src/ScintCalorHit.cc.o


CMakeFiles/LYSOScint.dir/src/ScintCalorimeterSD.cc.o: CMakeFiles/LYSOScint.dir/flags.make
CMakeFiles/LYSOScint.dir/src/ScintCalorimeterSD.cc.o: ../src/ScintCalorimeterSD.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Luc/Documents/Research/ScintillatorStudies/geant4sim/Versions/LYSO2.02/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/LYSOScint.dir/src/ScintCalorimeterSD.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LYSOScint.dir/src/ScintCalorimeterSD.cc.o -c /Users/Luc/Documents/Research/ScintillatorStudies/geant4sim/Versions/LYSO2.02/src/ScintCalorimeterSD.cc

CMakeFiles/LYSOScint.dir/src/ScintCalorimeterSD.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LYSOScint.dir/src/ScintCalorimeterSD.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Luc/Documents/Research/ScintillatorStudies/geant4sim/Versions/LYSO2.02/src/ScintCalorimeterSD.cc > CMakeFiles/LYSOScint.dir/src/ScintCalorimeterSD.cc.i

CMakeFiles/LYSOScint.dir/src/ScintCalorimeterSD.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LYSOScint.dir/src/ScintCalorimeterSD.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Luc/Documents/Research/ScintillatorStudies/geant4sim/Versions/LYSO2.02/src/ScintCalorimeterSD.cc -o CMakeFiles/LYSOScint.dir/src/ScintCalorimeterSD.cc.s

CMakeFiles/LYSOScint.dir/src/ScintCalorimeterSD.cc.o.requires:

.PHONY : CMakeFiles/LYSOScint.dir/src/ScintCalorimeterSD.cc.o.requires

CMakeFiles/LYSOScint.dir/src/ScintCalorimeterSD.cc.o.provides: CMakeFiles/LYSOScint.dir/src/ScintCalorimeterSD.cc.o.requires
	$(MAKE) -f CMakeFiles/LYSOScint.dir/build.make CMakeFiles/LYSOScint.dir/src/ScintCalorimeterSD.cc.o.provides.build
.PHONY : CMakeFiles/LYSOScint.dir/src/ScintCalorimeterSD.cc.o.provides

CMakeFiles/LYSOScint.dir/src/ScintCalorimeterSD.cc.o.provides.build: CMakeFiles/LYSOScint.dir/src/ScintCalorimeterSD.cc.o


CMakeFiles/LYSOScint.dir/src/ScintDetectorConstruction.cc.o: CMakeFiles/LYSOScint.dir/flags.make
CMakeFiles/LYSOScint.dir/src/ScintDetectorConstruction.cc.o: ../src/ScintDetectorConstruction.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Luc/Documents/Research/ScintillatorStudies/geant4sim/Versions/LYSO2.02/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/LYSOScint.dir/src/ScintDetectorConstruction.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LYSOScint.dir/src/ScintDetectorConstruction.cc.o -c /Users/Luc/Documents/Research/ScintillatorStudies/geant4sim/Versions/LYSO2.02/src/ScintDetectorConstruction.cc

CMakeFiles/LYSOScint.dir/src/ScintDetectorConstruction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LYSOScint.dir/src/ScintDetectorConstruction.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Luc/Documents/Research/ScintillatorStudies/geant4sim/Versions/LYSO2.02/src/ScintDetectorConstruction.cc > CMakeFiles/LYSOScint.dir/src/ScintDetectorConstruction.cc.i

CMakeFiles/LYSOScint.dir/src/ScintDetectorConstruction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LYSOScint.dir/src/ScintDetectorConstruction.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Luc/Documents/Research/ScintillatorStudies/geant4sim/Versions/LYSO2.02/src/ScintDetectorConstruction.cc -o CMakeFiles/LYSOScint.dir/src/ScintDetectorConstruction.cc.s

CMakeFiles/LYSOScint.dir/src/ScintDetectorConstruction.cc.o.requires:

.PHONY : CMakeFiles/LYSOScint.dir/src/ScintDetectorConstruction.cc.o.requires

CMakeFiles/LYSOScint.dir/src/ScintDetectorConstruction.cc.o.provides: CMakeFiles/LYSOScint.dir/src/ScintDetectorConstruction.cc.o.requires
	$(MAKE) -f CMakeFiles/LYSOScint.dir/build.make CMakeFiles/LYSOScint.dir/src/ScintDetectorConstruction.cc.o.provides.build
.PHONY : CMakeFiles/LYSOScint.dir/src/ScintDetectorConstruction.cc.o.provides

CMakeFiles/LYSOScint.dir/src/ScintDetectorConstruction.cc.o.provides.build: CMakeFiles/LYSOScint.dir/src/ScintDetectorConstruction.cc.o


CMakeFiles/LYSOScint.dir/src/ScintEventAction.cc.o: CMakeFiles/LYSOScint.dir/flags.make
CMakeFiles/LYSOScint.dir/src/ScintEventAction.cc.o: ../src/ScintEventAction.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Luc/Documents/Research/ScintillatorStudies/geant4sim/Versions/LYSO2.02/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/LYSOScint.dir/src/ScintEventAction.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LYSOScint.dir/src/ScintEventAction.cc.o -c /Users/Luc/Documents/Research/ScintillatorStudies/geant4sim/Versions/LYSO2.02/src/ScintEventAction.cc

CMakeFiles/LYSOScint.dir/src/ScintEventAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LYSOScint.dir/src/ScintEventAction.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Luc/Documents/Research/ScintillatorStudies/geant4sim/Versions/LYSO2.02/src/ScintEventAction.cc > CMakeFiles/LYSOScint.dir/src/ScintEventAction.cc.i

CMakeFiles/LYSOScint.dir/src/ScintEventAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LYSOScint.dir/src/ScintEventAction.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Luc/Documents/Research/ScintillatorStudies/geant4sim/Versions/LYSO2.02/src/ScintEventAction.cc -o CMakeFiles/LYSOScint.dir/src/ScintEventAction.cc.s

CMakeFiles/LYSOScint.dir/src/ScintEventAction.cc.o.requires:

.PHONY : CMakeFiles/LYSOScint.dir/src/ScintEventAction.cc.o.requires

CMakeFiles/LYSOScint.dir/src/ScintEventAction.cc.o.provides: CMakeFiles/LYSOScint.dir/src/ScintEventAction.cc.o.requires
	$(MAKE) -f CMakeFiles/LYSOScint.dir/build.make CMakeFiles/LYSOScint.dir/src/ScintEventAction.cc.o.provides.build
.PHONY : CMakeFiles/LYSOScint.dir/src/ScintEventAction.cc.o.provides

CMakeFiles/LYSOScint.dir/src/ScintEventAction.cc.o.provides.build: CMakeFiles/LYSOScint.dir/src/ScintEventAction.cc.o


CMakeFiles/LYSOScint.dir/src/ScintPrimaryGeneratorAction.cc.o: CMakeFiles/LYSOScint.dir/flags.make
CMakeFiles/LYSOScint.dir/src/ScintPrimaryGeneratorAction.cc.o: ../src/ScintPrimaryGeneratorAction.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Luc/Documents/Research/ScintillatorStudies/geant4sim/Versions/LYSO2.02/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/LYSOScint.dir/src/ScintPrimaryGeneratorAction.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LYSOScint.dir/src/ScintPrimaryGeneratorAction.cc.o -c /Users/Luc/Documents/Research/ScintillatorStudies/geant4sim/Versions/LYSO2.02/src/ScintPrimaryGeneratorAction.cc

CMakeFiles/LYSOScint.dir/src/ScintPrimaryGeneratorAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LYSOScint.dir/src/ScintPrimaryGeneratorAction.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Luc/Documents/Research/ScintillatorStudies/geant4sim/Versions/LYSO2.02/src/ScintPrimaryGeneratorAction.cc > CMakeFiles/LYSOScint.dir/src/ScintPrimaryGeneratorAction.cc.i

CMakeFiles/LYSOScint.dir/src/ScintPrimaryGeneratorAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LYSOScint.dir/src/ScintPrimaryGeneratorAction.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Luc/Documents/Research/ScintillatorStudies/geant4sim/Versions/LYSO2.02/src/ScintPrimaryGeneratorAction.cc -o CMakeFiles/LYSOScint.dir/src/ScintPrimaryGeneratorAction.cc.s

CMakeFiles/LYSOScint.dir/src/ScintPrimaryGeneratorAction.cc.o.requires:

.PHONY : CMakeFiles/LYSOScint.dir/src/ScintPrimaryGeneratorAction.cc.o.requires

CMakeFiles/LYSOScint.dir/src/ScintPrimaryGeneratorAction.cc.o.provides: CMakeFiles/LYSOScint.dir/src/ScintPrimaryGeneratorAction.cc.o.requires
	$(MAKE) -f CMakeFiles/LYSOScint.dir/build.make CMakeFiles/LYSOScint.dir/src/ScintPrimaryGeneratorAction.cc.o.provides.build
.PHONY : CMakeFiles/LYSOScint.dir/src/ScintPrimaryGeneratorAction.cc.o.provides

CMakeFiles/LYSOScint.dir/src/ScintPrimaryGeneratorAction.cc.o.provides.build: CMakeFiles/LYSOScint.dir/src/ScintPrimaryGeneratorAction.cc.o


CMakeFiles/LYSOScint.dir/src/ScintRunAction.cc.o: CMakeFiles/LYSOScint.dir/flags.make
CMakeFiles/LYSOScint.dir/src/ScintRunAction.cc.o: ../src/ScintRunAction.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Luc/Documents/Research/ScintillatorStudies/geant4sim/Versions/LYSO2.02/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/LYSOScint.dir/src/ScintRunAction.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LYSOScint.dir/src/ScintRunAction.cc.o -c /Users/Luc/Documents/Research/ScintillatorStudies/geant4sim/Versions/LYSO2.02/src/ScintRunAction.cc

CMakeFiles/LYSOScint.dir/src/ScintRunAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LYSOScint.dir/src/ScintRunAction.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Luc/Documents/Research/ScintillatorStudies/geant4sim/Versions/LYSO2.02/src/ScintRunAction.cc > CMakeFiles/LYSOScint.dir/src/ScintRunAction.cc.i

CMakeFiles/LYSOScint.dir/src/ScintRunAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LYSOScint.dir/src/ScintRunAction.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Luc/Documents/Research/ScintillatorStudies/geant4sim/Versions/LYSO2.02/src/ScintRunAction.cc -o CMakeFiles/LYSOScint.dir/src/ScintRunAction.cc.s

CMakeFiles/LYSOScint.dir/src/ScintRunAction.cc.o.requires:

.PHONY : CMakeFiles/LYSOScint.dir/src/ScintRunAction.cc.o.requires

CMakeFiles/LYSOScint.dir/src/ScintRunAction.cc.o.provides: CMakeFiles/LYSOScint.dir/src/ScintRunAction.cc.o.requires
	$(MAKE) -f CMakeFiles/LYSOScint.dir/build.make CMakeFiles/LYSOScint.dir/src/ScintRunAction.cc.o.provides.build
.PHONY : CMakeFiles/LYSOScint.dir/src/ScintRunAction.cc.o.provides

CMakeFiles/LYSOScint.dir/src/ScintRunAction.cc.o.provides.build: CMakeFiles/LYSOScint.dir/src/ScintRunAction.cc.o


CMakeFiles/LYSOScint.dir/src/TrackingAction.cc.o: CMakeFiles/LYSOScint.dir/flags.make
CMakeFiles/LYSOScint.dir/src/TrackingAction.cc.o: ../src/TrackingAction.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Luc/Documents/Research/ScintillatorStudies/geant4sim/Versions/LYSO2.02/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/LYSOScint.dir/src/TrackingAction.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LYSOScint.dir/src/TrackingAction.cc.o -c /Users/Luc/Documents/Research/ScintillatorStudies/geant4sim/Versions/LYSO2.02/src/TrackingAction.cc

CMakeFiles/LYSOScint.dir/src/TrackingAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LYSOScint.dir/src/TrackingAction.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Luc/Documents/Research/ScintillatorStudies/geant4sim/Versions/LYSO2.02/src/TrackingAction.cc > CMakeFiles/LYSOScint.dir/src/TrackingAction.cc.i

CMakeFiles/LYSOScint.dir/src/TrackingAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LYSOScint.dir/src/TrackingAction.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Luc/Documents/Research/ScintillatorStudies/geant4sim/Versions/LYSO2.02/src/TrackingAction.cc -o CMakeFiles/LYSOScint.dir/src/TrackingAction.cc.s

CMakeFiles/LYSOScint.dir/src/TrackingAction.cc.o.requires:

.PHONY : CMakeFiles/LYSOScint.dir/src/TrackingAction.cc.o.requires

CMakeFiles/LYSOScint.dir/src/TrackingAction.cc.o.provides: CMakeFiles/LYSOScint.dir/src/TrackingAction.cc.o.requires
	$(MAKE) -f CMakeFiles/LYSOScint.dir/build.make CMakeFiles/LYSOScint.dir/src/TrackingAction.cc.o.provides.build
.PHONY : CMakeFiles/LYSOScint.dir/src/TrackingAction.cc.o.provides

CMakeFiles/LYSOScint.dir/src/TrackingAction.cc.o.provides.build: CMakeFiles/LYSOScint.dir/src/TrackingAction.cc.o


# Object files for target LYSOScint
LYSOScint_OBJECTS = \
"CMakeFiles/LYSOScint.dir/LYSOScint.cc.o" \
"CMakeFiles/LYSOScint.dir/src/ScintActionInitialization.cc.o" \
"CMakeFiles/LYSOScint.dir/src/ScintCalorHit.cc.o" \
"CMakeFiles/LYSOScint.dir/src/ScintCalorimeterSD.cc.o" \
"CMakeFiles/LYSOScint.dir/src/ScintDetectorConstruction.cc.o" \
"CMakeFiles/LYSOScint.dir/src/ScintEventAction.cc.o" \
"CMakeFiles/LYSOScint.dir/src/ScintPrimaryGeneratorAction.cc.o" \
"CMakeFiles/LYSOScint.dir/src/ScintRunAction.cc.o" \
"CMakeFiles/LYSOScint.dir/src/TrackingAction.cc.o"

# External object files for target LYSOScint
LYSOScint_EXTERNAL_OBJECTS =

LYSOScint: CMakeFiles/LYSOScint.dir/LYSOScint.cc.o
LYSOScint: CMakeFiles/LYSOScint.dir/src/ScintActionInitialization.cc.o
LYSOScint: CMakeFiles/LYSOScint.dir/src/ScintCalorHit.cc.o
LYSOScint: CMakeFiles/LYSOScint.dir/src/ScintCalorimeterSD.cc.o
LYSOScint: CMakeFiles/LYSOScint.dir/src/ScintDetectorConstruction.cc.o
LYSOScint: CMakeFiles/LYSOScint.dir/src/ScintEventAction.cc.o
LYSOScint: CMakeFiles/LYSOScint.dir/src/ScintPrimaryGeneratorAction.cc.o
LYSOScint: CMakeFiles/LYSOScint.dir/src/ScintRunAction.cc.o
LYSOScint: CMakeFiles/LYSOScint.dir/src/TrackingAction.cc.o
LYSOScint: CMakeFiles/LYSOScint.dir/build.make
LYSOScint: /usr/local/lib/libG4Tree.dylib
LYSOScint: /usr/local/lib/libG4GMocren.dylib
LYSOScint: /usr/local/lib/libG4visHepRep.dylib
LYSOScint: /usr/local/lib/libG4RayTracer.dylib
LYSOScint: /usr/local/lib/libG4VRML.dylib
LYSOScint: /usr/local/lib/libG4OpenGL.dylib
LYSOScint: /usr/local/lib/libG4gl2ps.dylib
LYSOScint: /usr/local/lib/libG4interfaces.dylib
LYSOScint: /usr/local/lib/libG4persistency.dylib
LYSOScint: /usr/local/lib/libG4analysis.dylib
LYSOScint: /usr/local/lib/libG4error_propagation.dylib
LYSOScint: /usr/local/lib/libG4readout.dylib
LYSOScint: /usr/local/lib/libG4physicslists.dylib
LYSOScint: /usr/local/lib/libG4parmodels.dylib
LYSOScint: /usr/local/lib/libG4FR.dylib
LYSOScint: /usr/local/lib/libG4vis_management.dylib
LYSOScint: /usr/local/lib/libG4modeling.dylib
LYSOScint: /usr/local/lib/libXm.dylib
LYSOScint: /usr/X11R6/lib/libSM.dylib
LYSOScint: /usr/X11R6/lib/libICE.dylib
LYSOScint: /usr/X11R6/lib/libX11.dylib
LYSOScint: /usr/X11R6/lib/libXext.dylib
LYSOScint: /usr/X11R6/lib/libXt.dylib
LYSOScint: /usr/X11R6/lib/libXmu.dylib
LYSOScint: /usr/X11R6/lib/libGL.dylib
LYSOScint: /usr/X11R6/lib/libGLU.dylib
LYSOScint: /usr/local/Qt5.6.2/5.6/clang_64/lib/QtOpenGL.framework/QtOpenGL
LYSOScint: /usr/local/Qt5.6.2/5.6/clang_64/lib/QtPrintSupport.framework/QtPrintSupport
LYSOScint: /usr/local/Qt5.6.2/5.6/clang_64/lib/QtWidgets.framework/QtWidgets
LYSOScint: /usr/local/Qt5.6.2/5.6/clang_64/lib/QtGui.framework/QtGui
LYSOScint: /usr/local/Qt5.6.2/5.6/clang_64/lib/QtCore.framework/QtCore
LYSOScint: /usr/local/lib/libG4run.dylib
LYSOScint: /usr/local/lib/libG4event.dylib
LYSOScint: /usr/local/lib/libG4tracking.dylib
LYSOScint: /usr/local/lib/libG4processes.dylib
LYSOScint: /usr/local/lib/libG4zlib.dylib
LYSOScint: /usr/lib/libexpat.dylib
LYSOScint: /usr/local/lib/libG4digits_hits.dylib
LYSOScint: /usr/local/lib/libG4track.dylib
LYSOScint: /usr/local/lib/libG4particles.dylib
LYSOScint: /usr/local/lib/libG4geometry.dylib
LYSOScint: /usr/local/lib/libG4materials.dylib
LYSOScint: /usr/local/lib/libG4graphics_reps.dylib
LYSOScint: /usr/local/lib/libG4intercoms.dylib
LYSOScint: /usr/local/lib/libG4global.dylib
LYSOScint: /usr/local/lib/libG4clhep.dylib
LYSOScint: CMakeFiles/LYSOScint.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/Luc/Documents/Research/ScintillatorStudies/geant4sim/Versions/LYSO2.02/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable LYSOScint"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LYSOScint.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LYSOScint.dir/build: LYSOScint

.PHONY : CMakeFiles/LYSOScint.dir/build

CMakeFiles/LYSOScint.dir/requires: CMakeFiles/LYSOScint.dir/LYSOScint.cc.o.requires
CMakeFiles/LYSOScint.dir/requires: CMakeFiles/LYSOScint.dir/src/ScintActionInitialization.cc.o.requires
CMakeFiles/LYSOScint.dir/requires: CMakeFiles/LYSOScint.dir/src/ScintCalorHit.cc.o.requires
CMakeFiles/LYSOScint.dir/requires: CMakeFiles/LYSOScint.dir/src/ScintCalorimeterSD.cc.o.requires
CMakeFiles/LYSOScint.dir/requires: CMakeFiles/LYSOScint.dir/src/ScintDetectorConstruction.cc.o.requires
CMakeFiles/LYSOScint.dir/requires: CMakeFiles/LYSOScint.dir/src/ScintEventAction.cc.o.requires
CMakeFiles/LYSOScint.dir/requires: CMakeFiles/LYSOScint.dir/src/ScintPrimaryGeneratorAction.cc.o.requires
CMakeFiles/LYSOScint.dir/requires: CMakeFiles/LYSOScint.dir/src/ScintRunAction.cc.o.requires
CMakeFiles/LYSOScint.dir/requires: CMakeFiles/LYSOScint.dir/src/TrackingAction.cc.o.requires

.PHONY : CMakeFiles/LYSOScint.dir/requires

CMakeFiles/LYSOScint.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/LYSOScint.dir/cmake_clean.cmake
.PHONY : CMakeFiles/LYSOScint.dir/clean

CMakeFiles/LYSOScint.dir/depend:
	cd /Users/Luc/Documents/Research/ScintillatorStudies/geant4sim/Versions/LYSO2.02/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Luc/Documents/Research/ScintillatorStudies/geant4sim/Versions/LYSO2.02 /Users/Luc/Documents/Research/ScintillatorStudies/geant4sim/Versions/LYSO2.02 /Users/Luc/Documents/Research/ScintillatorStudies/geant4sim/Versions/LYSO2.02/build /Users/Luc/Documents/Research/ScintillatorStudies/geant4sim/Versions/LYSO2.02/build /Users/Luc/Documents/Research/ScintillatorStudies/geant4sim/Versions/LYSO2.02/build/CMakeFiles/LYSOScint.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/LYSOScint.dir/depend


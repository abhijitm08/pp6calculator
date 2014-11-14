# - Main CMake scripts for pp6calculator
# Comments in CMake begin with a '#' just like shell and python scripts#
# - Require latest generator for CMake
cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

# - Configures the build of the program ie. add the pp6calculator program. 
# - Declare the project
project(pp6calculator)

# - Use if(CMAKE_COMPILER_IS_GNUCXX) to gaurd the setting
if(CMAKE_COMPILER_IS_GNUCXX)
  set(CMAKE_CXX_FLAGS "-std=c++98 -Wall -Wextra -Werror -Wfatal-errors -Wwrite-strings -Woverloaded-virtual -fno-nonansi-builtins -fno-gnu-keywords -fstrict-aliasing")
endif()

# - Conifugure the compiler to look for headers in the PP6Lib directory relative to CMakeLists.txt 
include_directories(PP6Lib)
include_directories(FileReader-1.0.0)

# - Add the PP6Lib library
add_subdirectory(PP6Lib)
add_subdirectory(FileReader-1.0.0)

# - Configures the build of the program ie. add the pp6calculator program. 
# - Need not add headers while building in linux as it finds them automatically but for mac which uses IDE Xcode, we have to.
add_executable( pp6calculator pp6calculator.cpp)

# - Link pp6calculator to the pp6lib library.
# - See notes. Creates precompiled code for maths functions ie. a static libpp6lib.a which then gets linked to main executable (pp6calculator.cpp)
target_link_libraries(pp6calculator pp6lib FileReader)

# - Install pp6calculator to the bin subdirectory of CMAKE_INSTALL_PREFIX.
#install(TARGETS pp6calculator DESTINATION bin)
install(TARGETS pp6calculator DESTINATION bin)

# - Package pp6calculator sources and executable
include(CPack)

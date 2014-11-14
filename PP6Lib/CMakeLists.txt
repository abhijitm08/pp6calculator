# - Partition the build into library which contains headers and sources
# - Although we have in our main program PP6Lib but by doig this CMake does that for us.
# -  Need not pass PP6Lib/PP6Math.cpp in add_executable when done this but only source for main program and also do target_link_libraries.
add_library(pp6lib STATIC PP6MathDay2.hpp PP6MathDay2.cpp PP6MathDay1.hpp PP6MathDay1.cpp day.hpp day1.cpp day2.cpp)

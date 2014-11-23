# - Partition the build into library which contains headers and sources
# - Although we have in our main program PP6Lib but by doig this CMake does that for us.
# -  Need not pass PP6Lib/PP6Math.cpp in add_executable when done this but only source for main program and also do target_link_libraries.
add_library(pp6lib STATIC Day.hpp Day1Menu.cpp Day2Menu.cpp Day3Menu.cpp PP6MathDay1.hpp PP6MathDay1.cpp PP6Day2meanE.hpp PP6Day2meanE.cpp PP6Day2muon.hpp PP6Day2muon.cpp PP6ThreeVector.hpp PP6ThreeVector.cpp PP6FourVector.hpp PP6FourVector.cpp PP6Particle.hpp PP6Particle.cpp)

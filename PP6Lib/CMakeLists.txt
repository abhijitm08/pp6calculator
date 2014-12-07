# - Partition the build into library which contains headers and sources
# - Although we have in our main program PP6Lib but by doig this CMake does that for us.
# -  Need not pass PP6Lib/PP6Math.cpp in add_executable when done this but only source for main program and also do target_link_libraries.
add_library(pp6lib STATIC Day.hpp Day1Menu.cpp Day2Menu.cpp Day3Menu.cpp Day4Menu.cpp PP6Day1Math.hpp PP6Day1Math.cpp PP6Day2meanE.hpp PP6Day2meanE.cpp PP6Day2muon.hpp PP6Day2muon.cpp PP6ThreeVector.hpp PP6ThreeVector.cpp PP6FourVector.hpp PP6FourVector.cpp PP6Particle.hpp PP6Particle.cpp PP6Day4Exercises.cpp PP6Day4Exercises.cpp PP6ParticleInfo.cpp PP6ParticleInfo.hpp PP6Day4muon.cpp PP6Day4muon.hpp)

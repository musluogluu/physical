cmake_minimum_required(VERSION 3.16)
project(NeutronOptimization)

find_package(Geant4 REQUIRED)
include(${Geant4_USE_FILE})

add_executable(simulator
  main.cc
  DetectorConstruction.cc
  PrimaryGeneratorAction.cc
  RunAction.cc
  EventAction.cc
)

target_link_libraries(simulator ${Geant4_LIBRARIES})

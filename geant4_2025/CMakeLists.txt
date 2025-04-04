cmake_minimum_required(VERSION 3.16)
project(NeutronSimulator)

find_package(Geant4 REQUIRED)
include(${Geant4_USE_FILE})

set(SOURCES
    main.cc
    DetectorConstruction.cc
    PhysicsList.cc
    PrimaryGeneratorAction.cc
    RunAction.cc
    EventAction.cc
    NeutronSD.cc
    NeutronHit.cc  # Bu satırın ekli olduğundan emin ol cano
)

add_executable(simulator ${SOURCES})
target_link_libraries(simulator ${Geant4_LIBRARIES})

set_target_properties(simulator PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

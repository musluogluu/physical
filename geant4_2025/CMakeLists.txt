cmake_minimum_required(VERSION 3.16)
project(NeutronSimulator LANGUAGES CXX)

# Geant4 Konfigürasyonu
find_package(Geant4 REQUIRED)
include(${Geant4_USE_FILE})

# Tüm kaynak dosyaları
set(SOURCES
    main.cc
    DetectorConstruction.cc
    PhysicsList.cc
    PrimaryGeneratorAction.cc
    RunAction.cc
    EventAction.cc
)

# Executable oluştur
add_executable(simulator ${SOURCES})
target_link_libraries(simulator PRIVATE ${Geant4_LIBRARIES})

# Çıktı dizini
set_target_properties(simulator PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

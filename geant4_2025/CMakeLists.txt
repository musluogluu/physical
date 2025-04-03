cmake_minimum_required(VERSION 3.16)
project(NeutronOptimization LANGUAGES CXX)

# Geant4 Konfigürasyonu
find_package(Geant4 REQUIRED COMPONENTS vis_ogl)
include(${Geant4_USE_FILE})

# Tüm kaynak dosyaları
set(SOURCES
    src/main.cc
    src/DetectorConstruction.cc
    src/PhysicsList.cc
    src/PrimaryGeneratorAction.cc
    src/RunAction.cc
    src/EventAction.cc
)

# Executable oluştur
add_executable(bl4s_sim ${SOURCES})
target_link_libraries(bl4s_sim PRIVATE ${Geant4_LIBRARIES})

# Çıktı dizini
set_target_properties(bl4s_sim PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

cmake_minimum_required(VERSION 3.16)
project(NeutronSimulator LANGUAGES CXX)

# Temel ayarlar
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Geant4 konfigürasyonu
find_package(Geant4 REQUIRED)
include(${Geant4_USE_FILE})

# Tüm kaynak ve başlık dosyaları
set(SOURCES
    main.cc
    DetectorConstruction.cc
    PrimaryGeneratorAction.cc
    RunAction.cc
    EventAction.cc
    PhysicsList.cc
)

set(HEADERS
    DetectorConstruction.hh
    PrimaryGeneratorAction.hh
    RunAction.hh
    EventAction.hh
    PhysicsList.hh
)

# Executable oluştur
add_executable(simulator ${SOURCES} ${HEADERS})

# Link ayarları
target_link_libraries(simulator PRIVATE ${Geant4_LIBRARIES})

# Çıktı dizini
set_target_properties(simulator PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

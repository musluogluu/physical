cmake_minimum_required(VERSION 3.16)
project(Geant4_NeutronSimulation LANGUAGES CXX)

# Geant4 bulma
find_package(Geant4 REQUIRED PATHS /usr/local/geant4/lib/cmake/Geant4)
include(${Geant4_USE_FILE})

# ROOT analiz desteği (opsiyonel)
find_package(ROOT QUIET)

# Tüm kaynak dosyalar
set(SOURCES
    main.cc
    PhysicsList.cc
    DetectorConstruction.cc
    PrimaryGeneratorAction.cc
    RunAction.cc
    EventAction.cc
)

# Çalıştırılabilir oluştur
add_executable(simulator ${SOURCES})

# Kütüphane bağlantıları
target_link_libraries(simulator 
    ${Geant4_LIBRARIES}
    ${ROOT_LIBRARIES}
)

# Derleme ayarları
target_compile_features(simulator PRIVATE cxx_std_17)
set_target_properties(simulator PROPERTIES
    CXX_EXTENSIONS OFF
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# Kurulum ayarları (opsiyonel)
install(TARGETS simulator DESTINATION bin)

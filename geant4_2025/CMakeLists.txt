cmake_minimum_required(VERSION 3.16)
project(NeutronSimulator)

# Geant4 paketini bul
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
    NeutronSD.cc
    NeutronHit.cc
)

# Derleme ayarları
add_executable(simulator ${SOURCES})
target_include_directories(simulator PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(simulator ${Geant4_LIBRARIES})

# Çıktı dizini ayarı
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Optimizasyon ve debug sembolleri
if(CMAKE_BUILD_TYPE STREQUAL "Release")
    target_compile_options(simulator PRIVATE -O3 -march=native)
else()
    target_compile_options(simulator PRIVATE -g -O0)
endif()

# Geant4 data dosyaları için
if(Geant4_DATASETS)
    file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/data)
    foreach(dataset ${Geant4_DATASETS})
        add_custom_command(TARGET simulator POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${dataset} ${CMAKE_BINARY_DIR}/data/${dataset}
        )
    endforeach()
endif()

add_executable(simulator
  main.cc
  PhysicsList.cc  # Yeni ekle
  DetectorConstruction.cc
  PrimaryGeneratorAction.cc
  RunAction.cc
  EventAction.cc
)

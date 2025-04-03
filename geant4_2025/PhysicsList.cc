#include "PhysicsList.hh"
#include "FTFP_BERT.hh"  // Hadronik fizik için eklendi

PhysicsList::PhysicsList() {
  RegisterPhysics(new FTFP_BERT());  // Proton-nükleer etkileşimler
  RegisterPhysics(new G4EmStandardPhysics_option4());  // EM süreçler
}

PhysicsList::~PhysicsList() {}

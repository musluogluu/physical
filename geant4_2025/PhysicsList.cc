#include "PhysicsList.hh"
#include "G4DecayPhysics.hh"
#include "G4EmStandardPhysics.hh"
#include "G4RadioactiveDecayPhysics.hh"

PhysicsList::PhysicsList() {
    RegisterPhysics(new G4DecayPhysics());
    RegisterPhysics(new G4EmStandardPhysics());
    RegisterPhysics(new G4RadioactiveDecayPhysics());
}

PhysicsList::~PhysicsList() {}

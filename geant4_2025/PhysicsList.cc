#include "PhysicsList.hh"
#include "G4PhysListFactory.hh"
#include "G4EmStandardPhysics_option4.hh"
#include "G4DecayPhysics.hh"

PhysicsList::PhysicsList() {
    RegisterPhysics(new G4DecayPhysics());
    RegisterPhysics(new G4EmStandardPhysics_option4());
    
    G4PhysListFactory factory;
    auto physList = factory.GetReferencePhysList("FTFP_BERT");
    for(auto physics : *physList->GetPhysicsVector()) {
        RegisterPhysics(physics);
    }
}

PhysicsList::~PhysicsList() {}

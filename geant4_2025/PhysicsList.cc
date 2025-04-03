#include "PhysicsList.hh"
#include "G4PhysListFactory.hh"
#include "G4EmStandardPhysics_option4.hh"
#include "G4DecayPhysics.hh"
#include "G4RadioactiveDecayPhysics.hh"

PhysicsList::PhysicsList() {
    // 1. Temel süreçler
    RegisterPhysics(new G4DecayPhysics());
    
    // 2. EM süreçler (1.5 GeV için optimize)
    RegisterPhysics(new G4EmStandardPhysics_option4());
    
    // 3. Hadronik fizik (FTFP_BERT)
    G4PhysListFactory factory;
    auto physList = factory.GetReferencePhysList("FTFP_BERT");
    for(auto physics : *physList->GetPhysicsVector()) {
        RegisterPhysics(physics);
    }
    
    // 4. Radyoaktif bozunum
    RegisterPhysics(new G4RadioactiveDecayPhysics());
}

PhysicsList::~PhysicsList() {}

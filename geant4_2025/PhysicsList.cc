#include "PhysicsList.hh"
#include "G4PhysListFactory.hh"
#include "G4SystemOfUnits.hh"

PhysicsList::PhysicsList() {
    G4PhysListFactory factory;
    auto physList = factory.GetReferencePhysList("FTFP_BERT");
    
    // Geant4 v11.3.1 uyumlu kesin çözüm
    G4int i = 0;
    while(G4VPhysicsConstructor* physics = const_cast<G4VPhysicsConstructor*>(physList->GetPhysics(i++))) {
        if(!physics) break;
        RegisterPhysics(physics);
    }
}

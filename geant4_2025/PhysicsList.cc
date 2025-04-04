#include "PhysicsList.hh"
#include "G4PhysListFactory.hh"

PhysicsList::PhysicsList() {
    G4PhysListFactory factory;
    auto physList = factory.GetReferencePhysList("FTFP_BERT");
    
    // Geant4 v11.3.1 uyumlu yeni yöntem
    G4int i = 0;
    while(true) {
        G4VPhysicsConstructor* physics = physList->GetPhysics(i++);
        if(!physics) break;
        RegisterPhysics(physics);
    }
}

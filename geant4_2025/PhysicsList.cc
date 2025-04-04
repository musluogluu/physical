// PhysicsList.cc
#include "PhysicsList.hh"
#include "G4PhysListFactory.hh"

PhysicsList::PhysicsList() {
    G4PhysListFactory factory;
    auto physList = factory.GetReferencePhysList("FTFP_BERT");
    
    G4int i = 0;
    while(true) {
        auto physics = const_cast<G4VPhysicsConstructor*>(physList->GetPhysics(i++));
        if(!physics) break;
        RegisterPhysics(physics);
    }
}

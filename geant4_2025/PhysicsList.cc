#include "PhysicsList.hh"
#include "G4PhysListFactory.hh"
#include "G4SystemOfUnits.hh"

PhysicsList::PhysicsList() {
    G4PhysListFactory factory;
    auto physList = factory.GetReferencePhysList("FTFP_BERT");
    
    for(int i=0; i<physList->GetPhysicsLength(); i++) {
        RegisterPhysics(const_cast<G4VPhysicsConstructor*>(physList->GetPhysics(i)));
    }
}

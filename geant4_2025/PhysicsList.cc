#include "PhysicsList.hh"
#include "G4PhysListFactory.hh"

PhysicsList::PhysicsList() {
    G4PhysListFactory factory;
    auto physList = factory.GetReferencePhysList("FTFP_BERT");
    
    // Alternatif yöntem - iterator kullanımı
    for(size_t i=0; i<physList->size(); ++i) {
        RegisterPhysics(const_cast<G4VPhysicsConstructor*>(physList->GetPhysics(i)));
    }
}

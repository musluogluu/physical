#include "PhysicsList.hh"
#include "G4VModularPhysicsList.hh"
#include "G4VPhysicsConstructor.hh"
#include "G4PhysListFactory.hh"
#include "G4ParticleTypes.hh"
#include "FTFP_BERT.hh"

PhysicsList::PhysicsList() : G4VModularPhysicsList() {
    // Geant4 fizik listesi fabrikasını kullanarak bir fizik listesi oluştur
    G4PhysListFactory factory;
    G4VModularPhysicsList* physList = factory.GetReferencePhysList("FTFP_BERT");

    if (physList) {
        for (G4int i = 0; i < physList->GetPhysicsVector()->size(); i++) {
            RegisterPhysics((*physList->GetPhysicsVector())[i]);
        }
    } else {
        G4cerr << "Error: Could not create physics list!" << G4endl;
    }
}

PhysicsList::~PhysicsList() {}

void PhysicsList::SetCuts() {
    SetCutsWithDefault();
}

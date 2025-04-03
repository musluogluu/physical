#include "PhysicsList.hh"
#include "FTFP_BERT.hh"  // Doğrudan ekleyin
#include "G4EmStandardPhysics_option4.hh"
#include "G4DecayPhysics.hh"
#include "G4HadronicParameters.hh"

PhysicsList::PhysicsList() {
    // 1. Temel süreçler
    RegisterPhysics(new G4DecayPhysics());
    
    // 2. EM süreçler
    RegisterPhysics(new G4EmStandardPhysics_option4());
    
    // 3. Hadronik fizik (DÜZELTME BURADA)
    RegisterPhysics(new FTFP_BERT());  // Direkt kayıt
    
    // 4. Enerji aralığı ayarı
    G4HadronicParameters::Instance()->SetMaxEnergy(1.2*GeV);
}

PhysicsList::~PhysicsList() {}

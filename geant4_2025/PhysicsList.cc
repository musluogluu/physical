#include "PhysicsList.hh"
#include "G4PhysListFactory.hh"  // Fizik listesi fabrikası için
#include "G4EmStandardPhysics_option4.hh"
#include "G4DecayPhysics.hh"
#include "G4RadioactiveDecayPhysics.hh"

PhysicsList::PhysicsList() {
    // 1. Temel bozunum fizikleri
    RegisterPhysics(new G4DecayPhysics());

    // 2. EM süreçler (1.5 GeV için optimize edilmiş)
    RegisterPhysics(new G4EmStandardPhysics_option4());

    // 3. Hadronik fizik listesi (DÜZELTME BURADA)
    G4PhysListFactory factory;
    RegisterPhysics(factory.GetReferencePhysList("FTFP_BERT"));

    // 4. Radyoaktif bozunum (opsiyonel)
    RegisterPhysics(new G4RadioactiveDecayPhysics());
}

PhysicsList::~PhysicsList() {}

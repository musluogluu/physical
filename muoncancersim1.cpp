#include "G4RunManager.hh"
#include "G4UImanager.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"
#include "G4ParticleGun.hh"
#include "G4SystemOfUnits.hh"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4NistManager.hh"
#include "G4VisAttributes.hh"
#include "G4MuonPlus.hh"
#include "G4EmStandardPhysics.hh"
#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4Event.hh"
#include "G4ParticleTable.hh"

class TumorDetector : public G4VUserDetectorConstruction {
public:
    G4VPhysicalVolume* Construct() override {
        G4NistManager* nist = G4NistManager::Instance();

        // Simülasyon ortamı: Hava
        G4Box* worldBox = new G4Box("World", 50*cm, 50*cm, 50*cm);
        G4LogicalVolume* worldLog = new G4LogicalVolume(worldBox, nist->FindOrBuildMaterial("G4_AIR"), "World");
        G4VPhysicalVolume* worldPhys = new G4PVPlacement(0, G4ThreeVector(), worldLog, "World", 0, false, 0);

        // Kanserli doku modeli (su bazlı)
        G4Box* tumorBox = new G4Box("Tumor", 5*cm, 5*cm, 5*cm);
        G4LogicalVolume* tumorLog = new G4LogicalVolume(tumorBox, nist->FindOrBuildMaterial("G4_WATER"), "Tumor");
        new G4PVPlacement(0, G4ThreeVector(0,0,0), tumorLog, "Tumor", worldLog, false, 0);

        return worldPhys;
    }
};

// Müon kaynağını oluşturan sınıf
class MuonGun : public G4VUserPrimaryGeneratorAction {
public:
    G4ParticleGun* particleGun;
    MuonGun() {
        particleGun = new G4ParticleGun(1);
        particleGun->SetParticleDefinition(G4ParticleTable::GetParticleTable()->FindParticle("mu+"));
        particleGun->SetParticleEnergy(100*GeV); // 100 GeV Müon
        particleGun->SetParticleMomentumDirection(G4ThreeVector(0.,0.,-1.)); // -Z yönünde
    }
    void GeneratePrimaries(G4Event* anEvent) override {
        particleGun->GeneratePrimaryVertex(anEvent);
    }
};

class MuonPhysics : public G4VUserPhysicsList {
public:
    void ConstructParticle() override {
        G4MuonPlus::MuonPlusDefinition();
    }

    void ConstructProcess() override {
        auto emPhysics = new G4EmStandardPhysics();
        emPhysics->ConstructProcess();
    }

    void SetCuts() override {
        SetCutsWithDefault();
    }
};

int main(int argc, char** argv) {
    G4RunManager* runManager = new G4RunManager();
    runManager->SetUserInitialization(new TumorDetector());
    runManager->SetUserInitialization(new MuonPhysics());
    runManager->SetUserAction(new MuonGun());

    // Görselleştirme
    G4VisManager* visManager = new G4VisExecutive();
    visManager->Initialize();
    G4UImanager* uiManager = G4UImanager::GetUIpointer();
    G4UIExecutive* ui = new G4UIExecutive(argc, argv);

    uiManager->ApplyCommand("/vis/open OGL");
    uiManager->ApplyCommand("/vis/drawVolume");
    uiManager->ApplyCommand("/run/beamOn 1000"); // 1000 Müon atışı

    ui->SessionStart();

    delete visManager;
    delete runManager;
    return 0;
}
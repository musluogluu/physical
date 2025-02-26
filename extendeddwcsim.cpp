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

class MyDetector : public G4VUserDetectorConstruction {
public:
    G4VPhysicalVolume* Construct() override {
        G4NistManager* nist = G4NistManager::Instance();

        // Dünya hacmi
        G4Box* worldBox = new G4Box("World", 50*cm, 50*cm, 50*cm);
        G4LogicalVolume* worldLog = new G4LogicalVolume(worldBox, nist->FindOrBuildMaterial("G4_AIR"), "World");
        G4VPhysicalVolume* worldPhys = new G4PVPlacement(0, G4ThreeVector(), worldLog, "World", 0, false, 0);

        // Dedektör hacmi
        G4Box* detectorBox = new G4Box("Detector", 10*cm, 10*cm, 1*cm);
        G4LogicalVolume* detectorLog = new G4LogicalVolume(detectorBox, nist->FindOrBuildMaterial("G4_Si"), "Detector");
        new G4PVPlacement(0, G4ThreeVector(0,0,0), detectorLog, "Detector", worldLog, false, 0);

        return worldPhys;
    }
};

int main(int argc, char** argv) {
    G4RunManager* runManager = new G4RunManager();
    runManager->SetUserInitialization(new MyDetector());

    // Görselleştirme motoru
    G4VisManager* visManager = new G4VisExecutive();
    visManager->Initialize();

    // Kullanıcı arayüzü
    G4UImanager* uiManager = G4UImanager::GetUIpointer();
    G4UIExecutive* ui = new G4UIExecutive(argc, argv);
    uiManager->ApplyCommand("/vis/open OGL");
    uiManager->ApplyCommand("/vis/drawVolume");

    // Müon ışını
    G4ParticleGun* particleGun = new G4ParticleGun(1);
    particleGun->SetParticleDefinition(G4MuonPlus::MuonPlusDefinition());
    particleGun->SetParticleMomentumDirection(G4ThreeVector(0.,0.,-1.));
    particleGun->SetParticleEnergy(10*GeV);
    particleGun->GeneratePrimaryVertex(new G4Event(0));

    ui->SessionStart();

    delete visManager;
    delete runManager;
    return 0;
}
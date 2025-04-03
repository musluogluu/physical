#include "G4RunManager.hh"
#include "PhysicsList.hh"  // Yeni ekle
#include "DetectorConstruction.hh"
#include "PrimaryGeneratorAction.hh"
#include "RunAction.hh"
#include "EventAction.hh"
#include "G4SystemOfUnits.hh"

int main() {
    G4RunManager* runManager = new G4RunManager();
    
    // 1. ÖNCE PhysicsList
    runManager->SetUserInitialization(new PhysicsList());
    
    // 2. SONRA Detector
    DetectorConstruction* detector = new DetectorConstruction();
    detector->SetMaterial("G4_W");
    detector->SetDimensions(10*cm, 10*cm);
    runManager->SetUserInitialization(detector);

    // 3. Diğer aksiyonlar
    runManager->SetUserAction(new PrimaryGeneratorAction());
    runManager->SetUserAction(new RunAction());
    runManager->SetUserAction(new EventAction());

    runManager->Initialize();
    runManager->BeamOn(10000);
    delete runManager;
    return 0;
}

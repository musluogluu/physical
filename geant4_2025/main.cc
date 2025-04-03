#include "G4RunManager.hh"
#include "DetectorConstruction.hh"
#include "PrimaryGeneratorAction.hh"
#include "RunAction.hh"
#include "EventAction.hh"
#include "G4SystemOfUnits.hh"

int main() {
    G4RunManager* runManager = new G4RunManager();
    
    DetectorConstruction* detector = new DetectorConstruction();
    detector->SetMaterial("G4_W");  // Tungsten
    detector->SetDimensions(10*cm, 10*cm);
    runManager->SetUserInitialization(detector);

    runManager->SetUserAction(new PrimaryGeneratorAction());
    runManager->SetUserAction(new RunAction());
    runManager->SetUserAction(new EventAction());

    runManager->Initialize();
    runManager->BeamOn(10000);  // 10k proton atışı
    delete runManager;
    return 0;
}

#include "G4RunManager.hh"
#include "DetectorConstruction.hh"
#include "PrimaryGeneratorAction.hh"
#include "RunAction.hh"

int main() {
  G4RunManager* runManager = new G4RunManager();
  runManager->SetUserInitialization(new DetectorConstruction());
  runManager->SetUserAction(new PrimaryGeneratorAction());
  runManager->SetUserAction(new RunAction());
  runManager->Initialize();
  runManager->BeamOn(10000); // 10k proton atışı
  delete runManager;
  return 0;
}

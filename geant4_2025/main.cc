#include "G4RunManager.hh"
#include "G4UImanager.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"

#include "DetectorConstruction.hh"
#include "PhysicsList.hh"
#include "PrimaryGeneratorAction.hh"
#include "RunAction.hh"
#include "EventAction.hh"

int main(int argc, char** argv) {
    G4RunManager* runManager = new G4RunManager();
    
    runManager->SetUserInitialization(new DetectorConstruction());
    runManager->SetUserInitialization(new PhysicsList());
    
    runManager->SetUserAction(new PrimaryGeneratorAction());
    runManager->SetUserAction(new RunAction());
    runManager->SetUserAction(new EventAction());
    
    G4VisManager* visManager = new G4VisExecutive();
    visManager->Initialize();
    
    G4UIExecutive* ui = new G4UIExecutive(argc, argv);
    G4UImanager::GetUIpointer()->ApplyCommand("/control/execute macros/init_vis.mac");
    ui->SessionStart();
    
    delete ui;
    delete visManager;
    delete runManager;
    return 0;
}

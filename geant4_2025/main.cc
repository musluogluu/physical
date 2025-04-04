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
    
    RunAction* runAction = new RunAction();
    runManager->SetUserAction(new PrimaryGeneratorAction());
    runManager->SetUserAction(runAction);
    runManager->SetUserAction(new EventAction(runAction));
    
    G4VisManager* visManager = new G4VisExecutive("quiet");
    visManager->Initialize();
    
    G4UImanager* UImanager = G4UImanager::GetUIpointer();
    UImanager->ApplyCommand("/control/macroPath macros");
    UImanager->ApplyCommand("/control/execute init_vis.mac");
    
    G4UIExecutive* ui = new G4UIExecutive(argc, argv);
    ui->SessionStart();
    
    delete ui;
    delete visManager;
    delete runManager;
    return 0;
}

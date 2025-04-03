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
    // 1. RunManager oluştur
    G4RunManager* runManager = new G4RunManager();

    // 2. Zorunlu başlatma
    runManager->SetUserInitialization(new DetectorConstruction());
    runManager->SetUserInitialization(new PhysicsList());

    // 3. Aksiyonlar
    runManager->SetUserAction(new PrimaryGeneratorAction());
    runManager->SetUserAction(new RunAction());
    runManager->SetUserAction(new EventAction());

    // 4. Görselleştirme
    G4VisManager* visManager = new G4VisExecutive();
    visManager->Initialize();

    // 5. UI
    G4UIExecutive* ui = new G4UIExecutive(argc, argv);
    G4UImanager::GetUIpointer()->ApplyCommand("/control/execute macros/init_vis.mac");
    
    // 6. Simülasyon
    runManager->Initialize();
    ui->SessionStart();

    delete ui;
    delete visManager;
    delete runManager;
    return 0;
}

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
    // 1. RunManager oluşturma
    G4RunManager* runManager = new G4RunManager();
    
    // 2. Detector Construction - Nötron dedektörlü versiyon
    DetectorConstruction* detector = new DetectorConstruction();
    runManager->SetUserInitialization(detector);
    
    // 3. Fizik listesi
    runManager->SetUserInitialization(new PhysicsList());
    
    // 4. Aksiyon sınıflarını oluştur ve bağla
    RunAction* runAction = new RunAction();
    EventAction* eventAction = new EventAction(runAction);
    
    // Dedektöre event action'ı bağla
    detector->SetEventAction(eventAction);
    
    // 5. Kullanıcı aksiyonlarını ayarla
    runManager->SetUserAction(new PrimaryGeneratorAction());
    runManager->SetUserAction(runAction);
    runManager->SetUserAction(eventAction);
    
    // 6. Görselleştirme ayarları
    G4VisManager* visManager = new G4VisExecutive();
    visManager->Initialize();
    
    // 7. UI yöneticisi
    G4UIExecutive* ui = new G4UIExecutive(argc, argv);
    G4UImanager* UImanager = G4UImanager::GetUIpointer();
    
    // 8. Görselleştirme komutları
    UImanager->ApplyCommand("/control/execute macros/init_vis.mac");
    
    // 9. Batch mod veya interaktif mod
    if(argc == 1) { // Interaktif mod
        ui->SessionStart();
    } else { // Batch mod
        G4String command = "/control/execute ";
        G4String fileName = argv[1];
        UImanager->ApplyCommand(command + fileName);
    }
    
    // 10. Temizlik
    delete ui;
    delete visManager;
    delete runManager;
    
    return 0;
}

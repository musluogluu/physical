#include "G4RunManager.hh"
#include "G4UImanager.hh"
#include "PhysicsList.hh"
#include "DetectorConstruction.hh"
#include "PrimaryGeneratorAction.hh"
#include "RunAction.hh"
#include "EventAction.hh"

int main() {
  // 1. RunManager oluştur
  G4RunManager* runManager = new G4RunManager();

  // 2. Zorunlu başlatma sırası
  runManager->SetUserInitialization(new PhysicsList());
  
  DetectorConstruction* detector = new DetectorConstruction();
  detector->SetMaterial("G4_W");  // Tungsten varsayılan
  detector->SetDimensions(10*cm, 10*cm);  // 10cm çap/yükseklik
  runManager->SetUserInitialization(detector);

  // 3. Aksiyonlar
  runManager->SetUserAction(new PrimaryGeneratorAction());
  runManager->SetUserAction(new RunAction());
  runManager->SetUserAction(new EventAction());

  // 4. Görselleştirme (OGL)
  G4UImanager* UI = G4UImanager::GetUIpointer();
  UI->ApplyCommand("/control/execute macros/init_vis.mac");  // 3D görsel

  // 5. Simülasyonu başlat
  runManager->Initialize();
  runManager->BeamOn(1000);  // 1000 olay

  delete runManager;
  return 0;
}

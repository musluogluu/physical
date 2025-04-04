// DetectorConstruction.cc
#include "DetectorConstruction.hh"
#include "G4NistManager.hh"
#include "G4Tubs.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "NeutronSD.hh"
#include "G4SDManager.hh"

DetectorConstruction::DetectorConstruction() {}

G4VPhysicalVolume* DetectorConstruction::Construct() {
    G4Material* tungsten = G4NistManager::Instance()->FindOrBuildMaterial("G4_W");
    
    G4Tubs* solidTarget = new G4Tubs("Target", 0, 7.5*cm, 30*cm, 0, 360*deg);
    G4LogicalVolume* logicTarget = new G4LogicalVolume(solidTarget, tungsten, "Target");
    
    G4SDManager* sdManager = G4SDManager::GetSDMpointer();
    NeutronSD* neutronSD = new NeutronSD("NeutronSD");
    sdManager->AddNewDetector(neutronSD);
    logicTarget->SetSensitiveDetector(neutronSD);
    
    return new G4PVPlacement(0, G4ThreeVector(), logicTarget, "Target", nullptr, false, 0);
}

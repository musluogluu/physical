#include "DetectorConstruction.hh"
#include "G4NistManager.hh"
#include "G4Tubs.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SDManager.hh"
#include "NeutronSD.hh"

DetectorConstruction::DetectorConstruction() {
    fMaterial = G4NistManager::Instance()->FindOrBuildMaterial("G4_W");
}

G4VPhysicalVolume* DetectorConstruction::Construct() {
    // Tungsten hedef
    G4Tubs* solidTarget = new G4Tubs("Target", 0, fDiameter/2, fHeight/2, 0, 360*deg);
    G4LogicalVolume* logicTarget = new G4LogicalVolume(solidTarget, fMaterial, "Target");
    
    // Hassas dedektör ekleme
    G4SDManager* sdManager = G4SDManager::GetSDMpointer();
    NeutronSD* neutronSD = new NeutronSD("NeutronSD");
    sdManager->AddNewDetector(neutronSD);
    logicTarget->SetSensitiveDetector(neutronSD);
    
    return new G4PVPlacement(0, G4ThreeVector(), logicTarget, "Target", nullptr, false, 0);
}

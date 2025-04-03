#include "DetectorConstruction.hh"
#include "G4NistManager.hh"
#include "G4Tubs.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"

DetectorConstruction::DetectorConstruction()
: fWorldSize(1.5*m), fTargetMaterial(nullptr) {
    SetMaterial("G4_W"); // Varsayılan: Tungsten
    SetDimensions(10*cm, 10*cm); // Varsayılan boyut
}

G4VPhysicalVolume* DetectorConstruction::Construct() {
    // Dünya hacmi
    G4Box* solidWorld = new G4Box("World", fWorldSize/2, fWorldSize/2, fWorldSize/2);
    G4LogicalVolume* logicWorld = new G4LogicalVolume(solidWorld, 
        G4NistManager::Instance()->FindOrBuildMaterial("G4_AIR"), "World");
    
    // Hedef silindir
    G4Tubs* solidTarget = new G4Tubs("Target", 0, fDiameter/2, fHeight/2, 0, 360*deg);
    G4LogicalVolume* logicTarget = new G4LogicalVolume(solidTarget, fTargetMaterial, "Target");
    new G4PVPlacement(0, G4ThreeVector(), logicTarget, "Target", logicWorld, false, 0);
    
    return new G4PVPlacement(0, G4ThreeVector(), logicWorld, "World", 0, false, 0);
}

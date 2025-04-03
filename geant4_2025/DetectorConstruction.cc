#include "DetectorConstruction.hh"
#include "G4NistManager.hh"
#include "G4Tubs.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"

DetectorConstruction::DetectorConstruction()
: fDiameter(10*cm), fHeight(10*cm), fMaterial(nullptr) {}

G4VPhysicalVolume* DetectorConstruction::Construct() {
    G4Tubs* solidTarget = new G4Tubs("Target", 0, fDiameter/2, fHeight/2, 0, 360*deg);
    G4LogicalVolume* logicTarget = new G4LogicalVolume(solidTarget, fMaterial, "Target");
    return new G4PVPlacement(0, G4ThreeVector(), logicTarget, "Target", 0, false, 0);
}

void DetectorConstruction::SetMaterial(const G4String& materialName) {
    fMaterial = G4NistManager::Instance()->FindOrBuildMaterial(materialName);
}

void DetectorConstruction::SetDimensions(G4double diameter, G4double height) {
    fDiameter = diameter;
    fHeight = height;
}

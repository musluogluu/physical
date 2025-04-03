#include "DetectorConstruction.hh"
#include "G4NistManager.hh"
#include "G4Tubs.hh"

DetectorConstruction::DetectorConstruction() 
  : fDiameter(10*cm), fHeight(10*cm) {}

G4VPhysicalVolume* DetectorConstruction::Construct() {
  G4Material* tungsten = G4NistManager::Instance()->FindOrBuildMaterial("G4_W");
  G4Tubs* solidTarget = new G4Tubs("Target", 0, fDiameter/2, fHeight/2, 0, 360*deg);
  G4LogicalVolume* logicTarget = new G4LogicalVolume(solidTarget, tungsten, "Target");
  return new G4PVPlacement(0, G4ThreeVector(), logicTarget, "Target", 0, false, 0);
}

void DetectorConstruction::SetSize(G4double diameter, G4double height) {
  fDiameter = diameter;
  fHeight = height;
}

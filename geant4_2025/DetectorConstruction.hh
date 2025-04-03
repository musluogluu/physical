#include "G4VUserDetectorConstruction.hh"

class DetectorConstruction : public G4VUserDetectorConstruction {
public:
  DetectorConstruction();
  virtual G4VPhysicalVolume* Construct();
  void SetSize(G4double diameter, G4double height);
private:
  G4double fDiameter, fHeight;
};

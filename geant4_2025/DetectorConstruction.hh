#ifndef DETECTOR_CONSTRUCTION_HH
#define DETECTOR_CONSTRUCTION_HH

#include "G4VUserDetectorConstruction.hh"
#include "G4Material.hh"

class DetectorConstruction : public G4VUserDetectorConstruction {
public:
    DetectorConstruction();
    virtual ~DetectorConstruction();  // Düzeltme: Virtual destructor eklendi
    
    virtual G4VPhysicalVolume* Construct();
    void SetMaterial(const G4String& materialName);
    void SetDimensions(G4double diameter, G4double height);

private:
    G4double fDiameter;
    G4double fHeight;
    G4Material* fMaterial;
};

#endif

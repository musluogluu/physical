#ifndef DETECTOR_CONSTRUCTION_HH
#define DETECTOR_CONSTRUCTION_HH

#include "G4VUserDetectorConstruction.hh"
#include "G4Material.hh"
#include "G4SystemOfUnits.hh"

class EventAction; // Forward declaration eklendi

class DetectorConstruction : public G4VUserDetectorConstruction {
public:
    DetectorConstruction();
    virtual ~DetectorConstruction() = default;
    
    virtual G4VPhysicalVolume* Construct() override;
    void SetEventAction(EventAction* eventAction); // Yeni eklendi
    
private:
    G4double fDiameter = 15*cm;
    G4double fHeight = 60*cm;
    G4Material* fMaterial = nullptr;
    EventAction* fEventAction = nullptr; // Yeni eklendi
};

#endif

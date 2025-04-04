#include "NeutronSD.hh"
#include "G4Step.hh"
#include "G4Track.hh"
#include "G4Neutron.hh"
#include "G4SDManager.hh"
#include "G4SystemOfUnits.hh"

NeutronSD::NeutronSD(const G4String& name)
    : G4VSensitiveDetector(name) {
    collectionName.insert("NeutronHitsCollection");
}

void NeutronSD::Initialize(G4HCofThisEvent* hce) {
    fHitsCollection = new NeutronHitsCollection(
        SensitiveDetectorName, 
        collectionName[0]
    );
    
    if(hce) {
        G4int hcID = G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]);
        hce->AddHitsCollection(hcID, fHitsCollection);
    }
}

G4bool NeutronSD::ProcessHits(G4Step* aStep, G4TouchableHistory* ROhist) {
    
    G4Track* track = step->GetTrack();
    G4Track* track = aStep->GetTrack();
    G4ThreeVector momentumDirection = track->GetMomentumDirection();
    G4double theta = momentumDirection.theta(); // Radyan cinsinden
    
    G4double energy = track->GetKineticEnergy(); // MeV cinsinden
    
    auto hit = new NeutronHit();
    hit->SetTheta(theta * 180.0 / CLHEP::pi); // Dereceye çevir
    hit->SetEnergy(energy);
    if(track->GetDefinition() != G4Neutron::NeutronDefinition()) {
        return false;
    }

    NeutronHit* hit = new NeutronHit();
    hit->SetEnergy(track->GetKineticEnergy());
    hit->SetMomentumDirection(track->GetMomentumDirection());
    
    fHitsCollection->insert(hit);
    return true;
}

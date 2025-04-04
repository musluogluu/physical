#include "NeutronSD.hh"
#include "G4Neutron.hh"
#include "G4Step.hh"
#include "G4Track.hh"
#include "G4HCofThisEvent.hh"
#include "G4SDManager.hh"

NeutronSD::NeutronSD(const G4String& name) 
: G4VSensitiveDetector(name), fHitsCollection(nullptr), fHCID(-1) {
    collectionName.insert("NeutronHitsCollection");
}

void NeutronSD::Initialize(G4HCofThisEvent* hce) {
    fHitsCollection = new NeutronHitsCollection(SensitiveDetectorName, collectionName[0]);
    if(fHCID < 0) fHCID = G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]);
    hce->AddHitsCollection(fHCID, fHitsCollection);
}

G4bool NeutronSD::ProcessHits(G4Step* step, G4TouchableHistory*) {
    G4Track* track = step->GetTrack();
    
    // Sadece nötronları kaydet
    if(track->GetDefinition() != G4Neutron::NeutronDefinition()) return false;
    
    NeutronHit* hit = new NeutronHit();
    hit->SetEnergy(track->GetKineticEnergy());
    hit->SetPosition(track->GetPosition());
    hit->SetMomentumDirection(track->GetMomentumDirection());
    
    fHitsCollection->insert(hit);
    return true;
}

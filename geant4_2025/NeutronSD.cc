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

G4bool NeutronSD::ProcessHits(G4Step* step, G4TouchableHistory*) {
    G4Track* track = step->GetTrack();
    
    // Nötron kontrolü ve veri yazdırma
    if(track->GetDefinition() == G4Neutron::NeutronDefinition()) {
        G4cout << "NEUTRON_DATA: "
               << "Angle=" << track->GetMomentumDirection().theta()/deg << "deg "
               << "Energy=" << track->GetKineticEnergy()/MeV << "MeV "
               << "Pos=" << track->GetPosition()/mm << "mm\n";
    }
    
    // Mevcut hit işleme kodu (değiştirme)
    if(track->GetDefinition() != G4Neutron::NeutronDefinition()) return false;
    NeutronHit* hit = new NeutronHit();
    hit->SetEnergy(track->GetKineticEnergy());
    hit->SetMomentumDirection(track->GetMomentumDirection());
    fHitsCollection->insert(hit);
    return true;
}

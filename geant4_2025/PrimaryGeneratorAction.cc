#include "PrimaryGeneratorAction.hh"
#include "G4Proton.hh"
#include "G4Event.hh"
#include "G4SystemOfUnits.hh"

PrimaryGeneratorAction::PrimaryGeneratorAction() {
    fParticleGun = new G4ParticleGun();
    fParticleGun->SetParticleDefinition(G4Proton::ProtonDefinition());
    fParticleGun->SetParticleEnergy(1.5*GeV);
    fParticleGun->SetParticlePosition(G4ThreeVector(0, 0, -1*m));
    fParticleGun->SetParticleMomentumDirection(G4ThreeVector(0, 0, 1));
}

PrimaryGeneratorAction::~PrimaryGeneratorAction() {  // Düzeltme: Destructor implemente edildi
    delete fParticleGun;
}

void PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent) {
    fParticleGun->GeneratePrimaryVertex(anEvent);
}

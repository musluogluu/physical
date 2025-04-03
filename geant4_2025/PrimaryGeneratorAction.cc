#include "PrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"

PrimaryGeneratorAction::PrimaryGeneratorAction() {
  G4ParticleGun* fParticleGun = new G4ParticleGun();
  fParticleGun->SetParticleDefinition(G4Proton::ProtonDefinition());
  fParticleGun->SetParticleEnergy(1.5*GeV);
  fParticleGun->SetParticlePosition(G4ThreeVector(0, 0, -1*m));
}

void PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent) {
  fParticleGun->GeneratePrimaryVertex(anEvent);
}

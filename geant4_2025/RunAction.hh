#ifndef RUN_ACTION_HH
#define RUN_ACTION_HH

#include "G4UserRunAction.hh"
#include "G4Accumulable.hh"
#include <map>

class RunAction : public G4UserRunAction {
public:
    RunAction();
    virtual ~RunAction();  // DESTRUCTOR mutlaka virtual olmalı
    
    virtual void BeginOfRunAction(const G4Run* run) override;
    virtual void EndOfRunAction(const G4Run* run) override;
    
    void AddNeutronEnergy(G4double energy);
    
private:
    G4Accumulable<G4int> fNeutronCount;
    std::map<G4int, G4int> fEnergySpectrum;
};

#endif

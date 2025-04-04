// RunAction.hh
#ifndef RUN_ACTION_HH
#define RUN_ACTION_HH

#include "G4UserRunAction.hh"
#include <map>

class RunAction : public G4UserRunAction {
public:
    RunAction();
    virtual ~RunAction();
    
    virtual void BeginOfRunAction(const G4Run*) override;
    virtual void EndOfRunAction(const G4Run*) override;
    
    void RecordNeutron(G4double energy, G4double angle);
    
private:
    std::map<G4int, G4int> angleHist; // 5°'lik bölmeler
    std::map<G4int, G4int> energyHist; // 10 MeV'lik bölmeler
    G4int totalNeutrons;
};

#endif

#ifndef RUN_ACTION_HH
#define RUN_ACTION_HH

#include "G4UserRunAction.hh"
#include "globals.hh"

class RunAction : public G4UserRunAction {
public:
    RunAction();
    virtual ~RunAction();  // Düzeltme: Virtual destructor eklendi
    
    virtual void BeginOfRunAction(const G4Run*);
    virtual void EndOfRunAction(const G4Run*);
};

#endif

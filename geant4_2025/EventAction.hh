// EventAction.hh
#ifndef EVENT_ACTION_HH
#define EVENT_ACTION_HH

#include "G4UserEventAction.hh"
#include "RunAction.hh"

class EventAction : public G4UserEventAction {
public:
    EventAction(RunAction* runAction);
    virtual ~EventAction() = default;
    
    virtual void BeginOfEventAction(const G4Event*) override;
    virtual void EndOfEventAction(const G4Event*) override;
    
private:
    RunAction* fRunAction;
};

#endif

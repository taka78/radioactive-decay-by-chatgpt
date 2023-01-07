#ifndef RUNACTION_HH
#define RUNACTION_HH

#include "G4UserRunAction.hh"

class RunAction : public G4UserRunAction
    {
    G4Run* GenerateRun() override;
    public:
     RunAction();
     virtual ~RunAction();

    virtual void BeginOfRunAction(const G4Run* run);
    virtual void EndOfRunAction(const G4Run* run);
};

#endif
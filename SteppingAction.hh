#ifndef STEPPINGACTION_HH
#define STEPPINGACTION_HH

#include "G4UserSteppingAction.hh"

class DetectorConstruction;
class EventAction;

class SteppingAction : public G4UserSteppingAction
{
 public:
  SteppingAction(DetectorConstruction* detector, EventAction* eventAction);
  virtual ~SteppingAction();

  virtual void UserSteppingAction(const G4Step* step);

 private:
  DetectorConstruction* fDetector;
  EventAction* fEventAction;
};

#endif
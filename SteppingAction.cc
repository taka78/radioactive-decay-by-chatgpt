#include "SteppingAction.hh"

#include "G4Step.hh"
#include "G4Track.hh"
#include "G4VProcess.hh"

SteppingAction::SteppingAction(DetectorConstruction* detector, EventAction* eventAction)
  : G4UserSteppingAction(),
    fDetector(detector),
    fEventAction(eventAction)
{
}

SteppingAction::~SteppingAction()
{
}

void SteppingAction::UserSteppingAction(const G4Step* step)
{
  // Get the track and process that caused the step
  G4Track* track = step->GetTrack();
  const G4VProcess* process = track->GetCreatorProcess();

  // Print the process name if it is a radioactive decay
  if (process && process->GetProcessName() == "RadioactiveDecay")
  {
    G4cout << ">>> Radioactive decay process: " << process->GetProcessName() << G4endl;
  }
}
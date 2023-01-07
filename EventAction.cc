#include "EventAction.hh"

#include "G4Event.hh"

EventAction::EventAction(RunAction* runAction)
  : G4UserEventAction(),
    fRunAction(runAction)
{
}

EventAction::~EventAction()
{
}

void EventAction::BeginOfEventAction(const G4Event* event)
{
  // Print the event number at the start of the event
  G4cout << ">>> Event " << event->GetEventID() << " start." << G4endl;
}

void EventAction::EndOfEventAction(const G4Event* event)
{
  // Print the event number at the end of the event
  G4cout << ">>> Event " << event->GetEventID() << " end." << G4endl;
}

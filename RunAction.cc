#include "RunAction.hh"

#include "G4Run.hh"
#include "G4SystemOfUnits.hh"

RunAction::RunAction()
  : G4UserRunAction()
{
}

RunAction::~RunAction()
{
}

G4Run* RunAction::GenerateRun()
{
  return new G4Run();
}

void RunAction::BeginOfRunAction(const G4Run* run)
{
  // Print the run number at the start of the run
  G4cout << ">>> Run " << run->GetRunID() << " start." << G4endl;
}

void RunAction::EndOfRunAction(const G4Run* run)
{
  // Print the run number at the end of the run
  G4cout << ">>> Run " << run->GetRunID() << " end." << G4endl;
}

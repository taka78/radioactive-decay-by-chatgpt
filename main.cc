#include "G4RunManager.hh"
#include "G4UImanager.hh"
#include "Randomize.hh"

#include "GMTubeSD.hh"
#include "DetectorConstruction.hh"
#include "PrimaryGeneratorAction.hh"
#include "RunAction.hh"
#include "EventAction.hh"
#include "SteppingAction.hh"

int main(int argc, char** argv)
{
  // Set the random seed
  CLHEP::HepRandom::setTheSeed(time(NULL));

  // Create the run manager
  G4RunManager* runManager = new G4RunManager;

  // Set the detector construction
  DetectorConstruction* detector = new DetectorConstruction;
  runManager->SetUserInitialization(detector);

  // Set the primary generator action
  PrimaryGeneratorAction* generator = new PrimaryGeneratorAction(detector);
  runManager->SetUserAction(generator);

  // Set the run action
  RunAction* runAction = new RunAction;
  runManager->SetUserAction(runAction);

  // Set the event action
  EventAction* eventAction = new EventAction(runAction);
  runManager->SetUserAction(eventAction);

  // Set the stepping action
  SteppingAction* steppingAction = new SteppingAction(detector, eventAction);
  runManager->SetUserAction(steppingAction);

  // Initialize the run manager
  runManager->Initialize();

  // Get the UI manager
  G4UImanager* UImanager = G4UImanager::GetUIpointer();

  // Process the macro file
  G4String macroName = "run.mac";
  UImanager->ExecuteMacroFile(macroName);

  // Run the simulation
  runManager->BeamOn(10000);

  // Clean up
  delete runManager;

  return 0;
}
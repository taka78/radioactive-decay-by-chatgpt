#include "GMTubeSD.hh"

#include "GMTubeSD.hh"
#include "G4Step.hh"
#include "G4SDManager.hh"
#include "G4VSensitiveDetector.hh"
#include "G4MultiFunctionalDetector.hh"
#include "G4VTouchable.hh"
#include "GMTubeHit.hh"

const int N_VOLUMES = 100;
G4double fEdep[N_VOLUMES]; // Declare fEdep as a global variable
GMTubeHit* fHit; // Declare fHit as a global variable

GMTubeSD::GMTubeSD(const G4String& name) : G4VSensitiveDetector(name)
{
  // Register the sensitive detector with the G4SDManager
  G4SDManager::GetSDMpointer()->AddNewDetector(this);
  for (G4int i = 0; i < N_VOLUMES; i++) {
    fEdep[i] = 0;
  }
}

G4bool GMTubeSD::ProcessHits(G4Step* aStep, G4TouchableHistory*) {
  // Get the energy deposit in the step
  G4double edep = aStep->GetTotalEnergyDeposit();

  // Get the touchable for the current step
  G4VTouchable* touchable = const_cast<G4VTouchable*>(aStep->GetPreStepPoint()->GetTouchable());

  // Get the copy number of the current volume
  G4int copyNo = touchable->GetVolume()->GetCopyNo();

  // Add the energy deposit to the current volume
  fEdep[copyNo] += edep;

  return true;
}
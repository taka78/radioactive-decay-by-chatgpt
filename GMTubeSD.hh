#ifndef GMTUBESD_hh
#define GMTUBESD_hh

#include "G4VSensitiveDetector.hh"

class GMTubeSD : public G4VSensitiveDetector
{
public:
  GMTubeSD(const G4String& name);
  virtual ~GMTubeSD();

  virtual void Initialize(G4HCofThisEvent* HCE);
  virtual G4bool ProcessHits(G4Step* aStep, G4TouchableHistory* ROhist);
  virtual void EndOfEvent(G4HCofThisEvent* HCE);

private:
  static const G4int N_VOLUMES = 10;  // Declare N_VOLUMES as a constant integer
  G4double fEdep[N_VOLUMES];
};

#endif
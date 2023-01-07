#ifndef GMTubeHit_hh
#define GMTubeHit_hh

#include "G4VHit.hh"

class GMTubeHit : public G4VHit
{
 public:
  GMTubeHit();
  virtual ~GMTubeHit();

  void* operator new(size_t);
  void  operator delete(void*);
};

#endif
#ifndef ScintPhysicsList_h
#define ScintPhysicsList_h 1

#include "G4VUserPhysicsList.hh"
#include "globals.hh"

class ScintPhysicsList: public G4VUserPhysicsList
{
  public:
    ScintPhysicsList();
    ~ScintPhysicsList();

  protected:
    // Construct particle and physics process
    void ConstructParticle();
    void ConstructProcess();
    void ConstructEM();
    void SetCuts();

};

#endif
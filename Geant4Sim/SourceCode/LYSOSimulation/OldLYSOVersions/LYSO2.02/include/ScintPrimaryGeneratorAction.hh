#ifndef ScintPrimaryGeneratorAction_h
#define ScintPrimaryGeneratorAction_h 1

#include "G4VUserPrimaryGeneratorAction.hh"


class G4GeneralParticleSource;
class G4Event;


class ScintPrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
  public:
    ScintPrimaryGeneratorAction();
    ~ScintPrimaryGeneratorAction();

    // methods
    virtual void GeneratePrimaries(G4Event*);

  private:
    // data members
    G4GeneralParticleSource* fParticleGun; //pointer a to G4 service class
};

#endif
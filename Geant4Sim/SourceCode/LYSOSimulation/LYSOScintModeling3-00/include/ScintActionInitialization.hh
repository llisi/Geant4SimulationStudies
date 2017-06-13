#ifndef ScintActionInitialization_h
#define ScintActionInitialization_h 1

#include "G4VUserActionInitialization.hh"

class ScintDetectorConstruction;
/// Action initialization class.
///

class ScintActionInitialization : public G4VUserActionInitialization
{
  public:
    ScintActionInitialization(ScintDetectorConstruction*);
    virtual ~ScintActionInitialization();

    virtual void BuildForMaster() const;
    virtual void Build() const;

  private:
    ScintDetectorConstruction* fDetConstruction;
};

#endif
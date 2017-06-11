#ifndef ScintActionInitialization_h
#define ScintActionInitialization_h 1

#include "G4VUserActionInitialization.hh"

/// Action initialization class.
///

class ScintActionInitialization : public G4VUserActionInitialization
{
  public:
    ScintActionInitialization();
    virtual ~ScintActionInitialization();

    virtual void BuildForMaster() const;
    virtual void Build() const;
};

#endif
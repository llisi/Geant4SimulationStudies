//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
// $Id: ScintCalorHit.hh 100946 2016-11-03 11:28:08Z gcosmo $
//
/// \file ScintCalorHit.hh
/// \brief Definition of the ScintCalorHit class

#ifndef ScintCalorHit_h
#define ScintCalorHit_h 1

#include "G4VHit.hh"
#include "G4THitsCollection.hh"
#include "G4Allocator.hh"
#include "G4ThreeVector.hh"
#include "G4Threading.hh"

/// Calorimeter hit class
///
/// It defines data members to store the the energy deposit and track lengths
/// of charged particles in a selected volume:
/// - fEdep, fTrackLength

class ScintCalorHit : public G4VHit
{
  public:
    ScintCalorHit();
    ScintCalorHit(const ScintCalorHit&);
    virtual ~ScintCalorHit();

    // operators
    const ScintCalorHit& operator=(const ScintCalorHit&);
    G4int operator==(const ScintCalorHit&) const;

    inline void* operator new(size_t);
    inline void  operator delete(void*);

    // methods from base class
    virtual void Draw() {}
    virtual void Print();

    // methods to handle data
    void Add(G4double de, G4double dl, G4ThreeVector p);

    // get methods
    G4double GetEdep() const;
    G4double GetTrackLength() const;
    G4ThreeVector GetTrackPos() const;
      
  private:
    G4double fEdep;        ///< Energy deposit in the sensitive volume
    G4double fTrackLength; ///< Track length in the  sensitive volume
    G4ThreeVector fTrackPos;
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

using ScintCalorHitsCollection = G4THitsCollection<ScintCalorHit>;

extern G4ThreadLocal G4Allocator<ScintCalorHit>* ScintCalorHitAllocator;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

inline void* ScintCalorHit::operator new(size_t)
{
  if (!ScintCalorHitAllocator) {
    ScintCalorHitAllocator = new G4Allocator<ScintCalorHit>;
  }
  void *hit;
  hit = (void *) ScintCalorHitAllocator->MallocSingle();
  return hit;
}

inline void ScintCalorHit::operator delete(void *hit)
{
  if (!ScintCalorHitAllocator) {
    ScintCalorHitAllocator = new G4Allocator<ScintCalorHit>;
  }
  ScintCalorHitAllocator->FreeSingle((ScintCalorHit*) hit);
}

inline void ScintCalorHit::Add(G4double de, G4double dl, G4ThreeVector p) {
  fEdep += de; 
  fTrackLength += dl;
  fTrackPos = p;
}

inline G4double ScintCalorHit::GetEdep() const { 
  return fEdep; 
}

inline G4double ScintCalorHit::GetTrackLength() const { 
  return fTrackLength; 
}

inline G4ThreeVector ScintCalorHit::GetTrackPos() const { 
  return fTrackPos; 
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

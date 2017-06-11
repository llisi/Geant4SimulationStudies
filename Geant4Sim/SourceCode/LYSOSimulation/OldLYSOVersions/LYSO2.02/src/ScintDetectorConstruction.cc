#include "ScintDetectorConstruction.hh"

#include "G4Material.hh"
#include "G4NistManager.hh"

#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4PVReplica.hh"
#include "G4GlobalMagFieldMessenger.hh"
#include "G4AutoDelete.hh"

#include "G4SDManager.hh"

#include "G4VisAttributes.hh"
#include "G4Colour.hh"

#include "G4PhysicalConstants.hh"
#include "G4SystemOfUnits.hh"

#include "ScintCalorimeterSD.hh"

G4ThreadLocal 
G4GlobalMagFieldMessenger* ScintDetectorConstruction::fMagFieldMessenger = 0; 

ScintDetectorConstruction::ScintDetectorConstruction()
 : G4VUserDetectorConstruction(),
   fCheckOverlaps(false),
   fNofLayers(-1)
{
}

ScintDetectorConstruction::~ScintDetectorConstruction()
{
}

G4VPhysicalVolume* ScintDetectorConstruction::Construct()
{
  // Define materials 
  DefineMaterials();
  
  // Define volumes
  return DefineVolumes();
}


void ScintDetectorConstruction::DefineMaterials()
{ 
  // Lead material defined using NIST Manager
  //------------------------------------------------------ materials

  G4double density;
  G4double fractionalmass;

  G4String name;
  G4int ncomponents;

  //G4Material* Pb = 
  //new G4Material("Lead", z= 82., a= 207.19*g/mole, density= 11.35*g/cm3);

  G4NistManager* man = G4NistManager::Instance();


  G4Material* Lu  = man->FindOrBuildMaterial("G4_Lu");
  G4Material* Y = man->FindOrBuildMaterial("G4_Y");
  G4Material* Si = man->FindOrBuildMaterial("G4_Si");
  G4Material* O = man->FindOrBuildMaterial("G4_O");
  G4Material* Ce = man->FindOrBuildMaterial("G4_Ce");

  G4Material* Ba = man->FindOrBuildMaterial("G4_Ba");
  G4Material* S = man->FindOrBuildMaterial("G4_S");

  G4Material* N = man->FindOrBuildMaterial("G4_N");

  
  G4Material* Air = new G4Material(name="Air",density = 1.290*mg/cm3,ncomponents=2);
  Air->AddMaterial(N, fractionalmass=70*perCent);
  Air->AddMaterial(O, fractionalmass=30*perCent);

  G4Material* LYSO = new G4Material(name="LYSO",density= 7.4*g/cm3 ,ncomponents= 5);
  LYSO->AddMaterial(Lu, fractionalmass= 39*perCent);
  LYSO->AddMaterial(Y, fractionalmass= 20*perCent);
  LYSO->AddMaterial(Si, fractionalmass= 6*perCent);
  LYSO->AddMaterial(O, fractionalmass= 4*perCent);
  LYSO->AddMaterial(Ce, fractionalmass= 31*perCent);

  // Information of BaSO4 reflector found at http://www.optopolymer.de/pdf/OptoPolymer-en.pdf

  G4Material* BaSO4 = new G4Material(name="BaSO4", density= 1.5*g/cm3, ncomponents= 3);
  BaSO4->AddMaterial(Ba, fractionalmass= 58.8*perCent);
  BaSO4->AddMaterial(S, fractionalmass= 13.8*perCent);
  BaSO4->AddMaterial(O, fractionalmass= 27.4*perCent);

}

G4VPhysicalVolume* ScintDetectorConstruction::DefineVolumes()
{
  //Geometry Parameters
  fNofLayers = 50.*60.;
  G4int copyNumber;

  G4double world_x = 40.0*cm *.5;
  G4double world_y = 40.0*cm *.5;
  G4double world_z = 40.0*cm *.5;

  G4double pixel_x = 1.2*mm *.5;
  G4double pixel_y = 12*mm *.5;
  G4double pixel_z = 1.2*mm *.5;

  G4double reflectorInside_x = 0.05*mm;
  G4double reflectorInside_y = 6*mm;
  G4double reflectorInside_z = 0.6*mm;

  G4double reflectorOutside1_x = 0.25*mm;
  G4double reflectorOutside1_y = 6*mm;
  G4double reflectorOutside1_z = 32.95*mm;

  G4double reflectorOutside2_x = 38.95*mm;
  G4double reflectorOutside2_y = 6*mm;
  G4double reflectorOutside2_z = 0.25*mm;

  G4double reflectorBottom_x = 39.45*mm;
  G4double reflectorBottom_y = 0.5*mm;
  G4double reflectorBottom_z = 32.95*mm;

  G4double pixelPos_x;
  G4double pixelPos_y = 0.0*cm;     // y is vertial. We do not translate pixels vertially
  G4double pixelPos_z;

  G4double reflectorPos_x;
  G4double reflectorPos_y;
  G4double reflectorPos_z;

  auto worldMaterial = G4Material::GetMaterial("Air");
  auto scintMaterial = G4Material::GetMaterial("LYSO");
  auto relfectorMaterial = G4Material::GetMaterial("BaSO4");


  //
  // World
  //

  G4Box* worldS
    = new G4Box("World",world_x,world_y,world_z);

  auto worldLV =                         
    new G4LogicalVolume(worldS,               //its solid
                        worldMaterial,                  //its material
                        "World");             //its name
                                   
  auto worldPV = 
    new G4PVPlacement(0,                     //no rotation
                      G4ThreeVector(),       //at (0,0,0)
                      worldLV,               //its logical volume
                      "World",               //its name
                      0,                     //its mother  volume
                      false,                 //no boolean operation
                      0,                     //copy number
                      fCheckOverlaps);       //overlaps checking


//
// Pixels
//


G4Box* pixelS = new G4Box("Pixel",
                            pixel_x,
                            pixel_y,
                            pixel_z);

auto pixelLV = new G4LogicalVolume(pixelS,
                                    scintMaterial,
                                    "PixelLV");

//Layer a 60x50 grid of LYSO Pixels

for(G4int i=1;i<61;i++) {

  pixelPos_x = -39.65*mm + 1.3*mm * i;

  for(G4int n=1;n<51;n++){

    copyNumber = (n)*(i);

    pixelPos_z = -33.8*mm + 1.3*mm * n;
  
    new G4PVPlacement(0,
                      G4ThreeVector(pixelPos_x,pixelPos_y,pixelPos_z),
                      pixelLV,
                      "Pixel",
                      worldLV,
                      false,
                      copyNumber,
                      fCheckOverlaps);

    }
  }

//
// Inside Reflectors
//

reflectorPos_y = 0.0*cm;

G4Box* reflectorInsideS = new G4Box("ReflectorInside",
                                    reflectorInside_x,
                                    reflectorInside_y,
                                    reflectorInside_z);

auto reflectorInsideLV = new G4LogicalVolume(reflectorInsideS,
                                              relfectorMaterial,
                                              "ReflectorLV");

//------------------------ Reflectors normal to z

  for(G4int i=1;i<60;i++){

    reflectorPos_x = -39.0*mm + 1.3*mm * i;

    for(G4int n=1;n<51;n++){

      copyNumber = (n)*(i);

      reflectorPos_z = -33.8*mm + 1.3*mm * n;

      new G4PVPlacement(0,
                        G4ThreeVector(reflectorPos_x,reflectorPos_y,reflectorPos_z),
                        reflectorInsideLV,
                        "ReflectorInside",
                        worldLV,
                        false,
                        copyNumber,
                        fCheckOverlaps);

    }
  }

//------------------------ Reflectors normal to x

  G4RotationMatrix* reflectorRotation = new G4RotationMatrix();
  reflectorRotation->rotateX(0.*deg);
  reflectorRotation->rotateY(90.*deg);
  reflectorRotation->rotateZ(0.*rad);

  for(G4int i=1;i<61;i++){

    reflectorPos_x = -39.65*mm + 1.3*mm * i;

    for(G4int n=1;n<50;n++){

      copyNumber = (n)*(i)*-1;

      reflectorPos_z = -33.15*mm + 1.3*mm * n;

      new G4PVPlacement(reflectorRotation,
                        G4ThreeVector(reflectorPos_x,reflectorPos_y,reflectorPos_z),
                        reflectorInsideLV,
                        "ReflectorInside",
                        worldLV,
                        false,
                        copyNumber,
                        fCheckOverlaps);
    }
}

//
//Oustide Reflectors
//

//--------------------------- Normal to x


G4Box* reflectorOutside1S = new G4Box("ReflectorOutisde1",
                                       reflectorOutside1_x,
                                       reflectorOutside1_y,
                                       reflectorOutside1_z);

auto reflectorOutside1LV = new G4LogicalVolume(reflectorOutside1S,
                                              relfectorMaterial,
                                              "ReflectorOutside1LV");

reflectorPos_z = -0.65;

for(G4int i=0;i<2;i++){

  copyNumber = i;
  
  reflectorPos_x = (-38.35*mm - 0.85*mm) + (78.4*mm * i);
  new G4PVPlacement(0,
                    G4ThreeVector(reflectorPos_x,reflectorPos_y,reflectorPos_z),
                    reflectorOutside1LV,
                    "ReflectorOutside",
                    worldLV,
                    false,
                    copyNumber,
                    fCheckOverlaps);
}

//-------------------------- Normal to z

G4Box* reflectorOutside2S = new G4Box("ReflectorOutside2",
                                      reflectorOutside2_x,
                                      reflectorOutside2_y,
                                      reflectorOutside2_z);

auto reflectorOutside2LV = new G4LogicalVolume(reflectorOutside2S,
                                              relfectorMaterial,
                                              "ReflectorOutisde2LV");
reflectorPos_x = 0;

for(G4int i=0;i<2;i++){

  copyNumber = i*-1;

  reflectorPos_z = (-33.35*mm) + (65.4*mm * i);
  new G4PVPlacement(0,
                    G4ThreeVector(reflectorPos_x,reflectorPos_y,reflectorPos_z),
                    reflectorOutside2LV,
                    "ReflectorOutside",
                    worldLV,
                    false,
                    copyNumber,
                    fCheckOverlaps);
}

//
// Bottom Reflector
//

G4Box* reflectorBottomS = new G4Box("ReflectorBottom",
                                     reflectorBottom_x,
                                     reflectorBottom_y,
                                     reflectorBottom_z);

auto reflectorBottomLV = new G4LogicalVolume(reflectorBottomS,
                                             relfectorMaterial,
                                             "ReflectorBottomLV");
reflectorPos_x = 0;
reflectorPos_y = -6.5;
reflectorPos_z = -0.65;

new G4PVPlacement(0,
                  G4ThreeVector(reflectorPos_x,reflectorPos_y,reflectorPos_z),
                  reflectorBottomLV,
                  "ReflectorBottom",
                  worldLV,
                  false,
                  0,
                  fCheckOverlaps);


  //
  // Always return the physical World
  //
  return worldPV;

}

void ScintDetectorConstruction::ConstructSDandField()
{
  // G4SDManager::GetSDMpointer()->SetVerboseLevel(1);

  // 
  // Sensitive detectors
  //

  auto absoSD 
    = new ScintCalorimeterSD("AbsorberSD", "AbsorberHitsCollection", fNofLayers);
  G4SDManager::GetSDMpointer()->AddNewDetector(absoSD);
  SetSensitiveDetector("PixelLV",absoSD);


  // 
  // Magnetic field
  //
  // Create global magnetic field messenger.
  // Uniform magnetic field is then created automatically if
  // the field value is not zero.
  G4ThreeVector fieldValue;
  fMagFieldMessenger = new G4GlobalMagFieldMessenger(fieldValue);
  fMagFieldMessenger->SetVerboseLevel(1);
  
  // Register the field messenger for deleting
  G4AutoDelete::Register(fMagFieldMessenger);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......





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
  G4int copyNumber;


  // z by x pixel grid. Laser direction in Z

  G4double nPixels_Z = 11;
  G4double nPixels_X = 7;

  fNofLayers = nPixels_X*nPixels_Z;
  G4double pixel_XZ = 1.2*mm;
  G4double pixelHeight= 12*mm;

  G4double pixelPos_X;
  G4double pixelPos_Y = 0.*mm;     // y is vertial. We do not translate pixels vertially so we center on 0
  G4double pixelPos_Z;


  //Inner Reflector Material Dimensions

  G4double InnerReflectorThickness = 0.1*mm;
  G4double InnerReflectorHeight = pixelHeight;


  //Outside reflector dimensions (seperated into Front/Back, Left/Right, and Bottom parts)

  G4double OuterReflectorThickness = 0.5*mm; // Bottom is same as sides
  G4double OuterReflectorHeight_Sides = pixelHeight;


  // Calculate total scintillator dimensions
  G4double TotalSize_X = (nPixels_X * pixel_XZ) + (nPixels_X - 1.)*InnerReflectorThickness + (2.*OuterReflectorThickness);
  G4double TotalSize_Y = pixelHeight + OuterReflectorThickness;
  G4double TotalSize_Z = (nPixels_Z * pixel_XZ) + (nPixels_Z - 1.)*InnerReflectorThickness + (2.*OuterReflectorThickness);


  // We let the front and back reflector be the full length and LR smaller to fit the pieces together
  G4double FBOuterReflectorLength = TotalSize_X;
  G4double LROuterReflectorLength = TotalSize_Z - 2*OuterReflectorThickness;  // to avoid overlap


  G4double BottomReflector_X = TotalSize_X;
  G4double BottomReflector_Z = TotalSize_Z;


  G4double ReflectorPos_X;
  G4double ReflectorPos_Y;
  G4double ReflectorPos_Z;


  
  //World Size
  G4double world_X = TotalSize_X*1.2;
  G4double world_Y = TotalSize_Y*1.2;
  G4double world_Z = TotalSize_Z*1.2;

  //Set the materials

  auto worldMaterial = G4Material::GetMaterial("Air");
  auto scintMaterial = G4Material::GetMaterial("LYSO");
  auto relfectorMaterial = G4Material::GetMaterial("BaSO4");


  //
  // World
  //

  G4Box* worldS
    = new G4Box("World",world_X/2,world_Y/2,world_Z/2);

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
                            pixel_XZ/2,
                            pixelHeight/2,
                            pixel_XZ/2);

auto pixelLV = new G4LogicalVolume(pixelS,
                                    scintMaterial,
                                    "PixelLV");

//Layer a 60x50 grid of LYSO Pixels
copyNumber = 0;

for(G4int i=1;i <= nPixels_X;i++) {

  pixelPos_X = -1.*TotalSize_X/2 + OuterReflectorThickness + pixel_XZ/2 + (pixel_XZ+InnerReflectorThickness)*(i-1);

  for(G4int n=1;n <= nPixels_Z ;n++){

    copyNumber += 1;

    pixelPos_Z = -1.*TotalSize_Z/2 + OuterReflectorThickness+ pixel_XZ/2 + (pixel_XZ+InnerReflectorThickness)*(n-1);
  
    new G4PVPlacement(0,
                      G4ThreeVector(pixelPos_X,pixelPos_Y,pixelPos_Z),
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
ReflectorPos_Y = 0.0*mm;

G4double InnerReflectorNormX_Len = TotalSize_Z - OuterReflectorThickness*2; //The normal X reflectors are the full length

G4Box* InnerReflectorNormX_S = new G4Box("ReflectorInside_NormX",
                                    InnerReflectorThickness/2,
                                    InnerReflectorHeight/2,
                                    InnerReflectorNormX_Len/2);

auto InnerReflectorNormX_LV = new G4LogicalVolume(InnerReflectorNormX_S,
                                              relfectorMaterial,
                                              "ReflectorLV");


G4Box* InnerReflectorNormZ_S = new G4Box("ReflectorInside_NormZ",
                                    pixel_XZ/2,
                                    InnerReflectorHeight/2,
                                    InnerReflectorThickness/2);

auto InnerReflectorNormZ_LV = new G4LogicalVolume(InnerReflectorNormZ_S,
                                              relfectorMaterial,
                                              "ReflectorLV");

// Inside Reflectors normal to x
// These are full length

copyNumber = 0;

ReflectorPos_Z = 0; 

for(G4int i=1; i < nPixels_X; i++){

  ReflectorPos_X = -1.*TotalSize_X/2 + OuterReflectorThickness + pixel_XZ + InnerReflectorThickness/2 + (pixel_XZ+InnerReflectorThickness)*(i-1);

  copyNumber += 1;

  new G4PVPlacement(0,
                    G4ThreeVector(ReflectorPos_X,ReflectorPos_Y,ReflectorPos_Z),
                    InnerReflectorNormX_LV,
                    "ReflectorInside",
                    worldLV,
                    false,
                    copyNumber,
                    fCheckOverlaps);

    }

// Inside Reflectors normal to z
copyNumber = 0;

  for(G4int i=1; i <= nPixels_X ;i++){

    ReflectorPos_X = -1.*TotalSize_X/2 + OuterReflectorThickness + pixel_XZ/2 + (pixel_XZ+InnerReflectorThickness)*(i-1);

    for(G4int n=1; n < nPixels_Z ;n++){

      copyNumber += 1;

      ReflectorPos_Z = -1.*TotalSize_Z/2 + OuterReflectorThickness + pixel_XZ + InnerReflectorThickness/2 + (pixel_XZ+InnerReflectorThickness)*(n-1);

      new G4PVPlacement(0,
                        G4ThreeVector(ReflectorPos_X,ReflectorPos_Y,ReflectorPos_Z),
                        InnerReflectorNormZ_LV,
                        "ReflectorInside",
                        worldLV,
                        false,
                        -1*copyNumber,
                        fCheckOverlaps);
    }
}



//
// Oustide Reflectors
//


// Outside Normal to x

G4Box* reflectorOutside1S = new G4Box("ReflectorOutisde1",
                                       OuterReflectorThickness/2,
                                       pixelHeight/2,
                                       LROuterReflectorLength/2);

auto reflectorOutside1LV = new G4LogicalVolume(reflectorOutside1S,
                                              relfectorMaterial,
                                              "ReflectorOutside1LV");

ReflectorPos_Z = 0;
ReflectorPos_Y = 0;

for(G4int i=0;i<2;i++){

  copyNumber = i;
  
  ReflectorPos_X = (TotalSize_X/2 - OuterReflectorThickness/2) - (TotalSize_X - OuterReflectorThickness)*i;

  new G4PVPlacement(0,
                    G4ThreeVector(ReflectorPos_X,ReflectorPos_Y,ReflectorPos_Z),
                    reflectorOutside1LV,
                    "ReflectorOutside",
                    worldLV,
                    false,
                    copyNumber,
                    fCheckOverlaps);
}


//-------------------------- Normal to z

G4Box* reflectorOutside2S = new G4Box("ReflectorOutside2",
                                      FBOuterReflectorLength/2,
                                      pixelHeight/2,
                                      OuterReflectorThickness/2);

auto reflectorOutside2LV = new G4LogicalVolume(reflectorOutside2S,
                                              relfectorMaterial,
                                              "ReflectorOutisde2LV");
ReflectorPos_X = 0;
ReflectorPos_Y = 0;

for(G4int i=0;i<2;i++){

  copyNumber = i*-1;

  ReflectorPos_Z = (TotalSize_Z/2 - OuterReflectorThickness/2) - (TotalSize_Z - OuterReflectorThickness)*i;
  new G4PVPlacement(0,
                    G4ThreeVector(ReflectorPos_X,ReflectorPos_Y,ReflectorPos_Z),
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
                                     TotalSize_X/2,
                                     OuterReflectorThickness/2,
                                     TotalSize_Z/2);

auto reflectorBottomLV = new G4LogicalVolume(reflectorBottomS,
                                             relfectorMaterial,
                                             "ReflectorBottomLV");
ReflectorPos_X = 0;
ReflectorPos_Z = 0;
ReflectorPos_Y = -1*(pixelHeight/2 + OuterReflectorThickness/2);


new G4PVPlacement(0,
                  G4ThreeVector(ReflectorPos_X,ReflectorPos_Y,ReflectorPos_Z),
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





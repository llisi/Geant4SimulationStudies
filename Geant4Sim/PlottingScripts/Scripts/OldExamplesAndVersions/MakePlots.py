from ROOT import *
import math

Energy = raw_input("What energy would you like to get? ")

filePath="/Users/Luc/Documents/Research/ScintillatorStudies/geant4sim/LYSORootFiles/%sMeVAverageEnergeticPhotons.root" %Energy

rFile = TFile(filePath)

# Get Trees

totals = rFile.Get('Totals')
PixelHits = rFile.Get('PixelHits')
PrimaryPartInfo = rFile.Get('PrimaryPartInfo')


# How many events in file (1 event = 1 incedent photon)

nEvents = totals.GetEntries()


# Initialize Histograms!

H_EnergyPercent = TH1F("Eabs","%s MeV Average; Percent of Total Energy; Normalized Number of Photons " %Energy, 55, 0., 110)

H_xEnergyDist1D = TH1F("x_Edep","%sMeV Average #gamma; Displacement from Incidence [mm]; Energy Deposited [MeV] / 1.2mm " %Energy, 60,0.,78.)
H_yEnergyDist1D = TH1F("y_Edep","%sMeV Average #gamma; Displacement from Incidence [mm]; Energy Deposited [MeV] / 1.2mm " %Energy, 50, -33.15, 31.85)


H_PixelEnergy = TH2F("PixelEnergy", "%s MeV Average; Displacement Parallel to Incidence [mm]; Displacement Normal to Incidence [mm]" % Energy, 60 ,0.,78.,50, -33.15, 31.85)

H_PrimaryEnergy = TH1F("PrimEKin", "%s MeV Average; Energy of Incident Photons [MeV]; Number of Photons / 500 KeV" %Energy, 200,0,100)

print "There are", nEvents, "events in this file."

# Initialize some variables
EnergyPercent = []
nGoodEvents = 0

for i in range(nEvents):

	if i%1000 == 0:
		print "Processing Event info:",i, "/", nEvents

	totals.GetEntry(i)
	PrimaryPartInfo.GetEntry(i)

	H_PrimaryEnergy.Fill(PrimaryPartInfo.GetLeaf('PrimaryParticleEkin').GetValue())

	if totals.GetLeaf("Eabs").GetValue() != 0:

		nGoodEvents = nGoodEvents + 1
		EnergyPercent.append(100. * totals.GetLeaf("Eabs").GetValue()/PrimaryPartInfo.GetLeaf('PrimaryParticleEkin').GetValue())
		H_EnergyPercent.Fill(100. * totals.GetLeaf("Eabs").GetValue()/PrimaryPartInfo.GetLeaf('PrimaryParticleEkin').GetValue())
		if (100. * totals.GetLeaf("Eabs").GetValue()/PrimaryPartInfo.GetLeaf('PrimaryParticleEkin').GetValue()) > 100.1:
			print "SOMETHING WRONG"
			print totals.GetLeaf("Eabs").GetValue()
			print PrimaryPartInfo.GetLeaf('PrimaryParticleEkin').GetValue()
			print 100. * totals.GetLeaf("Eabs").GetValue()/PrimaryPartInfo.GetLeaf('PrimaryParticleEkin').GetValue()



for n in range(PixelHits.GetEntries()):

	if n%10000 == 0:
		print "Processing Pixel Hit: ",n, "/", PixelHits.GetEntries()

	PixelHits.GetEntry(n)
	PixelEnergy = PixelHits.GetLeaf('Edep').GetValue()
	Pixel_x = PixelHits.GetLeaf('xPos').GetValue()
	Pixel_y = PixelHits.GetLeaf('zPos').GetValue()

	H_xEnergyDist1D.Fill(Pixel_x + 39., PixelEnergy/nGoodEvents)
	H_yEnergyDist1D.Fill(Pixel_y , PixelEnergy/nGoodEvents)
	H_PixelEnergy.Fill(Pixel_x + 39.,Pixel_y,PixelEnergy/nGoodEvents)

print H_xEnergyDist1D.Integral()

# Draw and save!

H_EnergyPercent.Sumw2(kTRUE)
EPercIntegral = H_EnergyPercent.Integral()
print EPercIntegral
H_EnergyPercent.Scale(1/EPercIntegral)

#H_xEnergyDist.Sumw2(kTRUE)
#xEDepIntegral = H_xEnergyDist.Integral()
#print xEDepIntegral
#H_xEnergyDist.Scale(1/xEDepIntegral)
#H_xEnergyDist.Draw('E0')
H_EnergyPercent.Draw('E0')
raw_input('Press anything to continue...')
H_xEnergyDist1D.Draw('hist')
raw_input('Press anything to continue...')
H_yEnergyDist1D.Draw('hist')
raw_input('Press anything to continue...')
H_PixelEnergy.Draw('colz')
raw_input('Press anything to continue...')
H_PrimaryEnergy.Draw()
raw_input('Press anything to continue...')

savebool = raw_input('Do you want to save plots? (y/n)')

if savebool == 'y' or savebool == 'Y':
	H_EnergyPercent.SaveAs('TotalEdepPercent%sMeV.root'%Energy)
	H_xEnergyDist1D.SaveAs('x_EdepDist%sMeV.root' %Energy)
	H_yEnergyDist1D.SaveAs('y_EdepDist%sMeV.root' %Energy)
	H_PrimaryEnergy.SaveAs('PrimaryEnergyDist%sMeV.root' %Energy)
	H_PixelEnergy.SaveAs('2DPixelEnergDist%sMeV.root' %Energy)



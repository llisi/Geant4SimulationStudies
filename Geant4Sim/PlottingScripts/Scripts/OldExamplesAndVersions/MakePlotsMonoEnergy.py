from ROOT import *
import math

Energy = raw_input("What energy would you like to get? ")

filePath="/Users/Luc/Documents/Research/ScintillatorStudies/geant4sim/LYSORootFiles/%sMeVMonoEnergeticPhotons.root" %Energy

rFile = TFile(filePath)

# Get Trees

totals = rFile.Get('Totals')
PixelHits = rFile.Get('PixelHits')
PrimaryPartInfo = rFile.Get('PrimaryPartInfo')


# How many events in file (1 event = 1 incedent photon)

nEvents = totals.GetEntries()


# Initialize Histograms!

H_EnergyPercent = TH1F("Eabs","Percent of Total Energy Deposited in LYSO at %s MeV; Percent of Total Energy; Normalized Number of Photons " %Energy, 55, 0., 110);
H_xEnergyDist = TH1F("x_Edep","1D Energy Distribution in LYSO at %s MeV; Displacement from Incidence [mm]; Normalized Energy Deposited / Pixel Size" %Energy, 60,0.,78.);

print "There are", nEvents, "events in this file."

# Initialize some variables
EnergyPercent = []

for i in range(nEvents):

	if i%1000 == 0:
		print "Processing Event info:",i, "/", nEvents

	totals.GetEntry(i)
	PrimaryPartInfo.GetEntry(i)

	if totals.GetLeaf("Eabs").GetValue() != 0:
		EnergyPercent.append(100. * totals.GetLeaf("Eabs").GetValue()/PrimaryPartInfo.GetLeaf('PrimaryParticleEkin').GetValue())
		H_EnergyPercent.Fill(100. * totals.GetLeaf("Eabs").GetValue()/PrimaryPartInfo.GetLeaf('PrimaryParticleEkin').GetValue())
		if (100. * totals.GetLeaf("Eabs").GetValue()/PrimaryPartInfo.GetLeaf('PrimaryParticleEkin').GetValue()) > 100.:
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

	H_xEnergyDist.Fill(Pixel_x + 39, PixelEnergy)




# Draw and save!

H_EnergyPercent.Sumw2(kTRUE)
EPercIntegral = H_EnergyPercent.Integral()
print EPercIntegral
H_EnergyPercent.Scale(1/EPercIntegral)
H_EnergyPercent.Draw('E0')
H_EnergyPercent.SaveAs('TotalEdepPercent%sMeV.root'%Energy)

H_xEnergyDist.Sumw2(kTRUE)
xEDepIntegral = H_xEnergyDist.Integral()
print xEDepIntegral
H_xEnergyDist.Scale(1/xEDepIntegral)
H_xEnergyDist.Draw('E0')
H_xEnergyDist.SaveAs('x_EdepDist%sMeV.root' %Energy)

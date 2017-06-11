#!/bin/bash 

echo "~~~~~BEGIN Geant4 Script ~~~~~"
cd /Users/Luc/Documents/Research/ScintillatorStudies/geant4sim/Versions/LYSO2.02/build/

for Eng in 2

do

	./LYSOScint run$((Eng))MeV.mac
	mv MonoEnergeticPhotons.root /Users/Luc/Documents/Research/ScintillatorStudies/geant4sim/LYSORootFiles/$((Eng))MeVAverageEnergeticPhotons.root

done
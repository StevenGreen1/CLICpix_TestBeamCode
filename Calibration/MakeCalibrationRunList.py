#!/usr/bin/python

import sys
import re

textFile = open("CalibrationRunList.txt", "w")
basePath = '/afs/cern.ch/work/s/sgreen/CLICpixTestPulse/Plots/CalibrationFiles/FitParamA_Set%s.txt /afs/cern.ch/work/s/sgreen/CLICpixTestPulse/Plots/CalibrationFiles/FitParamB_Set%s.txt /afs/cern.ch/work/s/sgreen/CLICpixTestPulse/Plots/CalibrationFiles/FitParamC_Set%s.txt /afs/cern.ch/work/s/sgreen/CLICpixTestPulse/Plots/CalibrationFiles/FitParamT_Set%s.txt'

with open('/afs/cern.ch/eng/clic/work/clicpix/macros/runListMay2015ThresholdScan.dat') as f:
    for line in f:
        newLine = ' '.join(line.split())
        regex = re.compile("(.*?) (.*?) SET(.*?) (.*?)")
        q = regex.search(newLine)
        if q is not None:
            setNumber = q.group(3)
            string = '/afs/cern.ch/work/s/sgreen/CLICpixTestPulse/Plots/CalibrationFiles/FitParamA_Set%s.txt /afs/cern.ch/work/s/sgreen/CLICpixTestPulse/Plots/CalibrationFiles/FitParamB_Set%s.txt /afs/cern.ch/work/s/sgreen/CLICpixTestPulse/Plots/CalibrationFiles/FitParamC_Set%s.txt /afs/cern.ch/work/s/sgreen/CLICpixTestPulse/Plots/CalibrationFiles/FitParamT_Set%s.txt' % (setNumber,setNumber,setNumber,setNumber)
            saveLine = q.group(1) + '\t' + string + '\n'
            textFile.write(saveLine)

textFile.close()


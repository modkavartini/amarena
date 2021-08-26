[Variables]
@IncludeVars=#@#Variables.inc
averageSize=3

[MAudio]
Measure=Plugin
Plugin=AudioLevel
Port=Output
FFTSize=2048
FFTOverlap=1024
FFTAttack=80
FFTDecay=150
Bands=6
FreqMin=20
FreqMax=16500
Sensitivity=35
DynamicVariables=1
Disabled=1

[MBar1]
Measure=Plugin
Plugin=AudioLevel
Parent=MAudio
Type=Band
BandIdx=0

[MBar2]
Measure=Plugin
Plugin=AudioLevel
Parent=MAudio
Type=Band
BandIdx=1

[MBar3]
Measure=Plugin
Plugin=AudioLevel
Parent=MAudio
Type=Band
BandIdx=2

[MBar4]
Measure=Plugin
Plugin=AudioLevel
Parent=MAudio
Type=Band
BandIdx=3

[MBar5]
Measure=Plugin
Plugin=AudioLevel
Parent=MAudio
Type=Band
BandIdx=4

[MBar6]
Measure=Plugin
Plugin=AudioLevel
Parent=MAudio
Type=Band
BandIdx=5

[MBar1S]
Measure=Calc
Formula=(MBar1+MBar1+MBar2)/3
AverageSize=#averageSize#
;Disabled=#visSmooth#=1? 0 : 1

[MBar2S]
Measure=Calc
Formula=(MBar1+MBar2+MBar3)/3
AverageSize=#averageSize#
;Disabled=#visSmooth#=1? 0 : 1

[MBar3S]
Measure=Calc
Formula=(MBar2+MBar3+MBar4)/3
AverageSize=#averageSize#
;Disabled=#visSmooth#=1? 0 : 1

[MBar4S]
Measure=Calc
Formula=(MBar3+MBar4+MBar5)/2
AverageSize=#averageSize#
;Disabled=#visSmooth#=1? 0 : 1

[MBar5S]
Measure=Calc
Formula=(MBar4+MBar5+MBar6)/1.5
AverageSize=#averageSize#
;Disabled=#visSmooth#=1? 0 : 1
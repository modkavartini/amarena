[Variables]
@IncludeVars=#@#Variables.inc

appIconScale=40
appsBgWidth=170
appsBgHeight=80
appsBgGap=10

[AppBg1]
Meter=Shape
X=#appsX#
Y=#appsY#
Shape=Rectangle 0,0,#appsBgWidth#,#appsBgHeight#,#bgRadius# | StrokeWidth 0 | Fill Color #bgColorD#
DynamicVariables=1

[AppBg2]
Meter=Shape
MeterStyle=AppBg1
Y=(#appsBgHeight#+#appsBgGap#)r

[app1]
Meter=Image
ImageName=[##CurrentSection#Icon]
ImageTint=#green#
X=(#appsX#+((#appsBgWidth#-#appIconScale#)/2))
Y=(#appsY#+((#appsBgHeight#-#appIconScale#)/2))
W=#appIconScale#
H=#appIconScale#
LeftMouseUpAction=["[##CurrentSection#Path]"][#disableMode# "#CurrentConfig#" "#CurrentFile#"]
DynamicVariables=1

[app2]
Meter=Image
MeterStyle=app1
ImageTint=#indigo#
Y=(#appsBgGap#+#appsBgHeight#)r



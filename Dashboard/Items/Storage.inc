[Variables]
@IncludeVars=#@#Variables.inc
ringWidth=10
ringRadius=50
angleStart=(-90)
sIconScale=30

storageBgScale=170

[StorageBg]
Meter=Shape
X=#StorageX#
Y=#StorageY#
Shape=Rectangle 0,0,#storageBgScale#,#storageBgScale#,#bgRadius# | StrokeWidth 0 | Fill Color #bgColorD#
DynamicVariables=1

[FreeSpace]
Measure=FreeDiskSpace
DynamicVariables=1

[OccupiedSpace]
Measure=FreeDiskSpace
InvertMeasure=1
DynamicVariables=1

[Percentage]
Measure=Calc
Formula=Round((OccupiedSpace/(FreeSpace+OccupiedSpace))*100)/100
DynamicVariables=1

[StorageRoundline]
Meter=Shape
X=(#storageBgScale#/2)r
Y=(#storageBgScale#/2)r
Shape=Ellipse 0,0,(#ringRadius#-(#ringWidth#/2)) | StrokeWidth #ringWidth# | StrokeColor #bgColorS# | Fill Color 0,0,0,1
Shape2=Path Ring | StrokeWidth 0 | Fill Color #violet#
Ring=(#ringRadius#*cos(rad(0+#angleStart#))),(#ringRadius#*sin(rad(0+#angleStart#))) | ArcTo (#ringRadius#*cos(rad(-[Percentage]*360+#angleStart#))),(#ringRadius#*sin(rad(-[Percentage]*360+#angleStart#))),#ringRadius#,#ringRadius#,0,1,([Percentage]>0.5?1:0) | ArcTo ((#ringRadius#-#ringWidth#)*cos(rad(-[Percentage]*360+#angleStart#))),((#ringRadius#-#ringWidth#)*sin(rad(-[Percentage]*360+#angleStart#))),(#ringWidth#/2),(#ringWidth#/2),0,1 | ArcTo ((#ringRadius#-#ringWidth#)*cos(rad(0+#angleStart#))),((#ringRadius#-#ringWidth#)*sin(rad(0+#angleStart#))),(#ringRadius#-#ringWidth#),(#ringRadius#-#ringWidth#),0,0,([Percentage]>0.5?1:0) | ArcTo (#ringRadius#*cos(rad(0+#angleStart#))),(#ringRadius#*sin(rad(0+#angleStart#))),(#ringWidth#/2),(#ringWidth#/2),0,1
DynamicVariables=1

[StorageIcon]
Meter=String
X=r
Y=5r
Text=
StringAlign=CenterCenter
FontColor=#indigo#
FontFace=FiraCode Nerd Font Mono
FontSize=#sIconScale#
AntiAlias=1
DynamicVariables=1
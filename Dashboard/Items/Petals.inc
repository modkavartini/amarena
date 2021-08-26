[Variables]
@IncludeVars=#@#Variables.inc

petalScale=80
petalGap=10

0color=#indigo#
1color=#pink#
2color=#green#
3color=#peach#

[Petal]
Shape=Rectangle 0,0,#petalScale#,#petalScale#,50 | StrokeWidth 0 | Extend Prop
Shape2=Rectangle (#petalScale#/(#petalScale#/40)),(#petalScale#/(#petalScale#/40)),(#petalScale#-40),(#petalScale#-40),4
Shape3=Combine Shape | Union Shape2 | Rotate (#CurrentSection#*90)
MouseOverAction=[!SetOption #CurrentSection# Prop "Fill Color #fgColorD#"][!Update][!Redraw]
MouseLeaveAction=[!SetOption #CurrentSection# Prop "Fill Color [##CurrentSection#color]"][!Update][!Redraw]
Prop=Fill Color [##CurrentSection#color]
DynamicVariables=1

[0]
Meter=Shape
MeterStyle=Petal
X=#petalsX#
Y=#petalsY#
LeftMouseUpAction=["#p1path#"][#disableMode# "#CurrentConfig#" "#CurrentFile#"]

[1]
Meter=Shape
MeterStyle=Petal
X=(#petalScale#+#petalGap#)r
Y=r
LeftMouseUpAction=["#p2path#"][#disableMode# "#CurrentConfig#" "#CurrentFile#"]

[3]
Meter=Shape
MeterStyle=Petal
X=#petalsX#
Y=(#petalScale#+#petalGap#)r
LeftMouseUpAction=["#p3path#"][#disableMode# "#CurrentConfig#" "#CurrentFile#"]

[2]
Meter=Shape
MeterStyle=Petal
X=(#petalScale#+#petalGap#)r
Y=r
LeftMouseUpAction=["#p4path#"][#disableMode# "#CurrentConfig#" "#CurrentFile#"]

[petalNames]
Text=[##CurrentSection#Name]
W=(#petalScale#-10)
StringAlign=CenterCenter
FontColor=#fgColorL#
FontFace=#gsans#
FontSize=14
FontWeight=550
AntiAlias=1
ClipString=1
DynamicVariables=1

[p1]
Meter=String
MeterStyle=petalNames
X=(#petalsX#+(#petalScale#/2))
Y=(#petalsY#+(#petalScale#/2))

[p2]
Meter=String
MeterStyle=petalNames
X=(#petalGap#+#petalScale#)r
Y=r

[p3]
Meter=String
MeterStyle=petalNames
X=(#petalsX#+(#petalScale#/2))
Y=(#petalGap#+#petalScale#)r

[p4]
Meter=String
MeterStyle=petalNames
X=(#petalGap#+#petalScale#)r
Y=r


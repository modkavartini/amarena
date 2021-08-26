[Variables]
@IncludeVars=#@#Variables.inc

fBgWidth=230
fBgHeight=340

folderGap=40

folder1Col=#pink#
folder2Col=#green#
folder3Col=#cyan#
folder4Col=#blue#
folder5Col=#violet#
folder6Col=#peach#

[FolderBg]
Meter=Shape
X=#foldersX#
Y=#foldersY#
Shape=Rectangle 0,0,#fBgWidth#,#fBgHeight#,#bgRadius# | StrokeWidth 0 | Fill Color #bgColorD#
DynamicVariables=1

[Folders]
;Meter=String
Text=[##CurrentSection#]
X=(#foldersX#+(#fBgWidth#/2))
StringAlign=Center
FontColor=[##CurrentSection#Col]
FontFace=#gsans#
FontSize=17
FontWeight=550
AntiAlias=1
DynamicVariables=1
LeftMouseUpAction=["[##CurrentSection#Path]"][#disableMode# "#CurrentConfig#" "#CurrentFile#"]
MouseOverAction=[!SetOption #CurrentSection# FontColor #fgColorD#][!Update][!Redraw]
MouseLeaveAction=[!SetOption #CurrentSection# FontColor [##CurrentSection#Col]][!Update][!Redraw]

[folder1]
Meter=String
MeterStyle=Folders
Y=(#foldersY#+50)

[folder2]
Meter=String
MeterStyle=Folders
Y=#folderGap#r

[folder3]
Meter=String
MeterStyle=Folders
Y=#folderGap#r

[folder4]
Meter=String
MeterStyle=Folders
Y=#folderGap#r

[folder5]
Meter=String
MeterStyle=Folders
Y=#folderGap#r

[folder6]
Meter=String
MeterStyle=Folders
Y=#folderGap#r
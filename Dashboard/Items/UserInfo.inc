[Variables]
@IncludeVars=#@#Variables.inc

uWidth=315
uHeight=355
avScale=160

pMenuGap=30
rebootColor=#indigo#
shutdownColor=#pink#
sleepColor=#green#
logoffColor=#violet#
hoverFX=0

[DragAndDropAv]
Measure=Plugin
Plugin=Drag&Drop
Action=Path
Bounds=#userinfoX#,#userinfoY#,#uWidth#,#uHeight#
OnDropAction=[!WriteKeyValue Variables "avatarPath" "$File$" "#@#Variables.inc"][!Refresh]
DynamicVariables=1

[UserBackground]
Meter=Shape
Shape=Rectangle #userinfoX#,#userinfoY#,#uWidth#,#uHeight#,#bgRadius# | StrokeWidth 0 | Fill Color #bgColorD#,#bgAlpha#
DynamicVariables=1

[AvContain]
Meter=Shape
X=(((#uWidth#-#avScale#)/2)+#userinfoX#)
Y=(((#uWidth#-#avScale#)/2)+#userinfoY#-10)
Shape=Rectangle 0,0,#avScale#,#avScale#,40 | StrokeWidth 0 | Extend Fill
Shape2=Rectangle (#avScale#/2),(#avScale#/2),(#avScale#/2),(#avScale#/2),5
Shape3=Combine Shape | Union Shape2 |
Fill=Fill Color 255,255,255
DynamicVariables=1

[DiscordAvatar]
Measure=Plugin
Plugin=WebParser
URL=file://#@#Images\DiscordAv.txt
RegExp=(.*)
StringIndex=1
Download=1
DownloadFile=dAvatar.png

[AvImg]
Meter=Image
ImageName=#avatar#
X=r
Y=r
W=#avScale#
H=#avScale#
PreserveAspectRatio=2
Container=AvContain
DynamicVariables=1

[UserNameDisplay]
Meter=String
Text=#userName#
X=(#avScale#/2)r
Y=(#avScale#+22)r
W=(#uWidth#-20)
InlineSetting=CharacterSpacing | 0.2 | 0.2
StringAlign=Center
StringCase=Upper
FontColor=#fgColorL#
FontFace=#sfdisp#
FontSize=16
FontWeight=750
AntiAlias=1
ClipString=1
DynamicVariables=1
;LeftMouseUpAction=[!CommandMeasure "UserNameInput" "ExecuteBatch 1"]

;[UserNameInput]
;Measure=Plugin
;Plugin=InputText
;X=[UserNameDisplay:X]
;Y=[UserNameDisplay:Y]
;W=(#uWidth#-20)
;StringAlign=Center
;SolidColor=#bgColorD#
;FontFace=#sfdisp#
;FontSize=16
;FontColor=#fgColorL#
;AntiAlias=1
;ClipString=1
;DefaultValue=#userName#
;Command1=[!WriteKeyValue Variables "userName" "$UserInput$" "#@#Variables.inc"][!Refresh]
;DynamicVariables=1

[SetupName]
Meter=String
MeterStyle=UserNameDisplay
Text=@#setupName#
X=r
Y=32r
InlineSetting=None
StringCase=None
FontFace=#iosevka#
FontColor=#fgColorD#
FontSize=14
FontWeight=500

[powerMenuToggle]
Measure=Calc
Formula=#powerMenu#
IfCondition=#CurrentSection#=1
IfTrueAction=[!ShowMeter HoverMenuBg][!Update][!Redraw]
IfFalseAction=[!HideMeter HoverMenuBg][!Update][!Redraw]
DynamicVariables=1

[HoverMenuBg]
Meter=Shape
MeterStyle=AvContain
Fill=Fill Color 0,0,0,#hoverFX#
MouseOverAction=[!CommandMeasure HoverFX "Execute 1"][!Update][!Redraw]
MouseLeaveAction=[!CommandMeasure HoverFX "Execute 2"][!Update][!Redraw]
DynamicVariables=1

[PowerMenu]
FontColor=[##CurrentSection#Color],(#hoverFX#*1.45)
FontFace=#gsans#
FontSize=14
;FontWeight=450
StringAlign=CenterCenter
Text="#CurrentSection#"
X=((#avScale#/2)+[AvContain:X])
Group=PowerMenu
Hidden=1
AntiAlias=1
DynamicVariables=1
MouseOverAction=[!SetOption #CurrentSection# FontColor #fgColorL#][!UpdateMeter #CurrentSection#][!Redraw]
MouseLeaveAction=[!SetOption #CurrentSection# FontColor ""][!UpdateMeter #CurrentSection#][!Redraw]
LeftMouseUpAction=[#disableMode#][!Delay 100][!ActivateConfig "#RootConfig#\Dashboard\SubSkins" "PowerMenu.ini"][!SetVariable currentMode "#CurrentSection#" "#RootConfig#\Dashboard\SubSkins"][!WriteKeyValue Variables currentMode "#CurrentSection#" "#CurrentPath#SubSkins\PowerMenu.ini"][!Update][!Redraw]

[reboot]
Meter=String
MeterStyle=PowerMenu
Y=((#avScale#/4)+[AvContain:Y]-5)

[shutdown]
Meter=String
MeterStyle=PowerMenu
Y=#pMenuGap#r

[sleep]
Meter=String
MeterStyle=PowerMenu
Y=#pMenuGap#r

[logoff]
Meter=String
MeterStyle=PowerMenu
Y=#pMenuGap#r

[HoverFX]
Measure=Plugin
Plugin=ActionTimer
ActionList1=Repeat FadeIn, 2, 7
FadeIn=[!ShowMeterGroup PowerMenu][!SetVariable hoverFX "(Clamp(#hoverFX#+25,0,175))"][!Update][!Redraw]
ActionList2=Repeat FadeOut, 2, 7
FadeOut=[!SetVariable hoverFX "(Clamp(#hoverFX#-25,0,175))"][!HideMeterGroup PowerMenu][!Update][!Redraw]
Disabled=1
DynamicVariables=1

[discAvChoose]
Measure=Calc
Formula=#discAv#=1? 1 : 0
IfCondition=#CurrentSection#=1
IfTrueAction=[!SetVariable avatar "#avatarLink#"][!WriteKeyValue Variables avatar "#avatarLink#" "#@#Variables.inc"][!Update][!Redraw]
IfFalseAction=[!SetVariable avatar "#avatarPath#"][!WriteKeyValue Variables avatar "#avatarPath#" "#@#Variables.inc"][!Update][!Redraw]
DynamicVariables=1
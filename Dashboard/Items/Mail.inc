[Variables]
@IncludeVars=#@#Variables.inc

mBgWidth=230
mBgHeight=180
gTextPadding=10
gradColor=#pink#
;#green#,230
;#peach#
gradMove=#pink#
;#cyan#
;#indigo#

;[\xF18C] tick read mails icon
;[\xF18A] dot unread mails icon

[MailBg]
Meter=Shape
X=#mailX#
Y=#mailY#
Shape=Rectangle 0,0,#mBgWidth#,#mBgHeight#,#bgRadius# | StrokeWidth 0 | Fill Color #bgColorD#
DynamicVariables=1

[Gmail]
Meter=String
X=(#mBgWidth#/2)r
Y=50r
StringAlign=CenterCenter
Text="#CurrentSection#"
FontColor=#indigo#
FontFace=#gsans#
FontSize=23
FontWeight=550
AntiAlias=1
DynamicVariables=1

[Grad]
Measure=Calc
Formula=#CurrentSection#>=1.5? -0.5 : (#CurrentSection#+0.045)
DynamicVariables=1

Disabled=1

[UnreadDisplay]
Meter=String
X=r
Y=60r
;35r
W=(#mBgWidth#-10)
StringAlign=CenterCenter
Text=#userName#, you have #unreadCount# unread mails.
FontColor=#fgColorL#
FontFace=#gsans#
FontSize=14
;FontWeight=550
;InlineSetting=GradientColor | 180 | #gradColor# ; ([Grad]-0.75) | #gradMove# ; [Grad] | #gradColor# ; ([Grad]+0.75) |
;InlinePattern=#unreadCount#
ClipString=2
AntiAlias=1
DynamicVariables=1

[mail1]
Meter=String
X=(#mailX#+0)
;((Neg([MailScroll]))+#mailX#)
Y=35r
W=(#mBgWidth#-#gTextPadding#-2)
StringAlign=LeftCenter
;StringStyle=Italic
Text=• #title1# - #author1#
SolidColor=#green#,70
Padding=(#gTextPadding#-3),5,5,5
FontColor=#fgColorL#
FontFace=#gsans#
FontSize=12
AntiAlias=1
ClipString=1
DynamicVariables=1
LeftMouseUpAction=["#link1#"]

Hidden=1

[mail2]
Meter=String
MeterStyle=mail1
Y=35r
Text=• #title2# - #author2#
SolidColor=#pink#,70
LeftMouseUpAction=["#link2#"]

Hidden=1

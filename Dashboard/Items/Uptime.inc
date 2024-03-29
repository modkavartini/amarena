[Variables]
@IncludeVars=#@#Variables.inc

upBgWidth=340
upBgHeight=90

[UptimeBg]
Meter=Shape
X=#UptimeX#
Y=#UptimeY#
Shape=Rectangle 0,0,#upBgWidth#,#upBgHeight#,#bgRadius# | StrokeWidth 0 | Fill Color #bgColorD#
DynamicVariables=1

[UpIcon]
Meter=String
X=35r
Y=(#upBgHeight#/2)r
Text=
StringAlign=LeftCenter
FontColor=#peach#
FontFace=Material Icons
FontSize=20
AntiAlias=1
DynamicVariables=1

[UptimeText]
Meter=String
X=((#upBgWidth#/2)+#UptimeX#-95)
Y=r
Text=up[UptimeReal]
StringAlign=LeftCenter
FontColor=#fgColorL#
FontFace=#gsans#
FontSize=13
;FontWeight=500
AntiAlias=1
DynamicVariables=1

[CurrentTime]
Measure=Time
OnChangeAction=[!UpdateMeter UptimeText][!UpdateMeasureGroup Uptime][!Redraw]
DynamicVariables=1

[UserLoginTime]
Measure=Plugin
Plugin=SysInfo
SysInfoType=USER_LOGONTIME
DynamicVariables=1

[UptimeReal]
Measure=UpTime
SecondsValue=([CurrentTime:] - [UserLoginTime:])
Format="#day##hour##minute#"
DynamicVariables=1

[UptimeD]
Measure=Uptime
SecondsValue=([CurrentTime:] - [UserLoginTime:])
Format="%4!i!"
Group=Uptime
DynamicVariables=1

[UptimeDNum]
Measure=Calc
Formula=[UptimeD]
IfCondition=#CurrentSection#=0
IfTrueAction=[!SetVariable day ""][!SetVariable hp ","][!Update][!Redraw]
IfCondition2=#CurrentSection#=1
IfTrueAction2=[!SetVariable day " [#CurrentSection#] day,"][!SetVariable hp ","][!Update][!Redraw]
IfAboveValue=1
IfAboveAction=[!SetVariable day " [#CurrentSection#] days,"][!SetVariable hp ","][!Update][!Redraw]
Group=Uptime
DynamicVariables=1

[UptimeH]
Measure=Uptime
SecondsValue=([CurrentTime:] - [UserLoginTime:])
Format="%3!i!"
Group=Uptime
DynamicVariables=1

[UptimeHNum]
Measure=Calc
Formula=[UptimeH]-([UptimeDNum]*24)
IfCondition=#CurrentSection#=0
IfTrueAction=[!SetVariable hour ""][!Update][!Redraw]
IfCondition2=#CurrentSection#=1
IfTrueAction2=[!SetVariable hour " [#CurrentSection#] hour#hp#"][!Update][!Redraw]
IfAboveValue=1
IfAboveAction=[!SetVariable hour " [#CurrentSection#] hours#hp#"][!Update][!Redraw]
Group=Uptime
DynamicVariables=1

[UptimeM]
Measure=Uptime
SecondsValue=([CurrentTime:] - [UserLoginTime:])
Format="%2!i!"
Group=Uptime
DynamicVariables=1

[UptimeMNum]
Measure=Calc
Formula=[UptimeM]
IfCondition=UptimeDNum<>0
IfTrueAction=[!Update][!Redraw]
IfCondition2=#CurrentSection#=1
IfTrueAction2=[!SetVariable minute " [#CurrentSection#] minute."][!Update][!Redraw]
IfAboveValue=1
IfAboveAction=[!SetVariable minute " [#CurrentSection#] minutes."][!Update][!Redraw]
Group=Uptime
DynamicVariables=1

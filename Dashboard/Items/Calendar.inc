[Variables]
@IncludeVars=#@#Variables.inc

CBgWidth=340
CBgHeight=430
colGap=38

dayColor=#violet#
;By default

1=#pink#
2=#indigo#
3=#violet#

s=#CRLF##CRLF#

[CalendarBg]
Meter=Shape
X=#calendarX#
Y=#calendarY#
Shape=Rectangle 0,0,#CBgWidth#,#CBgHeight#,#bgRadius# | StrokeWidth 0 | Fill Color #bgColorD#
DynamicVariables=1

[MMonth]
Measure=Time
Format=%B
IfMatch=January|March|May|July|August|October|December
IfMatchAction=[!SetVariable 31 31][!SetVariable 30 30][!SetVariable 29 29][!Update][!Redraw]
IfMatch2=April|June|September|November
IfMatchAction2=[!SetVariable 31 ""][!SetVariable 30 30][!SetVariable 29 29][!Update][!Redraw]
IfMatch3=February
IfMatchAction3=[!EnableMeasure LeapYearStuff][!Update][!Redraw]
DynamicVariables=1

[MYear]
Measure=Time
Format=%Y

[MonthYear]
Meter=String
MeasureName=MMonth
MeasureName2=MYear
X=(#CBgWidth#/2)r
Y=52r
Text=%1 %2
StringAlign=Center
FontColor=#green#
;#indigo#
FontFace=#gsans#
FontSize=20
FontWeight=550 
AntiAlias=1
DynamicVariables=1

[WeekNameCol]
Meter=String
X=126r
Y=58r
Text=Mo     Tu     We     Th     Fr     Sa     Su
InlineSetting=CharacterSpacing | 0.2 | 0
InlinePattern=Mo(.*)Tu(.*)We(.*)Th(.*)Fr(.*)Sa(.*)Su
StringAlign=Right
FontColor=#fgColorL#
FontFace=#gsans#
FontSize=12
FontWeight=550
AntiAlias=1
DynamicVariables=1

[MDate]
Measure=Time
Format=%d
IfCondition=#CurrentSection#%10=2
IfTrueAction=[!SetVariable dayColor #green#][!Update][!Redraw]
IfCondition2=#CurrentSection#%10=3
IfTrueAction2=[!SetVariable dayColor #pink#][!Update][!Redraw]
DynamicVariables=1

[grid1]
Meter=String
X=(67+#calendarX#)
Y=(45+[WeekNameCol:Y])
Text=[##CurrentSection#]
InlineSetting=Color|#dayColor#
InlinePattern=[MDate]
InlineSetting2=Face|Blank
InlinePattern2=(0)[1-9]
StringAlign=Right
FontColor=#fgColorL#
FontFace=#gsans#
FontSize=12
FontWeight=550
AntiAlias=1
DynamicVariables=1

[grid2]
Meter=String
MeterStyle=grid1
X=#colGap#r

[grid3]
Meter=String
MeterStyle=grid1
X=#colGap#r

[grid4]
Meter=String
MeterStyle=grid1
X=#colGap#r

[grid5]
Meter=String
MeterStyle=grid1
X=#colGap#r

[grid6]
Meter=String
MeterStyle=grid1
X=#colGap#r

[grid7]
Meter=String
MeterStyle=grid1
X=#colGap#r

[MonthNum]
Measure=Time
Format=%#m

[LeapYearStuff]
Measure=Calc
Formula=MYear%4=0? 1 : 0
IfCondition=#CurrentSection#=1
IfTrueAction=[!SetVariable 31 ""][!SetVariable 30 ""][!SetVariable 29 "29"][!Update][!Redraw]
IfFalseAction=[!SetVariable 31 ""][!SetVariable 30 ""][!SetVariable 29 ""][!Update][!Redraw]
DynamicVariables=1
Disabled=1

[MonthNumKey]
Measure=Time
Format=%b
IfMatch=Oct
IfMatchAction=[!SetVariable keyValM 1][!Update][!Redraw]
IfMatch2=Mar|Nov
IfMatchAction2=[!SetVariable keyValM 4][!Update][!Redraw]
IfMatch3=Apr|Jul
IfMatchAction3=[!SetVariable keyValM 0][!Update][!Redraw]
IfMatch4=May
IfMatchAction4=[!SetVariable keyValM 2][!Update][!Redraw]
IfMatch5=Jun
IfMatchAction5=[!SetVariable keyValM 5][!Update][!Redraw]
IfMatch6=Aug
IfMatchAction6=[!SetVariable keyValM 3][!Update][!Redraw]
IfMatch7=Sep|Dec
IfMatchAction7=[!SetVariable keyValM 6][!Update][!Redraw]
DynamicVariables=1

[MonthNumKeyLeapYear]
Measure=Calc
Formula=MYear%4=0? 1 : 0
IfCondition2=(#CurrentSection#=1) && (MMonth=1)
IfTrueAction2=[!SetVariable keyValM 6][!Update][!Redraw]
IfFalseAction2=[!SetVariable keyValM 1][!Update][!Redraw]
IfCondition3=(#CurrentSection#=1) && (MMonth=2)
IfTrueAction3=[!SetVariable keyValM 2][!Update][!Redraw]
IfFalseAction3=[!SetVariable keyValM 4][!Update][!Redraw]
DynamicVariables=1

[YearSuffix]
Measure=Time
Format=%y

[KeyValue]
Measure=Calc
Formula=Round((((YearSuffix/4)+1+#keyValM#+6)+YearSuffix)%7)
IfCondition=#CurrentSection#=2
IfTrueAction=[!SetVariable grid1 "01#s#08#s#15#s#22#s##29#"][!SetVariable grid2 "02#s#09#s#16#s#23#s##30#"][!SetVariable grid3 "03#s#10#s#17#s#24#s##31#"][!SetVariable grid4 "04#s#11#s#18#s#25"][!SetVariable grid5 "05#s#12#s#19#s#26"][!SetVariable grid6 "06#s#13#s#20#s#27"][!SetVariable grid7 "07#s#14#s#21#s#28"][!Update][!Redraw]
IfCondition2=#CurrentSection#=3
IfTrueAction2=[!SetVariable grid1 "#s#07#s#14#s#21#s#28"][!SetVariable grid2 "01#s#08#s#15#s#22#s##29#"][!SetVariable grid3 "02#s#09#s#16#s#23#s##30#"][!SetVariable grid4 "03#s#10#s#17#s#24#s##31#"][!SetVariable grid5 "04#s#11#s#18#s#25"][!SetVariable grid6 "05#s#12#s#19#s#26"][!SetVariable grid7 "06#s#13#s#20#s#27"][!Update][!Redraw]
IfCondition3=#CurrentSection#=4
IfTrueAction3=[!SetVariable grid1 "#s#06#s#13#s#20#s#27"][!SetVariable grid2 "#s#07#s#14#s#21#s#28"][!SetVariable grid3 "01#s#08#s#15#s#22#s##29#"][!SetVariable grid4 "02#s#09#s#16#s#23#s##30#"][!SetVariable grid5 "03#s#10#s#17#s#24#s##31#"][!SetVariable grid6 "04#s#11#s#18#s#25"][!SetVariable grid7 "05#s#12#s#19#s#26"][!Update][!Redraw]
IfCondition4=#CurrentSection#=5
IfTrueAction4=[!SetVariable grid1 "#s#05#s#12#s#19#s#26"][!SetVariable grid2 "#s#06#s#13#s#20#s#27"][!SetVariable grid3 "#s#07#s#14#s#21#s#28"][!SetVariable grid4 "01#s#08#s#15#s#22#s##29#"][!SetVariable grid5 "02#s#09#s#16#s#23#s##30#"][!SetVariable grid6 "03#s#10#s#17#s#24#s##31#"][!SetVariable grid7 "04#s#11#s#18#s#25"][!Update][!Redraw]
IfCondition5=#CurrentSection#=6
IfTrueAction5=[!SetVariable grid1 "#s#04#s#11#s#18#s#25"][!SetVariable grid2 "#s#05#s#12#s#19#s#26"][!SetVariable grid3 "#s#06#s#13#s#20#s#27"][!SetVariable grid4 "#s#07#s#14#s#21#s#28"][!SetVariable grid5 "01#s#08#s#15#s#22#s##29#"][!SetVariable grid6 "02#s#09#s#16#s#23#s##30#"][!SetVariable grid7 "03#s#10#s#17#s#24#s##31#"][!Update][!Redraw]
IfCondition6=#CurrentSection#=7
IfTrueAction6=[!SetVariable grid1 "#s#03#s#10#s#17#s#24#s##31#"][!SetVariable grid2 "#s#04#s#11#s#18#s#25"][!SetVariable grid3 "#s#05#s#12#s#19#s#26"][!SetVariable grid4 "#s#06#s#13#s#20#s#27"][!SetVariable grid5 "#s#07#s#14#s#21#s#28"][!SetVariable grid6 "01#s#08#s#15#s#22#s##29#"][!SetVariable grid7 "02#s#09#s#16#s#23#s##30#"][!Update][!Redraw]
IfCondition7=#CurrentSection#=1
IfTrueAction7=[!SetVariable grid1 "#s#02#s#09#s#16#s#23#s##30#"][!SetVariable grid2 "#s#03#s#10#s#17#s#24#s##31#"][!SetVariable grid3 "#s#04#s#11#s#18#s#25"][!SetVariable grid4 "#s#05#s#12#s#19#s#26"][!SetVariable grid5 "#s#06#s#13#s#20#s#27"][!SetVariable grid6 "#s#07#s#14#s#21#s#28"][!SetVariable grid7 "01#s#08#s#15#s#22#s##29#"][!Update][!Redraw]
DynamicVariables=1
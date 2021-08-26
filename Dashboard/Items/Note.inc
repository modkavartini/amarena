[Variables]
@IncludeVars=#@#Variables.inc
fadeInOut=0

noteColor=[##mainNoteColor#]
noteColor2=#pink#
noteColor3=#green#

nextLine=##
strikeThru=~~
underline=__
italic=\*
bold=\*\*
color2=\$\$
color3=::

nXPadding=30
nYPadding=30
nWidth=315
nHeight=170

Note=*First, solve the ~~problem~~.##Then, write the __code__.####                                      $$-- John Johnson$$*

[NoteBackground]
Meter=Shape
Shape=Rectangle #noteX#,#noteY#,#nWidth#,#nHeight#,#bgRadius# | StrokeWidth 0 | Fill Color #bgColorD#,#bgAlpha#
MouseOverAction=[!ShowMeter Info][!Update][!Redraw]
MouseLeaveAction=[!HideMeter Info][!Update][!Redraw]
DynamicVariables=1

[TextInput]
Measure=Plugin
Plugin=InputText
FontFace=#gsans#
X=(#nXPadding#+#noteX#)
Y=(#noteY#+30)
W=(#nWidth#-(#nXPadding#*2))
H=(#nHeight#-(#nYPadding#*2))
StringAlign=LeftTop
SolidColor=#bgColorD#
FontSize=#noteSize#
FontColor=#noteColor#
AntiAlias=1
ClipString=2
DefaultValue=#Note#
Command1=[!WriteKeyValue Variables "Note" "$UserInput$" "#CurrentPath#\Items\Note.inc"][!Refresh]
DynamicVariables=1

[NoteText]
Measure=String
String=#Note#
Substitute="#nextLine#":"#CRLF#"

[NoteDisplay]
Meter=String
MeasureName=NoteText
Text="%1"
X=(#nXPadding#+#noteX#)
Y=((#nHeight#/2)+#noteY#)r
W=(#nWidth#-(#nXPadding#*2))
H=(#nHeight#-(#nYPadding#*2))
StringAlign=LeftCenter
FontFace=#gsans#
FontColor=#noteColor#
FontSize=#noteSize#
InlineSetting=Face|Blank
InlinePattern=#nextLine#|#strikeThru#|#underline#|#italic#|#bold#|#color2#|#color3#
InlineSetting2=Size|1
InlinePattern2=#nextLine#|#strikeThru#|#underline#|#italic#|#bold#|#color2#|#color3#
InlineSetting3=CharacterSpacing | (-#noteSize#/27.5)
InlinePattern3=#nextLine#|#strikeThru#|#underline#|#italic#|#bold#|#color2#|#color3#
InlineSetting4=Strikethrough
InlinePattern4=#strikeThru#(.*)#strikeThru#
InlineSetting5=Underline
InlinePattern5=#underline#(.*)#underline#
InlineSetting6=Italic
InlinePattern6=#italic#([^\*]*)#italic#
InlineSetting7=Weight|700
InlinePattern7=#bold#([^\*]*)#bold#
InlineSetting8=Color|#noteColor2#
InlinePattern8=#color2#(.*)#color2#
InlineSetting9=Color|#noteColor3#
InlinePattern9=#color3#(.*)#color3#
LeftMouseUpAction=[!CommandMeasure "TextInput" "ExecuteBatch 1"]
AntiAlias=1
ClipString=2
DynamicVariables=1

[Info]
Meter=String
X=(#nWidth#-30+#noteX#)
Y=(#nHeight#-30+#noteY#)
Padding=0,5,5,0
Text=" i"
FontFace=#iosevka#
FontColor=#noteColor#
FontSize=11
AntiAlias=1
Hidden=1
DynamicVariables=1
MouseOverAction=[!SetVariable fadeInOut 255][!Update][!Redraw]
MouseLeaveAction=[!SetVariable fadeInOut 0][!Update][!Redraw]

[FadeInOut]
Measure=Calc
Formula=#fadeInOut#
AverageSize=10
DynamicVariables=1

[TooltipBg]
Meter=Shape
X=r
Y=(-[TooltipText:H]-20)r
Shape=Rectangle -10,-10,([TooltipText:W]+20),([TooltipText:H]+20),#bgRadius# | StrokeWidth 0 | Fill Color #bgColorL#,[FadeInOut]
DynamicVariables=1

[TooltipText]
Meter=String
X=r
Y=r
Text=Use #nextLine# at the end of the text for going to the next line.#CRLF#Use #strikeThru# on both ends of the text to strike through it.#CRLF#Use #underline# on both ends of the text to underline it.#CRLF#Use * on both ends of the text to make it italic.#CRLF#Use ** on both ends of the text to make it bold.#CRLF#Use #color2# on both ends of the text to color it with #noteColor2#.#CRLF#Use #color3# on both ends of the text to color it with #noteColor3#.
FontColor=#fgColorL#,[FadeInOut]
FontFace=#iosevka#
FontSize=10
AntiAlias=1
DynamicVariables=1

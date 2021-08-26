[Variables]
@IncludeVars=#@#Variables.inc

[MTitle]
Measure=Plugin
Plugin=#plugin#
PlayerName=#player#
PlayerType=Title
RegExpSubstitute=1
Substitute="^(.+)\s\(.+$":"\1","":"Absolutely"," - (.*)":""
OnChangeAction=[!UpdateMeasure ScrollOrNot "#RootConfig#\Launcher\Spotify"][!Redraw]

[MArtist]
Measure=Plugin
Plugin=#plugin#
PlayerName=#player#
PlayerType=Artist
RegExpSubstitute=1
Substitute=", (.*)$":"","":"Nothing"
OnChangeAction=[!UpdateMeasure ScrollOrNot "#RootConfig#\Launcher\Spotify"][!Redraw]

[MProgress]
Measure=Plugin
Plugin=#plugin#
PlayerName=#player#
PlayerType=Progress
AverageSize=30

[MControl]
Measure=Plugin
Plugin=#plugin#
PlayerName=#player#
PlayerType=State
RegExpSubstitute=1
Substitute="0":"Play","1":"Pause","2":"Play","3":"Play Something!"
IfCondition=#CurrentSection#=2
IfTrueAction=[!SetOption PlayPause FontColor #fgColorL#][!SetOption PlayPauseS FontColor #indigo#][!SetVariable mButton 20][!Update][!Redraw]
IfFalseAction=[!SetOption PlayPause FontColor #indigo#][!SetOption PlayPauseS FontColor #fgColorL#][!SetVariable mButton 0][!Update][!Redraw]
DynamicVariables=1
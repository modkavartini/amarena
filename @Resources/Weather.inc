[Variables]
@IncludeVars=#@#Variables.inc

[MainWeather]
Measure=Plugin
Plugin=Webparser
URL=https://www.yahoo.com/news/weather
;Your location is automatically located. If it's incorrect or you want a custom place, access to https://www.yahoo.com/news/weather
;Click "Change Location", type in then choose where you want. After that, copy new webpage link and replace it with this measure URL. And refresh skin!
RegExp=(?siU)<h1 class="city.*data-reactid="7">(.*)</h1>.*<div class="My\(2px\).*60x60\/(.*)@2x.png.*data-reactid="26">(.*)<.*<span class="Va\(t\)" data-reactid="37">(.*)</span>
RegExpSubstitute=1
UpdateRate=60
FinishAction=[!SetOption WIcon ImageName "#@#Icons\WIcons\[MWeatherIcon]" ][!UpdateMeter WIcon][!Redraw]

[WeatherDesc]
Measure=Plugin
Plugin=Webparser
URL=[MainWeather]
StringIndex=3
Substitute="":"Loading..."
DynamicVariables=1

[MWeatherIcon]
Measure=Plugin
Plugin=Webparser
URL=[MainWeather]
StringIndex=2
DynamicVariables=1
Substitute="rain_day_night":"rain","scattered_showers_day_night":"scattered showers","windy_day_night":"wind","mostly_cloudy_day_night":"cloudy","partly_cloudy_night":"cloudy night","partly_cloudy_day":"cloudy day","cloudy_day_night":"cloudy","snow_rain_mix_day_night":"sleet","fair_day":"sun","fair_night":"moon","flurries_day_night":"light snow","snow_day_night":"snow","thundershowers_day_night":"storm","fog_day_night":"fog"
IfMatch=rain|scattered showers|wind|cloudy|sleet|fog
IfMatchAction=[!SetVariable wIconColor #indigo#]
IfMatch2=storm|light snow|snow
IfMatchAction2=[!SetVariable wIconColor #pink#]
IfMatch3=sun|cloudy day
IfMatchAction3=[!SetVariable wIconColor #peach#]
IfMatch4=moon|cloudy night
IfMatchAction4=[!SetVariable wIconColor #violet#]

[WTempF]
Measure=Plugin
Plugin=Webparser
URL=[MainWeather]
StringIndex=4
DynamicVariables=1

[WTempC]
Measure=Calc
Formula=Round((WTempF-32)*5/9)
;Substitute="-18":""


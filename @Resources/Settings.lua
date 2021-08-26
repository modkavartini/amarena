function Initialize()
	fileview = SKIN:GetMeasure('MeasureChild1')
	filecount = SKIN:GetMeasure('MeasureFileCount')
	itemConfig_X = SKIN:GetVariable('itemConfigX')
	itemName_X = SKIN:GetVariable('itemConfigX')
end

function editPosition()

	SKIN:Bang('[!ShowMeter X]'
			..'[!ShowMeter xPosSetting]'
			..'[!SetOption SliderX OnChangeAction """[!SetVariable itemConfig_X (round([*SliderX*]/100*#ScreenAreaWidth#))][!SetVariable '..itemName..'_X (round([*SliderX*]/100*#ScreenAreaWidth#)) "#rootconfig#\\Dashboard"][!WriteKeyValue Variables '..itemName..'X (round([*SliderX*]/100*#ScreenAreaWidth#)) "#*RootConfigPath*#\\@Resources\\Variables.inc"][!Update "#rootconfig#\\Dashboard"]"""]'
			..'[!SetOption xPosSetting MouseScrollUpAction """[!SetVariable itemConfig_X (#*itemConfig_X*#+1)][!SetVariable '..itemName..'_X (#*itemConfig_X*#+1) "#rootconfig#\\Dashboard"][!WriteKeyValue Variables '..itemName..'_X (#*itemConfig_X*#+1) "#*RootConfigPath*#\\@Resources\\Variables.inc"][!Update "#rootconfig#\\Dashboard"]"""]'
			..'[!SetOption xPosSetting MouseScrollDownAction """[!SetVariable itemConfig_X (#*itemConfig_X*#-1)][!SetVariable '..itemName..'_X (#*itemConfig_X*#-1) "#rootconfig#\\Dashboard"][!WriteKeyValue Variables '..itemName..'_X (#*itemConfig_X*#-1) "#*RootConfigPath*#\\@Resources\\Variables.inc"][!Update "#rootconfig#\\Dashboard"]"""]')
end
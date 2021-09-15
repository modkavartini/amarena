$githubName="ModkaVartini"
$skinName="Amarena"
$latestVerRaw=Invoke-WebRequest -Uri "https://api.github.com/repos/$githubName/$skinName/releases/latest" -UseBasicParsing
$latestVer=($latestVerRaw | ConvertFrom-Json).tag_name -replace "v",""
$url="https://github.com/$githubName/$skinName/releases/download/v$latestVer/$skinName"+"_$latestVer.rmskin"
$outPath="C:/Windows/Temp/$skinName"+"_$latestVer.rmskin"

    Write-Host "Downloading $skinName.rmskin..." -ForegroundColor "Yellow"
    $wc=New-Object System.Net.WebClient
    $wc.DownloadFile($url, $outPath)
    Start-Process -Filepath $outPath

    If($Null -NotMatch (get-process "SkinInstaller" -ea SilentlyContinue)) {
        Write-Host "Installing v$latestVer..." -ForegroundColor "Yellow"
        $wshell=New-Object -ComObject wscript.shell
        Start-Sleep -s .5
        $wshell.AppActivate('Rainmeter Skin Installer')
        Start-Sleep -s 1
        #$wshell.SendKeys('~')
        Write-Host "> The $skinName suite was installed successfully." -ForegroundColor "Green"
    }

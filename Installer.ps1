$githubName="modkavartini"
$skinName="Amarena"
$latestVerRaw=Invoke-WebRequest -Uri "https://api.github.com/repos/$githubName/$skinName/releases/latest" -UseBasicParsing
$latestVer=($latestVerRaw | ConvertFrom-Json).tag_name -replace "v",""
$url="https://github.com/$githubName/$skinName/releases/download/v$latestVer/$skinName"+"_$latestVer.rmskin"
$outPath="C:/Windows/Temp/$skinName"+"_$latestVer.rmskin"

    Write-Host "> Downloading $skinName..." -ForegroundColor "Yellow"
    $wc=New-Object System.Net.WebClient
    $wc.DownloadFile($url, $outPath)
    Start-Process -Filepath $outPath

    if($null -ne (get-process "SkinInstaller" -ea SilentlyContinue)) {
        Write-Host "> Installing v$latestVer..." -ForegroundColor "Yellow"
        $wshell=New-Object -ComObject wscript.shell
        Start-Sleep -s 1
        $wshell.AppActivate('Rainmeter Skin Installer')
        Start-Sleep -s 1
        $wshell.SendKeys('~')

        Write-Host "> The $skinName suite was installed successfully." -ForegroundColor "Green"
        Write-Host "> This window will close itself in 10 seconds..."
        Start-Sleep -s 10
        Remove-Item $outPath -ErrorAction SilentlyContinue
        exit
    }

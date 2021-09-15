$githubName="ModkaVartini"
$skinName="Amarena"
$latestVer="0.6"
$currentVer="0.5"
$url="https://github.com/$githubName/$skinName/releases/download/v$latestVer/$skinName"+"_$latestVer.rmskin"
$outPath="C:/Windows/Temp/$skinName"+"_$latestVer.rmskin"

If($latestVer -NotMatch $currentVer) {
    $wc=New-Object System.Net.WebClient
    $wc.DownloadFile($url, $outPath)
    Start-Process -Filepath $outPath

    If($Null -NotMatch (get-process "SkinInstaller" -ea SilentlyContinue)) {
        $wshell=New-Object -ComObject wscript.shell
        $wshell.AppActivate('Rainmeter Skin Installer')
        Start-Sleep -s 1
        #$wshell.SendKeys('~')
    }
}
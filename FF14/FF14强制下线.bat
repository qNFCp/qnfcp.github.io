@echo off
@chcp 65001
%1 mshta vbscript:CreateObject("Shell.Application").ShellExecute("cmd.exe","/c %~s0 rem","","runas",1)(window.close)&&exit
cls
echo .
echo 按任意键结束FF14进程...
echo .
pause > nul
taskkill /f /t /im ffxiv_dx11.exe
taskkill /f /t /im ffxiv.exe
echo .
echo .
echo .
echo . 请等待20秒后才能完全下线...
timeout /nobreak /t 20
echo .
echo OK啦
pause > nul
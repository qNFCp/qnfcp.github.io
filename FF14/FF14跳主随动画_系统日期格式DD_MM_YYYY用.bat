chcp 65001
@echo off
::修改系统日期和时间并重新同步网络时间
%1 mshta vbscript:CreateObject("Shell.Application").ShellExecute("cmd.exe","/c %~s0 rem","","runas",1)(window.close)&&exit
set #=FF14主随动画跳过工具（时间格式DD-MM-YY用）
title %#%
::设定时间
If %date:~3,2% equ 01 goto 31D
If %date:~3,2% equ 03 goto 31D
If %date:~3,2% equ 05 goto 31D
If %date:~3,2% equ 07 goto 31D
If %date:~3,2% equ 08 goto 31D
If %date:~3,2% equ 10 goto 31D
If %date:~3,2% equ 12 goto Dec
If %date:~3,2% equ 04 goto 30D
If %date:~3,2% equ 06 goto 30D
If %date:~3,2% equ 09 goto 30D
If %date:~3,2% equ 11 goto 30D
If %date:~3,2% equ 02 (goto LE) Else (Goto Next)

:LE
set a=&set b=&set c=&set d=
set a=%date:~6,4%
set /a b=%a%%%4
set /a c=%a%%%100
set /a d=%a%%%400
if %d%==0 goto yes
if %b%==0 (if not %c%==0 (goto yes) else (
goto no
)
) else goto no


:yes
If %date:~0,2% equ 29 (
Set DD=01
Set /a MM=%date:~3,2%+1
Set YY=%date:~6,4%
)
Else (
Set /a DD=%date:~0,2%+1
Set MM=%date:~3,2%
Set YY=%date:~6,4%
)
Goto Next


:no
If %date:~0,2% equ 28 (
Set DD=%date:~0,2%
Set /a MM=%date:~3,2%+1
Set YY=%date:~6,4%
)
Else (
Set /a DD=%date:~0,2%+1
Set MM=%date:~3,2%
Set YY=%date:~6,4%
)
Goto Next


:31D
If %date:~0,2% equ 31 (
Set DD=01
Set /a MM=%date:~3,2%+1
Set YY=%date:~6,4%
)
Else (
Set /a DD=%date:~0,2%+1
Set MM=%date:~3,2%
Set YY=%date:~6,4%
)
Goto Next

:30D
If %date:~0,2% equ 30 (
Set DD=01
Set /a MM=%date:~3,2%+1
Set YY=%date:~6,4%
)
Else (
Set /a DD=%date:~0,2%+1
Set MM=%date:~3,2%
Set YY=%date:~6,4%
)
Goto Next

:DEC
If %date:~0,2% equ 31(
Set DD=01
Set MM=01
Set /a YY=%date:~6,4%+1
)
Else (
Set /a DD=%date:~0,2%+1
Set MM=%date:~3,2%
Set YY=%date:~6,4%
)
Goto Next

:Next
Set Tdate=%DD%-%MM%-%YY%
set datetime=%Tdate% 23:59:00
::设定x秒后一键同步时间
set sleep=2
set "regpath=HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\services"
::关闭网络时间同步
reg add "%regpath%\W32Time" /v "Start" /t REG_DWORD /d 4 /f
reg add "%regpath%\W32Time\Parameters" /v "Type" /t REG_SZ /d "NoSync" /f
::修改时间
for /f "tokens=1,2" %%a in ("%datetime%") do (date %%a&time %%b)
if exist "%windir%\System32\timeout.exe" (timeout /t %sleep% /nobreak) else (>nul ping /n %sleep% 0)
::开启网络时间同步
reg add "%regpath%\W32Time" /v "Start" /t REG_DWORD /d 3 /f
reg add "%regpath%\W32Time\Parameters" /v "Type" /t REG_SZ /d "NTP" /f
::立即同步网络时间
w32tm /register
net start w32time
reg add "%regpath%\W32Time\Config" /v "MaxNegPhaseCorrection" /t REG_DWORD /d 4294967295 /f
reg add "%regpath%\W32Time\Config" /v "MaxPosPhaseCorrection" /t REG_DWORD /d 4294967295 /f
w32tm /config /manualpeerlist:time.windows.com /syncfromflags:manual /update
w32tm /resync

echo
echo 请等待20秒后再登录游戏...
timeout /nobreak /t 20
cls
echo
echo                 执行完成! 可以进入游戏啦！
echo
echo
echo 按任意键关闭
pause

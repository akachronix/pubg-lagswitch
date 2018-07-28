@echo off

IF NOT EXIST bin\ goto BIN_NOT_EXIST
IF EXIST bin\ goto BIN_EXIST

:COMPILE
echo Compiling fortnite_lagswitch.exe.
g++ -D_FORTNITE -Isrc\liblog -Isrc -Lsrc -Lbin -Wall -pedantic -g -s -o bin\fortnite_lagswitch.exe src\lagg.cpp src\lag_switch.cpp -static

echo Compiling pubg_lagswitch.exe.
g++ -D_PUBG -Isrc\liblog -Isrc -Lsrc -Lbin -Wall -pedantic -g -s -o bin\pubg_lagswitch.exe src\lagg.cpp src\lag_switch.cpp -static

IF NOT EXIST obj\ goto OBJ_NOT_EXIST
IF EXIST obj\ goto OBJ_EXIST

:MOVE_OBJECTS
rem move /Y *.o obj

pause
goto DONE

:BIN_EXIST
del /Q /S bin
goto BIN_NOT_EXIST

echo.

:BIN_NOT_EXIST
mkdir bin
goto COMPILE

:OBJ_EXIST
del /Q /S obj
goto OBJ_NOT_EXIST

:OBJ_NOT_EXIST
rem mkdir obj
goto MOVE_OBJECTS

:DONE
rem exit
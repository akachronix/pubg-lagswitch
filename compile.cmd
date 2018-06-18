@echo off

IF NOT EXIST bin\ goto BIN_NOT_EXIST
IF EXIST bin\ goto BIN_EXIST

:COMPILE
echo Compiling.
g++ -Isrc\liblog -Isrc -Lsrc -Lbin -Wall -pedantic -g -s -c src\lagg.cpp src\liblog\liblog.cpp src\lag_switch.cpp

IF NOT EXIST obj\ goto OBJ_NOT_EXIST
IF EXIST obj\ goto OBJ_EXIST

:MOVE_OBJECTS
move /Y *.o obj

echo Linking.
g++ -Isrc\liblog -Isrc -Lsrc -Lbin -Wall -pedantic -g -s -o bin\pubg_lagswitch.exe obj\lagg.o obj\liblog.o obj\lag_switch.o -static

echo Done.

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
mkdir obj
goto MOVE_OBJECTS

:DONE
exit
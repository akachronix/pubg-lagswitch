@echo off

echo compiling
g++ -Isrc\liblog -Isrc -Lsrc -Lbin -Wall -pedantic -g -s -o bin\pubg_lagswitch.exe src\lagg.cpp src\liblog\liblog.cpp src\lag_switch.cpp -static
g++ -Isrc\liblog -Isrc -Lsrc -Lbin -Wall -pedantic -g -D_LOGGER_DEBUG -o bin\pubg_lagswitch_debug.exe src\lagg.cpp src\liblog\liblog.cpp src\lag_switch.cpp -static

pause
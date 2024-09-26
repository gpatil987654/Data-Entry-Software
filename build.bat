cl.exe /c /EHsc Window.cpp
rc.exe dilog.rc
link Window.obj dilog.res user32.lib gdi32.lib kernel32.lib /SUBSYSTEM:WINDOWS
window.exe


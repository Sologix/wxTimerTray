; TimerTray setup script

[Setup]
AppName=TimerTray
AppVerName=TimerTray Version 2.1
DefaultDirName={pf}\TimerTray
DefaultGroupName=TimerTray
UninstallDisplayIcon={app}\TimerTray.exe
WizardImageFile=stopwatch.bmp
WizardImageStretch=yes
WizardImageAlphaFormat=none

[Files]
Source: "TimerTray.exe"; DestDir: "{app}"
Source: "Alarm.wav"; DestDir: "{app}"
Source: "License.txt"; DestDir: "{app}"

[Icons]
Name: "{group}\TimerTray"; Filename: "{app}\TimerTray.ico"

[Registry]
Root: HKCU; Subkey: "Software\Microsoft\Windows\CurrentVersion\Run"; Flags: uninsdeletekey; ValueType: string; ValueName: "TimerTray"; ValueData: "{app}\TimerTray.exe"

[Run]
Filename: "{app}\TimerTray.exe"; Flags: nowait runasoriginaluser



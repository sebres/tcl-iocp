cd %~dp0
echo foo
IF NOT DEFINED VCINSTALLDIR call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvars64.bat" 10.0.15063.0
echo bar
nmake /s /f makefile.vc INSTALLDIR=d:\tcl\debug\x64 OPTS=pdbs %*


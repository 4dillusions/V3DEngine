rem WindowsAndroid

rem ####################################################################################
rem clear temporary files
del /s /q *.bak

rem ####################################################################################
rem clear Assets folder to Windows
del /s /q Solution\WindowsAndroid\Windows\Bin\Debug\x64\Assets\*
del /s /q Solution\WindowsAndroid\Windows\Bin\Release\x64\Assets\*

rem clear Assets folder to Android
del /s /q Solution\WindowsAndroid\Android\V3DEngineTests\V3DEngineTests.Packaging\assets\*

rem ####################################################################################
rem clean all WindowsAndroid VS compiled files
del /s /q Solution\WindowsAndroid\.vs\*

rem clean all Windows VS compiled files
del /s /q Solution\WindowsAndroid\Windows\Bin\*.ilk
del /s /q Solution\WindowsAndroid\Windows\Bin\*.pdb
del /s /q Solution\WindowsAndroid\Windows\Bin\*.ipdb
del /s /q Solution\WindowsAndroid\Windows\Bin\*.iobj
del /s /q Solution\WindowsAndroid\Windows\Bin\*.exp
del /s /q Solution\WindowsAndroid\Windows\Bin\*.obj
del /s /q Solution\WindowsAndroid\Windows\Bin\*.log
del /s /q Solution\WindowsAndroid\Windows\Bin\*.txt
del /s /q Solution\WindowsAndroid\Windows\Bin\*.tlog
del /s /q Solution\WindowsAndroid\Windows\Bin\*.lastbuildstate

del /s /q Solution\WindowsAndroid\Windows\ThirdParty\SoLoud\x64\Debug\*
del /s /q Solution\WindowsAndroid\Windows\ThirdParty\SoLoud\x64\Release\*

del /s /q Solution\WindowsAndroid\Windows\V3DEngine\x64\Debug\*
del /s /q Solution\WindowsAndroid\Windows\V3DEngine\x64\Release\*

del /s /q Solution\WindowsAndroid\Windows\V3DEngineTests\x64\Debug\*
del /s /q Solution\WindowsAndroid\Windows\V3DEngineTests\x64\Release\*

rem clean all Android VS compiled files
del /s /q Solution\WindowsAndroid\Android\Bin\*

del /s /q Solution\WindowsAndroid\Android\V3DEngine\ARM\Debug\*
del /s /q Solution\WindowsAndroid\Android\V3DEngine\ARM\Release\*
del /s /q Solution\WindowsAndroid\Android\V3DEngine\ARM64\Debug\*
del /s /q Solution\WindowsAndroid\Android\V3DEngine\ARM64\Release\*
del /s /q Solution\WindowsAndroid\Android\V3DEngine\x86\Debug\*
del /s /q Solution\WindowsAndroid\Android\V3DEngine\x86\Release\*
del /s /q Solution\WindowsAndroid\Android\V3DEngine\x64\Debug\*
del /s /q Solution\WindowsAndroid\Android\V3DEngine\x64\Release\*

del /s /q Solution\WindowsAndroid\Android\V3DEngineTests\V3DEngineTests.NativeActivity\ARM\Debug\*
del /s /q Solution\WindowsAndroid\Android\V3DEngineTests\V3DEngineTests.NativeActivity\ARM\Release\*
del /s /q Solution\WindowsAndroid\Android\V3DEngineTests\V3DEngineTests.NativeActivity\ARM64\Debug\*
del /s /q Solution\WindowsAndroid\Android\V3DEngineTests\V3DEngineTests.NativeActivity\ARM64\Release\*
del /s /q Solution\WindowsAndroid\Android\V3DEngineTests\V3DEngineTests.NativeActivity\x86\Debug\*
del /s /q Solution\WindowsAndroid\Android\V3DEngineTests\V3DEngineTests.NativeActivity\x86\Release\*
del /s /q Solution\WindowsAndroid\Android\V3DEngineTests\V3DEngineTests.NativeActivity\x64\Debug\*
del /s /q Solution\WindowsAndroid\Android\V3DEngineTests\V3DEngineTests.NativeActivity\x64\Release\*

del /s /q Solution\WindowsAndroid\Android\V3DEngineTests\V3DEngineTests.Packaging\ARM\Debug\*
del /s /q Solution\WindowsAndroid\Android\V3DEngineTests\V3DEngineTests.Packaging\ARM\Release\*
del /s /q Solution\WindowsAndroid\Android\V3DEngineTests\V3DEngineTests.Packaging\ARM64\Debug\*
del /s /q Solution\WindowsAndroid\Android\V3DEngineTests\V3DEngineTests.Packaging\ARM64\Release\*
del /s /q Solution\WindowsAndroid\Android\V3DEngineTests\V3DEngineTests.Packaging\x86\Debug\*
del /s /q Solution\WindowsAndroid\Android\V3DEngineTests\V3DEngineTests.Packaging\x86\Release\*
del /s /q Solution\WindowsAndroid\Android\V3DEngineTests\V3DEngineTests.Packaging\x64\Debug\*
del /s /q Solution\WindowsAndroid\Android\V3DEngineTests\V3DEngineTests.Packaging\x64\Release\*
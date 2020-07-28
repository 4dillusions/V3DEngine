rem clear and copy Assets folder to Windows
del /s /q Solution\WindowsAndroid\Windows\Bin\Debug\x64\Assets\*
del /s /q Solution\WindowsAndroid\Windows\Bin\Release\x64\Assets\*

xcopy /s Assets Solution\WindowsAndroid\Windows\Bin\Debug\x64\Assets /e
xcopy /s Assets Solution\WindowsAndroid\Windows\Bin\Release\x64\Assets /e

rem clear and copy Assets folder to Android
del /s /q Solution\WindowsAndroid\Android\V3DEngineTests\V3DEngineTests.Packaging\assets\*
xcopy /s Assets Solution\WindowsAndroid\Android\V3DEngineTests\V3DEngineTests.Packaging\assets /e

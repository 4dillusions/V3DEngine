rem clear and copy AssetsMain folder to Windows
del /s /q Solution\WindowsAndroid\Windows\Bin\Debug\x64\Assets\*
del /s /q Solution\WindowsAndroid\Windows\Bin\Release\x64\Assets\*

xcopy /s /i AssetsMain Solution\WindowsAndroid\Windows\Bin\Debug\x64\Assets /e
xcopy /s /i AssetsMain Solution\WindowsAndroid\Windows\Bin\Release\x64\Assets /e

rem clear and copy AssetsMain folder to Android
del /s /q Solution\WindowsAndroid\Android\V3DEngineTests\V3DEngineTests.Packaging\assets\*
xcopy /s /i AssetsMain Solution\WindowsAndroid\Android\V3DEngineTests\V3DEngineTests.Packaging\assets /e

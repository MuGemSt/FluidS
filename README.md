# FluidS

[![license](https://img.shields.io/github/license/george-chou/FluidS.svg)](https://www.gnu.org/licenses/gpl-3.0.en.html)
[![AppVeyor](https://img.shields.io/appveyor/ci/george-chou/FluidS.svg?logo=appveyor)](https://ci.appveyor.com/project/george-chou/FluidS)
[![Github All Releases](https://img.shields.io/github/downloads/george-chou/FluidS/total.svg)](https://github.com/george-chou/FluidS/releases)
[![GitHub release](https://img.shields.io/github/release/george-chou/FluidS.svg)](https://github.com/george-chou/FluidS/releases/latest)

Its core algorithm of the simulation process refers to Robert Bridson's <i>Fluid Simulation for Computer Graphics</i>. It uses the numerical solution of Navier-Stokes equations to predict the density and velocity distribution of particles in each frame displayed in the OpenGL widget of Qt. There are two resolution options for users: 64 × 64 and 128 × 128. Users can also change display mode between density and velocity in 7 colors.

| <img src="https://george-chou-github-io.vercel.app/covers/FluidS/fsd.PNG"/> | <img src="https://george-chou-github-io.vercel.app/covers/FluidS/fsv.PNG"/> |
| :-------------------------------------------------------------------------: | :-------------------------------------------------------------------------: |
|                                Density field                                |                               Velocity field                                |

## Code download
```
git clone https://github.com/george-chou/FluidS.git
```

## Environment installation

### Requirements download
| Requirements                    | Links                                                                                                                                    | Extraction code  |
| :------------------------------ | :--------------------------------------------------------------------------------------------------------------------------------------- | :--------------: |
| Qt 5.7 dynamic      compiler    | [qt-opensource-windows-x86-msvc2015-5.7.1](https://download.qt.io/new_archive/qt/5.7/5.7.1/qt-opensource-windows-x86-msvc2015-5.7.1.exe) |   Direct link    |
| Compiled Qt 5.7 static compiler | [qt5-x86-static-release](https://www.123pan.com/s/qeQDVv-gcFJH)                                                                          |      `iUgO`      |
| Visual Studio 2015              | [Microsoft Visual Studio 2015](https://www.123pan.com/s/qeQDVv-wcFJH)                                                                    |      `0pwH`      |
| Qt VS AddIn                     | [qt-vsaddin-msvc2015-2.4.3.vsix](https://download.qt.io/archive/vsaddin/2.4.3/qt-vsaddin-msvc2015-2.4.3.vsix)                            |   Direct link    |
| MinGW                           | [mingw-w64-install.exe](https://www.123pan.com/s/qeQDVv-3ZFJH)                                                                           |      `BWll`      |
| Visual Studio Code              | <https://code.visualstudio.com/Download>                                                                                                 | Official website |

### Installation order

1. Install Qt 5.7 dynamic compiler
2. Install Visual Studio 2015
3. Install Qt VS AddIn
4. Install MinGW
5. Install Visual Studio Code

## Environment configuration

### Dependencies 

1. Open the project with VS2015, right click `Project` - `Properties`
2. Configure the selection `Release`
3. Open `Configuration Properties` - `C/C++` - `Code Generation` - `Runtime Library` and select `Multithreading (/MT)`
4. Open `Configuration Properties` - `Linker` - `Input` - `Additional Dependencies` and paste in the following long string of characters:

`$(QTDIR)\lib\qtmain.lib;$(QTDIR)\lib\Qt5Widgets.lib;$(QTDIR)\plugins\platforms\qwindows.lib;winspool.lib;shlwapi.lib;rpcrt4.lib;$(QTDIR)\lib\Qt5PlatformSupport.lib;$(QTDIR)\plugins\imageformats\qdds.lib;$(QTDIR)\plugins\imageformats\qicns.lib;$(QTDIR)\plugins\imageformats\qico.lib;$(QTDIR)\plugins\imageformats\qtga.lib;$(QTDIR)\plugins\imageformats\qtiff.lib;$(QTDIR)\plugins\imageformats\qwbmp.lib;$(QTDIR)\plugins\imageformats\qwebp.lib;$(QTDIR)\lib\Qt5Gui.lib;comdlg32.lib;oleaut32.lib;imm32.lib;winmm.lib;glu32.lib;opengl32.lib;gdi32.lib;$(QTDIR)\lib\qtharfbuzzng.lib;$(QTDIR)\lib\Qt5Core.lib;kernel32.lib;user32.lib;shell32.lib;uuid.lib;ole32.lib;advapi32.lib;ws2_32.lib;mpr.lib`

### Qt configuration

1. Complete the additional dependencies configuration from the previous step
2. Unzip the compiled Qt static compiler `qt5-x86-static-release`
3. Open the project with VS2015, click `[Qt VS Tools]` -> `[Qt Options]` -> `[Add]`, select the Qt static compiler path unzipped just now and confirm
4. Select `qt5-x86-static-release` in the `[Default Qt/Win version]` drop-down menu, click OK

## Debug

1. Right-click the project directory and open the project with VSCode
2. Confirm that the `includePath` of `c_cpp_properties.json` in the project is correctly configured with the `Qt 5.7 dynamic compiler` path installed earlier, and the `compilerPath` is correctly configured with the environment variable path of `MinGW`
3. Click `Run` - `Start Debug` (or press F5 directly on the keyboard to start Debug mode)

## Release

1. Open the project with VS2015
2. Select `Release` mode `x86`
3. Select `Build` - `Rebuild Solution`
4. Take out the .exe file from Release in the project directory, which is the file for release

## License

![GPL-v3](https://www.gnu.org/graphics/gplv3-127x51.png)

[Flat icon set](https://www.easyicon.net/550601-Fluid_icon.html) from [easyicon](https://www.easyicon.net/);

All source codes are licensed under [GPL-3.0](https://opensource.org/licenses/GPL-3.0).

If you want to make any modification on these source codes while keeping new codes unprotected by GPL-3.0, please contact me for a sublicense instead.

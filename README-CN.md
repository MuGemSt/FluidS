# FluidS

[![license](https://img.shields.io/github/license/george-chou/FluidS.svg)](https://www.gnu.org/licenses/gpl-3.0.en.html)
[![AppVeyor](https://img.shields.io/appveyor/ci/george-chou/FluidS.svg?logo=appveyor)](https://ci.appveyor.com/project/george-chou/FluidS)
[![Github All Releases](https://img.shields.io/github/downloads/george-chou/FluidS/total.svg)](https://github.com/george-chou/FluidS/releases)
[![GitHub release](https://img.shields.io/github/release/george-chou/FluidS.svg)](https://github.com/george-chou/FluidS/releases/latest)

其仿真过程的核心算法参考了 Robert Bridson 的 <i>Fluid Simulation for Computer Graphics</i>。它使用 Navier-Stokes 方程的数值解来预测 Qt 的 OpenGL 小部件中显示的每一帧中粒子的密度和速度分布。有两种分辨率可供用户选择：64 × 64 和 128 × 128。用户还可以在 7 种颜色的密度和速度之间切换显示模式。

| <img src="https://george-chou-github-io.vercel.app/covers/FluidS/fsd.PNG"/> | <img src="https://george-chou-github-io.vercel.app/covers/FluidS/fsv.PNG"/> |
| :-------------------------------------------------------------------------: | :-------------------------------------------------------------------------: |
|                                   密度场                                    |                                   速度场                                    |

## 代码下载
```
git clone https://github.com/george-chou/FluidS.git
```

## 环境安装

### 必要项下载

| 必要项                  | 链接                                                                                                                                     | 提取码 |
| :---------------------- | :--------------------------------------------------------------------------------------------------------------------------------------- | :----: |
| Qt 5.7 动态编译器       | [qt-opensource-windows-x86-msvc2015-5.7.1](https://download.qt.io/new_archive/qt/5.7/5.7.1/qt-opensource-windows-x86-msvc2015-5.7.1.exe) |  直链  |
| 编译好的Qt5.7静态编译器 | [qt5-x86-static-release](https://www.123pan.com/s/qeQDVv-gcFJH)                                                                          | `iUgO` |
| Visual Studio 2015      | [Microsoft Visual Studio 2015](https://www.123pan.com/s/qeQDVv-wcFJH)                                                                    | `0pwH` |
| Qt VS AddIn             | [qt-vsaddin-msvc2015-2.4.3.vsix](https://download.qt.io/archive/vsaddin/2.4.3/qt-vsaddin-msvc2015-2.4.3.vsix)                            |  直链  |
| MinGW                   | [mingw-w64-install.exe](https://www.123pan.com/s/qeQDVv-3ZFJH)                                                                           | `BWll` |
| Visual Studio Code      | <https://code.visualstudio.com/Download>                                                                                                 |  官网  |

### 安装顺序

1. 安装 Qt 5.7 动态编译器
2. 安装 Visual Studio 2015
3. 安装 Qt VS AddIn
4. 安装 MinGW
5. 安装 Visual Studio Code

## 环境配置

### 附加依赖项配置

1. 用 VS2015 打开工程，右键 `项目` - `属性`
2. 配置选择 `活动(Release)`
3. 打开 `配置属性` - `C/C++` - `代码生成` - `运行库` 选择 `多线程(/MT)`
4. 打开 `配置属性` - `链接器` - `输入` - `附加依赖项` ，将下述长串字符粘贴进去：

`$(QTDIR)\lib\qtmain.lib;$(QTDIR)\lib\Qt5Widgets.lib;$(QTDIR)\plugins\platforms\qwindows.lib;winspool.lib;shlwapi.lib;rpcrt4.lib;$(QTDIR)\lib\Qt5PlatformSupport.lib;$(QTDIR)\plugins\imageformats\qdds.lib;$(QTDIR)\plugins\imageformats\qicns.lib;$(QTDIR)\plugins\imageformats\qico.lib;$(QTDIR)\plugins\imageformats\qtga.lib;$(QTDIR)\plugins\imageformats\qtiff.lib;$(QTDIR)\plugins\imageformats\qwbmp.lib;$(QTDIR)\plugins\imageformats\qwebp.lib;$(QTDIR)\lib\Qt5Gui.lib;comdlg32.lib;oleaut32.lib;imm32.lib;winmm.lib;glu32.lib;opengl32.lib;gdi32.lib;$(QTDIR)\lib\qtharfbuzzng.lib;$(QTDIR)\lib\Qt5Core.lib;kernel32.lib;user32.lib;shell32.lib;uuid.lib;ole32.lib;advapi32.lib;ws2_32.lib;mpr.lib`

### Qt 配置

1. 完成前一步的附加依赖项配置
2. 解压编译好的 Qt 静态编译器 `qt5-x86-static-release`
3. 用 VS2015 打开工程，点击 `[Qt VS Tools]` -> `[Qt Options]` -> `[Add]`，选择前面解压好的 Qt 静态编译器路径并确定
4. 在 `[Default Qt/Win version]` 下拉菜单中选择 `qt5-x86-static-release`，点 OK

## 调试

1. 右键工程目录以 VSCode 打开工程
2. 确认工程中 `c_cpp_properties.json` 的 `includePath` 正确配置了前面安装的 `Qt 5.7 动态编译器`路径，同时 `compilerPath` 正确配置了 `MinGW` 的环境变量路径
3. 点击 `运行` - `启动调试` (或直接键盘按F5开启Debug模式)

## 发布

1. 用 VS2015 打开工程
2. 选择 `Release` 模式 `x86`
3. 选择 `生成` - `重新生成解决方案`
4. 在工程目录下的 Release 中取出 .exe 文件，即为用于发布的文件

## 许可证

<a href="https://opensource.org/licenses/GPL-3.0" target="_blank">
    <img src="https://www.gnu.org/graphics/gplv3-127x51.png" />
</a>


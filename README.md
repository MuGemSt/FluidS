# FluidS
[![license](https://img.shields.io/github/license/MuGeminorum/FluidS.svg)](https://www.gnu.org/licenses/gpl-3.0.en.html)
[![AppVeyor](https://img.shields.io/appveyor/ci/MuGeminorum/FluidS.svg?logo=appveyor)](https://ci.appveyor.com/project/MuGeminorum/FluidS)
[![Github All Releases](https://img.shields.io/github/downloads/MuGeminorum/FluidS/total.svg)](https://github.com/MuGeminorum/FluidS/releases)
[![GitHub release](https://img.shields.io/github/release/MuGeminorum/FluidS.svg)](https://github.com/MuGeminorum/FluidS/releases/latest)
[![](https://img.shields.io/badge/bilibili-BV1LM4y1Q7K1-fc8bab.svg)](https://www.bilibili.com/video/BV1LM4y1Q7K1)
[![](https://img.shields.io/badge/cnblog-17181715-075db3.svg)](https://www.cnblogs.com/MuGeminorum/p/17181715.html)

其仿真过程的核心算法参考了 Robert Bridson 的 _Fluid Simulation for Computer Graphics_。它使用 Navier-Stokes 方程的数值解来预测 Qt 的 OpenGL 小部件中显示的每一帧中粒子的密度和速度分布。有两种分辨率可供用户选择：64 × 64 和 128 × 128。用户还可以在 7 种颜色的密度和速度之间切换显示模式。

Its core algorithm of the simulation process refers to Robert Bridson's _Fluid Simulation for Computer Graphics_. It uses the numerical solution of Navier-Stokes equations to predict the density and velocity distribution of particles in each frame displayed in the OpenGL widget of Qt. There are two resolution options for users: 64 × 64 and 128 × 128. Users can also change display mode between density and velocity in 7 colors.

| ![fsd](https://user-images.githubusercontent.com/20459298/233125917-4eb82aec-a305-4e92-8bb7-88fb5f52d775.PNG) | ![fsv](https://user-images.githubusercontent.com/20459298/233125957-1e9ed77d-85f5-40a5-873d-86efc9adba2f.PNG) |
| :-----------------------------------------------------------------------------------------------------------: | :-----------------------------------------------------------------------------------------------------------: |
|                                          **密度场 (Density field)**                                           |                                          **速度场 (Velocity field)**                                          |

## 代码下载 Code download
```bash
git clone https://github.com/MuGeminorum/FluidS.git
cd FluidS
```

## 环境安装配置及代码调试发布 Environment installation, configuration & code debugging, release
此部分内容请统一参考此[博文](https://www.cnblogs.com/MuGeminorum/p/17017063.html)

Please refer to this [blog post](https://www.cnblogs.com/MuGeminorum/p/17017063.html) for this section.
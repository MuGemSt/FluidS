# FluidS
[![license](https://img.shields.io/github/license/MuGeminorum/FluidS.svg)](https://www.gnu.org/licenses/gpl-3.0.en.html)
[![AppVeyor](https://img.shields.io/appveyor/ci/MuGeminorum/FluidS.svg?logo=appveyor)](https://ci.appveyor.com/project/MuGeminorum/FluidS)
[![Github All Releases](https://img.shields.io/github/downloads/MuGeminorum/FluidS/total.svg)](https://github.com/MuGeminorum/FluidS/releases)
[![GitHub release](https://img.shields.io/github/release/MuGeminorum/FluidS.svg)](https://github.com/MuGeminorum/FluidS/releases/latest)
[![](https://img.shields.io/badge/bilibili-BV1LM4y1Q7K1-fc8bab.svg)](https://www.bilibili.com/video/BV1LM4y1Q7K1)

Its core algorithm of the simulation process refers to Robert Bridson's <i>Fluid Simulation for Computer Graphics</i>. It uses the numerical solution of Navier-Stokes equations to predict the density and velocity distribution of particles in each frame displayed in the OpenGL widget of Qt. There are two resolution options for users: 64 × 64 and 128 × 128. Users can also change display mode between density and velocity in 7 colors.

| ![fsd](https://user-images.githubusercontent.com/20459298/233125917-4eb82aec-a305-4e92-8bb7-88fb5f52d775.PNG) | ![fsv](https://user-images.githubusercontent.com/20459298/233125957-1e9ed77d-85f5-40a5-873d-86efc9adba2f.PNG) |
| :-----------------------------------------------------------------------------------------------------------: | :-----------------------------------------------------------------------------------------------------------: |
|                                               **Density field**                                               |                                              **Velocity field**                                               |

## Code download
```bash
git clone https://github.com/MuGeminorum/FluidS.git
```

## Environment installation, configuration & code debugging, release
Please refer to this [blog post](https://www.cnblogs.com/MuGeminorum/p/17017063.html) for this section.

## License
![GPL-v3](https://www.gnu.org/graphics/gplv3-127x51.png)

[Flat icon set](./SmokeSimulation/Resources/Fluid_48px.ico) from [easyicon](https://www.easyicon.cc/)

All source codes are licensed under [GPL-3.0](https://opensource.org/licenses/GPL-3.0)

If you want to make any modification on these source codes while keeping new codes unprotected by GPL-3.0, please contact me for a sublicense instead.

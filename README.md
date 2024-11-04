# FluidS
[![license](https://img.shields.io/github/license/MuGemSt/FluidS.svg)](https://github.com/MuGemSt/FluidS/blob/main/LICENSE)
[![Build status](https://ci.appveyor.com/api/projects/status/b531gepjilv9m6ko?svg=true)](https://ci.appveyor.com/project/MuGemSt/fluids)
[![GitHub release](https://img.shields.io/github/release/MuGemSt/FluidS.svg)](https://github.com/MuGemSt/FluidS/releases/latest)
[![bilibili](https://img.shields.io/badge/bilibili-BV1LM4y1Q7K1-fc8bab.svg)](https://www.bilibili.com/video/BV1LM4y1Q7K1)
[![cnblogs](https://img.shields.io/badge/cnblog-17181715-075db3.svg)](https://www.cnblogs.com/MuGem/p/17181715.html)

其仿真过程的核心算法参考了 Robert Bridson 的 _Fluid Simulation for Computer Graphics_。它使用 Navier-Stokes 方程的数值解来预测 Qt 的 OpenGL 小部件中显示的每一帧中粒子的密度和速度分布。有两种分辨率可供用户选择：64 × 64 和 128 × 128。用户还可以在 7 种颜色的密度和速度之间切换显示模式。

Its core algorithm of the simulation process refers to Robert Bridson's _Fluid Simulation for Computer Graphics_. It uses the numerical solution of Navier-Stokes equations to predict the density and velocity distribution of particles in each frame displayed in the OpenGL widget of Qt. There are two resolution options for users: 64 × 64 and 128 × 128. Users can also change display mode between density and velocity in 7 colors.

| ![](https://user-images.githubusercontent.com/20459298/233125917-4eb82aec-a305-4e92-8bb7-88fb5f52d775.PNG) | ![](https://user-images.githubusercontent.com/20459298/233125957-1e9ed77d-85f5-40a5-873d-86efc9adba2f.PNG) |
| :--------------------------------------------------------------------------------------------------------: | :--------------------------------------------------------------------------------------------------------: |
|                                         **密度场 (Density field)**                                         |                                        **速度场 (Velocity field)**                                         |

## 代码下载 Code download
```bash
git clone https://github.com/MuGemSt/FluidS.git
cd FluidS
```

## 环境安装配置及代码调试发布 Environment installation, configuration & code debugging, release
此部分内容请统一参考此[博文](https://www.cnblogs.com/MuGem/p/17017055.html)

Please refer to this [blog post](https://www.cnblogs.com/MuGem/p/17017063.html) for this section.

# Welcome to the FluidS wiki!
The core problems solved are as follows:

<div align=center> 
    <img width="215" src="https://user-images.githubusercontent.com/20459298/233126128-b877e41e-d323-4ba3-836b-2a8600b5bd88.png"/>
</div>

Since the equations to be processed are made in two lines in real-time, one is the velocity field, and the other is the density field. And what we're going to end up visualizing is the latter. However, real-time updates of the former are also essential because the latter's real-time updates need to be supported by the former.

## Core process
The solution flow for the speed field and the density field is as follows:

<div align=center>
    <b>Figure 1: Velocity field and density field solution process</b><br>
    <img width="515" src="https://user-images.githubusercontent.com/20459298/233126211-494305a0-e3ec-4b19-8d5f-e6865df7991d.png"/>
</div>

First, the source force item is handled, and the processing of it is also in processing concentration supplement of the density field. If we assume that the external force added throughout the process does not change dramatically,

<div align=center>
    <img width="215" src="https://user-images.githubusercontent.com/20459298/233126269-c41afb7b-a1ef-4feb-a94a-fc3246fc6e9a.PNG"/>
</div>

It is an excellent approximation within the _Δt_ time interval and is highly compatible with interactive systems. The effect of force occurs only at the beginning of each moment.

Next, the convection terms are calculated. Since the velocity field and density fields are solved similarly, the relatively complex velocity field is directly explained. It is precise because of the existence of _−(**u** · ∇)**u**_ that the Navier-Stokes equation becomes a nonlinear equation. Foster and Metaxas use the finite difference method when processing this term. Their algorithm can only guarantee stability when the time step is tiny, and the condition is _∆t < ∆τ/|**u**|_, where delta t is the scale of the current computing grid. Here uses Stam's semi-Lagrangian characteristic line solution method. Convection item questions can be abstracted into the following form:

<div align=center>
    <img width="355" src="https://user-images.githubusercontent.com/20459298/233126345-7b90aa2c-b147-420d-9d68-99ed359fc419.PNG"/>
</div>

, where a is a scalar field, _**v**_ is a stable vector field, and _a0_ is the first field at time _t = 0_. Use _**P**(**x**0, t)_ to represent the characteristic line of the vector field _**v**_ at time _t = 0_ passing through the point _**x**0_:

<div align=center>
    <img width="315" src="https://user-images.githubusercontent.com/20459298/233126422-6a5f18d0-fd5f-431b-bc5e-9ef69310cc54.PNG"/>
</div>

Now let ̅a _(**x**0, t) = a(**P**(**x**0, t))_ be the value of the field along the characteristic line passing through the point _**x**0_ at time _t = 0_. The following difference law chain can calculate the rate of change of this quantity with time:

<div align=center>
    <img width="175" src="https://user-images.githubusercontent.com/20459298/233126482-53c78957-819f-443b-b958-f1c275546820.PNG"/>
</div>

It indicates that the value of this scalar is not consistent along the curve. In particular, we have  ̅a _(**x**0, t) =_ ̅a _(**x**0, 0) = a0(**x**0)_. Therefore, the first field and the characteristic line can completely define the solution to the convection problem. The field at a given time _t_ and position _**x**_ can be calculated by _**x**_ back to the previous position along the characteristic line in real-time to get the point _**x**0_, and then approximate the first field at that point:

<div align=center>
    <img width="175" src="https://user-images.githubusercontent.com/20459298/233126537-f255d820-b1a3-4b6d-80dd-225d7dbed596.PNG"/>
</div>

We use this method to solve the fluid's convection equation in the time interval _[t, t + ∆t]_. Where _v = **u**(**x**, t)_ and a _0_ is the velocity component of any fluid at time _t_. Use the above method to advance _**u**1_ to _**u**2_ as follows:

<div align=center>
    <img width="185" src="https://user-images.githubusercontent.com/20459298/233126597-6ee593a8-d1f2-407c-95c1-48cf5ceed5d3.PNG"/>
</div>

Next, the viscous term is calculated. Since the relationship between the two-dimensional viscous term and the one-dimensional diffusion term is merely one-dimensional, the solution of the viscous item is the solution to each component's diffuse issue. In the previous introduction, it was also mentioned that it could be processed by Gauss-Seidel iteration, namely:

<div align=center>
    <img width="110" src="https://user-images.githubusercontent.com/20459298/233126647-47e59438-313f-4887-af86-37f932a66466.PNG"/>
</div>

, where the _**I**_ is the unit operator. When the diffusion operator is discretized, solving this format requires solving a sparse linear system to get _**u**3_. The last thing that needs to be done is to introduce a projection operator to make the obtained field a passive field so that _**u**3_ can be used for _**u**0_ at the next moment. To solve the above problem, we need to start with the Helmholtz-Hodge decomposition. For any vector field _**w**_ can be decomposed into the following form:

<div align=center>
    <img width="100" src="https://user-images.githubusercontent.com/20459298/233126704-5cf8d7f4-2787-43fb-b10c-953f0fc6e968.PNG"/>
</div>

, where **_u_** is a passive field, and _q_ is a scalar field. According to this conclusion, we define a projection operator _**P**_ so that any vector field _**w**_ can be projected to the part with a divergence of _0_, that is, _**u** = **Pw**_. The construction of this operator can be obtained by multiplying the gradient operator on both sides of the above formula at the same time:

<div align=center>
    <img width="105" src="https://user-images.githubusercontent.com/20459298/233126771-46ebdab6-203a-4b82-8375-827497e0ab23.PNG"/>
</div>

At this time, a Poisson equation about the scalar field _q_ is obtained with Neumann boundary conditions _∂q/∂**n** = 0_ on _∂D_. The process of solving is the process of calculating _**u**_ projection:

<div align=center>
    <img width="155" src="https://user-images.githubusercontent.com/20459298/233126845-f798a3f0-3dbc-4f51-8a87-caef5461c868.PNG"/>
</div>

Applying this projection operator to both sides of the original Navier-Stokes equation gives a simple comparison of the velocity field:

<div align=center>
    <img width="255" src="https://user-images.githubusercontent.com/20459298/233126919-bde4e3d4-86d2-4653-84b0-8bdafd3b98f8.PNG"/>
</div>

According to the above description, the projection process for this step is transformed into a problem to solve the Poisson equation, namely:

<div align=center>
    <img width="220" src="https://user-images.githubusercontent.com/20459298/233126990-2b04763c-5fa3-473b-aa26-a9a233eb2632.PNG"/>
</div>

After the Poisson problem's discretization, a sparse linear system is obtained with a solution complexity of _O(N)_. Since the entire process is calculated in the _∆t_ period, the algorithm's operation efficiency is also critical. For the operation processing of the operators above, we use the FFT algorithm. Fourier transform is often used to deal with periodic boundary conditions. The problem, our current challenge, is a particular simple situation. Periodicity allows us to map the velocity field to Fourier space:

<div align=center>
    <img width="135" src="https://user-images.githubusercontent.com/20459298/233127056-809cead7-1944-4dd5-a17c-cb4be34851a9.PNG"/>
</div>

The gradient operator _∇_ in Fourier space can be equivalent to multiplying by _i**k**_, where _i^2 = −1_. In this way, the calculation of the previous diffusion operator and projection operator will become very simple:

<div align=center>
    <img width="275" src="https://user-images.githubusercontent.com/20459298/233127111-20f4e20c-0e63-414c-a8dd-e7bd10e84157.PNG"/>
</div>

, where _k = |**k**|_. The operator ̂**P** maps the vector ̂**w**_(**k**)_ to a relatively regular region for wavelet _**k**_. The Fourier transform of the velocity in the passive field therefore, always remains orthogonal to the wavelet. The diffusion operator can be regarded as a filter whose attenuation is proportional to the time step and the viscosity coefficient. Therefore, we can completely convert the solution operator into two routes. Both are optimized with the following _O(NlogN)_ complexity FFT algorithm:

<div align=center>
    <img width="615" src="https://user-images.githubusercontent.com/20459298/233127157-7ac17865-cf85-45f6-aa9f-81427929faca.PNG"/>
</div>

The last task is to embed the adaptive grid algorithm into each solution plate. As mentioned earlier, the density gradient is used as a criterion. If the density gradient at the center of a block exceeds the threshold, the mesh subdivides and solves the problem. According to the density gradient level, you can determine how many degrees the area needs to be divided so that it is determined to iterate on until the highest density gradient is completed.
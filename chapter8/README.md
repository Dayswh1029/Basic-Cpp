
# Chapter 8: Speedup Your Program  
我的是Intel 因此需要利用其余办法解决ARM 的案例程序
自己部署了 docker 来模拟 ARM

## Compiler options (-O3 for GCC, -Wall, etc…)

## SIMD (SSE, AVX, NEON, RISC-V, Universal Intrinsics of OpenCV)

## OpenMP

## Memory Hierarchies and Speed

## Crop ROI from a 2D Matrix

## Intel, ARM and RISC-V Architechture 

## Lab:

Create two 1Mx1K float matrices matA and matB, compute matA + matB.

* compute the result row by row and col by col, compare the performance difference
* use -O3 to improve the speed
* improve the speed using SIMD, will the speed be improved? Why?

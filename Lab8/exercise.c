#include <stdio.h>
#include <stdlib.h>
#include <immintrin.h> // AVX2
#include <omp.h>       // OpenMP
#include <time.h>
#include <stdlib.h>

#ifdef _WIN32
    #include <malloc.h>
    // Windows 下使用 _aligned_malloc //  
    #define MY_ALIGNED_ALLOC(alignment, size) _aligned_malloc(size, alignment)
    #define MY_ALIGNED_FREE(ptr) _aligned_free(ptr)
#else
    // Linux/macOS 使用标准 aligned_alloc
    #define MY_ALIGNED_ALLOC(alignment, size) aligned_alloc(alignment, size)
    #define MY_ALIGNED_FREE(ptr) free(ptr)
#endif
#define N 1000000 // 1M

int main() {
    // 使用 aligned_alloc 保证 AVX2 对齐 (32 bytes)
    // float *a = (float*)aligned_alloc(32, N * sizeof(float)); // 这个aligned_alloc 常常有错误问题！
    //如果你在 Windows 上，aligned_alloc 并不总是直接可用，Windows 下通常使用 _aligned_malloc。

// 替换前：
// float *a = (float*)aligned_alloc(32, N * sizeof(float));
// float *b = (float*)aligned_alloc(32, N * sizeof(float));
// float *c = (float*)aligned_alloc(32, N * sizeof(float));

// 替换后：
float *a = (float*)MY_ALIGNED_ALLOC(32, N * sizeof(float));
float *b = (float*)MY_ALIGNED_ALLOC(32, N * sizeof(float));
float *c = (float*)MY_ALIGNED_ALLOC(32, N * sizeof(float));

// 在程序末尾释放内存时，也要注意：
MY_ALIGNED_FREE(a);

    // 初始化
    for (int i = 0; i < N; i++) { a[i] = (float)i; b[i] = (float)i; }

    // --- 1. 纯 C 实现 ---
    double start = omp_get_wtime();
    for (int i = 0; i < N; i++) c[i] = a[i] + b[i];
    printf("Pure C: %f seconds\n", omp_get_wtime() - start);

    // --- 2. SIMD (AVX2) 实现 ---
    start = omp_get_wtime();
    for (int i = 0; i < N; i += 8) { // 每次处理 8 个 float
        __m256 va = _mm256_load_ps(&a[i]);
        __m256 vb = _mm256_load_ps(&b[i]);
        __m256 vc = _mm256_add_ps(va, vb);
        _mm256_store_ps(&c[i], vc);
    }
    printf("SIMD (AVX2): %f seconds\n", omp_get_wtime() - start);

    // --- 3. OpenMP 并行实现 ---
    start = omp_get_wtime();
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        c[i] = a[i] + b[i];
    }
    printf("OpenMP: %f seconds\n", omp_get_wtime() - start);

    free(a); free(b); free(c);
    return 0;

}

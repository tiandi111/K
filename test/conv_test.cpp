//
// Created by 田地 on 2021/1/5.
//
#include "test/conv_test.h"
#include "conv.h"
#include <iostream>

using namespace std;

void TestConv2D(const int32_t oc, const int32_t ic,
                const int32_t ih, const int32_t iw,
                const int32_t kh, const int32_t kw) {
    int32_t target = kw * kh * ic;

    int32_t oh = ih - kh + 1;
    int32_t ow = iw - kw + 1;

    float *src = new float [ic * ih * iw];
    float *ker = new float [oc * ic * kh * kw];
    float *dst = new float [oc * oh * ow];

    for (int32_t i=0; i<ic * ih * iw; i++) {
        src[i] = 1;
    }
    for (int32_t i=0; i<oc * ic * kh * kw; i++) {
        ker[i] = 1;
    }

    K::Conv2DHandle h = K::Conv2DHandle(oc, ic, ih, iw, kh, kw, src, ker, dst);

    h.Forward();

    for (int32_t i=0; i<oc * oh * ow; i++) {
        assert(dst[i] == target);
    }
}

void BenchmarkConv2D(const int32_t oc, const int32_t ic,
                     const int32_t ih, const int32_t iw,
                     const int32_t kh, const int32_t kw) {
    int32_t oh = ih - kh + 1;
    int32_t ow = iw - kw + 1;

    float *src = new float [ic * ih * iw];
    float *ker = new float [oc * ic * kh * kw];
    float *dst = new float [oc * oh * ow];

    for (int32_t i=0; i<ic * ih * iw; i++) {
        src[i] = 1;
    }
    for (int32_t i=0; i<oc * ic * kh * kw; i++) {
        ker[i] = 1;
    }

    K::Conv2DHandle h = K::Conv2DHandle(oc, ic, ih, iw, kh, kw, src, ker, dst);

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    h.Forward();

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
}
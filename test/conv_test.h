//
// Created by 田地 on 2021/1/5.
//

#ifndef K_CONV_TEST_H
#define K_CONV_TEST_H

#include <cstdint>

void TestConv2D(const int32_t oc, const int32_t ic,
                const int32_t ih, const int32_t iw,
                const int32_t kh, const int32_t kw);

void BenchmarkConv2D(const int32_t oc, const int32_t ic,
        const int32_t ih, const int32_t iw,
        const int32_t kh, const int32_t kw);

#endif //K_CONV_TEST_H

//
// Created by 田地 on 2021/1/5.
//

#include "conv_test.h"
#include <chrono>
#include <iostream>

int main() {
//    TestConv2D(16, 8, 256, 256, 3, 3);
    BenchmarkConv2D(16, 8, 256, 256, 3, 3);
}
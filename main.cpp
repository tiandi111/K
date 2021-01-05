#include <iostream>
#include "conv.h"

using namespace std;

int main() {
    float src[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
    float ker[4] = {1, 1, 1, 1};
    float dst[4] = {};

    K::Conv2DHandle h = K::Conv2DHandle(1, 1, 3, 3, 2, 2, src, ker, dst);

    h.Forward();

    for (int32_t i=0; i<4; i++) {
        cout<< dst[i] <<endl;
    }
}

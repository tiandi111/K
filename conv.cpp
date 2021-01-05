//
// Created by 田地 on 2021/1/5.
//
#include "conv.h"

void K::Conv2DHandle::inferShape() {
    oh = ih - kh + 1;
    ow = iw - kw + 1;
}

// nchw layout
void K::Conv2DHandle::Forward() {
//    int32_t oc_step = oh*ow;
    #pragma omp parallel
    for (int32_t m=0; m<oc; m++) {
//        int32_t oc_off = m*oc_step;
        for (int32_t k=0; k<ic; k++) {
            for (int32_t j=0; j<oh; j++) {
//                int32_t oh_off = j*ow;
//                int32_t ih_off = j*iw;
                for (int32_t i=0; i<ow; i++) {
                    for (int32_t u=0; u<kh; u++) {
//                        ih_off += iw;
//                        int32_t kh_off = u*kw;
                        for (int32_t v=0; v<kw; v++) {
//                            dst[oc_off + oh_off + i] += src[ih_off + (i+v)] * ker[kh_off + v];
                            dst[m*oh*ow + j*ow + i] += src[j*iw + (i+v)] * ker[v*kw + v];
                        }
                    }
                }
            }
        }
    }
}
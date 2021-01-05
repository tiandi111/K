//
// Created by 田地 on 2021/1/5.
//

#ifndef K_CONV_H
#define K_CONV_H

#include <cstddef>
#include <cstdint>

namespace K {
    struct Conv2DHandle {
    private:
        int32_t oc, ic;
        int32_t ih, iw;
        int32_t kh, kw;

        int32_t oh, ow;

        float *src;
        float *ker;
        float *dst;

        void inferShape();

    public:
        Conv2DHandle(int32_t _oc, int32_t _ic, int32_t _ih, int32_t _iw, int32_t _kh, int32_t _kw,
                float *_src, float *_ker, float *_dst) :
        oc(_oc), ic(_ic), ih(_ih), iw(_iw), kh(_kh), kw(_kw), src(_src), ker(_ker), dst(_dst) {
            inferShape();
        }

        int32_t OW() {return ow;}
        int32_t OH() {return oh;}

        void Forward();
    };

}

#endif //K_CONV_H

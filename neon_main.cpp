#include <arm_neon.h>
#include <stdio.h>

int main(int argc, char const* argv[]) {
  {
    const uint8_t buf1[] = {0, 1, 2, 3, 4, 5, 6, 7};
    const uint8_t buf2[] = {8, 9, 10, 11, 12, 13, 14, 15};
    uint8_t buf3[8]      = {0};
    uint8x8_t a;
    uint8x8_t b;
    uint8x8_t c;

    a = vld1_u8(buf1);
    b = vld1_u8(buf2);
    c = vadd_u8(a, b);
    vst1_u8(buf3, c);

    for (int i = 0; i < 8; i++) {
      printf("%d\n", buf3[i]);
    }
  }

  {
    int8_t buf1[16];
    int8_t buf2[16];
    int8_t buf3[16] = {0};
    int8x16_t a;
    int8x16_t b;
    int8x16_t c;

    for (int i = 0; i < 16; i++) {
      buf1[i] = 64 + i;
      buf2[i] = 64 + i;
    }

    a = vld1q_s8(buf1);
    b = vld1q_s8(buf2);
    // NOTE: overflow
    // NOTE: c=a+b
    c = vaddq_s8(a, b);
    // NOTE: c=c>>2
    c = vshrq_n_s8(c, 2);
    vst1q_s8(buf3, c);

    for (int i = 0; i < 8; i++) {
      printf("%d\n", buf3[i]);
    }
  }

  {
    int8_t buf1[8];
    int8_t buf2[8];
    int8_t buf3[8] = {0};
    int8x8_t src1;
    int8x8_t src2;
    int16x8_t mid;
    int8x8_t ret;

    for (int i = 0; i < 16; i++) {
      buf1[i] = 64 + i;
      buf2[i] = 64 + i;
    }

    src1 = vld1_s8(buf1);
    src2 = vld1_s8(buf2);
    // NOTE: no overflow
    // NOTE: c=a+b
    // NOTE: 1lane(64bit)を拡張して，結果を2lanes(128bit)で取得
    mid = vaddl_s8(src1, src2);
    // NOTE: c=c>>2 and cast int16x8_t -> int8x8_t
    // NOTE: 演算とlaneのshrinkを同時に行う
    ret = vshrn_n_s16(mid, 2);
    vst1_s8(buf3, ret);

    for (int i = 0; i < 8; i++) {
      printf("%d\n", buf3[i]);
    }
  }
  return 0;
}

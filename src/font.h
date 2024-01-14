#ifndef Font_H
#define Font_H

#include "constants.h"
#include <stdint.h>

// https://lvgl.io/tools/font_conv_v5_3

LEDCUBE_NAMESPACE_BEGIN

typedef struct font_t font_t;
typedef struct font_glyph_dsc_t font_glyph_dsc_t;
typedef struct draw_buf_t draw_buf_t;

struct font_t {
  uint32_t unicode_first;
  uint32_t unicode_last;
  uint16_t h_px;
  const uint8_t *glyph_bitmap;
  const font_glyph_dsc_t *glyph_dsc;
  uint16_t glyph_cnt;
};

struct font_glyph_dsc_t {
  const font_t *font_p;
  uint16_t w_px;
  uint32_t glyph_index;
};

struct byte_buffer_t {
  uint8_t size;
  uint8_t cursor;
  uint8_t buffer[8];
  bool has_next() { return size > cursor; };
  uint8_t next() {
    uint8_t value = buffer[cursor];
    cursor += 1;
    return value;
  };
};

bool font_get_glyph_dsc(const font_t *font_p, font_glyph_dsc_t *glyph_p,
                        uint32_t letter);

const void font_get_glyph_bitmap(font_glyph_dsc_t *glyph_p,
                                 byte_buffer_t *buffer_p);

LEDCUBE_NAMESPACE_END

// uint_t transform_buffer[8]

//     void
//     clear_buffer() {
//   for (int i = 0; i < 8; i++) {
//     for (int j = 0; j < 8; j++) {
//       transform_buffer[i][j] = 0x00;
//     }
//   }
// }

// void transform(uint8_t *src[][], uint8_t *dat[][],
//                std::function<void(*CubeAddress, *CubeAddress)>
//                transformation) {
//   clear_buffer();

//   for (int i = 0; i < 8; i++) {
//     for (int j = 0; j < 8; j++) {
//     }
//   }
// }

// void test() {
//   auto transformation = [](CubeAddress *in, CubeAddress *out) {
//     out->x = in->y;
//     out->y = in->x;
//     out->z = byte_reverse(in->z);
//   }
// }

#endif

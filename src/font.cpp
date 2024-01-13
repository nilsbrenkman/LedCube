#include "font.h"

LEDCUBE_NAMESPACE_BEGIN

bool font_get_glyph_dsc(const font_t *font_p, font_glyph_dsc_t *glyph_p,
                        uint32_t letter) {
  if (letter < font_p->unicode_first || letter > font_p->unicode_last) {
    return false;
  }

  glyph_p->font_p = font_p;
  glyph_p->w_px = font_p->glyph_dsc[letter - font_p->unicode_first].w_px;
  glyph_p->glyph_index =
      font_p->glyph_dsc[letter - font_p->unicode_first].glyph_index;

  return true;
}

const void font_get_glyph_bitmap(font_glyph_dsc_t *glyph_p,
                                 draw_buf_t *buffer_p) {

  buffer_p->size = glyph_p->w_px;

  for (int i = 0; i < 8; i++) {
    buffer_p->bitmap[i] = 0x00;
  }

  for (int i = 0; i < 8; i++) {
    uint8_t row = glyph_p->font_p->glyph_bitmap[glyph_p->glyph_index + i];
    for (int j = 0; j < 8; j++) {
      if (bit_check(row, j)) {
        bit_set(buffer_p->bitmap[7 - j], i);
      }
    }
  }
}

LEDCUBE_NAMESPACE_END
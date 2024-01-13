#include "ticker.h"

LEDCUBE_NAMESPACE_BEGIN

Ticker::Ticker() { buffer = {}; }

void Ticker::tick() {
  if (buffer->size == 0) {
    font_glyph_dsc_t glyph = {};
    font_get_glyph_dsc(&dogica, &glyph, 0x0047);
    font_get_glyph_bitmap(&glyph, buffer);
  }
}

LEDCUBE_NAMESPACE_END
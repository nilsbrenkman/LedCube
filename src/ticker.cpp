#include "ticker.h"

LEDCUBE_NAMESPACE_BEGIN

static const uint8_t columns[] = {
    0x70, 0x60, 0x50, 0x40, 0x30, 0x20, 0x10, 0x00, 0x01, 0x02, 0x03,
    0x04, 0x05, 0x06, 0x07, 0x17, 0x27, 0x37, 0x47, 0x57, 0x67, 0x77};

const String text = String("Hoi Lenae, heb je lekker geslapen?  ");

Ticker::Ticker() {
  for (unsigned int i = 0; i < sizeof(columns); i++) {
    uint8_t xy = columns[i];
    uint8_t x = (xy & 0xF0) >> 4;
    uint8_t y = (xy & 0x0F);
    ticker_data[i] = {idx_to_bit(x), idx_to_bit(y), NO_BITS};
  }

  update(ALL_CUBE, CLEAR);
}

void Ticker::tick() {
  if (buffer.has_next()) {

    append_to_ticker(buffer.next());

  } else {

    font_glyph_dsc_t glyph = {};
    font_get_glyph_dsc(&dogica, &glyph, text.charAt(next_char_idx));
    font_get_glyph_bitmap(&glyph, &buffer);

    next_char_idx = (next_char_idx + 1) % (text.length() + 8);
    append_to_ticker(0);
  }
}

int Ticker::frequency() { return 250; }

void Ticker::append_to_ticker(uint8_t bit) {
  cube_address_t *target;
  cube_address_t *source;
  for (unsigned int i = 1; i < sizeof(columns); i++) {
    target = &ticker_data[i - 1];
    source = &ticker_data[i];
    uint8_t toggle = target->z ^ source->z;
    if (toggle == 0) {
      continue; // no update
    }
    target->z = source->z;
    update({target->x, target->y, toggle}, TOGGLE);
  }
  uint8_t toggle = source->z ^ bit;
  if (toggle != 0) {
    update({source->x, source->y, toggle}, TOGGLE);
    source->z = bit;
  }

  print_to_serial();
}

void Ticker::print_to_serial() {
  Serial.print("\n\n\n\n");
  for (int j = 0; j < 8; j++) {
    Serial.print("// ");
    for (unsigned int i = 0; i < sizeof(columns); i++) {
      uint8_t dots = ticker_data[i].z;
      if (bit_check(dots, j)) {
        Serial.print("# ");
      } else {
        Serial.print("` ");
      }
    }
    Serial.println("");
  }
}

LEDCUBE_NAMESPACE_END
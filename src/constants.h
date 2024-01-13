#ifndef Constants_H
#define Constants_H

#ifndef LEDCUBE_NAMESPACE_BEGIN
#define LEDCUBE_NAMESPACE_BEGIN //namespace LedCube {
#define LEDCUBE_NAMESPACE_END   //}
#endif

LEDCUBE_NAMESPACE_BEGIN

#define LED_CLOCK_PIN TX
#define LED_DATA_PIN RX
#define LED_LATCH_PIN A7

#define LED_CUBE_SIZE 8
#define REFRESH_RATE 1000

enum class LedCubeOperation { set, clear, toggle };

#define SET LedCubeOperation::set
#define TOGGLE LedCubeOperation::toggle
#define CLEAR LedCubeOperation::clear

#define ALL_BITS 0xFF
#define ALL_CUBE                                                               \
  { ALL_BITS, ALL_BITS, ALL_BITS }

/*
 * Bit operations
 */
#define bit_set(byte, nbit) ((byte) |= (1 << (nbit)))
#define bit_clear(byte, nbit) ((byte) &= ~(1 << (nbit)))
#define bit_flip(byte, nbit) ((byte) ^= (1 << (nbit)))
#define bit_check(byte, nbit) ((byte) & (1 << (nbit)))

#define idx_to_bit(idx) (uint8_t)(0x01 << idx)

#define write_to_register(out)                                                 \
  shiftOut(LED_DATA_PIN, LED_CLOCK_PIN, MSBFIRST, out);

LEDCUBE_NAMESPACE_END

#endif

#ifndef CubeTypes_H
#define CubeTypes_H

#include "stdint.h"

typedef struct {
  uint8_t x = (uint8_t) 0;
} cube_vector_t;

typedef struct {
  cube_vector_t y[8];
} cube_matrix_t;

typedef struct {
  cube_matrix_t z[8];
} cube_t;

typedef struct {
  uint8_t x;
  uint8_t y;
  uint8_t z;
} cube_address_t;

#endif
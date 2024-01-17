struct {
  degrees heading;
  degrees attitude;
  degrees bank;
} rotation_t;

struct {
  axis_t from;
  axis_t to;
  bool imverted;
} mapping_t;


enum degrees_t { R_0, R_90, R_180, R_270 };
enum axis_t { x, y, z };

void rotate_cube(cube_t *source,
                 cube_t *dest,
                 rotation_t * rotation) {
                  
  mapping_t mapping[3] = {
    { x, x, false },
    { y, y, false },
    { z, z, false }
  };
  apply_rotation(&mapping, x, z, rotation.heading);
  apply_rotation(&mapping, x, y, rotation.attitude);
  apply_rotation(&mapping, y, z, rotation.bank);
  
  cube_t *buffer = new cube_t;
  
  for (uint8_t z : BITS_RANGE) {
    for (uint8_t y : BITS_RANGE) {
      for (uint8_t x : BITS_RANGE) {
        if (bit_check(*source.z[z].y[y].x, x) {
          
        }
      }
    }
  }
    
  delete[] buffer;
    
}


void apply_rotation(mapping_t *mapping,
                    axis_t axis_1,
                    acis_t axis_2,
                    degrees_t degrees) {
  mapping_t a;
  mapping_t b;
  switch (degrees) {
    case R_0: return;
    case R_90:
      a = { axis_1, axis_2, true };
      b = { axis_2, axis_1, false };
      break;
    case R_180:
      a = { axis_1, axis_1, true };
      b = { axis_2, axis_2, true };
      break;
    case R_270:
      a = { axis_1, axis_2, false };
      b = { axis_2, axis_1, true };
      break;
  }
  for (int i = 0; i < 3; i++) {
    if (*mapping[i].to == a.from) {
      *mapping[i].to = a.to;
      *mapping[i].inverted ^= a.inverted;
    } else if (*mapping[i].to == b.from) {
      *mapping[i].to = b.to;
      *mapping[i].inverted ^= b.inverted;
    } 
  }
}



struct {
  degrees heading;
  degrees attitude;
  degrees bank;
} rotation;

enum degrees { R_0, R_90, R_180, R_270 };

void rotate_cube(cube_t *source,
                 cube_t *dest,
                 rotation * rotation) {
    
    cube_t *buffer = new cube_t;
    
    
    
}
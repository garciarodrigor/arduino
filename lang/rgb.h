#ifndef RGB_h
#define RGB_h

#ifdef __cplusplus
extern "C" {
#endif

typedef struct rgb *rgb_t;

/**
 * Set Red color on RGB types
 */
rgb_t rgb_new(unsigned char r, unsigned char g, unsigned char b);

/**
 * Destroy a RGB type
 */
void rgb_destroy(rgb_t);

/**
 * Set Red color on RGB types
 */
void rgb_set_red(rgb_t obj, unsigned char value);

/**
 * Get Red color on RGB types
 */
unsigned char rgb_get_red(rgb_t obj);

/**
 * Set Green color on RGB types
 */
void rgb_set_green(rgb_t obj, unsigned char value);

/**
 * Get Green color on RGB types
 */
unsigned char rgb_get_green(rgb_t obj);

/**
 * Set Blue color on RGB types
 */
void rgb_set_blue(rgb_t obj, unsigned char value);

/**
 * Get Blue color on RGB types
 */
unsigned char rgb_get_blue(rgb_t obj);

#ifdef __cplusplus
}
#endif

#endif

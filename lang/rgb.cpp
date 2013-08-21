#include <stdlib.h>

#include "rgb.h"

#define IS_RGB(t) (t!=NULL)

struct rgb {
    unsigned char r;
    unsigned char g;
    unsigned char b;
};

/**
 * Create a new RGB type
 */
rgb_t rgb_new(unsigned char r, unsigned char g, unsigned char b)
{
    rgb_t obj;
    
    obj = (rgb_t) malloc(sizeof(*obj));
    
    if (IS_RGB(obj)) {
        rgb_set_red(obj, r);
        rgb_set_green(obj, g);
        rgb_set_blue(obj, b);
    }
    
    return obj;
}

/**
 * Destroy a RGB type
 */
void rgb_destroy(rgb_t obj)
{
    if (IS_RGB(obj)) {
        free(obj);
    }
}

/**
 * Set Red color on RGB types
 */
void rgb_set_red(rgb_t obj, unsigned char value)
{
    obj->r = value;
}

/**
 * Get Red color on RGB types
 */
unsigned char rgb_get_red(rgb_t obj)
{
    return obj->r;
}

/**
 * Set Green color on RGB types
 */
void rgb_set_green(rgb_t obj, unsigned char value)
{
    obj->g = value;
}

/**
 * Get Green color on RGB types
 */
unsigned char rgb_get_green(rgb_t obj)
{
    return obj->g;
}

/**
 * Set Blue color on RGB types
 */
void rgb_set_blue(rgb_t obj, unsigned char value)
{
    obj->b = value;
}

/**
 * Get Blue color on RGB types
 */
unsigned char rgb_get_blue(rgb_t obj)
{
    return obj->b;
}


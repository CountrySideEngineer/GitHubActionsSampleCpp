/**
 *  template.c
 *
 *  this is template file.
 */
#include "ev3api.h"

CPP_DECL_BEGIN

 // Global variables.


// Static variables.


// External variables.


// Constant


// Static constant


// Methods

/**
 *  Initialize buffer specified by arguments.
 */
void init_buff(int size, char *buff, char val) {
    int id;

    for (id = 0; id < size; id++) {
        *buff = val;
        buff++;
    }
}

/**
 *  @brief  Limitation values specofied by arguments.
 *          If the specified value is within the range, return that value.
 *          If it is outside the range, return the upper or lower limit.
 *          If the upper and lower limits are reversed, return "0".
 */  
int limit_int(int value, int min, int max) {
    int limited_value = 0;

    if (min < max) {    // Check the "max" is larger than "min".
        if ((min <= value) && (value <= max)) {
            // In caase the value is in the range.
            limited_value = value;
        } else {
            // In caase the value is out of the range.
            if (value < min) {
                limited_value = min;
            } else if (max < value) {
                limited_value = max;
            }
        }
    } else {
        limited_value = 0;
    }

    return limited_value;
}

CPP_DECL_END

#pragma once

#include "ev3api.h"

extern void init_buff(int size, char *buff, char val);
extern int limit_int(int value, int min, int max);

/**
 *  @macro
 *  Initialize the buffer.
 *  Specify the variable that represents the buffer index as the first argument.
 *  Use "val" to specify the initial value (the value to initialize with).
 */
#define INIT_BUF_VAL(size, buff, val)    init_buff(size, buff, val)

/**
 *  @macro
 *  Initialize the buffer.
 *  Specify the variable that represents the buffer index as the first argument.
 *  The buffer is initialized with all values set to 0.
 */
#define INIT_BUF(size, buff) INIT_BUF_VAL(size, buff, 0)

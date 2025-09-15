/**
 *  CLC_TravelSpeed.c
 *
 *  Calculate speed of vehicle from travel distance in a cycle.
 */
#include "ev3api.h"

/*****************************************************************************/
/*                                  �ϐ���`                                 */
/*****************************************************************************/
int16_t left_speed;
int16_t right_speed;
int32_t left_motor_trav_dist_hi_acc_prev;   //Unit:mm LSB:0.01
int32_t right_motor_trav_dist_hi_acc_prev;  //Unit:mm LSB:0.01

/*****************************************************************************/
/*                                  �ÓI�ϐ�                                 */
/*****************************************************************************/
static const int CYCLE_PERIOD = 2; //unit:sec LSB:0.1 - 200msec

/*****************************************************************************/
/*                                  �萔��`                                 */
/*****************************************************************************/


/*****************************************************************************/
/*                                �O���ϐ��錾                               */
/*****************************************************************************/
extern int32_t left_motor_trav_dist_hi_acc;    //Unit:mm LSB:0.01
extern int32_t right_motor_trav_dist_hi_acc;   //Unit:mm LSB:0.01

/*****************************************************************************/
/*                                �O���萔��`                               */
/*****************************************************************************/


/*****************************************************************************/
/*                                  �O���֐�                                 */
/*****************************************************************************/


/*****************************************************************************/
/*                                  �֐�����                                 */
/*****************************************************************************/
static int32_t travel_speed(int32_t trav_dist, int32_t trav_dist_prev, int cycle);

/**
 * @brief   Calculate speed from travel distance of left and right motor.
 */
void calc_travel_speed(void) {
    left_speed = travel_speed(left_motor_trav_dist_hi_acc,
        left_motor_trav_dist_hi_acc_prev,
        CYCLE_PERIOD);
    right_speed = travel_speed(right_motor_trav_dist_hi_acc,
        right_motor_trav_dist_hi_acc_prev,
        CYCLE_PERIOD);

    left_motor_trav_dist_hi_acc_prev = left_motor_trav_dist_hi_acc;
    right_motor_trav_dist_hi_acc_prev = right_motor_trav_dist_hi_acc;
}

/**
 * @brief   Calculate speed from travel distance.
 */
static int32_t travel_speed(int32_t trav_dist, int32_t trav_dist_prev, int cycle) {
    int32_t speed = 0;
    int32_t ddist = 0;

    ddist = trav_dist - trav_dist_prev;
    speed = ddist / cycle;   //LSB:0.1 mm/sec
    speed /= 10;    //Convert LSB into 1.0 mm/sec

    return speed;
}

/**
 * @brief   Initialize parameters.
 */
void init_travel_speed(void) {
    left_speed = 0;
    right_speed = 0;
    left_motor_trav_dist_hi_acc_prev = 0;
    right_motor_trav_dist_hi_acc_prev = 0;
}
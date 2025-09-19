#include "gtest/gtest.h"
#include "ev3api.h"

CPP_DECL_BEGIN

// グローバル変数
extern int16_t left_speed;
extern int16_t right_speed;
extern int32_t left_motor_trav_dist_hi_acc_prev;   //Unit:mm LSB:0.01
extern int32_t right_motor_trav_dist_hi_acc_prev;  //Unit:mm LSB:0.01

int32_t left_motor_trav_dist_hi_acc = 0;    //Unit:mm LSB:0.01
int32_t right_motor_trav_dist_hi_acc = 0;   //Unit:mm LSB:0.01

// テスト対象関数
void init_travel_speed(void);

CPP_DECL_END

TEST(UTEST_TravelSpeed_init_travel_speed, 001)
{
	// 事前条件
	left_speed = 1234;
	right_speed = 5678;
	left_motor_trav_dist_hi_acc_prev = 91011;
	right_motor_trav_dist_hi_acc_prev = 121314;

	// テスト実行
	init_travel_speed();

	// 判定
	EXPECT_EQ(0, left_speed);
	EXPECT_EQ(0, right_speed);
	EXPECT_EQ(0, left_motor_trav_dist_hi_acc_prev);
	EXPECT_EQ(0, right_motor_trav_dist_hi_acc_prev);
}	

TEST(UTEST_TravelSpeed_init_travel_speed, 002)
{
	// 事前条件
	left_speed = 0;
	right_speed = 0;
	left_motor_trav_dist_hi_acc_prev = 0;
	right_motor_trav_dist_hi_acc_prev = 0;

	// テスト実行
	init_travel_speed();

	// 判定
	EXPECT_EQ(0, left_speed);
	EXPECT_EQ(0, right_speed);
	EXPECT_EQ(0, left_motor_trav_dist_hi_acc_prev);
	EXPECT_EQ(0, right_motor_trav_dist_hi_acc_prev);
}	

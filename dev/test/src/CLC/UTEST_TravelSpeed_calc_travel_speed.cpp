#include "gtest/gtest.h"
#include "ev3api.h"

CPP_DECL_BEGIN

// グローバル変数
extern int16_t left_speed;
extern int16_t right_speed;
extern int32_t left_motor_trav_dist_hi_acc_prev;   //Unit:mm LSB:0.01
extern int32_t right_motor_trav_dist_hi_acc_prev;  //Unit:mm LSB:0.01

extern int32_t left_motor_trav_dist_hi_acc;    //Unit:mm LSB:0.01
extern int32_t right_motor_trav_dist_hi_acc;   //Unit:mm LSB:0.01

// テスト対象関数
void calc_travel_speed(void);

CPP_DECL_END

class TravelSpeed_calc_travel_speed : public ::testing::Test {
protected:
    void SetUp() override { }
};

TEST_F(TravelSpeed_calc_travel_speed, SpeedCalculation_001)
{
	left_motor_trav_dist_hi_acc = 1000; 
	right_motor_trav_dist_hi_acc = 2000;
	left_motor_trav_dist_hi_acc_prev = 500;
	right_motor_trav_dist_hi_acc_prev = 1000;


    calc_travel_speed();
    // left_speed, right_speed の計算結果を検証
    // (1000-500)/2/10 = 25, (2000-1000)/2/10 = 50
    EXPECT_EQ(left_speed, 25);
    EXPECT_EQ(right_speed, 50);
    EXPECT_EQ(left_motor_trav_dist_hi_acc_prev, 1000);
    EXPECT_EQ(right_motor_trav_dist_hi_acc_prev, 2000);
}

TEST_F(TravelSpeed_calc_travel_speed, SpeedCalculation_002)
{
	left_motor_trav_dist_hi_acc = 0;
	right_motor_trav_dist_hi_acc = 0;
	left_motor_trav_dist_hi_acc_prev = 0;
	right_motor_trav_dist_hi_acc_prev = 0;


    calc_travel_speed();
    // left_speed, right_speed の計算結果を検証
    // (1000-500)/2/10 = 25, (2000-1000)/2/10 = 50
    EXPECT_EQ(left_speed, 0);
    EXPECT_EQ(right_speed, 0);
    EXPECT_EQ(left_motor_trav_dist_hi_acc_prev, 0);
    EXPECT_EQ(right_motor_trav_dist_hi_acc_prev, 0);
}

TEST_F(TravelSpeed_calc_travel_speed, SpeedCalculation_003)
{
	left_motor_trav_dist_hi_acc = 1;
	right_motor_trav_dist_hi_acc = 1;
	left_motor_trav_dist_hi_acc_prev = 0;
	right_motor_trav_dist_hi_acc_prev = 0;


    calc_travel_speed();
    // left_speed, right_speed の計算結果を検証
    // (1000-500)/2/10 = 25, (2000-1000)/2/10 = 50
    EXPECT_EQ(left_speed, 0);
    EXPECT_EQ(right_speed, 0);
    EXPECT_EQ(left_motor_trav_dist_hi_acc_prev, 1);
    EXPECT_EQ(right_motor_trav_dist_hi_acc_prev, 1);
}

TEST_F(TravelSpeed_calc_travel_speed, SpeedCalculation_004)
{
	left_motor_trav_dist_hi_acc = 19;
	right_motor_trav_dist_hi_acc = 19;
	left_motor_trav_dist_hi_acc_prev = 0;
	right_motor_trav_dist_hi_acc_prev = 0;


    calc_travel_speed();
    // left_speed, right_speed の計算結果を検証
    // (1000-500)/2/10 = 25, (2000-1000)/2/10 = 50
    EXPECT_EQ(left_speed, 0);
    EXPECT_EQ(right_speed, 0);
    EXPECT_EQ(left_motor_trav_dist_hi_acc_prev, 19);
    EXPECT_EQ(right_motor_trav_dist_hi_acc_prev, 19);
}

TEST_F(TravelSpeed_calc_travel_speed, SpeedCalculation_005)
{
	left_motor_trav_dist_hi_acc = 20;
	right_motor_trav_dist_hi_acc = 20;
	left_motor_trav_dist_hi_acc_prev = 0;
	right_motor_trav_dist_hi_acc_prev = 0;


    calc_travel_speed();
    // left_speed, right_speed の計算結果を検証
    // (1000-500)/2/10 = 25, (2000-1000)/2/10 = 50
    EXPECT_EQ(left_speed, 1);
    EXPECT_EQ(right_speed, 1);
    EXPECT_EQ(left_motor_trav_dist_hi_acc_prev, 20);
    EXPECT_EQ(right_motor_trav_dist_hi_acc_prev, 20);
}

TEST_F(TravelSpeed_calc_travel_speed, SpeedCalculation_006)
{
	left_motor_trav_dist_hi_acc = -1;
	right_motor_trav_dist_hi_acc = -1;
	left_motor_trav_dist_hi_acc_prev = 0;
	right_motor_trav_dist_hi_acc_prev = 0;


    calc_travel_speed();
    // left_speed, right_speed の計算結果を検証
    // (1000-500)/2/10 = 25, (2000-1000)/2/10 = 50
    EXPECT_EQ(left_speed, 0);
    EXPECT_EQ(right_speed, 0);
    EXPECT_EQ(left_motor_trav_dist_hi_acc_prev, -1);
    EXPECT_EQ(right_motor_trav_dist_hi_acc_prev, -1);
}

TEST_F(TravelSpeed_calc_travel_speed, SpeedCalculation_007)
{
	left_motor_trav_dist_hi_acc = -19;
	right_motor_trav_dist_hi_acc = -19;
	left_motor_trav_dist_hi_acc_prev = 0;
	right_motor_trav_dist_hi_acc_prev = 0;


    calc_travel_speed();
    // left_speed, right_speed の計算結果を検証
    // (1000-500)/2/10 = 25, (2000-1000)/2/10 = 50
    EXPECT_EQ(left_speed, 0);
    EXPECT_EQ(right_speed, 0);
    EXPECT_EQ(left_motor_trav_dist_hi_acc_prev, -19);
    EXPECT_EQ(right_motor_trav_dist_hi_acc_prev, -19);
}

TEST_F(TravelSpeed_calc_travel_speed, SpeedCalculation_008)
{
	left_motor_trav_dist_hi_acc = -20;
	right_motor_trav_dist_hi_acc = -20;
	left_motor_trav_dist_hi_acc_prev = 0;
	right_motor_trav_dist_hi_acc_prev = 0;


    calc_travel_speed();
    // left_speed, right_speed の計算結果を検証
    // (1000-500)/2/10 = 25, (2000-1000)/2/10 = 50
    EXPECT_EQ(left_speed, -1);
    EXPECT_EQ(right_speed, -1);
    EXPECT_EQ(left_motor_trav_dist_hi_acc_prev, -20);
    EXPECT_EQ(right_motor_trav_dist_hi_acc_prev, -20);
}

TEST_F(TravelSpeed_calc_travel_speed, SpeedCalculation_009)
{
	left_motor_trav_dist_hi_acc = 21;
	right_motor_trav_dist_hi_acc = 21;
	left_motor_trav_dist_hi_acc_prev = 0;
	right_motor_trav_dist_hi_acc_prev = 0;


    calc_travel_speed();
    // left_speed, right_speed の計算結果を検証
    // (1000-500)/2/10 = 25, (2000-1000)/2/10 = 50
    EXPECT_EQ(left_speed, 1);
    EXPECT_EQ(right_speed, 1);
    EXPECT_EQ(left_motor_trav_dist_hi_acc_prev, 21);
    EXPECT_EQ(right_motor_trav_dist_hi_acc_prev, 21);
}

TEST_F(TravelSpeed_calc_travel_speed, SpeedCalculation_010)
{
	left_motor_trav_dist_hi_acc = -21;
	right_motor_trav_dist_hi_acc = -21;
	left_motor_trav_dist_hi_acc_prev = 0;
	right_motor_trav_dist_hi_acc_prev = 0;


    calc_travel_speed();
    // left_speed, right_speed の計算結果を検証
    // (1000-500)/2/10 = 25, (2000-1000)/2/10 = 50
    EXPECT_EQ(left_speed, -1);
    EXPECT_EQ(right_speed, -1);
    EXPECT_EQ(left_motor_trav_dist_hi_acc_prev, -21);
    EXPECT_EQ(right_motor_trav_dist_hi_acc_prev, -21);
}

TEST_F(TravelSpeed_calc_travel_speed, SpeedCalculation_011)
{
	left_motor_trav_dist_hi_acc = 0x7FFFFFFF; // 例: 10.00mm
	right_motor_trav_dist_hi_acc = 0x7FFFFFFF; // 例: 20.00mm
	left_motor_trav_dist_hi_acc_prev = 0; // 例: 5.00mm
	right_motor_trav_dist_hi_acc_prev = 0; // 例: 10.00mm


    calc_travel_speed();
    // left_speed, right_speed の計算結果を検証
    // (1000-500)/2/10 = 25, (2000-1000)/2/10 = 50
    EXPECT_EQ(left_speed, 0x6666);
    EXPECT_EQ(right_speed, 0x6666);
    EXPECT_EQ(left_motor_trav_dist_hi_acc_prev, 0x7FFFFFFF);
    EXPECT_EQ(right_motor_trav_dist_hi_acc_prev, 0x7FFFFFFF);
}

TEST_F(TravelSpeed_calc_travel_speed, SpeedCalculation_021)
{
	left_motor_trav_dist_hi_acc = 21;
	right_motor_trav_dist_hi_acc = -21;
	left_motor_trav_dist_hi_acc_prev = 0;
	right_motor_trav_dist_hi_acc_prev = 0;


    calc_travel_speed();
    // left_speed, right_speed の計算結果を検証
    // (1000-500)/2/10 = 25, (2000-1000)/2/10 = 50
    EXPECT_EQ(left_speed, 1);
    EXPECT_EQ(right_speed, -1);
    EXPECT_EQ(left_motor_trav_dist_hi_acc_prev, 21);
    EXPECT_EQ(right_motor_trav_dist_hi_acc_prev, -21);
}

TEST_F(TravelSpeed_calc_travel_speed, SpeedCalculation_022)
{
	left_motor_trav_dist_hi_acc = -21;
	right_motor_trav_dist_hi_acc = 21;
	left_motor_trav_dist_hi_acc_prev = 0;
	right_motor_trav_dist_hi_acc_prev = 0;


    calc_travel_speed();
    // left_speed, right_speed の計算結果を検証
    // (1000-500)/2/10 = 25, (2000-1000)/2/10 = 50
    EXPECT_EQ(left_speed, -1);
    EXPECT_EQ(right_speed, 1);
    EXPECT_EQ(left_motor_trav_dist_hi_acc_prev, -21);
    EXPECT_EQ(right_motor_trav_dist_hi_acc_prev, 21);
}

TEST_F(TravelSpeed_calc_travel_speed, SpeedCalculation_023)
{
	left_motor_trav_dist_hi_acc = 21;
	right_motor_trav_dist_hi_acc = -21;
	left_motor_trav_dist_hi_acc_prev = -1;
	right_motor_trav_dist_hi_acc_prev = 1;


    calc_travel_speed();
    // left_speed, right_speed の計算結果を検証
    // (1000-500)/2/10 = 25, (2000-1000)/2/10 = 50
    EXPECT_EQ(left_speed, 1);
    EXPECT_EQ(right_speed, -1);
    EXPECT_EQ(left_motor_trav_dist_hi_acc_prev, 21);
    EXPECT_EQ(right_motor_trav_dist_hi_acc_prev, -21);
}

TEST_F(TravelSpeed_calc_travel_speed, SpeedCalculation_024)
{
	left_motor_trav_dist_hi_acc = 21;
	right_motor_trav_dist_hi_acc = -21;
	left_motor_trav_dist_hi_acc_prev = 2;
	right_motor_trav_dist_hi_acc_prev = -2;


    calc_travel_speed();
    // left_speed, right_speed の計算結果を検証
    // (1000-500)/2/10 = 25, (2000-1000)/2/10 = 50
    EXPECT_EQ(left_speed, 0);
    EXPECT_EQ(right_speed, 0);
    EXPECT_EQ(left_motor_trav_dist_hi_acc_prev, 21);
    EXPECT_EQ(right_motor_trav_dist_hi_acc_prev, -21);
}

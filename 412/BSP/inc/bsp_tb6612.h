/*
 * 立创开发板软硬件资料与相关扩展板软硬件资料官网全部开源
 * 开发板官网：www.lckfb.com
 * 文档网站：wiki.lckfb.com
 * 技术支持常驻论坛，任何技术问题欢迎随时交流学习
 * 嘉立创社区问答：https://www.jlc-bbs.com/lckfb
 * 关注bilibili账号：【立创开发板】，掌握我们的最新动态！
 * 不靠卖板赚钱，以培养中国工程师为己任
 */

#ifndef _BSP_TB6612_H
#define _BSP_TB6612_H

#include "board.h"

typedef enum {
    STATE_1,
    STATE_2,
    STATE_3,
    STATE_4,
    STATE_5,
    STATE_6,
} State_t;

volatile  State_t currentState ;

typedef enum {
    FOLLOW,     // 循迹模式
    TURN,       // 转弯模式
    STOP        // 停车
} CarState;

volatile CarState carState ;  // 初始状态为循迹模式

#define AIN1_OUT(X)  ( (X) ? (DL_GPIO_setPins(TB6612_PORT,TB6612_AIN1_PIN)) : (DL_GPIO_clearPins(TB6612_PORT,TB6612_AIN1_PIN)) )
#define AIN2_OUT(X)  ( (X) ? (DL_GPIO_setPins(TB6612_PORT,TB6612_AIN2_PIN)) : (DL_GPIO_clearPins(TB6612_PORT,TB6612_AIN2_PIN)) )

#define BIN1_OUT(X)  ( (X) ? (DL_GPIO_setPins(TB6612_PORT,TB6612_BIN1_PIN)) : (DL_GPIO_clearPins(TB6612_PORT,TB6612_BIN1_PIN)) )
#define BIN2_OUT(X)  ( (X) ? (DL_GPIO_setPins(TB6612_PORT,TB6612_BIN2_PIN)) : (DL_GPIO_clearPins(TB6612_PORT,TB6612_BIN2_PIN)) )


void TB6612_Motor_Stop(void);
void AO_Control(uint8_t dir, uint32_t speed);
void BO_Control(uint8_t dir, uint32_t speed);

void car_forward(int speed_a, int speed_b);
void car_backward(int speed);
void car_right(int speed);
void car_left(int speed);

int sensor_A_judge(void);
int sensor_B_judge(void);
int sensor_C_judge(void);
int sensor_D_judge(void);
int sensor_L_judge(void);
int sensor_R_judge(void);

void Hunting(void);
void handleState(void);

#endif  /* _BSP_TB6612_H */

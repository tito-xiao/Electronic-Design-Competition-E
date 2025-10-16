/*
 * 立创开发板软硬件资料与相关扩展板软硬件资料官网全部开源
 * 开发板官网：www.lckfb.com
 * 文档网站：wiki.lckfb.com
 * 技术支持常驻论坛，任何技术问题欢迎随时交流学习
 * 嘉立创社区问答：https://www.jlc-bbs.com/lckfb
 * 关注bilibili账号：【立创开发板】，掌握我们的最新动态！
 * 不靠卖板赚钱，以培养中国工程师为己任
 */
#include "bsp_tb6612.h"
#include "board.h"

int sensor_A = 0, sensor_B = 0, sensor_C = 0, sensor_D = 0, sensor_L = 0, sensor_R = 0;
int count = 0;  // 转弯计数

/******************************************************************
 * 函 数 名 称：TB6612_Motor_Stop
 * 函 数 说 明：A端和B端电机停止
 * 函 数 形 参：无
 * 函 数 返 回：无
 * 作       者：LCKFB
 * 备       注：无
******************************************************************/
void TB6612_Motor_Stop(void)
{
    AIN1_OUT(1);
    AIN2_OUT(1);
    BIN1_OUT(1);
    BIN2_OUT(1);
}

/******************************************************************
 * 函 数 名 称：AO_Control
 * 函 数 说 明：A端口电机控制
 * 函 数 形 参：dir旋转方向 1正转0反转   speed旋转速度，范围（0 ~ per-1）
 * 函 数 返 回：无
 * 作       者：LCKFB
 * 备       注：speed 0-1000
******************************************************************/
void AO_Control(uint8_t dir, uint32_t speed)
{
    if(speed > 999 || dir > 1)
    {
        lc_printf("\nAO_Control parameter error!!!\r\n");
        return;
    }

    if( dir == 1 )
    {
        AIN1_OUT(0);
        AIN2_OUT(1);
    }
    else
    {
        AIN1_OUT(1);
        AIN2_OUT(0);
    }

    DL_TimerG_setCaptureCompareValue(PWM_0_INST, speed, GPIO_PWM_0_C1_IDX);
}



/******************************************************************
 * 函 数 名 称：BO_Control
 * 函 数 说 明：B端口电机控制
 * 函 数 形 参：dir旋转方向 1正转0反转   speed旋转速度，范围（0 ~ per-1）
 * 函 数 返 回：无
 * 作       者：LCKFB
 * 备       注：speed 0-1000
******************************************************************/
void BO_Control(uint8_t dir, uint32_t speed)
{
    if(speed > 999 || dir > 1)
    {
        lc_printf("\nAO_Control parameter error!!!\r\n");
        return;
    }

    if( dir == 1 )
    {
        BIN1_OUT(0);
        BIN2_OUT(1);
    }
    else
    {
        BIN1_OUT(1);
        BIN2_OUT(0);
    }

    DL_TimerG_setCaptureCompareValue(PWM_0_INST, speed, GPIO_PWM_0_C0_IDX);
}

/******************************************************************/
void car_forward(int speed_a, int speed_b) {
    AO_Control(1, speed_a); // A端电机转动 速度最大1000
    BO_Control(1, speed_b); // B端电机转动 速度最大1000
}

void car_backward(int speed) {
    AO_Control(0, speed); // A端电机转动 速度最大1000
    BO_Control(0, speed); // B端电机转动 速度最大1000
}

void car_right(int speed) {
    AO_Control(1, speed); // A端电机转动 速度最大1000
    BO_Control(0, speed); // B端电机转动 速度最大1000
}

void car_left(int speed) {
    AO_Control(0, speed); // A端电机转动 速度最大1000
    BO_Control(1, speed); // B端电机转动 速度最大1000
}

int sensor_A_judge(void) {
    int a;
    if (DL_GPIO_readPins(SENSOR_PORT, SENSOR_A_PIN) == 0) {  //读取电平
        a = 0;
    } else {
        a = 1;
    }
    return a;
}

int sensor_B_judge(void) {
    int a;
    if (DL_GPIO_readPins(SENSOR_PORT, SENSOR_B_PIN) == 0) {  //读取电平
        a = 0;
    } else {
        a = 1;
    }
    return a;
}

int sensor_C_judge(void) {
    int a;
    if (DL_GPIO_readPins(SENSOR_PORT, SENSOR_C_PIN) == 0) {  //读取电平
        a = 0;
    } else {
        a = 1;
    }
    return a;
}

int sensor_D_judge(void) {
    int a;
    if (DL_GPIO_readPins(SENSOR_PORT, SENSOR_D_PIN) == 0) {  //读取电平
        a = 0;
    } else {
        a = 1;
    }
    return a;
}

int sensor_L_judge(void) {
    int a;
    if (DL_GPIO_readPins(SENSOR2_PORT, SENSOR2_L_PIN) == 0) {  //读取电平
        a = 1;
    } else {
        a = 0;
    }
    return a;
}
int sensor_R_judge(void) {
    int a;
    if (DL_GPIO_readPins(SENSOR2_PORT, SENSOR2_R_PIN) == 0) {  //读取电平
        a = 1;
    } else {
        a = 0;
    }
    return a;
}

/******************************************************************/

void Hunting(void){

        sensor_A = sensor_A_judge();
        sensor_B = sensor_B_judge();
        sensor_C = sensor_C_judge();
        sensor_D = sensor_D_judge();
        sensor_L = sensor_L_judge();
        sensor_R = sensor_R_judge();
        // delay_cycles(3200000);

        switch(carState) {
        case FOLLOW:
            // 根据偏差调整转向
            if (sensor_A==1 && sensor_B==0 && sensor_C==0 && sensor_D==0 && sensor_L==0 && sensor_R==0) {  // 严重偏右
                car_forward(0, 400);
            } else if (sensor_A==1 && sensor_B==1 && sensor_C==0 && sensor_D==0 && sensor_L==0 && sensor_R==0) {  // 中等偏右
                car_forward(240, 300);
            } else if (sensor_A==0 && sensor_B==1 && sensor_C==0 && sensor_D==0 && sensor_L==0 && sensor_R==0) {  // 轻微偏右
                car_forward(240, 280);
            } else if (sensor_A==0 && sensor_B==1 && sensor_C==1 && sensor_D==0 && sensor_L==0 && sensor_R==0) {  // 居中直行
                car_forward(350, 350);
            } else if (sensor_A==0 && sensor_B==0 && sensor_C==1 && sensor_D==0 && sensor_L==0 && sensor_R==0) {  // 轻微偏左
                car_forward(280, 240);
            } else if (sensor_A==0 && sensor_B==0 && sensor_C==1 && sensor_D==1 && sensor_L==0 && sensor_R==0) {  // 中等偏左
                car_forward(300, 240);
            } else if (sensor_A==0 && sensor_B==0 && sensor_C==0 && sensor_D==1 && sensor_L==0 && sensor_R==0) {  // 严重偏左
                car_forward(300, 240);
            } else if (sensor_A==1 && sensor_B==1 && sensor_C==1 && sensor_D==1 && sensor_L==0 && sensor_R==0) {  // 慢慢找线
                car_forward(0, 0);
            } else if (sensor_A==0 && sensor_B==0 && sensor_C==0 && sensor_D==0 && sensor_L==0 && sensor_R==0) {  // 停车
                car_forward(350, 350);
            } else if (sensor_L==1 && sensor_R==1) {  // 左转
                delay_ms(240);
                carState = TURN;
                count += 1;  // 直角数+1
            }
            // delay_ms(10);
        break;

        case TURN:
            car_left(140);
            if (sensor_B==1 && sensor_C==1) {
                carState = FOLLOW;
                // if (count == 2) {
                //     carState = STOP;
                // }
            }
        break;

        case STOP:
            car_forward(0, 0);
        break;
        }
}

void handleState(void) {
    switch (currentState) {
        case STATE_1:
            lc_printf("111111");
            break;
        case STATE_2:
            lc_printf("222222");
            break;
        case STATE_3:
            lc_printf("333333");
            break;
        case STATE_4:
            lc_printf("444444");
            break;
        case STATE_5:
            lc_printf("555555");
            break;
        case STATE_6:
            lc_printf("666666");
            break;
        default:
            currentState = STATE_6;
            break;
    }
}
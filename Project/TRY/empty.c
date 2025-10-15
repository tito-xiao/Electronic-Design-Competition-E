#include "ti_msp_dl_config.h"
#include "board.h"
#include "bsp_tb6612.h"

int16_t R = 0;
int16_t num_R = 0;
int16_t speed_R = 0;

int16_t L = 0;
int16_t num_L = 0;
int16_t speed_L = 0;

int16_t Get_Mileage_R(void)
{
    int16_t temp;
    temp = R;
    R = 0 ;
    return temp;
}

int16_t Get_Mileage_L(void)
{
    int16_t temp;
    temp = L;
    L = 0 ;
    return temp;
}

int16_t Get_Speed_R(void)
{
    int16_t temp;
    temp = R;
    return temp;
}

int16_t Get_Speed_L(void)
{
    int16_t temp;
    temp = L;
    return temp;
}

int main(void)
{
    SYSCFG_DL_init();
    NVIC_ClearPendingIRQ(TIMER_0_INST_INT_IRQN);
    //使能定时器中断
    NVIC_EnableIRQ(TIMER_0_INST_INT_IRQN);
    NVIC_EnableIRQ(ENCODER1A_INT_IRQN);//开启按键引脚的GPIOA端口中断

    TB6612_Motor_Stop();

    lc_printf("\nTB6612 Motor Demo Start...\r\n");

    while (1) 
    {
        for(int i = 0; i < 1000; i += 50)
        {
            AO_Control(1, i);// A端电机转动 速度最大1000
            BO_Control(1, i);// B端电机转动 速度最大1000

            // lc_printf("Dir[ 1 ]   i[ %d ]\r\n",i);
            // lc_printf("num: %d   \r\n", num_R );
            lc_printf("speed_R: %d   \r\n", speed_R );
            lc_printf("speed_L: %d   \r\n", speed_L );
            delay_ms(200);
        }
        TB6612_Motor_Stop(); // 停止转动
        delay_ms(1000);

        for(int i = 0; i < 1000; i += 50)
        {
            AO_Control(0, i);// A端电机转动 速度最大1000
            BO_Control(0, i);// B端电机转动 速度最大1000

            // lc_printf("Dir[ 0 ]   i[ %d ]\r\n",i);
            // lc_printf("num: %d   \r\n", num_R );
            lc_printf("speed_R: %d   \r\n", speed_R );
            lc_printf("speed_L: %d   \r\n", speed_L );
            delay_ms(200);
        }
        TB6612_Motor_Stop(); // 停止转动
        delay_ms(1000);
        num_R += Get_Mileage_R();
        lc_printf("num_R: %d   \r\n", num_R );
        lc_printf("num_L: %d   \r\n", num_L );
        //delay_cycles(3200000);  
    }
}

void GROUP1_IRQHandler(void)//Group1的中断服务函数
{
    //读取Group1的中断寄存器并清除中断标志位
    switch( DL_Interrupt_getPendingGroup(DL_INTERRUPT_GROUP_1) )
    {
       // 检查是否是KEY的GPIOB端口中断，注意是INT_IIDX，不是PIN_22_IIDX
        case ENCODER1A_INT_IIDX:
            if (DL_GPIO_getEnabledInterruptStatus(ENCODER1A_PORT, ENCODER1A_A_PIN))
            {
                if(DL_GPIO_readPins(ENCODER1B_PORT, ENCODER1B_B_PIN) == 0)
                {
                    R++;
                }
                else 
                {
                    R--;
                }
                DL_GPIO_clearInterruptStatus(ENCODER1A_PORT, ENCODER1A_A_PIN);
                NVIC_ClearPendingIRQ(ENCODER1A_INT_IRQN);
            }

        break;
        case ENCODER2A_INT_IIDX:
            if (DL_GPIO_getEnabledInterruptStatus(ENCODER2A_PORT, ENCODER2A_A2_PIN))
            {
                if(DL_GPIO_readPins(ENCODER2B_PORT, ENCODER2B_B2_PIN) == 0)
                {
                    L++;
                }
                else 
                {
                    L--;
                }
                DL_GPIO_clearInterruptStatus(ENCODER2A_PORT, ENCODER2A_A2_PIN);
                NVIC_ClearPendingIRQ(ENCODER2A_INT_IRQN);
            }

        break;

    }
}


//定时器的中断服务函数 已配置为1秒的周期
void TIMER_0_INST_IRQHandler(void)
{
    //如果产生了定时器中断
    switch( DL_TimerG_getPendingInterrupt(TIMER_0_INST) )
    {
        case DL_TIMER_IIDX_ZERO://如果是0溢出中断
            //将LED灯的状态翻转
            DL_GPIO_togglePins(LED1_PORT, LED1_PIN_22_PIN);
            speed_R = Get_Speed_R();
            speed_L = Get_Speed_L();
            break;

        default://其他的定时器中断
            break;
    }
}




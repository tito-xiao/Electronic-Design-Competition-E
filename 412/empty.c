#include "ti_msp_dl_config.h"
#include "board.h"
#include "bsp_tb6612.h"

int16_t R = 0;
int16_t num_R = 0;

int16_t L = 0;
int16_t num_L = 0;

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

int main(void)
{
    SYSCFG_DL_init();
    NVIC_EnableIRQ(GPIO_MULTIPLE_GPIOA_INT_IRQN);
    NVIC_EnableIRQ(GPIO_MULTIPLE_GPIOB_INT_IRQN);//开启按键引脚的GPIOA端口中断
    TB6612_Motor_Stop();
    currentState = STATE_6;
    carState = FOLLOW;

    while (1)
    {
        // handleState();
        Hunting();
        // car_forward(400, 400);
        // num_R += Get_Mileage_R();
        // num_L += Get_Mileage_L();
        // lc_printf("num_R: %d   ", num_R );
        // lc_printf("num_L: %d   \r\n", num_L );
    }
}


void GROUP1_IRQHandler(void)//Group1的中断服务函数
{
    //读取Group1的中断寄存器并清除中断标志位
    switch( DL_Interrupt_getPendingGroup(DL_INTERRUPT_GROUP_1) )
    {
        case GPIO_MULTIPLE_GPIOA_INT_IIDX:
            //如果按键按下变为高电平
            if( DL_GPIO_readPins(KEY_KEY1_PORT, KEY_KEY1_PIN) == 0 )
            {
                // delay_ms(50);
                // while( DL_GPIO_readPins(KEY_KEY1_PORT, KEY_KEY1_PIN) == 0 );
                // delay_ms(50);
                currentState = STATE_1;
            }
            else if ( DL_GPIO_readPins(KEY_KEY2_PORT, KEY_KEY2_PIN) == 0 )
            {
                // delay_ms(50);
                // while( DL_GPIO_readPins(KEY_KEY2_PORT, KEY_KEY2_PIN) == 0 );
                // delay_ms(50);
                currentState = STATE_2;
            }
            else if ( DL_GPIO_readPins(KEY_KEY3_PORT, KEY_KEY3_PIN) == 0 )
            {
                // delay_ms(50);
                // while( DL_GPIO_readPins(KEY_KEY3_PORT, KEY_KEY3_PIN) == 0 );
                // delay_ms(50);
                currentState = STATE_3;
            }
            else if ( DL_GPIO_readPins(KEY_KEY4_PORT, KEY_KEY4_PIN) == 0 )
            {
                // delay_ms(50);
                // while( DL_GPIO_readPins(KEY_KEY4_PORT, KEY_KEY4_PIN) == 0 );
                // delay_ms(50);
                currentState = STATE_4;
            }
            else if (DL_GPIO_getEnabledInterruptStatus(ENCODER1A_PORT, ENCODER1A_A1_PIN))
            {
                if(DL_GPIO_readPins(ENCODER1B_PORT, ENCODER1B_B1_PIN) == 0)
                {
                    R++;
                }
                else 
                DL_GPIO_clearInterruptStatus(ENCODER1A_PORT, ENCODER1A_A1_PIN);
                NVIC_ClearPendingIRQ(GPIO_MULTIPLE_GPIOA_INT_IRQN);
            }

        break;

        case GPIO_MULTIPLE_GPIOB_INT_IIDX:
            if( DL_GPIO_readPins(KEY_KEY5_PORT, KEY_KEY5_PIN) == 0 )
            {
                currentState = STATE_5;

            }
            else if ( DL_GPIO_readPins(KEY_KEY6_PORT, KEY_KEY6_PIN) == 0 )
            {
                currentState = STATE_6;
            }
            else if (DL_GPIO_getEnabledInterruptStatus(ENCODER2A_PORT, ENCODER2A_A2_PIN))
            {
                if(DL_GPIO_readPins(ENCODER2B_PORT, ENCODER2B_B2_PIN) == 0)
                {
                    L--;
                }
                else 
                {
                    L++;
                }
                DL_GPIO_clearInterruptStatus(ENCODER2A_PORT, ENCODER2A_A2_PIN);
                NVIC_ClearPendingIRQ(GPIO_MULTIPLE_GPIOB_INT_IRQN);
            } 
        break;
    }
}

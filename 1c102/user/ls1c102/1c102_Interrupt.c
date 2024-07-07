#include "ls1x.h"
#include "ls1x_gpio.h"
#include "ls1x_wdg.h"
#include "ls1x_common.h"
#include "ls1x_exti.h"
#include "ls1c102_interrupt.h"
#include "ls1c102_touch.h"
#include "ls1c102_ptimer.h"
#include "ls1c102_i2c.h"
#include "ls1x_uart.h"
#include "Config.h"


#define	BEBUG_IRQ()  printf("\r\n < IRQ: %d func:%s   >\r\n",__LINE__,__FUNCTION__)
void (* const exti_irq_handle[32])(void);

void exti_gpioa0_irq_handler(void)
{
    BEBUG_IRQ();
    EXTI_ClearITPendingBit(EXTI, IRQ_GPIO_A0);
}
void exti_gpioa1_irq_handler(void)
{
    BEBUG_IRQ();
    EXTI_ClearITPendingBit(EXTI, IRQ_GPIO_A1);
}
void exti_gpioa2_irq_handler(void)
{
    BEBUG_IRQ();
    EXTI_ClearITPendingBit(EXTI, IRQ_GPIO_A2);
}
void exti_gpioa3_irq_handler(void)
{
    BEBUG_IRQ();
    EXTI_ClearITPendingBit(EXTI, IRQ_GPIO_A3);
}
void exti_gpioa4_irq_handler(void)
{
    BEBUG_IRQ();
    EXTI_ClearITPendingBit(EXTI, IRQ_GPIO_A4);
}
void exti_gpioa5_irq_handler(void)
{
    BEBUG_IRQ();
    EXTI_ClearITPendingBit(EXTI, IRQ_GPIO_A5);
}
void exti_gpioa6_irq_handler(void)
{
    BEBUG_IRQ();
    EXTI_ClearITPendingBit(EXTI, IRQ_GPIO_A6);
}
void exti_gpioa7_irq_handler(void)
{
    BEBUG_IRQ();
    EXTI_ClearITPendingBit(EXTI, IRQ_GPIO_A7);
}
void exti_gpiob0_irq_handler(void)
{
    BEBUG_IRQ();
    EXTI_ClearITPendingBit(EXTI, IRQ_GPIO_B0);
}
void exti_gpiob1_irq_handler(void)
{
    BEBUG_IRQ();
    EXTI_ClearITPendingBit(EXTI, IRQ_GPIO_B1);
}
void exti_gpiob2_irq_handler(void)
{
    BEBUG_IRQ();
    EXTI_ClearITPendingBit(EXTI, IRQ_GPIO_B2);
}
void exti_gpiob3_irq_handler(void)
{
    BEBUG_IRQ();
    EXTI_ClearITPendingBit(EXTI, IRQ_GPIO_B3);
}
void exti_gpiob4_irq_handler(void)
{
    BEBUG_IRQ();
    EXTI_ClearITPendingBit(EXTI, IRQ_GPIO_B4);
}
void exti_gpiob5_irq_handler(void)
{
    BEBUG_IRQ();
    EXTI_ClearITPendingBit(EXTI, IRQ_GPIO_B5);
}
void exti_gpiob6_irq_handler(void)
{
    BEBUG_IRQ();
    EXTI_ClearITPendingBit(EXTI, IRQ_GPIO_B6);
}
void exti_gpiob7_irq_handler(void)
{
    BEBUG_IRQ();
    EXTI_ClearITPendingBit(EXTI, IRQ_GPIO_B7);
}

void exti_gpioc0_irq_handler(void)
{
    BEBUG_IRQ();
    EXTI_ClearITPendingBit(EXTI, IRQ_GPIO_C0);
}
void exti_gpioc1_irq_handler(void)
{
    BEBUG_IRQ();
    EXTI_ClearITPendingBit(EXTI, IRQ_GPIO_C1);
}
void exti_gpioc2_irq_handler(void)
{
    BEBUG_IRQ();
    EXTI_ClearITPendingBit(EXTI, IRQ_GPIO_C2);
}
void exti_gpioc3_irq_handler(void)
{
    BEBUG_IRQ();
    EXTI_ClearITPendingBit(EXTI, IRQ_GPIO_C3);
}
void exti_gpioc4_irq_handler(void)
{
    BEBUG_IRQ();
    EXTI_ClearITPendingBit(EXTI, IRQ_GPIO_C4);
}
void exti_gpioc5_irq_handler(void)
{
    BEBUG_IRQ();
    EXTI_ClearITPendingBit(EXTI, IRQ_GPIO_C5);
}
void exti_gpioc6_irq_handler(void)
{
    BEBUG_IRQ();
    EXTI_ClearITPendingBit(EXTI, IRQ_GPIO_C6);
}
void exti_gpioc7_irq_handler(void)
{
    BEBUG_IRQ();
    EXTI_ClearITPendingBit(EXTI, IRQ_GPIO_C7);
}
void exti_gpiod0_irq_handler(void)
{
    BEBUG_IRQ();
    EXTI_ClearITPendingBit(EXTI, IRQ_GPIO_D0);
}
void exti_gpiod1_irq_handler(void)
{
    BEBUG_IRQ();
    EXTI_ClearITPendingBit(EXTI, IRQ_GPIO_D1);
}
void exti_gpiod2_irq_handler(void)
{
    BEBUG_IRQ();
    EXTI_ClearITPendingBit(EXTI, IRQ_GPIO_D2);
}
void exti_gpiod3_irq_handler(void)
{
    BEBUG_IRQ();
    EXTI_ClearITPendingBit(EXTI, IRQ_GPIO_D3);
}
void exti_gpiod4_irq_handler(void)
{
    BEBUG_IRQ();
    EXTI_ClearITPendingBit(EXTI, IRQ_GPIO_D4);
}

void exti_gpiod5_irq_handler(void)
{
    BEBUG_IRQ();
    EXTI_ClearITPendingBit(EXTI, IRQ_GPIO_D5);
}
void exti_gpiod6_irq_handler(void)
{
    BEBUG_IRQ();
    EXTI_ClearITPendingBit(EXTI, IRQ_GPIO_D6);
}
void exti_gpiod7_irq_handler(void)
{
    BEBUG_IRQ();
    EXTI_ClearITPendingBit(EXTI, IRQ_GPIO_D7);
}
void (* const Ext_IrqHandle[32])(void) =
{
    exti_gpioa0_irq_handler,
    exti_gpioa1_irq_handler,
    exti_gpioa2_irq_handler,
    exti_gpioa3_irq_handler,
    exti_gpioa4_irq_handler,
    exti_gpioa5_irq_handler,
    exti_gpioa6_irq_handler,
    exti_gpioa7_irq_handler,
    exti_gpiob0_irq_handler,
    exti_gpiob1_irq_handler,
    exti_gpiob2_irq_handler,
    exti_gpiob3_irq_handler,
    exti_gpiob4_irq_handler,
    exti_gpiob5_irq_handler,
    exti_gpiob6_irq_handler,
    exti_gpiob7_irq_handler,
    exti_gpioc0_irq_handler,
    exti_gpioc1_irq_handler,
    exti_gpioc2_irq_handler,
    exti_gpioc3_irq_handler,
    exti_gpioc4_irq_handler,
    exti_gpioc5_irq_handler,
    exti_gpioc6_irq_handler,
    exti_gpioc7_irq_handler,
    exti_gpiod0_irq_handler,
    exti_gpiod1_irq_handler,
    exti_gpiod2_irq_handler,
    exti_gpiod3_irq_handler,
    exti_gpiod4_irq_handler,
    exti_gpiod5_irq_handler,
    exti_gpiod6_irq_handler,
    exti_gpiod7_irq_handler,
};

void ext_handler(void)
{
    PMU_CMDW = (1 << 24);
    INT32U regsrc;// = EXTI->EXINT_SRC;
    INT32U regen;// = EXTI->EXINT_SRC;
    INT32U irq_no;
    //BEBUG_IRQ();
    regsrc = EXTI->EXINT_SRC;
    regen = EXTI->EXINT_EN;
    regsrc = (regsrc & regen);
    asm("nop");

    for(irq_no = 0; irq_no < 32; irq_no++)
    {
        if((regsrc>>irq_no) & 0x1)
        {
            Ext_IrqHandle[irq_no]();
        }
    }
}

void SOFT_INT(void)
{
    printf("\n.............SOFT_INT..............\n\r");
    Set_soft_stop();
}

/***********************************************************************
 函数功能:    	8M定时器中断处理函数
 @param:		无
 @other:     无
 @return:	无
 @auther :	朱晓宇
 @time	:	2020年4月9日
 ***********************************************************************/
void TIMER_8M_INT(void)
{
    PMU_CMDW = (1 << 21); // 清除中断标志
    Set_Timer_clear();
    Set_Timer_Init(8 * 10000); //  1.25ms
}

/***********************************************************************
 函数功能:    	定时唤醒中断处理函数
 @param:		无
 @other:     睡眠下定时喂狗，防止系统复位
 @return:	无
 @auther :	朱晓宇
 @time	:	2020年4月9日
 ***********************************************************************/
void TIMER_WAKE_INT(void)
{
    //printf("TIMER_WAKE_INT feed WDG!\n\r");
    PMU_CMDW = (1 << 16); // 清除中断标志
    INT32U SleepEn = PMU_CMDSTS & 0xffffffff;
    WDG_DogFeed();
    (void)SleepEn;
    //睡眠后，定时喂狗，否则会不断重启
    Wake_Set(6);        //定时唤醒喂狗
}

/***********************************************************************
 函数功能:    	触摸按键中断处理函数
 @param:	无
 @other:        无
 @return:	无
 @auther :	朱晓宇
 @time	:	2020年4月9日
 ***********************************************************************/
#define KEY_CANCLE 8
void TOUCH(void)
{
    INT16U KeyChannel;
    INT8U KeyType;
    KeyChannel = (TS_STAT >> 16) & 0xfff;
    KeyType = TS_STAT & 0xf;
    PMU_CMDW = (1 << 17); // 清除中断标志
    TS_STAT = 0xf;

    Printf_KeyType(KeyType);
    Printf_KeyChannel(KeyChannel);
    Printf_KeyVal();
}

/***********************************************************************
 函数功能:    	串口2接收中断处理函数
 @param:		无
 @other:     无
 @return:	无
 @auther :	朱晓宇
 @time	:	2020年4月9日
 ***********************************************************************/
void UART2_INT(void)
{
    PMU_CMDW = (1 << 18);
    INT8U uart_sr = UART2_IIR;
    (void)uart_sr;
}

/***********************************************************************
 函数功能:    	电量检测中断处理函数
 @param:		无
 @other:     该中断可查看用户手册
 @return:	无
 @auther :	朱晓宇
 @time	:	2020年4月9日
 ***********************************************************************/
void BAT_FAIL(void)
{
    uint32_t tmp = (PMU_CMDSTS & 0xf80000)>>19;
    PMU_CMDW = (PMU_CMDSTS & 0xf80000);
    switch(tmp)
    {
        case 0x1:
            printf("\r\n.............BAT_FAIL..............\r\n");
            PMU_CMDSTS  =   0x0;   // IT config
            break;
        case 0x2:
            break;
        case 0x4:
            break;
        case 0x8:
            break;
        case 0x10:
            printf("\r\n.............ADC..............\r\n");
            PMU_CMDSTS  &=   (~0x8000);   // IT dis
            break;
        default:
            break;
    }
}

void INTC(void)
{
}

void RING(void)
{
}

/***********************************************************************
 函数功能:    	INTC中断处理函数
 @param:		无
 @other:     该中断可查看用户手册
 @return:	无
 @auther :	朱晓宇
 @time	:	2020年4月9日
 ***********************************************************************/
#define MAX_receive 128
extern uint8_t receive_buf[];
char rx[128];
uint8_t receive_buf[MAX_receive];
extern uint8_t receive_flag;
uint8_t receive_index=0;
int receive_cnt=0;
// 假设添加了一个标志来追踪是否找到了数据开头
uint8_t found_start = 0;
void intc_handler(void)
{

    INT8U IntReg = INT_OUT;

    if(IntReg  & IRQ_TIMER)//Timer
    {
        if(TIM_GetITStatus(TIM_FLAG_Trigger))
        {
            receive_cnt++;//每过一毫秒+1;,若接收到数据包则清零
            TIM_ClearIT(TIM_FLAG_Trigger);
            if(receive_cnt>=5)
            {
                receive_cnt=0;
                receive_flag=1;
                receive_index=0;

            }

        }
    }
    if (IntReg & UART1_INT_OUT) //Uart1
    {
        INT_CLR = UART1_INT_CLR;
    }


    if (IntReg & UART0_INT_OUT) //Uart0
    {
        uint8_t data = UART_ReceiveData(UART0);

        // 检查是否找到了数据开头
        if (found_start == 0 && data == '@') {
            found_start = 1; // 设置找到开头的标志
            // 如果需要，可以重置缓冲区索引或计数器
            
        }
  if (data == '\n') {
                // 如果找到了结尾，设置相应的标志或处理数据
                receive_flag = 1; // 假设这是处理完整数据包的标志
                // 可能还需要停止接收数据或重置某些状态
                found_start = 0; // 重置找到开头的标志，以便接收下一个数据包

                // 在这里可以处理完整的数据包，例如通过函数调用


                // 重置索引，以便接收新的数据包
                receive_index = 0;
            }
        // 如果找到了开头，则将数据保存到缓冲区
        if (found_start && data!='@' && data!='\n') {
            receive_buf[receive_index++] = data;

            // 检查是否超出了缓冲区大小
            if (receive_index >= MAX_receive) {
                // 缓冲区已满，处理错误或丢弃数据
                // 可以在这里设置receive_flag或其他标志
                receive_index = MAX_receive - 1; // 防止数组越界
            }

            // 检查是否找到了数据结尾
          
        }

        // 每次接收到数据，都重置超时计数器
        receive_cnt = 0;

        // 清除UART0的中断标志
        INT_CLR = UART0_INT_CLR;
    }

    // ... 其他中断处理代码 ...

    INT_CLR = 0xff; // 确保清除所有中断标志
}

// 可能需要添加的函数来处理完整的数据包




void TIMER_HANDLER(void)
{
    Set_Timer_clear();
    printf("Core Timer clear interrupt..\r\n");
    Set_Timer_stop();
}



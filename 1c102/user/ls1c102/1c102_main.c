
#include "ls1x.h"
#include "Config.h"
#include "oled96.h"
#include "ls1c102_i2c.h"
#include "ls1x_latimer.h"
#include "ls1c102_ptimer.h"
#include "ls1x_gpio.h"
#include "ls1x_rtc.h"

uint8_t receive_flag=0;
uint8_t i=0;
uint8_t a=0;
uint8_t qwer[7];
extern receive_index;
extern uint8_t receive_buf[];
int main(int arg, char *args[])
{
    gpio_pin_remap(GPIO_PIN_4,GPIO_FUNC_MAIN);//引脚复用4：scl
    gpio_pin_remap(GPIO_PIN_5,GPIO_FUNC_MAIN);//引脚复用5：sda
      gpio_write_pin(GPIO_PIN_14, 0);
    I2C_InitTypeDef I2C_InitStruct0;
    I2C_StructInit(&I2C_InitStruct0);

    I2C_Init(I2C, &I2C_InitStruct0);
    delay_ms(100);
    OLED_Init();// 初始化 OLED 模块
    OLED_Full();// OLED全屏变白
    OLED_Clear();// OLED 清屏（整个屏幕填充黑色）

    while(1)
    {if(strncmp(receive_buf,"no1",3)==0)
  OLED_ShowString(0,0,receive_buf);
       if(strncmp(receive_buf,"no2",3)==0)
  OLED_ShowString(0,2,receive_buf);
       if(strncmp(receive_buf,"no3",3)==0)
          {gpio_write_pin(GPIO_PIN_14, 0);
          OLED_ShowString(0,4,"normal.");}
          
        if(strncmp(receive_buf,"no4",3)==0)
          {
          OLED_ShowString(0,4,"warning");
           gpio_write_pin(GPIO_PIN_14, 1);}
            //if(strncmp(receive_buf,"safe",4)==0) OLED_ShowString(0,2,"smoke detection normal.");
             // if(strncmp(receive_buf,"warn",4)==0) OLED_ShowString(0,4,"warning");

             
       

          
      }

    return 0;
}




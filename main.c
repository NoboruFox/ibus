#include <stm8s.h>

void setup_clock()
{
  CLK_DeInit();
  CLK_SYSCLKConfig(CLK_PRESCALER_HSIDIV8);
  CLK_ClockSwitchConfig(CLK_SWITCHMODE_AUTO, CLK_SOURCE_HSI, DISABLE,
                        CLK_CURRENTCLOCKSTATE_DISABLE);
}

void setup_gpio()
{
    GPIO_Init(GPIOA, GPIO_PIN_3, GPIO_MODE_OUT_PP_LOW_SLOW);
}

void main()
{
  int i = 0;
  setup_clock();

  setup_gpio();

  while(1) {
      GPIO_WriteHigh(GPIOA, GPIO_PIN_3);
      for (i=0; i < 10000; i++){}
      GPIO_WriteLow(GPIOA, GPIO_PIN_3);
      for (i=0; i < 10000; i++){}
  }
}

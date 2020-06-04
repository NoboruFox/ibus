#include <stm8s.h>


void setup_clock()
{
  CLK_DeInit();
  CLK_SYSCLKConfig(CLK_PRESCALER_HSIDIV8);
  CLK_ClockSwitchConfig(CLK_SWITCHMODE_AUTO, CLK_SOURCE_HSI, DISABLE,
                        CLK_CURRENTCLOCKSTATE_DISABLE);
}



void main()
{
  setup_clock();

  while(1) {
  }

}

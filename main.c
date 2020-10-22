#include <stm8s.h>

void setup_clock()
{
  CLK_DeInit();
  CLK_SYSCLKConfig(CLK_PRESCALER_HSIDIV8); //divides HSI CLK (16MHZ/8 = 2MHz)
  CLK_ClockSwitchConfig(CLK_SWITCHMODE_AUTO, CLK_SOURCE_HSI, DISABLE,
                        CLK_CURRENTCLOCKSTATE_DISABLE);
  CLK_PeripheralClockConfig(CLK_PERIPHERAL_TIMER1, ENABLE);
}

void setup_gpio()
{
    GPIO_Init(GPIOA, GPIO_PIN_3, GPIO_MODE_OUT_PP_LOW_SLOW);
}

void setup_timer()
{
    TIM1_DeInit();
    //what is repetitioncounter?
    //Diode to blink once in a sec. Div 2MHz by 30 (2000000/65535=30), so prescaler = 0x1E (30) or...
    //is it better to set period to 65535 so it resets after reaching this value? -> interrupts 30 times/sec?
    //The last value is repetition counter, when it turns 0 -> update event occurs
   enableInterrupts(); 
//    __asm__("rim\n");
//    asm("rim");
    TIM1_TimeBaseInit(30, TIM1_COUNTERMODE_UP, 65535, 1);//1 -> 0 probably
    //Clear bit of interrupt?
    TIM1_ClearFlag(TIM1_FLAG_UPDATE);
    //Turn on the TIM1? 
    TIM1_Cmd(ENABLE);
    //Enabling TIM1 interrupts source
    TIM1_ITConfig(TIM1_IT_UPDATE, ENABLE);
//    ITC_SetSoftwarePriority(ITC_IRQ_TIM1_OVF, ITC_PRIORITYLEVEL_1);
}

//INTERRUPT_HANDLER(handler_name, interrupt_number) - ITC..._OVF = overflow interrupt
//= 11. 
void INTERRUPT_HANDLER(TIM1_handler, ITC_IRQ_TIM1_OVF)
{
    if (TIM1_GetITStatus(TIM1_IT_UPDATE) != RESET)
            GPIO_WriteReverse(GPIOA, GPIO_PIN_3);
    TIM1_ClearFlag(TIM1_FLAG_UPDATE);

}

//ITC_SetSoftwarePriority(ITC_IRQ_TIM1_OVF, ITC_PRIORITYLEVEL_1);

void main()
{
 // int i = 0;
  setup_clock();
  setup_gpio();
  setup_timer();
//  INTERRUPT_HANDLER(TIM1_handler, ITC_IRQ_TIM1_OVF);
    //while(1) {
      //GPIO_WriteHigh(GPIOA, GPIO_PIN_3);
      //for (i=0; i < 10000; i++){}
      //GPIO_WriteLow(GPIOA, GPIO_PIN_3);
      //for (i=0; i < 10000; i++){}

//    if (TIM1_GetITStatus(TIM1_IT_UPDATE) != RESET){
//       TIM1_ClearITPendingBit(TIM1_IT_UPDATE);
//       GPIO_WriteHigh(GPIOA, GPIO_PIN_3);
//            GPIO_WriteReverse(GPIOA, GPIO_PIN_3);

}

cmake_minimum_required(VERSION 3.10)

project(stm8spl LANGUAGES C)

add_library(stm8spl STATIC)

target_include_directories(stm8spl PRIVATE ./include)
target_sources(stm8spl PRIVATE stm8s_gpio.c stm8s_adc1.c stm8s_awu.c
               stm8s_beep.c stm8s_clk.c stm8s_exti.c
               stm8s_flash.c stm8s_gpio.c stm8s_i2c.c stm8s_itc.c
               stm8s_iwdg.c stm8s_rst.c stm8s_spi.c stm8s_tim1.c
               stm8s_uart1.c stm8s_wwdg.c)

if("${MCU}" MATCHES "^(STM8S208|STM8S207|STM8S007|STM8AF52Ax|STM8AF62Ax)$")
  target_sources(stm8spl PRIVATE stm8s_adc2.c)
endif()

if("${MCU}" MATCHES "^(STM8S208|STM8AF52Ax)$")
  target_sources(stm8spl PRIVATE stm8s_can.c)
endif()

if("${MCU}" MATCHES
    "^(STM8S208|STM8S207|STM8S007|STM8S103|STM8S105|STM8S005|STM8AF52Ax|STM8AF62Ax|STM8AF626x)$")
  target_sources(stm8spl PRIVATE stm8s_tim2.c)
endif()

if("${MCU}" MATCHES
    "^(STM8S208|STM8S207|STM8S007|STM8S105|STM8S005|STM8AF52Ax|STM8AF62Ax|STM8AF626x)$")
  target_sources(stm8spl PRIVATE stm8s_tim3.c)
endif()

if("${MCU}" MATCHES
    "^(STM8S208|STM8S207|STM8S007|STM8S103|STM8S105|STM8S005|STM8AF52Ax|STM8AF62Ax|STM8AF626x)$")
  target_sources(stm8spl PRIVATE stm8s_tim4.c)
endif()

if("${MCU}" MATCHES "^(STM8S903|STM8AF622x)$")
  target_sources(stm8spl PRIVATE stm8s_tim5.c stm8s_tim6.c)
endif()

if("${MCU}" MATCHES
    "^(STM8S105|STM8S005|STM8AF626x)$")
  target_sources(stm8spl PRIVATE stm8s_uart2.c)
endif()

if("${MCU}" MATCHES
    "^(STM8S208|STM8S207|STM8S007|STM8AF52Ax|STM8AF62Ax)$")
  target_sources(stm8spl PRIVATE stm8s_uart3.c)
endif()

if("${MCU}" MATCHES
    "^(STM8AF622x)$")
  target_sources(stm8spl PRIVATE stm8s_uart4.c)
endif()

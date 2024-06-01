cmake_minimum_required(VERSION 3.10)

include(pico_sdk_import.cmake)

project(uart C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

pico_sdk_init()

add_executable(uart
	gpio_init.c
	uart.c
)

pico_add_extra_outputs(uart)

pico_enable_stdio_usb(uart 0)
pico_enable_stdio_uart(uart 1)
target_link_libraries(uart pico_stdlib)


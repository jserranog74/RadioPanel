// 2023 Radio Panel for Flight Simulation
#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"

int main() 
{
    stdio_init_all();
    if (cyw43_arch_init()) 
    {
        printf("WiFi init failed");
        return -1;
    }
    while (true) 
    {
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
        sleep_ms(1000);
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
        sleep_ms(250);
    }
}
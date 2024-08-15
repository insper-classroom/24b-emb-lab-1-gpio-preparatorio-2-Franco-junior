    #include <stdio.h>
    #include "pico/stdlib.h"
    #include "hardware/gpio.h"

    const int LED_PIN = 5;
    const int LED_PIN2 = 28;

    int main() {
        stdio_init_all();

        gpio_init(LED_PIN);
        gpio_init(LED_PIN2);
        gpio_set_dir(LED_PIN, GPIO_OUT);
        gpio_set_dir(LED_PIN2, GPIO_OUT);

        while (true) {
            gpio_put(LED_PIN, 1);
            gpio_put(LED_PIN2, 1);
            sleep_ms(250);
            gpio_put(LED_PIN, 0);
            gpio_put(LED_PIN2, 0);
            sleep_ms(250);
        }
    }

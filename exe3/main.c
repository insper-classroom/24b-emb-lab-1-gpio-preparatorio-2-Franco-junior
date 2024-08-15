#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_PIN = 26; //verde
const int BTN_PIN2 = 28; //vermelho

const int LED_PIN = 4; //vermelho
const int LED_PIN2 = 6; //verde

int main() {
  stdio_init_all();

  gpio_init(BTN_PIN);
  gpio_init(BTN_PIN2);
  gpio_set_dir(BTN_PIN, GPIO_IN);
  gpio_set_dir(BTN_PIN2, GPIO_IN);
  gpio_pull_up(BTN_PIN);
  gpio_pull_up(BTN_PIN2);

  gpio_init(LED_PIN);
  gpio_init(LED_PIN2);
  gpio_set_dir(LED_PIN, GPIO_OUT);
  gpio_set_dir(LED_PIN2, GPIO_OUT);

  int vermelho = 0;
  int verde = 0;

  while (true) {
    if (!gpio_get(BTN_PIN)) {
      if (verde == 0) {
        gpio_put(LED_PIN2, 1);
        verde = 1;
      } else if (verde == 1) {
        gpio_put(LED_PIN2, 0);
        verde = 0;
      }
      sleep_ms(250);
    } else if (!gpio_get(BTN_PIN2)) {
      if (vermelho == 0) {
        gpio_put(LED_PIN, 1);
        vermelho = 1;
      } else if (vermelho == 1) {
        gpio_put(LED_PIN, 0);
        vermelho = 0;
      }
      sleep_ms(250);
    }
  }
}
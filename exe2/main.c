#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_PIN = 5;
const int BTN_PIN2 = 28;

int main() {
  stdio_init_all();

  gpio_init(BTN_PIN);
  gpio_init(BTN_PIN2);
  gpio_set_dir(BTN_PIN, GPIO_IN);
  gpio_set_dir(BTN_PIN2, GPIO_IN);
  gpio_pull_up(BTN_PIN);
  gpio_pull_up(BTN_PIN2);

  while (true) {
    if (!gpio_get(BTN_PIN)) {
      printf("Botao 1\n");
      while (!gpio_get(BTN_PIN)) {
      };
    } else if (!gpio_get(BTN_PIN2)) {
      printf("Botao 2\n");
      while (!gpio_get(BTN_PIN2)) {
      };
    }
  }
}
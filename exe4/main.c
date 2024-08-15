#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_PIN = 28; //vermelho

const int LED_PIN = 5; //vermelho
const int LED_PIN2 = 8; //roxo
const int LED_PIN3 = 11; //azul
const int LED_PIN4 = 15; //amarelo

int main() {
  stdio_init_all();

  gpio_init(BTN_PIN);
  gpio_set_dir(BTN_PIN, GPIO_IN);
  gpio_pull_up(BTN_PIN);

  gpio_init(LED_PIN);
  gpio_init(LED_PIN2);
  gpio_init(LED_PIN3);
  gpio_init(LED_PIN4);
  gpio_set_dir(LED_PIN, GPIO_OUT);
  gpio_set_dir(LED_PIN2, GPIO_OUT);
  gpio_set_dir(LED_PIN3, GPIO_OUT);
  gpio_set_dir(LED_PIN4, GPIO_OUT);

  int vermelho = 0;
  int roxo = 0;
  int azul = 0;
  int amarelo = 0;

  while (true) {
    if (!gpio_get(BTN_PIN)) {
      if (vermelho == 0 && roxo == 0 && azul == 0 && amarelo == 0) {
        gpio_put(LED_PIN, 1);
        vermelho = 1;
      } else if (vermelho == 1 && roxo == 0 && azul == 0 && amarelo == 0) {
        gpio_put(LED_PIN, 0);
        sleep_ms(300);
        gpio_put(LED_PIN2, 1);
        vermelho = 0;
        roxo = 1;
      } else if (vermelho == 0 && roxo == 1 && azul == 0 && amarelo == 0) {
        gpio_put(LED_PIN2, 0);
        sleep_ms(300);
        gpio_put(LED_PIN3, 1);
        roxo = 0;
        azul = 1;
      } else if (vermelho == 0 && roxo == 0 && azul == 1 && amarelo == 0) {
        gpio_put(LED_PIN3, 0);
        sleep_ms(300);
        gpio_put(LED_PIN4, 1);
        azul = 0;
        amarelo = 1;
      } else if (vermelho == 0 && roxo == 0 && azul == 0 && amarelo == 1) {
        gpio_put(LED_PIN4, 0);
        amarelo = 0;
      }
      sleep_ms(300);
    }
  }
}
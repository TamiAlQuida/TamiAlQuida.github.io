/*https://www.youtube.com/watch?v=BvyYMIpI2R8*/

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "pico-ssd1306/ssd1306.h"

#define I2C_PORT i2c0
#define I2C_SDA 0
#define I2C_SCL 1

int main() {
    stdio_init_all();

    i2c_init(I2C_PORT, 400 * 1000); // 400kHz I2C
    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA);
    gpio_pull_up(I2C_SCL);

    // Initialize display
    SSD1306 display;
    ssd1306_init(&display, 128, 64, I2C_PORT, 0x3C); // 0x3C is typical I2C address

    ssd1306_clear(&display);
    ssd1306_draw_string(&display, 0, 0, 2, "Hello, OLED!");
    ssd1306_show(&display);

    while (true) {
        sleep_ms(1000);
    }
}
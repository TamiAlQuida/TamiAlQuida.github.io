/*
 * https://github.com/daschr/pico-ssd1306
 * https://www.youtube.com/watch?v=BvyYMIpI2R8
 */

#include "pico/stdlib.h"
extern "C"{
#include "ssd1306.h"
}
#include <cstdio>
#include "font.h"

#define DELAY 500 // in milliseconds

const char* word[] = {
	"Hello",
	"mothafucka",
	"how are ya?"
};

/***
 * Draw the word testing on the Oled Screen
 */
void drawTest(ssd1306_t *pOled, const char* word){
	ssd1306_draw_string(
			pOled,
			0,
			1,
			2,
			word);

	ssd1306_draw_line(
			pOled,
			2, 40,
			126, 40);
}

/***
 * Deaw the word Testing amd Blink on the Screen
 */
void drawBlink(ssd1306_t *pOled){
	ssd1306_draw_string(
			pOled,
			0,
			50,
			1,
			"Blink");
}

int main() {
	stdio_init_all();
	sleep_ms(2000);
	printf("GO\n");

	//Setup the OLED Screen
	i2c_init(i2c0, 400000);
	gpio_pull_up(12);
	gpio_pull_up(13);
	gpio_set_function(12, GPIO_FUNC_I2C);
	gpio_set_function(13, GPIO_FUNC_I2C);
	ssd1306_t oled;
	oled.external_vcc=false;
	bool res = ssd1306_init(
			&oled,
			128,
			64,
			0x3c,
			i2c0);

	//If setup OK then write the test text on OLED
	if (res){
		ssd1306_clear(&oled);
		drawTest(&oled, word[0]);
		ssd1306_show(&oled);
	} else {
		printf("Oled Init failed\n");
	}


    while (true) { // Loop forever
		for (int i = 0; i < 3; i++) {
			ssd1306_clear(&oled);
			drawTest(&oled, word[i]);
			drawBlink(&oled);
			ssd1306_show(&oled);
        	sleep_ms(DELAY);

        	ssd1306_clear(&oled);
			drawTest(&oled, word[i]);
			ssd1306_show(&oled);
        	sleep_ms(DELAY);
		}
    }
}

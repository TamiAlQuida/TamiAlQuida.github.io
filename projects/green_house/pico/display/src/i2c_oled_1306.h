#ifndef I2C_OLED_1306_H
#define I2C_OLED_1306_H

#include "ssd1306.h"

#ifdef __cplusplus
extern "C" {
#endif

// External declaration of the oled variable
extern ssd1306_t oled;

/**
 * Initialize the OLED display
 * Sets up I2C communication and initializes the OLED screen
 */
void setupOled();

/**
 * Draw test text on the OLED screen
 * @param pOled Pointer to the OLED display structure
 * @param word Text to display
 */
void drawTest(ssd1306_t *pOled, const char* word, const char* date);

/**
 * Draw blinking text on the OLED screen
 * @param pOled Pointer to the OLED display structure
 */
void drawBlink(ssd1306_t *pOled);

#ifdef __cplusplus
}
#endif

#endif // I2C_OLED_1306_H 
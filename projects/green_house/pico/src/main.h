#pragma once
extern const uint LED_PIN;
extern const uint RELAY_PIN;
extern const bool BUTTON_OUT_PIN;
extern const bool BUTTON_IN_PIN;

void setupPico() {
    stdio_init_all();
    gpio_init(LED_PIN);
    gpio_init(RELAY_PIN);
    gpio_init(BUTTON_OUT_PIN);
    gpio_init(BUTTON_IN_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_set_dir(RELAY_PIN, GPIO_OUT);
    gpio_set_dir(BUTTON_OUT_PIN, GPIO_OUT);
    gpio_set_dir(BUTTON_IN_PIN, GPIO_IN);
    sleep_ms(1000);
}

void test_relay() {
    for (int i = 0; i < 5; i++) {
        gpio_put(LED_PIN, 1);
        gpio_put(RELAY_PIN, 1);
        printf("LED on\n");
        sleep_ms(100);
        gpio_put(LED_PIN, 0);
        gpio_put(RELAY_PIN, 0);
        printf("LED off\n");
        sleep_ms(100);
    }
}

//void buttonPressed() {
//        gpio_put(LED_PIN, 2);
//        gpio_put(RELAY_PIN, 2);
//        printf("button pressed\n"); // print out to console
//        sleep_ms(100);
//        gpio_put(LED_PIN, 0);
//        gpio_put(RELAY_PIN, 0);
//        printf("LED off\n");
//        sleep_ms(100);
//    }
//}

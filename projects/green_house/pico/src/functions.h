#pragma once
extern int setClock[];
extern int sleepTime;
extern const uint LED_PIN;
extern const uint RELAY_PIN;
extern int* fakeClock;
extern int activitionHours[];
extern int activitionMinutes[];
extern int activitionSeconds[];
extern const int activitionHoursSize;
extern const int activitionMinutesSize;
extern const int activitionSecondsSize;

void setup() {
    stdio_init_all();
    gpio_init(LED_PIN);
    gpio_init(RELAY_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_set_dir(RELAY_PIN, GPIO_OUT);
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

void changeClock() {
    printf("Clock: %02d:%02d:%02d\n", fakeClock[0], fakeClock[1], fakeClock[2]);
    if (fakeClock[0] == 23 && fakeClock[1] == 59 && fakeClock[2] == 60 - sleepTime) {
        fakeClock[0] = 0;
        fakeClock[1] = 0;
        fakeClock[2] = 0;
    } else if (fakeClock[1] == 59 && fakeClock[2] == 60 - sleepTime) {
        fakeClock[0]++;
        fakeClock[1] = 0;
        fakeClock[2] = 0;
    } else if (fakeClock[2] == 60 - sleepTime) {
        fakeClock[1]++;
        fakeClock[2] = 0;
    } else {
        fakeClock[2] += sleepTime;
    }
    sleep_ms(sleepTime * 1000);
}

bool checkArray(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return true;
        }
    }
    return false;
}
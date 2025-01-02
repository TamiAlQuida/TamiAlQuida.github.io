#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "hardware/uart.h"
#include <stdio.h>
#include <math.h>

// I2C defines
#define I2C_PORT i2c0
#define MPU6050_ADDR 0x68

// MPU6050 register addresses
#define REG_PWR_MGMT_1 0x6B
#define REG_ACCEL_XOUT_H 0x3B
#define REG_GYRO_CONFIG 0x1B
#define REG_ACCEL_CONFIG 0x1C
#define REG_SMPLRT_DIV 0x19
#define WHO_AM_I_REG 0x75

// Sensitivity scale factors for different ranges
#define ACCEL_SCALE_FACTOR_2G 16384.0  // for ±2g
#define ACCEL_SCALE_FACTOR_4G 8192.0   // for ±4g
#define ACCEL_SCALE_FACTOR_8G 4096.0   // for ±8g
#define ACCEL_SCALE_FACTOR_16G 2048.0  // for ±16g

#define GYRO_SCALE_FACTOR_250DPS 131.0    // for ±250 DPS
#define GYRO_SCALE_FACTOR_500DPS 65.5     // for ±500 DPS
#define GYRO_SCALE_FACTOR_1000DPS 32.8    // for ±1000 DPS
#define GYRO_SCALE_FACTOR_2000DPS 16.4    // for ±2000 DPS

// Select the desired scale factor
#define ACCEL_SCALE_FACTOR ACCEL_SCALE_FACTOR_4G  // Change this to the desired accelerometer range
#define GYRO_SCALE_FACTOR GYRO_SCALE_FACTOR_250DPS // Change this to the desired gyroscope range

// Corresponding configuration values
#define ACCEL_CONFIG_VALUE 0x08  // for ±4g
#define GYRO_CONFIG_VALUE 0x00  // for ±250 DPS
#define SAMPLE_RATE_DIV 1  // Sample rate = 1kHz / (1 + 1) = 500Hz

// UART definitions for MAVLink
#define UART_ID uart0
#define BAUD_RATE 57600
#define UART_TX_PIN 0
#define UART_RX_PIN 1

void mpu6050_reset() {
    uint8_t reset[] = {REG_PWR_MGMT_1, 0x80};
    i2c_write_blocking(I2C_PORT, MPU6050_ADDR, reset, 2, false);
    sleep_ms(200);
    uint8_t wake[] = {REG_PWR_MGMT_1, 0x00};
    i2c_write_blocking(I2C_PORT, MPU6050_ADDR, wake, 2, false);
    sleep_ms(200);
}

void mpu6050_configure() {
    // Set accelerometer range
    uint8_t accel_config[] = {REG_ACCEL_CONFIG, ACCEL_CONFIG_VALUE};
    i2c_write_blocking(I2C_PORT, MPU6050_ADDR, accel_config, 2, false);

    // Set gyroscope range
    uint8_t gyro_config[] = {REG_GYRO_CONFIG, GYRO_CONFIG_VALUE};
    i2c_write_blocking(I2C_PORT, MPU6050_ADDR, gyro_config, 2, false);

    // Set sample rate
    uint8_t sample_rate[] = {REG_SMPLRT_DIV, SAMPLE_RATE_DIV};
    i2c_write_blocking(I2C_PORT, MPU6050_ADDR, sample_rate, 2, false);
}

void mpu6050_read_raw(int16_t accel[3], int16_t gyro[3], int16_t *temp) {
    uint8_t buffer[14];
    uint8_t reg = REG_ACCEL_XOUT_H;
    i2c_write_blocking(I2C_PORT, MPU6050_ADDR, &reg, 1, true);
    i2c_read_blocking(I2C_PORT, MPU6050_ADDR, buffer, 14, false);

    accel[0] = (buffer[0] << 8) | buffer[1];
    accel[1] = (buffer[2] << 8) | buffer[3];
    accel[2] = (buffer[4] << 8) | buffer[5];
    *temp = (buffer[6] << 8) | buffer[7];
    gyro[0] = (buffer[8] << 8) | buffer[9];
    gyro[1] = (buffer[10] << 8) | buffer[11];
    gyro[2] = (buffer[12] << 8) | buffer[13];
}

// Function to send MAVLink heartbeat (simplified)
void send_heartbeat() {
    uint8_t buf[] = {
        0xFE,  // MAVLink 1.0 start
        9,     // Payload length
        0,     // Packet sequence
        1,     // System ID
        1,     // Component ID
        0,     // Message ID (heartbeat)
        // ... rest of heartbeat message
    };
    uart_write_blocking(UART_ID, buf, sizeof(buf));
}

// Function to send attitude data (simplified)
void send_attitude(float roll, float pitch, float yaw) {
    // Convert angles to radians
    float roll_rad = roll * 0.0174533f;
    float pitch_rad = pitch * 0.0174533f;
    float yaw_rad = yaw * 0.0174533f;

    uint8_t buf[32];  // Adjust size as needed
    // ... Pack MAVLink attitude message ...
    uart_write_blocking(UART_ID, buf, sizeof(buf));
}

int main() {
    // Initialize chosen serial port
    stdio_init_all();
    
    // Initialize UART for MAVLink
    uart_init(UART_ID, BAUD_RATE);
    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);

    // Initialize I2C
    i2c_init(I2C_PORT, 400 * 1000);
    gpio_set_function(4, GPIO_FUNC_I2C);
    gpio_set_function(5, GPIO_FUNC_I2C);
    gpio_pull_up(4);
    gpio_pull_up(5);

    // Reset and configure MPU6050
    mpu6050_reset();
    mpu6050_configure();

    uint8_t who_am_i = 0;
    uint8_t reg = WHO_AM_I_REG;
    i2c_write_blocking(I2C_PORT, MPU6050_ADDR, &reg, 1, true);
    i2c_read_blocking(I2C_PORT, MPU6050_ADDR, &who_am_i, 1, false);
    printf("MPU6050 WHO_AM_I: 0x%02X\n", who_am_i);

    if (who_am_i != 0x68) {
        printf("MPU6050 not found!\n");
        while (1);
    }

    int16_t accel[3], gyro[3], temp;

    while (1) {
        mpu6050_read_raw(accel, gyro, &temp);

        // Convert raw values to angles (basic example)
        float accel_x = accel[0] / ACCEL_SCALE_FACTOR;
        float accel_y = accel[1] / ACCEL_SCALE_FACTOR;
        float accel_z = accel[2] / ACCEL_SCALE_FACTOR;

        // Calculate roll and pitch from accelerometer
        float roll = atan2(accel_y, accel_z) * 57.3;
        float pitch = atan2(-accel_x, sqrt(accel_y*accel_y + accel_z*accel_z)) * 57.3;

        // Send data via MAVLink
        send_heartbeat();
        send_attitude(roll, pitch, 0);  // Yaw set to 0 as we can't measure it with just accelerometer

        sleep_ms(100);  // 10Hz update rate
    }

    return 0;
}
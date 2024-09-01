#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu.initialize();
}

void loop() {
  int16_t ax, ay, az, gx, gy, gz;
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  // Normalize acceleration data
  float acc_x = ax * (3.33 / 32768);
  float acc_y = ay * (3.33 / 32768);
  float acc_z = az * (3.33 / 32768);

  // Convert gyroscope data to radians/second
  float gyro_x = gx * (250.0 / 32768) * (PI / 180.0);
  float gyro_y = gy * (250.0 / 32768) * (PI / 180.0);
  float gyro_z = gz * (250.0 / 32768) * (PI / 180.0);

  // Send data to serial port
  Serial.print(acc_x);
  Serial.print(",");
  Serial.print(acc_y);
  Serial.print(",");
  Serial.print(acc_z);
  Serial.print(",");
  Serial.print(gyro_x);
  Serial.print(",");
  Serial.print(gyro_y);
  Serial.print(",");
  Serial.println(gyro_z); 



}
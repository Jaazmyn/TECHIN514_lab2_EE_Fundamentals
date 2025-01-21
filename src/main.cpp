#include <Arduino.h>

// 根据你的硬件连接选择正确的 ADC 引脚
const int VOUT1_PIN = 1;  // 替换为支持 ADC 的 GPIO
const int VOUT2_PIN = 2;  // 替换为支持 ADC 的 GPIO

void setup() {
    Serial.begin(115200);

    // 确保 ADC 引脚已正确绑定
    adcAttachPin(VOUT1_PIN);
    adcAttachPin(VOUT2_PIN);

    // 设置 ADC 衰减范围为 0-3.3V
    analogSetAttenuation(ADC_11db);
}

void loop() {
    // 读取 ADC 值
    int adc1 = analogRead(VOUT1_PIN);
    int adc2 = analogRead(VOUT2_PIN);

    // 将 ADC 值转换为实际电压
    float voltage1 = (adc1 / 4095.0) * 3.3; // 12-bit 分辨率
    float voltage2 = (adc2 / 4095.0) * 3.3;

    // 输出电压值
    Serial.print("VOUT1: "); Serial.print(voltage1); Serial.println(" V");
    Serial.print("VOUT2: "); Serial.print(voltage2); Serial.println(" V");
    Serial.println("----------------------");

    delay(1000);  // 每秒更新一次
}
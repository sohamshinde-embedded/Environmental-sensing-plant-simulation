# 🌡️ ESP32 Environmental Monitor & Distance Tracker

A multi-sensor monitoring station built with an **ESP32**. This project captures ambient light, temperature, humidity, and object distance, displaying the data on a 20x4 I2C LCD screen.

## 🚀 Features
* **Temperature & Humidity:** High-accuracy monitoring via DHT22.
* **Auto-Lighting:** LDR (Photoresistor) measures light levels and automatically toggles an LED in dark conditions.
* **Distance Measurement:** HC-SR04 Ultrasonic sensor calculates distance in centimeters.
* **I2C Integration:** Uses a 20x4 LCD with an I2C backpack to minimize wiring.

## 🛠️ Hardware Requirements
| Component | Quantity | Description |
| :--- | :--- | :--- |
| **ESP32 DevKit V1** | 1 | Main Microcontroller |
| **DHT22** | 1 | Digital Temp/Humidity Sensor |
| **HC-SR04** | 1 | Ultrasonic Distance Sensor |
| **LDR** | 1 | Light Dependent Resistor |
| **LCD 20x4 (I2C)** | 1 | Character Display (Address 0x27) |
| **LED** | 1 | Night-light Indicator |

---

## 📌 Pin Mapping

| Component | ESP32 Pin | Mode |
| :--- | :--- | :--- |
| **DHT22 Data** | GPIO 25 | INPUT |
| **LDR (Analog)** | GPIO 34 | INPUT |
| **LED** | GPIO 4 | OUTPUT |
| **Ultrasonic TRIG**| GPIO 2 | OUTPUT |
| **Ultrasonic ECHO**| GPIO 0 | INPUT |
| **LCD SDA** | GPIO 21 | I2C Data |
| **LCD SCL** | GPIO 22 | I2C Clock |

---

## 💻 Software Setup

### 1. Libraries Required
Install these via the Arduino Library Manager:
* `DHT sensor library` by Adafruit
* `LiquidCrystal I2C` by Frank de Brabander
* `Adafruit Unified Sensor` (Dependency for DHT)

### 2. Logic & Calculations
The distance is calculated based on the speed of sound ($0.0343$ cm/μs):

$$Distance = \frac{Duration \times 0.0343}{2}$$

The LDR intensity is mapped from the ESP32's 12-bit ADC ($0$ to $4095$) to a percentage:

$$Light\% = \frac{RawValue \times 100}{4095}$$

---

## 🔌 Wiring Diagram Reference


## 📝 How to Use
1.  Connect the components according to the **Pin Mapping** table.
2.  Open the `.ino` file in Arduino IDE.
3.  Ensure you have the **ESP32 Board Manager** installed.
4.  Select `DOIT ESP32 DEVKIT V1` as your board.
5.  Upload the code and open the Serial Monitor at `115200` baud to see the debug values.

---

**Developed for IoT Prototyping**

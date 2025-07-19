#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEScan.h>

#define SCAN_TIME 5  // seconds
#define RSSI_THRESHOLD -80

BLEScan* pBLEScan;

void setup() {
  Serial.begin(115200);
  BLEDevice::init("");
  pBLEScan = BLEDevice::getScan();
  pBLEScan->setActiveScan(true);

  Serial.println("Starting BLE RF Validation Logger");
}

void loop() {
  BLEScanResults results = pBLEScan->start(SCAN_TIME, false);
  Serial.println("Device Count: " + String(results.getCount()));

  for (int i = 0; i < results.getCount(); i++) {
    BLEAdvertisedDevice device = results.getDevice(i);
    int rssi = device.getRSSI();
    String addr = device.getAddress().toString().c_str();
    String name = device.getName().c_str();
    if (rssi > RSSI_THRESHOLD) {
      Serial.print("Device: "); Serial.print(name); Serial.print(" (" + addr + ")");
      Serial.print(" RSSI: "); Serial.print(rssi);
      Serial.println(" dBm");
    }
  }

  pBLEScan->clearResults();
  delay(1000);
}

# Wireless Connectivity System Validation

## Aim
Test and validate wireless RF protocols (BLE, UWB) for embedded systems in noisy automotive environments.

## Workflow
- Perform RF tests in multiple environments
- Evaluate SNR, BLE range, and RSSI drop-off
- Coordinate with antenna suppliers
- Document test logs in diagnostic tool

## Explanation
RF systems were validated under controlled conditions to ensure resilience to interference and reliable signal transmission. BLE and UWB modules were tested for range and data integrity.

## Technologies Used
- Bluetooth Low Energy (BLE)
- Ultra-Wideband (UWB)
- Embedded Linux and ECU tools
- Diagnostic test framework

## Tools
- RF Signal Generator
- Spectrum Analyzer
- Automotive test bench
- BMW diagnostic suite

## Methodology
- Log data at ECU endpoints
- Measure attenuation and RSSI under EMI
- Plot correlation between noise and signal drop

## Observations
- Certain ECUs caused drop to -85 dBm
- Strategic antenna placement resolved performance issues

## Results
- BLE range extended beyond 10 meters
- RSSI stabilized at greater than -75 dBm

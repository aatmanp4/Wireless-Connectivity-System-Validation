import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

# Load BLE scan log (assumes CSV from serial log)
df = pd.read_csv("ble_scan_log.csv")  # Columns: ['name','mac','rssi','time']

# Basic stats
devices = df['mac'].unique()
for dev in devices:
    rssi_vals = df[df['mac'] == dev]['rssi']
    print(f"{dev}: avg RSSI = {rssi_vals.mean():.2f} dBm")

# Range profile (simplified: assume rssi ~ distance)
plt.figure()
for dev in devices:
    plt.plot(df[df['mac'] == dev]['time'], df[df['mac'] == dev]['rssi'], label=dev)

plt.axhline(-75, color='gray', linestyle='--', label='Acceptable RSSI')
plt.xlabel("Time")
plt.ylabel("RSSI (dBm)")
plt.title("BLE RSSI Range Profile")
plt.legend()
plt.grid(True)
plt.show();

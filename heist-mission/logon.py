#!/usr/bin/env python3
import serial
import time

uartDevice = "/dev/ttyUSB0"
consoleUsername = "taylor"
consolePassword = "171717"

ser = serial.Serial(
    uartDevice,
    baudrate=115200,
    timeout=2
)



    



# converts the string to bytes first. then sends it over as a serial connection.
ser.write(bytes(consoleUsername + '\n', "utf-8"))
time.sleep(10) # time to wait between username and password is adjustable, 5 seconds is just to be safe.

ser.write(bytes(consolePassword + "\n","utf-8"))
time.sleep(2)

# time to wait for login prompt
time.sleep(2)


# Send command
ser.write(b"uname -a\n")



# Read response
while True:
    line = ser.readline()
    if not line:
        break
    print(line.decode(errors="ignore").strip())

ser.close()


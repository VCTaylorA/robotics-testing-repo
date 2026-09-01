import serial
import threading
import sys


#uartDevice = "/dev/ttyUSB0"
#consoleUsername = "taylor"
#consolePassword = "171717"
#
#ser = serial.Serial(
#    uartDevice,
#    baudrate=115200,
#    timeout=2
#)

#adapted from https://www.pyserial.com/docs/examples
 
def reader_thread(ser):
    """Print incoming data in real time."""
    while ser.is_open:
        try:
            data = ser.read(ser.in_waiting or 1)
            if data:
                sys.stdout.write(data.decode('utf-8', errors='replace'))
                sys.stdout.flush()
        except serial.SerialException:
            break

def terminal(port, baudrate=115200):
    """Interactive serial terminal. Type 'exit' to quit."""
    ser = serial.Serial(port, baudrate, timeout=0.1)
    print(f"Connected to {port} at {baudrate} baud. Type 'exit' to quit.\n")

    reader = threading.Thread(target=reader_thread, args=(ser,))
    reader.daemon = True
    reader.start()

    try:
        while True:
            line = input()
            if line.strip().lower() == 'exit':
                break
            ser.write((line + '\r\n').encode())
    except (KeyboardInterrupt, EOFError):
        pass
    finally:
        ser.close()
        print("\nDisconnected")


terminal('/dev/ttyUSB0')
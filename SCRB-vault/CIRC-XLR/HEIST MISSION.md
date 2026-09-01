Heist Mission 3.3-3.6 
[Heist Mission 3.3-3.6](https://circ.cstag.ca/2026/tasks/#heist-mission)
Access and read data from Linux terminal using XLR connector

[UART (Universal Asynchronous Receiver Transmitter)](https://en.wikipedia.org/wiki/Universal_asynchronous_receiver-transmitter)
 

jetson uart serial connection

[https://www.cyberciti.biz/hardware/5-linux-unix-commands-for-connecting-to-the-serial-console/](https://www.cyberciti.biz/hardware/5-linux-unix-commands-for-connecting-to-the-serial-console/)  
[https://www.cyberciti.biz/faq/find-out-linux-serial-ports-with-setserial/](https://www.cyberciti.biz/faq/find-out-linux-serial-ports-with-setserial/)

https://drive.google.com/drive/u/0/folders/1XgO3_FnDRx5uoHMbpfKX-1UKzptlDmA2



https://linuxvox.com/blog/linux-serial-port-listener-and-interpreter/#understanding-serial-ports-in-linux


## Standard:

3.3v TTL 115200 baud 8N1, no flow control
## development steps:
1.  connected CP2102 TX, RX, MX to the 3 pins on the right of the orangepi3lts 1.4 [[Orange-pi-3-lts-interface-details-img2.png]] (console)
	1. TX to RX, RX to TX, GND to GND
2. in the laptop (rover) make sure the device shows up with `sudo dmesg | tail`
	1. alternatively you can do `ls /dev/ttyUSB*` or `ls /dev/ttyACM0`
3. log in with screen/picocom
	1. picocom command: `picocom -b 115200 /dev/ttyUSB0`
4. screen command for login: `screen /dev/ttyUSB0 115200`

ensure that your user is in the group that can write to the device
sudo chmod +xrw /dev/ttyUSB0
sudo usermod -aG dialout taylor

#Radio Frequency test

This test consists of two Arduino Uno boards that send and receive a signal using a [nRF24L01+](https://www.nordicsemi.com/eng/Products/2.4GHz-RF/nRF24L01P) transceiver IC. The wires are connected the same way for the transceiver and the LED on both boards. Colors are for easier reading. However, black is always ground, and red is always power.

[![Working Demonstration Video](demo.jpg)](http://youtu.be/K33vYQWaf7E)

![Transmitter Breadboard](transmitter_bb.png)


![Receiver Breadboard](receiver_bb.png)

Parts:

| Quantity | Type | Description |
| --- | --- | --- |
| 2 | Ceramic Capacitor | 0.1µF part 104 |
| 1 | Red LED | |
| 1 | Green LED | |
| 2 | nRF24L01+ | 2.4GHz Wireless RF Transceiver |
| 2 | Arduino | Uno Rev3 |
| 3 | 10Ω Resistor | tolerance ±5%; |
| 1 | Pushbutton | THT |

Breadboard schematics were made using [Fritzing](http://fritzing.org/)

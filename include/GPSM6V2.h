/* ============================================
MIT License

Copyright (c) 2022 PiotrTopa

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.GPSM6V2
===============================================
*/

#ifndef _GPSM6V2_H_
#define _GPSM6V2_H_

#include <math.h>
#include "driver/uart.h"

#define CONFIG_GPSM6V2_UART_BAUD_RATE 115200
#define CONFIG_GPSM6V2_UART_DATA_BITS UART_DATA_8_BITS
#define CONFIG_GPSM6V2_UART_PARITY UART_PARITY_DISABLE
#define CONFIG_GPSM6V2_UART_STOP_BITS UART_STOP_BITS_1
#define CONFIG_GPSM6V2_UART_FLOW_CTRL UART_HW_FLOWCTRL_CTS_RTS
#define CONFIG_GPSM6V2_UART_FLOW_THRS 122
#define CONFIG_GPSM6V2_UART_GPIO_RX GPIO_NUM_12
#define CONFIG_GPSM6V2_UART_GPIO_TX GPIO_NUM_13
#define CONFIG_GPSM6V2_UART_BUFFER_SIZE (1024 * 2)

class GPSM6V2
{

public:
        GPSM6V2();
        void initialize();
        void update();

private:
        void configureUart();
        uart_port_t uartPort;
};

#endif /* _GPSM6V2_H_ */
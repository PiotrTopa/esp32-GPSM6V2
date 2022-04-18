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
SOFTWARE.
===============================================
*/

#include "GPSM6V2.h"

static const char *TAG = "GPSM6V2";

GPSM6V2::GPSM6V2()
{
}

/**
 * Initialize device
 */
void GPSM6V2::initialize(uart_port_t _uartPort)
{
    uartPort = _uartPort;
}

void GPSM6V2::configureUart()
{
    uart_config_t uartConfig = {
        .baud_rate = CONFIG_GPSM6V2_UART_BAUD_RATE,
        .data_bits = CONFIG_GPSM6V2_UART_DATA_BITS,
        .parity = CONFIG_GPSM6V2_UART_PARITY,
        .stop_bits = CONFIG_GPSM6V2_UART_STOP_BITS,
        .flow_ctrl = CONFIG_GPSM6V2_UART_FLOW_CTRL,
        .rx_flow_ctrl_thresh = CONFIG_GPSM6V2_UART_FLOW_THRS,
    };

    ESP_ERROR_CHECK(uart_param_config(uartPort, &uartConfig));

    ESP_ERROR_CHECK(uart_set_pin(
        uartPort,
        CONFIG_GPSM6V2_UART_GPIO_RX,
        CONFIG_GPSM6V2_UART_GPIO_TX,
        UART_PIN_NO_CHANGE,
        UART_PIN_NO_CHANGE
    ));

    // Setup UART buffered IO with event queue
    const int uart_buffer_size = (1024);
    QueueHandle_t uart_queue;
    // Install UART driver using an event queue here
    ESP_ERROR_CHECK(uart_driver_install(
        UART_NUM_2,
        CONFIG_GPSM6V2_UART_BUFFER_SIZE * 2,
        CONFIG_GPSM6V2_UART_BUFFER_SIZE * 2,
        0,
        NULL,
        0
    ));
}

void GPSM6V2::update()
{
}
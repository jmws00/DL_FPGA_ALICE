#include <stdio.h>
#include "xparameters.h"
#include "xgpio.h"

#define GPIO_DEVICE_ID XPAR_AXI_GPIO_0_DEVICE_ID // ID for GPIO setting `time`
#define TIME_OUTPUT_CHANNEL 1                   // Channel for `time`

XGpio Gpio;

int main() {
    int Status;
    u32 time_value = 0;

    // Initialize GPIO
    Status = XGpio_Initialize(&Gpio, GPIO_DEVICE_ID);
    if (Status != XST_SUCCESS) {
        xil_printf("GPIO initialization failed\n");
        return XST_FAILURE;
    }

    // Set direction: output on channel 1 (for controlling `time`)
    XGpio_SetDataDirection(&Gpio, TIME_OUTPUT_CHANNEL, 0x0);

    // Set the time value
    time_value = 100;

    // Send the value to GPIO
    xil_printf("Sending value %u to the pulse_generator module\n\r", time_value);
    XGpio_DiscreteWrite(&Gpio, TIME_OUTPUT_CHANNEL, time_value);

    return 0;
}

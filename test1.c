#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"

#include "xil_io.h"
#include "xparameters.h"
#include "xgpio.h"
#include "xil_types.h"
#include "sleep.h"
#include "counter_signal_generator_axi.h"

#define GPIO_DEVICE_ID_LED XPAR_AXI_GPIO_0_DEVICE_ID
#define LED_OUTPUT_CHANNEL 1

int generate(u32 N, u32 T1,  u32 *signal_out);

int main()
{
    init_platform();
	XGpio GpioLED;
    XGpio_Initialize(&GpioLED, GPIO_DEVICE_ID_LED);

    u32 N = 0b11111111; // Przykładowy wzór (8-bitowa liczba binarna)
    u32 T1 = 500;     // 32-bitowa liczba dziesiętna;
    u32 signal_out;

    while(1)
    {
    	generate(N, T1, &signal_out);
    	usleep(250000);
    	xil_printf("Signal out: %x\n\r", signal_out);
    }


    cleanup_platform();
    return 0;
}



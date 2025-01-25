/***************************** Include Files *********************************/
#include "xil_io.h"
#include "xparameters.h"
#include "counter_signal_generator_axi.h"

/**************************** user definitions ********************************/


#define GENERATOR_BASE_ADDR      XPAR_COUNTER_SIGNAL_GENER_0_S00_AXI_BASEADDR


#define N_REG_OFFSET    		COUNTER_SIGNAL_GENERATOR_AXI_S00_AXI_SLV_REG0_OFFSET
#define T1_REG_OFFSET      		COUNTER_SIGNAL_GENERATOR_AXI_S00_AXI_SLV_REG1_OFFSET



int generate(u32 N, u32 T1)
{
u32 dataN  = N;
u32 dataT1 = T1;

//Send data to data register of processor
	COUNTER_SIGNAL_GENERATOR_AXI_mWriteReg(GENERATOR_BASE_ADDR, N_REG_OFFSET, dataN);
	COUNTER_SIGNAL_GENERATOR_AXI_mWriteReg(GENERATOR_BASE_ADDR, T1_REG_OFFSET, dataT1);

	return 1;
}


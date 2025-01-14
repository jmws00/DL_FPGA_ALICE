/*
 * generator_ip.c
 *
 *  Created on: 14.01.2025
 *      Author: KubaM
 */

/***************************** Include Files *********************************/
#include "xil_io.h"
#include "xparameters.h"
#include "counter_signal_generator_axi.h"

/**************************** user definitions ********************************/

//Cordic processor base addres redefinition
#define GENERATOR_BASE_ADDR      XPAR_COUNTER_SIGNAL_GENER_0_S00_AXI_BASEADDR

//Cordic processor registers' offset redefinition
#define N_REG_OFFSET    		COUNTER_SIGNAL_GENERATOR_AXI_S00_AXI_SLV_REG0_OFFSET
#define T1_REG_OFFSET      		COUNTER_SIGNAL_GENERATOR_AXI_S00_AXI_SLV_REG1_OFFSET
#define SIGNAL_OUT_REG_OFFSET   COUNTER_SIGNAL_GENERATOR_AXI_S00_AXI_SLV_REG2_OFFSET


int generate(u32 N, u32 T1,  u32 *signal_out)
{
u32 dataN  = N;
u32 dataT1 = T1;
u32 result;

//Debug
//	result = CORDIC_IP_mReadReg(CORDIC_BASE_ADDR, RESULT_REG_OFFSET);


//Send data to data register of cordic processor
	COUNTER_SIGNAL_GENERATOR_AXI_mWriteReg(GENERATOR_BASE_ADDR, N_REG_OFFSET, dataN);

	COUNTER_SIGNAL_GENERATOR_AXI_mWriteReg(GENERATOR_BASE_ADDR, T1_REG_OFFSET, dataT1);

//Get results
	result = COUNTER_SIGNAL_GENERATOR_AXI_mReadReg(GENERATOR_BASE_ADDR, SIGNAL_OUT_REG_OFFSET);

	*signal_out = result;

	return 1;
}


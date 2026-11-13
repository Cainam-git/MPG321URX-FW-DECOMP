/* reg_ahb_write32  (FUN_CODE_beb5)
 *
 * Write a 32-bit word over the PBus-to-AHB bridge.
 *   addr: AHB address
 *   val: word
 * Name basis: proven - bridge registers 0xCD80..0xCD8C; prints 'PBus to AHB bridge Error!!'
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_beb5, OPTIMIZE(8,SPEED) LARGE.
 * The ready test is written '(unsigned int)(reg & 1)', which Keil compiles to ANL A,#1 / JNZ, not JB.
 */
#include <intrins.h>
typedef union { unsigned long l; unsigned char b[4]; } DW;
extern volatile unsigned char xdata reg_ahb_bridge_addr, reg_ahb_bridge_addr_byte1, reg_ahb_bridge_addr_byte2, reg_ahb_bridge_addr_byte3;
extern volatile unsigned char xdata reg_ahb_bridge_wdata, reg_ahb_bridge_wdata_byte1, reg_ahb_bridge_wdata_byte2, reg_ahb_bridge_wdata_byte3, reg_ahb_bridge_control;
extern void lib_printf517(void *fmt, ...) large;
/*
 * reg_ahb_write32 - write one 32-bit word to the AHB bus through the PBus-to-AHB bridge.
 *   addr: AHB address
 *   val: the word
 * If bit 0 of the bridge control register (0xCD8C) is clear, print "PBus to AHB bridge Error!!" and write nothing.
 * Otherwise write the address to 0xCD80..0xCD83 and the data to 0xCD84..0xCD87 (low byte first), start the write
 * with 0xCD8C = 0x80 and wait until bit 0 is set again. Twin of reg_ahb_read32 (start code 0x40).
 * Used by ipc_portal_write and by the processor start / stop routines on the core-control registers.
 */
void reg_ahb_write32(DW addr, DW val)
{
    if (!(unsigned int)(reg_ahb_bridge_control & 1)) {
        lib_printf517((void code *)0xda1d);   /* "PBus to AHB bridge Error!!\r\n" */
    } else {
        reg_ahb_bridge_addr = addr.b[3];
        reg_ahb_bridge_addr_byte1 = addr.b[2];
        reg_ahb_bridge_addr_byte2 = addr.b[1];
        reg_ahb_bridge_addr_byte3 = addr.b[0];
        reg_ahb_bridge_wdata = val.b[3];
        reg_ahb_bridge_wdata_byte1 = val.b[2];
        reg_ahb_bridge_wdata_byte2 = val.b[1];
        reg_ahb_bridge_wdata_byte3 = val.b[0];
        reg_ahb_bridge_control = 0x80;
        while (!(unsigned int)(reg_ahb_bridge_control & 1)) _nop_();
    }
}

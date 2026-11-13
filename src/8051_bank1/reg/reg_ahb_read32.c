/* reg_ahb_read32  (FUN_CODE_bcad)
 *
 * Read a 32-bit word over the PBus-to-AHB bridge.
 *   addr: AHB address
 * Returns: word
 * Name basis: proven - bridge registers 0xCD80..0xCD8C; prints 'PBus to AHB bridge Error!!'
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_bcad, OPTIMIZE(8,SPEED) LARGE.
 * The ready test is written '(unsigned int)(reg & 1)', which Keil compiles to ANL A,#1 / JNZ, not JB. The result union
 * lives in the callee's block (Keil returns a pointer), so it is left unchanged on the error path.
 */
#include <intrins.h>
typedef union { unsigned long l; unsigned char b[4]; } DW;
extern volatile unsigned char xdata reg_ahb_bridge_addr, reg_ahb_bridge_addr_byte1, reg_ahb_bridge_addr_byte2, reg_ahb_bridge_addr_byte3;
extern volatile unsigned char xdata reg_ahb_bridge_rdata, reg_ahb_bridge_rdata_byte1, reg_ahb_bridge_rdata_byte2, reg_ahb_bridge_rdata_byte3, reg_ahb_bridge_control;
extern void lib_printf517(void *fmt, ...) large;
/*
 * reg_ahb_read32 - read one 32-bit word from the AHB bus through the PBus-to-AHB bridge.
 *   addr: AHB address
 * If bit 0 of the bridge control register (0xCD8C) is clear, the bridge is not ready: print "PBus to AHB bridge
 * Error!!" and return the result variable unset. Otherwise write the address to 0xCD80..0xCD83 (low byte first),
 * start the read with 0xCD8C = 0x40, wait until bit 0 is set again, and collect the data from 0xCD88..0xCD8B (low
 * byte first).
 * Used by the processor start routines (startup_run_leon2m / startup_run_leon2s) on the core-control registers 0x9F020008 /
 * 0x9F120008, and by the mailbox code.
 */
DW reg_ahb_read32(DW addr)
{
    DW word;
    if (!(unsigned int)(reg_ahb_bridge_control & 1)) {
        lib_printf517((void code *)0xda1d);   /* "PBus to AHB bridge Error!!\r\n" */
    } else {
        reg_ahb_bridge_addr = addr.b[3];
        reg_ahb_bridge_addr_byte1 = addr.b[2];
        reg_ahb_bridge_addr_byte2 = addr.b[1];
        reg_ahb_bridge_addr_byte3 = addr.b[0];
        reg_ahb_bridge_control = 0x40;
        while (!(unsigned int)(reg_ahb_bridge_control & 1)) _nop_();
        word.b[3] = reg_ahb_bridge_rdata;
        word.b[2] = reg_ahb_bridge_rdata_byte1;
        word.b[1] = reg_ahb_bridge_rdata_byte2;
        word.b[0] = reg_ahb_bridge_rdata_byte3;
    }
    return word;
}

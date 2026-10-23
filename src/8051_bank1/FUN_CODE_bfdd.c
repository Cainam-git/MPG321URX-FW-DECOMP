/* FUN_CODE_bfdd, 8051_bank1, range 0xBFDD..0xC03F (98 B).
 * Options: OPTIMIZE(8,SPEED) (also with REGFILE(R.ORC) added).
 * Code facts: serial-port interrupt service routine (interrupt 4: the vector at CODE 0x0023 is 'LJMP 0xBFDD',
 * thunk_FUN_CODE_bfdd; 'using 1' = MOV PSW,#08H, and Keil saves only ACC, DPH, DPL, PSW). RX (RI): clear RI, the
 * byte goes to IDATA 0x5D and into the 16-byte ring DAT_EXTMEM_a1e8[] at the IDATA write index 0x42 (wraps after
 * 15). TX (TI): clear TI; when the read index 0x45 differs from the write index 0x43 it sends DAT_EXTMEM_a1f8[0x45]
 * and advances 0x45 (wraps after 15); otherwise it sets the idle flag 0x46 = 1. Counterpart of the accepted
 * FUN_CODE_d1a8 (puts a byte into a1f8 at 0x43 and restarts TX via TI = 1 when 0x46 is set), same IDATA names.
 * Caller: the vector LJMP at 0x0023 only. No aids.
 */
#include <reg51.h>
extern unsigned char idata DAT_INTMEM_42, DAT_INTMEM_43, DAT_INTMEM_45, DAT_INTMEM_46, DAT_INTMEM_5d;
extern unsigned char xdata DAT_EXTMEM_a1e8[];
extern unsigned char xdata DAT_EXTMEM_a1f8[];
void FUN_CODE_bfdd(void) interrupt 4 using 1
{
    if (RI) {
        RI = 0;
        DAT_INTMEM_5d = SBUF;
        DAT_EXTMEM_a1e8[DAT_INTMEM_42] = DAT_INTMEM_5d;
        if (++DAT_INTMEM_42 > 0x0f) DAT_INTMEM_42 = 0;
    }
    if (TI) {
        TI = 0;
        if (DAT_INTMEM_45 != DAT_INTMEM_43) {
            SBUF = DAT_EXTMEM_a1f8[DAT_INTMEM_45];
            if (++DAT_INTMEM_45 > 0x0f) DAT_INTMEM_45 = 0;
        } else DAT_INTMEM_46 = 1;
    }
}

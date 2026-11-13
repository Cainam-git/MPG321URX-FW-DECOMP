/* dp_status_reg_write8  (FUN_a00a6fc0)
 *
 * Write a byte register of one or both DP receiver status blocks.
 *   unit
 *   reg: register
 *   value
 * Name basis: derived - block table 0xA00B4D90, unit 2 = both; audio_clear_dp_status writes 0xFF to registers
 *   3/4 (clear events)
 *
 * Matching notes
 * --------------
 * leon2s, flags -mcpu=v8 -Os -g.
 */
extern unsigned short dp_status_reg_bases[];

/*
 * Write a byte register of a DP receiver status block; unit 2 writes both units (0 and 1), values above 2
 * write nothing. Counterpart of dp_status_reg_read8.
 *
 *   unit:  0, 1, or 2 = both
 *   reg:   register number
 *   value: only the low byte is written
 */
void dp_status_reg_write8(unsigned int unit, unsigned short reg, unsigned int value)
{
    unsigned char i;
    
    unit &= 0xff;
    if (unit > 2)
        return;
    
    if (unit == 2) {
        i = 0;
        do {
            *(volatile unsigned int *)(0xcf000000 | 
                ((dp_status_reg_bases[i] + (unsigned short)reg) * 4)) = value & 0xff;
            i++;
        } while (i <= 1);
    } else {
        *(volatile unsigned int *)(0xcf000000 | 
            ((dp_status_reg_bases[unit] + (unsigned short)reg) * 4)) = value & 0xff;
    }
}

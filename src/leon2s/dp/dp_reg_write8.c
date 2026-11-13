/* dp_reg_write8  (FUN_a00a6c00)
 *
 * Write a byte register of one or both DP receivers.
 *   receiver: receiver, 2 = both
 *   reg: register
 *   value
 * Name basis: proven - block table 0xA00B4D94, port 2 = both
 *
 * Matching notes
 * --------------
 * leon2s, flags -mcpu=v8 -Os -g.
 */
extern unsigned short dp_reg_bases[];

/*
 * Write a byte register of a DP receiver; receiver 2 writes both receivers (0 and 1), values above 2 write
 * nothing. Counterpart of dp_reg_read8; same address scheme.
 *
 *   receiver: 0, 1, or 2 = both
 *   reg:      register number
 *   value:    only the low byte is written
 */
void dp_reg_write8(unsigned int receiver, unsigned short reg, unsigned int value)
{
    unsigned char i;
    
    receiver &= 0xff;
    if (receiver > 2)
        return;
    
    if (receiver == 2) {
        for (i = 0; i <= 1; i++) {
            *(volatile unsigned int *)(0xcf000000 | 
                ((dp_reg_bases[i] + (unsigned short)reg) * 4)) = value & 0xff;
        }
    } else {
        *(volatile unsigned int *)(0xcf000000 | 
            ((dp_reg_bases[receiver] + (unsigned short)reg) * 4)) = value & 0xff;
    }
}

/* dp_tx_ctl_reg_write8  (FUN_a00a7b64)
 *
 * Write a byte register of a DP / eDP transmitter control bank.
 *   bank: output 0..4
 *   reg: register
 *   val: value
 * Name basis: derived - block table 0xA00B4D70 with the eDP bank select of register 0x60
 *
 * Matching notes
 * --------------
 * leon2s, flags -mcpu=v8 -Os -g. A leaf routine.
 * Source forms as in dp_tx_ctl_reg_read8: the address uses ((unsigned)reg << 16) >> 16, taken after the bank
 * write, and the compare uses (unsigned short)reg, which keeps two separate truncations; separate nested tests.
 */
extern unsigned short dp_tx_ctl_reg_bases[];

#define CTL_BANK_SELECT_REG 0x60    /* bits 6..7 select the bank of the registers below it */
#define CTL_LAST_BANKED_REG 0x5f

/*
 * Write a byte register of a DP transmitter control bank (bank 0 = DPTX, 1..4 = eDP outputs). Banks above 4
 * write nothing. Counterpart of dp_tx_ctl_reg_read8; the bank is selected the same way (bits 6..7 of the
 * register at offset 0x60 get bank - 1 for banks 1..4 and registers up to 0x5F).
 *
 *   bank: 0..4
 *   reg:  register number
 *   val:  value to write
 */
void dp_tx_ctl_reg_write8(unsigned char bank, short reg, unsigned char val)
{
    unsigned int addr;

    if (bank <= 4) {
        if (bank != 0) {
            if ((unsigned short)reg <= CTL_LAST_BANKED_REG)
                *(volatile unsigned int *)(((dp_tx_ctl_reg_bases[bank] + CTL_BANK_SELECT_REG) << 2) | 0xcf000000) =
                    (*(volatile unsigned int *)(((dp_tx_ctl_reg_bases[bank] + CTL_BANK_SELECT_REG) << 2) | 0xcf000000) & 0x3f) | ((bank - 1) << 6);
        }
        addr = reg;
        addr = (addr << 16) >> 16;
        *(volatile unsigned int *)(((dp_tx_ctl_reg_bases[bank] + addr) << 2) | 0xcf000000) = val;
    }
}

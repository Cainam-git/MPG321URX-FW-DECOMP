/* dp_tx_ctl_reg_read8  (FUN_a00a7acc)
 *
 * Read a byte register of a DP / eDP transmitter control bank.
 *   bank: output 0..4
 *   reg: register
 * Returns: byte, 0 for an invalid unit
 * Name basis: derived - block table 0xA00B4D70 (output 0 = 0x7500, eDP 1..4 = 0x7400 with bank bits 6-7 of
 *   register 0x60); callers DP TX and HDCP TX code
 *
 * Matching notes
 * --------------
 * leon2s, flags -mcpu=v8 -Os -g. A leaf routine.
 * Source forms as in dp_tx_reg_update_bits: the address uses ((unsigned)reg << 16) >> 16, taken after the bank
 * write, and the compare uses (unsigned short)reg, which keeps two separate truncations; separate nested tests;
 * the result is an unsigned int masked to a byte at the read.
 */
extern unsigned short dp_tx_ctl_reg_bases[];

#define CTL_BANK_SELECT_REG 0x60    /* bits 6..7 select the bank of the registers below it */
#define CTL_LAST_BANKED_REG 0x5f

/*
 * Read a byte register of a DP transmitter control bank (bank 0 = DPTX, 1..4 = eDP outputs). Returns 0 for a
 * bank above 4.
 *
 *   bank: 0..4
 *   reg:  register number
 *
 * The register is the word at 0xCF000000 | ((dp_tx_ctl_reg_bases[bank] + reg) * 4). For banks 1..4 and
 * registers up to 0x5F the number (bank - 1) is first written into bits 6..7 of the register at offset 0x60
 * of the same block, the other bits kept.
 */
unsigned char dp_tx_ctl_reg_read8(unsigned char bank, short reg)
{
    unsigned int addr;
    unsigned int value = 0;

    if (bank <= 4) {
        if (bank != 0) {
            if ((unsigned short)reg <= CTL_LAST_BANKED_REG)
                *(volatile unsigned int *)(((dp_tx_ctl_reg_bases[bank] + CTL_BANK_SELECT_REG) << 2) | 0xcf000000) =
                    (*(volatile unsigned int *)(((dp_tx_ctl_reg_bases[bank] + CTL_BANK_SELECT_REG) << 2) | 0xcf000000) & 0x3f) | ((bank - 1) << 6);
        }
        addr = reg;
        addr = (addr << 16) >> 16;
        value = *(volatile unsigned int *)(((dp_tx_ctl_reg_bases[bank] + addr) << 2) | 0xcf000000) & 0xff;
    }
    return value;
}

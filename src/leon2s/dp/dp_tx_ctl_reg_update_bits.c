/* dp_tx_ctl_reg_update_bits  (FUN_a00a7bf8)
 *
 * Set or clear masked bits of a byte register of a DP / eDP transmitter control bank.
 *   port: unit
 *   reg: register
 *   mask: bits
 *   mode: 1 = set
 * Name basis: derived - block table 0xA00B4D70 with the eDP bank select of register 0x60
 *
 * Matching notes
 * --------------
 * leon2s, flags -mcpu=v8 -Os -g.
 * Source forms: the inlined helper reg_addr() keeps (base + 0x60) * 4 as add + shift; the read address uses a
 * copy addr = reg truncated as ((addr << 16) >> 16) and the store uses (unsigned short)reg, which keeps the
 * separate truncations and register copies of the firmware (as in dp_tx_reg_update_bits); mask is a byte.
 */
extern unsigned char dp_tx_ctl_reg_bases;

static __inline__ volatile unsigned int *reg_addr(unsigned int a)
{
    return (volatile unsigned int *)((a * 4) | 0xcf000000);
}

#define CTL_BANK_SELECT_REG 0x60    /* bits 6..7 select the bank of the registers below it */

/*
 * Set or clear the bits of mask in a byte register of a DP transmitter control bank (bank 0 = DPTX, 1..4 =
 * eDP outputs). Banks above 4 are ignored. Read-modify-write; the bank is selected as in
 * dp_tx_ctl_reg_read8 (for banks 1..4 and registers below 0x60, bank - 1 goes to bits 6..7 of the register at
 * offset 0x60).
 *
 *   port: bank 0..4
 *   reg:  register number
 *   mask: bits to change
 *   mode: 1 = set the bits, any other value = clear them
 */
void dp_tx_ctl_reg_update_bits(unsigned char port, short reg, unsigned char mask, unsigned char mode)
{
    unsigned int addr;
    unsigned char value;
    volatile unsigned int *bank_select;

    if (port < 5) {
        if (port != 0)
            if ((unsigned short)reg < CTL_BANK_SELECT_REG) {
                bank_select = reg_addr(*(unsigned short *)(&dp_tx_ctl_reg_bases + port * 2) + CTL_BANK_SELECT_REG);
                *bank_select = (*bank_select & 0x3f) | ((port - 1) << 6);
            }
        addr = reg;
        addr = ((*(unsigned short *)(&dp_tx_ctl_reg_bases + port * 2) + ((addr << 16) >> 16)) * 4) | 0xcf000000;
        value = *(volatile unsigned int *)addr;
        if (mode == 1)
            value |= mask;
        else
            value &= ~mask;
        *reg_addr(*(unsigned short *)(&dp_tx_ctl_reg_bases + port * 2) + (unsigned short)reg) = value & 0xff;
    }
}

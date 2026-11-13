/* dp_paged_reg_write8  (FUN_a00a7614)
 *
 * Write a byte to a paged register of DP receiver 0 or 1 through the page-select registers.
 *   port: DP receiver 0/1
 *   reg: register
 *   val: value
 * Name basis: derived - block table 0xA00B4D84 (0x8500 / 0x8600), bank bit = reg >> 8; caller
 *   dp_write_port_reg, dp_init_port_registers
 *
 * Matching notes
 * --------------
 * leon2s, flags -mcpu=v8 -Os -g.
 * Source form: page_mask is an unsigned short and its low byte is stored as '(unsigned char)page_mask'.
 * Same code shape as dp_paged_reg_read8.
 */
extern const unsigned short dp_paged_reg_bases[];

#define PAGE_SELECT_PORT0_LOW  (*(volatile unsigned int *)0xcf03d014)
#define PAGE_SELECT_PORT0_HIGH (*(volatile unsigned int *)0xcf03d018)
#define PAGE_SELECT_PORT1_LOW  (*(volatile unsigned int *)0xcf03d01c)
#define PAGE_SELECT_PORT1_HIGH (*(volatile unsigned int *)0xcf03d020)

/*
 * Write a byte to a paged register of DP receiver 0 or 1. Other ports do nothing.
 *
 *   port: receiver 0 or 1
 *   reg:  high byte = page number, low byte = register inside the page
 *   val:  value to write
 *
 * The mask 1 << page is written to the page-select registers of the port (low 8 bits to
 * PAGE_SELECT_PORTn_LOW, bit 8 to PAGE_SELECT_PORTn_HIGH). The value goes to the register word
 * ((dp_paged_reg_bases[port] + low byte of reg) * 4) | 0xCF000000. The four page-select registers are
 * saved first and put back afterwards.
 */
void dp_paged_reg_write8(unsigned char port, unsigned short reg, unsigned char val)
{
    unsigned char saved_port0_low = PAGE_SELECT_PORT0_LOW;
    unsigned char saved_port0_high = PAGE_SELECT_PORT0_HIGH;
    unsigned char saved_port1_low = PAGE_SELECT_PORT1_LOW;
    unsigned char saved_port1_high = PAGE_SELECT_PORT1_HIGH;
    unsigned short page_mask;

    if (port < 2) {
        page_mask = 1 << ((reg & 0xff00) >> 8);
        switch (port) {
        case 0:
            PAGE_SELECT_PORT0_LOW = (unsigned char)page_mask;
            PAGE_SELECT_PORT0_HIGH = (page_mask >> 8) & 1;
            break;
        case 1:
            PAGE_SELECT_PORT1_LOW = (unsigned char)page_mask;
            PAGE_SELECT_PORT1_HIGH = (page_mask >> 8) & 1;
            break;
        }
        *(volatile unsigned int *)(((dp_paged_reg_bases[port] + (unsigned char)reg) * 4) | 0xcf000000) = val;
        PAGE_SELECT_PORT0_LOW = saved_port0_low;
        PAGE_SELECT_PORT0_HIGH = saved_port0_high;
        PAGE_SELECT_PORT1_LOW = saved_port1_low;
        PAGE_SELECT_PORT1_HIGH = saved_port1_high;
    }
}

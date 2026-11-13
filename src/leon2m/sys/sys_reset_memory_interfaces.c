/* sys_reset_memory_interfaces  (FUN_a0114650)
 *
 * Clear and set the fixed register sequence of the three memory interfaces.
 * Name basis: descriptive - ports 0 to 2 through paged register access; part of the shut-down sequence
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0114650, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the register helpers are static functions with the same form as in dbg_ddr_phy_write_reg and dbg_ddr_phy_get_reg_161 (inlined);
 *    their switch cases are written in the order 0, 2, 1;
 *  - one unsigned char `value` holds every value read, also the unused read of register 0x125;
 *  - each mask is its own statement (value &= mask) after its read, and every bit has its own read and write.
 */
#define REG(a) (*(volatile unsigned int *)(a))
#define PREG(n) REG(0xcf000000 | ((n) << 2))

/* The three memory interfaces (ports 0..2). Each has a page register, and its registers are reached
 * at (0xcf000000 | ((base + low byte of the register number) << 2)) after the page register has been given
 * bits 8..15 of the register number. */
#define MEM_IF_PAGE_REG_PORT0 0xcf022bf8
#define MEM_IF_PAGE_REG_PORT1 0xcf0233f8
#define MEM_IF_PAGE_REG_PORT2 0xcf022ff8
#define MEM_IF_BASE_PORT0     0x8a00
#define MEM_IF_BASE_PORT1     0x8c00
#define MEM_IF_BASE_PORT2     0x8b00
#define MEM_IF_PORTS          3

static void mem_if_write_reg(unsigned char port, unsigned short reg, unsigned char val)
{
    switch (port) {
    case 0:
        REG(MEM_IF_PAGE_REG_PORT0) = (unsigned char)(reg >> 8);
        PREG(MEM_IF_BASE_PORT0 + (unsigned char)reg) = val;
        break;
    case 2:
        REG(MEM_IF_PAGE_REG_PORT2) = (unsigned char)(reg >> 8);
        PREG(MEM_IF_BASE_PORT2 + (unsigned char)reg) = val;
        break;
    case 1:
        REG(MEM_IF_PAGE_REG_PORT1) = (unsigned char)(reg >> 8);
        PREG(MEM_IF_BASE_PORT1 + (unsigned char)reg) = val;
        break;
    }
}

static unsigned char mem_if_read_reg(unsigned char port, unsigned short reg)
{
    unsigned char val;

    val = 0;
    switch (port) {
    case 0:
        REG(MEM_IF_PAGE_REG_PORT0) = (unsigned char)(reg >> 8);
        val = PREG(MEM_IF_BASE_PORT0 + (unsigned char)reg);
        break;
    case 2:
        REG(MEM_IF_PAGE_REG_PORT2) = (unsigned char)(reg >> 8);
        val = PREG(MEM_IF_BASE_PORT2 + (unsigned char)reg);
        break;
    case 1:
        REG(MEM_IF_PAGE_REG_PORT1) = (unsigned char)(reg >> 8);
        val = PREG(MEM_IF_BASE_PORT1 + (unsigned char)reg);
        break;
    }
    return val;
}

/*
 * Run a fixed register sequence on each of the three memory interfaces, ports 0, 1 and 2 in turn.
 * Per port: write 0xf0 to registers 0x149, 0x14b, 0x14a, 0x14c; write 0 to 0x129, 0x12a, 0x12b and 0x125;
 * then clear single bits, one read-modify-write per bit:
 *   register 0xe1 bits 1, 0;  0xe3 bits 1, 0;  0xe5 bits 6, 5;  0xd8 bits 1, 0;
 *   0xd7 bits 7, 6, 5;  0xbe bit 7;  0xd7 bit 1.
 * Called through sys_api_reset_memory_interfaces, which sys_shut_down_blocks calls.
 */
void sys_reset_memory_interfaces(void)
{
    unsigned char port;
    unsigned char value;

    for (port = 0; port < MEM_IF_PORTS; port++) {
        mem_if_write_reg(port, 0x149, 0xf0);
        mem_if_write_reg(port, 0x14b, 0xf0);
        mem_if_write_reg(port, 0x14a, 0xf0);
        mem_if_write_reg(port, 0x14c, 0xf0);
        mem_if_write_reg(port, 0x129, 0);
        mem_if_write_reg(port, 0x12a, 0);
        mem_if_write_reg(port, 0x12b, 0);
        value = mem_if_read_reg(port, 0x125);   /* the value read is not used */
        mem_if_write_reg(port, 0x125, 0);
        value = mem_if_read_reg(port, 0x0e1);
        value &= 0xfd;
        mem_if_write_reg(port, 0x0e1, value);
        value = mem_if_read_reg(port, 0x0e1);
        value &= 0xfe;
        mem_if_write_reg(port, 0x0e1, value);
        value = mem_if_read_reg(port, 0x0e3);
        value &= 0xfd;
        mem_if_write_reg(port, 0x0e3, value);
        value = mem_if_read_reg(port, 0x0e3);
        value &= 0xfe;
        mem_if_write_reg(port, 0x0e3, value);
        value = mem_if_read_reg(port, 0x0e5);
        value &= 0xbf;
        mem_if_write_reg(port, 0x0e5, value);
        value = mem_if_read_reg(port, 0x0e5);
        value &= 0xdf;
        mem_if_write_reg(port, 0x0e5, value);
        value = mem_if_read_reg(port, 0x0d8);
        value &= 0xfd;
        mem_if_write_reg(port, 0x0d8, value);
        value = mem_if_read_reg(port, 0x0d8);
        value &= 0xfe;
        mem_if_write_reg(port, 0x0d8, value);
        value = mem_if_read_reg(port, 0x0d7);
        value &= 0x7f;
        mem_if_write_reg(port, 0x0d7, value);
        value = mem_if_read_reg(port, 0x0d7);
        value &= 0xbf;
        mem_if_write_reg(port, 0x0d7, value);
        value = mem_if_read_reg(port, 0x0d7);
        value &= 0xdf;
        mem_if_write_reg(port, 0x0d7, value);
        value = mem_if_read_reg(port, 0x0be);
        value &= 0x7f;
        mem_if_write_reg(port, 0x0be, value);
        value = mem_if_read_reg(port, 0x0d7);
        value &= 0xfd;
        mem_if_write_reg(port, 0x0d7, value);
    }
}

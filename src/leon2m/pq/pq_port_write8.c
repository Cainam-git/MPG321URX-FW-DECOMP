/* pq_port_write8  (FUN_a00f2b8c)
 *
 * Write an 8-bit register of one port block, or of all four.
 * Name basis: derived - block base addresses from the ROM table at 0x19A2E4
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f2b8c @ 0xa00f2b8c-0xa00f2c20 (37 words), flags -mcpu=v8 -O3 -g.
 * Source form: written like the twin input_unit_write8 (u16 table array, u8 params, do/while over i); volatile only on the
 * 0xcf... hw register store.
 */
extern unsigned short pq_port_reg_bases[4];

#define ALL_PORT_BLOCKS 8          /* port_block value selecting all four blocks */
#define LAST_PORT_BLOCK 3          /* highest single-block index */
#define PORT_REG_BASE 0xcf000000   /* memory-mapped base of the port registers */
#define REG_ADDR_SHIFT 2           /* register offsets are word-aligned */

/*
 * Write an 8-bit value to a register of one port block, or of all four.
 * port_block: 0-3 selects a single block, ALL_PORT_BLOCKS (8) selects all four; other values do nothing.
 * reg_offset is the register number; value is the byte written.
 * Called by pq_port_set_reg10_bit0, pq_block_set_fill_color and pq_load_block8_config.
 */
void pq_port_write8(unsigned char port_block, unsigned char reg_offset, unsigned char value)
{
    unsigned char i;
    unsigned int register_address;

    if (port_block == ALL_PORT_BLOCKS) {
        i = 0;
        do {
            register_address = pq_port_reg_bases[i] + reg_offset;
            *(volatile unsigned int *)(PORT_REG_BASE | (register_address << REG_ADDR_SHIFT)) = value;
            i++;
        } while (i <= LAST_PORT_BLOCK);
    } else if (port_block <= LAST_PORT_BLOCK) {
        register_address = pq_port_reg_bases[port_block] + reg_offset;
        *(volatile unsigned int *)(PORT_REG_BASE | (register_address << REG_ADDR_SHIFT)) = value;
    }
}

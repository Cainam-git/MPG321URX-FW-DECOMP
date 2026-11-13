/* pq_load_profile_table  (FUN_a0110fb4)
 *
 * Load the built-in 1024-entry profile table into the picture hardware.
 * Name basis: proven - prints 'Profile_Load_Table'; through the memory port
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0110fb4 @ 0xa0110fb4-0xa0111028 (29 words), flags -mcpu=v8 -O3 -g.
 * Source form: the entry count is held in the variable entry_count; with a literal bound the compiler emits
 * cmp 0x3ff / bleu instead of the firmware's cmp 0x400 / bcs.
 */
#define R(a) (*(volatile unsigned int *)(a))

#define MEM_PORT_CONTROL       0xcf011f80   /* memory port control register (as in sys_mem_port_enable) */
#define MEM_PORT_CONTROL_VALUE 0x81         /* bit 7 and bit 0 (port on) */
#define PROFILE_REGION         0x14         /* memory region the table is written to */
#define PROFILE_BASE_REG       0xb7080160   /* receives the region address times 32 */
#define PROFILE_ENTRIES        0x400
#define PROFILE_ENTRY_BYTES    0x20         /* one memory port block */
#define TIMES_32_SHIFT         5
#define MEM_PORT_IN_ORDER      1            /* sys_mem_port_write_blocks: bytes in buffer order */

extern int dbg_printf(const char *fmt, ...);
extern unsigned int sys_get_region_address(unsigned int);
extern void reg_write32(unsigned int addr, unsigned int value);
extern void sys_mem_port_write_blocks(const unsigned char *p, unsigned int addr, unsigned char n, unsigned char mode);
extern const unsigned char pq_profile_table[PROFILE_ENTRIES][PROFILE_ENTRY_BYTES];

/*
 * Copy pq_profile_table through the memory port, one 32-byte entry per block. The address of memory region
 * 0x14 (sys_get_region_address) is the port address of entry 0, entry i goes to that address + i; register
 * 0xB7080160 receives the region address times 32.
 *
 * Called by System_Initialize and by pq_api_load_profile_table.
 */
void pq_load_profile_table(void)
{
    unsigned int region_address;
    unsigned int i, entry_count = PROFILE_ENTRIES;

    dbg_printf("\nProfile_Load_Table\r\n");
    R(MEM_PORT_CONTROL) = MEM_PORT_CONTROL_VALUE;
    region_address = sys_get_region_address(PROFILE_REGION);
    reg_write32(PROFILE_BASE_REG, region_address << TIMES_32_SHIFT);
    for (i = 0; i < entry_count; i++)
        sys_mem_port_write_blocks(pq_profile_table[i], i + region_address, 1, MEM_PORT_IN_ORDER);
}

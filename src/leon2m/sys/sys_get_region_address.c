/* sys_get_region_address  (FUN_a002e46c)
 *
 * Return the address of memory region k (0..0x14), or for 0x15..0x18 an address read from registers.
 *   k: region index
 * Returns: address, 0 for unknown k
 * Note: Regions 0..0x12 are fixed offsets from the base word 0xA802C990; 0x13/0x14 are separate words;
 *   0x15..0x18 read four byte registers at 0xCF011880 / B0 / E0 / 0xCF011910.
 * Name basis: descriptive - code only; callers include the picture profile loader
 *
 * Matching notes
 * --------------
 * leon2m FUN_a002e46c @ 0xa002e46c-0xa002e658 (123 words), flags -mcpu=v8 -O3 -g.
 * Source form: one switch on the unsigned char k with the cases in the order written below (0x12 before the
 * shared 0xe / 0x11 block); the compiler builds a jump table at 0xa002e408 from it.
 */
extern unsigned int sys_region_base_first, sys_region_base_second, sys_region_base_third;
extern unsigned int reg_read32_bytes(unsigned int);

/*
 * Return the start address of one of the numbered memory regions.
 *
 *   k   region number 0..0x18
 *
 * Returns the address, or 0 for a region number above 0x18.
 *
 * Regions 0 to 0x12 lie at fixed distances above the base word sys_region_base_first (0x40000 for region 1,
 * up to 0x300000 for region 0x10; regions 0xe and 0x11 give the same address). Regions 0x13 and 0x14 are two
 * further base words (sys_region_base_second and _third) that are used as they are. Regions 0x15 to 0x18 are
 * not kept in RAM: the address is read from four byte registers that start at 0xcf011880, 0xcf0118b0,
 * 0xcf0118e0 and 0xcf011910.
 *
 * Callers: the update-port start sequence asks for region 0x13, pq_load_profile_table for 0x14 (the
 * profile table is written there) and pq_read_zone_color_averages for 0x18.
 */
unsigned int sys_get_region_address(unsigned char k)
{
    unsigned int r = 0;

    switch (k) {
    case 0:
        r = sys_region_base_first;
        break;
    case 0x1:
        r = sys_region_base_first + 0x40000;
        break;
    case 0x2:
        r = sys_region_base_first + 0xc0000;
        break;
    case 0x3:
        r = sys_region_base_first + 0x140000;
        break;
    case 0x4:
        r = sys_region_base_first + 0x180000;
        break;
    case 0x5:
        r = sys_region_base_first + 0x1c0000;
        break;
    case 0x6:
        r = sys_region_base_first + 0x200000;
        break;
    case 0x7:
        r = sys_region_base_first + 0x220000;
        break;
    case 0x8:
        r = sys_region_base_first + 0x240000;
        break;
    case 0x9:
        r = sys_region_base_first + 0x260000;
        break;
    case 0xa:
        r = sys_region_base_first + 0x280000;
        break;
    case 0xb:
        r = sys_region_base_first + 0x290000;
        break;
    case 0xc:
        r = sys_region_base_first + 0x2a0000;
        break;
    case 0xd:
        r = sys_region_base_first + 0x2b0000;
        break;
    case 0x12:
        r = sys_region_base_first + 0x2c0000;
        break;
    case 0xe:
    case 0x11:
        r = sys_region_base_first + 0x2d0000;
        break;
    case 0xf:
        r = sys_region_base_first + 0x2f0000;
        break;
    case 0x10:
        r = sys_region_base_first + 0x300000;
        break;
    case 0x13:
        r = sys_region_base_second;
        break;
    case 0x14:
        r = sys_region_base_third;
        break;
    case 0x15:
        r = reg_read32_bytes(0xcf011880);
        break;
    case 0x16:
        r = reg_read32_bytes(0xcf0118b0);
        break;
    case 0x17:
        r = reg_read32_bytes(0xcf0118e0);
        break;
    case 0x18:
        r = reg_read32_bytes(0xcf011910);
        break;
    }
    return r;
}

/* sys_frc_write_setting_values  (FUN_a01129e4)
 *
 * Write up to three values to the registers of the selected group (0..5, 0xA, 0xB, 0x13).
 * Note: Groups 0..4: three registers from 0xCF011880 + group * 0x30; 5 and 0x13: one; 0xA and 0xB: two.
 * Name basis: descriptive - switch on the selector; reg_write32_bytes calls
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01129e4 @ 0xa01129e4-0xa0112b2c, flags -mcpu=v8 -O3 -g.
 * Source form the exact build depends on: one case per selector with the register addresses as plain literals;
 * the firmware has an unreachable return/restore tail after the switch.
 */
extern void reg_write32_bytes(unsigned int reg, unsigned int v);

/*
 * Write the values of one group of a stored setting to their registers.
 *
 *   group   which registers: 0..4, 5, 0xA, 0xB or 0x13; any other value writes nothing
 *   first, second, third   the values, in the order of the registers below; a value past the last register of
 *                          the group is ignored
 *
 * Each value goes to reg_write32_bytes, which writes a 32-bit value to four byte registers.
 *   groups 0..4  three registers 0x10 apart, from 0xCF011880 + group * 0x30 (first, second, third)
 *   group 5      0xCF011970 (first)
 *   group 0xA    0xCF00F510 (first) and 0xCF00F520 (second)
 *   group 0xB    0xCF00F590 (first) and 0xCF00F5A0 (second)
 *   group 0x13   0xCF015B40 (first)
 * Called by sys_frc_load_rom_settings, once per group, with the words of the ROM setting set that the two stored
 * indexes select.
 */
void sys_frc_write_setting_values(unsigned char group, unsigned int first, unsigned int second, unsigned int third)
{
    switch (group) {
    case 0x0:
        reg_write32_bytes(0xcf011880, first);
        reg_write32_bytes(0xcf011890, second);
        reg_write32_bytes(0xcf0118a0, third);
        break;
    case 0x1:
        reg_write32_bytes(0xcf0118b0, first);
        reg_write32_bytes(0xcf0118c0, second);
        reg_write32_bytes(0xcf0118d0, third);
        break;
    case 0x2:
        reg_write32_bytes(0xcf0118e0, first);
        reg_write32_bytes(0xcf0118f0, second);
        reg_write32_bytes(0xcf011900, third);
        break;
    case 0x3:
        reg_write32_bytes(0xcf011910, first);
        reg_write32_bytes(0xcf011920, second);
        reg_write32_bytes(0xcf011930, third);
        break;
    case 0x4:
        reg_write32_bytes(0xcf011940, first);
        reg_write32_bytes(0xcf011950, second);
        reg_write32_bytes(0xcf011960, third);
        break;
    case 0x5:
        reg_write32_bytes(0xcf011970, first);
        break;
    case 0xa:
        reg_write32_bytes(0xcf00f510, first);
        reg_write32_bytes(0xcf00f520, second);
        break;
    case 0xb:
        reg_write32_bytes(0xcf00f590, first);
        reg_write32_bytes(0xcf00f5a0, second);
        break;
    case 0x13:
        reg_write32_bytes(0xcf015b40, first);
        break;
    }
}

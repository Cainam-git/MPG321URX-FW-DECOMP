/* sys_program_block_f500  (FUN_a0109654)
 *
 * Program the register block at 0xCF00F500 or 0xCF00F580 with fixed values and one word.
 * Name basis: descriptive - 1 ms delays between the writes; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0109654 @ 0xa0109654-0xa010983c, flags -mcpu=v8 -O3 -g.
 * Source form the exact build depends on: the two blocks are written out in full in the two arms of 'if (block_select
 * != 0)', one 32-bit store per register in the order listed, with the byte split of 'word' as written.
 */
/* Two register blocks of the same layout, 0x80 bytes apart. */
#define BLOCK_F500 0xcf00f500
#define BLOCK_F580 0xcf00f580
#define R(a) (*(volatile unsigned int *)(a))
extern void timer_sleep_ticks(int ms);

/*
 * Fill one of two register blocks with fixed start values and one 32-bit value, or clear both blocks' first register.
 *
 *   block_select  0: block at 0xCF00F500, anything else: block at 0xCF00F580
 *   word          written to the block bytewise, low byte first, at offsets 0x30, 0x34, 0x38 and 0x3C
 *   enable        0: write 0 to the first register of both blocks and nothing else
 *
 * No routine calls it. With enable set the sequence is: wait (timer_sleep_ticks(1)); 0x40 then 0x80 to offset 0; the
 * fixed values below (the last two: 0x80 to offset 0x60 and 1 to 0x64); wait again; 0x40 then 0x80 to offset 0 once more. The two blocks differ in the values at
 * offsets 0x18 (0xC6 or 0xC8) and 0x28 (0xC8 or 0xCA). Offsets 0x10 and 0x20 are the registers that
 * sys_frc_write_setting_values sets with selector 0xA (block F500) and 0xB (block F580).
 */
void sys_program_block_f500(unsigned char block_select, unsigned int word, unsigned char enable)
{
    if (enable) {
        if (block_select != 0) {
            timer_sleep_ticks(1);
            R(BLOCK_F580) = 0x40;
            R(BLOCK_F580) = 0x80;
            R(BLOCK_F580 + 0x4) = 0x20;
            R(BLOCK_F580 + 0x8) = 0x20;
            R(BLOCK_F580 + 0xc) = 0x20;
            R(BLOCK_F580 + 0x10) = 0;
            R(BLOCK_F580 + 0x14) = 0;
            R(BLOCK_F580 + 0x18) = 0xc8;
            R(BLOCK_F580 + 0x1c) = 0;
            R(BLOCK_F580 + 0x20) = 0;
            R(BLOCK_F580 + 0x24) = 0;
            R(BLOCK_F580 + 0x28) = 0xca;
            R(BLOCK_F580 + 0x2c) = 0;
            R(BLOCK_F580 + 0x30) = word & 0xff;
            R(BLOCK_F580 + 0x34) = (word >> 8) & 0xff;
            R(BLOCK_F580 + 0x38) = (word >> 16) & 0xff;
            R(BLOCK_F580 + 0x3c) = word >> 24;
            R(BLOCK_F580 + 0x60) = 0x80;
            R(BLOCK_F580 + 0x64) = 1;
            timer_sleep_ticks(1);
            R(BLOCK_F580) = 0x40;
            R(BLOCK_F580) = 0x80;
        } else {
            timer_sleep_ticks(1);
            R(BLOCK_F500) = 0x40;
            R(BLOCK_F500) = 0x80;
            R(BLOCK_F500 + 0x4) = 0x20;
            R(BLOCK_F500 + 0x8) = 0x20;
            R(BLOCK_F500 + 0xc) = 0x20;
            R(BLOCK_F500 + 0x10) = 0;
            R(BLOCK_F500 + 0x14) = 0;
            R(BLOCK_F500 + 0x18) = 0xc6;
            R(BLOCK_F500 + 0x1c) = 0;
            R(BLOCK_F500 + 0x20) = 0;
            R(BLOCK_F500 + 0x24) = 0;
            R(BLOCK_F500 + 0x28) = 0xc8;
            R(BLOCK_F500 + 0x2c) = 0;
            R(BLOCK_F500 + 0x30) = word & 0xff;
            R(BLOCK_F500 + 0x34) = (word >> 8) & 0xff;
            R(BLOCK_F500 + 0x38) = (word >> 16) & 0xff;
            R(BLOCK_F500 + 0x3c) = word >> 24;
            R(BLOCK_F500 + 0x60) = 0x80;
            R(BLOCK_F500 + 0x64) = 1;
            timer_sleep_ticks(1);
            R(BLOCK_F500) = 0x40;
            R(BLOCK_F500) = 0x80;
        }
    } else {
        R(BLOCK_F500) = 0;
        R(BLOCK_F580) = 0;
    }
}

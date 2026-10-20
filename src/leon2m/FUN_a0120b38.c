/* leon2m FUN_a0120b38 @ 0xa0120b38  (-mcpu=v8 -O3 -g)
 *
 * Measured input vertical refresh rate of display channel blk, in tenths of Hz (0xFFFF = no valid measurement).
 *   cnt = FUN_a00f21f0(blk, 0x14): a 16-bit frame-period count from registers 0x14/0x15 of the 0x19A2FC-table
 *         block (block 0: 0xCF006B10/0xCF006B14).
 *   cnt outside 1027..18750 -> 0xFFFF.
 *   mode word +4 of the channel's 12-byte record at 0xA8027AAC == 1:  round(120,000,000 / cnt / 32)
 *   otherwise:                                                         round(120,000,000 / cnt / 256)
 * In the /32 mode the result is 3,750,000 / cnt, so 60.000 Hz needs cnt = 6250 and gives 600; inputs from about
 * 60.06 to 60.14 Hz (cnt 6235..6244) give 601 (rounded to nearest). 59.94 Hz gives 599.
 * Caller: FUN_a01070b4 (panel limit check) calls FUN_a0120b38(0) and compares the result with the active
 * panel row's max vfreq (600 for the <62 Hz row): 601 > 600 sets violation bit 0x20.
 * FW.012 has this function byte for byte (file 0x1C7598; only the call distance and the record address
 * 0xA8027A7C differ), so the measurement and its rounding did not change between FW.012 and FW.021.
 */
struct VMode { unsigned int a; unsigned int div32; unsigned int c; };   /* 12-byte per-channel record */
extern struct VMode DAT_a8027aac[];
extern unsigned short FUN_a00f21f0(unsigned char, unsigned char);    /* 16-bit register pair read */

unsigned short FUN_a0120b38(unsigned char blk)
{
    unsigned short cnt = FUN_a00f21f0(blk, 0x14);
    unsigned short v;
    if ((unsigned short)(cnt - 1027) > 0x453b) v = 0xffff;
    else if (DAT_a8027aac[blk].div32 == 1) v = (120000000u / cnt + 0x10) >> 5;
    else v = (120000000u / cnt + 0x80) >> 8;
    return v;
}

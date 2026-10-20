/* leon2m FUN_a00886f8 @ 0xa00886f8  MATCH (-mcpu=v8 -O2 -g)
 * Returns bit 6 of the byte at 0xa802af99 and clears it (mask 0xBF). Same form as FUN_a00b5064 and FUN_a00b5048:
 * the shifted value is held in a local `int`, the masked byte is stored back, and the low bit of the shift is
 * returned.
 */
extern unsigned char DAT_a802af99; // 0xa802af99

int FUN_a00886f8(void)
{
    int bVar1;

    bVar1 = DAT_a802af99 >> 6;
    DAT_a802af99 = DAT_a802af99 & 0xbf;
    return bVar1 & 1;
}

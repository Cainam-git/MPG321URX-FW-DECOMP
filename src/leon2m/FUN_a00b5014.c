/* leon2m FUN_a00b5014 @ 0xa00b5014 (-mcpu=v8 -O2 -g)
 * Returns bit 1 of the byte at 0xa802b08e and clears it (mask 0xFD). Same form as FUN_a00b5064: the shifted value
 * is held in a local `int`, the masked byte is stored back, and the low bit of the shift is returned.
 */
extern unsigned char DAT_a802b08e;   // 0xa802b08e

int FUN_a00b5014(void)
{
    int bVar1;

    bVar1 = DAT_a802b08e >> 1;
    DAT_a802b08e = DAT_a802b08e & 0xfd;
    return bVar1 & 1;
}

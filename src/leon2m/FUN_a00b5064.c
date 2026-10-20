/* leon2m FUN_a00b5064 @ 0xa00b5064 (-mcpu=v8 -O2 -g)
 * Returns bit 2 of the byte at 0xa802b08e and clears it (mask 0xFB). The return value is computed from the loaded
 * byte before the masked byte is stored back.
 */
extern unsigned char DAT_a802b08e;

int FUN_a00b5064(void)
{
    int bVar1;
    
    bVar1 = DAT_a802b08e >> 2;
    DAT_a802b08e = DAT_a802b08e & 0xfb;
    return bVar1 & 1;
}

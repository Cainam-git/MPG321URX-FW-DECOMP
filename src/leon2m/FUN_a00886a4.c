/* leon2m FUN_a00886a4 @ 0xa00886a4 (-mcpu=v8 -O2 -g)
 * Returns bit 2 of byte 0xA802AF99 and clears that bit. Same code as FUN_a00b5064 with other constants.
 */
extern unsigned char DAT_a802af99;

int FUN_a00886a4(void)
{
    int bVar1;
    
    bVar1 = DAT_a802af99 >> 2;
    DAT_a802af99 = DAT_a802af99 & 0xfb;
    return bVar1 & 1;
}

/* leon2m FUN_a00886dc @ 0xa00886dc (-mcpu=v8 -O2 -g)
 * Clears bit 5 of the byte 0xA802AF99 and returns the bit's previous value (0 or 1).
 */
extern unsigned char DAT_a802af99;

unsigned int FUN_a00886dc(void)
{
    int bVar1;
    
    bVar1 = DAT_a802af99 >> 5;
    DAT_a802af99 = DAT_a802af99 & 0xdf;
    return bVar1 & 1;
}

/* leon2m FUN_a00886c0 @ 0xa00886c0  MATCH (-mcpu=v8 -O2 -g)
 * Returns bit 4 of the byte at 0xA802AF99 (0 or 1) and clears that bit in memory (AND 0xEF). The shifted value is
 * held in an int local before the store and masked with & 1 on return.
 */
extern unsigned char DAT_a802af99;

int FUN_a00886c0(void)
{
    int bVar1;
    
    bVar1 = DAT_a802af99 >> 4;
    DAT_a802af99 = DAT_a802af99 & 0xef;
    return bVar1 & 1;
}

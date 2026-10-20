/* leon2m FUN_a00886a4 @ 0xa00886a4  MATCH (-mcpu=v8 -O2 -g, twin)
 * Twin of FUN_a00b5064: same code, constants swapped; byte-exact.
 */
extern unsigned char DAT_a802af99;

int FUN_a00886a4(void)
{
    int bVar1;
    
    bVar1 = DAT_a802af99 >> 2;
    DAT_a802af99 = DAT_a802af99 & 0xfb;
    return bVar1 & 1;
}

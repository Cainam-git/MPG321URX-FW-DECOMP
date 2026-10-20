/* leon2m FUN_a008866c @ 0xa008866c  MATCH (-mcpu=v8 -O2 -g, twin)
 * Twin of FUN_a00b5014: same code, constants swapped; byte-exact.
 */
extern unsigned char DAT_a802af99;   // 0xa802af99

int FUN_a008866c(void)
{
    int bVar1;

    bVar1 = DAT_a802af99 >> 1;
    DAT_a802af99 = DAT_a802af99 & 0xfd;
    return bVar1 & 1;
}

/* leon2m FUN_a0088688 @ 0xa0088688 (-mcpu=v8 -O2 -g)
 * Twin of FUN_a00b5048: same code, other constants.
 */
extern unsigned char DAT_a802af99;

unsigned int FUN_a0088688(void)
{
    unsigned int val = DAT_a802af99;
    unsigned int shifted = val >> 3;
    DAT_a802af99 = val & 0xf7;
    return shifted & 1;
}

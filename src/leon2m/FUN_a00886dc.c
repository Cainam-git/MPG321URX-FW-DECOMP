/* leon2m FUN_a00886dc @ 0xa00886dc  MATCH (-mcpu=v8 -O2 -g)
 * The function reads a byte from `DAT_a802af99`, clears bit 5 (mask with 0xdf), stores it back, and returns bit 5 (after shifting right by 5 and masking with 1). The main uncertainty is whether the return type should be `unsigned int` or `unsigned char` — the assembly leaves the value in `%o0` after the final `and`, which matches an `int` return, but the byte load/store suggests the global is `unsigned char`.
 */
extern unsigned char DAT_a802af99;

unsigned int FUN_a00886dc(void)
{
    int bVar1;
    
    bVar1 = DAT_a802af99 >> 5;
    DAT_a802af99 = DAT_a802af99 & 0xdf;
    return bVar1 & 1;
}

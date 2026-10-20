/* leon2m FUN_a00dd3d4 @ 0xa00dd3d4-0xa00dd43c (26 words).
 * For a non-null word pointer p: prints "\n [", the address (FUN_a00deffc) and "] : " through FUN_a00def40; an
 * address that is not 4-byte aligned prints "Address Fail", otherwise v is stored at p, printed with
 * FUN_a00deffc and followed by "\n". The final "\n" is the string at 0xfef90 (the tail of another string, merged
 * by the linker), so it is named by its address symbol s_000fef90.
 */
extern void FUN_a00def40(const char *);
extern void FUN_a00deffc(unsigned int val);
extern const char s_000fef90[];

void FUN_a00dd3d4(unsigned int *p, unsigned int v)
{
    if (p) {
        FUN_a00def40("\n [");
        FUN_a00deffc((unsigned int)p);
        FUN_a00def40("] : ");
        if ((unsigned int)p & 3)
            FUN_a00def40("Address Fail\n");
        else {
            *p = v;
            FUN_a00deffc(v);
            FUN_a00def40(s_000fef90);
        }
    }
}

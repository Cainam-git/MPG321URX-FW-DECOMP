/* leon2s FUN_a00cdc74 @ 0xa00cdc74-0xa00cdcdc (26 words incl. the unreachable ret/restore pair
 * FUN_a00cdcd4), flags -mcpu=v8 -Os -g.
 * jf 100.00 match=True, rawcmp 0/26 mismatches.
 * Code facts: ch (u8). Word 0 of the 24-byte record DAT_a8078bb0[ch]: bits 16..17 = 1 (andn
 * 0x30000, or 0x10000). a = FUN_a00c9368(ch) (a stub 'retl; mov 1,%o0' that ignores its arg;
 * all other callers pass one, e.g. FUN_a00c9398 / FUN_a00cc900); if a != FUN_a00c972c() (both
 * u8): tail call FUN_a00cca38(a). void.
 * Fix vs the autoc draft (84.62): FUN_a00c9368 takes the channel as its argument (the zero-extended
 * ch stays in %o0 to the call; without the arg local-alloc reuses %i0: 88.46); 24-byte record
 * struct indexed by ch. Aids: none.
 */
struct Rec18 { unsigned int w0; unsigned char pad[0x14]; };
extern struct Rec18 DAT_a8078bb0[];
extern unsigned char FUN_a00c9368(unsigned char);
extern unsigned char FUN_a00c972c(void);
extern void FUN_a00cca38(unsigned char);

void FUN_a00cdc74(unsigned char ch)
{
    unsigned char a;

    DAT_a8078bb0[ch].w0 = (DAT_a8078bb0[ch].w0 & ~0x30000) | 0x10000;
    a = FUN_a00c9368(ch);
    if (a != FUN_a00c972c())
        FUN_a00cca38(a);
}

/* leon2m FUN_a00a012c @ 0xa00a012c-0xa00a01b8 (35 words). BYTE-EXACT: -mcpu=v8 -O3 -g, jf 100 match=True,
 * rawcmp 0/35 (written from the asm; same shape as FUN_a008a09c).
 * What it does (APP event pump FUN_a008a210 callee): runs the event handler FUN_a009f42c() (no arguments: it
 * never reads %i0 before setting it), then picks one pending event code:
 *   v = 0x84 (none); the first of FUN_a00b5014, FUN_a00b5030, FUN_a00b5048, FUN_a00b5064 that returns
 *   nonzero gives v = 0x80, 0x82, 0x81, 0x83 (each callee is a leaf flag test, 'and %o0,1' at its retl);
 *   FUN_a008a184(v) as a tail call.
 * Not rate-dependent (event flags; FUN_a009f42c reads the port state map).
 * Code fact: the fw 'and %i0,0x87' is the u8 argument extension of v, narrowed by combine because every
 * value of v (0x80..0x84) has bits 3..6 clear. volatile: none. Aids: none.
 */
extern void FUN_a009f42c(void);
extern unsigned char FUN_a00b5014(void), FUN_a00b5030(void), FUN_a00b5048(void), FUN_a00b5064(void);
extern void FUN_a008a184(unsigned char code);

void FUN_a00a012c(void)
{
    unsigned char v = 0x84;

    FUN_a009f42c();
    if (FUN_a00b5014())
        v = 0x80;
    else if (FUN_a00b5030())
        v = 0x82;
    else if (FUN_a00b5048())
        v = 0x81;
    else if (FUN_a00b5064())
        v = 0x83;
    FUN_a008a184(v);
}

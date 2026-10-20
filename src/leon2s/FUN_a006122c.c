/* FUN_a006122c (leon2s, 0xa006122c-0xa0061280, 21 words, leaf). Flags -mcpu=v8 -Os -g. jf 100.00 match=True, rawcmp_l2s 0 mismatches.
 Code facts: void (u8 c): waits until bit 5 of the UART status register 0xc00c0014 is set, at most 0xffffe polls, then writes c to 0xc00c0000.
 Fixes vs draft: plain while loop with the counter test inside (gives the fw annulled bgu,a); 0xc00c0000 is a constant hardware address
 (fw 'st %o5,[%g1]' reg+reg form; an extern symbol gives the simm13 form). Aids: none.
 */
#define REG_c00c0000 (*(volatile unsigned int *)0xc00c0000)
#define REG_c00c0014 (*(volatile unsigned int *)0xc00c0014)

void FUN_a006122c(unsigned char c)
{
    unsigned int n = 0;

    while ((REG_c00c0014 & 0x20) == 0) {
        if (++n > 0xffffe)
            break;
    }
    REG_c00c0000 = c;
}

/* FUN_a006122c (leon2s, 0xa006122c-0xa0061280, 21 words, leaf). Flags -mcpu=v8 -Os -g.
 * void (u8 c): waits until bit 5 of the UART status register 0xc00c0014 is set, at most 0xffffe polls, then
 * writes c to 0xc00c0000.
 * Source form: a plain while loop with the counter test inside (gives the firmware's annulled bgu,a);
 * 0xc00c0000 is a constant hardware address (firmware 'st %o5,[%g1]' reg+reg form; an extern symbol gives
 * the simm13 form).
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

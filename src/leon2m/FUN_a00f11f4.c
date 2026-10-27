/* FUN_a00f11f4 (leon2m 0xa00f11f4-0xa00f1298, 164 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Writes the byte v to the word register 0xcf000000 + 4 * (DAT_a8026a7e[c] + k) for c = 0..3; for c = 4 writes it
 * to the registers of entries 0, 1 and 2 (the loop runs i = 0..3 and skips i = 3); other c do nothing. Nothing in
 * the image refers to it: no call, branch, sethi/or constant or address word. It lies between FUN_a00f11ac and
 * FUN_a00f1298. Source form: the c == 4 loop runs to 3 with 'if (i == 3) continue;'.
 */
extern unsigned short DAT_a8026a7e[];

void FUN_a00f11f4(unsigned char c, unsigned short k, unsigned char v)
{
    unsigned char i;

    if (c == 4) {
        for (i = 0; i <= 3; i++) {
            if (i == 3)
                continue;
            *(volatile unsigned int *)(0xcf000000 | ((DAT_a8026a7e[i] + k) << 2)) = v;
        }
    } else if (c <= 3)
        *(volatile unsigned int *)(0xcf000000 | ((DAT_a8026a7e[c] + k) << 2)) = v;
}

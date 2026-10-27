/* FUN_a0104e50 (leon2m 0xa0104e50-0xa0104e80, 48 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Replaces bits 1..4 (mask 0x1e) of the word register 0xcf012890 with those of v and writes the resulting low byte
 * to 0xcf012890 and 0xcf012990. Nothing in the image refers to it: no call, branch, sethi/or constant or address
 * word. It lies between FUN_a0104d18 and FUN_a0104e80. Source form: the merged value is an unsigned char local.
 */
#define REG90 (*(volatile unsigned int *)0xcf012890)
#define REG190 (*(volatile unsigned int *)0xcf012990)

void FUN_a0104e50(unsigned int v)
{
    unsigned char x = (REG90 & ~0x1eu) | (v & 0x1e);

    REG90 = x;
    REG190 = x;
}

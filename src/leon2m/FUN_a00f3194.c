/* FUN_a00f3194 (leon2m 0xa00f3194-0xa00f31bc, 40 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Writes 0xe0 to the word register 0xcf0200d4, then sets bits 5..7 (0xe0) of the word register 0xcf020114
 * (read-modify-write). Nothing in the image refers to it. It lies between FUN_a00f3164 and FUN_a00f31bc.
 */
void FUN_a00f3194(void)
{
    *(volatile unsigned int *)0xcf0200d4 = 0xe0;
    *(volatile unsigned int *)0xcf020114 |= 0xe0;
}

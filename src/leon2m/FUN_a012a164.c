/* FUN_a012a164 (leon2m 0xa012a164-0xa012a1a0, 60 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Copies the 16 words DAT_a802ca5c[0..15] to DAT_a802ca9c[0..15]. Nothing in the image refers to it: no call,
 * branch, sethi/or constant or address word. It lies between FUN_a012a128 and FUN_a012a1a0. Source form: an
 * unsigned char loop counter.
 */
extern int DAT_a802ca5c[];
extern int DAT_a802ca9c[];

void FUN_a012a164(void)
{
    unsigned char i;

    for (i = 0; i < 16; i++)
        DAT_a802ca9c[i] = DAT_a802ca5c[i];
}

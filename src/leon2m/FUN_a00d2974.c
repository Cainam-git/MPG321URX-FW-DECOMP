/* FUN_a00d2974 (leon2m 0xa00d2974-0xa00d2994, 32 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Copies p[6] to the byte DAT_a802b09f and p[7] to the byte DAT_a802b09e, then returns 0xe0. Nothing in the image
 * refers to it: no call, branch, sethi/or constant or address word. It lies between FUN_a00d28d4 and FUN_a00d2994.
 * Source form: two separate extern byte symbols (each store has its own sethi).
 */
extern unsigned char DAT_a802b09f;
extern unsigned char DAT_a802b09e;

unsigned char FUN_a00d2974(unsigned char *p)
{
    DAT_a802b09f = p[6];
    DAT_a802b09e = p[7];
    return 0xe0;
}

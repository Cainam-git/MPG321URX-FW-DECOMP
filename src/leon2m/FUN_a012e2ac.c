/* leon2m FUN_a012e2ac @ 0xa012e2ac-0xa012e3ec (80 words).
 * Expands three 32-byte blocks of the input buffer (block ch at in + ch * 0x20, ch = 0..2) into 0x200-byte
 * tables and passes each to FUN_a010ae8c(ch, 0, 0x200, out). For byte j of a block: x = in byte XOR key[j % 4]
 * with key = 0f f0 10 01; for k = 0..7: t = (acc << 4) + (k * (x << 4) + 4) / 8 (16 bits, acc = sum of the
 * previous x of the block), q = t * DAT_001a31a8[j] / 100 (16 bits); the next two output bytes are q << 2 and
 * q >> 6. The second argument is not used. Called by FUN_a012e3ec.
 * Compiler aids (no instructions): p is assigned in + off again at the end of the byte loop, so p is not loop
 * invariant and the address in + off is formed inside the loop as in the firmware; the unused array pad after out
 * gives the firmware's 8 extra frame bytes.
 */
extern const unsigned char DAT_001a31a8[32];
extern void FUN_a010ae8c(int, int, int, unsigned char *);

void FUN_a012e2ac(unsigned char *in, unsigned char flag)
{
    unsigned char key[4] = { 0x0f, 0xf0, 0x10, 0x01 };
    unsigned char out[0x200];
    unsigned char pad[4];
    unsigned char *p;
    int ch, j, k;
    unsigned char x;
    int off;
    unsigned short n, acc, t, q;

    off = 0;
    for (ch = 0; ch <= 2; ch++) {
        n = 0;
        acc = 0;
        for (j = 0; j < 32; j++) {
            p = in + (unsigned char)off;
            x = p[j] ^ key[j % 4];
            for (k = 0; k < 8; k++) {
                t = (acc << 4) + (k * (x << 4) + 4) / 8;
                q = (unsigned int)(t * DAT_001a31a8[j]) / 100;
                out[n++] = q << 2;
                out[n++] = q >> 6;
            }
            acc += x;
            p = in + (unsigned char)off;
        }
        FUN_a010ae8c(ch, 0, 0x200, out);
        off += 0x20;
    }
}

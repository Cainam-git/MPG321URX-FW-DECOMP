/* leon2m FUN_a012e2ac @ 0xa012e2ac-0xa012e3ec (80 words), flags -mcpu=v8 -O3 -g -msoft-float.
 * Expands three 32-byte blocks of the input buffer (block ch at in + ch * 0x20, ch = 0..2) into 0x200-byte
 * tables and passes each to FUN_a010ae8c(ch, 0, 0x200, out). For byte j of a block: x = in byte XOR key[j % 4]
 * with key = 0f f0 10 01; for k = 0..7: t = (acc << 4) + (k * x * 16 + 4) / 8 (16 bits, acc = sum of the
 * previous x of the block), v = t * DAT_001a31a8[j] / 100 (16 bits); the next two output bytes are v << 2 and
 * v >> 6. The second argument is not used. Called by FUN_a012e3ec.
 * Source form: written like the twin FUN_a012e004 (same file flags -msoft-float, block byte read as
 * in[(unsigned char)off + j] with the key XOR in a second statement); the declarations keep the twin's
 * 'unsigned short q[2]', which this function does not use: the firmware frame (save -632) holds its 8-byte slot at
 * fp-536, the twin's q position, with no access.
 */
extern const unsigned char DAT_001a31a8[32];
extern void FUN_a010ae8c(int, int, int, unsigned char *);

void FUN_a012e2ac(unsigned char *in, unsigned char flag)
{
    unsigned char key[4] = { 0x0f, 0xf0, 0x10, 0x01 };
    unsigned char out[0x200];
    unsigned short q[2];
    int ch, j, k;
    unsigned char x;
    int off;
    unsigned short n, acc, t, v;

    off = 0;
    for (ch = 0; ch <= 2; ch++) {
        n = 0;
        acc = 0;
        for (j = 0; j < 32; j++) {
            x = in[(unsigned char)off + j];
            x ^= key[j % 4];
            for (k = 0; k < 8; k++) {
                t = (acc << 4) + ((k * x << 4) + 4) / 8;
                v = (unsigned int)(t * DAT_001a31a8[j]) / 100;
                out[n++] = v << 2;
                out[n++] = v >> 6;
            }
            acc += x;
        }
        FUN_a010ae8c(ch, 0, 0x200, out);
        off += 0x20;
    }
}

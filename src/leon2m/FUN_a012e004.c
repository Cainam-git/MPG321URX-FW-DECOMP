/* leon2m FUN_a012e004 @ 0xa012e004-0xa012e2ac (170 words), flags -mcpu=v8 -O3 -g -msoft-float.
 * Expands three 32-byte blocks of the input buffer (block ch at in + ch * 0x20, ch = 0..2) into 0x200-byte tables.
 * Byte j of a block is x = in byte XOR key[j % 4] with key = 0f f0 10 01; acc is the 16-bit sum of the previous x.
 * flag != 0: first 32 entries from the block at in + ch * 0x20 + 0x60, v = (unsigned)((double)((acc + x) << 4)
 * + 0.5) (soft-float routines __floatsidf FUN_a0156840, __adddf3 FUN_a01560ac, __fixunsdfsi FUN_a0155160; 0.5 is
 * the literal at 0x19a638); then the bytes j = 4..31 of the block, eight entries each,
 * v = (acc << 4) + (k * (x << 4) + 4) / 8 for k = 0..7; the table goes to FUN_a010ae8c(ch, 0, 0x200, out).
 * flag == 0: out[0] = out[1] = 0, then one entry per byte j = 0..31, q = ((x + acc) << 4) (16 bits) *
 * DAT_001a31a8[j] / 100; the table goes to FUN_a010af6c(ch, out).
 * Each entry is two output bytes: value << 2, then value >> 6. Called by FUN_a012e3ec.
 * Source form: the key is a const local array (its initialising stores keep their place before the load of the
 * 0.5 literal); the scaled value is stored in an unsigned short array element (the firmware's halfword store at
 * fp-536); the second loop reads the block through p = in + (unsigned char)off as in FUN_a012e2ac.
 * Compiler aid (no instructions): p is assigned in + off again at the end of the second loop body, so the address
 * is formed inside the loop as in the firmware (same form as FUN_a012e2ac).
 */
extern const unsigned char DAT_001a31a8[32];
extern void FUN_a010ae8c(int, int, int, unsigned char *);
extern void FUN_a010af6c(int, unsigned char *);

void FUN_a012e004(unsigned char *in, unsigned char flag)
{
    const unsigned char key[4] = { 0x0f, 0xf0, 0x10, 0x01 };
    unsigned char out[0x200];
    unsigned short q[2];
    unsigned char *p;
    int ch, j, k;
    unsigned char x;
    int off;
    unsigned short n, acc, t;
    unsigned int v;

    off = 0;
    for (ch = 0; ch <= 2; ch++) {
        n = 0;
        acc = 0;
        if (flag) {
            for (j = 0; j < 32; j++) {
                x = in[(unsigned char)off + 0x60 + j] ^ key[j % 4];
                v = (unsigned int)((double)((acc + x) << 4) + 0.5);
                out[n++] = v << 2;
                out[n++] = v >> 6;
                acc += x;
            }
        } else {
            out[0] = 0;
            out[1] = 0;
            n = 2;
        }
        for (j = 0; j < 32; j++) {
            if (j == 0 && flag)
                j = 4;
            p = in + (unsigned char)off;
            x = p[j] ^ key[j % 4];
            if (flag) {
                for (k = 0; k < 8; k++) {
                    v = (acc << 4) + (k * (x << 4) + 4) / 8;
                    out[n++] = v << 2;
                    out[n++] = v >> 6;
                }
            } else {
                v = x + acc;
                t = v << 4;
                q[0] = (unsigned int)(t * DAT_001a31a8[j]) / 100;
                out[n++] = q[0] << 2;
                out[n++] = q[0] >> 6;
            }
            acc += x;
            p = in + (unsigned char)off;
        }
        if (flag)
            FUN_a010ae8c(ch, 0, 0x200, out);
        else
            FUN_a010af6c(ch, out);
        off += 0x20;
    }
}

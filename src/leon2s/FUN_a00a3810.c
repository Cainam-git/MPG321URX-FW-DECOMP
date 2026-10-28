/* FUN_a00a3810 (leon2s, 0xa00a3810-0xa00a3a10). Flags -mcpu=v8 -Os -g.
 * u8 port. If ARR_a807db6c[port] != DAT_a807873c[port]: prints DAT_a006bb08 with port and copies db6c[port]
 * into 873c[port]. DAT_a80791d0[port] = FUN_a0091d64(port, 1). When the low byte of FUN_a0091960(port) is 1 and
 * (DAT_a80791b2 == 0, or d8[port] != 0 && e0[port] == 1 && d0[port] != 0, or DAT_a80791b2 == 0 again):
 * v = DAT_a80791d8[port]; v <= 6 is stored to the word DAT_a80791fc[port] and the byte at offset 0x12 of the
 * 28-byte record ARR_a807d580[port]; with DAT_a80791b2 == 0 and v == 0 both get 5; then
 * FUN_a0091918(port, fc[port]), FUN_a0094fb0(fc[port]), db6c[port] = 2, return 0.
 * Otherwise db6c[port] = 6 (and FUN_a0091988(port) when FUN_a0091960 returned 1), FUN_a0091b74(port), and in
 * the word at offset 0x14 of ARR_a807d580[port] bit 11 is cleared and bit 12 set. Returns 0.
 * Source form: the first block indexes the word arrays through 'idx = port' (as in FUN_a00a3a10), the later
 * accesses use the byte parameter, and the final FUN_a0091b74 call passes idx.
 * Compiler aid: __builtin_expect(DAT_a80791b2 == 0, 0) on the last term of the condition emits no
 * instructions; it changes the branch prediction so the delay slot of that test is filled from the
 * db6c[port] = 6 path.
 */
struct Ch1c { unsigned char pad[0x12]; unsigned char b12; unsigned char pad13; unsigned int w14; unsigned char rest[4]; };
extern struct Ch1c ARR_a807d580[];
extern unsigned int ARR_a807db6c[];
extern unsigned int DAT_a807873c[];
extern unsigned int DAT_a80791fc[];
extern unsigned char DAT_a80791b2;
extern unsigned char DAT_a80791d0[];
extern unsigned char DAT_a80791d8[];
extern unsigned char DAT_a80791e0[];
extern const char DAT_a006bb08[];
extern int FUN_a0073044(const char *, ...);
extern unsigned char FUN_a0091d64(unsigned int, unsigned int);
extern unsigned int FUN_a0091960(unsigned int);
extern void FUN_a0091918(unsigned int, unsigned char);
extern void FUN_a0094fb0(unsigned char);
extern void FUN_a0091988(unsigned int);
extern void FUN_a0091b74(unsigned int);

int FUN_a00a3810(unsigned char port)
{
    unsigned char v;
    unsigned int idx;

    idx = port;
    if (ARR_a807db6c[idx] != DAT_a807873c[idx]) {
        FUN_a0073044(DAT_a006bb08, port);
        DAT_a807873c[idx] = ARR_a807db6c[idx];
    }
    DAT_a80791d0[port] = FUN_a0091d64(port, 1);
    if ((unsigned char)FUN_a0091960(port) == 1) {
        if (DAT_a80791b2 == 0 || (DAT_a80791d8[port] != 0 && DAT_a80791e0[port] == 1 && DAT_a80791d0[port] != 0)
            || __builtin_expect(DAT_a80791b2 == 0, 0)) {
            v = DAT_a80791d8[port];
            if (v <= 6) {
                DAT_a80791fc[port] = v;
                ARR_a807d580[port].b12 = v;
            }
            if (DAT_a80791b2 == 0)
                if (v == 0) {
                    DAT_a80791fc[port] = 5;
                    ARR_a807d580[port].b12 = 5;
                }
            FUN_a0091918(port, DAT_a80791fc[port]);
            FUN_a0094fb0(DAT_a80791fc[port]);
            ARR_a807db6c[port] = 2;
            return 0;
        }
        ARR_a807db6c[port] = 6;
        FUN_a0091988(port);
    } else {
        ARR_a807db6c[idx] = 6;
    }
    FUN_a0091b74(idx);
    ARR_a807d580[idx].w14 = (ARR_a807d580[idx].w14 & ~0x800) | 0x1000;
    return 0;
}

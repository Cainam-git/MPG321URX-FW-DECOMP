/* FUN_a00aa3a4 (leon2s 0xa00aa3a4-0xa00aa45c, 184 bytes), flags -mcpu=v8 -Os -g.
 * Register bank writes through FUN_a00a7b64(bank, reg, value) and reads through FUN_a00a7acc(bank, reg).
 * port 0: register 0:9 = (old 0:9 & 0x08) | 0x91, register 0:0xa = 0x11, then tail call FUN_a00aa2d0().
 * Other ports: once (while the byte flag DAT_a8079304 is 0) writes 1:0x64 = 7 and 1:0x63 = 0x94, calls
 * FUN_a00aa308() and sets the flag; then writes port:0xc = 0x10 and port:0xd = 8.
 */
extern unsigned char DAT_a8079304;
extern unsigned char FUN_a00a7acc(unsigned char, unsigned short);
extern void FUN_a00a7b64(unsigned char, unsigned short, unsigned char);
extern void FUN_a00aa2d0(void);
extern void FUN_a00aa308(void);

void FUN_a00aa3a4(unsigned char port)
{
    if (port == 0) {
        FUN_a00a7b64(0, 9, (FUN_a00a7acc(0, 9) & 0x08) | 0x91);
        FUN_a00a7b64(0, 10, 0x11);
        FUN_a00aa2d0();
        return;
    }
    if (DAT_a8079304 == 0) {
        FUN_a00a7b64(1, 100, 7);
        FUN_a00a7b64(1, 99, 0x94);
        FUN_a00aa308();
        DAT_a8079304 = 1;
    }
    FUN_a00a7b64(port, 0xc, 0x10);
    FUN_a00a7b64(port, 0xd, 8);
}

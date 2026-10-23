/* leon2m FUN_a00ad1c0 @ 0xa00ad1c0-0xa00ad460 (168 words), flags -mcpu=v8 -O3 -g -msoft-float.
 * FUN_a0146b50(0x92, 0), func_0x4008e2a4(); for i = 5..0x14: FUN_a0146b20(0, 0x13, i, 0x13, 0, 0) and
 * FUN_a0146a80(0x13, i, 0x13, 0x792, 0); FUN_a0146b20(0, 0x1c, 0x15, 2, 0, 0), FUN_a0146c40(5, 0, 0),
 * FUN_a0146b6c(0, 0). mode 0: for i = 0..6, FUN_a0146a80(0x14, i * 2 + 6, 0xd, 0x292, 0) when FUN_a00aa520(i) is
 * 0, then entry i * 29 + byte DAT_a802d290+8 of the table DAT_001874f8 (FUN_a00a3844) to FUN_a00a31a4(0, 0x14,
 * i * 2 + 6, 1, entry, 0); other modes: the same for i = 7..9 with rows (i % 7) * 2 + 6 and i * 2 - 8.
 * Then FUN_a00b32e4(1, 1, 0x792, 0x1c, 0x15, 2, 0x28); mode 0 calls FUN_a00b7944() and FUN_a00b7980(), mode 1
 * FUN_a00b79d0() and FUN_a00b7a08() (tail call).
 * Source form: the mode 0 loop limit is a local (n = 7; i < n gives the cmp 7 / bcc exit test); the two final
 * mode tests are separate ifs (the mode 0 calls are then not tail calls).
 */
struct St {
    unsigned char pad[8];
    unsigned char b08;
};
extern struct St DAT_a802d290;
extern unsigned int DAT_001874f8[];
extern void FUN_a0146b50(unsigned short, unsigned char);
extern void FUN_a0146b6c(int, int);
extern void func_0x4008e2a4(void);
extern void FUN_a0146b20(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);
extern void FUN_a0146a80(unsigned int, unsigned int, unsigned char, unsigned int, unsigned char);
extern void FUN_a0146c40(int, int, int);
extern unsigned char FUN_a00aa520(unsigned char);
extern unsigned int FUN_a00a3844(unsigned int *, unsigned short);
extern void FUN_a00a31a4(int, int, unsigned short, int, unsigned int, int);
extern void FUN_a00b32e4(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int,
                         unsigned int);
extern void FUN_a00b7944(void);
extern void FUN_a00b7980(void);
extern void FUN_a00b79d0(void);
extern void FUN_a00b7a08(void);

void FUN_a00ad1c0(unsigned char mode)
{
    unsigned char i;
    unsigned char n = 7;

    FUN_a0146b50(0x92, 0);
    func_0x4008e2a4();
    for (i = 5; i <= 0x14; i++) {
        FUN_a0146b20(0, 0x13, i, 0x13, 0, 0);
        FUN_a0146a80(0x13, i, 0x13, 0x792, 0);
    }
    FUN_a0146b20(0, 0x1c, 0x15, 2, 0, 0);
    FUN_a0146c40(5, 0, 0);
    FUN_a0146b6c(0, 0);
    if (mode == 0) {
        for (i = 0; i < n; i++) {
            if (!FUN_a00aa520(i))
                FUN_a0146a80(0x14, i * 2 + 6, 0xd, 0x292, 0);
            FUN_a00a31a4(0, 0x14, i * 2 + 6, 1, FUN_a00a3844(DAT_001874f8, i * 29 + DAT_a802d290.b08), 0);
        }
    } else {
        for (i = 7; i <= 9; i++) {
            if (!FUN_a00aa520(i))
                FUN_a0146a80(0x14, (i % 7) * 2 + 6, 0xd, 0x292, 0);
            FUN_a00a31a4(0, 0x14, i * 2 - 8, 1, FUN_a00a3844(DAT_001874f8, i * 29 + DAT_a802d290.b08), 0);
        }
    }
    FUN_a00b32e4(1, 1, 0x792, 0x1c, 0x15, 2, 0x28);
    if (mode == 0) {
        FUN_a00b7944();
        FUN_a00b7980();
    }
    if (mode == 1) {
        FUN_a00b79d0();
        FUN_a00b7a08();
    }
}

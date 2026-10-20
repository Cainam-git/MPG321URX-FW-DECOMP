/* leon2m FUN_a00b7188 @ 0xa00b7188-0xa00b72cc (81 words), flags -mcpu=v8 -O3 -g.
 * Code facts: FUN_a00ab5f0(0x2c, 6, (byte 0xa802d290+0x49) * 20 as u8, 6, p1 & 0xff); p1 != 0 -> v = 0x742,
 * FUN_a00a9468(1, 3); else v = 0x792, FUN_a00a9468(1, 2) (u16 v, 'and 0x7d2' = its zero-extension);
 * FUN_a0146a80(0x28/0x2b/0x32, 6, 3/1/1, v, 0) with FUN_a0146b20(0, 0x2b/0x32, 6, 1, 0x3f/0x40, 0) after the 2nd
 * and 3rd; FUN_a0146b50(0xe6, 0); FUN_a01577f4(buf[8] at %fp-16, 0x1981d0, byte +0x49); buf[0] = 3;
 * FUN_a0146b6c(2, 0); FUN_a00a31a4(0, 0x28, 6, 2, buf, 0). One parameter (u8).
 * Twin of FUN_a00b7e68: same body, the x value and the format value come from record byte DAT_a802d290.b49 instead
 * of parameters and there is no FUN_a0146b50(0x111, 0) first.
 * Source form: v is set in both arms; the prototypes as in FUN_a00b7e68; the record as a struct.
 * Compiler aids: none.
 */
struct R290 { unsigned char pad[0x49]; unsigned char b49; };
extern struct R290 DAT_a802d290;
extern void FUN_a0146b50(unsigned int, unsigned char);
extern void FUN_a00ab5f0(unsigned int, unsigned int, unsigned char, unsigned int, unsigned int);
extern void FUN_a00a9468(unsigned int, unsigned int);
extern void FUN_a0146a80(unsigned int, unsigned int, unsigned char, unsigned int, unsigned char);
extern void FUN_a0146b20(unsigned int, unsigned int, unsigned int, unsigned char, unsigned char, unsigned char);
extern void FUN_a01577f4(unsigned char *, unsigned int, unsigned char);
extern void FUN_a0146b6c(unsigned int, unsigned int);
extern void FUN_a00a31a4(unsigned int, unsigned int, unsigned int, unsigned int, unsigned char *, unsigned int);

void FUN_a00b7188(unsigned char param_1)
{
    unsigned short uVar1;
    unsigned char local_10[8];

    FUN_a00ab5f0(0x2c, 6, DAT_a802d290.b49 * 20, 6, param_1);

    if (param_1 != 0) {
        uVar1 = 0x742;
        FUN_a00a9468(1, 3);
    } else {
        uVar1 = 0x792;
        FUN_a00a9468(1, 2);
    }

    FUN_a0146a80(0x28, 6, 3, uVar1, 0);
    FUN_a0146a80(0x2b, 6, 1, uVar1, 0);
    FUN_a0146b20(0, 0x2b, 6, 1, 0x3f, 0);
    FUN_a0146a80(0x32, 6, 1, uVar1, 0);
    FUN_a0146b20(0, 0x32, 6, 1, 0x40, 0);
    FUN_a0146b50(0xe6, 0);

    FUN_a01577f4(local_10, 0x1981d0, DAT_a802d290.b49);
    local_10[0] = 3;
    FUN_a0146b6c(2, 0);
    FUN_a00a31a4(0, 0x28, 6, 2, local_10, 0);
}

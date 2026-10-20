/* FUN_a0095d78 (leon2s 0xa0095d78-0xa0095e08, 144 bytes), flags -mcpu=v8 -Os -g.
 * Compares FUN_a0095d34(port) (byte) with the byte DAT_a8078c50[port]. When they differ, stores a second
 * FUN_a0095d34(port) result there; when that is non-zero calls FUN_a0095ca4(port, 0), sets DAT_a8078c48[port] to 1
 * and tail-calls FUN_a00a33f4(port, 0x9f1b0200 + port * 0x200); when it is 0 calls the ROM routine
 * func_0x9f1b8a1c(port) and clears DAT_a8078c48[port].
 */
extern unsigned char DAT_a8078c50[];
extern unsigned char DAT_a8078c48[];
extern int FUN_a0095d34(unsigned char);
extern void FUN_a0095ca4(unsigned char, unsigned char);
extern void FUN_a00a33f4(unsigned char, unsigned int);
extern void func_0x9f1b8a1c(unsigned char);

void FUN_a0095d78(unsigned char port)
{
    unsigned char v;

    if (DAT_a8078c50[port] == (unsigned char)FUN_a0095d34(port))
        return;
    v = FUN_a0095d34(port);
    DAT_a8078c50[port] = v;
    if (v != 0) {
        FUN_a0095ca4(port, 0);
        DAT_a8078c48[port] = 1;
        FUN_a00a33f4(port, 0x9f1b0200 + port * 0x200);
    } else {
        func_0x9f1b8a1c(port);
        DAT_a8078c48[port] = 0;
    }
}

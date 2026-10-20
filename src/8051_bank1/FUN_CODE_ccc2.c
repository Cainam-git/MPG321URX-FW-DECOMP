/* 8051_bank1 FUN_CODE_ccc2 @ 0xccc2 (69 B)  Byte-exact with OPTIMIZE(8,SPEED) LARGE.
 * Sets XDATA 0xA64D to 0x1F; when m == 1 it also resets all ten 3-byte entries of the table at 0xA62F to
 * {0x1F, 0xFF, 0xFF} (0x1F in the low five bits of byte 0 is the end marker that FUN_CODE_d27f stops at).
 * Callers: FUN_CODE_3fe7 at start-up with m = 1, and the command switch FUN_CODE_224f with m = 0 (0x2523).
 * The loop counter reuses R7 (m is dead after the test); 'XRL A,#1 / JNZ' leaves A = 0 for 'i = 0'.
 */
struct ent3 { unsigned char a, b, c; };
extern struct ent3 xdata DAT_EXTMEM_a62f[10];
extern unsigned char xdata DAT_EXTMEM_a64d;

void FUN_CODE_ccc2(unsigned char m)
{
    unsigned char i;

    DAT_EXTMEM_a64d = 0x1f;
    if (m == 1) {
        for (i = 0; i < 10; i++) {
            DAT_EXTMEM_a62f[i].a = 0x1f;
            DAT_EXTMEM_a62f[i].b = 0xff;
            DAT_EXTMEM_a62f[i].c = 0xff;
        }
    }
}

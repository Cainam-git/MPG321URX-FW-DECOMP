/* 8051_bank1 FUN_CODE_8622 @ 0x8622..0x8731 (271 B)  Options: OPTIMIZE(8,SPEED) LARGE.
 * FUN_CODE_8622(dev, reg, n, buf): FUN_CODE_97c4(); up to 10 tries of FUN_CODE_6781(dev), with FUN_CODE_d086()
 * between tries, until it returns 0. When a try returned 0: FUN_CODE_6781 with the high and the low byte of reg
 * (XDATA 0xA70C == 1) or with the low byte only; FUN_CODE_97c4(); up to 10 tries of FUN_CODE_6781(dev | 1) the same
 * way; then for i = 0..n-1: XDATA 0xF00A = 0x55 and buf[i] = FUN_CODE_8c5d(1 for the last i, else 0). Ends with
 * FUN_CODE_c6ec() on both paths. Parameters and locals live in the LARGE parameter block (dev 0xA740,
 * reg 0xA741..0xA742, n 0xA743..0xA744, buf 0xA745..0xA747 generic pointer, i 0xA748..0xA749).
 * Source form: the two FUN_CODE_8c5d calls are separate statements ('CLR A / MOV R7,A' for the 0, shared call and
 * store), and FUN_CODE_c6ec() is written in both arms of 'if (i != 10)' (shared 'LCALL / RET' tail instead of LJMP).
 * volatile on 0xF00A: hardware register written in the loop.
 */
extern unsigned char volatile xdata DAT_EXTMEM_f00a;
extern unsigned char xdata DAT_EXTMEM_a70c;
extern void FUN_CODE_97c4(void);
extern unsigned char FUN_CODE_6781(unsigned char v);
extern void FUN_CODE_d086(void);
extern unsigned char FUN_CODE_8c5d(unsigned char last);
extern void FUN_CODE_c6ec(void);

void FUN_CODE_8622(unsigned char dev, unsigned int reg, unsigned int n, unsigned char *buf)
{
    unsigned int i;

    FUN_CODE_97c4();
    for (i = 0; i < 10; i++) {
        if (!FUN_CODE_6781(dev))
            break;
        FUN_CODE_d086();
    }
    if (i != 10) {
        if ((unsigned int)DAT_EXTMEM_a70c == 1) {
            FUN_CODE_6781(reg >> 8);
            FUN_CODE_6781(reg);
        } else {
            FUN_CODE_6781(reg);
        }
        FUN_CODE_97c4();
        for (i = 0; i < 10; i++) {
            if (!FUN_CODE_6781(dev | 1))
                break;
            FUN_CODE_d086();
        }
        for (i = 0; i < n; i++) {
            DAT_EXTMEM_f00a = 0x55;
            if (i == n - 1) buf[i] = FUN_CODE_8c5d(1); else buf[i] = FUN_CODE_8c5d(0);
        }
        FUN_CODE_c6ec();
    } else {
        FUN_CODE_c6ec();
    }
}

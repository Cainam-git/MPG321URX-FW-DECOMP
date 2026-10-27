/* 8051_bank1 FUN_CODE_a41f @ 0xa41f..0xa4d2 (179 B)  Options: OPTIMIZE(8,SPEED) LARGE.
 * FUN_CODE_a41f(op): one 0x200-byte read through the 0xF0E5..0xF1C0 register block with command byte op; each byte
 * read is passed to FUN_CODE_2820 (printf). Register set-up as in FUN_CODE_7ca8: 0xF0E6 = (0xF0E6 & 0x0C) | 0x01, 0xF0EA = op,
 * 0xF0EB = 0, 0xF0EC/0xF0ED = 0x0200, 0xF0F0/0xF0F1/0xF0F2 = XDATA 0xA74E/0xA750/0xA74F, 0xF0F4 = 0x0B,
 * 0xF1C0 = 0x81, 0xF0E5 = 2 and wait for bit 1 clear, 0xF1C0 = 0x82 and one read of 0xF1C0 into v. Then for
 * i = 0..0x1FF: v = 0xF1C0; when (i & 0x0F) == 0, FUN_CODE_2820("\r\n%04X:" at CODE 0xA32C, i); then
 * FUN_CODE_2820("%02bX " at CODE 0xA334, v). Locals (LARGE): v 0xA767, i 0xA768..0xA769.
 * Source form: the 0xF0E6 update is an unsigned int expression; the char form makes Keil move op from R7 to R5
 * at entry (MOV R5,AR7) because that expression uses R7 as a temporary.
 * volatile on the 0xF0xx / 0xF1C0 registers: hardware registers (0xF1C0 is read repeatedly, 0xF0E5 is polled).
 */
extern unsigned char volatile xdata DAT_EXTMEM_f0e5, DAT_EXTMEM_f0e6, DAT_EXTMEM_f0ea, DAT_EXTMEM_f0eb, DAT_EXTMEM_f0ec, DAT_EXTMEM_f0ed;
extern unsigned char volatile xdata DAT_EXTMEM_f0f0, DAT_EXTMEM_f0f1, DAT_EXTMEM_f0f2, DAT_EXTMEM_f0f4, DAT_EXTMEM_f1c0;
extern unsigned char xdata DAT_EXTMEM_a74e, DAT_EXTMEM_a74f, DAT_EXTMEM_a750;
extern void FUN_CODE_2820(void *fmt, ...) large;

void FUN_CODE_a41f(unsigned char op)
{
    unsigned char v;
    unsigned int i;

    DAT_EXTMEM_f0e6 = (unsigned int)DAT_EXTMEM_f0e6 & 0x0c | 0x01;
    DAT_EXTMEM_f0ea = op;
    DAT_EXTMEM_f0eb = 0;
    DAT_EXTMEM_f0ec = 2;
    DAT_EXTMEM_f0ed = 0;
    DAT_EXTMEM_f0f0 = DAT_EXTMEM_a74e;
    DAT_EXTMEM_f0f1 = DAT_EXTMEM_a750;
    DAT_EXTMEM_f0f2 = DAT_EXTMEM_a74f;
    DAT_EXTMEM_f0f4 = 0x0b;
    DAT_EXTMEM_f1c0 = 0x81;
    DAT_EXTMEM_f0e5 = 2;
    while ((unsigned int)(DAT_EXTMEM_f0e5 & 2)) ;
    DAT_EXTMEM_f1c0 = 0x82;
    v = DAT_EXTMEM_f1c0;
    for (i = 0; i < 0x200; i++) {
        v = DAT_EXTMEM_f1c0;
        if ((i & 0x0f) == 0) FUN_CODE_2820((void code *)0xa32c, i);
        FUN_CODE_2820((void code *)0xa334, v);
    }
}

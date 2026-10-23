/* 8051_bank1 FUN_CODE_78ba @ 0x78ba..0x7a0b (337 bytes), OPTIMIZE(8,SPEED) LARGE.
 * Handles one message in the XDATA block at 0xD80D (status), 0xD80F, 0xD821.. (4 reply bytes), 0xD831 (header),
 * 0xD832.. (16 data bytes). Returns 5 (after writing 0x38 back) when any of status bits 3..5 is set, 6 when bit 0
 * is clear or 0xD80F is 0 (status = 1 in the latter case). Otherwise the header and the 16 data bytes are copied
 * (buf), XDATA 0xA75A = header bits 7..4, and buf[0] selects the action:
 *   header bits 3..0 == 0xF: 0x36: XDATA 0xA758 |= 2; 0x82: 0xA757 = 0xA75A and 0xA758 |= 4 when buf[1] != 0.
 *   otherwise: 0x9D: 0xA758 |= 8; 0x83: reply 84 00 00 00, FUN_CODE_bf7b(0x0F, 4); 0x36: 0xA758 |= 2;
 *   0x91: reply 32 65 6E 67, FUN_CODE_bf7b(0xA75A, 4); 0x8F: reply 90 and FUN_CODE_df0b() as 0/1,
 *   FUN_CODE_bf7b(0xA75A, 2); 0x0F: reply 00 02, FUN_CODE_bf7b(0xA75A, 2); 0x93 / 0xFF: reply 00 00 00,
 *   FUN_CODE_bf7b(0xA75A, 3); 0x44: 0xA759 = buf[1], 0xA758 |= 0x10.
 * Then status = 1 and the function returns 1.
 * LARGE local: buf[16] at XDATA 0xA474; header in R7, loop counter in R6.
 * volatile on 0xD80D: read again for the bit-0 test.
 * Source form: the case bodies are written in the firmware's code order (the ?C?CCASE table itself is sorted);
 *   the first switch lists 0x36 before 0x82; the bit-0 test wraps the rest of the function so 'return 6' is the
 *   shared tail; the FUN_CODE_df0b test is negated ('!df0b()' first arm stores 0).
 * Caller: FUN_CODE_c4ee (LCALL at 0xC4F3).
 */
extern unsigned char volatile xdata DAT_EXTMEM_d80d;
extern unsigned char xdata DAT_EXTMEM_d80f;
extern unsigned char xdata DAT_EXTMEM_d831;
extern unsigned char xdata DAT_EXTMEM_d832[16];
extern unsigned char xdata DAT_EXTMEM_d821[4];
extern unsigned char xdata DAT_EXTMEM_a757, DAT_EXTMEM_a758, DAT_EXTMEM_a759, DAT_EXTMEM_a75a;
extern bit FUN_CODE_df0b(void);
extern void FUN_CODE_bf7b(unsigned char a, unsigned char n);

unsigned char FUN_CODE_78ba(void)
{
    unsigned char buf[16];
    unsigned char hdr;
    unsigned char i;

    if (DAT_EXTMEM_d80d & 0x38) {
        DAT_EXTMEM_d80d = 0x38;
        return 5;
    }
    if (DAT_EXTMEM_d80d & 0x01) {
        if (DAT_EXTMEM_d80f == 0) {
            DAT_EXTMEM_d80d = 0x01;
            return 6;
        }
        hdr = DAT_EXTMEM_d831;
        for (i = 0; i < 16; i++)
            buf[i] = DAT_EXTMEM_d832[i];
        DAT_EXTMEM_a75a = (hdr & 0xf0) >> 4;
        if ((hdr & 0x0f) == 0x0f) {
            switch (buf[0]) {
            case 0x36:
                DAT_EXTMEM_a758 |= 0x02;
                break;
            case 0x82:
                DAT_EXTMEM_a757 = DAT_EXTMEM_a75a;
                if (buf[1])
                    DAT_EXTMEM_a758 |= 0x04;
                break;
            }
        } else {
            switch (buf[0]) {
            case 0x9d:
                DAT_EXTMEM_a758 |= 0x08;
                break;
            case 0x83:
                DAT_EXTMEM_d821[0] = 0x84;
                DAT_EXTMEM_d821[1] = 0x00;
                DAT_EXTMEM_d821[2] = 0x00;
                DAT_EXTMEM_d821[3] = 0x00;
                FUN_CODE_bf7b(0x0f, 4);
                break;
            case 0x36:
                DAT_EXTMEM_a758 |= 0x02;
                break;
            case 0x91:
                DAT_EXTMEM_d821[0] = 0x32;
                DAT_EXTMEM_d821[1] = 0x65;
                DAT_EXTMEM_d821[2] = 0x6e;
                DAT_EXTMEM_d821[3] = 0x67;
                FUN_CODE_bf7b(DAT_EXTMEM_a75a, 4);
                break;
            case 0x8f:
                DAT_EXTMEM_d821[0] = 0x90;
                if (!FUN_CODE_df0b())
                    DAT_EXTMEM_d821[1] = 0x00;
                else
                    DAT_EXTMEM_d821[1] = 0x01;
                FUN_CODE_bf7b(DAT_EXTMEM_a75a, 2);
                break;
            case 0x0f:
                DAT_EXTMEM_d821[0] = 0x00;
                DAT_EXTMEM_d821[1] = 0x02;
                FUN_CODE_bf7b(DAT_EXTMEM_a75a, 2);
                break;
            case 0x93:
            case 0xff:
                DAT_EXTMEM_d821[0] = 0x00;
                DAT_EXTMEM_d821[1] = 0x00;
                DAT_EXTMEM_d821[2] = 0x00;
                FUN_CODE_bf7b(DAT_EXTMEM_a75a, 3);
                break;
            case 0x44:
                DAT_EXTMEM_a759 = buf[1];
                DAT_EXTMEM_a758 |= 0x10;
                break;
            }
        }
        DAT_EXTMEM_d80d = 0x01;
        return 1;
    }
    return 6;
}

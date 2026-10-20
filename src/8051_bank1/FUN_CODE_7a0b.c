/* 8051_bank1 FUN_CODE_7a0b @ 0x7a0b..0x7b5a (335 bytes)  STBC power-off hardware sequence.
 * MATCH: tools/diff8051.py 8051_bank1 FUN_CODE_7a0b -> 335/335 bytes, 100 %, exact None, at OPTIMIZE(8,SPEED) (also
 * LARGE). Keys: 0x5034/0x5035 and 0x5134/0x5135 are one 16-bit register each (fw MOV A,#0FFH / MOVX / INC DPTR /
 * MOV A,#34H: a 16-bit store of 0xFF34); the final call is a tail call (fw LJMP 0xA142).
 * Callers (code): the Big-chip command 0x17 CMD_SYS_POWEROFF case of FUN_CODE_224f (0x2553) and the crash path of
 * the liveness check FUN_CODE_7b5a (0x7C9C), both right after STOP Leon2 Main (cbac), STOP Leon2 Sub (cbf2),
 * 0xF150 = 9 and 0xF152 |= 0x40.
 * What the code does (code facts): bit 0x0E = 1; 0xF1E0 = 0xC1; writes the same 13-value pattern into the two register
 *   blocks 0x5000 and 0x5100 (+9 = 0x93, +5 = 0x53, +0xE = 0, +8 = 6, +6 = 0x1C, +0x34 = 0xFF34, +2 = 0x14, +0 = 0x88,
 *   +0xC = 0x35, +0xB = 0xFF, +0xA = 0x20); 0xD929 = 0x71; clears 0xD90B bit 7, 0xD904 bits 7..4, 0xD905 bit 7, sets
 *   0xD90C bit 0; for chip ID 0xD511 == 0x20 also clears further bits in 0xD90B/0xD904/0xD90F/0xD92D/0xDA00 and in
 *   the 0xE1xx block and zeroes 0xD910/0xD911/0xD912/0xE1D8; then 0xD52C |= 0x0C, 0xD52D |= 0x82; FUN_CODE_dc51
 *   (0xF1DF |= 0x80, chip-dependent 0xF1A8 bit 0); XDATA 0xA6EE = 0; FUN_CODE_daad (Timer-0 reload words
 *   0xA772/0xA773 = 0xFC/0x18, i.e. 1000 counts per tick, then the clock switch FUN_CODE_d802); FUN_CODE_a142(1).
 *   The individual hardware registers are not named; from the callers, this is the hardware part of the power-off
 *   path (the command handler prints "CMD_SYS_POWEROFF" before the call).
 * After a liveness-check trip the 8051 runs exactly the CMD_SYS_POWEROFF hardware sequence and then
 *   parks in 'SJMP $' instead of entering the run-state-1 wake-source polling of FUN_CODE_3fe7, so no wake source is
 *   polled after a trip; only an external reset restarts the 8051.
 * volatile: the 0x50xx/0x51xx/0xD5xx/0xD9xx/0xDAxx/0xE1xx/0xF1xx addresses are treated as hardware registers
 *   (outside the RAM that the Keil start-up clears, 0xA000..0xAFFF and 0xF800..0xFFFF; fixed bit patterns, 0xD90B is
 *   cleared twice in a row for chip 0x20); 0xA6EE is RAM inside 0xA000..0xAFFF (not volatile).
 */
extern bit BITS_21_6;
extern unsigned char volatile xdata DAT_EXTMEM_f1e0;
extern unsigned char volatile xdata DAT_EXTMEM_5009, DAT_EXTMEM_5005, DAT_EXTMEM_500e, DAT_EXTMEM_5008, DAT_EXTMEM_5006;
extern unsigned int volatile xdata DAT_EXTMEM_5034;
extern unsigned char volatile xdata DAT_EXTMEM_5002, DAT_EXTMEM_5000, DAT_EXTMEM_500c, DAT_EXTMEM_500b, DAT_EXTMEM_500a;
extern unsigned char volatile xdata DAT_EXTMEM_5109, DAT_EXTMEM_5105, DAT_EXTMEM_510e, DAT_EXTMEM_5108, DAT_EXTMEM_5106;
extern unsigned int volatile xdata DAT_EXTMEM_5134;
extern unsigned char volatile xdata DAT_EXTMEM_5102, DAT_EXTMEM_5100, DAT_EXTMEM_510c, DAT_EXTMEM_510b, DAT_EXTMEM_510a;
extern unsigned char volatile xdata DAT_EXTMEM_d929, DAT_EXTMEM_d90b, DAT_EXTMEM_d904, DAT_EXTMEM_d905, DAT_EXTMEM_d90c;
extern unsigned char volatile xdata DAT_EXTMEM_d511, DAT_EXTMEM_d910, DAT_EXTMEM_d911, DAT_EXTMEM_d912, DAT_EXTMEM_d90f;
extern unsigned char volatile xdata DAT_EXTMEM_d92d, DAT_EXTMEM_da00, DAT_EXTMEM_e1bf, DAT_EXTMEM_e1cf, DAT_EXTMEM_e1d8;
extern unsigned char volatile xdata DAT_EXTMEM_e1e0, DAT_EXTMEM_e1e2, DAT_EXTMEM_e1ec, DAT_EXTMEM_e1ee, DAT_EXTMEM_e19f;
extern unsigned char volatile xdata DAT_EXTMEM_e1af, DAT_EXTMEM_e12b, DAT_EXTMEM_d52c, DAT_EXTMEM_d52d;
extern unsigned char xdata DAT_EXTMEM_a6ee;
extern void FUN_CODE_dc51(void);
extern void FUN_CODE_daad(void);
extern void FUN_CODE_a142(unsigned char on);

void FUN_CODE_7a0b(void)
{
    BITS_21_6 = 1;
    DAT_EXTMEM_f1e0 = 0xc1;
    DAT_EXTMEM_5009 = 0x93;
    DAT_EXTMEM_5005 = 0x53;
    DAT_EXTMEM_500e = 0;
    DAT_EXTMEM_5008 = 0x06;
    DAT_EXTMEM_5006 = 0x1c;
    DAT_EXTMEM_5034 = 0xff34;
    DAT_EXTMEM_5002 = 0x14;
    DAT_EXTMEM_5000 = 0x88;
    DAT_EXTMEM_500c = 0x35;
    DAT_EXTMEM_500b = 0xff;
    DAT_EXTMEM_500a = 0x20;
    DAT_EXTMEM_5109 = 0x93;
    DAT_EXTMEM_5105 = 0x53;
    DAT_EXTMEM_510e = 0;
    DAT_EXTMEM_5108 = 0x06;
    DAT_EXTMEM_5106 = 0x1c;
    DAT_EXTMEM_5134 = 0xff34;
    DAT_EXTMEM_5102 = 0x14;
    DAT_EXTMEM_5100 = 0x88;
    DAT_EXTMEM_510c = 0x35;
    DAT_EXTMEM_510b = 0xff;
    DAT_EXTMEM_510a = 0x20;
    DAT_EXTMEM_d929 = 0x71;
    DAT_EXTMEM_d90b &= 0x7f;
    DAT_EXTMEM_d904 &= 0x0f;
    DAT_EXTMEM_d905 &= 0x7f;
    DAT_EXTMEM_d90c |= 0x01;
    if (DAT_EXTMEM_d511 == 0x20) {
        DAT_EXTMEM_d90b &= 0x7f;
        DAT_EXTMEM_d910 = 0;
        DAT_EXTMEM_d904 &= 0x01;
        DAT_EXTMEM_d911 = 0;
        DAT_EXTMEM_d912 = 0;
        DAT_EXTMEM_d90f &= 0x7f;
        DAT_EXTMEM_d92d &= 0x3f;
        DAT_EXTMEM_da00 &= 0xfe;
        DAT_EXTMEM_e1bf &= 0x7f;
        DAT_EXTMEM_e1cf &= 0x7f;
        DAT_EXTMEM_e1d8 = 0;
        DAT_EXTMEM_e1e0 &= 0x80;
        DAT_EXTMEM_e1e2 &= 0x8f;
        DAT_EXTMEM_e1ec &= 0x80;
        DAT_EXTMEM_e1ee &= 0x80;
        DAT_EXTMEM_e19f &= 0x7f;
        DAT_EXTMEM_e1af &= 0x7f;
        DAT_EXTMEM_e12b &= 0x7f;
    }
    DAT_EXTMEM_d52c |= 0x0c;
    DAT_EXTMEM_d52d |= 0x82;
    FUN_CODE_dc51();
    DAT_EXTMEM_a6ee = 0;
    FUN_CODE_daad();
    FUN_CODE_a142(1);
}

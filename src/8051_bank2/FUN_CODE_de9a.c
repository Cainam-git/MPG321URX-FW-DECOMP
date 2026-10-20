/* 8051_bank2 FUN_CODE_de9a @ 0xde9a  BYTE-EXACT under OPTIMIZE(8,SPEED) LARGE (also plain OPTIMIZE(8,SPEED));
 * hand C (97.3 % at O8) + the tail form below.
 * Reads the flash status: clears the 10-byte service buffer XDATA 0x0436, sends the packet 09 53 05 00 .. 00 11 to
 * slave 0x6E (FUN_CODE_bfcf), waits 100 units (FUN_CODE_d059), reads the reply back (FUN_CODE_bba9), waits 5 units
 * (FUN_CODE_e44b) and returns FUN_CODE_e105(0xF880) (scaler register read). Only caller: FUN_CODE_ceee (status sr).
 * The clear loop is the same 'for (i = 0; i < 10; i++) buf[i] = 0;' as in FUN_CODE_ceee (the only two copies of
 * this loop in the four banks); at level 8 it gives MOV R7,#10 / CLR A hoisted / MOVX / INC DPTR / DJNZ.
 * TAIL (documented no-code aid): the firmware keeps 'LCALL e105; RET' at level 8. Keil only does that when the RET
 * is a jump target: here the two arms of 'if (FUN_CODE_bba9(..) == 1)' are identical, Keil cross-jumps them, then
 * drops the now useless CJNE completely (no residue) and the exit label ?C0005 stays on the RET, so the LCALL is not
 * turned into LJMP. Same mechanism as in FUN_CODE_b84b (last statement written in both arms). Compare value: '== 1'
 * and '== 0xff' match; '== 0' leaves MOV A,R7 (75 B), '!= 1' 77 B, a test on the register variable i 103 B.
 * bba9 returns 0, 1 or a status byte (see FUN_CODE_bba9).
 * Dead ends (all LJMP e105, 73 B): return casts, e105 declared uint / char, 'r = e105(); return r;', goto/label at
 * the end, 'if (0) goto', dead second return, do{}while(1), for(;;) return; OPTIMIZE(8/9,SIZE), (9,SPEED).
 */
extern unsigned char xdata DAT_EXTMEM_0436[];
unsigned char FUN_CODE_bfcf(unsigned char addr, unsigned char len, unsigned char *buf);
unsigned char FUN_CODE_bba9(unsigned char addr, unsigned char *buf);
void FUN_CODE_d059(unsigned int t);
void FUN_CODE_e44b(unsigned char n);
unsigned char FUN_CODE_e105(unsigned int reg);

unsigned char FUN_CODE_de9a(void)
{
    unsigned char i;
    for (i = 0; i < 10; i++) DAT_EXTMEM_0436[i] = 0;
    DAT_EXTMEM_0436[0] = 9;
    DAT_EXTMEM_0436[1] = 0x53;
    DAT_EXTMEM_0436[2] = 0x05;
    DAT_EXTMEM_0436[9] = 0x11;
    FUN_CODE_bfcf(0x6e, 10, DAT_EXTMEM_0436);
    FUN_CODE_d059(100);
    if (FUN_CODE_bba9(0x6e, DAT_EXTMEM_0436) == 1) {
        FUN_CODE_e44b(5);
        return FUN_CODE_e105(0xf880);
    } else {
        FUN_CODE_e44b(5);
        return FUN_CODE_e105(0xf880);
    }
}

/* 8051_bank1 FUN_CODE_db32 @ 0xdb32 (no draft)
 * Queues one byte: XDATA 0xA2B0[IDATA 0x4D++] = v; when the count reaches 0x37 it calls FUN_CODE_cfad
 * (which sends the queue and clears IDATA 0x4D). Twins: FUN_CODE_db4b, FUN_CODE_db64 (same code, other queue).
 * The count must be idata (MOV R0,#4DH / MOV A,@R0 / INC @R0); as data Keil gives MOV R6,dir / INC dir (27 B).
 * Only caller 0x1f72 (FUN_CODE_1c3c).
 * Byte-exact with OPTIMIZE(8,SPEED) (MATCH exact None 25/25).
 */
extern unsigned char idata DAT_INTMEM_4d;
extern unsigned char xdata DAT_EXTMEM_a2b0[];
void FUN_CODE_cfad(void);
void FUN_CODE_db32(unsigned char v)
{
    DAT_EXTMEM_a2b0[DAT_INTMEM_4d++] = v;
    if (DAT_INTMEM_4d >= 0x37) FUN_CODE_cfad();
}

/* 8051_bank1 FUN_CODE_db4b @ 0xdb4b
 * Queues one byte: XDATA 0xA2E8[IDATA 0x50++] = v; when the count reaches 0x37 it calls FUN_CODE_cfe7
 * (which sends the queue and clears IDATA 0x50). Twins: FUN_CODE_db32, FUN_CODE_db64 (same code, other queue).
 * The count must be idata (MOV R0,#50H / MOV A,@R0 / INC @R0); as data Keil gives MOV R6,dir / INC dir (27 B).
 * Only caller 0x1fb0 (FUN_CODE_1c3c).
 * Options: OPTIMIZE(8,SPEED).
 */
extern unsigned char idata DAT_INTMEM_50;
extern unsigned char xdata DAT_EXTMEM_a2e8[];
void FUN_CODE_cfe7(void);
void FUN_CODE_db4b(unsigned char v)
{
    DAT_EXTMEM_a2e8[DAT_INTMEM_50++] = v;
    if (DAT_INTMEM_50 >= 0x37) FUN_CODE_cfe7();
}

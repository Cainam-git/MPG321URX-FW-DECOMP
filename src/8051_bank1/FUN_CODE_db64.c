/* 8051_bank1 FUN_CODE_db64 @ 0xdb64 (no draft)
 * Queues one byte: XDATA 0xA320[IDATA 0x53++] = v; when the count reaches 0x37 it calls FUN_CODE_d021
 * (which sends the queue and clears IDATA 0x53). Twins: FUN_CODE_db32, FUN_CODE_db4b (same code, other queue).
 * The count must be idata (MOV R0,#53H / MOV A,@R0 / INC @R0); as data Keil gives MOV R6,dir / INC dir (27 B).
 * Callers 0x1ff1 (FUN_CODE_1c3c), 0xd844 (no functions.json entry).
 * Byte-exact with OPTIMIZE(8,SPEED) (MATCH exact None 25/25).
 */
extern unsigned char idata DAT_INTMEM_53;
extern unsigned char xdata DAT_EXTMEM_a320[];
void FUN_CODE_d021(void);
void FUN_CODE_db64(unsigned char v)
{
    DAT_EXTMEM_a320[DAT_INTMEM_53++] = v;
    if (DAT_INTMEM_53 >= 0x37) FUN_CODE_d021();
}

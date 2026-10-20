/* 8051_bank1 FUN_CODE_b228 @ 0xb228  post words into the Big chip's mailbox portal (byte-exact with
 * OPTIMIZE(8,SPEED) LARGE; real size 0x88: Ghidra had cut it at the inline constant).
 *
 * FUN_CODE_b228(off, src, n): writes the n 32-bit words src[0..n-1] over the AHB bridge (FUN_CODE_beb5) to
 * 0x9F0A0100 + off + 4*i, the Main <-> helper-chip mailbox portal (portal 0, see MailBox_Read / MailBox_Write on the
 * Big chip, FUN_a002c4d0 / FUN_a002c5f8). Only the low address byte is changed (off + 4*i, 8-bit). The third
 * parameter is passed in memory (XDATA 0xA4BF) because the generic pointer occupies R1..R3.
 * Caller seen: FUN_CODE_d31d ("Update FE2P Addr"): FUN_CODE_b228(0xB4, &addr, 1) posts the new FE2P address to the
 * Big chip. Helper-to-Big-chip messaging on the update path.
 */
typedef union { unsigned long l; unsigned char b[4]; } DW;
extern DW xdata DAT_EXTMEM_a4ec;
extern DW xdata DAT_EXTMEM_a4f0;
extern void FUN_CODE_beb5(void);   /* parameters in its overlay: addr = 0xA4EC, val = 0xA4F0 */
void FUN_CODE_b228(unsigned char off, unsigned long *src, unsigned char n)
{
    unsigned char i;
    DW addr;
    DW val;
    addr.l = 0x9F0A0100;
    for (i = 0; i < n; i++) {
        addr.b[3] = off + i * 4;
        val.l = src[i];
        DAT_EXTMEM_a4ec = addr;
        DAT_EXTMEM_a4f0 = val;
        FUN_CODE_beb5();
    }
}

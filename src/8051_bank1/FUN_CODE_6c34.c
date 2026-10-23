/* 8051_bank1 FUN_CODE_6c34 @ 0x6c34  STBC firmware-update command loop (byte-exact with
 * OPTIMIZE(8,SPEED) REGFILE(R.ORC)). Real size 0x181 bytes (Ghidra's list says 74: it left the case bodies as data).
 * The standby controller (this 8051) prints "STBC FW updating......" and then serves commands forever from a
 * mailbox in XDATA 0xF250.. (written by another processor):
 *   0xF250 = command, 0xF251..0xF255 = arguments, 0xF260 = acknowledgement (inverted command), 0xF261 = 0x55 on a
 *   checksum error. Every pass also writes 0x55 to 0xF00A and 0xF0E0.
 *   1  FUN_CODE_9b11(address >> 12, count): address = 0xF252..0xF255 (32-bit, big-endian, kept at 0xA4B3), so
 *      the first argument is a 4 KB sector number; count = 0xF251.
 *   2  expected = 0xF254 << 8 | 0xF255 (kept at 0xA4B8); FUN_CODE_bd81(a, b, c) then sum = FUN_CODE_ac5b(a, b, c)
 *      with a, b, c = 0xF251..0xF253; on a mismatch 0xF261 = 0x55 and "checksum error %04X, %04X" (expected, sum).
 *   3  FUN_CODE_d81c(0xF251): set the flash's extended address register (address bits 24..31).
 *   4  FUN_CODE_b192(0xF251, 0xF252, 0xF253) (the three bytes also stored at 0xA4B3.., 0xA4B6 = 0).
 *   5  FUN_CODE_bd81(0xF251, 0xF252, 0xF253) (the same three bytes).
 *   6  FUN_CODE_dc51(); FUN_CODE_7765(xdata 0xA776); FUN_CODE_dc67().
 *   7  FUN_CODE_dc51(); FUN_CODE_b456(xdata 0xA776); FUN_CODE_dc67().
 *   8  endless loop (waits to be reset).
 *   other non-zero commands: acknowledged only; command 0: nothing (no acknowledgement).
 * After a non-zero command: 0xF250 = 0 and 0xF260 = ~command.
 * The mailbox is one array (Keil steps through it with INC DPTR); 0xA4B3 is a 32-bit / byte union.
 */
extern unsigned char volatile xdata DAT_EXTMEM_f250[0x12];
extern unsigned char volatile xdata DAT_EXTMEM_f00a, DAT_EXTMEM_f0e0;
extern unsigned char xdata DAT_EXTMEM_a4b7;
extern unsigned int xdata DAT_EXTMEM_a4b8;
extern union { unsigned long l; unsigned char b[4]; } xdata DAT_EXTMEM_a4b3;
extern void FUN_CODE_2820(void *fmt, ...) large;
extern void FUN_CODE_9b11(unsigned int sector, unsigned char n);
extern void FUN_CODE_bd81(unsigned char a, unsigned char b, unsigned char c);
extern unsigned int FUN_CODE_ac5b(unsigned char a, unsigned char b, unsigned char c);
extern void FUN_CODE_b192(unsigned char a, unsigned char b, unsigned char c);
extern void FUN_CODE_d81c(unsigned char ext);
extern void FUN_CODE_7765(void *p);
extern void FUN_CODE_b456(void *p);
extern void FUN_CODE_dc51(void);
extern void FUN_CODE_dc67(void);

void FUN_CODE_6c34(void)
{
    unsigned int sum;
    FUN_CODE_2820((void code *)0xc930);
    for (;;) {
        DAT_EXTMEM_a4b7 = DAT_EXTMEM_f250[0x00];
        if (DAT_EXTMEM_a4b7 != 0) {
            switch (DAT_EXTMEM_a4b7) {
            case 1:
                DAT_EXTMEM_a4b3.b[0] = DAT_EXTMEM_f250[0x02];
                DAT_EXTMEM_a4b3.b[1] = DAT_EXTMEM_f250[0x03];
                DAT_EXTMEM_a4b3.b[2] = DAT_EXTMEM_f250[0x04];
                DAT_EXTMEM_a4b3.b[3] = DAT_EXTMEM_f250[0x05];
                FUN_CODE_9b11(DAT_EXTMEM_a4b3.l >> 12, DAT_EXTMEM_f250[0x01]);
                break;
            case 2:
                DAT_EXTMEM_a4b8 = DAT_EXTMEM_f250[0x04] << 8 | DAT_EXTMEM_f250[0x05];
                FUN_CODE_bd81(DAT_EXTMEM_f250[0x01], DAT_EXTMEM_f250[0x02], DAT_EXTMEM_f250[0x03]);
                sum = FUN_CODE_ac5b(DAT_EXTMEM_f250[0x01], DAT_EXTMEM_f250[0x02], DAT_EXTMEM_f250[0x03]);
                if (DAT_EXTMEM_a4b8 != sum) {
                    DAT_EXTMEM_f250[0x11] = 0x55;
                    FUN_CODE_2820((void code *)0xc949, DAT_EXTMEM_a4b8, sum);
                }
                break;
            case 3:
                FUN_CODE_d81c(DAT_EXTMEM_f250[0x01]);
                break;
            case 4:
                DAT_EXTMEM_a4b3.b[0] = DAT_EXTMEM_f250[0x01];
                DAT_EXTMEM_a4b3.b[1] = DAT_EXTMEM_f250[0x02];
                DAT_EXTMEM_a4b3.b[2] = DAT_EXTMEM_f250[0x03];
                DAT_EXTMEM_a4b3.b[3] = 0;
                FUN_CODE_b192(DAT_EXTMEM_a4b3.b[0], DAT_EXTMEM_a4b3.b[1], DAT_EXTMEM_a4b3.b[2]);
                break;
            case 5:
                DAT_EXTMEM_a4b3.b[0] = DAT_EXTMEM_f250[0x01];
                DAT_EXTMEM_a4b3.b[1] = DAT_EXTMEM_f250[0x02];
                DAT_EXTMEM_a4b3.b[2] = DAT_EXTMEM_f250[0x03];
                DAT_EXTMEM_a4b3.b[3] = 0;
                FUN_CODE_bd81(DAT_EXTMEM_a4b3.b[0], DAT_EXTMEM_a4b3.b[1], DAT_EXTMEM_a4b3.b[2]);
                break;
            case 6:
                FUN_CODE_dc51();
                FUN_CODE_7765((void xdata *)0xa776);
                FUN_CODE_dc67();
                break;
            case 7:
                FUN_CODE_dc51();
                FUN_CODE_b456((void xdata *)0xa776);
                FUN_CODE_dc67();
                break;
            case 8:
                for (;;) ;
            }
            DAT_EXTMEM_f250[0x00] = 0;
            DAT_EXTMEM_f250[0x10] = ~DAT_EXTMEM_a4b7;
        }
        DAT_EXTMEM_f00a = 0x55;
        DAT_EXTMEM_f0e0 = 0x55;
    }
}

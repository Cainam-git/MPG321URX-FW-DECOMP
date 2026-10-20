/* leon2m FUN_a0127724 @ 0xa0127724  OLED set Inspection Pattern (hand; -mcpu=v8 -O3 -g -msoft-float, soft-float unit)
 *
 * Panel test-pattern select over the software I2C bus (device 0x60, 16-bit register address, register 0x1C8):
 * - buffer DAT_a802d890 = { 0, pat }; only when GPIO group 9 bit 3 is high (FUN_a01248c8):
 *   print "OLED set Inspection Pattern %d", write the 2 bytes (FUN_a0147aa0), wait 50 ms, read them back into
 *   DAT_a802d888 (FUN_a0147ae8), print "OLED Get Inspection Pattern %x %x", wait 50 ms;
 * - while the read-back differs from the buffer and the GLOBAL retry byte DAT_a802c9fd < 10: print the retry line,
 *   write again, wait 5 ms, read back, DAT_a802c9fd++. The retry byte is never reset here, so the loop is bounded
 *   (at most 10 retries over the whole run time).
 * Callers: factory menu / tool command only.
 */
extern unsigned char FUN_a01248c8(void);   /* GPIO group 9 bit 3 is high */
extern unsigned short FUN_a0147aa0();      /* I2C register write */
extern unsigned short FUN_a0147ae8();      /* I2C register read */
extern int FUN_a00df170();                 /* debug printf */
extern void func_0x4008d1a0(int ms);       /* delay */
extern unsigned char DAT_a802d890[2];      /* bytes written to register 0x1C8 */
extern unsigned char DAT_a802d888[2];      /* bytes read back */
extern unsigned char DAT_a802c9fd;         /* retry count (global) */
extern const char s_001a4a20[], s_001a4a50[], s_001a4a80[];

void FUN_a0127724(unsigned char pat)
{
    DAT_a802d890[1] = pat;
    DAT_a802d890[0] = 0;
    if (FUN_a01248c8()) {
        FUN_a00df170(s_001a4a20, pat);
        FUN_a0147aa0(0x60, 2, 0x1c8, 5, 0, DAT_a802d890, 2, 1);
        func_0x4008d1a0(50);
        FUN_a0147ae8(0x60, 2, 0x1c8, 5, 0, DAT_a802d888, 2);
        FUN_a00df170(s_001a4a50, DAT_a802d888[0], DAT_a802d888[1]);
        func_0x4008d1a0(50);
        while ((DAT_a802d890[1] != DAT_a802d888[1] || DAT_a802d890[0] != DAT_a802d888[0]) && DAT_a802c9fd < 10) {
            FUN_a00df170(s_001a4a80, DAT_a802d890[0], DAT_a802d890[1], DAT_a802d888[0], DAT_a802d888[1]);
            FUN_a0147aa0(0x60, 2, 0x1c8, 5, 0, DAT_a802d890, 2, 1);
            func_0x4008d1a0(5);
            FUN_a0147ae8(0x60, 2, 0x1c8, 5, 0, DAT_a802d888, 2);
            DAT_a802c9fd++;
        }
    }
}

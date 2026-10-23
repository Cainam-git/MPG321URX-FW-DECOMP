/* leon2m FUN_a00fdf74 @ 0xa00fdf74-0xa00fe184 (528 bytes)  Set_INTERNAL_1_INPUT_Path: select the source of internal
 * path 1. Flags -mcpu=v8 -O3 -g (also matches with -O3 -g -msoft-float and with -O3). Twin of FUN_a00fe1dc (path 2);
 * the reader of this field is FUN_a00fe184.
 *
 * void FUN_a00fdf74(mode): prints "Set_INTERNAL_1_INPUT_Path = %02x\r\n" (0x19A4B0) with mode.
 *   Path register: 0xCF0116E0 when FUN_a011cf88() > 0x81, else 0xCF0116D4 (chosen again before
 *   the write). v = low byte of that register with bits 4 and 6 (0x50) cleared; then
 *     mode 1: field = 0;      0xCF011600 bit 6 cleared under the hardware semaphore 0xCF03C840
 *     mode 2: field = 0x10;   0xCF011600 bit 6 set under the semaphore
 *     mode 3: field = 0x40;   0xCF011600 bit 6 set under the semaphore
 *     other : field = 0, no semaphore access.
 *   Write-back: code > 0x81 -> 0xCF0116E0 = v; else 0xCF0116D4 = v, EXCEPT when the transformed 0x58-byte row
 *   (*DAT_a802d6a4) word +0x00 has bits 20-22 == 1 (value 0x100000 under mask 0x700000): then nothing is written.
 *   Semaphore (same as FUN_a01026e8): write 1 unless it reads 2, done when it reads 1, at most 65536 tries, then
 *   1 is written anyway; released by writing 0.
 * Callers: FUN_a0132770 (tail calls: its arg 0 -> mode 1, 1 -> mode 2, 2 or 4 -> mode 3).
 * ROW FIELDS READ: transformed row +0x00 bits 20-22 (only on the code <= 0x81 path).
 * Source form: the register READ is written as if/else of two loads (one sethi per address; a selected pointer
 *   shares the sethi); case order 1, 2, 3; case 1 repeats 'v &= ~0x50' (no-op on the value, the bits are already
 *   clear; it gives the firmware's extra 'mov %o5,%l0' in case 1); the semaphore as static inline lock()/unlock().
 */
#define R(a) (*(volatile unsigned int *)(a))
#define SEM R(0xcf03c840)
struct PanelParam { unsigned int w0; };
extern struct PanelParam *DAT_a802d6a4;
extern int FUN_a00df170();
extern unsigned char FUN_a011cf88(void);
extern char s_0019a4b0[];
static void lock(void)
{
    unsigned short t = 0xffff;
    do {
        if (SEM != 2) SEM = 1;
        if (SEM == 1) break;
    } while (--t != 0xffff);
    SEM = 1;
}
static void unlock(void) { SEM = 0; }

void FUN_a00fdf74(unsigned char mode)
{
    unsigned char v;

    FUN_a00df170(s_0019a4b0, mode);
    if (FUN_a011cf88() > 0x81) v = R(0xcf0116e0); else v = R(0xcf0116d4);
    v &= ~0x50;
    switch (mode) {
    case 1:
        v &= ~0x50;
        lock(); R(0xcf011600) &= ~0x40; unlock();
        break;
    case 2:
        v |= 0x10;
        lock(); R(0xcf011600) |= 0x40; unlock();
        break;
    case 3:
        v |= 0x40;
        lock(); R(0xcf011600) |= 0x40; unlock();
        break;
    }
    if (FUN_a011cf88() > 0x81) R(0xcf0116e0) = v;
    else if ((DAT_a802d6a4->w0 & 0x700000) != 0x100000) R(0xcf0116d4) = v;
}

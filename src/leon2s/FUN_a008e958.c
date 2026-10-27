/* leon2s FUN_a008e958 @ 0xa008e958-0xa008ecb8 (216 words, leaf), flags -mcpu=v8 -Os -g.
 * void (u8 sel, u8 rate). Sets bits 0..1 (sel 0 and other values) or 2..3 (sel 1) of register 0xcf014754,
 * takes the hardware semaphore 0xcf03c840 (inline helper as in FUN_a008a238: writes 2 while it does not read
 * 1, until it reads 2, at most 65535 tries, then writes 2), clears bit 5 (bit 6 for sel 1) of 0xcf01477c and
 * releases the semaphore (0). Then for rate 1..6 (jump table) prints "FRL CLK 3GHz" / "6GHz" (rates 2 and 3) /
 * "8GHz" / "10GHz" / "12GHz" and writes the low nibble (sel 0) or the high nibble (sel 1) of register
 * 0xcf014748: cleared, then set to 1, 2, 3 or 4 for the rates above 1 (two register writes).
 * Source form: the semaphore release written in each arm of the sel test (shares the address register).
 */
#define SEM (*(volatile unsigned int *)0xcf03c840)
#define R4748 (*(volatile unsigned int *)0xcf014748)
#define R4754 (*(volatile unsigned int *)0xcf014754)
#define R477C (*(volatile unsigned int *)0xcf01477c)

extern int FUN_a00734c4(const char *);

static inline void sem_take(void)
{
    unsigned short n = 0xffff;

    do {
        if (SEM != 1)
            SEM = 2;
        if (SEM == 2)
            break;
        n--;
    } while (n != 0xffff);
    SEM = 2;
}

void FUN_a008e958(unsigned char sel, unsigned char rate)
{
    if (sel == 0) {
        R4754 |= 3;
        sem_take();
        R477C &= ~0x20;
        SEM = 0;
    } else if (sel == 1) {
        R4754 |= 0xc;
        sem_take();
        R477C &= ~0x40;
        SEM = 0;
    } else {
        R4754 |= 3;
        sem_take();
        R477C &= ~0x20;
        SEM = 0;
    }
    switch (rate) {
    case 1:
        FUN_a00734c4("\x1b[0m\t\t - FRL CLK 3GHz\n");
        if (sel == 0)
            R4748 &= 0xf0;
        else if (sel == 1)
            R4748 &= 0xf;
        break;
    case 2:
    case 3:
        FUN_a00734c4("\x1b[0m\t\t - FRL CLK 6GHz\n");
        if (sel == 0) {
            R4748 &= 0xf0;
            R4748 |= 1;
        } else if (sel == 1) {
            R4748 &= 0xf;
            R4748 |= 0x10;
        }
        break;
    case 4:
        FUN_a00734c4("\x1b[0m\t\t - FRL CLK 8GHz\n");
        if (sel == 0) {
            R4748 &= 0xf0;
            R4748 |= 2;
        } else if (sel == 1) {
            R4748 &= 0xf;
            R4748 |= 0x20;
        }
        break;
    case 5:
        FUN_a00734c4("\x1b[0m\t\t - FRL CLK 10GHz\n");
        if (sel == 0) {
            R4748 &= 0xf0;
            R4748 |= 3;
        } else if (sel == 1) {
            R4748 &= 0xf;
            R4748 |= 0x30;
        }
        break;
    case 6:
        FUN_a00734c4("\x1b[0m\t\t - FRL CLK 12GHz\n");
        if (sel == 0) {
            R4748 &= 0xf0;
            R4748 |= 4;
        } else if (sel == 1) {
            R4748 &= 0xf;
            R4748 |= 0x40;
        }
        break;
    }
}

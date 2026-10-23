/* FUN_a008ed50 (leon2s 0xa008ed50-0xa008f270, 1312 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Arguments port, code, mode (bytes). Each register update below runs while holding the hardware semaphore
 * 0xcf03c840 (take: write 2 while it does not read 1, until it reads 2, at most 65535 tries, then write 2;
 * release: write 0), as in FUN_a008a238.
 * mode 1 and code 0x31 / 0x41 / 0x51 / 0x61: port 0 clears bit 0 of 0xcf0116b4, sets bit 4 of 0xcf011600
 * (under the semaphore), sets bit 0 of 0xcf0117bc and writes 2 to bits 1..0 of 0xcf014754; port 1 clears bit 1,
 * sets bit 5, sets bit 1 and writes 2 to bits 3..2 (value 8); other ports clear bits 5..4 of 0xcf011600.
 * Then 0xcf0124bc = 1 / 2 / 3 for code 0x41 / 0x51 / 0x61, else 0.
 * Any other mode or code: clears bit 4 (port 0), bit 5 (port 1) or bits 5..4 (other ports) of 0xcf011600.
 * Source forms: the semaphore take is an inline helper; the code switch has an explicit case 0x31 (it sets
 * the decision-tree pivot at 0x41); the register updates are written out for both outer else arms.
 */
#define SEM (*(volatile unsigned int *)0xcf03c840)
#define R1600 (*(volatile unsigned int *)0xcf011600)
#define R16B4 (*(volatile unsigned int *)0xcf0116b4)
#define R17BC (*(volatile unsigned int *)0xcf0117bc)
#define R24BC (*(volatile unsigned int *)0xcf0124bc)
#define R4754 (*(volatile unsigned int *)0xcf014754)

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

void FUN_a008ed50(unsigned char port, unsigned char code, unsigned char mode)
{
    if (mode == 1) {
        if (code == 0x31 || code == 0x41 || code == 0x51 || code == 0x61) {
            if (port == 0) {
                R16B4 &= 0xfe;
                sem_take();
                R1600 |= 0x10;
                SEM = 0;
                R17BC |= 1;
                R4754 &= 0xfc;
                R4754 |= 2;
            } else if (port == 1) {
                R16B4 &= 0xfd;
                sem_take();
                R1600 |= 0x20;
                SEM = 0;
                R17BC |= 2;
                R4754 &= 0xf3;
                R4754 |= 8;
            } else {
                sem_take();
                R1600 &= ~0x30;
                SEM = 0;
            }
            switch (code) {
            case 0x31:
                R24BC = 0;
                break;
            case 0x41:
                R24BC = 1;
                break;
            case 0x51:
                R24BC = 2;
                break;
            case 0x61:
                R24BC = 3;
                break;
            default:
                R24BC = 0;
                break;
            }
        } else {
            if (port == 0) {
                sem_take();
                R1600 &= ~0x10;
                SEM = 0;
            } else if (port == 1) {
                sem_take();
                R1600 &= ~0x20;
                SEM = 0;
            } else {
                sem_take();
                R1600 &= ~0x30;
                SEM = 0;
            }
        }
    } else {
        if (port == 0) {
            sem_take();
            R1600 &= ~0x10;
            SEM = 0;
        } else if (port == 1) {
            sem_take();
            R1600 &= ~0x20;
            SEM = 0;
        } else {
            sem_take();
            R1600 &= ~0x30;
            SEM = 0;
        }
    }
}

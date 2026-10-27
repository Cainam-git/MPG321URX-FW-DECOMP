/* leon2s FUN_a008bddc @ 0xa008bddc (-mcpu=v8 -Os -g)
 * Port setup by mode (mode, port). First, for modes 2, 8, 10, 12, 14 FUN_a008bd1c(port, 1); for 3 and 0x13
 * FUN_a008bd1c(port, 3); for 4..7 FUN_a008bd1c(port, v) with v from bits 6-7 of byte 0xa8076689 (1 -> 2, 2 -> 0,
 * else 1). Then FUN_a00a71fc(port, 2, 0x2c, 0) and a second switch on mode writes register sequences through
 * FUN_a00a71fc(port, reg, mask, val) / FUN_a00a7168(port, reg, val) / FUN_a00a71b4(port, reg) (read):
 * 4 and 6 repeat the four writes 7/0x80, 7/0x10, 2/8, 0/1 when FUN_a008b2bc(mode) is non-zero and bit 0 of
 * FUN_a00a6bb8(0 or 1, 0x51) is set; 8, 10, 12, 14 store mode & 0xf into the low (port 0, 2) or high (port 1, 3)
 * nibble of register 0xcf011240 (ports 0, 1) or 0xcf011244 (ports 2, 3); 1 and 0x11 set, clear and set bit
 * (port + 4) of 0xcf012444, each under the hardware semaphore 0xcf03c840 (written 2 while not owned elsewhere,
 * at most 65535 tries, released with 0). Other modes only get the 0x2c write. Both switches use jump tables.
 * Source form: the first switch is a static helper with unsigned char parameters (inlined); its inner test is a
 * switch listing case 2 before case 1, and cases 3 and 0x13 are separate (more than three case bodies keep the
 * jump table); the semaphore take is the inline helper of FUN_a008a238.
 */
#define SEM (*(volatile unsigned int *)0xcf03c840)
#define R2444 (*(volatile unsigned int *)0xcf012444)
#define R1240 (*(volatile unsigned int *)0xcf011240)
#define R1244 (*(volatile unsigned int *)0xcf011244)

extern unsigned char DAT_a8076689;
extern void FUN_a008bd1c(unsigned char port, unsigned char v);
extern void FUN_a00a71fc(unsigned char port, unsigned char reg, unsigned char mask, unsigned char val);
extern void FUN_a00a7168(unsigned char port, unsigned char reg, unsigned char val);
extern unsigned char FUN_a00a71b4(unsigned char port, unsigned char reg);
extern unsigned char FUN_a008b2bc(unsigned char mode);
extern unsigned int FUN_a00a6bb8(unsigned char a, unsigned short b);

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

static void sel_bd1c(unsigned char mode, unsigned char p)
{
    switch (mode) {
    case 4:
    case 5:
    case 6:
    case 7:
        switch (DAT_a8076689 >> 6) {
        case 2:
            FUN_a008bd1c(p, 0);
            break;
        case 1:
            FUN_a008bd1c(p, 2);
            break;
        default:
            FUN_a008bd1c(p, 1);
            break;
        }
        break;
    case 2:
    case 8:
    case 10:
    case 12:
    case 14:
        FUN_a008bd1c(p, 1);
        break;
    case 3:
        FUN_a008bd1c(p, 3);
        break;
    case 0x13:
        FUN_a008bd1c(p, 3);
        break;
    }
}

void FUN_a008bddc(unsigned char mode, unsigned char port)
{
    unsigned char v;

    sel_bd1c(mode, port);
    FUN_a00a71fc(port, 2, 0x2c, 0);
    switch (mode) {
    case 4:
        FUN_a00a71fc(port, 7, 0x40, 0);
        FUN_a00a71fc(port, 7, 0x80, 0);
        FUN_a00a71fc(port, 7, 0x10, 0);
        FUN_a00a71fc(port, 2, 8, 8);
        FUN_a00a71fc(port, 0, 1, 1);
        if (FUN_a008b2bc(mode) && (FUN_a00a6bb8(0, 0x51) & 1)) {
            FUN_a00a71fc(port, 7, 0x80, 0);
            FUN_a00a71fc(port, 7, 0x10, 0);
            FUN_a00a71fc(port, 2, 8, 8);
            FUN_a00a71fc(port, 0, 1, 1);
        }
        FUN_a00a71fc(port, 1, 0x40, 0x40);
        FUN_a00a7168(port, 3, 0x12);
        break;
    case 5:
    case 7:
        FUN_a00a71fc(port, 7, 0x40, 0);
        FUN_a00a71fc(port, 7, 0x80, 0);
        FUN_a00a71fc(port, 7, 0x10, 0);
        FUN_a00a71fc(port, 2, 8, 8);
        FUN_a00a71fc(port, 0, 1, 1);
        FUN_a00a71fc(port, 1, 0x40, 0x40);
        FUN_a00a7168(port, 3, 0x12);
        break;
    case 6:
        FUN_a00a71fc(port, 7, 0x40, 0);
        FUN_a00a71fc(port, 7, 0x80, 0);
        FUN_a00a71fc(port, 7, 0x10, 0);
        FUN_a00a71fc(port, 2, 8, 8);
        FUN_a00a71fc(port, 0, 1, 1);
        if (FUN_a008b2bc(mode) && (FUN_a00a6bb8(1, 0x51) & 1)) {
            FUN_a00a71fc(port, 7, 0x80, 0);
            FUN_a00a71fc(port, 7, 0x10, 0);
            FUN_a00a71fc(port, 2, 8, 8);
            FUN_a00a71fc(port, 0, 1, 1);
        }
        FUN_a00a71fc(port, 1, 0x40, 0x40);
        FUN_a00a7168(port, 3, 0x12);
        break;
    case 8:
    case 10:
    case 12:
    case 14:
        FUN_a00a71fc(port, 7, 0x40, 0);
        FUN_a00a71fc(port, 7, 0x10, 0x10);
        FUN_a00a71fc(port, 0, 1, 0);
        FUN_a00a71fc(port, 1, 0x40, 0x40);
        FUN_a00a7168(port, 3, 0x1a);
        switch (port) {
        case 0:
            R1240 = (R1240 & 0xf0) | (mode & 0xf);
            break;
        case 1:
            R1240 = (R1240 & 0xf) | ((mode & 0xf) << 4);
            break;
        case 2:
            R1244 = (R1244 & 0xf0) | (mode & 0xf);
            break;
        case 3:
            R1244 = (R1244 & 0xf) | ((mode & 0xf) << 4);
            break;
        }
        break;
    case 2:
        FUN_a00a71fc(port, 7, 0x40, 0);
        FUN_a00a71fc(port, 0, 1, 0);
        FUN_a00a71fc(port, 2, 0x24, 0x24);
        FUN_a00a71fc(port, 7, 0x80, 0x80);
        FUN_a00a7168(port, 8, 0);
        FUN_a00a7168(port, 9, 4);
        FUN_a00a7168(port, 10, 0);
        FUN_a00a7168(port, 12, 0);
        FUN_a00a7168(port, 13, 1);
        FUN_a00a7168(port, 14, 0);
        FUN_a00a7168(port, 3, 0x1a);
        v = FUN_a00a71b4(port, 2);
        FUN_a00a7168(port, 2, v & 0xbf);
        FUN_a00a7168(port, 2, v | 0x40);
        FUN_a00a7168(port, 2, v & 0xbf);
        v = FUN_a00a71b4(port, 7);
        FUN_a00a7168(port, 7, v & 0x7f);
        FUN_a00a7168(port, 7, v | 0x80);
        break;
    case 1:
    case 0x11:
        FUN_a00a71fc(port, 7, 0x40, 0);
        FUN_a00a71fc(port, 0, 1, 0);
        FUN_a00a71fc(port, 7, 0x10, 0);
        FUN_a00a7168(port, 3, 2);
        FUN_a00a71fc(port, 7, 0x80, 0);
        sem_take();
        R2444 |= 1 << (port + 4);
        SEM = 0;
        sem_take();
        R2444 &= ~(1 << (port + 4));
        SEM = 0;
        sem_take();
        R2444 |= 1 << (port + 4);
        SEM = 0;
        FUN_a00a7168(port, 4, 0x95);
        FUN_a00a7168(port, 5, 0x18);
        FUN_a00a7168(port, 6, 4);
        FUN_a00a7168(port, 1, 0x68);
        break;
    case 3:
    case 0x13:
        FUN_a00a7168(port, 3, 0x1a);
        FUN_a00a71fc(port, 2, 0x24, 0x24);
        FUN_a00a7168(port, 7, 0x40);
        FUN_a00a7168(port, 8, 0);
        FUN_a00a7168(port, 9, 0x80);
        FUN_a00a7168(port, 10, 0);
        FUN_a00a7168(port, 12, 0);
        FUN_a00a7168(port, 13, 1);
        FUN_a00a7168(port, 14, 0);
        v = FUN_a00a71b4(port, 2);
        FUN_a00a7168(port, 2, v & 0xbf);
        FUN_a00a7168(port, 2, v | 0x40);
        FUN_a00a7168(port, 2, v & 0xbf);
        break;
    }
}

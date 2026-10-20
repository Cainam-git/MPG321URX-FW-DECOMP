/* FUN_a008a238 (leon2s 0xa008a238-0xa008a470, 568 bytes, leaf), flags -mcpu=v8 -Os -g.
 * For sel 0..4 (jump table): takes the hardware semaphore 0xcf03c840 (writes 2 while it is not owned
 * elsewhere (1) until it reads 2, at most 65535 tries, then writes 2), sets bit 4, 5, 6, 7 or bits 4..7 of
 * register 0xcf012444 and releases the semaphore (0). Other sel values do nothing.
 * Source forms: the semaphore take is an inline helper; each case releases the semaphore itself (GCC
 * shares the store tail).
 */
#define SEM (*(volatile unsigned int *)0xcf03c840)
#define R2444 (*(volatile unsigned int *)0xcf012444)

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

void FUN_a008a238(unsigned char sel)
{
    switch (sel) {
    case 0:
        sem_take();
        R2444 |= 0x10;
        SEM = 0;
        break;
    case 1:
        sem_take();
        R2444 |= 0x20;
        SEM = 0;
        break;
    case 2:
        sem_take();
        R2444 |= 0x40;
        SEM = 0;
        break;
    case 3:
        sem_take();
        R2444 |= 0x80;
        SEM = 0;
        break;
    case 4:
        sem_take();
        R2444 |= 0xf0;
        SEM = 0;
        break;
    }
}

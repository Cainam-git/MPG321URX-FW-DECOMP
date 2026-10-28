/* leon2m FUN_a010ebd0 @ 0xa010ebd0-0xa010ec70 (40 words), flags -mcpu=v8 -O3 -g. No direct callers.
 * Reads the register 0xd0030420 (the value is replaced before use), then picks a word by b and c:
 * b 0: c 0 -> 0x13200000, c 1 -> 0x13020000, c 2 -> 0x10320000; b 1: c 0 -> 0x03210000, c 1 -> 0x03120000,
 * c 2 -> 0x01320000, and writes it to the registers 0xd0030420 and 0xd0038420. Other b or c: no write.
 * volatile: both addresses are hardware registers.
 * Source form: the first register is accessed through a pointer local (the firmware keeps its address in a
 * register from the read to the write).
 */
#define RB (*(volatile unsigned int *)0xd0038420)

void FUN_a010ebd0(unsigned char c, unsigned char b)
{
    volatile unsigned int *ra = (volatile unsigned int *)0xd0030420;
    unsigned int x;

    x = *ra;
    if (b == 0) {
        switch (c) {
        case 0:
            x = 0x13200000;
            break;
        case 1:
            x = 0x13020000;
            break;
        case 2:
            x = 0x10320000;
            break;
        default:
            return;
        }
    } else if (b == 1) {
        switch (c) {
        case 0:
            x = 0x03210000;
            break;
        case 1:
            x = 0x03120000;
            break;
        case 2:
            x = 0x01320000;
            break;
        default:
            return;
        }
    } else
        return;
    *ra = x;
    RB = x;
}

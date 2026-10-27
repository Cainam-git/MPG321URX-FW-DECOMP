/* leon2m FUN_a011337c @ 0xa011337c-0xa01136a0 (804 bytes), flags -mcpu=v8 -O3 -g. Leaf.
 * Called by FUN_a0147c80 and FUN_a0150df8. Determines v (0, 1 or 2; starts at 0) for sel (switch, jump table
 * 0xb1884, 15 entries) from status bits:
 *   sel 0: 0xcf01345c bit 0 -> 0, bit 1 -> 2, bit 2 -> 1;  sel 1, 3, 5: 0xcf013444 / 0xcf01344c / 0xcf013454
 *   bit 4 -> 0, bit 5 -> 2, bit 6 -> 1;  sel 2, 4: 0xcf013448 / 0xcf013450 bit 0 -> 0, bit 1 -> 2;
 *   sel 13, 14 and all others: 0xcf013428 read under the hardware semaphore 0xcf03c840 (same lock()/unlock() as
 *   FUN_a00fdf74), then its bit (3 for sel 13, 4 for sel 14, 6 otherwise) -> 0, else the same bit of 0xcf013430 -> 2;
 *   for the other sel values bit 6 of 0xcf013438 then gives 1, else 0.
 * Finally bits 0..2 of 0xcf01345c are replaced by 1 (v 0), 2 (v 2) or 4 (v 1).
 * Source form: each test chain is an if/else-if chain on fresh register reads; only the last chain ends with an
 * explicit 'else v = 0' (store-flag there, branches elsewhere); case order 0, 2, 5, 3, 4, 1, 13, 14, default and
 * 0, 2, 1 in the final switch (register names). volatile: hardware registers only.
 */
#define R(a) (*(volatile unsigned int *)(a))
#define SEM R(0xcf03c840)

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

void FUN_a011337c(unsigned char sel)
{
    unsigned char v = 0;
    unsigned int x;

    switch (sel) {
    case 0:
        if (R(0xcf01345c) & 1) v = 0;
        else if (R(0xcf01345c) & 2) v = 2;
        else if (R(0xcf01345c) & 4) v = 1;
        break;
    case 2:
        if (R(0xcf013448) & 1) v = 0;
        else if (R(0xcf013448) & 2) v = 2;
        break;
    case 5:
        if (R(0xcf013454) & 0x10) v = 0;
        else if (R(0xcf013454) & 0x20) v = 2;
        else if (R(0xcf013454) & 0x40) v = 1;
        break;
    case 3:
        if (R(0xcf01344c) & 0x10) v = 0;
        else if (R(0xcf01344c) & 0x20) v = 2;
        else if (R(0xcf01344c) & 0x40) v = 1;
        break;
    case 4:
        if (R(0xcf013450) & 1) v = 0;
        else if (R(0xcf013450) & 2) v = 2;
        break;
    case 1:
        if (R(0xcf013444) & 0x10) v = 0;
        else if (R(0xcf013444) & 0x20) v = 2;
        else if (R(0xcf013444) & 0x40) v = 1;
        break;
    case 13:
        lock();
        x = R(0xcf013428);
        unlock();
        if (x & 8) v = 0;
        else if (R(0xcf013430) & 8) v = 2;
        break;
    case 14:
        lock();
        x = R(0xcf013428);
        unlock();
        if (x & 0x10) v = 0;
        else if (R(0xcf013430) & 0x10) v = 2;
        break;
    default:
        lock();
        x = R(0xcf013428);
        unlock();
        if (x & 0x40) v = 0;
        else if (R(0xcf013430) & 0x40) v = 2;
        else if (R(0xcf013438) & 0x40) v = 1;
        else v = 0;
        break;
    }
    switch (v) {
    case 0: R(0xcf01345c) = (R(0xcf01345c) & 0xf8) | 1; break;
    case 2: R(0xcf01345c) = (R(0xcf01345c) & 0xf8) | 2; break;
    case 1: R(0xcf01345c) = (R(0xcf01345c) & 0xf8) | 4; break;
    }
}

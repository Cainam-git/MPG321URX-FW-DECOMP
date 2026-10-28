/* leon2m FUN_a010ad28 @ 0xa010ad28-0xa010adb8 (36 words), -mcpu=v8 -O3 -g. No direct callers found.
 * x = v & 0x3f. Selects one of four registers by c: 1 -> 0xcf011dd0, 2 -> 0xcf011dd4, 3 -> 0xcf011dd8, any other
 * value -> 0xcf011dcc, and writes (old value & 0x80) | x to it.
 * Source form: a switch with the default arm written first; GCC shares the store block of case 2 and the default
 * through a register holding the address.
 */
#define RCC (*(volatile unsigned int *)0xcf011dcc)
#define RD0 (*(volatile unsigned int *)0xcf011dd0)
#define RD4 (*(volatile unsigned int *)0xcf011dd4)
#define RD8 (*(volatile unsigned int *)0xcf011dd8)

void FUN_a010ad28(unsigned char c, unsigned int v)
{
    unsigned char x = v & 0x3f;

    switch (c) {
    default:
        RCC = (RCC & 0x80) | x;
        break;
    case 1:
        RD0 = (RD0 & 0x80) | x;
        break;
    case 2:
        RD4 = (RD4 & 0x80) | x;
        break;
    case 3:
        RD8 = (RD8 & 0x80) | x;
        break;
    }
}

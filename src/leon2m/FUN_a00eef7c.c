/* leon2m FUN_a00eef7c @ 0xa00eef7c-0xa00ef034 (46 words), flags -mcpu=v8 -O3 -g, leaf.
 * DAT_a8026a79 = p; then, as the switch at the start of FUN_a00ef048 (jump table 0xa00eef3c, 8 entries):
 *   p 0: DAT_a8026a78 = 0;                 p 1: DAT_a8026a78 = 1;
 *   p 2: a78 = 2, 0xcf014750 &= ~1;        p 6: a78 = 2, 0xcf014750 |= 1;
 *   p 3: a78 = 3, 0xcf014750 &= ~4;        p 7: a78 = 3, 0xcf014750 |= 4;   (p 4, 5, > 7: nothing)
 * volatile only on the hardware register.
 * Source form: case order 0, 1, 2, 6, 3, 7 as in FUN_a00ef048; each case stores the byte before the register
 * read-modify-write (the firmware schedules the byte store between the register load and store).
 */
extern unsigned char DAT_a8026a78, DAT_a8026a79;
#define R(a) (*(volatile unsigned int *)(a))

void FUN_a00eef7c(unsigned char p)
{
    DAT_a8026a79 = p;
    switch (p) {
    case 0: DAT_a8026a78 = 0; break;
    case 1: DAT_a8026a78 = 1; break;
    case 2: DAT_a8026a78 = 2; R(0xcf014750) &= ~1; break;
    case 6: DAT_a8026a78 = 2; R(0xcf014750) |= 1; break;
    case 3: DAT_a8026a78 = 3; R(0xcf014750) &= ~4; break;
    case 7: DAT_a8026a78 = 3; R(0xcf014750) |= 4; break;
    }
}

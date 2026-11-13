/* startup_init_clock_blocks  (FUN_a0118400)
 *
 * Set up the three identical clock blocks.
 * Name basis: derived - start-up step 5; called from start-up
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0118400, flags -mcpu=v8 -O3 -g.
 * Exact form: u16 parameters, the range checks as (u16)(x - lo) > n, 1500 / a signed (int promotion of the u16).
 */
#define R(a) (*(volatile unsigned int *)(a))

/*
 * Program the same two values into the three blocks at 0xCF0129D0, 0xCF012B10 and 0xCF014090.
 *
 *   a  used when it lies in 25..50, else 30
 *   b  used when it lies in 5..250, else 20; 0 switches the three blocks off (bit 0 of each block cleared) and
 *      returns
 *
 * Values: q = 1500 / a and r = ((b * a) << 15) / 15000000, both kept to 8 bits. For each block, q goes to the word
 * at +8 (then bit 7 of it is set) and r to the word at +0xC; last, bit 0 of each block is set. Writes only: nothing
 * is read back or waited for. startup_bring_up_system calls it with a = 0x1E and b = 0x32, giving q = 50 and r = 3.
 */
void startup_init_clock_blocks(unsigned short a, unsigned short b)
{
    unsigned char q, r;
    if (b == 0) {
        R(0xcf0129d0) &= ~1;
        R(0xcf012b10) &= ~1;
        R(0xcf014090) &= ~1;
        return;
    }
    if ((unsigned short)(a - 25) > 25)
        a = 30;
    q = 1500 / a;
    if ((unsigned short)(b - 5) > 0xf5)
        b = 20;
    r = ((unsigned int)(b * a) << 15) / 15000000;
    R(0xcf0129d8) = q;
    R(0xcf0129dc) = r;
    R(0xcf0129d8) |= 0x80;
    R(0xcf012b18) = q;
    R(0xcf012b1c) = r;
    R(0xcf012b18) |= 0x80;
    R(0xcf014098) = q;
    R(0xcf01409c) = r;
    R(0xcf014098) |= 0x80;
    R(0xcf0129d0) |= 1;
    R(0xcf012b10) |= 1;
    R(0xcf014090) |= 1;
}

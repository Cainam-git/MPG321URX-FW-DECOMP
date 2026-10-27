/* FUN_a0104cb0 (leon2m 0xa0104cb0-0xa0104d18, 104 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Sets bit 0 of the word registers 0xcf012890 and 0xcf012990 when bit 26 of the word *DAT_a802d6a4 is set,
 * otherwise clears it in both. Nothing in the image refers to it: no call, branch, sethi/or constant or address
 * word. It lies between FUN_a0104c34 and FUN_a0104d18.
 */
#define REG90 (*(volatile unsigned int *)0xcf012890)
#define REG190 (*(volatile unsigned int *)0xcf012990)
extern unsigned int *DAT_a802d6a4;

void FUN_a0104cb0(void)
{
    if (*DAT_a802d6a4 & 0x4000000) {
        REG90 |= 1;
        REG190 |= 1;
    } else {
        REG90 &= ~1u;
        REG190 &= ~1u;
    }
}

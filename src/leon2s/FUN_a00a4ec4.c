/* leon2s FUN_a00a4ec4 @ 0xa00a4ec4-0xa00a5050 (-mcpu=v8 -Os -g).
 * With on set: register 0xcf0124b4 |= 0x40, 0xcf0127c0 = 0, then up to 0x10000 rounds until register 0xcf03c840
 * reads 2 (writing 2 whenever it is not 1), then 0xcf03c840 = 2, 0xcf01477c |= 0x80, 0xcf03c840 = 0 and registers
 * 0xcf0127c4 / 0xcf0127c8 / 0xcf0127cc = 0, 0, 0x19. Otherwise x = 150000 for v > 400, v * 250 when bit 24 of word
 * 0x58 of the block at _DAT_a807dc08 is set, else (v * 333250) / 1000 - 100; then x = x * 10 + (x * 2768 / 3) / 1000
 * and its three low bytes go to 0xcf0127c4, 0xcf0127c8 and 0xcf0127cc.
 * Source form: x * 10 is taken into its own variable before the division, which places the add before the
 * multiply as in the firmware; the register-block pointer word is read as (unsigned char)(w >> 24) & 1.
 */
extern volatile unsigned int *_DAT_a807dc08;

#define R4B4 (*(volatile unsigned int *)0xcf0124b4)
#define R7C0 (*(volatile unsigned int *)0xcf0127c0)
#define R7C4 (*(volatile unsigned int *)0xcf0127c4)
#define R7C8 (*(volatile unsigned int *)0xcf0127c8)
#define R7CC (*(volatile unsigned int *)0xcf0127cc)
#define R77C (*(volatile unsigned int *)0xcf01477c)
#define R840 (*(volatile unsigned int *)0xcf03c840)

void FUN_a00a4ec4(unsigned char on, unsigned short v)
{
    unsigned short n;
    unsigned int x;
    unsigned int y;

    if (on) {
        R4B4 |= 0x40;
        R7C0 = 0;
        n = 0xffff;
        do {
            if (R840 != 1)
                R840 = 2;
            if (R840 == 2)
                break;
        } while (n--);
        R840 = 2;
        R77C |= 0x80;
        R840 = 0;
        R7C4 = 0;
        R7C8 = 0;
        R7CC = 0x19;
    } else {
        if (v > 400)
            x = 150000;
        else if ((unsigned char)(_DAT_a807dc08[0x58 / 4] >> 24) & 1)
            x = v * 250;
        else
        {
            x = (int)(v * 333250) / 1000;
            x -= 100;
        }
        {
            unsigned int z = x * 10;

            y = (unsigned int)(x * 2768) / 3;
            x = z + y / 1000;
        }        R7C4 = x & 0xff;
        R7C8 = (x >> 8) & 0xff;
        R7CC = (x >> 16) & 0xff;
    }
}

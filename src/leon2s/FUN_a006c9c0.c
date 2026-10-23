/* FUN_a006c9c0 (leon2s 0xa006c9c0-0xa006cb98, 472 bytes), flags -mcpu=v8 -Os -g -msoft-float.
 * Reads n blocks of 8 words through the hardware registers at 0xcf011f80: for each block writes the 4 bytes of
 * addr to 0xcf011fa0..0xcf011fac, 0x80 to 0xcf011f84 and 0xcf011f8c, waits (at most 0xffff polls) for
 * 0xcf011f90 to read 0x80, then assembles each of the 8 words out[i * 8 + k] from 4 reads of 0xcf011f94: low byte
 * first when DAT_a80787e0 is 1, high byte first otherwise (out[] is updated after every read). addr is
 * incremented per block. volatile only on the hardware registers.
 * Same source form as the main processor's FUN_a0113cd8 (with the mode taken from DAT_a80787e0); the wait
 * counter reuses the word-loop counter j. Compiled with -msoft-float (it changes the loop-invariant threshold,
 * as in DRV_HDMI21_RXDetect_FSM_LTS_3).
 */
#define REG(a) (*(volatile unsigned int *)(a))
extern unsigned char DAT_a80787e0;

void FUN_a006c9c0(unsigned int *out, unsigned int addr, unsigned short n)
{
    unsigned short i, j;

    for (i = 0; i < n; i++) {
        REG(0xcf011fa0) = addr;
        REG(0xcf011fa4) = addr >> 8;
        REG(0xcf011fa8) = addr >> 16;
        REG(0xcf011fac) = addr >> 24;
        REG(0xcf011f84) = 0x80;
        REG(0xcf011f8c) = 0x80;
        j = 0xffff;
        while (REG(0xcf011f90) != 0x80) {
            if (--j == 0)
                break;
        }
        if (DAT_a80787e0 == 1) {
            for (j = i * 8; j < i * 8 + 8; j++) {
                out[j] = REG(0xcf011f94);
                out[j] |= REG(0xcf011f94) << 8;
                out[j] |= REG(0xcf011f94) << 16;
                out[j] |= REG(0xcf011f94) << 24;
            }
        } else {
            for (j = i * 8; j < i * 8 + 8; j++) {
                out[j] = REG(0xcf011f94) << 24;
                out[j] |= REG(0xcf011f94) << 16;
                out[j] |= REG(0xcf011f94) << 8;
                out[j] |= REG(0xcf011f94);
            }
        }
        addr++;
    }
}

/* leon2m FUN_a00f0380 @ 0xa00f0380-0xa00f04f8 (94 words).
 * v = register 0x51 of block blk (FUN_a00f2254). First step, when bit 1 of byte 0xa802b750 is set or cnt is 0:
 * cnt 0 stores v to byte 0xa802b751 and writes v - 1 when bit 1 of f is set and v is non-zero; cnt 300 writes byte
 * 0xa802b751; otherwise v + 1 is written when bit 0 of f is set (result 1), else v - 1 when v is non-zero.
 * Second step, when bit 0 of byte 0xa802b750 is set or cnt is 0: cnt 0 stores v to 0xa802b751 and writes v + 1
 * when bit 0 of f is set; cnt 300 writes byte 0xa802b751; otherwise v - 1 when bit 1 of f is set (result 1), else
 * v + 1. Writes go to register 0x51 with FUN_a00f2298. Stores f to 0xa802b750 and returns the result (0 or 1).
 * Source form: in the second step the "bit 1 of f clear" arm comes first (it fixes the register choice).
 */
extern unsigned char DAT_a802b750;
extern unsigned char DAT_a802b751;
extern unsigned char FUN_a00f2254(unsigned char blk, unsigned char reg);
extern void FUN_a00f2298(unsigned char blk, unsigned char reg, unsigned char val);

unsigned char FUN_a00f0380(unsigned char blk, unsigned short cnt, unsigned char f)
{
    unsigned char v = FUN_a00f2254(blk, 0x51);
    unsigned char r = 0;

    if ((DAT_a802b750 & 2) || cnt == 0) {
        if (cnt == 0) {
            DAT_a802b751 = v;
            if ((f & 2) && v != 0)
                FUN_a00f2298(blk, 0x51, v - 1);
        } else if (cnt == 300) {
            FUN_a00f2298(blk, 0x51, DAT_a802b751);
        } else if (f & 1) {
            FUN_a00f2298(blk, 0x51, v + 1);
            r = 1;
        } else if (v != 0) {
            FUN_a00f2298(blk, 0x51, v - 1);
        }
    }
    if ((DAT_a802b750 & 1) || cnt == 0) {
        if (cnt == 0) {
            DAT_a802b751 = v;
            if (f & 1)
                FUN_a00f2298(blk, 0x51, v + 1);
        } else if (cnt == 300) {
            FUN_a00f2298(blk, 0x51, DAT_a802b751);
        } else if (!(f & 2)) {
            FUN_a00f2298(blk, 0x51, v + 1);
        } else {
            FUN_a00f2298(blk, 0x51, v - 1);
            r = 1;
        }
    }
    DAT_a802b750 = f;
    return r & 1;
}

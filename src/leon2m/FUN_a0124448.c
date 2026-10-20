/* leon2m FUN_a0124448 @ 0xa0124448..0xa0124828 (248 words)  start-up step 3 of FUN_a015266c, called right after
 * WAIT 1 with the boot byte r the 8051 posted (portal 0 +0xB8 bits 8..15, "Boot from %02X"): pin set-up by boot kind,
 * then two lookup bytes from the ROM port table.
 * What it does (code facts):
 *  - r > 1: GPIO primitive func_0x4008c86c (RAM copy of FUN_a002c86c) (7, 0x20, 0xFF) and (7, 0x10, 0xFF), i.e. bank 7
 *    bits 5 and 4 driven (value bit 0 = 1).
 *  - r <= 1 (0 or 1): 17 x FUN_a00dddb8(bank, v), 17 x FUN_a00de088(bank, v), 17 x FUN_a00de1fc(bank, v, w) for banks
 *    1..17 with the fixed bytes below; each of the three is an 18-way switch that stores v (and w) into one fixed
 *    0xCF03C000..0xCF03CCFF register per bank (three register sets per bank; their pin meaning, e.g. mux/pull/drive,
 *    is NOT proven).
 *  - both: FUN_a00dd904(0x70) (0xCF03CF00..0C sequence, bits 4..6 -> 0xCF03C200 bits 0..2).
 *  - For k = 0..6: DAT_a802d880[k] = index of the first of the 8 22-byte records of DAT_001a42a8 (ROM, flash 0x2AC2A8)
 *    whose byte +2 == k, else 0xFF. FW.021 table: +2 bytes 0F 0F 0F 04 06 00 02 0F -> D880 = 05 FF 06 FF 03 FF 04.
 *  - For the 8 records with byte +3 == 1: DAT_a802c9fa and DAT_a802c9fb |= (u8)(1 << byte +2). FW.021: |= 0x55 (the
 *    1 << 15 of records 1, 2 and 7 falls off the byte). FUN_a0125350 later reads single bits of DAT_a802c9fb.
 *    (Inference: the 22-byte records are the input/port descriptors, +1 = port type as used by FUN_a01250c4.)
 * Can it fail or wait? No: fixed register stores and two bounded loops (7 x 8, 8); no read-back, no timeout.
 * It runs before FUN_a0106d64 and depends only on the 8051's boot byte.
 * Exact form: the r <= 1 arm written first, the inner search as a for with break, u8 counters, and the two globals
 * or-ed directly in the loop (gcc keeps them in registers and stores each once after the loop).
 */
struct Rec { unsigned char b0, b1, b2, b3; unsigned char rest[18]; };
extern const struct Rec DAT_001a42a8[];
extern unsigned char DAT_a802d880[];
extern unsigned char DAT_a802c9fa, DAT_a802c9fb;
extern void FUN_a00dddb8(unsigned char, unsigned char);
extern void FUN_a00de088(unsigned char, unsigned char);
extern void FUN_a00de1fc(unsigned char, unsigned char, unsigned char);
extern void FUN_a00dd904(unsigned char);
extern void func_0x4008c86c(unsigned char, unsigned char, unsigned char);

void FUN_a0124448(unsigned char boot)
{
    unsigned char k, j;

    if (boot <= 1) {
        FUN_a00dddb8(1, 0xfb); FUN_a00dddb8(2, 0xfb); FUN_a00dddb8(3, 0xff); FUN_a00dddb8(4, 0x0f);
        FUN_a00dddb8(5, 0x3c); FUN_a00dddb8(6, 0xf8); FUN_a00dddb8(7, 0x7b); FUN_a00dddb8(8, 0xff);
        FUN_a00dddb8(9, 0xd7); FUN_a00dddb8(10, 0xff); FUN_a00dddb8(11, 0xff); FUN_a00dddb8(12, 0xbe);
        FUN_a00dddb8(13, 0x8f); FUN_a00dddb8(14, 0xff); FUN_a00dddb8(15, 0xff); FUN_a00dddb8(16, 0xff);
        FUN_a00dddb8(17, 0xff);
        FUN_a00de088(1, 0xff); FUN_a00de088(2, 0xfb); FUN_a00de088(3, 0xff); FUN_a00de088(4, 0x0f);
        FUN_a00de088(5, 0x0c); FUN_a00de088(6, 0xf0); FUN_a00de088(7, 0x49); FUN_a00de088(8, 0x55);
        FUN_a00de088(9, 0xd7); FUN_a00de088(10, 0xff); FUN_a00de088(11, 0xdf); FUN_a00de088(12, 0x2e);
        FUN_a00de088(13, 0x93); FUN_a00de088(14, 0xff); FUN_a00de088(15, 0xff); FUN_a00de088(16, 0xff);
        FUN_a00de088(17, 0xff);
        FUN_a00de1fc(1, 7, 0); FUN_a00de1fc(2, 7, 2); FUN_a00de1fc(3, 0, 0); FUN_a00de1fc(4, 0xf0, 0);
        FUN_a00de1fc(5, 3, 0); FUN_a00de1fc(6, 7, 0); FUN_a00de1fc(7, 0x84, 0); FUN_a00de1fc(8, 0, 0);
        FUN_a00de1fc(9, 8, 0); FUN_a00de1fc(10, 0, 0); FUN_a00de1fc(11, 0, 0); FUN_a00de1fc(12, 0xc1, 0);
        FUN_a00de1fc(13, 0x6c, 0); FUN_a00de1fc(14, 0, 0); FUN_a00de1fc(15, 0, 0); FUN_a00de1fc(16, 0, 0);
        FUN_a00de1fc(17, 0, 0);
    } else {
        func_0x4008c86c(7, 0x20, 0xff);
        func_0x4008c86c(7, 0x10, 0xff);
    }
    FUN_a00dd904(0x70);

    for (k = 0; k < 7; k++) {
        DAT_a802d880[k] = 0xff;
        for (j = 0; j < 8; j++)
            if (DAT_001a42a8[j].b2 == k) {
                DAT_a802d880[k] = j;
                break;
            }
    }
    for (j = 0; j < 8; j++)
        if (DAT_001a42a8[j].b3 == 1) {
            DAT_a802c9fb |= 1 << DAT_001a42a8[j].b2;
            DAT_a802c9fa |= 1 << DAT_001a42a8[j].b2;
        }
}

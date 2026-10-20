/* leon2m FUN_a0145af8 @ 0xa0145af8  (hand; byte-exact at -mcpu=v8 -O3 -g, jump table included)
 *
 * Getter for the monitor's saved-settings record at 0xA802E1A0, the 0x50-byte block that FUN_a0153970 writes
 * back to the settings EEPROM (I2C device 0 of the FUN_a0140e74 table, offset 0x470, 16-byte page writes with the
 * write-protect pin and ACK polling). switch(id) over a jump table (firmware table at run-time address 0xE3238):
 *   0, 1, 2, 3   single flag bits 30, 29, 27, 26 of the record's first word
 *   6, 8, 10, 11 bytes at +0x08, +0x0C, +0x0F, +0x10
 *   7, 9, 12, 14 16-bit values at +0x09, +0x0D, +0x11, +0x15
 *   13, 15       16-bit values at +0x13, +0x17 (they cross a word boundary, so the halves are read as bytes)
 *   16, 17       flag bits 7 and 6 of the byte at +0x19
 *   4, 5, other  0xFFFF
 * FUN_a00dac38 calls FUN_a0145af8(2); when that flag is 1 the panel row thresholds use an
 * offset of 0.5 Hz instead of 2.0 Hz. The same bit is sent to another processor as message 0x80 by FUN_a012b884
 * (via FUN_a0138b98 / FUN_a01370dc) and gates bit 31 of 0xA802E3D0 in FUN_a0148d98.
 */
/* The saved-settings record at 0xA802E1A0 (0x50 bytes; FUN_a0153970 writes it back to the settings EEPROM at
 * offset 0x470). Only the fields this getter returns are named, after their case number. The layout is a packed
 * record on a 4-byte boundary, which is why the compiler reads the 16-bit fields with a word load and a shift. */
struct InInfo {
    unsigned int b31:1, f0:1, f1:1, b28:1, f2:1, f3:1, b25:2, rest0:24;   /* +0x00 */
    unsigned char pad[4];                                                  /* +0x04 */
    unsigned char f6;                                                      /* +0x08 */
    unsigned short f7;                                                     /* +0x09 */
    unsigned char pad2;                                                    /* +0x0b */
    unsigned char f8;                                                      /* +0x0c */
    unsigned short f9;                                                     /* +0x0d */
    unsigned char f10;                                                     /* +0x0f */
    unsigned char f11;                                                     /* +0x10 */
    unsigned short f12;                                                    /* +0x11 */
    unsigned short f13;                                                    /* +0x13 */
    unsigned short f14;                                                    /* +0x15 */
    unsigned short f15;                                                    /* +0x17 */
    unsigned int f16:1, f17:1, rest1:6;                                    /* +0x19 */
} __attribute__((packed, aligned(4)));
extern struct InInfo DAT_a802e1a0;

/* Returns setting "id" (0..17) of the saved-settings record; ids 4, 5 and anything above 17 return 0xFFFF. */
unsigned short FUN_a0145af8(unsigned int id)
{
    unsigned short r = 0xffff;
    switch (id) {
    case 0: r = (unsigned char)DAT_a802e1a0.f0; break;
    case 1: r = (unsigned char)DAT_a802e1a0.f1; break;
    case 2: r = (unsigned char)DAT_a802e1a0.f2; break;   /* bit 27: FUN_a00dac38 uses 0.5 Hz instead of 2.0 Hz */
    case 3: r = (unsigned char)DAT_a802e1a0.f3; break;
    case 6: r = DAT_a802e1a0.f6; break;
    case 7: r = DAT_a802e1a0.f7; break;
    case 8: r = DAT_a802e1a0.f8; break;
    case 9: r = DAT_a802e1a0.f9; break;
    case 10: r = DAT_a802e1a0.f10; break;
    case 11: r = DAT_a802e1a0.f11; break;
    case 12: r = DAT_a802e1a0.f12; break;
    case 13: r = DAT_a802e1a0.f13; break;
    case 14: r = DAT_a802e1a0.f14; break;
    case 15: r = DAT_a802e1a0.f15; break;
    case 16: r = (unsigned char)DAT_a802e1a0.f16; break;
    case 17: r = (unsigned char)DAT_a802e1a0.f17; break;
    }
    return r;
}

/* leon2m FUN_a0112b2c @ 0xa0112b2c-0xa0112db0 (161 words).
 * Selects the 24-word set DAT_001a6b34[DAT_a802c98e][DAT_a802c98f] (ROM, two 96-byte sets per first index) and
 * passes its words to FUN_a01129e4: (0, w0, w1, w2), (1, w3..w5), (2, w6..w8), (3, w9..w11), (4, w12..w14),
 * (5, w15, 0, 0), (0xa, w16, w17, 0), (0xb, w18, w19, 0), (0x13, w20, 0, 0); then DAT_a802c994 = w21,
 * DAT_a802c998 = w22, DAT_a802c990 = w23. Called by FUN_a0112db0 and FUN_a01131d4.
 */
struct Set { unsigned int w[24]; };
extern const struct Set DAT_001a6b34[][2];
extern unsigned char DAT_a802c98e, DAT_a802c98f;
extern unsigned int DAT_a802c990, DAT_a802c994, DAT_a802c998;
extern void FUN_a01129e4(unsigned char, unsigned int, unsigned int, unsigned int);

/* the set selected by the two index bytes; read again after every call */
#define SET DAT_001a6b34[DAT_a802c98e][DAT_a802c98f]

void FUN_a0112b2c(void)
{
    FUN_a01129e4(0, SET.w[0], SET.w[1], SET.w[2]);
    FUN_a01129e4(1, SET.w[3], SET.w[4], SET.w[5]);
    FUN_a01129e4(2, SET.w[6], SET.w[7], SET.w[8]);
    FUN_a01129e4(3, SET.w[9], SET.w[10], SET.w[11]);
    FUN_a01129e4(4, SET.w[12], SET.w[13], SET.w[14]);
    FUN_a01129e4(5, SET.w[15], 0, 0);
    FUN_a01129e4(0xa, SET.w[16], SET.w[17], 0);
    FUN_a01129e4(0xb, SET.w[18], SET.w[19], 0);
    FUN_a01129e4(0x13, SET.w[20], 0, 0);
    DAT_a802c994 = SET.w[21];
    DAT_a802c998 = SET.w[22];
    DAT_a802c990 = SET.w[23];
}

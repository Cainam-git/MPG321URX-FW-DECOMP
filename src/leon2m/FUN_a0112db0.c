/* leon2m FUN_a0112db0 @ 0xa0112db0..0xa0112fb8 (130 words)  start-up step 5 of FUN_a015266c, called with 0: clock and
 * block set-up of the display pipe, then 21 table bytes through FUN_a01118cc.
 * What it does (code facts), in order:
 *  - 0xCF011800, 0xCF011A00, 0xCF015A00, 0xCF011670 = 0; 0xCF012440 |= 0xC2; 0xCF014780 |= 4; DAT_a802c98f = mode.
 *  - Four 24-bit clock values through FUN_a00f30f0 (each with a 0x80 control write before and a |= 0x80 after, the same
 *    pattern FUN_a01026e8 uses): 0xCF0129C4 = 0x2B2AAA, 0xCF014084 = 0x2B2AAA, 0xCF012B04 = 0x2B2AAA, 0xCF012B44 =
 *    0x4B8000 (FUN_a01026e8's formula f = v * 12 MHz / 2^17: 259.1 MHz x 3 and 453.0 MHz).
 *  - 0xCF013410 / 0xCF013414 / 0xCF01341C = 0x3F, 0xCF013408 = 0, func_0x4008d1a0(2) (FUN_a002d1a0, the RAM-piece tick
 *    delay: tick word 0xA802B0C0 = 3, spins until a timer interrupt counts it to 0), then 0xCF013408 = 0x4F.
 *  - FUN_a00e1fc8() (DDR table select, "Old DDR" / "New DDR", then FUN_a00e0e44(0)).
 *  - For i = 0..20: FUN_a01118cc(i, DAT_001a6adc[DAT_a802c98e][DAT_a802c98f][i]) (ROM table of 22-byte rows; c98e set
 *    just before by FUN_a01118c0(FUN_a01423a0()), c98f = mode = 0 here).
 *  - 0xCF011A40..0xCF011A6C (12 words) = 0xC0; FUN_a0112b2c(); 0xCF011804 = 0xFF; 0xCF011F30 = 0xCF011F3C = 0x3F.
 * Wait: FUN_a002d1a0(2) returns only when the tick word reaches 0, which requires the timer interrupt (its countdown
 * only prints once); without a running timer interrupt it waits forever. Runs before FUN_a0106d64.
 */
#define R(a) (*(volatile unsigned int *)(a))
extern unsigned char DAT_a802c98e, DAT_a802c98f;
extern const unsigned char DAT_001a6adc[][2][22];
extern void FUN_a00f30f0(unsigned int, unsigned int);
extern void func_0x4008d1a0(int);
extern void FUN_a00e1fc8(void);
extern void FUN_a01118cc(unsigned char, unsigned char);
extern void FUN_a0112b2c(void);

void FUN_a0112db0(unsigned char mode)
{
    unsigned char i;

    R(0xcf011800) = 0;
    R(0xcf011a00) = 0;
    R(0xcf015a00) = 0;
    R(0xcf011670) = 0;
    R(0xcf012440) |= 0xc2;
    R(0xcf014780) |= 4;
    DAT_a802c98f = mode;
    R(0xcf0129c0) = 0x80;
    FUN_a00f30f0(0xcf0129c4, 0x2b2aaa);
    R(0xcf0129d4) |= 0x80;
    R(0xcf014080) = 0x80;
    FUN_a00f30f0(0xcf014084, 0x2b2aaa);
    R(0xcf014094) |= 0x80;
    R(0xcf012b00) = 0x80;
    FUN_a00f30f0(0xcf012b04, 0x2b2aaa);
    R(0xcf012b14) |= 0x80;
    FUN_a00f30f0(0xcf012b44, 0x4b8000);
    R(0xcf013410) = 0x3f;
    R(0xcf013414) = 0x3f;
    R(0xcf01341c) = 0x3f;
    R(0xcf013408) = 0;
    func_0x4008d1a0(2);
    R(0xcf013408) = 0x4f;
    FUN_a00e1fc8();
    for (i = 0; i <= 20; i++)
        FUN_a01118cc(i, DAT_001a6adc[DAT_a802c98e][DAT_a802c98f][i]);
    R(0xcf011a40) = 0xc0;
    R(0xcf011a44) = 0xc0;
    R(0xcf011a48) = 0xc0;
    R(0xcf011a4c) = 0xc0;
    R(0xcf011a50) = 0xc0;
    R(0xcf011a54) = 0xc0;
    R(0xcf011a58) = 0xc0;
    R(0xcf011a5c) = 0xc0;
    R(0xcf011a60) = 0xc0;
    R(0xcf011a64) = 0xc0;
    R(0xcf011a68) = 0xc0;
    R(0xcf011a6c) = 0xc0;
    FUN_a0112b2c();
    R(0xcf011804) = 0xff;
    R(0xcf011f30) = 0x3f;
    R(0xcf011f3c) = 0x3f;
}

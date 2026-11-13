/* sys_dsc_enc_write_timing_words  (FUN_a00dccd8)
 *
 * Pack the encoder's timing values into register words.
 * Name basis: descriptive - 16-bit values shifted into the high halves
 *
 * Matching notes
 * --------------
 * FUN_a00dccd8 (leon2s 0xa00dccd8-0xa00dcdb8, 224 bytes), flags -mcpu=v8 -Os -g.
 * Source form: values are read into locals ahead of earlier register writes: ha >> 3 (unsigned short) before the
 * 0x14 write; the (he + hc) >> 3 sum and h10 >> 3 (unsigned int) before the 0x18 write; h12 before the 0x1c
 * write; h14 and the unsigned short h16 + h14 sum before the 0x20 write; the 0x24 value composed at its write.
 */
/* The halfwords of dsc_encoder_record from +8 on (written by sys_dsc_enc_set_parameters). */
struct win {
    unsigned short _0[4];
    unsigned short h8, ha, hc, he, h10, h12, h14, h16;
};
extern struct win dsc_encoder_record;

#define REG(o) (*(volatile unsigned int *)(0xc0120800 + (o)))

/* Program the register block at 0xc0120800 from the halfwords of dsc_encoder_record (h8 .. h16, names are
 * their byte offsets):
 *   +0x14 = 0x12000218                     +0x18 = 0xffff0000
 *   +0x1c = (h8 >> 3) << 16 | 0xffff       +0x20 = (hc >> 3) << 16 | h14
 *   +0x24 = (he + hc) >> 3 | (h16 + h14) << 16
 *   +0x28 = ha >> 3 in both halves         +0x2c = h12
 *   +0x48 = h10 >> 3 | 0x80000000
 */
void sys_dsc_enc_write_timing_words(void)
{
    unsigned short ha_div8, h12, h14, high_half;
    unsigned int low_half, h10_div8;

    ha_div8 = dsc_encoder_record.ha >> 3;
    REG(0x14) = 0x12000218;
    low_half = ((unsigned int)dsc_encoder_record.he + dsc_encoder_record.hc) >> 3;
    h10_div8 = dsc_encoder_record.h10 >> 3;
    REG(0x18) = 0xffff0000;
    h12 = dsc_encoder_record.h12;
    REG(0x1c) = 0xffff | ((dsc_encoder_record.h8 >> 3) << 16);
    h14 = dsc_encoder_record.h14;
    high_half = dsc_encoder_record.h16 + h14;
    REG(0x20) = ((dsc_encoder_record.hc >> 3) << 16) | h14;
    REG(0x24) = low_half | ((unsigned int)high_half << 16);
    REG(0x28) = ha_div8 | (ha_div8 << 16);
    REG(0x2c) = h12;
    REG(0x48) = h10_div8 | 0x80000000;
}

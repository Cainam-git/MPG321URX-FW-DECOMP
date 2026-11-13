/* hdmi_rx21_init_audio_regs  (FUN_a00a2ecc)
 *
 * Set the start-up values of the audio block registers of both HDMI 2.1 receivers.
 * Returns: 0
 * Name basis: descriptive - word 12 of block +0x30 = 0x80008000 (level, as hdmi_rx21_write_audio_level), bit
 *   0x1C of word 13, fields of word 0 of block 1
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a2ecc @ 0xa00a2ecc, flags -mcpu=v8 -Os -g.
 * Source form: a plain for loop with a u8 counter; the rows hold the pointers as unsigned int *; an int 0 return.
 */
/* One row of hdmi_rx21_reg_blocks (0x34 bytes per HDMI 2.1 receiver): word 0 points to register block 0 of the
   receiver (0xCE009000, +0x1000 for receiver 1), word 1 to block 1, and so on up to block 12 at +0x30. */
struct hdmi_rx21_reg_blocks { unsigned int pad0; unsigned int *block1; unsigned char pad8[0x28]; unsigned int *block12; };
extern struct hdmi_rx21_reg_blocks ARR_a807db00[];
extern void reg_set_bit(unsigned int, unsigned int *);
extern void reg_clear_bit(unsigned int, unsigned int *);
extern unsigned int reg_test_bit(unsigned int, unsigned int *);

/* Start-up step (called by _hdmi21_Initialize) for both HDMI 2.1 receivers, in this order:
     block 12, word 12 = 0x80008000 and bit 28 of its word at offset 0x34 set;
     block 1, word 0: bits 20..23 = 5, bit 1 cleared, and when bit 1 then reads back as set, bits 16..19 = 2.
   Returns 0. */
int hdmi_rx21_init_audio_regs(void)
{
    unsigned char receiver;

    for (receiver = 0; receiver <= 1; receiver++) {
        struct hdmi_rx21_reg_blocks *row = &ARR_a807db00[receiver];
        row->block12[12] = 0x80008000;
        reg_set_bit(28, row->block12 + 13);
        *row->block1 = (*row->block1 & ~0xf00000) | 0x500000;
        reg_clear_bit(1, row->block1);
        if (reg_test_bit(1, row->block1) != 0)
            *row->block1 = (*row->block1 & ~0xf0000) | 0x20000;
    }
    return 0;
}

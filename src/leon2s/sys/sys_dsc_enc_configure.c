/* sys_dsc_enc_configure  (FUN_a00de8ac)
 *
 * Fill the encoder's timing record, compute its parameters and program the encoder.
 * Name basis: proven - prints 'DSC_ENC_TIMER_CONFIG'; called from ipc_dispatch_command
 *
 * Matching notes
 * --------------
 * Flags -mcpu=v8 -Os -g.
 * Source form: the halfword stores are written in field order before the word_0x20 and word_0x00 stores; bit 7
 * of the last input word is tested as '(signed char)p->w18 < 0' (a byte load in the word's alias set). The
 * slices chain keeps three arms ('q <= 400', 'q <= 800', else) although the last two store the same value.
 * Three assignment sites are what the registers show; the record's address is formed again before the
 * 'slices' stores, so they stay in separate arms.
 */
/* The compression encoder's timing record (dsc_encoder_record). Fields not named keep their offset. */
struct dsc_encoder_rec {
    unsigned int word_0x00;       /* computed here from the last input word, see below */
    unsigned char bit_depth;      /* +4, printed by sys_dsc_enc_compute_pps as 8 / 10 / 12 bit */
    unsigned char source;         /* +5, 0 DISP, 2 P2, 3 P3 (sys_dsc_enc_select_route) */
    unsigned char byte_0x06;
    unsigned char format;         /* +7, 0 RGB, 1 YUV422, 2 YUV420, 3 YUV444, 4 YUV422_SIMPLE (printed names) */
    unsigned short half[8];       /* +8 .. +0x16: [1] = width (+0xa), [5] = height (+0x12) */
    unsigned char byte_0x18;
    unsigned char slices;         /* +0x19, printed as SLICE */
    unsigned char bpp_divisor;    /* +0x1a, 24 / 16 / 12 divided by it in sys_dsc_enc_compute_pps */
    unsigned char byte_0x1b;
    unsigned int word_0x1c;
    unsigned int word_0x20;       /* the last input word, unchanged */
};
/* The command payload (mailbox 0xA5). */
struct dsc_enc_command {
    unsigned int word_0x00;
    unsigned int packed_bytes;    /* byte 0 -> +0x18, byte 1 -> source, byte 2 -> format, byte 3 -> bit_depth */
    unsigned int half_pair_0, half_pair_1, half_pair_2, half_pair_3; /* low half, high half -> half[0..7] */
    unsigned int word_0x18;
};
extern struct dsc_encoder_rec dsc_encoder_record;
extern unsigned char dsc_enc_configured_flag;
extern int dbg_printf(const char *, ...);
extern void sys_dsc_enc_select_route(void);
extern void sys_dsc_enc_write_timing_words(void);
extern void sys_dsc_enc_compute_pps(void);

/*
 * Set the compression encoder up from the command received from the main processor (mailbox command 0xA5).
 * First the command is copied into the encoder's timing record: the four bytes of the second word, the eight
 * halfwords (low and high half of each of the next four words) and the last word. Then word_0x00 is derived
 * from the last word:  ((last >> 8) << last) * 10 >> 17, times 12, divided by 10, and doubled when bit 7 of
 * the last word is set. From it the two derived fields follow:
 *   q = word_0x00 * 100 / 400 when word_0x00 > 0xa9f, else word_0x00 * 100 / 340 (kept in 16 bits);
 *   slices = 4 when q <= 400, otherwise 8;
 *   bpp_divisor = 3 when word_0x00 > 0xbb7, otherwise 2.
 * The eight halfwords are printed as "DSC_ENC_TIMER_CONFIG" (four per line); then the encoder route is selected
 * (sys_dsc_enc_select_route), the timing words are written to the encoder (sys_dsc_enc_write_timing_words)
 * and the parameter set is computed and written (sys_dsc_enc_compute_pps). dsc_enc_configured_flag is set last.
 *   p: the command payload
 */
void sys_dsc_enc_configure(struct dsc_enc_command *p)
{
    unsigned short q;

    dsc_encoder_record.byte_0x18 = p->packed_bytes;
    dsc_encoder_record.source = p->packed_bytes >> 8;
    dsc_encoder_record.format = p->packed_bytes >> 16;
    dsc_encoder_record.bit_depth = p->packed_bytes >> 24;
    dsc_encoder_record.half[0] = p->half_pair_0;
    dsc_encoder_record.half[1] = p->half_pair_0 >> 16;
    dsc_encoder_record.half[2] = p->half_pair_1;
    dsc_encoder_record.half[3] = p->half_pair_1 >> 16;
    dsc_encoder_record.half[4] = p->half_pair_2;
    dsc_encoder_record.half[5] = p->half_pair_2 >> 16;
    dsc_encoder_record.half[6] = p->half_pair_3;
    dsc_encoder_record.half[7] = p->half_pair_3 >> 16;
    dsc_encoder_record.word_0x20 = p->word_0x18;
    dsc_encoder_record.word_0x00 = (((p->word_0x18 >> 8) << p->word_0x18) * 10 >> 17) * 12 / 10;
    if ((signed char)p->word_0x18 < 0)
        dsc_encoder_record.word_0x00 *= 2;
    if (dsc_encoder_record.word_0x00 > 0xa9f)
        q = dsc_encoder_record.word_0x00 * 100 / 400;
    else
        q = dsc_encoder_record.word_0x00 * 100 / 340;
    if (q <= 400)
        dsc_encoder_record.slices = 4;
    else if (q <= 800)
        dsc_encoder_record.slices = 8;
    else
        dsc_encoder_record.slices = 8;
    if (dsc_encoder_record.word_0x00 > 0xbb7)
        dsc_encoder_record.bpp_divisor = 3;
    else
        dsc_encoder_record.bpp_divisor = 2;
    dbg_printf(" DSC_ENC_TIMER_CONFIG %d %d %d %d \n\r", dsc_encoder_record.half[0], dsc_encoder_record.half[1], dsc_encoder_record.half[2], dsc_encoder_record.half[3]);
    dbg_printf(" DSC_ENC_TIMER_CONFIG %d %d %d %d \n\r", dsc_encoder_record.half[4], dsc_encoder_record.half[5], dsc_encoder_record.half[6], dsc_encoder_record.half[7]);
    sys_dsc_enc_select_route();
    sys_dsc_enc_write_timing_words();
    sys_dsc_enc_compute_pps();
    dsc_enc_configured_flag = 1;
}

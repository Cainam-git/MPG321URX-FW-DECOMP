/* sys_dsc_enc_set_parameters  (FUN_a00dd398)
 *
 * Unpack the compression parameters received from the main processor into the timing record.
 * Name basis: derived - bytes of the command into the record at 0xA8079538; called from ipc_dispatch_command
 *
 * Matching notes
 * --------------
 * FUN_a00dd398 (leon2s 0xa00dd398-0xa00dd488, 240 bytes), flags -mcpu=v8 -Os -g.
 * The print is a tail call of func_0xa0f83044 with the string.
 * Source form: one unsigned int temporary holds the upper byte of every halfword before the shift
 * ('upper = (w >> 8) & 0xff; h = (upper << 8) + (w & 0xff);'); the reuse keeps the per-word load order.
 */
struct Rec538 {
    unsigned char _0[5];
    unsigned char source;       /* +5: 0 DISP, 2 P2, 3 P3 (dsc_encoder_record_source) */
    unsigned char _6[2];
    unsigned short h8, ha, hc, he, h10, h12, h14, h16;   /* halfwords at +8 .. +0x16 */
    unsigned char b18;
};
extern struct Rec538 dsc_encoder_record;
extern int dbg_printf(const char *, ...);

#define B0(w) ((w) >> 24)
#define B1(w) (((w) >> 16) & 0xff)
#define B2(w) (((w) >> 8) & 0xff)
#define B3(w) ((w) & 0xff)

/* Unpack the command words (mailbox command 0xFE from the main processor) into dsc_encoder_record:
 *   word 5: low byte -> byte +0x18, bits 8..15 -> byte +5 (the source)
 *   words 1..4: each gives two halfwords, bits 0..15 -> +8 / +0xc / +0x10 / +0x14 and
 *               bits 16..31 -> +0xa / +0xe / +0x12 / +0x16 (each half is rebuilt from its two bytes).
 * Then prints the firmware's reminder that this step comes before DSC_ENC_TIMER_CONFIG() and DSC_ENC_PPS_GEN().
 *   words: the command words (word 0 is not used here)
 */
void sys_dsc_enc_set_parameters(unsigned int *words)
{
    unsigned int upper;

    dsc_encoder_record.b18 = words[5];
    dsc_encoder_record.source = words[5] >> 8;
    upper = B2(words[1]);
    dsc_encoder_record.h8 = (upper << 8) + B3(words[1]);
    upper = B0(words[1]);
    dsc_encoder_record.ha = (upper << 8) + B1(words[1]);
    upper = B2(words[2]);
    dsc_encoder_record.hc = (upper << 8) + B3(words[2]);
    upper = B0(words[2]);
    dsc_encoder_record.he = (upper << 8) + B1(words[2]);
    upper = B2(words[3]);
    dsc_encoder_record.h10 = (upper << 8) + B3(words[3]);
    upper = B0(words[3]);
    dsc_encoder_record.h12 = (upper << 8) + B1(words[3]);
    upper = B2(words[4]);
    dsc_encoder_record.h14 = (upper << 8) + B3(words[4]);
    upper = B0(words[4]);
    dsc_encoder_record.h16 = (upper << 8) + B1(words[4]);
    dbg_printf("STEP1. - DSC_SET_TIMING_CONFIG MUST before DSC_ENC_TIMER_CONFIG() and DSC_ENC_PPS_GEN()\n\r");
}

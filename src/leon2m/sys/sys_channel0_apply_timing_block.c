/* sys_channel0_apply_timing_block  (FUN_a013c040)
 *
 * Apply the timing block of channel 0 to the output stage.
 * Name basis: descriptive - copies the 0x3C-byte block and passes it on with width, height and interlace flag;
 *   unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013c040 @ 0xa013c040-0xa013c144 (260 bytes), flags -mcpu=v8 -O3 -g.
 * Declaration order timing_copy_interlaced, timing_copy gives the firmware stack slots (fp-136 / fp-72).
 */
struct timing_block { unsigned char d[0x3c]; };
/* Channel record (0x78 bytes, table channel_records): the 0x3C-byte timing block at +6, the halfword +0x18 that
   overlaps it, and the words +0x68 and +0x70. */
struct channel_record {
    union {
        struct { unsigned char pad0[6]; struct timing_block timing; } a;
        struct { unsigned char pad0[0x18]; unsigned short half_0x18; } b;
    } u;
    unsigned char pad42[0x26];
    union { unsigned int w; unsigned char b[4]; } word_0x68;
    unsigned int word_0x6c;
    int flags;                                  /* +0x70 */
};
extern unsigned int sys_config;
extern struct channel_record *sys_find_channel_by_port(unsigned char port);
extern void *memcpy(void *dst, const void *src, int n);
extern unsigned char input_block_get_status_bit2(unsigned char port);
extern void SetFRCCHRW(unsigned char a, struct timing_block *t, unsigned short w, unsigned short h, unsigned char il, unsigned char x, unsigned char y);
extern void input_block0_toggle_pre_frc(void);

#define SYS_CONFIG_BIT25 0x2000000              /* bit 25 of sys_config word 0 */
#define WORD_0X68_BIT22 0x400000
#define WORD_0X68_BIT21 0x200000

/*
 * Apply the timing block of the channel record of port 0 with SetFRCCHRW; any other port does nothing.
 *
 *   port  only 0 does anything
 *   w, h  width and height passed on
 *
 * The 0x3C-byte block at record +6 is copied first. When bit 25 of sys_config is set, flag bit 31 (+0x70) is
 * set and input_block_get_status_bit2(0) is 1, SetFRCCHRW gets the halfword +0x18 of the record instead of h and
 * the flag 1, and the top byte of word +0x68 is cleared. Always: bits 22 and 21 of word +0x68 are cleared and
 * input_block0_toggle_pre_frc is called. No routine calls it by name.
 */
void sys_channel0_apply_timing_block(unsigned char port, unsigned short w, unsigned short h)
{
    struct channel_record *record;
    struct timing_block timing_copy_interlaced;
    struct timing_block timing_copy;

    record = sys_find_channel_by_port(port);
    if (port != 0)
        return;
    if ((sys_config & SYS_CONFIG_BIT25) && record->flags < 0 && input_block_get_status_bit2(0) == 1) {
        memcpy(&timing_copy_interlaced, &record->u.a.timing, 0x3c);
        SetFRCCHRW(0, &timing_copy_interlaced, w, record->u.b.half_0x18, 1, 0, 0);
        record->word_0x68.b[0] = 0;
    } else {
        memcpy(&timing_copy, &record->u.a.timing, 0x3c);
        SetFRCCHRW(0, &timing_copy, w, h, 0, 0, 0);
    }
    record->word_0x68.w &= ~WORD_0X68_BIT22;
    record->word_0x68.w &= ~WORD_0X68_BIT21;
    input_block0_toggle_pre_frc();
}

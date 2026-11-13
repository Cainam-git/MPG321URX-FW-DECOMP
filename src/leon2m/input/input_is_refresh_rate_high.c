/* input_is_refresh_rate_high  (FUN_a013bb50)
 *
 * Return 1 when the refresh rate in a port's channel record passes its limit (300.0 or 245.1 Hz).
 * Returns: 0 or 1
 * Note: The limit is 300.0 Hz for port 0 when its port mask bit is set, else 245.1 Hz.
 * Name basis: derived - channel record +8 (refresh rate, tenths of Hz) against 3000 or 0x993
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013bb50 @ 0xa013bb50, flags -mcpu=v8 -O3 -g (cflags in symbols/leon2m.json).
 * Source form the exact build depends on: the && chain, unsigned char prototypes (callers test the result with
 * btst 0xff), and the last test as "if (refresh_rate >= 0x993) return 1; return 0;" (if-converted to a
 * branch-free set-on-greater-or-equal).
 */

/* The channel record, up to the field used here. */
struct channel_record_head {
    unsigned int status_word;       /* +0: port in bits 12-15 */
    unsigned int word_0x4;
    unsigned short refresh_rate;    /* +8: timing field 1, in tenths of a hertz */
};
extern struct channel_record_head *sys_find_channel_by_port(unsigned char port);
extern unsigned char input_get_port_mask_bit(unsigned char port);

#define REFRESH_LIMIT_FLAGGED 3000      /* 300.0 Hz: limit for id 0 when its port's mask bit is set */
#define REFRESH_LIMIT         0x993     /* 245.1 Hz: limit in every other case */

/*
 * Return 1 when the refresh rate in the channel record of a port is above its limit.
 *
 *   id  the port of the channel record to test
 *
 * The limit is 300.0 Hz when id is 0 and the mask bit of the record's own port is set (input_get_port_mask_bit,
 * the bit that input_match_port_mode sets from port status bit 10). In every other case the refresh rate must
 * reach 245.1 Hz.
 *
 * (The name and the first line of the header say "line rate"; the field tested is the refresh rate.)
 */
unsigned char input_is_refresh_rate_high(unsigned char id)
{
  struct channel_record_head *record = sys_find_channel_by_port(id);

  if (id == 0 && input_get_port_mask_bit((record->status_word >> 12) & 0xf) && record->refresh_rate > REFRESH_LIMIT_FLAGGED)
    return 1;
  if (record->refresh_rate >= REFRESH_LIMIT)
    return 1;
  return 0;
}

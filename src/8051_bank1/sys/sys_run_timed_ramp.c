/* sys_run_timed_ramp  (FUN_CODE_42f6)
 *
 * Step the timed toggle or ramp set up by the main processor (indicator control).
 * Note: Mode 1 toggles bits of an XDATA register; other modes step bytes of the 0xE84B records towards
 *   high/low.
 * Name basis: derived - record 0xA735 set by commands 0x18/0x19/0x1A/0x30/0x31 (sys_set_timed_toggle_target,
 *   sys_set_timed_ramp_fields); main side ipc_8051_set_indicator
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_42f6 @ 0x42f6 (692 B)  Byte-exact with OPTIMIZE(8,SPEED) LARGE.
 * LARGE locals include rate 0xA475, i 0xA477, top 0xA479, bottom 0xA47A, entry 0xA47B..0xA47D.
 * volatile on 0xE84B..: outside the XDATA RAM blocks the start-up code clears (0xA000..0xAFFF, 0xF800..0xFFFF),
 *   referenced by no other code, read and rewritten in place through entry. Keil therefore stores entry and reads it
 *   back before the first access (type byte stored with 'MOV A,#01H').
 * Source form: the record index is written as the expression '(fields.b[i] & 0xe0) >> 5' both in the test against
 *   7 and in the index (Keil reuses the value in R5; a local copy adds 'MOV R7,AR5').
 * No local name may contain 'low' or 'high': the address fill then patches one byte of 'MOV DPTR,#name'.
 */

/* The timed toggle / ramp record at XDATA 0xA735, filled by mailbox commands 0x18, 0x19, 0x1A, 0x30 and 0x31
 * (sys_set_timed_toggle_target, sys_set_timed_limits_ch0 / _ch1, sys_set_timed_ramp_fields,
 * sys_set_timed_ramp_step). */
struct timed_pair {
    unsigned char top;          /* toggle: register value; ramp: top end */
    unsigned char bottom;       /* toggle: hold time in units of 100 ticks; ramp: bottom end */
};
struct timed_record {
    unsigned int last;          /* timer_get_ticks value of the last change */
    unsigned char steps[2];     /* per ramp channel: bit 7 = moving down, bits 0..6 = step */
    unsigned char mode;         /* TIMED_MODE_* */
    union {
        unsigned int addr;      /* toggle: XDATA address of the register (command 0x18) */
        unsigned char b[2];     /* ramp, per channel: bits 5..7 = record index, bits 0..4 = rate (command 0x30) */
    } fields;
    struct timed_pair limits[2];
};
extern struct timed_record xdata sys_timed_record;
extern struct { unsigned char b[6]; } volatile xdata DAT_EXTMEM_e84b[];
extern unsigned int timer_get_ticks(void);

#define TIMED_MODE_OFF      0
#define TIMED_MODE_TOGGLE   1   /* set by command 0x18; command 0x30 sets 2 */
#define RAMP_RECORD_NONE    7   /* record index 7: channel not used */
#define STEP_MOVING_DOWN    0x80
#define TICKS_PER_UNIT      100

/*
 * sys_run_timed_ramp - one step of the timed toggle or ramp that the main processor set up with mailbox commands
 * 0x18..0x1A and 0x30..0x31 (named indicator commands on the main side). Called by sys_main on every round of its
 * loop while the run state is power saving.
 *
 * Toggle (TIMED_MODE_TOGGLE): the register at fields.addr switches between limits[0].top and limits[1].top.
 *   Only the bits in which the two values differ are changed. While the register holds limits[0].top it is
 *   switched once more than limits[0].bottom units of 100 ticks have passed since the last change; in any other
 *   state it is switched back once more than limits[1].bottom units have passed.
 * Ramp (any other mode): at most once per 100 ticks. For each channel 0 and 1 whose record index is not 7, the
 *   first byte of the 6-byte record [index] at XDATA 0xE84B moves by one step towards limits[ch].top (bit 7 of
 *   steps[ch] clear) or limits[ch].bottom (bit 7 set). The step is (steps[ch] & 0x7F) * rate of channel 0 / 10, at
 *   least 1. When less than one step remains, the byte is set to the end, the direction turns and steps[ch] gets
 *   (top - bottom) / (rate of channel 1 * 5), the value sys_set_timed_ramp_step also computes.
 */
void sys_run_timed_ramp(void)
{
    unsigned int now;
    unsigned char rate;
    unsigned char step;
    unsigned char i;
    unsigned char current;
    unsigned char top;
    unsigned char bottom;
    unsigned char *entry;
    unsigned char old;
    unsigned char diff_bits;
    unsigned char restart_step;

    if (sys_timed_record.mode == TIMED_MODE_OFF) return;
    now = timer_get_ticks();
    if (sys_timed_record.mode == TIMED_MODE_TOGGLE) {
        entry = (unsigned char xdata *)sys_timed_record.fields.addr;
        if (*entry == sys_timed_record.limits[0].top) {
            if ((now - sys_timed_record.last) / TICKS_PER_UNIT > sys_timed_record.limits[0].bottom) {
                diff_bits = sys_timed_record.limits[0].top ^ sys_timed_record.limits[1].top;
                old = *entry;
                *entry = (sys_timed_record.limits[1].top & diff_bits) | (old & ~diff_bits);
            } else
                return;
        } else {
            if ((now - sys_timed_record.last) / TICKS_PER_UNIT <= sys_timed_record.limits[1].bottom) return;
            diff_bits = sys_timed_record.limits[0].top ^ sys_timed_record.limits[1].top;
            old = *entry;
            *entry = (sys_timed_record.limits[0].top & diff_bits) | (old & ~diff_bits);
        }
        sys_timed_record.last = now;
    } else {
        if (now - sys_timed_record.last <= TICKS_PER_UNIT) return;
        sys_timed_record.last = now;
        for (i = 0; i < 2; i++) {
            if (((sys_timed_record.fields.b[i] & 0xe0) >> 5) == RAMP_RECORD_NONE) continue;
            rate = sys_timed_record.fields.b[0] & 0x1f;
            top = sys_timed_record.limits[i].top;
            bottom = sys_timed_record.limits[i].bottom;
            entry = DAT_EXTMEM_e84b[((sys_timed_record.fields.b[i] & 0xe0) >> 5)].b;
            current = *entry;
            step = (unsigned int)((sys_timed_record.steps[i] & 0x7f) * rate) / 10;
            if (step == 0) step = 1;
            restart_step = (top - bottom) / ((sys_timed_record.fields.b[1] & 0x1f) * 5);
            if (!(sys_timed_record.steps[i] & STEP_MOVING_DOWN)) {
                if ((unsigned char)(top - current) < step) {
                    /* Top reached: turn down. */
                    *entry = top;
                    sys_timed_record.steps[i] = restart_step + STEP_MOVING_DOWN;
                } else {
                    *entry = current + step;
                    sys_timed_record.steps[i] = step;
                }
            } else {
                if ((unsigned char)(current - bottom) < step) {
                    /* Bottom reached: turn up. */
                    *entry = bottom;
                    sys_timed_record.steps[i] = restart_step;
                } else {
                    *entry = current - step;
                    sys_timed_record.steps[i] = step + STEP_MOVING_DOWN;
                }
            }
        }
    }
}

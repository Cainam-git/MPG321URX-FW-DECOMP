/* audio_calc_hdmi21_sample_rate  (FUN_a00a211c)
 *
 * Compute the audio sample rate of an HDMI 2.1 receiver from N, CTS and link clock.
 *   receiver: HDMI 2.1 receiver 0/1
 * Returns: sample rate (units of 100 Hz)
 * Name basis: proven - fs = clock * N / CTS * 10000 / 128; clock = TMDS / 10 or 166/333/444/555/666 MHz for
 *   FRL rates
 *
 * Matching notes
 * --------------
 * leon2s, flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on: the register block behind the record word at +4 is read through a
 * volatile unsigned int pointer, because the firmware loads the full words at +4/+8/+0xc and extracts the fields
 * (a plain pointer lets gcc narrow them to ldub/lduh); the codes are a jump-table switch with the clock held in
 * an unsigned short.
 */
struct port_regs {
    unsigned int field0;
    volatile unsigned int *field4;   /* +4: address of the receiver's register block */
    unsigned int field8;    /* +8 */
    unsigned int field_c;   /* +0xc: base address */
    unsigned int field_10;
    unsigned int field_14;
    unsigned int field_18;  /* +0x18: cfg pointer */
    unsigned int field_1c;
    unsigned int field_20;
    unsigned int field_24;
    unsigned int field_28;
    unsigned int field_2c;
    unsigned int field_30;
};

extern struct port_regs hdmi_rx21_reg_blocks[];            /* 0xa807db00 */
extern unsigned char hdmi_rx21_get_link_rate_code(unsigned int param_1);   /* 0xa00a20a8 */
extern unsigned short hdmi_rx21_calc_tmds_clock(unsigned char idx);     /* 0xa00a20c4 */

/*
 * Audio sample rate of an HDMI 2.1 receiver, from the N and CTS values its register block holds and the
 * clock of the link:  rate = clock * N / CTS * 10000 / 128.
 *
 *   receiver  HDMI 2.1 receiver 0 or 1
 *
 * Returns the rate in units of 100 Hz (clock in MHz), or 0 when N or CTS is 0.
 * N is a 24-bit value: bits 0..7 of register word 2 (as the high byte) and bits 16..31 of register word 1.
 * CTS is bits 0..23 of register word 3. The words belong to the register block whose address is the
 * second word of the receiver's hdmi_rx21_reg_blocks entry.
 * Clock by link rate code (hdmi_rx21_get_link_rate_code): 0 (TMDS) = hdmi_rx21_calc_tmds_clock / 10,
 * 1 = 166, 2 and 3 = 333, 4 = 444, 5 = 555, 6 = 666 MHz; any other code gives clock 0.
 * Caller: audio_check_hdmi21_rate_valid (it accepts 301..1929).
 */
unsigned short audio_calc_hdmi21_sample_rate(unsigned int receiver)
{
    unsigned int cts, n;
    unsigned short clock_mhz;
    struct port_regs *rec;
    volatile unsigned int *ptr;
    unsigned char rate_code;

    receiver &= 0xff;
    rec = &hdmi_rx21_reg_blocks[receiver];
    ptr = rec->field4;

    n = ((ptr[2] & 0xff) << 16) | (ptr[1] >> 16);
    cts = ptr[3] & 0xffffff;

    if (n != 0 && cts != 0) {
        rate_code = hdmi_rx21_get_link_rate_code(receiver);
        clock_mhz = 0;
        switch (rate_code) {
        case 0:
            clock_mhz = hdmi_rx21_calc_tmds_clock(receiver) / 10;
            break;
        case 1:
            clock_mhz = 166;
            break;
        case 2:
        case 3:
            clock_mhz = 333;
            break;
        case 4:
            clock_mhz = 444;
            break;
        case 5:
            clock_mhz = 555;
            break;
        case 6:
            clock_mhz = 666;
            break;
        }
        return (unsigned short)((clock_mhz * n / cts * 10000) >> 7);
    }
    return 0;
}

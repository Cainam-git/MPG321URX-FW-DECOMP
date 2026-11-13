/* input_set_ports_power_on_by_status  (FUN_a00b3530)
 *
 * Set the link state of port records above state 3 back to 2 (power on) when status register bits ask.
 * Returns: 3 after the update, -1 when the count is not 9
 * Note: Register 0xCF03C880 bit 0 with record flag bit 1, or bit 1 with bit 3 of halfword +0x12 clear and bit
 *   13 of halfword +0xE set (cleared in the same step). Then copies 0xCF03C910 to 0xCF03C920.
 * Name basis: descriptive - register 0xCF03C880 bits 0 and 1; link state byte of the nine port records set to
 *   2; called with 9 from input_poll_port_services
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00b3530 @ 0xa00b3530-0xa00b383c (195 words), flags -mcpu=v8 -g (no -O: cflags entry in
 * symbols/leon2s.json; the code is unoptimised).
 * Source form: halfword bit-fields are read through (unsigned char) casts (the firmware masks each extracted
 * bit with 0xff); both sides of the test of bit 3 of +0x12 contain the same statement in the firmware's code,
 * and it keeps both; two return statements (the unoptimised code keeps the result in a stack slot).
 */
#define LINK_STATE_POWER_ON 2  /* link state 2; 1 is power off (see input_set_ports_power_off) */

/* One of the nine 20-byte port records (see docs/DATA.md); only the fields used here are named. */
struct port_record {
    unsigned char link_state;       /* +0 */
    unsigned char _1[0xc];
    unsigned char published_flags;  /* +0xD: flags published to the main processor; bit 1 is tested */
    unsigned short word_0xe_top : 2;
    unsigned short word_0xe_bit13 : 1;  /* bit 13 of the halfword at +0xE */
    unsigned short word_0xe_low : 13;
    unsigned char _10[2];
    unsigned short flags_0x12_high : 12;
    unsigned short flags_0x12_bit3 : 1; /* bit 3 of the flags halfword at +0x12 */
    unsigned short flags_0x12_low : 3;
};
extern struct port_record input_port_records[];

#define REG_CF03C880 (*(volatile unsigned int *)0xcf03c880)
#define REG_CF03C910 (*(volatile unsigned int *)0xcf03c910)
#define REG_CF03C920 (*(volatile unsigned int *)0xcf03c920)

/*
 * Read the low byte of status register 0xCF03C880 and, for every one of the nine port records whose link
 * state is above 3, set the link state to 2 (power on) when:
 *   - register bit 0 is set and bit 1 of the record's published flags (+0xD) is set, or
 *   - register bit 1 is set, bit 3 of the record's flags halfword (+0x12) is clear and bit 13 of the halfword
 *     at +0xE is set; that bit 13 is cleared in the same step.
 * Afterwards the register 0xCF03C910 is copied to 0xCF03C920.
 * Parameter: count; the routine only works when it is 9 (the number of records).
 * Returns: 3 after the update, -1 (nothing done) for any other count. Called with 9 by input_poll_port_services.
 */
int input_set_ports_power_on_by_status(unsigned char n)
{
    unsigned char i;
    unsigned char status;

    if (n != 9)
        return -1;
    {
        status = REG_CF03C880;
        for (i = 0; i < n; i++) {
            if (input_port_records[i].link_state > 3) {
                if (status & 1) {
                    if ((unsigned char)input_port_records[i].flags_0x12_bit3) {
                        if (input_port_records[i].published_flags & 2)
                            input_port_records[i].link_state = LINK_STATE_POWER_ON;
                    } else {
                        if (input_port_records[i].published_flags & 2)
                            input_port_records[i].link_state = LINK_STATE_POWER_ON;
                    }
                }
                if (status & 2) {
                    if (!(unsigned char)input_port_records[i].flags_0x12_bit3) {
                        if ((unsigned char)input_port_records[i].word_0xe_bit13) {
                            input_port_records[i].word_0xe_bit13 = 0;
                            input_port_records[i].link_state = LINK_STATE_POWER_ON;
                        }
                    }
                }
            }
        }
        REG_CF03C920 = REG_CF03C910;
    }
    return 3;
}

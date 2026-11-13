/* input_adc_configure  (FUN_a00f32d8)
 *
 * Run the on or off register sequence of the analogue input stage and keep its record.
 * Name basis: descriptive - 0x24-byte record copied to 0xA802B770; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f32d8 @ 0xa00f32d8-0xa00f3528 (148 words), flags -mcpu=v8 -O3 -g.
 * Source form: every register access is a plain volatile word access R(address) in the order of the firmware;
 * the two accesses to 0xcf020114 (store 0xe0, later '|= 0xe0') and to 0xcf0200cc are separate statements.
 */
/* The record that stays in input_adc_record. The routines that read it (input_adc_set_line_width,
   input_adc_get_line_width, input_adc_set_phase, input_adc_get_phase) call a hook only when `enabled` is set and
   the hook is not null; otherwise they use the hardware registers themselves. 0x24 bytes. */
struct adc_hooks {
    unsigned char enabled;                      /* +0 */
    void *set_line_width;                       /* +4: called with (block, width) by input_adc_set_line_width */
    unsigned int (*get_line_width)(void);       /* +8: used by input_adc_get_line_width */
    void (*set_phase)(unsigned char);           /* +0xC: used by input_adc_set_phase */
    unsigned int (*get_phase)(void);            /* +0x10: used by input_adc_get_phase */
    void *hook_0x14, *hook_0x18, *hook_0x1c, *hook_0x20;     /* not used by any routine seen */
};
extern struct adc_hooks input_adc_record;
extern void input_capture_write8(unsigned char blk, unsigned char reg, unsigned char val);
extern void reg_write16_bytes(volatile unsigned int *r, unsigned int v);

#define R(a) (*(volatile unsigned int *)(a))

/*
 * Switch the analogue input stage on or off with a fixed sequence of register writes, then keep the hook record
 * for the other input_adc_* routines.
 *
 *   on     nonzero: the 'on' sequence; 0: the 'off' sequence. This is not the `enabled` field of the record.
 *   hooks  the record to keep; in both cases all 0x24 bytes are copied to input_adc_record at the end.
 *
 * 'On' sequence: clears registers 0xCF020024 to 0xCF020038, then loads fixed values into the registers
 * 0xCF0200xx and 0xCF0201xx, writes 0x81 to registers 1 and 2 of input capture block 8 (all blocks), sets the
 * line width pair 0xCF012820 to 0x800, loads 0x33, 0x81 and 2 into 0xCF012800, 0xCF012808 and 0xCF012804, sets bit 1
 * of 0xCF0116B8, writes 0x53 to 0xCF01141C and 0xCF011420 and ends with bit changes in 0xCF020080, 0xCF02006C
 * and 0xCF02003C.
 * 'Off' sequence: clears 0xCF0200D4, bits 0xE0 of 0xCF020114 and bits 0x41 of 0xCF0200CC, writes 0x50 and 0x22 to
 * 0xCF020134 and 0xCF020138, clears 0xCF012800 and 0xCF0200CC, writes 0x88 to 0xCF01141C and 0xCF011420.
 * What these registers do is not shown by the firmware. No routine calls this one directly.
 */
void input_adc_configure(unsigned char on, struct adc_hooks *hooks)
{
    if (on) {
        R(0xcf020024) = 0;
        R(0xcf020028) = 0;
        R(0xcf02002c) = 0;
        R(0xcf020030) = 0;
        R(0xcf020034) = 0;
        R(0xcf020038) = 0;
        R(0xcf02003c) = 0xe0;
        R(0xcf020074) = 0;
        R(0xcf020080) = 0x20;
        R(0xcf020084) = 0;
        R(0xcf020040) = 0x80;
        R(0xcf020044) = 0x40;
        R(0xcf020114) = 0xe0;
        R(0xcf02011c) = 3;
        R(0xcf020120) = 0xa;
        R(0xcf020124) = 0x48;
        R(0xcf02004c) = 0x40;
        R(0xcf020058) = 0xe0;
        R(0xcf02005c) = 0x80;
        R(0xcf020064) = 0x80;
        R(0xcf02008c) = 0;
        R(0xcf0200d4) = 0xe0;
        R(0xcf020114) |= 0xe0;
        input_capture_write8(8, 1, 0x81);
        input_capture_write8(8, 2, 0x81);
        reg_write16_bytes(&R(0xcf012820), 0x800);
        R(0xcf012800) = 0x33;
        R(0xcf012808) = 0x81;
        R(0xcf012804) = 2;
        R(0xcf0116b8) |= 2;
        R(0xcf01141c) = 0x53;
        R(0xcf011420) = 0x53;
        R(0xcf020080) &= ~0x90;
        R(0xcf02006c) |= 0xe0;
        R(0xcf02003c) |= 0xe0;
    } else {
        R(0xcf0200d4) = 0;
        R(0xcf020114) &= ~0xe0;
        R(0xcf0200cc) &= ~0x41;
        R(0xcf020134) = 0x50;
        R(0xcf020138) = 0x22;
        R(0xcf012800) = 0;
        R(0xcf0200cc) = 0;
        R(0xcf01141c) = 0x88;
        R(0xcf011420) = 0x88;
    }
    input_adc_record = *hooks;
}

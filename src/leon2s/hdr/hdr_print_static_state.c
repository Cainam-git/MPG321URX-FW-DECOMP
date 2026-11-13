/* hdr_print_static_state  (FUN_a00d2920)
 *
 * Print the static HDR state and read the tone-mapping table back.
 * Name basis: proven - prints the 'Static HDR' state and a 'Re-appl...' line; reads the TMO LUT when the
 *   status register reads 2
 *
 * Matching notes
 * --------------
 * leon2s, flags -mcpu=v8 -Os -g.
 * Source form: i = 0 at its declaration (the firmware sets it before the first test). The ROM helpers outside
 * the image (register access, debug print, UART string, wait) are declared by their link names.
 */
struct HdrInfo {
    unsigned int w0;
    unsigned int enEOTF_Type;
    unsigned char _8[0x1c - 8];
    unsigned short u16Max_MasterLum;
    unsigned char _1e[2];
    unsigned short u16MaxCLL;
};
extern struct HdrInfo hdr_static_info;
extern unsigned char hdr_source, hdr_status_code, hdr_eotf_mode;
extern unsigned short hdr_gain, hdr_peak_luminance;
extern unsigned short hdr_tone_curve[];
extern const char s_9f1cca78[];
extern unsigned int reg_read32(unsigned int);
extern void reg_write32(unsigned int, unsigned int);
extern void reg_write_bit_field(unsigned int *, unsigned int, unsigned int, unsigned int);
extern void uart_put_string(const char *);
extern void timer_delay_long_units(unsigned int);
extern int dbg_printf(const char *, ...);

/*
 * Print the static HDR state on the debug port when the status register 0xD0013FF0 asks for it, and read
 * the tone-mapping table back for comparison. No parameters, no return value. Called at the end of every
 * hdr_task round.
 *
 * What it does depends on the value of 0xD0013FF0:
 *  - 0x55: write 0 back, set hdr_status_code to 0, print "Re-apply HDR!" and a string on the UART; done.
 *  - 2: write 0 back and print the eight "[Static HDR]" lines (enEOTF_Type, u16Max_MasterLum and u16MaxCLL
 *    of hdr_static_info, gu8HDR_Mode = hdr_status_code, u8EOTFMode = hdr_eotf_mode, ucHDRSource,
 *    u16HDRGain = hdr_gain, PanelMaxLum = hdr_peak_luminance). Then read the table back through
 *    0xD0013F60 / 0xD0013F64: set bits 0 and 20 of 0xD0013F60, and for the indices 0, 0x10 .. 0x100 write
 *    the index into bits 16..8, wait (three writes of the register with waits of 5, 5 and 10 long units)
 *    and print TMO_LUT[i] (the value read from 0xD0013F64) next to g_usRealTMO[i] (hdr_tone_curve[i]).
 *    At the end print a string on the UART and clear bits 0 and 20 again.
 *  - any other value: nothing.
 */
void hdr_print_static_state(void)
{
    unsigned int w = 0;     /* value of the register 0xD0013F60 */
    unsigned int i = 0;     /* table index being compared */

    if (reg_read32(0xd0013ff0) == 0x55) {
        reg_write32(0xd0013ff0, 0);
        hdr_status_code = 0;
        dbg_printf("Re-apply HDR!");
        uart_put_string(s_9f1cca78);
        return;
    }
    if (reg_read32(0xd0013ff0) != 2)
        return;
    reg_write32(0xd0013ff0, 0);
    dbg_printf("[Static HDR]g_HDR_Info.enEOTF_Type=%d\n", hdr_static_info.enEOTF_Type);
    dbg_printf("[Static HDR]g_HDR_Info.u16Max_MasterLum=%d\n", hdr_static_info.u16Max_MasterLum);
    dbg_printf("[Static HDR]g_HDR_Info.u16MaxCLL=%d\n", hdr_static_info.u16MaxCLL);
    dbg_printf("[Static HDR]gu8HDR_Mode=%d\n", hdr_status_code);
    dbg_printf("[Static HDR]u8EOTFMode=0x%X\n", hdr_eotf_mode);
    dbg_printf("[Static HDR]ucHDRSource=0x%X\n", hdr_source);
    dbg_printf("[Static HDR]u16HDRGain=0x%X\n", hdr_gain);
    dbg_printf("[Static HDR]PanelMaxLum=%d\n", hdr_peak_luminance);
    w = reg_read32(0xd0013f60);
    reg_write_bit_field(&w, 0, 0, 1);
    reg_write_bit_field(&w, 0x14, 0x14, 1);
    reg_write_bit_field(&w, 0x10, 8, 0);
    reg_write32(0xd0013f60, w);
    for (; i <= 0x100; i += 0x10) {
        reg_write_bit_field(&w, 0, 0, 1);
        reg_write_bit_field(&w, 0x10, 8, i);
        reg_write32(0xd0013f60, w);
        timer_delay_long_units(5);
        reg_write32(0xd0013f60, w);
        timer_delay_long_units(5);
        reg_write32(0xd0013f60, w);
        timer_delay_long_units(10);
        dbg_printf("[Static HDR]    TMO_LUT[%d]=%d\n", i, reg_read32(0xd0013f64));
        dbg_printf("[Static HDR]g_usRealTMO[%d]=%d\n", i, hdr_tone_curve[i]);
    }
    uart_put_string(s_9f1cca78);
    w = reg_read32(0xd0013f60);
    reg_write_bit_field(&w, 0, 0, 0);
    reg_write_bit_field(&w, 0x14, 0x14, 0);
    reg_write32(0xd0013f60, w);
}

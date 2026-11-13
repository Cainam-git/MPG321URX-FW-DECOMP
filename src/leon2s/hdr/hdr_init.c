/* hdr_init  (FUN_a00d27fc)
 *
 * Initialise the HDR service: neutral curve, default record, coefficients and HDR10+ set-up.
 * Name basis: derived - called by a command from the main processor
 *
 * Matching notes
 * --------------
 * leon2s, flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on: the five (0, 0) callees take two unsigned char and return int (with
 * (int, int) prototypes gcc sets %o0 before %o1).
 */
extern unsigned char hdr_source;
extern unsigned char hdr_tmo_coefficients[];
extern int hdr_tmo_set_reg_fd0_bit(unsigned char, unsigned char);
extern int hdr_tmo_set_reg_fe0_bit(unsigned char, unsigned char);
extern int hdr_tmo_set_reg_f50_bit(unsigned char, unsigned char);
extern int hdr_tmo_set_reg_f60_f70_bit(unsigned char, unsigned char);
extern int hdr_tmo_set_reg_f10_bit(unsigned char, unsigned char);
extern void hdr_tmo_write_coefficients(void);
extern void hdr_select_source(unsigned char);
extern void hdr_reset_tone_curve(void);
extern void hdr_tmo_setup_mode(int);
extern void uart_put_string(unsigned int);
extern void reg_write_bit_field(unsigned int *, int, int, int);
extern unsigned int reg_read32(unsigned int);
extern void reg_write32(unsigned int, unsigned int);
extern /*
 * Bring the HDR tone-mapping service to its start state.
 *
 *   keep_coefficients  0 = reload the nine tone-mapping coefficients (hdr_tmo_coefficients) from the
 *                      default values in the image; non-zero = keep the current ones
 *
 * Called by the mailbox command "reload HDR tone curve" (0xA2) with 0, right after
 * hdr_request_curve_table_reload.
 *
 * Order: neutral tone curve; set bit 0 of 0xCF011F00; select the current HDR source; optionally restore the
 * coefficients; write them to the block (hdr_tmo_write_coefficients); load tone-mapping table 1
 * (hdr_tmo_setup_mode); HDR10+ set-up (hdr_init_hdr10plus); clear the five control bits; set the value
 * limits in 0xD0013FA0 and 0xD0013FAC; print one text on the debug port and one string on the UART.
 */
void hdr_init_hdr10plus(void);
extern void dbg_printf(unsigned int);
extern void lib_memcpy(void *, unsigned int, unsigned int);

void hdr_init(unsigned char keep_coefficients)
{
  unsigned int reg_value;

  reg_value = 0;
  /* neutral tone curve (every entry 0x400) */
  hdr_reset_tone_curve();
  *((volatile unsigned int *) 0xcf011f00) = (*((volatile unsigned int *) 0xcf011f00)) | 1;
  hdr_select_source(hdr_source);       /* re-select the current source; this also resets hdr_status_code */
  /* default coefficients, nine 32-bit values from the image */
  if (keep_coefficients == 0)
    lib_memcpy(hdr_tmo_coefficients, 0x9f1b07d0, 0x24);
  hdr_tmo_write_coefficients();
  hdr_tmo_setup_mode(1);                /* tone-mapping table 1 */
  hdr_init_hdr10plus();
  /* clear one control bit in each of the registers 0xD0013FD0, FE0, F60/F70, F50 and F10 */
  hdr_tmo_set_reg_fd0_bit(0, 0);
  hdr_tmo_set_reg_fe0_bit(0, 0);
  hdr_tmo_set_reg_f60_f70_bit(0, 0);
  hdr_tmo_set_reg_f50_bit(0, 0);
  hdr_tmo_set_reg_f10_bit(0, 0);
  /* open the value ranges: 0xD0013FA0 bits 11..0 = 0x3FF, 0xD0013FAC bits 3..0 = 0xF */
  reg_value = reg_read32(0xd0013fa0);
  reg_write_bit_field(&reg_value, 0xb, 0, 0x3ff);
  reg_write32(0xd0013fa0, reg_value);
  reg_value = reg_read32(0xd0013fac);
  reg_write_bit_field(&reg_value, 3, 0, 0xf);
  reg_write32(0xd0013fac, reg_value);
  dbg_printf(0x9f1c6240);
  uart_put_string(0x9f1cca78);
}

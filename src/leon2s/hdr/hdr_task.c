/* hdr_task  (FUN_a00d3c40)
 *
 * Run the HDR service once: read the source's metadata and update or switch off the tone curve.
 * Note: Runs only while register 0xCF03C80C reads 0x99; hdr_update_tone_curve runs only when the source
 *   reports HDR, its metadata changed and the EOTF type is above 1; hdr_apply_tone_curve runs when it does not
 *   report HDR and option bits 0 and 1 are set
 * Name basis: derived - gate register 0xCF03C80C == 0x99; source enable bit, metadata time-out,
 *   hdr_read_source_metadata, hdr_has_metadata_changed, hdr_update_tone_curve; ends with the state print and
 *   hdr_dump_hdr10plus_metadata
 *
 * Matching notes
 * --------------
 * leon2s, 0xa00d3c40..0xa00d3eb0 (the last bytes, FUN_a00d3ea8, are an unreachable ret/restore tail inside the
 * range). Flags -mcpu=v8 -Os -g.
 * No direct call to this routine exists in the image (reached through a pointer or table).
 * Source form: the prototypes of the calls outside the image (0xa0f7xxxx/0xa0f8xxxx/0xa0fcxxxx) are the ones
 * that give the firmware bytes; dbg_printf returns int (void changes the argument set-up). Two result variables
 * (hdr_active for hdr_is_source_hdr_active, changed for hdr_has_metadata_changed), one shared variable gives
 * different code. The tests of the "== 1" results are on the low byte (& 0xff). The block ends in a tail call of
 * hdr_dump_hdr10plus_metadata.
 */
extern unsigned char hdr_source;
extern unsigned char hdr_status_code;
extern unsigned char hdr_task_byte;
extern unsigned char hdr_mode_byte;
extern unsigned char hdr_settings_changed_flag;
extern unsigned char hdr_source_disable_bits;
extern unsigned char hdr_option_byte;
extern unsigned int hdr_last_update_ticks;
extern unsigned int hdr_static_info_eotf_type;
extern void hdr_mark_source_active(void);
extern void hdr_ack_dp_metadata(void);
extern void hdr_tmo_disable_and_print(void);
extern void hdr_tmo_enable_second(void);
extern int hdr_is_source_hdr_active(void);
extern void hdr_read_source_metadata(void);
extern int hdr_has_metadata_changed(void);
extern int hdr_update_tone_curve(void);
extern void hdr_tmo_disable(void);
extern void hdr_apply_tone_curve(void);
extern int hdr_is_update_due(void);
extern void hdr_update_smoothed_level(void);
extern void hdr_print_static_state(void);
extern void reg_write32(unsigned int, unsigned int);
extern int hdr_check_metadata_timeout(void);
extern int dbg_printf(unsigned int, unsigned int);
extern void uart_put_string(unsigned int);
extern unsigned int timer_get_ticks(void);
extern void hdr_dump_hdr10plus_metadata(void);

/* The service runs only while this register reads HDR_SERVICE_GATE_VALUE (hdr_update_hdr10plus_metadata tests the same). */
#define HDR_SERVICE_GATE_REG   0xcf03c80c
#define HDR_SERVICE_GATE_VALUE 0x99
/* Result register for the main processor: source number << 16 | result byte. 0xff is the "not loaded" result of
   the HDR10+ update; the other two bytes are written by this routine only and their meaning is not shown. */
#define HDR10PLUS_RESULT_REG        0xd0013ffc
#define HDR10PLUS_RESULT_NOT_LOADED 0xff
#define HDR_RESULT_55               0x55
#define HDR_RESULT_DD               0xdd
/* Values of hdr_status_code written by this routine (the status the main processor can read back). */
#define HDR_STATUS_OFF        0  /* tone mapping switched off for this source */
#define HDR_STATUS_EOTF_LOW   1  /* tone mapping off: EOTF type of the metadata is 0 or 1 */
#define HDR_STATUS_CURVE      2  /* hdr_update_tone_curve returned non-zero */
#define HDR_STATUS_SECOND_SET 4  /* second tone-mapping set switched on after the metadata timeout check */

/*
 * One step of the HDR curve service. Takes and returns nothing. It does nothing unless the gate register reads
 * 0x99. Order of decisions:
 *  1. hdr_mark_source_active (marks the source, or clears the mark).
 *  2. Source switched off in hdr_source_disable_bits: switch tone mapping off, status 0, report "not loaded" with the
 *     source number, and stop (the final steps below are skipped).
 *  3. hdr_check_metadata_timeout reports 1: switch the second tone-mapping set on, status 4, go to the final steps.
 *  4. Ask whether the source reports HDR (hdr_is_source_hdr_active). If it does: hdr_task_byte = 1, read its
 *     metadata (hdr_read_source_metadata), stamp the time in hdr_last_update_ticks, acknowledge DisplayPort
 *     metadata. If not: hdr_task_byte = 0.
 *  5. HDR active: only when the metadata changed (hdr_has_metadata_changed) go on, otherwise to the final steps.
 *     - EOTF type above 1: hdr_update_tone_curve. Non-zero: result 0x55, status 2, two debug prints. Zero: debug
 *       print and hdr_settings_changed_flag = 1 (the curve is retried on the next step).
 *     - EOTF type 0 or 1: tone mapping off, status 1, result 0xdd.
 *  6. HDR not active: if bit 0 of hdr_option_byte is set, apply the loaded curve when bit 1 is also set (see
 *     hdr_apply_tone_curve); otherwise, when hdr_is_update_due (more than 200 ticks since the last stamp), switch
 *     tone mapping off, status 0, result "not loaded".
 *  7. Final steps: when hdr_mode_byte is 1, update the smoothed level; print the static state; and tail-call
 *     hdr_dump_hdr10plus_metadata.
 */
void hdr_task(void)
{
  int hdr_active, changed;

  if (*(volatile unsigned int *)HDR_SERVICE_GATE_REG != HDR_SERVICE_GATE_VALUE)
    return;
  hdr_mark_source_active();
  if ((hdr_source_disable_bits >> hdr_source) & 1) {
    hdr_tmo_disable_and_print();
    hdr_status_code = HDR_STATUS_OFF;
    reg_write32(HDR10PLUS_RESULT_REG, (hdr_source << 16) | HDR10PLUS_RESULT_NOT_LOADED);
    return;
  }
  if ((hdr_check_metadata_timeout() & 0xff) == 1) {
    hdr_tmo_enable_second();
    hdr_status_code = HDR_STATUS_SECOND_SET;
    goto out;
  }
  hdr_active = hdr_is_source_hdr_active() & 0xff;
  if (hdr_active == 1) {
    hdr_task_byte = hdr_active;
    hdr_read_source_metadata();
    hdr_last_update_ticks = timer_get_ticks();
    hdr_ack_dp_metadata();
  } else {
    hdr_task_byte = 0;
  }
  if (hdr_task_byte == 1) {
    changed = hdr_has_metadata_changed() & 0xff;
    if (changed != 1)
      goto out;
    if (hdr_static_info_eotf_type > 1) {
      if ((hdr_update_tone_curve() & 0xff) != 0) {
        reg_write32(HDR10PLUS_RESULT_REG, (hdr_source << 16) | HDR_RESULT_55);
        hdr_status_code = HDR_STATUS_CURVE;
        dbg_printf(0x9f1c6458, 2);
        uart_put_string(0x9f1cca78);
      } else {
        dbg_printf(0x9f1c6438, hdr_status_code);
        hdr_settings_changed_flag = changed;
      }
      goto out;
    }
    hdr_tmo_disable_and_print();
    hdr_tmo_disable();
    hdr_status_code = changed;
    dbg_printf(0x9f1c6480, 1);
    reg_write32(HDR10PLUS_RESULT_REG, (hdr_source << 16) | HDR_RESULT_DD);
  } else {
    if (hdr_option_byte & 1) {
      if (hdr_option_byte & 2)
        hdr_apply_tone_curve();
      goto out;
    }
    if ((hdr_is_update_due() & 0xff) != 0) {
      hdr_tmo_disable_and_print();
      hdr_tmo_disable();
      hdr_status_code = HDR_STATUS_OFF;
      reg_write32(HDR10PLUS_RESULT_REG, (hdr_source << 16) | HDR10PLUS_RESULT_NOT_LOADED);
    }
  }
out:
  if (hdr_mode_byte == 1)
    hdr_update_smoothed_level();
  hdr_print_static_state();
  hdr_dump_hdr10plus_metadata();
}

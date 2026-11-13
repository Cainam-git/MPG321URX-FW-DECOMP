/* hdmi_tx_ddc_reset  (FUN_a00c7bf8)
 *
 * Reset the DDC master of an HDMI output until its status reads idle.
 * Name basis: derived - up to five tries per step
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00c7bf8 @ 0xa00c7bf8-0xa00c7ccc (53 words), flags -mcpu=v8 -Os -g (section default).
 * Source forms the exact build depends on:
 *  - both loops are 'do { ...; count++; if (status bits set && count <= 4) continue; break; } while (1)' with
 *    an unsigned int count compared as a byte (firmware 'btst; be exit');
 *  - the result is an unsigned char returned as result & 0xf;
 *  - hdmi_tx_reg_read8 and timer_delay_long_units are reached through calls linked 0xF10000 above their
 *    addresses (FUN_a0fb7fd8 = 0xa00a7fd8 + 0xF10000, FUN_a0fc1794 = 0xa00b1794 + 0xF10000), as in the other
 *    callers in 0xa00c0000-0xa00df000; the two local defines below name them.
 */
#define hdmi_tx_reg_read8             FUN_a0fb7fd8      /* hdmi_tx_reg_read8 (hdmi_tx_reg_read8) */
#define timer_delay_long_units        FUN_a0fc1794      /* timer_delay_long_units (timer_delay_long_units) */

/* Bank 0 registers of the HDMI transmitter used by the DDC reset. */
#define HDMI_TX_BANK_0       0
#define DDC_STATUS_F2        0xf2
#define DDC_STATUS_F2_BUSY   0x10       /* bit 4 */
#define DDC_STATUS_F5        0xf5
#define DDC_STATUS_F5_BUSY   0x1f       /* bits 0..4 */

#define DDC_RESET_LAST_TRY   4          /* tries are counted from 1: at most five per step */

/* Results. */
#define DDC_RESET_OK         0
#define DDC_RESET_F2_BUSY    0xe        /* register 0xF2 bit 4 still set at the end */
#define DDC_RESET_F5_BUSY    0xf        /* register 0xF5 bits 0..4 still set at the end */

extern void hdmi_tx_ddc_reset_step_first(unsigned int);
extern void hdmi_tx_ddc_reset_step_second(unsigned int);
extern void hdmi_tx_ddc_reset_step_third(unsigned int);
extern int hdmi_tx_reg_read8(unsigned int, unsigned int, unsigned int);
extern void timer_delay_long_units(unsigned int);

/*
 * Bring the DDC master of HDMI output `port` to idle. Each step routine rewrites the low nibble of DDC control
 * register 0xF3: step_first sets it to 0xF, step_second to 9, step_third to 0xA.
 *
 *   1. step_first, then read register 0xF2; again while bit 4 is set, at most five times.
 *   2. step_second, then read register 0xF5; again while any of bits 0..4 is set, at most five times.
 *   3. step_third, one wait unit (timer_delay_long_units(1)), then read both status registers once more.
 *
 * Returns DDC_RESET_F2_BUSY (0xE) when register 0xF2 bit 4 is still set, else DDC_RESET_F5_BUSY (0xF) when
 * register 0xF5 bits 0..4 are not all clear, else 0. hdmi_tx_scdc_write writes nothing on a non-zero result.
 */
unsigned int hdmi_tx_ddc_reset(unsigned char port)
{
  unsigned char result;
  unsigned int tries;
  unsigned int status;

  result = DDC_RESET_OK;
  tries = 0;
  port &= 0xff;

  do {
    hdmi_tx_ddc_reset_step_first(port);
    status = hdmi_tx_reg_read8(port, HDMI_TX_BANK_0, DDC_STATUS_F2);
    tries++;
    if ((status & DDC_STATUS_F2_BUSY) != 0 && (tries & 0xff) <= DDC_RESET_LAST_TRY) {
      continue;
    }
    break;
  } while (1);

  tries = 0;
  do {
    hdmi_tx_ddc_reset_step_second(port);
    status = hdmi_tx_reg_read8(port, HDMI_TX_BANK_0, DDC_STATUS_F5);
    tries++;
    if ((status & DDC_STATUS_F5_BUSY) != 0 && (tries & 0xff) <= DDC_RESET_LAST_TRY) {
      continue;
    }
    break;
  } while (1);

  hdmi_tx_ddc_reset_step_third(port);
  timer_delay_long_units(1);
  status = hdmi_tx_reg_read8(port, HDMI_TX_BANK_0, DDC_STATUS_F2);
  if ((status & DDC_STATUS_F2_BUSY) != 0) {
    result = DDC_RESET_F2_BUSY;
  } else {
    status = hdmi_tx_reg_read8(port, HDMI_TX_BANK_0, DDC_STATUS_F5);
    if ((status & DDC_STATUS_F5_BUSY) != 0) {
      result = DDC_RESET_F5_BUSY;
    }
  }
  return result & 0xf;
}

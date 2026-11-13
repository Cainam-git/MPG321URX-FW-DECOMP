/* pq_detect_ch1_input_change  (FUN_a0084330)
 *
 * Detect a change of channel 1's measured input size and refresh its window.
 *   reset: non-zero = forget the last state
 * Note: A change is a ratio step above 5 or more than 10 jitter hits.
 * Name basis: derived - header: change detector; calls pq_update_input_window(1)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0084330 @ 0xa0084330-0xa00844f8 (114 words), flags -mcpu=v8 -O3 -g.
 * Source form: changed is set by an if / else (the firmware's 'bg; mov 1' + 'clr'); abs() gives sra / xor / sub;
 * the pq_update_input_window(1) call is written in BOTH arms of 'if (changed == 1)' (one common call before the if
 * gives other code).
 */

#define TIMING_FIELD_7 7        /* input record field id 7: horizontal size; read and dropped here */

#define RATIO_STEP     5        /* a ratio change above this (0.5, ratio in tenths) counts as a size change */
#define VALUE_JITTER   0x14     /* third-value shift that counts as a change */
#define WIDTH_JITTER   0xf      /* width shift that counts as a change */
#define CHANGE_HITS    10       /* calls the values may stay moved before the window is refreshed */
#define CHANNEL_1      1
#define CHANNEL_TIMEOUT 500     /* time value for sys_api_set_channel_timeout (channel record halfword +0x74) */

extern unsigned short pq_ch1_measured_height, pq_ch1_measured_width, pq_ch1_measured_fourth_value, pq_ch1_measured_third_value;
extern unsigned char pq_ch1_change_flag;
extern unsigned short pq_ch1_last_ratio, pq_ch1_last_third_value, pq_ch1_last_width;
extern unsigned char pq_ch1_change_count;
extern int input_api_get_timing_field(int, int);
extern unsigned char input_measure_picture_size(int, unsigned short *, unsigned short *, unsigned short *, unsigned short *);
extern void pq_update_input_window(int);
extern void sys_user_rebuild_window_channel1(void);
extern void sys_api_set_channel_timeout(int, int, int);
extern int abs(int);

/*
 * Watch channel 1's measured picture size and refresh its input window when it changes.
 *
 *   reset  non-zero: set the stored flag to 0xFF and the stored ratio to 0, and return.
 *
 * Nothing is done when input_measure_picture_size returns 0. Otherwise 'changed' is 1 when the ratio
 * 10 * width / height moved by more than RATIO_STEP since the last call. The count goes up on every call on
 * which the third value differs from the last settled one by more than VALUE_JITTER or the width by more than
 * WIDTH_JITTER; on a quiet call the values are settled and the count cleared.
 *
 * The input window of channel 1 is recomputed (pq_update_input_window) when 'changed' differs from its value on
 * the last call (so also on the first call after a reset, and on the call after a ratio step) or the count is
 * above CHANGE_HITS. When 'changed' is 1 the window is also rebuilt (sys_user_rebuild_window_channel1) and
 * sys_api_set_channel_timeout(1, 1, 500) sets channel 1's flag bit 16 and time value. Each refresh settles the
 * values and clears the count.
 *
 * Callers: APPActionDispatcher, sys_run_app_timer_task.
 */
void pq_detect_ch1_input_change(unsigned char reset)
{
  unsigned short ratio;
  unsigned char changed;

  if (reset) {
    pq_ch1_change_flag = 0xff;
    pq_ch1_last_ratio = 0;
    return;
  }
  input_api_get_timing_field(CHANNEL_1, TIMING_FIELD_7);
  if (!input_measure_picture_size(CHANNEL_1, &pq_ch1_measured_width, &pq_ch1_measured_height, &pq_ch1_measured_third_value, &pq_ch1_measured_fourth_value))
    return;
  /* The picture's width-to-height ratio in tenths. */
  ratio = pq_ch1_measured_width * 10 / pq_ch1_measured_height;
  if (abs(pq_ch1_last_ratio - ratio) > RATIO_STEP)
    changed = 1;
  else
    changed = 0;
  /* Count the calls on which the values stay moved; settle on them on a quiet call. */
  if (abs(pq_ch1_last_third_value - pq_ch1_measured_third_value) > VALUE_JITTER || abs(pq_ch1_last_width - pq_ch1_measured_width) > WIDTH_JITTER) {
    pq_ch1_change_count++;
  } else {
    pq_ch1_last_width = pq_ch1_measured_width;
    pq_ch1_last_third_value = pq_ch1_measured_third_value;
    pq_ch1_change_count = 0;
  }
  /* 'changed' flipped since the last call, or the values stayed moved for too many calls. */
  if (pq_ch1_change_flag != changed || pq_ch1_change_count > CHANGE_HITS) {
    if (changed == 1) {
      pq_update_input_window(CHANNEL_1);
      sys_user_rebuild_window_channel1();
      sys_api_set_channel_timeout(CHANNEL_1, 1, CHANNEL_TIMEOUT);
    } else {
      pq_update_input_window(CHANNEL_1);
    }
    pq_ch1_last_third_value = pq_ch1_measured_third_value;
    pq_ch1_last_width = pq_ch1_measured_width;
    pq_ch1_change_count = 0;
  }
  pq_ch1_last_ratio = ratio;
  pq_ch1_change_flag = changed;
}

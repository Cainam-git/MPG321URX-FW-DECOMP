/* pq_match_ch1_timing_table  (FUN_a0082ec4)
 *
 * Match channel 1's input size against a 12-entry table and return four window values.
 *   start_x: out
 *   start_y: out
 *   width_out: out
 *   height_out: out
 * Note: Table of 18-byte records at ROM 0xFEB30; outputs unchanged when nothing matches.
 * Name basis: descriptive - code only; inlined in pq_update_input_window
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0082ec4 @ 0xa0082ec4-0xa00830f4 (140 words), flags -mcpu=v8 -O3 -g.
 * Source form: the distances are kept in a variable distance (a direct abs(..) <= 10 test is folded into a range
 * test); the found flag is tested as 'found == 1' (a plain 'if (found)' places the width_equal == 0 block
 * before the other blocks).
 */
struct ch1_size_row {
    unsigned short width;               /* compared with timing field 7 */
    unsigned short height;              /* compared with timing field 8 */
    unsigned short word_0x4;
    unsigned short height_out;          /* +6: the height taken over on a match */
    unsigned short rest[5];
};

/* Fields of the measured input timing (input_api_get_timing_field). */
enum {
    TIMING_WIDTH  = 7,
    TIMING_HEIGHT = 8
};

#define CH1_SIZE_ROWS       12
#define CH1_SIZE_TOLERANCE  10          /* a row matches when width and height are both within 10 */

extern unsigned short pq_ch1_measured_height, pq_ch1_measured_width, pq_ch1_measured_fourth_value, pq_ch1_measured_third_value;
extern const struct ch1_size_row pq_ch1_timing_table[];
extern unsigned short input_api_get_timing_field(unsigned char, unsigned int);
extern int abs(int);

/*
 * Look up channel 1's input size (timing fields 7 and 8) in the 12-row ROM table and write a window.
 *
 * The timing width is "equal" to pq_ch1_measured_width when they differ by at most width / 6, the timing height
 * "equal" to pq_ch1_measured_height when they differ by at most height / 6. A row matches when its width and
 * height are both within 10 of the timing values; the first match is used. Nothing is written when no row
 * matches, and nothing when width and height are both equal. Otherwise:
 *   width not equal:              width_out = measured width + 8, start_x = third value - 8,
 *                                 height_out = the row's height_out (start_y is not written);
 *   width equal, height not, and measured width > pq_ch1_measured_height:
 *                                 width_out = measured width + 8, start_x = third value,
 *                                 height_out = the row's height_out, start_y = 0;
 *   width equal, height not, otherwise:
 *                                 width_out = measured width, start_x = third value,
 *                                 height_out = pq_ch1_measured_height, start_y = fourth value.
 *
 * No call to this address was found: the same body is inlined as a static copy in pq_update_input_window.
 */
void pq_match_ch1_timing_table(unsigned short *start_x, unsigned short *start_y, unsigned short *width_out, unsigned short *height_out)
{
  unsigned short width, height, width_tolerance, height_tolerance;
  unsigned char found, width_equal, height_equal, i;
  int distance;

  width = input_api_get_timing_field(1, TIMING_WIDTH);
  height = input_api_get_timing_field(1, TIMING_HEIGHT);
  found = 0;
  width_tolerance = width / 6;
  if (abs(width - pq_ch1_measured_width) > width_tolerance)
    width_equal = 0;
  else
    width_equal = 1;
  height_tolerance = height / 6;
  if (abs(height - pq_ch1_measured_height) > height_tolerance)
    height_equal = 0;
  else
    height_equal = 1;
  for (i = 0; i < CH1_SIZE_ROWS; i++) {
    distance = abs(width - pq_ch1_timing_table[i].width);
    if (distance > CH1_SIZE_TOLERANCE)
      continue;
    distance = abs(height - pq_ch1_timing_table[i].height);
    if (distance > CH1_SIZE_TOLERANCE)
      continue;
    found = 1;
    break;
  }
  if (found == 1) {
    if (width_equal == 0) {
      *width_out = pq_ch1_measured_width + 8;
      *start_x = pq_ch1_measured_third_value - 8;
      *height_out = pq_ch1_timing_table[i].height_out;
    } else if (width_equal == 1 && height_equal == 0) {
      if (pq_ch1_measured_width > pq_ch1_measured_height) {
        *width_out = pq_ch1_measured_width + 8;
        *start_x = pq_ch1_measured_third_value;
        *height_out = pq_ch1_timing_table[i].height_out;
        *start_y = 0;
      } else {
        *width_out = pq_ch1_measured_width;
        *start_x = pq_ch1_measured_third_value;
        *height_out = pq_ch1_measured_height;
        *start_y = pq_ch1_measured_fourth_value;
      }
    }
  }
}

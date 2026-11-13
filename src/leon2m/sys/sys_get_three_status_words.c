/* sys_get_three_status_words  (FUN_a00f9500)
 *
 * Fetch the three stored result words into the caller's variables.
 * Name basis: descriptive - words at 0xA802B7BC..C4, written by the sample accumulation
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f9500 @ 0xa00f9500, flags -mcpu=v8 -O3 -g.
 * Source form: three plain loads and stores through the pointers, in the order of the stores below.
 */
extern unsigned int input_block_sample_average1;
extern unsigned int input_block_sample_average2;
extern unsigned int input_block_sample_average3;

/*
 * Copy the three stored sample averages into the caller's variables. Note the order: the third average goes to
 * *first, the first average to *third.
 *
 * Called by sys_api_get_three_status_words (sys_api_get_three_status_words), which only passes the pointers on.
 */
void sys_get_three_status_words(unsigned int *first, unsigned int *second, unsigned int *third)
{
  *first = input_block_sample_average3;
  *second = input_block_sample_average2;
  *third = input_block_sample_average1;
}

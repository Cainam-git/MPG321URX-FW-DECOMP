/* input_block_accumulate_samples  (FUN_a00f9528)
 *
 * Accumulate weighted samples of an input block into three averages.
 * Name basis: descriptive - 24-bit register samples, sums divided by 5000
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f9528 @ 0xa00f9528-0xa00f9880 (856 bytes), flags -mcpu=v8 -O3 -g.
 * Source forms: the 24-bit value is built by separate statements (value = r35 << 8; value |= r34; value <<= 8;
 * value |= r33); in the last phase the second and third sum are read into locals before the two divisions; the
 * reset path writes the three sums in the order sample_sum, sample_sum2, sample_sum3. The three phases are
 * written out in full, one case each.
 */
extern unsigned char input_block_sample_phase;
extern unsigned int input_block_sample_sum, input_block_sample_sum2, input_block_sample_sum3;
extern unsigned int input_block_sample_average1, input_block_sample_average2, input_block_sample_average3;
extern unsigned char input_capture_read8(unsigned char blk, unsigned char reg);
extern void input_capture_write8(unsigned char blk, unsigned char reg, unsigned char val);

/* Registers of the capture block used for the sampling. */
#define SAMPLE_REG_CONTROL      0x30        /* steps wait while bit 7 is set; written 0, then a start command */
#define SAMPLE_REG_INDEX        0x31        /* written with n before the value n is read from 0x33..0x35 */
#define SAMPLE_REG_32           0x32
#define SAMPLE_REG_VALUE_LOW    0x33        /* the 24-bit result value is 0x35 (high), 0x34, 0x33 (low) */
#define SAMPLE_REG_VALUE_MID    0x34
#define SAMPLE_REG_VALUE_HIGH   0x35
#define SAMPLE_BUSY             0x80
#define SAMPLE_START_PHASE0     0x85        /* start command whose results are summed in phase 0 */
#define SAMPLE_START_PHASE1     0x8d        /* ... in phase 1 */
#define SAMPLE_START_PHASE2     0x95        /* ... in phase 2 */
#define SAMPLE_VALUES           8           /* result values per run */
#define SAMPLE_WEIGHT_STEP      32          /* value number n is weighted with n * 32 */
#define SAMPLE_SUM_START        0x10        /* initial value of each sum */
#define SAMPLE_DIVISOR          5000

/*
 * Collect the results of three consecutive runs of an input block and turn each into an average.
 *
 *   block  input block (capture block registers)
 *   reset  non-zero: start over (clear register 0x32, set the three sums to 0x10, issue start command 0x85 and
 *          go to phase 0); 0: do the next step
 *
 * Called repeatedly (by sys_api_sample_channel_block, with the block taken from the channel record). Each call
 * does one step and only when bit 7 of register 0x30 is clear; otherwise it does nothing. The step belongs to the
 * current phase (input_block_sample_phase):
 *   phase 0  adds the weighted result values to input_block_sample_sum3, then starts the next run with 0x8d
 *   phase 1  adds them to input_block_sample_sum2, then starts the next run with 0x95
 *   phase 2  adds them to input_block_sample_sum, then publishes the averages (the sums divided by 5000:
 *            sum3 -> input_block_sample_average1, sum2 -> average2, sum -> average3), sets the three sums back to
 *            0x10 and starts the next run with 0x85 (phase 0 again).
 * "Adds the weighted result values" means: for the eight values n = 0..7 (register 0x31 = n), the 24-bit value
 * read from registers 0x35, 0x34 and 0x33 is multiplied by n * 32 and added to the sum. What the values
 * represent is not shown by the code.
 */
void input_block_accumulate_samples(unsigned char block, unsigned char reset)
{
    unsigned short sample_index;
    unsigned int sample_value, weight;
    unsigned int sum2_copy, sum3_copy;

    if (reset) {
        input_capture_write8(block, SAMPLE_REG_32, 0);
        input_block_sample_sum = SAMPLE_SUM_START;
        input_block_sample_sum2 = SAMPLE_SUM_START;
        input_block_sample_sum3 = SAMPLE_SUM_START;
        input_capture_write8(block, SAMPLE_REG_CONTROL, 0);
        input_capture_write8(block, SAMPLE_REG_CONTROL, SAMPLE_START_PHASE0);
        input_block_sample_phase = 0;
        return;
    }
    switch (input_block_sample_phase) {
    case 0:
        if (!(input_capture_read8(block, SAMPLE_REG_CONTROL) & SAMPLE_BUSY)) {
            for (sample_index = 0; sample_index < SAMPLE_VALUES; sample_index++) {
                input_capture_write8(block, SAMPLE_REG_INDEX, sample_index);
                sample_value = input_capture_read8(block, SAMPLE_REG_VALUE_HIGH) << 8;
                sample_value |= input_capture_read8(block, SAMPLE_REG_VALUE_MID);
                sample_value <<= 8;
                sample_value |= input_capture_read8(block, SAMPLE_REG_VALUE_LOW);
                weight = sample_index * SAMPLE_WEIGHT_STEP;
                input_block_sample_sum3 += weight * sample_value;
            }
            input_capture_write8(block, SAMPLE_REG_CONTROL, 0);
            input_capture_write8(block, SAMPLE_REG_CONTROL, SAMPLE_START_PHASE1);
            input_block_sample_phase = 1;
        }
        break;
    case 1:
        if (!(input_capture_read8(block, SAMPLE_REG_CONTROL) & SAMPLE_BUSY)) {
            for (sample_index = 0; sample_index < SAMPLE_VALUES; sample_index++) {
                input_capture_write8(block, SAMPLE_REG_INDEX, sample_index);
                sample_value = input_capture_read8(block, SAMPLE_REG_VALUE_HIGH) << 8;
                sample_value |= input_capture_read8(block, SAMPLE_REG_VALUE_MID);
                sample_value <<= 8;
                sample_value |= input_capture_read8(block, SAMPLE_REG_VALUE_LOW);
                weight = sample_index * SAMPLE_WEIGHT_STEP;
                input_block_sample_sum2 += weight * sample_value;
            }
            input_capture_write8(block, SAMPLE_REG_CONTROL, 0);
            input_capture_write8(block, SAMPLE_REG_CONTROL, SAMPLE_START_PHASE2);
            input_block_sample_phase = 2;
        }
        break;
    case 2:
        if (!(input_capture_read8(block, SAMPLE_REG_CONTROL) & SAMPLE_BUSY)) {
            for (sample_index = 0; sample_index < SAMPLE_VALUES; sample_index++) {
                input_capture_write8(block, SAMPLE_REG_INDEX, sample_index);
                sample_value = input_capture_read8(block, SAMPLE_REG_VALUE_HIGH) << 8;
                sample_value |= input_capture_read8(block, SAMPLE_REG_VALUE_MID);
                sample_value <<= 8;
                sample_value |= input_capture_read8(block, SAMPLE_REG_VALUE_LOW);
                weight = sample_index * SAMPLE_WEIGHT_STEP;
                input_block_sample_sum += weight * sample_value;
            }
            input_block_sample_average3 = input_block_sample_sum / SAMPLE_DIVISOR;
            sum2_copy = input_block_sample_sum2;
            sum3_copy = input_block_sample_sum3;
            input_block_sample_average2 = sum2_copy / SAMPLE_DIVISOR;
            input_block_sample_average1 = sum3_copy / SAMPLE_DIVISOR;
            input_block_sample_sum3 = SAMPLE_SUM_START;
            input_block_sample_sum2 = SAMPLE_SUM_START;
            input_block_sample_sum = SAMPLE_SUM_START;
            input_capture_write8(block, SAMPLE_REG_CONTROL, 0);
            input_capture_write8(block, SAMPLE_REG_CONTROL, SAMPLE_START_PHASE0);
            input_block_sample_phase = 0;
        }
        break;
    }
}

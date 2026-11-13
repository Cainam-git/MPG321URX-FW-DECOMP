/* pq_block_read_reg89_pair_average  (FUN_a01042c8)
 *
 * Read register 0x89 of a picture block in pairs one frame apart; return the average of the last pair.
 *   blk: picture block
 *   rate: refresh rate handed to timer_wait_frames
 * Returns: (first + second) / 2 of the last pair read
 * Note: A new pair is read while the two reads lie within 15 of each other, at most three more times; nothing
 *   calls it.
 * Name basis: descriptive - two pq_block_read24_stable reads with timer_wait_frames(1) in between, repeated
 *   while they differ by 15 or less; no reference in the image
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01042c8 @ 0xa01042c8-0xa0104380 (46 words), flags -mcpu=v8 -O2 -g (the section default; -O3 -g
 * gives the same bytes).
 * Source form: the loop condition compares (int)(first - second) against -CLOSE_DIFF and CLOSE_DIFF in that
 * order, then tests retry < MAX_RETRIES.
 */
extern unsigned int pq_block_read24_stable(unsigned char blk, unsigned char reg);
extern void timer_wait_frames(unsigned char frames, unsigned short rate);

#define BLK_COUNT 0x89          /* picture block register: 24-bit count */
#define WAIT_FRAMES 1           /* one frame period between reads */
#define CLOSE_DIFF 15           /* the loop goes on while the two reads differ by -15..15 */
#define MAX_RETRIES 3           /* at most three more pairs */

/*
 * Read the 24-bit count register BLK_COUNT (0x89) of a picture block twice, one frame period apart
 * (timer_wait_frames(1, rate)), and return the average of the last two reads, rounded down.
 *
 *   blk   picture block, passed to pq_block_read24_stable
 *   rate  refresh rate passed to timer_wait_frames
 *
 * The loop reads a new pair while the reads of the last pair lie within CLOSE_DIFF of each other, at most
 * MAX_RETRIES times: it stops at the first pair that differs by more than 15, or after four pairs.
 *
 * Nothing calls this routine.
 */
unsigned int pq_block_read_reg89_pair_average(unsigned char blk, unsigned short rate)
{
    unsigned int first, second;
    unsigned char retry;

    first = pq_block_read24_stable(blk, BLK_COUNT);
    timer_wait_frames(WAIT_FRAMES, rate);
    second = pq_block_read24_stable(blk, BLK_COUNT);
    for (retry = 0; (int)(first - second) >= -CLOSE_DIFF && (int)(first - second) <= CLOSE_DIFF && retry < MAX_RETRIES; retry++) {
        first = pq_block_read24_stable(blk, BLK_COUNT);
        timer_wait_frames(WAIT_FRAMES, rate);
        second = pq_block_read24_stable(blk, BLK_COUNT);
    }
    return (first + second) >> 1;
}

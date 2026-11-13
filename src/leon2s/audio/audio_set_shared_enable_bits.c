/* audio_set_shared_enable_bits  (FUN_a008a238)
 *
 * Set enable bits 4..7 of a shared audio register under the hardware lock.
 *   sel: 0..3 one bit, 4 all
 * Name basis: descriptive - bits of 0xCF012444 written between take and release of semaphore 0xCF03C840
 *
 * Matching notes
 * --------------
 * FUN_a008a238 (leon2s 0xa008a238-0xa008a470, 568 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on: the lock take is an inline helper; each case releases the lock
 * itself (GCC shares the store tail).
 */
/* Lock register shared between the two processors: this program claims it by writing 2. */
#define SHARED_LOCK (*(volatile unsigned int *)0xcf03c840)
#define LOCK_FREE      0
#define LOCK_BUSY      1        /* held by the other processor */
#define LOCK_HELD_HERE 2
#define AUDIO_SHARED_ENABLE_REG (*(volatile unsigned int *)0xcf012444)   /* bit 4 + unit = that unit's enable bit */

/*
 * Take the shared lock: write 2 whenever the register does not read 1, until it reads 2, at most 65536 tries.
 * After the last try the lock is claimed anyway (2 is written again).
 */
static inline void shared_lock_take(void)
{
    unsigned short tries = 0xffff;

    do {
        if (SHARED_LOCK != LOCK_BUSY)
            SHARED_LOCK = LOCK_HELD_HERE;
        if (SHARED_LOCK == LOCK_HELD_HERE)
            break;
        tries--;
    } while (tries != 0xffff);
    SHARED_LOCK = LOCK_HELD_HERE;
}

/*
 * Set enable bits of the audio register 0xcf012444 that the other processor also uses, while holding the shared
 * lock; the bit is set with a read-modify-write and the lock is released (written 0) afterwards.
 *   sel: 0..3 sets the enable bit of audio unit sel (bit 4 + sel); 4 sets all four (bits 4..7).
 *        Any other value does nothing.
 */
void audio_set_shared_enable_bits(unsigned char sel)
{
    switch (sel) {
    case 0:
        shared_lock_take();
        AUDIO_SHARED_ENABLE_REG |= 0x10;
        SHARED_LOCK = LOCK_FREE;
        break;
    case 1:
        shared_lock_take();
        AUDIO_SHARED_ENABLE_REG |= 0x20;
        SHARED_LOCK = LOCK_FREE;
        break;
    case 2:
        shared_lock_take();
        AUDIO_SHARED_ENABLE_REG |= 0x40;
        SHARED_LOCK = LOCK_FREE;
        break;
    case 3:
        shared_lock_take();
        AUDIO_SHARED_ENABLE_REG |= 0x80;
        SHARED_LOCK = LOCK_FREE;
        break;
    case 4:
        shared_lock_take();
        AUDIO_SHARED_ENABLE_REG |= 0xf0;
        SHARED_LOCK = LOCK_FREE;
        break;
    }
}

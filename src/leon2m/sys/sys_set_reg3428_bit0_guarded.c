/* sys_set_reg3428_bit0_guarded  (FUN_a0113810)
 *
 * Set or clear bit 0 of register 0xCF013428 inside the guard sequence.
 * Name basis: descriptive - wait / set / clear sequence on 0xCF03C840; unused
 *
 * Matching notes
 * --------------
 * FUN_a0113810 (leon2m 0xa0113810-0xa01138fc, 236 bytes), flags -mcpu=v8 -O3 -g.
 * Source form: two static helpers (the wait loop with a do/while (t--) unsigned short counter, and the final
 * write of 0) inlined in both arms.
 */
#define SHARED_LOCK (*(volatile unsigned int *)0xcf03c840)  /* lock register shared between the two processors */
#define LOCK_FREE        0
#define LOCK_HELD_HERE   1
#define LOCK_HELD_OTHER  2
#define REG_3428 (*(volatile unsigned int *)0xcf013428)

/* Try to take the lock: write HELD_HERE unless the register reads HELD_OTHER; give up after 0x10000 rounds. */
static void acquire_shared_lock(void)
{
    unsigned short tries = 0xffff;
    do {
        if (SHARED_LOCK != LOCK_HELD_OTHER)
            SHARED_LOCK = LOCK_HELD_HERE;
        if (SHARED_LOCK == LOCK_HELD_HERE)
            break;
    } while (tries--);
    SHARED_LOCK = LOCK_HELD_HERE;   /* written whether or not the lock was won */
}
static void release_shared_lock(void)
{
    SHARED_LOCK = LOCK_FREE;
}

/*
 * Set (on non-zero) or clear (on 0) bit 0 of register 0xCF013428 while holding the shared lock.
 * The lock is taken as described at acquire_shared_lock and released by writing 0 afterwards.
 */
void sys_set_reg3428_bit0_guarded(unsigned char on)
{
    if (on) {
        acquire_shared_lock();
        REG_3428 |= 1;
        release_shared_lock();
    } else {
        acquire_shared_lock();
        REG_3428 &= ~1u;
        release_shared_lock();
    }
}

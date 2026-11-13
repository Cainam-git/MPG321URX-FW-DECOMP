/* hdmi_tx_set_frl_clock  (FUN_a008e958)
 *
 * Select the FRL link clock (3 to 12 GHz) of an HDMI TX port.
 *   port: HDMI TX port (0 or 1)
 *   rate: FRL rate 1..6
 * Name basis: proven - prints 'FRL CLK 3GHz' .. 'FRL CLK 12GHz' for rate 1..6 and writes the clock code into
 *   the port's nibble of 0xCF014748; before that the port's bit of 0xCF01477C is cleared under the shared lock
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008e958 @ 0xa008e958-0xa008ecb8 (216 words, leaf), flags -mcpu=v8 -Os -g (section default).
 * Source forms the exact build depends on:
 *  - the lock take is a static inline helper (shared_lock_take, the same loop as in audio_set_shared_enable_bits);
 *  - the lock release is written in each arm of the port test (the arms share the address register);
 *  - the rate dispatch is a switch (a jump table in the firmware) whose arms each clear the port's nibble and
 *    then OR the clock code in, as two register writes.
 */
#define SHARED_LOCK    (*(volatile unsigned int *)0xcf03c840)   /* lock shared with the main processor */
#define LOCK_FREE      0
#define LOCK_BUSY      1        /* held by the other processor */
#define LOCK_HELD_HERE 2

#define CLOCK_REG_4748 (*(volatile unsigned int *)0xcf014748)   /* FRL clock code: bits 0..3 port 0, 4..7 port 1 */
#define CLOCK_REG_4754 (*(volatile unsigned int *)0xcf014754)   /* bits 0..1 port 0, bits 2..3 port 1 */
#define CLOCK_REG_477C (*(volatile unsigned int *)0xcf01477c)   /* bit 5 port 0, bit 6 port 1 */

/* Clock codes written to the port's nibble of CLOCK_REG_4748, named from the printed texts. */
#define FRL_CLOCK_3GHZ  0
#define FRL_CLOCK_6GHZ  1
#define FRL_CLOCK_8GHZ  2
#define FRL_CLOCK_10GHZ 3
#define FRL_CLOCK_12GHZ 4

extern int dbg_print_string(const char *);

/* Take the shared lock: up to 0x10000 tries, each claiming it unless it reads LOCK_BUSY, until it reads
   LOCK_HELD_HERE; then it is claimed once more whatever the outcome. */
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
 * Set the FRL clock of an HDMI TX port for an FRL rate.
 *
 *   port  the HDMI TX port (0 or 1)
 *   rate  FRL rate code 1..6 (frl_rate of the TX channel record)
 *
 * Called by hdmi_tx_run_step in set-up step 6 (TX_STEP_CLOCK_SOURCE_FRL), after the source port and the route
 * bits of the port were cleared.
 *
 * First the port's two bits of CLOCK_REG_4754 are set and, under the shared lock, its bit of CLOCK_REG_477C is
 * cleared. A port other than 0 or 1 gets the bits of port 0 here.
 * Then the rate gives the clock code, which goes into the port's nibble of CLOCK_REG_4748 and is printed:
 * rate 1 = 3 GHz, 2 and 3 = 6 GHz, 4 = 8 GHz, 5 = 10 GHz, 6 = 12 GHz. Another rate, or a port other than
 * 0 or 1, leaves CLOCK_REG_4748 as it is (a rate 1..6 is still printed).
 */
void hdmi_tx_set_frl_clock(unsigned char port, unsigned char rate)
{
    if (port == 0) {
        CLOCK_REG_4754 |= 3;
        shared_lock_take();
        CLOCK_REG_477C &= ~0x20;
        SHARED_LOCK = LOCK_FREE;
    } else if (port == 1) {
        CLOCK_REG_4754 |= 0xc;
        shared_lock_take();
        CLOCK_REG_477C &= ~0x40;
        SHARED_LOCK = LOCK_FREE;
    } else {
        CLOCK_REG_4754 |= 3;
        shared_lock_take();
        CLOCK_REG_477C &= ~0x20;
        SHARED_LOCK = LOCK_FREE;
    }
    switch (rate) {
    case 1:
        dbg_print_string("\x1b[0m\t\t - FRL CLK 3GHz\n");
        /* FRL_CLOCK_3GHZ is 0: clearing the nibble is enough. */
        if (port == 0)
            CLOCK_REG_4748 &= 0xf0;
        else if (port == 1)
            CLOCK_REG_4748 &= 0xf;
        break;
    case 2:
    case 3:
        dbg_print_string("\x1b[0m\t\t - FRL CLK 6GHz\n");
        if (port == 0) {
            CLOCK_REG_4748 &= 0xf0;
            CLOCK_REG_4748 |= FRL_CLOCK_6GHZ;
        } else if (port == 1) {
            CLOCK_REG_4748 &= 0xf;
            CLOCK_REG_4748 |= FRL_CLOCK_6GHZ << 4;
        }
        break;
    case 4:
        dbg_print_string("\x1b[0m\t\t - FRL CLK 8GHz\n");
        if (port == 0) {
            CLOCK_REG_4748 &= 0xf0;
            CLOCK_REG_4748 |= FRL_CLOCK_8GHZ;
        } else if (port == 1) {
            CLOCK_REG_4748 &= 0xf;
            CLOCK_REG_4748 |= FRL_CLOCK_8GHZ << 4;
        }
        break;
    case 5:
        dbg_print_string("\x1b[0m\t\t - FRL CLK 10GHz\n");
        if (port == 0) {
            CLOCK_REG_4748 &= 0xf0;
            CLOCK_REG_4748 |= FRL_CLOCK_10GHZ;
        } else if (port == 1) {
            CLOCK_REG_4748 &= 0xf;
            CLOCK_REG_4748 |= FRL_CLOCK_10GHZ << 4;
        }
        break;
    case 6:
        dbg_print_string("\x1b[0m\t\t - FRL CLK 12GHz\n");
        if (port == 0) {
            CLOCK_REG_4748 &= 0xf0;
            CLOCK_REG_4748 |= FRL_CLOCK_12GHZ;
        } else if (port == 1) {
            CLOCK_REG_4748 &= 0xf;
            CLOCK_REG_4748 |= FRL_CLOCK_12GHZ << 4;
        }
        break;
    }
}

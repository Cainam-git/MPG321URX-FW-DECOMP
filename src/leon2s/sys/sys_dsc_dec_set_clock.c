/* sys_dsc_dec_set_clock  (FUN_a00a4ec4)
 *
 * Switch the DSC decoder clock to its start value, or set it from a pixel clock.
 *   on: 1 = start value
 *   v: clock in MHz
 * Name basis: descriptive - on: sequence under the 0xCF03C840 lock; off: 24-bit value to 0xCF0127C4..CC from
 *   the clock in MHz
 *
 * Matching notes
 * --------------
 * Flags -mcpu=v8 -Os -g.
 * Source form: x * 10 is taken into its own variable (z) before the division, which places the add before the
 * multiply as in the firmware; the register-block word is read as (unsigned char)(w >> 24) & 1; the first
 * clock formula is split into two statements (x = ...; x -= 100).
 */
extern volatile unsigned int *sys_dsc_dec_record0_block;

/* Decoder clock registers; the 24-bit value is split into one byte per register. */
#define CLOCK_REG_24B4   (*(volatile unsigned int *)0xcf0124b4)
#define CLOCK_REG_27C0   (*(volatile unsigned int *)0xcf0127c0)
#define CLOCK_VALUE_LOW  (*(volatile unsigned int *)0xcf0127c4)
#define CLOCK_VALUE_MID  (*(volatile unsigned int *)0xcf0127c8)
#define CLOCK_VALUE_HIGH (*(volatile unsigned int *)0xcf0127cc)
#define CLOCK_REG_477C   (*(volatile unsigned int *)0xcf01477c)

/* Byte shared with the 8051 and used as a lock around the write to 0xcf01477c: this processor writes 2 to
 * take it and 0 to release it, and does not write while it reads 1 (same words as the other leon2s files). */
#define SHARED_LOCK     (*(volatile unsigned int *)0xcf03c840)
#define LOCK_FREE       0
#define LOCK_BUSY       1
#define LOCK_HELD_HERE  2

/* Bit 24 of word 0x58 of the first decoder record's register block selects the clock formula. */
#define BLOCK_WORD_58         (0x58 / 4)
#define BLOCK_58_FORMULA_BIT  1

/*
 * Set the clock of the DSC decoder: either to a fixed start value, or from a pixel clock.
 *   on: 1 = start value. Sets bit 6 of 0xcf0124b4, clears 0xcf0127c0, takes the shared lock (up to 0x10000
 *       tries), sets bit 7 of 0xcf01477c, releases the lock and writes the value 0x190000 to the three clock
 *       value registers (low, mid, high byte = 0, 0, 0x19). v is not used.
 *       0 = from v.
 *   v:  clock in MHz (the caller passes the pixel clock in kHz divided by 1000)
 * With on = 0 the clock value x is: 150000 for v above 400; otherwise v * 250 when bit 24 of word 0x58 of
 * the register block of the first decoder record is set, else v * 333250 / 1000 - 100. The register value is
 * then x * 10 + (x * 2768 / 3) / 1000, written as three bytes.
 * Callers include sys_dsc_dec_load_default_config (on = 1) and sys_dsc_dec_write_config (on = 0).
 */
void sys_dsc_dec_set_clock(unsigned char on, unsigned short v)
{
    unsigned short n;
    unsigned int x;
    unsigned int y;

    if (on) {
        CLOCK_REG_24B4 |= 0x40;
        CLOCK_REG_27C0 = 0;
        n = 0xffff;
        do {
            if (SHARED_LOCK != LOCK_BUSY)
                SHARED_LOCK = LOCK_HELD_HERE;
            if (SHARED_LOCK == LOCK_HELD_HERE)
                break;
        } while (n--);
        SHARED_LOCK = LOCK_HELD_HERE;
        CLOCK_REG_477C |= 0x80;
        SHARED_LOCK = LOCK_FREE;
        CLOCK_VALUE_LOW = 0;
        CLOCK_VALUE_MID = 0;
        CLOCK_VALUE_HIGH = 0x19;
    } else {
        if (v > 400)
            x = 150000;
        else if ((unsigned char)(sys_dsc_dec_record0_block[BLOCK_WORD_58] >> 24) & BLOCK_58_FORMULA_BIT)
            x = v * 250;
        else
        {
            x = (int)(v * 333250) / 1000;
            x -= 100;
        }
        {
            unsigned int z = x * 10;

            y = (unsigned int)(x * 2768) / 3;
            x = z + y / 1000;
        }
        CLOCK_VALUE_LOW = x & 0xff;
        CLOCK_VALUE_MID = (x >> 8) & 0xff;
        CLOCK_VALUE_HIGH = (x >> 16) & 0xff;
    }
}

/* dp_copy_tx_readings_to_rx  (FUN_a00ae3e4)
 *
 * Copy six readings of DP transmitter output 0 into receiver registers 0xCA..0xCF; write 0x7F to 0xD6.
 * Note: Each reading is transmitter register 0x14 after a selector (0xF1, 0xF9, 0xF3, 0xFB, 0xF5, 0xFD) is
 *   written to register 0x13.
 * Name basis: descriptive - six select-and-read steps on transmitter output 0, each stored in a receiver
 *   register of the port
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00ae3e4 @ 0xa00ae3e4-0xa00ae5e4, -mcpu=v8 -Os -g.
 * Source form: the take step is one static inline function (lock_take) used twice (same loop as sys_dsc_dec_set_clock).
 */
extern void dp_tx_reg_write8(unsigned char, unsigned short, unsigned char);
extern unsigned char dp_tx_reg_read8(unsigned int, unsigned short);
extern void dp_reg_write8(unsigned char, unsigned short, unsigned char);

#define SHARED_LOCK    (*(volatile unsigned int *)0xcf03c840)  /* hardware lock: 2 = taken, 0 = free */
#define LOCKED_REG_A   (*(volatile unsigned int *)0xcf00780c)
#define LOCKED_REG_B   (*(volatile unsigned int *)0xcf02d100)

#define LOCK_TAKEN        2
#define LOCK_FREE         0
#define LOCK_TRIES        0xffff
#define LOCKED_REG_A_BITS 0x28        /* bits 3 and 5 */

/* Selector values written to register 0x13 of the transmitter in output 0; register 0x14 then holds the reading. */
#define TX_SELECT_REG   0x13
#define TX_READING_REG  0x14

/* Take the lock: write LOCK_TAKEN while it does not read 1, until it reads LOCK_TAKEN or the tries run out. */
static inline void lock_take(void)
{
    unsigned short tries = LOCK_TRIES;

    do {
        if (SHARED_LOCK != 1)
            SHARED_LOCK = LOCK_TAKEN;
        if (SHARED_LOCK == LOCK_TAKEN)
            break;
    } while (tries--);
    SHARED_LOCK = LOCK_TAKEN;
}

/*
 * Take the hardware lock twice, once to set bits 3 and 5 of 0xCF00780C and once to set bit 0 of 0xCF02D100
 * (each time the lock is released again by writing 0). Then read six values from output 0 of the DP transmitter
 * block (selectors 0xF1, 0xF9, 0xF3, 0xFB, 0xF5, 0xFD) and write them to registers 0xCA to 0xCF of the receiver.
 * The last step writes 0x7F to register 0xD6.
 *   port: DP receiver (0 or 1)
 * Called by dp_port_task while the port's byte 0x11F is 1 and bit 0 of register 0x461 is set; otherwise
 * dp_port_task writes 0x86 to register 0xD6.
 */
void dp_copy_tx_readings_to_rx(unsigned int port)
{
    lock_take();
    LOCKED_REG_A |= LOCKED_REG_A_BITS;
    SHARED_LOCK = LOCK_FREE;
    lock_take();
    LOCKED_REG_B |= 1;
    SHARED_LOCK = LOCK_FREE;
    dp_tx_reg_write8(0, TX_SELECT_REG, 0xf1);
    dp_reg_write8(port, 0xca, dp_tx_reg_read8(0, TX_READING_REG));
    dp_tx_reg_write8(0, TX_SELECT_REG, 0xf9);
    dp_reg_write8(port, 0xcb, dp_tx_reg_read8(0, TX_READING_REG));
    dp_tx_reg_write8(0, TX_SELECT_REG, 0xf3);
    dp_reg_write8(port, 0xcc, dp_tx_reg_read8(0, TX_READING_REG));
    dp_tx_reg_write8(0, TX_SELECT_REG, 0xfb);
    dp_reg_write8(port, 0xcd, dp_tx_reg_read8(0, TX_READING_REG));
    dp_tx_reg_write8(0, TX_SELECT_REG, 0xf5);
    dp_reg_write8(port, 0xce, dp_tx_reg_read8(0, TX_READING_REG));
    dp_tx_reg_write8(0, TX_SELECT_REG, 0xfd);
    dp_reg_write8(port, 0xcf, dp_tx_reg_read8(0, TX_READING_REG));
    dp_reg_write8(port, 0xd6, 0x7f);
}

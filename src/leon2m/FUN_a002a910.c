/* leon2m FUN_a002a910 @ 0xa002a910..0xa002ab04 (125 words)  bit-banged I2C START with bus recovery.
 * Called twice per EEPROM read by FUN_a002bb28 (start and repeated start), start-up step 5
 * (FUN_a0153c74 -> FUN_a0140360 -> FUN_a002bb28). Bus = descriptor at RAM 0xA802D992 (see
 * FUN_a002ab04.c; FW.021: SCL port 6 mask 0x80, SDA port 6 mask 0x40, delay 4).
 * What it does (code facts): SCL taken, SDA driven 1, SCL driven 1 and released, wait until SCL reads high (0xFFFF
 * countdown, 2 nops per round), SCL taken again, SDA released, delay. Bus recovery: while SDA reads low, at most 9
 * extra clock pulses (SCL low, delay, SCL high + the same bounded SCL wait, delay). Then the START itself: SDA taken
 * and driven low while SCL is high, delay, SCL driven low.
 * Can it wait or fail? It cannot fail (void) and it CANNOT wait without limit: every loop is bounded (SCL waits by
 * 0xFFFF rounds, recovery by 9 pulses, FUN_a002d23c is a fixed nop loop). A stuck bus just runs out the counters.
 * Exact form: the same "while (!pin && --t) { nop; nop; }" poll as FUN_a002ab04, recovery as a for loop with a u8
 * counter.
 */
struct I2cBus { unsigned char scl_port, scl_mask, sda_port, sda_mask; unsigned short delay;
                unsigned char dev, alen; unsigned short flags; };
extern struct I2cBus DAT_a802d992;
extern void FUN_a002c86c(unsigned char, unsigned char, unsigned char);
extern void FUN_a002cb30(unsigned char, unsigned char, unsigned char);
extern unsigned char FUN_a002cd38(unsigned char, unsigned char);
extern void FUN_a002d23c(unsigned short);

void FUN_a002a910(void)
{
    unsigned char i;
    unsigned short t;

    FUN_a002cb30(DAT_a802d992.scl_port, DAT_a802d992.scl_mask, 0);
    FUN_a002c86c(DAT_a802d992.sda_port, DAT_a802d992.sda_mask, 1);
    FUN_a002c86c(DAT_a802d992.scl_port, DAT_a802d992.scl_mask, 1);
    FUN_a002cb30(DAT_a802d992.scl_port, DAT_a802d992.scl_mask, 1);
    t = 0xffff;
    while (!FUN_a002cd38(DAT_a802d992.scl_port, DAT_a802d992.scl_mask) && --t) {
        __asm__ __volatile__("nop");
        __asm__ __volatile__("nop");
    }
    FUN_a002cb30(DAT_a802d992.scl_port, DAT_a802d992.scl_mask, 0);
    FUN_a002cb30(DAT_a802d992.sda_port, DAT_a802d992.sda_mask, 1);
    FUN_a002d23c(DAT_a802d992.delay * 2);
    for (i = 0; !FUN_a002cd38(DAT_a802d992.sda_port, DAT_a802d992.sda_mask) && i <= 8; i++) {
        FUN_a002c86c(DAT_a802d992.scl_port, DAT_a802d992.scl_mask, 0);
        FUN_a002d23c(DAT_a802d992.delay * 2);
        FUN_a002c86c(DAT_a802d992.scl_port, DAT_a802d992.scl_mask, 1);
        FUN_a002cb30(DAT_a802d992.scl_port, DAT_a802d992.scl_mask, 1);
        t = 0xffff;
        while (!FUN_a002cd38(DAT_a802d992.scl_port, DAT_a802d992.scl_mask) && --t) {
            __asm__ __volatile__("nop");
            __asm__ __volatile__("nop");
        }
        FUN_a002cb30(DAT_a802d992.scl_port, DAT_a802d992.scl_mask, 0);
        FUN_a002d23c(DAT_a802d992.delay * 2);
    }
    FUN_a002cb30(DAT_a802d992.sda_port, DAT_a802d992.sda_mask, 0);
    FUN_a002c86c(DAT_a802d992.sda_port, DAT_a802d992.sda_mask, 0);
    FUN_a002d23c(DAT_a802d992.delay * 2);
    FUN_a002c86c(DAT_a802d992.scl_port, DAT_a802d992.scl_mask, 0);
}

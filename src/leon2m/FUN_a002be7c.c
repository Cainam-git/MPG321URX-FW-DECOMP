/* leon2m FUN_a002be7c @ 0xa002be7c..0xa002c11c (168 words), flags -mcpu=v8 -O3 -g.
 * What it does: I2C "is the device there" probe. The settings write FUN_a0140e74 uses it as its write-cycle ACK poll
 * after every 16-byte chunk (start-up callers FUN_a0153c74 / FUN_a012cfac, only when they write defaults).
 * Code facts: only if the bus copy 0xA802D992 has mode 2 (else returns 0 at once): START (FUN_a002a910), STOP (SDA 0,
 * delay, SCL 1 + released, bounded wait for SCL, taken, delay, SDA 1), delay, START, address byte dev through
 * FUN_a002ab04: ACK (0) -> r = 1, NACK -> r = 0, STOP, delay, START, STOP. Returns r (1 = the device ACKed).
 * Can it wait or fail at power-on? Its own three SCL waits are bounded (0xFFFF rounds of 2 nops each) and its delays
 * are the fixed nop loop FUN_a002d23c (no timer needed). The only open end inside is the shared FUN_a002ab04 late-ACK
 * loop (exits only when FUN_a002cd38(scl) reads 1). It cannot report an error other than r = 0. BUT its caller
 * FUN_a0140e74 loops 'while (!FUN_a002be7c(dev)) ;' with no counter (0xA0140F6C..0xA0140F78): a device that never
 * ACKs its address again keeps the Big chip there for ever.
 * Pin words (SCL/SDA) name the arguments of the pin functions (see FUN_a002ab04.c).
 * Source form: the first SCL poll is the '&& --t' form like the other two; the probe result is an if/else
 * ('if (ab04(dev) == 0) r = 1; else r = 0;'), which puts r in %i0 first and moves it to %l4 later (the '== 0'
 * expression and the '?:' form keep it in another register and change 90 words).
 */
struct I2cBus { unsigned char scl_port, scl_mask, sda_port, sda_mask; unsigned short delay;
                unsigned char dev, alen; unsigned short mode : 2, rest : 14; };
extern struct I2cBus DAT_a802d992;
extern void FUN_a002c86c(unsigned char, unsigned char, unsigned char);
extern void FUN_a002cb30(unsigned char, unsigned char, unsigned char);
extern unsigned char FUN_a002cd38(unsigned char, unsigned char);
extern void FUN_a002d23c(unsigned short);
extern void FUN_a002a910(void);
extern unsigned char FUN_a002ab04(unsigned char);

unsigned char FUN_a002be7c(unsigned char dev)
{
    unsigned char r = 0;
    unsigned short t;

    if (DAT_a802d992.mode == 2) {
        FUN_a002a910();
        FUN_a002c86c(DAT_a802d992.sda_port, DAT_a802d992.sda_mask, 0);
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
        FUN_a002c86c(DAT_a802d992.sda_port, DAT_a802d992.sda_mask, 1);
        FUN_a002d23c(DAT_a802d992.delay * 2);
        FUN_a002a910();
        if (FUN_a002ab04(dev) == 0) r = 1; else r = 0;
        FUN_a002c86c(DAT_a802d992.sda_port, DAT_a802d992.sda_mask, 0);
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
        FUN_a002c86c(DAT_a802d992.sda_port, DAT_a802d992.sda_mask, 1);
        FUN_a002d23c(DAT_a802d992.delay * 2);
        FUN_a002a910();
        FUN_a002c86c(DAT_a802d992.sda_port, DAT_a802d992.sda_mask, 0);
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
        FUN_a002c86c(DAT_a802d992.sda_port, DAT_a802d992.sda_mask, 1);
    }
    return r & 1;
}

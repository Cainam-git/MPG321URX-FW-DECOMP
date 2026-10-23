/* leon2m FUN_a002ae4c @ 0xa002ae4c..0xa002b058 (131 words)  bit-banged I2C: read one byte and send ACK / NACK
 * Called by FUN_a002bb28 once per data byte of an EEPROM read (start-up step 5, before
 * the hook, via FUN_a0153c74 -> FUN_a0140360). Bus = descriptor at RAM 0xA802D992 (see FUN_a002ab04.c).
 * What it does (code facts): SDA released and driven 1; 8 bits MSB first: SCL high and released, wait until SCL
 * reads high (0xFFFF countdown), SCL taken, delay, sample SDA into the byte, SCL low, delay. Then SDA taken and
 * driven 0 (ACK, more bytes follow) or 1 (NACK, 'last' set = final byte), one more SCL clock with the same bounded
 * wait, SCL low, delay. Returns the byte.
 * Can it wait or fail? It CANNOT wait without limit: the two SCL waits are 0xFFFF rounds each, the bit loop is 8
 * rounds, FUN_a002d23c is a fixed nop loop. It cannot report an error (a dead bus reads as SDA level, e.g. 0xFF).
 * Exact form: same poll shape as FUN_a002ab04; the shifted byte w = v << 1 taken at the top of each round and v = w or
 * w | 1 after the SDA sample; nack = last & 1 as an unsigned int local; both ifs written with the 0 arm first.
 */
struct I2cBus { unsigned char scl_port, scl_mask, sda_port, sda_mask; unsigned short delay;
                unsigned char dev, alen; unsigned short flags; };
extern struct I2cBus DAT_a802d992;
extern void FUN_a002c86c(unsigned char, unsigned char, unsigned char);
extern void FUN_a002cb30(unsigned char, unsigned char, unsigned char);
extern unsigned char FUN_a002cd38(unsigned char, unsigned char);
extern void FUN_a002d23c(unsigned short);

unsigned char FUN_a002ae4c(unsigned char last)
{
    unsigned char i;
    unsigned int v, w;
    unsigned short t;
    unsigned int nack = last & 1;

    FUN_a002cb30(DAT_a802d992.sda_port, DAT_a802d992.sda_mask, 1);
    FUN_a002c86c(DAT_a802d992.sda_port, DAT_a802d992.sda_mask, 1);
    v = 0;
    for (i = 0; i <= 7; i++) {
        w = v << 1;
        FUN_a002c86c(DAT_a802d992.scl_port, DAT_a802d992.scl_mask, 1);
        FUN_a002cb30(DAT_a802d992.scl_port, DAT_a802d992.scl_mask, 1);
        t = 0xffff;
        while (!FUN_a002cd38(DAT_a802d992.scl_port, DAT_a802d992.scl_mask) && --t) {
            __asm__ __volatile__("nop");
            __asm__ __volatile__("nop");
        }
        FUN_a002cb30(DAT_a802d992.scl_port, DAT_a802d992.scl_mask, 0);
        FUN_a002d23c(DAT_a802d992.delay * 2);
        if (!FUN_a002cd38(DAT_a802d992.sda_port, DAT_a802d992.sda_mask))
            v = w;
        else
            v = w | 1;
        FUN_a002c86c(DAT_a802d992.scl_port, DAT_a802d992.scl_mask, 0);
        FUN_a002d23c(DAT_a802d992.delay * 2);
    }
    FUN_a002cb30(DAT_a802d992.sda_port, DAT_a802d992.sda_mask, 0);
    if (!nack)
        FUN_a002c86c(DAT_a802d992.sda_port, DAT_a802d992.sda_mask, 0);
    else
        FUN_a002c86c(DAT_a802d992.sda_port, DAT_a802d992.sda_mask, 1);
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
    FUN_a002c86c(DAT_a802d992.scl_port, DAT_a802d992.scl_mask, 0);
    FUN_a002d23c(DAT_a802d992.delay * 2);
    return v;
}

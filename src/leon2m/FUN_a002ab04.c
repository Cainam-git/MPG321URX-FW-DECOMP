/* leon2m FUN_a002ab04 @ 0xa002ab04..0xa002ae4c (210 words)  bit-banged I2C: send one byte and read the ACK
 * Part of the EEPROM read FUN_a002bb28 (start-up step 5, via
 * FUN_a0153c74 -> FUN_a0140360). The bus is the 10-byte descriptor copied by FUN_a002bb28 to RAM 0xA802D992: SCL =
 * (port b0, mask b1), SDA = (port b2, mask b3), half-bit delay h4 (FW.021 descriptor ROM 0x1A69E0[0]: SCL port 6
 * mask 0x80, SDA port 6 mask 0x40, delay 4). GPIO helpers: FUN_a002c86c(port, mask, level) drives a pin,
 * FUN_a002cb30(port, mask, 1/0) releases / takes the pin (1 = released, read back below), FUN_a002cd38(port, mask)
 * reads it; FUN_a002d23c(n) is a pure nop busy loop (n x 200 nops, no timer).
 * What it does (code facts): 8 bits MSB first: SCL low, SDA = bit, SCL high and released, then wait for SCL to read
 * high with a 0xFFFF countdown (clock stretching, BOUNDED). Then the ACK clock: SDA released, SCL high, bounded SCL
 * wait, then: SCL reads low -> result 1; SDA reads low (ACK) -> result 0; else (NACK) the late-ACK loop below.
 * Tail: SCL and SDA taken and driven low, one delay, return result (0 = ACK, 1 = no ACK; FUN_a002bb28 retries on 1).
 * CAN IT WAIT WITHOUT LIMIT? YES, in one place: the late-ACK loop 'while ((SDA high && n) || SCL low) { delay; n--; }'
 * (0xA002AD90..0xA002ADD4) has its only exit at 0xA002ADD4 = SCL reads high; the counter n (7, then wrapping) only
 * stops the SDA part. So after a NACK, if SCL then reads low and stays low (a device holding the clock), the Big
 * chip spins here for ever. Every other wait in this function is bounded.
 * Exact form: the mask table as an initialised local array, poll as "while (!pin && --t) { nop; nop; }" (the fw has
 * them in the poll loops), result as u8 returned & 1.
 */
struct I2cBus { unsigned char scl_port, scl_mask, sda_port, sda_mask; unsigned short delay;
                unsigned char dev, alen; unsigned short flags; };
extern struct I2cBus DAT_a802d992;
extern void FUN_a002c86c(unsigned char, unsigned char, unsigned char);
extern void FUN_a002cb30(unsigned char, unsigned char, unsigned char);
extern unsigned char FUN_a002cd38(unsigned char, unsigned char);
extern void FUN_a002d23c(unsigned short);

unsigned char FUN_a002ab04(unsigned char v)
{
    unsigned char m[8] = { 0x80, 0x40, 0x20, 0x10, 8, 4, 2, 1 };
    unsigned char i, n, r;
    unsigned short t;

    for (i = 0; i <= 7; i++) {
        FUN_a002d23c(DAT_a802d992.delay * 2);
        FUN_a002c86c(DAT_a802d992.scl_port, DAT_a802d992.scl_mask, 0);
        FUN_a002d23c(DAT_a802d992.delay);
        if (v & m[i])
            FUN_a002c86c(DAT_a802d992.sda_port, DAT_a802d992.sda_mask, 1);
        else
            FUN_a002c86c(DAT_a802d992.sda_port, DAT_a802d992.sda_mask, 0);
        FUN_a002d23c(DAT_a802d992.delay);
        FUN_a002c86c(DAT_a802d992.scl_port, DAT_a802d992.scl_mask, 1);
        FUN_a002cb30(DAT_a802d992.scl_port, DAT_a802d992.scl_mask, 1);
        t = 0xffff;
        while (!FUN_a002cd38(DAT_a802d992.scl_port, DAT_a802d992.scl_mask) && --t) {
            __asm__ __volatile__("nop");
            __asm__ __volatile__("nop");
        }
        FUN_a002cb30(DAT_a802d992.scl_port, DAT_a802d992.scl_mask, 0);
    }
    FUN_a002d23c(DAT_a802d992.delay * 2);
    FUN_a002c86c(DAT_a802d992.scl_port, DAT_a802d992.scl_mask, 0);
    FUN_a002d23c(DAT_a802d992.delay * 2);
    FUN_a002c86c(DAT_a802d992.sda_port, DAT_a802d992.sda_mask, 0);
    FUN_a002cb30(DAT_a802d992.sda_port, DAT_a802d992.sda_mask, 1);
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
    FUN_a002cb30(DAT_a802d992.scl_port, DAT_a802d992.scl_mask, 1);
    if (!FUN_a002cd38(DAT_a802d992.scl_port, DAT_a802d992.scl_mask))
        r = 1;
    else if (!FUN_a002cd38(DAT_a802d992.sda_port, DAT_a802d992.sda_mask))
        r = 0;
    else {
        n = 7;
        while ((FUN_a002cd38(DAT_a802d992.sda_port, DAT_a802d992.sda_mask) && n)
               || !FUN_a002cd38(DAT_a802d992.scl_port, DAT_a802d992.scl_mask)) {
            FUN_a002d23c(DAT_a802d992.delay * 2);
            n--;
        }
        r = (n == 0);
    }
    FUN_a002cb30(DAT_a802d992.scl_port, DAT_a802d992.scl_mask, 0);
    FUN_a002c86c(DAT_a802d992.scl_port, DAT_a802d992.scl_mask, 0);
    FUN_a002cb30(DAT_a802d992.sda_port, DAT_a802d992.sda_mask, 0);
    FUN_a002c86c(DAT_a802d992.sda_port, DAT_a802d992.sda_mask, 0);
    FUN_a002d23c(DAT_a802d992.delay * 2);
    return r & 1;
}

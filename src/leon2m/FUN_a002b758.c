/* leon2m FUN_a002b758 @ 0xa002b758..0xa002bb28 (244 words), flags -mcpu=v8 -O3 -g. Caller: FUN_a01257f0.
 * Bit-banged I2C write-then-read, built like FUN_a002bb28 (same bus descriptor and helpers):
 * FUN_a002b758(bus, wbuf, wlen, rbuf, rlen) -> bytes read.
 * Code facts: copies the 10-byte bus descriptor *d to RAM 0xA802D992; device byte = descriptor byte dev. Mode != 2
 * -> returns 0 without touching the bus. START (FUN_a002a910), device byte with up to 10 tries (FUN_a002ab04 returns
 * 1 = no ACK, FUN_a002d23c(delay * 2) between tries); 10 failures -> STOP and return 0. Then wbuf[0..wlen-1] until
 * one byte is NACKed; a NACK before wlen bytes -> STOP and return 0. Otherwise repeated START, read command dev | 1
 * with up to 10 tries (result not checked), rlen bytes into rbuf via FUN_a002ae4c (argument 1 = NACK on the last
 * byte), STOP, return the count (= rlen).
 * STOP: SDA low, delay, SCL high (FUN_a002c86c / FUN_a002cb30), SCL polled with FUN_a002cd38 for at most 0xFFFF
 * rounds (two nops per round), then SCL released, delay, SDA high.
 * Source form: the write loop ends with the test i < wlen (the firmware's cmp wlen, i; bleu).
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
extern unsigned char FUN_a002ae4c(unsigned char);

unsigned short FUN_a002b758(struct I2cBus *d, unsigned char *wbuf, unsigned short wlen, unsigned char *rbuf,
                            unsigned short rlen)
{
    unsigned short n = 0, i, t;
    unsigned char dev;

    DAT_a802d992 = *d;
    dev = DAT_a802d992.dev;
    if (DAT_a802d992.mode == 2) {
        FUN_a002a910();
        for (i = 0; i <= 9; i++) {
            if (!FUN_a002ab04(dev))
                break;
            FUN_a002d23c(DAT_a802d992.delay * 2);
        }
        if (i == 10) {
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
            return 0;
        }
        for (i = 0; i < wlen; i++) {
            if (FUN_a002ab04(wbuf[i]) == 1)
                break;
        }
        if (i < wlen) {
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
            return 0;
        }
        FUN_a002a910();
        for (i = 0; i <= 9; i++) {
            if (!FUN_a002ab04(DAT_a802d992.dev | 1))
                break;
            FUN_a002d23c(DAT_a802d992.delay * 2);
        }
        for (i = 0; i < rlen; i++) {
            if (i == rlen - 1)
                rbuf[i] = FUN_a002ae4c(1);
            else
                rbuf[i] = FUN_a002ae4c(0);
            n++;
        }
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
    return n;
}

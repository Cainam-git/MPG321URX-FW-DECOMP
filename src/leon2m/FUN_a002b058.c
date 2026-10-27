/* leon2m FUN_a002b058 @ 0xa002b058..0xa002b3e4 (227 words), flags -mcpu=v8 -O3 -g. Caller: FUN_a0125754.
 * Bit-banged I2C write of two buffers, built like FUN_a002b3e4 (same bus descriptor and helpers).
 * Code facts: copies the 10-byte bus descriptor *d to RAM 0xA802D992; device byte = descriptor byte dev (no address
 * bytes, no FUN_a002ced8 calls). Per try, when mode == 2: START (FUN_a002a910), device byte with up to 10 tries
 * (FUN_a002d23c(delay * 2) between; 10 NACKs -> STOP sequence, return 0), then the bytes buf1[0..len1-1] until one
 * is NACKed (FUN_a002ab04 returns 1); only when all len1 bytes were ACKed, the bytes buf2[0..len2-1] the same way,
 * n = bytes of buf2 ACKed; STOP sequence if 'stop'; try count + 1. Repeats while (last byte NACKed && count <=
 * tries). Returns n.
 * STOP sequence: SDA low, delay, SCL high (FUN_a002c86c / FUN_a002cb30), SCL polled with FUN_a002cd38 for at most
 * 0xFFFF rounds (two nops per round), then SCL released, delay, SDA high.
 * Source form: one byte variable v carries every byte sent, as in FUN_a002b3e4.
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
extern void FUN_a002ced8(void);

unsigned short FUN_a002b058(struct I2cBus *d, unsigned char *buf1, unsigned short len1, unsigned char *buf2,
                            unsigned short len2, unsigned char tries, unsigned char stop)
{
    unsigned short n, i, t;
    unsigned char dev, ok = 1, cnt = 0, v;

    DAT_a802d992 = *d;
    dev = DAT_a802d992.dev;
    do {
        n = 0;
        if (DAT_a802d992.mode == 2) {
            FUN_a002a910();
            v = dev;
            for (i = 0; i <= 9; i++) {
                if (!FUN_a002ab04(v))
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
            for (i = 0; i < len1; i++) {
                v = buf1[i];
                ok = FUN_a002ab04(v);
                if (ok == 1)
                    break;
            }
            if (i == len1) {
                for (i = 0; i < len2; i++) {
                    v = buf2[i];
                    ok = FUN_a002ab04(v);
                    if (ok == 1)
                        break;
                    n++;
                }
            }
            if (stop) {
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
            cnt++;
        }
    } while (ok == 1 && cnt <= tries);
    return n;
}

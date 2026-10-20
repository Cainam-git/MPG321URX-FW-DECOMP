/* leon2m FUN_a002b3e4 @ 0xa002b3e4..0xa002b758 (221 words). BYTE-EXACT: jf 100.00
 * match=True, rawcmp 0/221 with -mcpu=v8 -O3 -g.
 * What it does: bit-banged I2C page write, used by the settings write FUN_a0140e74 (callers FUN_a0153c74 /
 * FUN_a012cfac, only when they write defaults). FUN_a0140e74 calls it with tries 1, stop 1, at most 16 bytes.
 * Code facts: copies the 10-byte bus descriptor *d to RAM 0xA802D992 (FW.021 bus ROM 0x1A69E0[0]: SCL port 6 mask
 * 0x80, SDA port 6 mask 0x40, delay 4, device 0xA0, 2 address bytes, mode 2); device byte = dev, or with 1 address byte
 * dev | ((addr >> 7) & 0xE); relays the liveness ring FUN_a002ced8 once, then per try: n = 0; if mode == 2: START
 * (FUN_a002a910), device byte with up to 10 tries (FUN_a002d23c delay between; 10 NACKs -> STOP, return 0), address
 * byte(s) (ACK not checked), data bytes until one is NACKed (ok == 1) -> n = bytes ACKed; STOP if 'stop'; try count + 1.
 * Then FUN_a002ced8 again; repeats while (last byte NACKed && count <= tries). Returns n.
 * Can it wait or fail at power-on? Its own waits are bounded in FW.021: SCL polls 0xFFFF rounds, retries bounded by
 * 'tries', delays are the fixed nop loop FUN_a002d23c. The only unbounded wait is the shared FUN_a002ab04 late-ACK loop
 * (exit only when FUN_a002cd38(SCL) reads 1). Failure = returns fewer bytes than asked (FUN_a0140e74 ignores the
 * return value). With mode != 2 the try count would never rise and the loop would not end while ok == 1; FW.021's
 * bus has mode 2, so this does not happen in FW.021.
 * Pin words (SCL/SDA) name the helper arguments (see FUN_a002ab04.c).
 * Byte-exact lever: one byte variable v carries every byte sent (device, address, data), as a driver's 'send byte'
 * variable. Because v is set several times in the retry loop, gcc's loop pass does not hoist the u8 truncation of the
 * device byte out of the retry loop (the fw truncates it after each START); with 'FUN_a002ab04(dev)' it is hoisted.
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

unsigned short FUN_a002b3e4(struct I2cBus *d, unsigned short addr, unsigned short len, unsigned char *buf,
                            unsigned char tries, unsigned char stop)
{
    unsigned short n, i, t;
    unsigned char dev, ok = 1, cnt = 0, v;

    DAT_a802d992 = *d;
    if (DAT_a802d992.alen == 1)
        dev = ((addr >> 7) & 0xe) | DAT_a802d992.dev;
    else
        dev = DAT_a802d992.dev;
    FUN_a002ced8();
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
            if (DAT_a802d992.alen != 1) {
                v = addr >> 8;
                FUN_a002ab04(v);
            }
            v = addr;
            FUN_a002ab04(v);
            for (i = 0; i < len; i++) {
                v = buf[i];
                ok = FUN_a002ab04(v);
                if (ok == 1)
                    break;
                n++;
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
        FUN_a002ced8();
    } while (ok == 1 && cnt <= tries);
    return n;
}

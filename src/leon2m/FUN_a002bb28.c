/* leon2m FUN_a002bb28 @ 0xa002bb28..0xa002be7c (213 words): bit-banged I2C random read of the settings storage,
 * FUN_a002bb28(bus, addr, len, buf) -> bytes read. Runs at start-up step 5: FUN_a0153c74 ->
 * FUN_a0140360(dev 0, ...) -> here (called as the RAM copy 0x4008BB28), and for the FGA marker read in FUN_a012cfac.
 * -mcpu=v8 -O3 -g (also -msoft-float): jf 100.00
 * match=True, tools/exact.py exact() = None.
 * In plain words: it copies the bus description, sends START + device byte (up to 10 tries), the storage address,
 * a repeated START with the read command, reads len bytes (the last one with NACK) and sends STOP. If the device
 * never answers the device byte it sends STOP and returns 0 without touching buf.
 * What it does (code facts, confirmed by this exact C):
 *  - copies the 10-byte bus descriptor to RAM 0xA802D992 (FW.021: ROM 0x1A69E0[0] = SCL port 6 mask 0x80, SDA port 6
 *    mask 0x40, delay 4, device 0xA0, address width 2, mode bits 15..14 = 2).
 *  - device byte = dev | ((addr >> 7) & 0xE) for width 1, else dev. Mode != 2 -> returns 0 without touching the bus.
 *  - START (FUN_a002a910), device byte with up to 10 tries (FUN_a002ab04 returns 1 = no ACK, delay 2 x delay between
 *    tries); 10 failures -> STOP and return 0 (buf untouched).
 *  - address: width 1 -> low byte only; else high byte then low byte (ACK of the address bytes NOT checked).
 *  - repeated START, read command dev | 1 with up to 10 tries (result NOT checked: after 10 NACKs it still reads),
 *    len bytes via FUN_a002ae4c (argument 1 = NACK on the last byte), STOP, return the count (= len).
 * Can it wait without limit? Not in this function: retries 10, read loop len, the SCL wait in STOP is 0xFFFF rounds,
 * FUN_a002d23c is a fixed delay. FUN_a002a910 and FUN_a002ae4c are bounded (byte-exact). The ONLY unbounded wait
 * under this read is inside FUN_a002ab04 (byte-exact): after a NACK it loops until SCL reads high.
 * Pin words (SCL/SDA high, low, released, taken) name the arguments of the pin functions:
 * FUN_a002c86c(p, m, 1) sets / (p, m, 0) clears the mask bits of the port data register, FUN_a002cb30(p, m, 1/0)
 * sets / clears them in the second register, FUN_a002cd38 reads the data register.
 * Levers (documented, no-code):
 *  (1) the address bytes as a full if/else, 'if (alen == 1) ab04(addr); else { ab04(addr >> 8);
 *      ab04(addr); }' (crossjump merges the common call, as in the fw). The form 'if (alen != 1)
 *      ab04(addr >> 8); ab04(addr);' leaves a skippable block, and CSE's skip-blocks path following then shares the
 *      record address between the STOP-on-failure block and the address block (found with -fno-cse-skip-blocks:
 *      82.16 / rawcmp 38 with the old form, diagnostic only). That one pseudo was the whole register difference.
 *  (2) the poll 't = 0xffff; while (!pin && --t) { nop; nop; }': the fw's nops are real instructions, written
 *      as asm nops (same form as FUN_a002a910 / FUN_a002ae4c / FUN_a002be7c).
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

unsigned short FUN_a002bb28(struct I2cBus *d, unsigned short addr, unsigned short len, unsigned char *buf)
{
    unsigned short n = 0, i, t;
    unsigned char dev;

    DAT_a802d992 = *d;
    if (DAT_a802d992.alen == 1)
        dev = ((addr >> 7) & 0xe) | DAT_a802d992.dev;
    else
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
        if (DAT_a802d992.alen == 1)
            FUN_a002ab04(addr);
        else {
            FUN_a002ab04(addr >> 8);
            FUN_a002ab04(addr);
        }
        FUN_a002a910();
        for (i = 0; i <= 9; i++) {
            if (!FUN_a002ab04(DAT_a802d992.dev | 1))
                break;
            FUN_a002d23c(DAT_a802d992.delay * 2);
        }
        for (i = 0; i < len; i++) {
            if (i == len - 1)
                buf[i] = FUN_a002ae4c(1);
            else
                buf[i] = FUN_a002ae4c(0);
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

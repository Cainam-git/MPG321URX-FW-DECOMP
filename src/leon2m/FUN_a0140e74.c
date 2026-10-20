/* leon2m FUN_a0140e74 @ 0xa0140e74..0xa01410a4 (140 words): settings-storage WRITE.
 * Flags: -mcpu=v8 -O3 -g.
 *
 * Plain words: writes len bytes from buf to settings storage 'dev' at storage address addr. The ROM record table
 * DAT_001a69fe[dev] (0x26 bytes per device) says how: its byte b0 with bit 7 SET selects the second path (not
 * used by FW.021 dev 0), bit 7 CLEAR the bit-banged I2C chip with bus number b = b0 (FW.021 dev 0: b0 = 0).
 *  - b0 bit 7 set: FUN_a0140b78(dev), offset off = DAT_a802cc00[dev].h0 if the area table DAT_001a6a24[b].b2 == 1,
 *    else 0, then FUN_a013588c(addr + off, len, buf); RAM byte 0xA802CBD9 = 1, RAM half 0xA802CC04 =
 *    func_0x4008d588(); if 'flag' is non-zero: FUN_a01405d0(dev) and 0xA802CBD9 = 0 again.
 *  - I2C path: write-protect pin DAT_001a69d6[b] (port, mask, level; FW.021 b 0 = port 6 mask 0x08 level 1) is driven
 *    to ~level, then per 16-byte chunk: copy of the bus descriptor DAT_001a69e0[b] onto the stack, func_0x4008b3e4
 *    (= FUN_a002b3e4, I2C page write, bounded), func_0x4008d1a0(7) (7-tick delay; ends only while the
 *    FUN_a002cfb8 timer IRQ runs), then 'while (!func_0x4008be7c(bus dev byte)) ;' (= FUN_a002be7c, ACK
 *    probe) at 0xA0140F6C..0xA0140F78 with NO counter. After the last chunk the pin goes back to 'level'.
 * At power-on it runs only when FUN_a0153c74 finds the system record bad or FUN_a012cfac (FGA_Init) finds no
 * 0x77..0x7A marker.
 * Can it wait or fail? WAIT: yes, the ACK poll above waits for ever if the storage chip never ACKs its address after
 * a write, and nothing relays the liveness ring inside that loop. FAIL: a failed write is not detected: the return
 * of FUN_a002b3e4 (ACKed byte count) is ignored, the function returns nothing.
 * Source form: (1) the bit-7 path is written FIRST ('if (b0 < 0) { bit-7 path } else { I2C }'): with
 * -frename-registers (on at -O3) the register renaming walks the basic blocks in source order and picks the least
 * recently used register ('tick' order), so the block order decides the I2C path's registers; (2) 'off = 0; if
 * (...) off = ...;' in a static u16 helper; (3) the descriptor copy as a struct copy per chunk arm.
 */
struct B38 { unsigned char b0, b1; unsigned short h2; unsigned char b4; char name[33]; };
struct A36 { unsigned short h0; unsigned char b2, b3; char name[32]; };
struct E4 { unsigned short h0; unsigned char b2, b3; };
struct Bus { unsigned char scl_port, scl_mask, sda_port, sda_mask; unsigned short delay; unsigned char dev, alen; unsigned short flags; };
struct Pin { unsigned char port, mask, level; };
extern const struct B38 DAT_001a69fe[];
extern const struct A36 DAT_001a6a24[];
extern const struct Bus DAT_001a69e0[];
extern const struct Pin DAT_001a69d6[];
extern struct E4 DAT_a802cc00[];
extern unsigned char DAT_a802cbd9;
extern unsigned short DAT_a802cc04;
extern void FUN_a002c86c(unsigned char, unsigned char, unsigned char);
extern unsigned short func_0x4008b3e4(struct Bus *, unsigned short, unsigned short, unsigned char *, unsigned char, unsigned char);
extern void func_0x4008d1a0(unsigned short);
extern unsigned char func_0x4008be7c(unsigned char);
extern unsigned short func_0x4008d588(void);
extern void func_0x4008c86c(unsigned char, unsigned char, unsigned char);
extern void FUN_a0140b78(unsigned char);
extern void FUN_a013588c(unsigned short, unsigned short, unsigned char *);
extern void FUN_a01405d0(unsigned char);

static unsigned short area_off(unsigned char dev, unsigned char b)
{
    unsigned short off = 0;
    if (DAT_001a6a24[b].b2 == 1)
        off = DAT_a802cc00[dev].h0;
    return off;
}

void FUN_a0140e74(unsigned char dev, unsigned short addr, unsigned short len, unsigned char *buf, unsigned char flag)
{
    unsigned char b;
    unsigned short n, off;

    if ((signed char)DAT_001a69fe[dev].b0 < 0) {
        b = DAT_001a69fe[dev].b0;
        FUN_a0140b78(dev);
        off = area_off(dev, b);
        FUN_a013588c(addr + off, len, buf);
        DAT_a802cbd9 = 1;
        DAT_a802cc04 = func_0x4008d588();
        if (flag) {
            FUN_a01405d0(dev);
            DAT_a802cbd9 = 0;
        }
    } else {
        b = DAT_001a69fe[dev].b0;
        func_0x4008c86c(DAT_001a69d6[b].port, DAT_001a69d6[b].mask, ~DAT_001a69d6[b].level);
        n = len;
        while (n != 0) {
            if (n > 16) {
                struct Bus d = DAT_001a69e0[b];
                func_0x4008b3e4(&d, addr, 16, buf + (len - n), 1, 1);
                addr += 16;
                n -= 16;
            } else {
                struct Bus d = DAT_001a69e0[b];
                func_0x4008b3e4(&d, addr, n, buf + (len - n), 1, 1);
                n = 0;
            }
            func_0x4008d1a0(7);
            while (!func_0x4008be7c(DAT_001a69e0[b].dev))
                ;
        }
        func_0x4008c86c(DAT_001a69d6[b].port, DAT_001a69d6[b].mask, DAT_001a69d6[b].level);
    }
}

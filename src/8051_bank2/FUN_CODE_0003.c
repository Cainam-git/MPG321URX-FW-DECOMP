/* 8051_bank2 module: FUN_CODE_0003 @ 0x0003 + FUN_CODE_c0be @ 0xc0be + FUN_CODE_da8a @ 0xda8a (byte-exact
 * with OPTIMIZE(8,SPEED) LARGE; compiled together because Keil's "reuse of common entry code" then emits the shared
 * entry blocks FUN_CODE_da66 / FUN_CODE_da86 in front of da8a exactly as in the firmware). Update agent (AUX 8051).
 *
 * FUN_CODE_0003: identify the SPI flash chip; returns 0 = known chip, 2 = unknown.
 *   Sends 0x9F (Read JEDEC ID) through the SPI engine FUN_CODE_c0be(buf, 2 bytes out, 1); a Winbond answer EF 40 is
 *   looked up directly in the chip table at CODE 0xCB8C (8-byte records; FUN_CODE_c44e). Otherwise up to 3 tries:
 *   scaler register 0xF068 = CODE[0xCBD6 + try] (FUN_CODE_e2da settles), the ID is read back with service-bus reads of
 *   0xF064..0xF066 (FUN_CODE_e105) and looked up with FUN_CODE_b044. Found: the 8-byte record is copied to XDATA 0x0640
 *   and its byte 2 written to scaler register 0xF067 (the da66 entry block of da8a); result 0. Not found: result 2.
 * FUN_CODE_c0be(buf, n, m): one SPI flash transaction run by the SCALER's SPI controller, driven remotely over the
 *   service bus (FUN_CODE_da8a writes): 0xF0C0 = ((n >> 1) << 4) | 3, 0xF0C1 = 0xA7, 0xF0C2 = 0, 0xF0C3 = 0xA7,
 *   0xF0C4 = n, 0xF0C5 = 0xA7, 0xF0C6 = n + m; the n + m bytes of buf go to the scaler window 0xA700 + i; then
 *   FUN_CODE_e3ab (start), wait 20 units, and 16 bytes are read back from 0xA700.. into buf (FUN_CODE_e105).
 *   Its only caller in the image is FUN_CODE_0003 with the 0x9F ID read (the public MPG 341CQPX write-up says the
 *   same: no write-enable / program / erase command is ever put into this engine's buffer by the update agent).
 * FUN_CODE_da8a: see src/8051_bank2/FUN_CODE_da8a.c (service-bus register write 04 78 hi lo val to slave 0x6E).
 */
extern unsigned char code DAT_CODE_cbd6[];
void FUN_CODE_c0be(unsigned char *buf, unsigned char n, unsigned char m);
unsigned char FUN_CODE_c44e(unsigned char *buf, void *tbl);
unsigned char FUN_CODE_b044(unsigned char *buf, void *tbl);
struct FlashInfo { unsigned char b[8]; };
extern struct FlashInfo code DAT_CODE_cb8c[];
extern struct FlashInfo xdata DAT_EXTMEM_0640;
extern unsigned char xdata DAT_EXTMEM_0436[];
unsigned char FUN_CODE_bfcf(unsigned char addr, unsigned char len, unsigned char *buf);
void FUN_CODE_d059(unsigned int t);
void FUN_CODE_e4b9(void);
unsigned char FUN_CODE_da8a(unsigned int reg, unsigned char val);
void FUN_CODE_e2da(void);
unsigned char FUN_CODE_e105(unsigned int reg);

unsigned char FUN_CODE_0003(void)
{
    unsigned char j, i, id;
    unsigned char buf[16];
    unsigned char res;
    buf[0] = 1;
    buf[1] = 3;
    buf[2] = 0x9f;
    FUN_CODE_c0be(buf, 2, 1);
    if (buf[3] == 0xef && buf[4] == 0x40) {
        id = FUN_CODE_c44e(buf, (void code *)0xcb8c);
        if (id == 0xff) {
            res = 2;
        } else {
            res = 0;
            DAT_EXTMEM_0640 = DAT_CODE_cb8c[id];
            FUN_CODE_da8a(0xf067, DAT_EXTMEM_0640.b[2]);
            return res;
        }
    }
    for (i = 0; i < 3; i++) {
        FUN_CODE_da8a(0xf068, DAT_CODE_cbd6[i]);
        FUN_CODE_e2da();
        for (j = 0; j < 3; j++) buf[j] = FUN_CODE_e105(0xf064 + j);
        id = FUN_CODE_b044(buf, (void code *)0xcb8c);
        if (id != 0xff) break;
    }
    if (id == 0xff) {
        res = 2;
    } else {
        res = 0;
        DAT_EXTMEM_0640 = DAT_CODE_cb8c[id];
        FUN_CODE_da8a(0xf067, DAT_EXTMEM_0640.b[2]);
    }
    return res;
}


void FUN_CODE_e3ab(void);
void FUN_CODE_e44b(unsigned char t);

void FUN_CODE_c0be(unsigned char *buf, unsigned char n, unsigned char m)
{
    unsigned char i;
    FUN_CODE_da8a(0xf0c0, ((n >> 1) << 4) | 3);
    FUN_CODE_da8a(0xf0c1, 0xa7);
    FUN_CODE_da8a(0xf0c2, 0);
    FUN_CODE_da8a(0xf0c3, 0xa7);
    FUN_CODE_da8a(0xf0c4, n);
    FUN_CODE_da8a(0xf0c5, 0xa7);
    FUN_CODE_da8a(0xf0c6, n + m);
    for (i = 0; i < n + m; i++) FUN_CODE_da8a(0xa700 + i, buf[i]);
    FUN_CODE_e3ab();
    FUN_CODE_e44b(0x14);
    for (i = 0; i < 0x10; i++) buf[i] = FUN_CODE_e105(0xa700 + i);
}

unsigned char FUN_CODE_da8a(unsigned int reg, unsigned char val)
{
    unsigned char r;
    DAT_EXTMEM_0436[0] = 4;
    DAT_EXTMEM_0436[1] = 0x78;
    DAT_EXTMEM_0436[2] = reg >> 8;
    DAT_EXTMEM_0436[3] = reg;
    DAT_EXTMEM_0436[4] = val;
    r = FUN_CODE_bfcf(0x6e, 5, DAT_EXTMEM_0436);
    FUN_CODE_d059(100);
    FUN_CODE_e4b9();
    return r;
}

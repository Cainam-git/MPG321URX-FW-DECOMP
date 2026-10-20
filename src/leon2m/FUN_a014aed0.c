/* leon2m FUN_a014aed0 @ 0xa014aed0-0xa014af84 (45 words).
 * Same flash descriptor lookup as FUN_a014ac28 (group 0x30; id 0x30 gives device 0 and size limit 0x8000, any
 * other id device 0xff), but calls FUN_a0140e74(device, addr, len, buf, 1) (writes) when the access fits, and logs "SYSAPI_WriteEEPROM : DG Unknow or exceed size
 * limit!!!!!" (string 0x1a7230) otherwise.
 */
extern int FUN_a00df170(const char *fmt, ...);
extern unsigned int FUN_a00dd614(unsigned int);
extern void FUN_a0140e74(unsigned char dev, unsigned short addr, unsigned short len, unsigned char *buf, unsigned char flag);
extern const char s_001a7230[];

struct FlashDesc {
    unsigned char dev;
    unsigned short limit;
};

unsigned char FUN_a014aed0(unsigned char id, unsigned char *buf, unsigned short addr, unsigned short len)
{
    struct FlashDesc d;
    unsigned char ok = 0;

    d.dev = 0xff;

    if ((id & 0xf0) == 0x30) {
        if (id == 0x30) {
            d.dev = 0;
            d.limit = 0x8000;
        } else {
            d.dev = 0xff;
            d.limit = 0;
        }
    } else {
        d.dev = 0xff;
        d.limit = 0;
    }
    if (d.dev != 0xff && addr + len <= d.limit) {
        FUN_a0140e74(d.dev, addr, len, buf, 1);
        ok = 1;
    } else if (FUN_a00dd614(0x40) & 0xff)
        FUN_a00df170(s_001a7230);
    return ok & 1;
}

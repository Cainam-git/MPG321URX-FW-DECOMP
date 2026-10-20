/* leon2m FUN_a014ac28 @ 0xa014ac28-0xa014acdc (45 words).
 * Looks up a flash descriptor for id: for id 0x30 inside the group (id & 0xf0) == 0x10 the device byte is 0 and the
 * size limit 0x8000; for any other id the device byte is 0xff and the limit 0 (the 0x30 test can never succeed
 * inside group 0x10, but the code keeps it). When the device byte is not 0xff and addr + len does not exceed the
 * limit, FUN_a0140360(device, addr, len, buf) is called and 1 is returned. Otherwise, when FUN_a00dd614(0x40) is
 * non-zero, "SYSAPI_LoadUSRFlashType2 : DG Unknow or exceed size limit!!!!!" (string 0x1a7110) is logged, and 0 is
 * returned. The descriptor is a local structure that stays in memory; its device byte starts as 0xff.
 */
extern int FUN_a00df170(const char *fmt, ...);
extern unsigned int FUN_a00dd614(unsigned int);
extern void FUN_a0140360(unsigned char dev, unsigned short addr, unsigned short len, unsigned char *buf);
extern const char s_001a7110[];

struct FlashDesc {
    unsigned char dev;
    unsigned short limit;
};

unsigned char FUN_a014ac28(unsigned char id, unsigned char *buf, unsigned short addr, unsigned short len)
{
    struct FlashDesc d;
    unsigned char ok = 0;

    d.dev = 0xff;

    if ((id & 0xf0) == 0x10) {
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
        FUN_a0140360(d.dev, addr, len, buf);
        ok = 1;
    } else if (FUN_a00dd614(0x40) & 0xff)
        FUN_a00df170(s_001a7110);
    return ok & 1;
}

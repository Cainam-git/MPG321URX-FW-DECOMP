/* leon2m FUN_a014ae1c @ 0xa014ae1c-0xa014aed0 (45 words).
 * Template FUN_a014ac28: Looks up a flash descriptor for id and reads len bytes at addr with FUN_a0140360 when it
 * fits, else logs an error.
 * This function is the same code as FUN_a014ac28 (its source comment explains the details), compiled with
 * other constants (template -> this function):
 * 0x10 -> 0x30, 0x1a7110 -> 0x1a71e8
 */
extern int FUN_a00df170(const char *fmt, ...);
extern unsigned int FUN_a00dd614(unsigned int);
extern void FUN_a0140360(unsigned char dev, unsigned short addr, unsigned short len, unsigned char *buf);
extern const char s_001a71e8[];

struct FlashDesc {
    unsigned char dev;
    unsigned short limit;
};

unsigned char FUN_a014ae1c(unsigned char id, unsigned char *buf, unsigned short addr, unsigned short len)
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
        FUN_a0140360(d.dev, addr, len, buf);
        ok = 1;
    } else if (FUN_a00dd614(0x40) & 0xff)
        FUN_a00df170(s_001a71e8);
    return ok & 1;
}

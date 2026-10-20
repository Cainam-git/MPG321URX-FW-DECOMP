/* FUN_a014ab74: checks the request (area code p, offset off, length len) against a static area table helper: only
 * p == 0x30 with (p & 0xf0) == 0x00 is known (area 0, size 0x8000);
 * the two tests cannot both hold, so every p takes the unknown-area path. Unknown area or off + len > size: when
 * FUN_a00dd614(0x40) is non-zero it prints the "SYSAPI_SaveUSRFlashType1 : DG Unknow or exceed size limit!!!!!" message
 * (s_001a70c0) and returns 0. Otherwise calls FUN_a0140e74(area, off, len, buf, 0) and returns 1 (_Bool).
 * The area helper fills a local struct (kept on the stack) with 0xff/0 and then a nested switch on (p & 0xf0)
 * and p; GCC inlines it at -O3. No direct callers were found (the address may be reached through a pointer).
 */
struct Area { unsigned char idx; unsigned short size; };
extern unsigned char FUN_a00dd614(unsigned int level);
extern int FUN_a0140e74();
extern int FUN_a00df170();
extern char s_001a70c0[];

static void area(unsigned char p, struct Area *a)
{
    a->idx = 0xff;
    a->size = 0;
    switch (p & 0xf0) {
    case 0x00:
        switch (p) {
        case 0x30:
            a->idx = 0;
            a->size = 0x8000;
            break;
        }
        break;
    }
}

_Bool FUN_a014ab74(unsigned char p, unsigned char *buf, unsigned short off, unsigned short len)
{
    struct Area a;
    _Bool r = 0;

    area(p, &a);
    if (a.idx == 0xff || off + len > a.size) {
        if (FUN_a00dd614(0x40))
            FUN_a00df170(s_001a70c0);
    } else {
        FUN_a0140e74(a.idx, off, len, buf, 0);
        r = 1;
    }
    return r;
}

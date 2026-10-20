/* FUN_a014aaa0: checks the request (area code p, offset off, length len) against the static area helper of
 * FUN_a014ab74 (p == 0x30 with (p & 0xf0) == 0x00 gives area 0, size 0x8000;
 * the two tests cannot both hold, so every p takes the unknown-area path). Unknown area or off + len > size: when
 * FUN_a00dd614(0x40) is non-zero it prints "SYSAPI_LoadUSRFlashType1 : DG Unknow or exceed size limit!!!!!"
 * (s_001a7070) and returns 0. Otherwise, when FUN_a0140304(area) == 1, calls FUN_a0140360(area, 0, len, buf)
 * and returns 1; else 0 (_Bool). The area helper is inlined at -O3. No direct callers were found.
 */
struct Area { unsigned char idx; unsigned short size; };
extern unsigned char FUN_a00dd614(unsigned int level);
extern unsigned char FUN_a0140304(unsigned char dev);
extern void FUN_a0140360(unsigned char dev, unsigned short addr, unsigned short len, unsigned char *buf);
extern int FUN_a00df170();
extern char s_001a7070[];

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

_Bool FUN_a014aaa0(unsigned char p, unsigned char *buf, unsigned short off, unsigned short len)
{
    struct Area a;
    _Bool r = 0;

    area(p, &a);
    if (a.idx == 0xff || off + len > a.size) {
        if (FUN_a00dd614(0x40))
            FUN_a00df170(s_001a7070);
    } else {
        if (FUN_a0140304(a.idx) == 1) {
            r = 1;
            FUN_a0140360(a.idx, 0, len, buf);
        }
    }
    return r;
}

/* FUN_a014ad90: looks up area code p with the static area helper of FUN_a014ab74 (here only p == 0x30 with
 * (p & 0xf0) == 0x10, i.e. never). Unknown area: when FUN_a00dd614(0x40) is non-zero it prints
 * "SYSAPI_EraseUSRFlashType2 : DG Unknow!!!!!" (s_001a71b0) and returns 0. Otherwise calls FUN_a0140500(area)
 * (one argument; the second parameter buf is not used) and returns 1 (_Bool). No direct callers were found.
 */
struct Area { unsigned char idx; unsigned short size; };
extern unsigned char FUN_a00dd614(unsigned int level);
extern void FUN_a0140500(unsigned char dev);
extern int FUN_a00df170();
extern char s_001a71b0[];

static void area(unsigned char p, struct Area *a)
{
    a->idx = 0xff;
    a->size = 0;
    switch (p & 0xf0) {
    case 0x10:
        switch (p) {
        case 0x30:
            a->idx = 0;
            a->size = 0x8000;
            break;
        }
        break;
    }
}

_Bool FUN_a014ad90(unsigned char p, unsigned char *buf)
{
    struct Area a;
    _Bool r = 0;

    area(p, &a);
    if (a.idx == 0xff) {
        if (FUN_a00dd614(0x40))
            FUN_a00df170(s_001a71b0);
    } else {
        FUN_a0140500(a.idx);
        r = 1;
    }
    return r;
}

/* FUN_a01454c4 (leon2m 0xa01454c4-0xa0145508, 68 bytes, leaf), flags -mcpu=v8 -O3 -g -msoft-float.
 * Calls FUN_a01539b8() for c = 2 and FUN_a0153a5c() for c above 3, as tail calls; c = 0, 1 or 3 returns at once.
 * Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It lies between
 * FUN_a0145360 and FUN_a0145508. Source form: a switch with explicit empty cases 0, 1 and 3.
 */
extern void FUN_a0153a5c(void);
extern void FUN_a01539b8(void);

void FUN_a01454c4(unsigned char c)
{
    switch (c) {
    case 0:
    case 1:
    case 3:
        break;
    case 2:
        FUN_a01539b8();
        break;
    default:
        FUN_a0153a5c();
        break;
    }
}

/* FUN_a00d0e48 (leon2m 0xa00d0e48-0xa00d0f68, 288 bytes), flags -mcpu=v8 -O3 -g.
 * Stores p[0] = 0x6e; for mode 0 p[1] = 0x86, p[2] = 0xc0; for mode 1 p[1] = 0x86, 0x93, 0xc5 or 0x95 chosen from
 * req[3] (and req[6] == 0x40) and p[2] = 0xd0; then copies req[3..6] to p[3..6]. Source form: an else-if chain with
 * one compare per value (only the first pair, 0x63 || 0x31 and 0x34 || 0x30, is one condition).
 * Source form: each p[1] value group is one || condition on req[3] (the same form as its inlined copy in
 * FUN_a00d3650).
 */
void FUN_a00d0e48(const unsigned char *req, unsigned char *p, unsigned char mode)
{
    p[0] = 0x6e;
    if (mode == 0) {
        p[1] = 0x86;
        p[2] = 0xc0;
    } else if (mode == 1) {
        if (req[3] == 0x63 ||
            req[3] == 0x31 ||
            req[3] == 0x32 ||
            req[3] == 0x27 ||
            req[3] == 0x28 ||
            req[3] == 0x35 ||
            req[3] == 0x36 ||
            req[3] == 0x39 ||
            req[3] == 0x3a)
            p[1] = 0x86;
        else if (req[3] == 0x34 ||
                 req[3] == 0x30 ||
                 req[3] == 0x38 ||
                 req[3] == 0x3c)
            p[1] = 0x93;
        else if (req[6] == 0x40)
            p[1] = 0xc5;
        else
            p[1] = 0x95;
        p[2] = 0xd0;
    }
    p[3] = req[3];
    p[4] = req[4];
    p[5] = req[5];
    p[6] = req[6];
}


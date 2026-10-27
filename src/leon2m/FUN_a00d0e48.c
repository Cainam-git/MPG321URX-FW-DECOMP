/* FUN_a00d0e48 (leon2m 0xa00d0e48-0xa00d0f68, 288 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Stores p[0] = 0x6e; for mode 0 p[1] = 0x86, p[2] = 0xc0; for mode 1 p[1] = 0x86, 0x93, 0xc5 or 0x95 chosen from
 * req[3] (and req[6] == 0x40) and p[2] = 0xd0; then copies req[3..6] to p[3..6]. Nothing in the image refers to it:
 * no call, branch, sethi/or constant or address word. It lies between FUN_a00cfacc and FUN_a00d0f68. Source form:
 * an else-if chain with one compare per value (only the first pair, 0x63 || 0x31 and 0x34 || 0x30, is one
 * condition).
 */
void FUN_a00d0e48(const unsigned char *req, unsigned char *p, unsigned char mode)
{
    unsigned char c;

    p[0] = 0x6e;
    if (mode == 0) {
        p[1] = 0x86;
        p[2] = 0xc0;
    } else if (mode == 1) {
        c = req[3];
        if (c == 0x63 || c == 0x31)
            p[1] = 0x86;
        else if (c == 0x32)
            p[1] = 0x86;
        else if (c == 0x27)
            p[1] = 0x86;
        else if (c == 0x28)
            p[1] = 0x86;
        else if (c == 0x35)
            p[1] = 0x86;
        else if (c == 0x36)
            p[1] = 0x86;
        else if (c == 0x39)
            p[1] = 0x86;
        else if (c == 0x3a)
            p[1] = 0x86;
        else if (c == 0x34 || c == 0x30)
            p[1] = 0x93;
        else if (c == 0x38)
            p[1] = 0x93;
        else if (c == 0x3c)
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

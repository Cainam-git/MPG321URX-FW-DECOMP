/* FUN_a012cf1c (leon2m 0xa012cf1c-0xa012cf64, 72 bytes, leaf), flags -mcpu=v8 -O3 -g -msoft-float.
 * Searches the first 11 entries of the {key, value} halfword table DAT_001a5198 for key c and returns the value of
 * the matching entry (of entry 11 when none matches). Nothing in the image refers to it: no call, branch, sethi/or
 * constant or address word. It lies between FUN_a012cf10 and FUN_a012cf64.
 */
struct KV { unsigned short key, val; };
extern const struct KV DAT_001a5198[];

unsigned short FUN_a012cf1c(unsigned char c)
{
    unsigned char i;

    for (i = 0; i < 11; i++)
        if (c == DAT_001a5198[i].key)
            break;
    return DAT_001a5198[i].val;
}

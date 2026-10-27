/* FUN_a012cf64 (leon2m 0xa012cf64-0xa012cfac, 72 bytes, leaf), flags -mcpu=v8 -O3 -g -msoft-float.
 * Searches the first 12 entries of the {key, value} halfword table DAT_001a5168 for key c and returns the value of
 * the matching entry (of entry 12 when none matches). Nothing in the image refers to it: no call, branch, sethi/or
 * constant or address word. It lies between FUN_a012cf1c and FUN_a012cfac.
 */
struct KV { unsigned short key, val; };
extern const struct KV DAT_001a5168[];

unsigned short FUN_a012cf64(unsigned char c)
{
    unsigned char i;

    for (i = 0; i < 12; i++)
        if (c == DAT_001a5168[i].key)
            break;
    return DAT_001a5168[i].val;
}

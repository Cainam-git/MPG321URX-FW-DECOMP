/* FUN_a00295ec (leon2m 0xa00295ec-0xa00295f4, 8 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Returns its byte argument (and 0xff in the retl delay slot). Nothing in the image refers to it: no call, branch,
 * sethi/or constant or address word. It lies between FUN_a00295e4 and FUN_a00295f4. Source form: an unsigned char
 * parameter returned as unsigned char.
 */
unsigned char FUN_a00295ec(unsigned char c)
{
    return c;
}

/* FUN_a00fc318 (leon2m 0xa00fc318-0xa00fc334, 28 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Writes 1 to the word register 0xcf012034, then clears the byte DAT_a802c97c. Nothing in the image refers to it:
 * no call, branch, sethi/or constant or address word. It lies between FUN_a00fc30c and FUN_a00fc334.
 */
#define REG (*(volatile unsigned int *)0xcf012034)
extern unsigned char DAT_a802c97c;

void FUN_a00fc318(void)
{
    REG = 1;
    DAT_a802c97c = 0;
}

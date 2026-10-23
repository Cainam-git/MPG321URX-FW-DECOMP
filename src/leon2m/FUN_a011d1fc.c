/* FUN_a011d1fc (leon2m 0xa011d1fc-0xa011d214, 24 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Writes 6 to the word register 0xcf03c374. Nothing in the image refers to it: no call, branch, sethi/or constant
 * or address word. It lies between FUN_a011d194 and switchdataD_a011d214. Source form: a volatile register store
 * (the store stays before retl).
 */
#define R (*(volatile unsigned int *)0xcf03c374)

void FUN_a011d1fc(void)
{
    R = 6;
}

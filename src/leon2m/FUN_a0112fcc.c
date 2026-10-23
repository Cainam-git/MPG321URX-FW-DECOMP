/* FUN_a0112fcc (leon2m 0xa0112fcc-0xa0112fe0, 20 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Writes 0 to the word register 0xcf011d8c. Nothing in the image refers to it: no call, branch, sethi/or constant
 * or address word. It lies between FUN_a0112fb8 and FUN_a0112fe0. Source form: a volatile register store (the store
 * stays before retl).
 */
#define R (*(volatile unsigned int *)0xcf011d8c)

void FUN_a0112fcc(void)
{
    R = 0;
}

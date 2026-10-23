/* FUN_a0109b58 (leon2m 0xa0109b58-0xa0109b70, 24 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Writes 0xa0 to the word register 0xcf011cc4. Nothing in the image refers to it: no call, branch, sethi/or
 * constant or address word. It lies between FUN_a0109b14 and FUN_a0109b70. Source form: a volatile register store
 * (the store stays before retl).
 */
#define R (*(volatile unsigned int *)0xcf011cc4)

void FUN_a0109b58(void)
{
    R = 0xa0;
}

/* leon2m FUN_a0121258 @ 0xa0121258 (-mcpu=v8 -O2 -g)
 * Returns 1 when bit 2 of FUN_a00f1a90(p, 0) (register 0 of input block p) is set, else 0.
 */
extern int FUN_a00f1a90(unsigned char, int);

int FUN_a0121258(unsigned char param_1) {
    int result = FUN_a00f1a90(param_1, 0);
    return (result & 4) == 0 ? 0 : 1;
}

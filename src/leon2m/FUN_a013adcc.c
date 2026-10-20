/* leon2m FUN_a013adcc @ 0xa013adcc  MATCH (-mcpu=v8 -O2 -g, twin)
 * Twin of FUN_a0138eb4: same code, constants swapped; byte-exact.
 * See FUN_a0138eb4 for the explanation; this copy's constants differ, so its comments were removed.
 */
extern int FUN_a013ab9c();

void FUN_a013adcc(void)
{
    unsigned char buf[4] = {0, 0, 0, 0};
    FUN_a013ab9c(0x95, 4, buf, 0);
}

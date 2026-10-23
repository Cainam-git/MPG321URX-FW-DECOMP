/* leon2m FUN_a013adcc @ 0xa013adcc (-mcpu=v8 -O2 -g)
 * Calls FUN_a013ab9c(0x95, 4, buf, 0) with four local zero bytes. Same code as FUN_a0138eb4 with other constants.
 * See FUN_a0138eb4 for the explanation; this copy's constants differ, so its comments were removed.
 */
extern int FUN_a013ab9c();

void FUN_a013adcc(void)
{
    unsigned char buf[4] = {0, 0, 0, 0};
    FUN_a013ab9c(0x95, 4, buf, 0);
}

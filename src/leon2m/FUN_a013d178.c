/* leon2m FUN_a013d178 @ 0xa013d178 (-mcpu=v8 -O2 -g)
 * Returns 1 when byte 0xA802E1A7 is above 4, else 0.
 */
extern unsigned char DAT_a802e1a7;

int FUN_a013d178(void)
{
    if (DAT_a802e1a7 <= 4)
        return 0;
    return 1;
}

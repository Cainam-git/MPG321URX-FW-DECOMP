/* leon2m FUN_a01486a8 @ 0xa01486a8 (-mcpu=v8 -Os -g)
 * Forwards its three arguments (cmd, len, buffer) to FUN_a0133b54(cmd, len, buffer) as a tail call; len is
 * passed on as an unsigned short. Callers: FUN_a0088724, FUN_a0089f6c, FUN_a00d2a98, FUN_a00d3650.
 */
extern void FUN_a0133b54(unsigned char cmd, unsigned short len, unsigned char *p);

void FUN_a01486a8(unsigned char cmd, unsigned short len, unsigned char *buf)
{
    FUN_a0133b54(cmd, len, buf);
}

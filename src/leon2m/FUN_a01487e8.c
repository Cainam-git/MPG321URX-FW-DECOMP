/* leon2m FUN_a01487e8 @ 0xa01487e8 (-mcpu=v8 -Os -g)
 * Forwards its three arguments (port, len, buffer) to FUN_a01337e8(port, len, buffer) as a tail call; len is
 * passed on as an unsigned short. Callers: FUN_a00ca878, FUN_a00c573c, FUN_a00bf110 and other handlers.
 */
extern void FUN_a01337e8(unsigned char cmd, unsigned short len, unsigned char *p);

void FUN_a01487e8(unsigned char port, unsigned short len, unsigned char *buf)
{
    FUN_a01337e8(port, len, buf);
}

/* leon2m FUN_a00babe4 @ 0xa00babe4 (-mcpu=v8 -O2 -g)
 * Calls FUN_a01487e8(port, len, DAT_a802d078) as a tail call: the same three-argument call with the buffer fixed to
 * the byte array at 0xa802d078. Both parameters are bytes (masked with 0xff before the call); FUN_a01487e8 takes
 * len as an unsigned short. Callers: the handlers from FUN_a00bc86c to FUN_a00be7d4 and FUN_a00bfcc4.
 */
extern unsigned char DAT_a802d078[];
extern void FUN_a01487e8(unsigned char, unsigned short, unsigned char *);

void FUN_a00babe4(unsigned char port, unsigned char len)
{
    FUN_a01487e8(port, len, DAT_a802d078);
}

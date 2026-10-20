/* leon2m FUN_a0083abc @ 0xa0083abc  MATCH (-mcpu=v8 -O2 -g)
 * Calls FUN_a008380c and tail-calls FUN_a0148eb4 with bit 1 of its result and param_2; param_1 is unused. The void
 * prototype of FUN_a008380c leaves a nop in the call delay slot, and the unsigned type gives a logical srl.
 */
extern int FUN_a008380c(void); /* 0xa008380c */
extern void FUN_a0148eb4(unsigned char param_1, unsigned int param_2); /* 0xa0148eb4 */

void FUN_a0083abc(unsigned int param_1, unsigned int param_2)
{
    unsigned int val = FUN_a008380c();
    FUN_a0148eb4((val >> 1) & 1, param_2);
}

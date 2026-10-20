/* leon2m FUN_a008a210 @ 0xa008a210, flags -mcpu=v8 -O3 -g
 * APP main step: empties the event queue (read index DAT_a802afa0, count DAT_a802afa1), runs the APP event
 * generator FUN_a0080c10 and three more producers, then pops each queued event from DAT_a802afa8[]
 * (at most 10) and hands it to the action dispatcher FUN_a008454c and three more consumers.
 */
extern unsigned char DAT_a802afa0;
extern unsigned char DAT_a802afa1;
extern unsigned char DAT_a802afa8[];
extern void FUN_a0080c10();
extern void FUN_a00a012c();
extern void FUN_a008e7b0();
extern void FUN_a008a09c();
extern void FUN_a008454c(unsigned int ev);
extern void FUN_a009eb38();
extern void FUN_a008e7a8();
extern void FUN_a008a034();

void FUN_a008a210(void)
{
    unsigned char ev;

    DAT_a802afa0 = 0;
    DAT_a802afa1 = 0;
    FUN_a0080c10();
    FUN_a00a012c();
    FUN_a008e7b0();
    FUN_a008a09c();
    while (DAT_a802afa1 != 0 && DAT_a802afa0 <= 9) {
        ev = DAT_a802afa8[DAT_a802afa0++];
        if (DAT_a802afa1 != 0)
            DAT_a802afa1--;
        FUN_a008454c(ev);
        FUN_a009eb38(ev);
        FUN_a008e7a8(ev);
        FUN_a008a034(ev);
    }
}

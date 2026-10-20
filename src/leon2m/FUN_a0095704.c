/* leon2m FUN_a0095704 @ 0xa0095704  MATCH (-mcpu=v8 -O2 -g)
 * 
 */
extern unsigned char DAT_a8025c55;
extern unsigned char DAT_a802b08e;
extern unsigned char DAT_a802d40b;
extern unsigned int _DAT_a802afec;
extern int FUN_a00a82c4();
extern int FUN_a00a8c88();
extern void FUN_a00a9468();
extern void FUN_a00a9650();
extern int FUN_a00b34d4();
extern int FUN_a00ba184();

void FUN_a0095704(void) {
    FUN_a00a8c88();
    FUN_a00a82c4();
    DAT_a802d40b = DAT_a8025c55;
    FUN_a00ba184(1);
    _DAT_a802afec = 0x40;
    FUN_a00a9650(1, 1);
    FUN_a00a9468(1, 2);
    FUN_a00b34d4(0, 1);
    DAT_a802b08e = DAT_a802b08e | 2;
}

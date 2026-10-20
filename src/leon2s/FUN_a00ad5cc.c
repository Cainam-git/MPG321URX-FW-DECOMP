/* leon2s FUN_a00ad5cc @ 0xa00ad5cc  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, permuter)
 * reached byte-exact by tools/permuter.py: 
 */
extern unsigned char DAT_a8079312;
extern unsigned char DAT_a8079313;
extern void FUN_a00acff4(void);
extern int FUN_a00ad3e0(int);

void FUN_a00ad5cc(void)
{
    if (DAT_a8079313 == 0) {
        return;
    }
    if ((FUN_a00ad3e0(0) & 0xff) == 1) {
        DAT_a8079312 = DAT_a8079312 | 1;
    }
    if ((FUN_a00ad3e0(1) & 0xff) == 1) {
        DAT_a8079312 = DAT_a8079312 | 2;
    }
    FUN_a00acff4();
}

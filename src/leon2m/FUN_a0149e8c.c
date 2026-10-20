/* leon2m FUN_a0149e8c @ 0xa0149e8c (-mcpu=v8 -O2 -g)
 * 
 */
// FUN_a0149e8c at 0xa0149e8c
extern int FUN_a00df170();
extern int FUN_a0109474();
extern int FUN_a012f1ec();
extern int FUN_a013cda8(unsigned int);
extern int FUN_a013d684();
extern int FUN_a013d918();
extern int func_0x4008d1a0();

void FUN_a0149e8c(unsigned char param_1)
{
    unsigned char uVar1;
    
    switch (param_1) {
    case 1:
        uVar1 = 1;
        break;
    case 2:
        uVar1 = 2;
        break;
    case 3:
        uVar1 = 3;
        break;
    case 0:
        uVar1 = 0;
        break;
    default:
        uVar1 = 0xff;
        break;
    }
    
    uVar1 = uVar1 & 0xff;
    if (uVar1 > 3) {
        FUN_a00df170(0x1a6dd8);
        uVar1 = 0;
    }
    
    FUN_a012f1ec(uVar1, 3);
    FUN_a0109474(FUN_a013cda8(uVar1) & 0xff, 0);
    FUN_a013d684(uVar1);
    FUN_a013d918(uVar1);
    func_0x4008d1a0(100);
    FUN_a0109474(FUN_a013cda8(uVar1) & 0xff, 1);
}

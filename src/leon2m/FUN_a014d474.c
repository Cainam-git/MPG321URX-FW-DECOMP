/* leon2m FUN_a014d474 @ 0xa014d474  MATCH (-mcpu=v8 -O2 -g)
 * Maps param_1 = 0..3 to itself and any other value to 0xFF; for a result above 3 it calls
 * FUN_a00df170(0x1A6DD8) and uses 0 instead. Ends with FUN_a0109474(FUN_a013cda8(v) & 0xFF, param_2) as a tail
 * call (restore in the delay slot). The switch lists the cases in the order 1, 0, 2, 3, which is the branch order
 * of the firmware.
 */
extern int FUN_a00df170();
extern int FUN_a0109474();
extern int FUN_a013cda8(unsigned int);

void FUN_a014d474(unsigned char param_1, unsigned char param_2)
{
    unsigned char uVar1;
    
    switch (param_1) {
    case 1:
        uVar1 = 1;
        break;
    case 0:
        uVar1 = 0;
        break;
    case 2:
        uVar1 = 2;
        break;
    case 3:
        uVar1 = 3;
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
    
    FUN_a0109474(FUN_a013cda8(uVar1) & 0xff, param_2);
    return 0;
}

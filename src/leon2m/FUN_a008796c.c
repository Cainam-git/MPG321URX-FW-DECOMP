/* leon2m FUN_a008796c @ 0xa008796c  first initialisation step of main(): register ten callbacks (flags
 * -mcpu=v8 -O3 -g, gcc 3.4.4).
 * Calls FUN_a0143700(n, handler) for n = 2, 3, 6, 10, 11, 7, 8, 12, 14, 15 (the last call is a tail call). The
 * handlers are run-time addresses of the RAM copy the program executes from (written func_0x... = literal address;
 * firmware address = value + 0xA0060000): 2 -> 0xA009108C, 3 -> FUN_a00d6054, 6 -> FUN_a00830f4, 10 -> FUN_a0083aa0,
 * 11 -> FUN_a0083abc, 7 -> FUN_a0083b14, 8 -> FUN_a0083b60, 12 -> FUN_a0083adc, 14 -> 0xA0083BE0, 15 -> FUN_a0080af0.
 * FUN_a0083aa0 / FUN_a0083abc are the two that pass APPGetFRCMode() bits 0 / 1 to the FRC lock / mode set-up;
 * they run as these registered callbacks.
 */
extern void FUN_a0143700(int irq, void (*handler)(void));
extern void func_0x0003108c(void);
extern void func_0x00076054(void);
extern void func_0x000230f4(void);
extern void func_0x00023aa0(void);
extern void func_0x00023abc(void);
extern void func_0x00023b14(void);
extern void func_0x00023b60(void);
extern void func_0x00023adc(void);
extern void func_0x00023be0(void);
extern void func_0x00020af0(void);
void FUN_a008796c(void)
{
    FUN_a0143700(2, func_0x0003108c);
    FUN_a0143700(3, func_0x00076054);
    FUN_a0143700(6, func_0x000230f4);
    FUN_a0143700(10, func_0x00023aa0);
    FUN_a0143700(11, func_0x00023abc);
    FUN_a0143700(7, func_0x00023b14);
    FUN_a0143700(8, func_0x00023b60);
    FUN_a0143700(12, func_0x00023adc);
    FUN_a0143700(14, func_0x00023be0);
    FUN_a0143700(15, func_0x00020af0);
}

/* leon2m FUN_a0148500 @ 0xa0148500  re-apply the active row's nominal rate to the FRC set-up
 * Flags: -mcpu=v8 -O3 -g and -O3 -msoft-float.
 *
 * rate = halfword +0x52 of the raw active panel row 0xA802E378 (= 0xA802E3CA: 2400 / 1200 / 600 tenths of Hz for rows
 * 0 / 1 / 2). Calls FRCConfigPostFRC FUN_a0107e44(0xA802E3D3 != 0, rate, 1), then tail-calls FUN_a0109bbc(0, 0, 0,
 * rate) (FRC lock / free-run set-up). Change-rule reader of the panel row (scorecard row 1c): after a row change
 * it programs the output side from the NEW row's nominal rate, never from the measured input.
 */
struct RawRow { unsigned char b00[0x52]; unsigned short rate; unsigned char b54[4]; };
extern struct RawRow DAT_a802e378;
extern unsigned char DAT_a802e3d3;
extern void FUN_a0107e44(int, unsigned short, int);
extern void FUN_a0109bbc(int, int, int, unsigned short);

void FUN_a0148500(void)
{
    FUN_a0107e44(DAT_a802e3d3 != 0, DAT_a802e378.rate, 1);
    FUN_a0109bbc(0, 0, 0, DAT_a802e378.rate);
}

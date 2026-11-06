/* leon2s FUN_a009ea34 @ 0xa009ea34 (-mcpu=v8 -Os -g)
 * m = p2 & 0xff. Mode 1 prints DAT_a006af70, modes 2 and 3 DAT_a006af90, mode 4 DAT_a006afb0, mode 5 DAT_a006afd0,
 * mode 6 DAT_a006aff0 (FUN_a0073044), then rewrites register 0xCF01474C with k = 0 (mode 1), 1 (modes 2, 3),
 * 2 (mode 4), 3 (mode 5), 4 (mode 6): p1 0 -> (reg & 0xf0) | k; p1 1 -> (reg & 0x0f) | k << 4 (mode 1 only
 * masks). Other modes change nothing. Jump table switchdataD_a009ea1c (index m - 1, entries 1 and 2 = the
 * modes 2/3 arm). volatile: hardware register.
 */

extern unsigned int DAT_a006af70;
extern unsigned int DAT_a006af90;
extern unsigned int DAT_a006afb0;
extern unsigned int DAT_a006afd0;
extern unsigned int DAT_a006aff0;
extern int FUN_a0073044();
void FUN_a009ea34(unsigned char param_1, unsigned int param_2)
{
  switch (param_2 & 0xff)
  {
  case 1:
    FUN_a0073044(&DAT_a006af70);
    if (param_1 == 0)
    {
      *((volatile unsigned int *) 0xcf01474c) = *((volatile unsigned int *) 0xcf01474c) & 0xf0;
    }
    else if (param_1 == 1)
    {
      *((volatile unsigned int *) 0xcf01474c) = *((volatile unsigned int *) 0xcf01474c) & 0xf;
    }
    break;
  case 2:
  case 3:
    FUN_a0073044(&DAT_a006af90);
    if (param_1 == 0)
    {
      *((volatile unsigned int *) 0xcf01474c) = *((volatile unsigned int *) 0xcf01474c) & 0xf0;
      *((volatile unsigned int *) 0xcf01474c) = *((volatile unsigned int *) 0xcf01474c) | 1;
    }
    else if (param_1 == 1)
    {
      *((volatile unsigned int *) 0xcf01474c) = *((volatile unsigned int *) 0xcf01474c) & 0xf;
      *((volatile unsigned int *) 0xcf01474c) = *((volatile unsigned int *) 0xcf01474c) | 0x10;
    }
    break;
  case 4:
    FUN_a0073044(&DAT_a006afb0);
    if (param_1 == 0)
    {
      *((volatile unsigned int *) 0xcf01474c) = *((volatile unsigned int *) 0xcf01474c) & 0xf0;
      *((volatile unsigned int *) 0xcf01474c) = *((volatile unsigned int *) 0xcf01474c) | 2;
    }
    else if (param_1 == 1)
    {
      *((volatile unsigned int *) 0xcf01474c) = *((volatile unsigned int *) 0xcf01474c) & 0xf;
      *((volatile unsigned int *) 0xcf01474c) = *((volatile unsigned int *) 0xcf01474c) | 0x20;
    }
    break;
  case 5:
    FUN_a0073044(&DAT_a006afd0);
    if (param_1 == 0)
    {
      *((volatile unsigned int *) 0xcf01474c) = *((volatile unsigned int *) 0xcf01474c) & 0xf0;
      *((volatile unsigned int *) 0xcf01474c) = *((volatile unsigned int *) 0xcf01474c) | 3;
    }
    else if (param_1 == 1)
    {
      *((volatile unsigned int *) 0xcf01474c) = *((volatile unsigned int *) 0xcf01474c) & 0xf;
      *((volatile unsigned int *) 0xcf01474c) = *((volatile unsigned int *) 0xcf01474c) | 0x30;
    }
    break;
  case 6:
    FUN_a0073044(&DAT_a006aff0);
    if (param_1 == 0)
    {
      *((volatile unsigned int *) 0xcf01474c) = *((volatile unsigned int *) 0xcf01474c) & 0xf0;
      *((volatile unsigned int *) 0xcf01474c) = *((volatile unsigned int *) 0xcf01474c) | 4;
    }
    else if (param_1 == 1)
    {
      *((volatile unsigned int *) 0xcf01474c) = *((volatile unsigned int *) 0xcf01474c) & 0xf;
      *((volatile unsigned int *) 0xcf01474c) = *((volatile unsigned int *) 0xcf01474c) | 0x40;
    }
    break;
  }
}

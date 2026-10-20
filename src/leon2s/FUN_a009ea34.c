/* leon2s FUN_a009ea34 @ 0xa009ea34  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, permuter)
 * reached byte-exact by tools/permuter.py: decomp-permuter (AST mutations), judged by exact bytes
 */

extern unsigned int DAT_a006af70;
extern unsigned int DAT_a006af90;
extern unsigned int DAT_a006afb0;
extern unsigned int DAT_a006afd0;
extern unsigned int DAT_a006aff0;
extern int FUN_a0073044();
void FUN_a009ea34(unsigned char param_1, unsigned int param_2)
{
  param_2 = param_2 & 0xff;
  if ((param_2 - 1) <= 5)
  {
    param_1 = param_1 & 0xff;
    switch (param_2)
    {
      case 1:
        FUN_a0073044(&DAT_a006af70);
        if (param_1 == 0)
      {
        *((volatile unsigned int *) 0xcf01474c) = (*((volatile unsigned int *) 0xcf01474c)) & 0xf0;
      }
      else
        if (param_1 == 1)
      {
        *((volatile unsigned int *) 0xcf01474c) = (*((volatile unsigned int *) 0xcf01474c)) & 0xf;
      }
        break;

      case 2:
        FUN_a0073044(&DAT_a006af90);
        if (param_1 == 0)
      {
        *((volatile unsigned int *) 0xcf01474c) = (*((volatile unsigned int *) 0xcf01474c)) & 0xf0;
        *((volatile unsigned int *) 0xcf01474c) = (*((volatile unsigned int *) 0xcf01474c)) | 1;
      }
      else
        if (param_1 == 1)
      {
        *((volatile unsigned int *) 0xcf01474c) = (*((volatile unsigned int *) 0xcf01474c)) & 0xf;
        *((volatile unsigned int *) 0xcf01474c) = (*((volatile unsigned int *) 0xcf01474c)) | 0x10;
      }
        break;

      case 3:
        FUN_a0073044(&DAT_a006afb0);
        if (param_1 == 0)
      {
        *((volatile unsigned int *) 0xcf01474c) = (*((volatile unsigned int *) 0xcf01474c)) & 0xf0;
        *((volatile unsigned int *) 0xcf01474c) = (*((volatile unsigned int *) 0xcf01474c)) | 2;
      }
      else
        if (param_1 == 1)
      {
        *((volatile unsigned int *) 0xcf01474c) = (*((volatile unsigned int *) 0xcf01474c)) & 0xf;
        *((volatile unsigned int *) 0xcf01474c) = (*((volatile unsigned int *) 0xcf01474c)) | 0x20;
      }
        break;

      case 4:
        FUN_a0073044(&DAT_a006afd0);
        if (param_1 == 0)
      {
        *((volatile unsigned int *) 0xcf01474c) = (*((volatile unsigned int *) 0xcf01474c)) & 0xf0;
        *((volatile unsigned int *) 0xcf01474c) = (*((volatile unsigned int *) 0xcf01474c)) | 3;
      }
      else
        if (param_1 == 1)
      {
        *((volatile unsigned int *) 0xcf01474c) = (*((volatile unsigned int *) 0xcf01474c)) & 0xf;
        *((volatile unsigned int *) 0xcf01474c) = (*((volatile unsigned int *) 0xcf01474c)) | 0x30;
      }
        break;

      case 5:
        FUN_a0073044(&DAT_a006aff0);
        if (param_1 == 0)
      {
        *((volatile unsigned int *) 0xcf01474c) = (*((volatile unsigned int *) 0xcf01474c)) & 0xf0;
        *((volatile unsigned int *) 0xcf01474c) = (*((volatile unsigned int *) 0xcf01474c)) | 4;
      }
      else
        if (param_1 == 1)
      {
        *((volatile unsigned int *) 0xcf01474c) = (*((volatile unsigned int *) 0xcf01474c)) & 0xf;
        *((volatile unsigned int *) 0xcf01474c) = (*((volatile unsigned int *) 0xcf01474c)) | 0x40;
      }
        break;

      case 6:
        if (param_1)
      {
        break;
      }
      else
      {
        break;
      }

    }

  }
}

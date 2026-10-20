/* leon2m FUN_a00bfcc4 @ 0xa00bfcc4..0xa00c0adc (902 insns)  Big chip UART/tool command switch (rescue
 * path): MSI tool -> 8051 mailbox portal 0 -> FUN_a00ce348 case 2 -> FUN_a00bfcc4(4, row) -> handler.
 * -mcpu=v8 -O3 -g (also -mcpu=v8 -O3 -g -msoft-float): words; the
 * 131-entry jump table (0xA00BA428, image-relative +0xA0060000) also matches entry by entry.
 *
 * What the code does (code facts):
 * - cmd (byte) > 0x82 or a hole in the table (1, 0xb, 0xc, 0xe, 0x10, 0x11, 0x40, 0x44, 0x47, 0x48, 0x4d..0x55, 0x57..0x64,
 *   0x67, 0x69, 0x6d, 0x79..0x7b): return, nothing done.
 * - 28 commands tail-call their handler with the port byte (case 2 = FUN_a00bf110 UartSetI2CEnable, the entry of MSI's
 *   official update; 0 = FUN_a00be9a8, 3/4/5 = FUN_a00bbda0/bbf1c/bc098, 7/8/9 = bc3f8/bc574/bc6f0, ... see the switch).
 * - The other 63 commands are "read a setting" replies: bytes 7, 8, 9 of the reply frame 0xA802D078 = three ASCII digits
 *   (mostly '0', '0', '0' + value: a status byte, or one/two bits of a status word such as 0xA802D338/D33C/D46C/D484),
 *   then FUN_a00bac3c(cmd) (or FUN_a00bacc4(cmd) for 6, 0xa, 0xd, 0xf) fills bytes 0..6 and 10 from command-table row cmd,
 *   FUN_a00ba950(port), and FUN_a00babe4(port, 11) (= FUN_a01487e8(port, 11, frame)) sends 11 bytes back. Commands 6
 *   and 0x4a call FUN_a01487e8(port, 0xb, 0xA802D078) directly. 0x28/0x29/0x2b: two-digit value ('1', v - 10 + '0' when
 *   v > 9). 0x30 replies the constant "V23", 0x4a "021", 0xf "001", 0x2f "00" + 0x9F, 0x38 '2' - byte 0xA802D2C1.
 *   0x41 builds the whole frame itself (bytes 35 62 30 30 5C 30 30 30 31 31 0D = "5b00" backslash "00011" CR) and calls FUN_a00babe4(port, 0x26).
 *   0x4c: digit = bit 20 of word 0xA802D33C, or '0' when byte 0xA802D2AF != 0 (both read off one 0xA802D290 base).
 * - No loops, no hardware registers, no waits; every path returns. This is the only route from the tool command
 *   task to FUN_a00bf110; it reads no panel/timing state.
 *
 * How it was matched: every inlined case body is the standalone handler of that command (FUN_a00bc3b0 .. FUN_a00be7d4,
 * they exist uncalled in the firmware; most are byte-exact in src/leon2m) - written here directly in the case. The case
 * ORDER in the source is the order of those handlers in the firmware file (handler addresses), not the case value: it
 * sets the -frename-registers LRU ticks (descending order 28.05, ascending 28.27, handler order 63.08).
 * Fixes on top: 0x1c index held in an int (address add operand order), 0x4c test written '== 0' first (fw branch
 * sense), 0x25 halfword read into an unsigned int first (keeps lduh), 0x28/0x29/0x2b store byte 7 BEFORE reading the
 * value (pre-rename allocation of the two sethi registers; 72.39 -> 100).
 * Compiler aids: none (no branch hints, no asm labels).
 */
extern unsigned char DAT_a802cffd;
extern unsigned char DAT_a802d290[];
extern unsigned char DAT_a802d298;
extern unsigned char DAT_a802d29f;
extern unsigned char DAT_a802d2a1;
extern unsigned char DAT_a802d2a9;
extern unsigned char DAT_a802d2af;
extern unsigned char DAT_a802d2bf;
extern unsigned char DAT_a802d2c1;
extern unsigned char DAT_a802d2da;
extern unsigned char DAT_a802d2db;
extern unsigned char DAT_a802d2dc;
extern unsigned char DAT_a802d3ce;
extern unsigned char DAT_a802d3cf;
extern unsigned char DAT_a802d3d0;
extern unsigned char DAT_a802d3eb;
extern unsigned char DAT_a802d407;
extern unsigned char DAT_a802d40b;
extern unsigned char DAT_a802d40c;
extern unsigned char DAT_a802d41a;
extern unsigned char DAT_a802d41b;
extern unsigned char DAT_a802d41d;
extern unsigned char DAT_a802d420;
extern unsigned char DAT_a802d430;
extern unsigned char DAT_a802d46d;
extern unsigned char DAT_a802d46f;
extern unsigned char DAT_a802d470;
extern unsigned char DAT_a802d471;
extern unsigned char DAT_a802d478;
extern unsigned char DAT_a802d479;
extern unsigned char DAT_a802d47a;
extern unsigned char DAT_a802d47b;
extern unsigned char DAT_a802d47c;
extern unsigned char DAT_a802d47d;
extern unsigned char DAT_a802d47e;
extern unsigned int DAT_a802d340;
extern unsigned int _DAT_a802d290;
extern unsigned int _DAT_a802d2c0;
extern unsigned int _DAT_a802d338;
extern unsigned int _DAT_a802d33c;
extern unsigned int _DAT_a802d3ac;
extern unsigned int _DAT_a802d404;
extern unsigned int _DAT_a802d46c;
extern unsigned int _DAT_a802d47c;
extern unsigned int _DAT_a802d484;
extern unsigned short _DAT_a802d2c4;
extern void FUN_a00bbda0(unsigned char);
extern void FUN_a00bbf1c(unsigned char);
extern void FUN_a00bc098(unsigned char);
extern void FUN_a00bc258(unsigned char);
extern void FUN_a00bc3f8(unsigned char);
extern void FUN_a00bc574(unsigned char);
extern void FUN_a00bc6f0(unsigned char);
extern void FUN_a00bc95c(unsigned char);
extern void FUN_a00bcecc(unsigned char);
extern void FUN_a00bd070(unsigned char);
extern void FUN_a00bd328(unsigned char);
extern void FUN_a00bd59c(unsigned char);
extern void FUN_a00bd760(unsigned char);
extern void FUN_a00bd9d8(unsigned char);
extern void FUN_a00bdf28(unsigned char);
extern void FUN_a00be81c(unsigned char);
extern void FUN_a00be9a8(unsigned char);
extern void FUN_a00beae0(unsigned char);
extern void FUN_a00bec0c(unsigned char);
extern void FUN_a00bed38(unsigned char);
extern void FUN_a00bee64(unsigned char);
extern void FUN_a00bef90(unsigned char);
extern void FUN_a00bf110(unsigned char);
extern void FUN_a00bf3f8(unsigned char);
extern void FUN_a00bf538(unsigned char);
extern void FUN_a00bf6b0(unsigned char);
extern void FUN_a00bf7dc(unsigned char);
extern void FUN_a00bfb28(unsigned char);
extern void FUN_a00bac3c(unsigned char);
extern void FUN_a00bacc4(unsigned char);
extern unsigned char FUN_a00ba950(unsigned char);
extern void FUN_a00babe4(unsigned char, unsigned char);
extern void FUN_a01487e8(unsigned char, int, unsigned char *);
extern unsigned char DAT_a802d078[];

void FUN_a00bfcc4(unsigned char port, unsigned char cmd)
{
    switch (cmd) {
    case 0x3:
        FUN_a00bbda0(port);
        break;
    case 0x4:
        FUN_a00bbf1c(port);
        break;
    case 0x5:
        FUN_a00bc098(port);
        break;
    case 0x4a:
        DAT_a802d078[7] = 0x30;
        DAT_a802d078[8] = 0x32;
        DAT_a802d078[9] = 0x31;
        FUN_a00bac3c(0x4a);
        FUN_a00ba950(port);
        FUN_a01487e8(port, 0xb, DAT_a802d078);
        break;
    case 0x4b:
        FUN_a00bc258(port);
        break;
    case 0x6:
        DAT_a802d078[7] = 0x30;
        DAT_a802d078[8] = 0x30;
        DAT_a802d078[9] = (DAT_a802d2a1 + 0x30);
        FUN_a00bacc4(0x6);
        FUN_a00ba950(port);
        FUN_a01487e8(port, 0xb, DAT_a802d078);
        break;
    case 0x7:
        FUN_a00bc3f8(port);
        break;
    case 0x8:
        FUN_a00bc574(port);
        break;
    case 0x9:
        FUN_a00bc6f0(port);
        break;
    case 0xa:
        DAT_a802d078[7] = DAT_a802d290[0x12] + 0x30;
        DAT_a802d078[8] = DAT_a802d290[0x13] + 0x30;
        DAT_a802d078[9] = DAT_a802d290[0x14] + 0x30;
        FUN_a00bacc4(0xa);
        FUN_a00ba950(port);
        FUN_a00babe4(port, 0xb);
        break;
    case 0xd:
        DAT_a802d078[7] = 0x30;
        DAT_a802d078[8] = 0x30;
        DAT_a802d078[9] = (DAT_a802d298 + 0x30);
        FUN_a00bacc4(0xd);
        FUN_a00ba950(port);
        FUN_a00babe4(port, 0xb);
        break;
    case 0xf:
        DAT_a802d078[7] = 0x30;
        DAT_a802d078[8] = 0x30;
        DAT_a802d078[9] = 0x31;
        FUN_a00bacc4(0xf);
        FUN_a00ba950(port);
        FUN_a00babe4(port, 0xb);
        break;
    case 0x13:
        FUN_a00bc95c(port);
        break;
    case 0x14:
        DAT_a802d078[7] = 0x30;
        DAT_a802d078[8] = 0x30;
        DAT_a802d078[9] = (DAT_a802d3d0 + 0x30);
        FUN_a00bac3c(0x14);
        FUN_a00ba950(port);
        FUN_a00babe4(port, 0xb);
        break;
    case 0x15:
        DAT_a802d078[7] = 0x30;
        DAT_a802d078[8] = 0x30;
        DAT_a802d078[9] = (DAT_a802d2a9 + 0x30);
        FUN_a00bac3c(0x15);
        FUN_a00ba950(port);
        FUN_a00babe4(port, 0xb);
        break;
    case 0x16:
        DAT_a802d078[7] = 0x30;
        DAT_a802d078[8] = 0x30;
        DAT_a802d078[9] = (DAT_a802d340 + 0x30);
        FUN_a00bac3c(0x16);
        FUN_a00ba950(port);
        FUN_a00babe4(port, 0xb);
        break;
    case 0x17: {
        unsigned int uVar1;
        uVar1 = (_DAT_a802d3ac >> 0x1f);
        DAT_a802d078[7] = 0x30;
        DAT_a802d078[8] = 0x30;
        DAT_a802d078[9] = (uVar1 + 0x30);
        FUN_a00bac3c(0x17);
        FUN_a00ba950(port);
        FUN_a00babe4(port, 0xb);
        break;
    }
    case 0x18: {
        unsigned int uVar1;
        uVar1 = ((_DAT_a802d338 >> 0xc) & 1);
        DAT_a802d078[7] = 0x30;
        DAT_a802d078[8] = 0x30;
        DAT_a802d078[9] = (uVar1 + 0x30);
        FUN_a00bac3c(0x18);
        FUN_a00ba950(port);
        FUN_a00babe4(port, 0xb);
        break;
    }
    case 0x19:
        DAT_a802d078[7] = 0x30;
        DAT_a802d078[8] = 0x30;
        DAT_a802d078[9] = (DAT_a802d3ce + 0x30);
        FUN_a00bac3c(0x19);
        FUN_a00ba950(port);
        FUN_a00babe4(port, 0xb);
        break;
    case 0x1a:
        DAT_a802d078[7] = 0x30;
        DAT_a802d078[8] = 0x30;
        DAT_a802d078[9] = (DAT_a802d430 + 0x30);
        FUN_a00bac3c(0x1a);
        FUN_a00ba950(port);
        FUN_a00babe4(port, 0xb);
        break;
    case 0x1b:
        DAT_a802d078[7] = 0x30;
        DAT_a802d078[8] = 0x30;
        DAT_a802d078[9] = (DAT_a802cffd + 0x30);
        FUN_a00bac3c(0x1b);
        FUN_a00ba950(port);
        FUN_a00babe4(port, 0xb);
        break;
    case 0x1c: {
        int i = DAT_a802cffd;
        DAT_a802d078[7] = 0x30;
        DAT_a802d078[8] = DAT_a802d290[i + 0x197] + 0x30;
        DAT_a802d078[9] = DAT_a802d290[i + 0x19b] + 0x30;
        FUN_a00bac3c(0x1c);
        FUN_a00ba950(port);
        FUN_a00babe4(port, 0xb);
        break;
    }
    case 0x1d:
        DAT_a802d078[7] = 0x30;
        DAT_a802d078[8] = 0x30;
        DAT_a802d078[9] = (DAT_a802d3cf + 0x30);
        FUN_a00bac3c(0x1d);
        FUN_a00ba950(port);
        FUN_a00babe4(port, 0xb);
        break;
    case 0x1e:
        DAT_a802d078[7] = 0x30;
        DAT_a802d078[8] = 0x30;
        DAT_a802d078[9] = (DAT_a802d420 + 0x30);
        FUN_a00bac3c(0x1e);
        FUN_a00ba950(port);
        FUN_a00babe4(port, 0xb);
        break;
    case 0x1f:
        DAT_a802d078[7] = 0x30;
        DAT_a802d078[8] = 0x30;
        DAT_a802d078[9] = (DAT_a802d40b + 0x30);
        FUN_a00bac3c(0x1f);
        FUN_a00ba950(port);
        FUN_a00babe4(port, 0xb);
        break;
    case 0x20: {
        unsigned int uVar1;
        uVar1 = ((_DAT_a802d338 >> 0x7) & 1);
        DAT_a802d078[7] = 0x30;
        DAT_a802d078[8] = 0x30;
        DAT_a802d078[9] = (uVar1 + 0x30);
        FUN_a00bac3c(0x20);
        FUN_a00ba950(port);
        FUN_a00babe4(port, 0xb);
        break;
    }
    case 0x21: {
        unsigned int uVar1;
        uVar1 = ((_DAT_a802d338 >> 0xd) & 1);
        DAT_a802d078[7] = 0x30;
        DAT_a802d078[8] = 0x30;
        DAT_a802d078[9] = (uVar1 + 0x30);
        FUN_a00bac3c(0x21);
        FUN_a00ba950(port);
        FUN_a00babe4(port, 0xb);
        break;
    }
    case 0x22:
        FUN_a00bcecc(port);
        break;
    case 0x23:
        FUN_a00bd070(port);
        break;
    case 0x24: {
        unsigned int uVar1;
        uVar1 = ((_DAT_a802d3ac >> 0x4) & 1);
        DAT_a802d078[7] = 0x30;
        DAT_a802d078[8] = 0x30;
        DAT_a802d078[9] = (uVar1 + 0x30);
        FUN_a00bac3c(0x24);
        FUN_a00ba950(port);
        FUN_a00babe4(port, 0xb);
        break;
    }
    case 0x25: {
        unsigned int uVar1;
        uVar1 = _DAT_a802d2c4 & 0xf;
        DAT_a802d078[7] = 0x30;
        DAT_a802d078[8] = 0x30;
        DAT_a802d078[9] = (uVar1 + 0x30);
        FUN_a00bac3c(0x25);
        FUN_a00ba950(port);
        FUN_a00babe4(port, 0xb);
        break;
    }
    case 0x26:
        DAT_a802d078[7] = 0x30;
        DAT_a802d078[8] = 0x30;
        DAT_a802d078[9] = (DAT_a802d29f + 0x30);
        FUN_a00bac3c(0x26);
        FUN_a00ba950(port);
        FUN_a00babe4(port, 0xb);
        break;
    case 0x27:
        FUN_a00bd328(port);
        break;
    case 0x28: {
        unsigned char val;
        DAT_a802d078[7] = 0x30;
        val = DAT_a802d41a;
        if (val > 9) {
            DAT_a802d078[8] = 0x31;
            DAT_a802d078[9] = (val + 0x26);
        } else {
            DAT_a802d078[8] = 0x30;
            DAT_a802d078[9] = (val + 0x30);
        }
        FUN_a00bac3c(0x28);
        FUN_a00ba950(port);
        FUN_a00babe4(port, 0xb);
        break;
    }
    case 0x29: {
        unsigned char val;
        DAT_a802d078[7] = 0x30;
        val = DAT_a802d41b;
        if (val > 9) {
            DAT_a802d078[8] = 0x31;
            DAT_a802d078[9] = (val + 0x26);
        } else {
            DAT_a802d078[8] = 0x30;
            DAT_a802d078[9] = (val + 0x30);
        }
        FUN_a00bac3c(0x29);
        FUN_a00ba950(port);
        FUN_a00babe4(port, 0xb);
        break;
    }
    case 0x2a:
        FUN_a00bd59c(port);
        break;
    case 0x2b: {
        unsigned char val;
        DAT_a802d078[7] = 0x30;
        val = DAT_a802d41d;
        if (val > 9) {
            DAT_a802d078[8] = 0x31;
            DAT_a802d078[9] = (val + 0x26);
        } else {
            DAT_a802d078[8] = 0x30;
            DAT_a802d078[9] = (val + 0x30);
        }
        FUN_a00bac3c(0x2b);
        FUN_a00ba950(port);
        FUN_a00babe4(port, 0xb);
        break;
    }
    case 0x2c:
        FUN_a00bd760(port);
        break;
    case 0x2d: {
        unsigned int uVar1;
        uVar1 = ((_DAT_a802d33c >> 0x11) & 1);
        DAT_a802d078[7] = 0x30;
        DAT_a802d078[8] = 0x30;
        DAT_a802d078[9] = (uVar1 + 0x30);
        FUN_a00bac3c(0x2d);
        FUN_a00ba950(port);
        FUN_a00babe4(port, 0xb);
        break;
    }
    case 0x2e:
        FUN_a00bd9d8(port);
        break;
    case 0x2f:
        DAT_a802d078[7] = 0x30;
        DAT_a802d078[8] = 0x30;
        DAT_a802d078[9] = 0x9f;
        FUN_a00bac3c(0x2f);
        FUN_a00ba950(port);
        FUN_a00babe4(port, 0xb);
        break;
    case 0x30:
        DAT_a802d078[7] = 0x56;
        DAT_a802d078[8] = 0x32;
        DAT_a802d078[9] = 0x33;
        FUN_a00bac3c(0x30);
        FUN_a00ba950(port);
        FUN_a00babe4(port, 0xb);
        break;
    case 0x33:
        DAT_a802d078[7] = 0x30;
        DAT_a802d078[8] = 0x30;
        DAT_a802d078[9] = (DAT_a802d2af + 0x30);
        FUN_a00bac3c(0x33);
        FUN_a00ba950(port);
        FUN_a00babe4(port, 0xb);
        break;
    case 0x38:
        DAT_a802d078[7] = 0x30;
        DAT_a802d078[8] = 0x30;
        DAT_a802d078[9] = (0x32 - DAT_a802d2c1);
        FUN_a00bac3c(0x38);
        FUN_a00ba950(port);
        FUN_a00babe4(port, 0xb);
        break;
    case 0x39: {
        unsigned int uVar1;
        uVar1 = (_DAT_a802d2c0 >> 4) & 0xf;
        DAT_a802d078[7] = 0x30;
        DAT_a802d078[8] = 0x30;
        DAT_a802d078[9] = (uVar1 + 0x30);
        FUN_a00bac3c(0x39);
        FUN_a00ba950(port);
        FUN_a00babe4(port, 0xb);
        break;
    }
    case 0x68:
        DAT_a802d078[7] = 0x30;
        DAT_a802d078[8] = 0x30;
        DAT_a802d078[9] = (DAT_a802d2bf + 0x30);
        FUN_a00bac3c(0x68);
        FUN_a00ba950(port);
        FUN_a00babe4(port, 0xb);
        break;
    case 0x3a: {
        unsigned int uVar1;
        uVar1 = ((_DAT_a802d338 >> 0x6) & 1);
        DAT_a802d078[7] = 0x30;
        DAT_a802d078[8] = 0x30;
        DAT_a802d078[9] = (uVar1 + 0x30);
        FUN_a00bac3c(0x3a);
        FUN_a00ba950(port);
        FUN_a00babe4(port, 0xb);
        break;
    }
    case 0x3b:
        DAT_a802d078[7] = 0x30;
        DAT_a802d078[8] = 0x30;
        DAT_a802d078[9] = (DAT_a802d3eb + 0x30);
        FUN_a00bac3c(0x3b);
        FUN_a00ba950(port);
        FUN_a00babe4(port, 0xb);
        break;
    case 0x3c:
        DAT_a802d078[7] = 0x30;
        DAT_a802d078[8] = 0x30;
        DAT_a802d078[9] = (DAT_a802d2da + 0x30);
        FUN_a00bac3c(0x3c);
        FUN_a00ba950(port);
        FUN_a00babe4(port, 0xb);
        break;
    case 0x3d:
        DAT_a802d078[7] = 0x30;
        DAT_a802d078[8] = 0x30;
        DAT_a802d078[9] = (DAT_a802d2db + 0x30);
        FUN_a00bac3c(0x3d);
        FUN_a00ba950(port);
        FUN_a00babe4(port, 0xb);
        break;
    case 0x3e:
        DAT_a802d078[7] = 0x30;
        DAT_a802d078[8] = 0x30;
        DAT_a802d078[9] = (DAT_a802d2dc + 0x30);
        FUN_a00bac3c(0x3e);
        FUN_a00ba950(port);
        FUN_a00babe4(port, 0xb);
        break;
    case 0x56: {
        unsigned int uVar1;
        uVar1 = ((_DAT_a802d290 >> 0x9) & 1);
        DAT_a802d078[7] = 0x30;
        DAT_a802d078[8] = 0x30;
        DAT_a802d078[9] = (uVar1 + 0x30);
        FUN_a00bac3c(0x56);
        FUN_a00ba950(port);
        FUN_a00babe4(port, 0xb);
        break;
    }
    case 0x41:
        DAT_a802d078[0] = 0x35;
        DAT_a802d078[1] = 0x62;
        DAT_a802d078[2] = 0x30;
        DAT_a802d078[3] = 0x30;
        DAT_a802d078[4] = 0x5c;
        DAT_a802d078[5] = 0x30;
        DAT_a802d078[6] = 0x30;
        DAT_a802d078[7] = 0x30;
        DAT_a802d078[8] = 0x31;
        DAT_a802d078[9] = 0x31;
        DAT_a802d078[10] = 0xd;
        FUN_a00ba950(port);
        FUN_a00babe4(port, 0x26);
        break;
    case 0x43:
        FUN_a00bdf28(port);
        break;
    case 0x45: {
        unsigned int uVar1;
        uVar1 = ((_DAT_a802d338 >> 0xf) & 1);
        DAT_a802d078[7] = 0x30;
        DAT_a802d078[8] = 0x30;
        DAT_a802d078[9] = (uVar1 + 0x30);
        FUN_a00bac3c(0x45);
        FUN_a00ba950(port);
        FUN_a00babe4(port, 0xb);
        break;
    }
    case 0x46: {
        unsigned int uVar1;
        uVar1 = ((_DAT_a802d33c >> 0x16) & 1);
        DAT_a802d078[7] = 0x30;
        DAT_a802d078[8] = 0x30;
        DAT_a802d078[9] = (uVar1 + 0x30);
        FUN_a00bac3c(0x46);
        FUN_a00ba950(port);
        FUN_a00babe4(port, 0xb);
        break;
    }
    case 0x4c:
        DAT_a802d078[7] = 0x30;
        DAT_a802d078[8] = 0x30;
        if (DAT_a802d290[0x1f] == 0)
            DAT_a802d078[9] = ((*(unsigned int *)(DAT_a802d290 + 0xac) >> 0x14) & 1) + 0x30;
        else
            DAT_a802d078[9] = 0x30;
        FUN_a00bac3c(0x4c);
        FUN_a00ba950(port);
        FUN_a00babe4(port, 0xb);
        break;
    case 0x66:
        DAT_a802d078[7] = 0x30;
        DAT_a802d078[8] = 0x30;
        DAT_a802d078[9] = (DAT_a802d407 + 0x30);
        FUN_a00bac3c(0x66);
        FUN_a00ba950(port);
        FUN_a00babe4(port, 0xb);
        break;
    case 0x65:
        DAT_a802d078[7] = 0x30;
        DAT_a802d078[8] = 0x30;
        DAT_a802d078[9] = (DAT_a802d40c + 0x30);
        FUN_a00bac3c(0x65);
        FUN_a00ba950(port);
        FUN_a00babe4(port, 0xb);
        break;
    case 0x6a: {
        unsigned int uVar1;
        uVar1 = (_DAT_a802d33c >> 0x12) & 3;
        DAT_a802d078[7] = 0x30;
        DAT_a802d078[8] = 0x30;
        DAT_a802d078[9] = (uVar1 + 0x30);
        FUN_a00bac3c(0x6a);
        FUN_a00ba950(port);
        FUN_a00babe4(port, 0xb);
        break;
    }
    case 0x6b: {
        unsigned int uVar1;
        uVar1 = ((_DAT_a802d47c >> 0x7) & 1);
        DAT_a802d078[7] = 0x30;
        DAT_a802d078[8] = 0x30;
        DAT_a802d078[9] = (uVar1 + 0x30);
        FUN_a00bac3c(0x6b);
        FUN_a00ba950(port);
        FUN_a00babe4(port, 0xb);
        break;
    }
    case 0x6c: {
        unsigned int uVar1;
        uVar1 = ((_DAT_a802d404 >> 0xf) & 1);
        DAT_a802d078[7] = 0x30;
        DAT_a802d078[8] = 0x30;
        DAT_a802d078[9] = (uVar1 + 0x30);
        FUN_a00bac3c(0x6c);
        FUN_a00ba950(port);
        FUN_a00babe4(port, 0xb);
        break;
    }
    case 0x6e: {
        unsigned int uVar1;
        uVar1 = (_DAT_a802d484 >> 0x1f);
        DAT_a802d078[7] = 0x30;
        DAT_a802d078[8] = 0x30;
        DAT_a802d078[9] = (uVar1 + 0x30);
        FUN_a00bac3c(0x6e);
        FUN_a00ba950(port);
        FUN_a00babe4(port, 0xb);
        break;
    }
    case 0x6f: {
        unsigned int uVar1;
        uVar1 = ((_DAT_a802d484 >> 0x1e) & 1);
        DAT_a802d078[7] = 0x30;
        DAT_a802d078[8] = 0x30;
        DAT_a802d078[9] = (uVar1 + 0x30);
        FUN_a00bac3c(0x6f);
        FUN_a00ba950(port);
        FUN_a00babe4(port, 0xb);
        break;
    }
    case 0x70:
        DAT_a802d078[7] = 0x30;
        DAT_a802d078[8] = 0x30;
        DAT_a802d078[9] = (DAT_a802d46d + 0x30);
        FUN_a00bac3c(0x70);
        FUN_a00ba950(port);
        FUN_a00babe4(port, 0xb);
        break;
    case 0x71: {
        unsigned int uVar1;
        uVar1 = (_DAT_a802d46c >> 0x1f);
        DAT_a802d078[7] = 0x30;
        DAT_a802d078[8] = 0x30;
        DAT_a802d078[9] = (uVar1 + 0x30);
        FUN_a00bac3c(0x71);
        FUN_a00ba950(port);
        FUN_a00babe4(port, 0xb);
        break;
    }
    case 0x72: {
        unsigned int uVar1;
        uVar1 = ((_DAT_a802d46c >> 0x1e) & 1);
        DAT_a802d078[7] = 0x30;
        DAT_a802d078[8] = 0x30;
        DAT_a802d078[9] = (uVar1 + 0x30);
        FUN_a00bac3c(0x72);
        FUN_a00ba950(port);
        FUN_a00babe4(port, 0xb);
        break;
    }
    case 0x73: {
        unsigned int uVar1;
        uVar1 = ((_DAT_a802d46c >> 0xf) & 1);
        DAT_a802d078[7] = 0x30;
        DAT_a802d078[8] = 0x30;
        DAT_a802d078[9] = (uVar1 + 0x30);
        FUN_a00bac3c(0x73);
        FUN_a00ba950(port);
        FUN_a00babe4(port, 0xb);
        break;
    }
    case 0x74:
        DAT_a802d078[7] = 0x30;
        DAT_a802d078[8] = 0x30;
        DAT_a802d078[9] = (DAT_a802d470 + 0x30);
        FUN_a00bac3c(0x74);
        FUN_a00ba950(port);
        FUN_a00babe4(port, 0xb);
        break;
    case 0x76:
        DAT_a802d078[7] = 0x30;
        DAT_a802d078[8] = 0x30;
        DAT_a802d078[9] = (DAT_a802d46f + 0x30);
        FUN_a00bac3c(0x76);
        FUN_a00ba950(port);
        FUN_a00babe4(port, 0xb);
        break;
    case 0x75:
        DAT_a802d078[7] = 0x30;
        DAT_a802d078[8] = 0x30;
        DAT_a802d078[9] = (DAT_a802d471 + 0x30);
        FUN_a00bac3c(0x75);
        FUN_a00ba950(port);
        FUN_a00babe4(port, 0xb);
        break;
    case 0x77:
        DAT_a802d078[7] = 0x30;
        DAT_a802d078[8] = 0x30;
        DAT_a802d078[9] = 0x30;
        FUN_a00bac3c(0x77);
        FUN_a00ba950(port);
        FUN_a00babe4(port, 0xb);
        break;
    case 0x7c:
        DAT_a802d078[7] = 0x30;
        DAT_a802d078[8] = 0x30;
        DAT_a802d078[9] = (DAT_a802d478 + 0x30);
        FUN_a00bac3c(0x7c);
        FUN_a00ba950(port);
        FUN_a00babe4(port, 0xb);
        break;
    case 0x7d:
        DAT_a802d078[7] = 0x30;
        DAT_a802d078[8] = 0x30;
        DAT_a802d078[9] = (DAT_a802d479 + 0x2f);
        FUN_a00bac3c(0x7d);
        FUN_a00ba950(port);
        FUN_a00babe4(port, 0xb);
        break;
    case 0x7e:
        DAT_a802d078[7] = 0x30;
        DAT_a802d078[8] = 0x30;
        DAT_a802d078[9] = (DAT_a802d47a + 0x30);
        FUN_a00bac3c(0x7e);
        FUN_a00ba950(port);
        FUN_a00babe4(port, 0xb);
        break;
    case 0x7f:
        DAT_a802d078[7] = 0x30;
        DAT_a802d078[8] = 0x30;
        DAT_a802d078[9] = (DAT_a802d47b + 0x2f);
        FUN_a00bac3c(0x7f);
        FUN_a00ba950(port);
        FUN_a00babe4(port, 0xb);
        break;
    case 0x80:
        DAT_a802d078[7] = 0x30;
        DAT_a802d078[8] = 0x30;
        DAT_a802d078[9] = (DAT_a802d47c + 0x30);
        FUN_a00bac3c(0x80);
        FUN_a00ba950(port);
        FUN_a00babe4(port, 0xb);
        break;
    case 0x81:
        DAT_a802d078[7] = 0x30;
        DAT_a802d078[8] = 0x30;
        DAT_a802d078[9] = (DAT_a802d47d + 0x2f);
        FUN_a00bac3c(0x81);
        FUN_a00ba950(port);
        FUN_a00babe4(port, 0xb);
        break;
    case 0x82:
        DAT_a802d078[7] = 0x30;
        DAT_a802d078[8] = 0x30;
        DAT_a802d078[9] = (DAT_a802d47e + 0x30);
        FUN_a00bac3c(0x82);
        FUN_a00ba950(port);
        FUN_a00babe4(port, 0xb);
        break;
    case 0x78:
        FUN_a00be81c(port);
        break;
    case 0x0:
        FUN_a00be9a8(port);
        break;
    case 0x37:
        FUN_a00beae0(port);
        break;
    case 0x36:
        FUN_a00bec0c(port);
        break;
    case 0x35:
        FUN_a00bed38(port);
        break;
    case 0x34:
        FUN_a00bee64(port);
        break;
    case 0x12:
        FUN_a00bef90(port);
        break;
    case 0x2:
        FUN_a00bf110(port);
        break;
    case 0x31:
        FUN_a00bf3f8(port);
        break;
    case 0x32:
        FUN_a00bf538(port);
        break;
    case 0x3f:
        FUN_a00bf6b0(port);
        break;
    case 0x49:
        FUN_a00bf7dc(port);
        break;
    case 0x42:
        FUN_a00bfb28(port);
        break;
    }
}

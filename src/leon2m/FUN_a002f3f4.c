/* leon2m FUN_a002f3f4 @ 0xa002f3f4..0xa002f550 (348 bytes, RAM copy: CPU 0x4008f3f4)  Big chip -> 8051 command send
 * Called as func_0x4008f3f4(cmd, a1, a2, a3, mode) by the 8051-command wrappers
 * FUN_a0133e34 (cmd 0x16 = STOP Leon2 Main, mode 3), FUN_a0133e58 (8), FUN_a0133e7c (7: I2C service slave, used by
 * UartSetI2CEnable with 0x6E), FUN_a0133f24 (6), FUN_a0133f48 (5), FUN_a0133f84 (2 and 0xF), FUN_a01340b0 (0x1F), ...
 * What the code does (code facts):
 *  1. Polls mailbox portal 0 (8051) word +0 (MailBox_Read FUN_a002c4d0) at most 100 times until it reads 0 (the
 *     8051 clears it when it has taken the previous command).
 *  2. If the slot became free, or mode == 3: writes the command word a3 << 24 | a2 << 16 | a1 << 8 | cmd to
 *     portal 0 +0 (MailBox_Write FUN_a002c5f8). On the 8051 this is the command switch FUN_CODE_224f (command =
 *     low byte; table 0x22DB: 0x16 / 0x17 STOP Main / Sub, 0x29 = STBC flash update loop FUN_CODE_6c34).
 *     If the slot stayed busy (100 reads) and mode != 3: nothing is sent, return.
 *  3. mode 3: endless loop right after sending (the sender waits to be stopped / reset; used for cmd 0x16).
 *     mode 2: handshake on portal 0 +0xB8: low byte := 1, then waits WITHOUT timeout until the low byte reads 2;
 *     then as mode 1. mode 1 and 2: waits WITHOUT timeout until portal 0 +0 reads 0 again (command done).
 * Dependency: every Big chip -> 8051 command with mode 1/2 (e.g. the I2C slave 0x6E set-up of the MSI update
 *   entry FUN_a00bf110) needs a running 8051; if the 8051 has parked itself (liveness check FUN_CODE_7b5a,
 *   'SJMP $'), the Big chip hangs here forever.
 */
extern void FUN_a002c4d0(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);
extern void FUN_a002c5f8(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);

void FUN_a002f3f4(unsigned char cmd, unsigned char a1, unsigned char a2, unsigned char a3, unsigned char mode)
{
    unsigned int w = 0;
    unsigned char tries = 100;
    do {
        FUN_a002c4d0(0, 0, &w, 1);
        tries--;
        if (tries == 0)
            break;
    } while (w != 0);
    if (tries != 0 || mode == 3) {
        w = (a3 << 24) + (a2 << 16) + (a1 << 8) + cmd;
        FUN_a002c5f8(0, 0, &w, 1);
        if (mode == 3)
            for (;;)
                ;
        if (mode == 2) {
            unsigned int h = 0;
            FUN_a002c4d0(0, 0xb8, &h, 1);
            h = (h & ~0xffu) | 1;
            FUN_a002c5f8(0, 0xb8, &h, 1);
            do
                FUN_a002c4d0(0, 0xb8, &h, 1);
            while ((unsigned char)h != 2);
        }
        if ((unsigned char)(mode - 1) < 2) {
            do
                FUN_a002c4d0(0, 0, &w, 1);
            while (w != 0);
        }
    }
}

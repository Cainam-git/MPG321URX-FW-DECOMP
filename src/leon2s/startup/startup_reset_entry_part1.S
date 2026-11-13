! startup_reset_entry_part1  (FUN_a00602c0)
!
! Flush the instruction cache, set PSR to 0xCF (supervisor, traps off), clear WIM and Y.
! Note: Ghidra piece 1 of the routine 0xA00602C0..0xA0060313, not callable on its own.
! Name basis: proven - trap-table slot 0 (reset) jumps to 0x2C0; trap-name table says 'Power-on reset'; part 5
!   calls main 0xA0060864
!
! Matching notes
! --------------
! leon2s FUN_a00602c0 @ 0xa00602c0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a00602c0
	.type FUN_a00602c0, #function
FUN_a00602c0:
! Reset start-up of the input processor, entered from the reset slot (trap_reset_entry). It sets the
! processor state, the register windows, the stack and the trap table, then calls the main routine
! sys_main. It continues in startup_reset_entry_part2..4.S and startup_reset_entry_part5.S (0xA0060300).
	flush  %g0 + 0                    ! FLUSH: empty the instruction cache
	wr  %g0, 0xcf, %psr               ! PSR = 0xCF: supervisor mode, traps off, current window 15
	mov  %g0, %wim                    ! WIM = 0: no register window marked invalid yet
	mov  %g0, %y                      ! Y register = 0
	.size FUN_a00602c0, .-FUN_a00602c0

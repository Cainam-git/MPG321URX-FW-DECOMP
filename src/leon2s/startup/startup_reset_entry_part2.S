! startup_reset_entry_part2  (FUN_a00602d0)
!
! Mark window 0 invalid and build the run-time PSR 0x10E0 (supervisor, FPU on, traps on).
! Note: Ghidra piece 2 of the routine 0xA00602C0..0xA0060313, not callable on its own.
! Name basis: proven - trap-table slot 0 (reset) jumps to 0x2C0; trap-name table says 'Power-on reset'; part 5
!   calls main 0xA0060864
!
! Matching notes
! --------------
! leon2s FUN_a00602d0 @ 0xa00602d0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a00602d0
	.type FUN_a00602d0, #function
FUN_a00602d0:
! Part 2 of the reset start-up (0xA00602C0..0xA0060313).
	mov  1, %g1                       ! %g1 = 1
	mov  %g1, %wim                    ! WIM = 1: window 0 is the invalid window (the stop for SAVE)
	sethi  %hi(0x1000), %g1           ! %g1 = 0x1000 ...
	or  %g1, 0xe0, %g1                ! ... | 0xE0 = 0x10E0: FPU on, supervisor mode, traps on, window 0
	.size FUN_a00602d0, .-FUN_a00602d0

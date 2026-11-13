! startup_reset_entry_part3  (FUN_a00602e0)
!
! Load the run-time PSR and set the frame pointer near the top of data RAM.
! Note: Ghidra piece 3 of the routine 0xA00602C0..0xA0060313, not callable on its own.
! Name basis: proven - trap-table slot 0 (reset) jumps to 0x2C0; trap-name table says 'Power-on reset'; part 5
!   calls main 0xA0060864
!
! Matching notes
! --------------
! leon2s FUN_a00602e0 @ 0xa00602e0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a00602e0
	.type FUN_a00602e0, #function
FUN_a00602e0:
! Part 3 of the reset start-up (0xA00602C0..0xA0060313).
	mov  %g1, %psr                    ! write PSR: traps on from here, current window 0
	sethi  %hi(0xa807fc00), %g3       ! %g3 = 0xA807FC00 ...
	or  %g3, 0x350, %g3               ! ... + 0x350 = 0xA807FF50, just below the save area at 0xA807FF60
	mov  %g3, %fp                     ! frame pointer = 0xA807FF50
	.size FUN_a00602e0, .-FUN_a00602e0

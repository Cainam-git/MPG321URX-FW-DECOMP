! startup_reset_entry_part4  (FUN_a00602f0)
!
! Set the stack pointer below the frame and point TBR at the trap table.
! Note: Ghidra piece 4 of the routine 0xA00602C0..0xA0060313, not callable on its own.
! Name basis: proven - trap-table slot 0 (reset) jumps to 0x2C0; trap-name table says 'Power-on reset'; part 5
!   calls main 0xA0060864
!
! Matching notes
! --------------
! leon2s FUN_a00602f0 @ 0xa00602f0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a00602f0
	.type FUN_a00602f0, #function
FUN_a00602f0:
! Part 4 of the reset start-up (0xA00602C0..0xA0060313).
	sub  %g3, 0x60, %sp               ! stack pointer = 0xA807FEF0 (0x60 below the frame pointer)
	sethi  %hi(0xa0060000), %g1       ! %g1 = 0xA0060000, the trap table of this program
	mov  %g1, %tbr                    ! TBR = 0xA0060000: traps and interrupts now use this table
	nop                               ! wait one instruction for the TBR write
	.size FUN_a00602f0, .-FUN_a00602f0

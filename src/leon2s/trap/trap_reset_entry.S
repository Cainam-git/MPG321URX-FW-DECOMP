! trap_reset_entry  (FUN_a0060000)
!
! Trap table slot 0x00 (reset): clears %l0 and jumps to the reset start-up at 0xa00602c0.
! Name basis: proven - trap table position and the slot's own instructions
!
! Matching notes
! --------------
! leon2s FUN_a0060000 @ 0xa0060000  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060000
	.type FUN_a0060000, #function
FUN_a0060000:
! Slot of trap type 0x00, reset: the input processor (Leon2S) starts here. It jumps to the reset
! start-up at 0xA00602C0 (startup_reset_entry_part1.S). Unlike the other used slots it does not
! read PSR or TBR.
	mov  %g0, %l0                     ! %l0 = 0
	sethi  %hi(0xa0060000), %l4       ! upper bits of the start-up address 0xA00602C0
	jmp  %l4 + 0x2c0                  ! jump to the reset start-up
	nop                               ! delay slot: nothing
	.size FUN_a0060000, .-FUN_a0060000

! trap_reset_entry  (FUN_a0028000)
!
! Trap table slot 0x00 (reset): jumps to the handler at 0xa0029000.
! Name basis: proven - trap table position and the slot's own instructions
!
! Labels used below:
!   FUN_a0028ff0 = trap_software_trap_127_unhandled
!
! Matching notes
! --------------
! leon2m FUN_a0028000 @ 0xa0028000  reset trap slot (trap table entry 0) - byte-exact (sparc-elf-as -Av8,
! asm). %l0 = 0, then jumps to the reset code at 0xA0029000 (in FUN_a0028ff0). Hand-written assembly.
	.section ".text"
	.align 4
	.global FUN_a0028000
	.type FUN_a0028000, #function
FUN_a0028000:
	mov  %g0, %l0
	sethi  %hi(0xa0029000), %l4
	jmp  %l4 + 0
	nop
	.size FUN_a0028000, .-FUN_a0028000

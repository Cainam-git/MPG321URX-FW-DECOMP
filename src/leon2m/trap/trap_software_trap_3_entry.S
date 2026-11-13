! trap_software_trap_3_entry  (FUN_a0028830)
!
! Trap table slot 0x83 (software trap 3): reads %psr and %tbr and jumps to the handler at 0xa0029328.
! Name basis: proven - trap table position and the slot's own instructions
!
! Matching notes
! --------------
! leon2m FUN_a0028830 @ 0xa0028830  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0028830
	.type FUN_a0028830, #function
FUN_a0028830:
! Slot of trap type 0x83, software trap 3 ('ta 3'). The trap has already put the PC and nPC of the
! trapped instruction in %l1 and %l2; the slot adds PSR and TBR and jumps on to
! trap_handle_faults at 0xA0029328, which writes every register window to its stack
! and goes on after the 'ta 3'.
	rd  %psr, %l0                     ! processor state register (PSR) to %l0
	sethi  %hi(0xa0029000), %l4       ! upper bits of the handler address 0xA0029328
	jmp  %l4 + 0x328                  ! jump to 0xA0029328: flush the register windows to the stack
	rd  %tbr, %l3                     ! delay slot, runs before the jump: TBR (holds the trap type) to %l3
	.size FUN_a0028830, .-FUN_a0028830

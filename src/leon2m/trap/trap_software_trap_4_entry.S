! trap_software_trap_4_entry  (FUN_a0028840)
!
! Trap table slot 0x84 (software trap 4): reads %psr and %tbr and jumps to the handler at 0xa0029210.
! Name basis: proven - trap table position and the slot's own instructions
!
! Matching notes
! --------------
! leon2m FUN_a0028840 @ 0xa0028840  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0028840
	.type FUN_a0028840, #function
FUN_a0028840:
! Slot of trap type 0x84, software trap 4 ('ta 4'). The trap has already put the PC and nPC of the
! trapped instruction in %l1 and %l2; the slot adds PSR and TBR and jumps on to
! trap_handle_faults at 0xA0029210, which skips the trapped instruction and goes on
! with the next one.
	rd  %psr, %l0                     ! processor state register (PSR) to %l0
	sethi  %hi(0xa0029000), %l4       ! upper bits of the handler address 0xA0029210
	jmp  %l4 + 0x210                  ! jump to 0xA0029210: skip the trapped instruction
	rd  %tbr, %l3                     ! delay slot, runs before the jump: TBR (holds the trap type) to %l3
	.size FUN_a0028840, .-FUN_a0028840

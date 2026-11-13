! trap_software_trap_0_entry  (FUN_a0028800)
!
! Trap table slot 0x80 (software trap 0): reads %psr and %tbr and jumps to the handler at 0xa0029388.
! Name basis: proven - trap table position and the slot's own instructions
!
! Matching notes
! --------------
! leon2m FUN_a0028800 @ 0xa0028800  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0028800
	.type FUN_a0028800, #function
FUN_a0028800:
! Slot of trap type 0x80, software trap 0 ('ta 0'). The trap has already put the PC and nPC of the
! trapped instruction in %l1 and %l2; the slot adds PSR and TBR and jumps on to
! trap_handle_faults at 0xA0029388: a load from the odd address 1 with traps off,
! which puts the processor into error mode (it stops until a reset).
	rd  %psr, %l0                     ! processor state register (PSR) to %l0
	sethi  %hi(0xa0029000), %l4       ! upper bits of the handler address 0xA0029388
	jmp  %l4 + 0x388                  ! jump to 0xA0029388: deliberate stop (error mode)
	rd  %tbr, %l3                     ! delay slot, runs before the jump: TBR (holds the trap type) to %l3
	.size FUN_a0028800, .-FUN_a0028800

native '>r', to_r
  pop rax
  rpush rax
  jmp next

native 'r>', from_r
  rpop rax
  push rax
  jmp next

native "r@", r_fetch
  push qword [rstack]
  jmp next

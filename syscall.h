//******************************************************************************
// Copyright (c) 2018, The Regents of the University of California (Regents).
// All Rights Reserved. See LICENSE for license details.
//------------------------------------------------------------------------------
#ifndef __SYSCALL_H__
#define __SYSCALL_H__

#include "printf.h"
#include "regs.h"
#include "edge_syscall.h"
#include "vm.h"

#define RUNTIME_SYSCALL_UNKNOWN             1000
#define RUNTIME_SYSCALL_OCALL               1001
#define RUNTIME_SYSCALL_SHAREDCOPY          1002
#define RUNTIME_SYSCALL_ATTEST_ENCLAVE      1003
#define RUNTIME_SYSCALL_GET_SEALING_KEY     1004
#define RUNTIME_SYSCALL_GET_RANDOM          1005
#define RUNTIME_SYSCALL_GET_RANDOM_WORD     1006
#define RUNTIME_SYSCALL_GET_UID_RULEID      1007
#define RUNTIME_SYSCALL_REGISTER_TIME       1008
#define RUNTIME_SYSCALL_GET_TIME            1009
#define RUNTIME_SYSCALL_VERIFY_NONCE        1010
#define RUNTIME_SYSCALL_EXIT                1101

void handle_syscall(struct encl_ctx* ctx);
void init_edge_internals(void);
uintptr_t dispatch_edgecall_syscall(struct edge_syscall* syscall_data_ptr,
                                    size_t data_len);

// Define this to enable printing of a large amount of syscall information
//#define INTERNAL_STRACE 1

#ifdef INTERNAL_STRACE
#define print_strace printf
#else
#define print_strace(...)
#endif

#endif /* syscall.h */

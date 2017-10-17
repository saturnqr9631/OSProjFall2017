/*
 * This file contains the function definitions for the library interfaces
 * to the USLOSS system calls.
 */
#ifndef _LIBUSER_H
#define _LIBUSER_H

// Phase 3 -- User Function Prototypes
extern int  Spawn(char *name, int (*func)(char *), char *arg, long stack_size,
                  long priority, int *pid);
extern int  Wait(int *pid, int *status);
extern void Terminate(long status);
extern void GetTimeofDay(int *tod);
extern void CPUTime(int *cpu);
extern void GetPID(int *pid);
extern int  SemCreate(long value, int *semaphore);
extern int  SemP(long semaphore);
extern int  SemV(long semaphore);
extern int  SemFree(int semaphore);

#endif

#ifndef SEMS_H
#define SEMS_H


#define UNUSED      0
#define USED        1
#define TERMINATED  2

#define VALID       0
#define INVALID     -1

typedef struct process  process;
typedef struct process* procPtr;
typedef struct semaphore semaphore;

struct process {
    int             pid;
    int             status;
    procPtr         parentPtr;
    procPtr         childPtr;
    procPtr         nextSiblingPtr;
    int             entryMade;      // has the process table entry been made yet
};


struct semaphore {
    int     status;
    int     value;
    int     mboxID;         // every semaphore has a mailbox so that it can block processes
};



int start3(char* arg);




// syscall functions
void    nullsys3();

void    spawn(USLOSS_Sysargs*);
long    spawnReal(char* name, int(*startFunc)(char *), void* arg, int stackSize, int priority);
int     spawnLaunch(char*);

void    wait(USLOSS_Sysargs* args);
long    waitReal(int* status);

void    terminate(USLOSS_Sysargs* args);
void    terminateReal(int status);

void    semCreate(USLOSS_Sysargs* args);
long    semCreateReal(int value, long* status);

void    semP(USLOSS_Sysargs* args);
long    semPReal(int semNumber);

void    semV(USLOSS_Sysargs* args);
long    semVReal(int semNumber);


// helper functions
void initializeProcessTable();
void initializeSemaphoreTable();
void initializeSysCallTable();
void checkKernelMode(char* name);
void setToUserMode();
void setToKernelMode();
void addToChildList(int parentPid, int childPid);
int getNextSemIndex();

#endif
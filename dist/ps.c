//Addison Wurtz
//4.16.21
//This file contains the user program for the ps command

#ifdef CS333_P2
#include "types.h"
#include "user.h"
#include "uproc.h"

#define MAX 64 


int
main(int argc, char *argv[])
{
  uint i, pnum; //pnum is the number of active processes copied into table
  uint secs, msecs, cpu_secs, cpu_msecs;

  struct uproc *table = malloc(sizeof(struct uproc) * MAX);
  
  
  pnum = getprocs(MAX, table);
  if(pnum < 0)
  {
    printf(1, "Error: getprocs failed.");
    exit();
  }
#ifdef CS333_P4
  printf(1, "\nPID\tName\t     UID\tGID\tPPID\tPrio\tElapsed\tCPU\tState\tSize\n");
#else
  printf(1, "\nPID\tName\t     UID\tGID\tPPID\tElapsed\tCPU\tState\tSize\n");
#endif //CS333_P4
  for(i = 0; i < pnum; ++i)
  {

    secs = table[i].elapsed_ticks / 1000;
    msecs = table[i].elapsed_ticks % 1000;
    cpu_secs = table[i].CPU_total_ticks / 1000;
    cpu_msecs = table[i].CPU_total_ticks % 1000;

#ifdef CS333_P4
    if(msecs < 10)
       printf(1, "%d\t%s\t     %d\t\t%d\t%d\t%d\t%d.00%d\t", table[i].pid, table[i].name, table[i].uid, table[i].gid, table[i].ppid, table[i].priority, secs, msecs);
    else if(msecs < 100)
       printf(1, "%d\t%s\t     %d\t\t%d\t%d\t%d\t%d.0%d\t", table[i].pid, table[i].name, table[i].uid, table[i].gid, table[i].ppid, table[i].priority, secs, msecs);
    else
       printf(1, "%d\t%s\t     %d\t\t%d\t%d\t%d\t%d.%d\t", table[i].pid, table[i].name, table[i].uid, table[i].gid, table[i].ppid, table[i].priority, secs, msecs);
#else
    if(msecs < 10)
       printf(1, "%d\t%s\t     %d\t\t%d\t%d\t%d.00%d\t", table[i].pid, table[i].name, table[i].uid, table[i].gid, table[i].ppid, secs, msecs);
    else if(msecs < 100)
       printf(1, "%d\t%s\t     %d\t\t%d\t%d\t%d.0%d\t", table[i].pid, table[i].name, table[i].uid, table[i].gid, table[i].ppid, secs, msecs);
    else
       printf(1, "%d\t%s\t     %d\t\t%d\t%d\t%d.%d\t", table[i].pid, table[i].name, table[i].uid, table[i].gid, table[i].ppid, secs, msecs);
#endif //CS333_P4
    if(cpu_msecs < 10)
      printf(1, "%d.00%d\t%s\t%d\n", cpu_secs, cpu_msecs, table[i].state, table[i].size);
    else if(cpu_msecs < 100)
      printf(1, "%d.0%d\t%s\t%d\n", cpu_secs, cpu_msecs, table[i].state, table[i].size);
    else
      printf(1, "%d.%d\t%s\t%d\n", cpu_secs, cpu_msecs, table[i].state, table[i].size);
  }
  printf(1, "\n");

  free(table);

  exit();
}
#endif //CS333_P2

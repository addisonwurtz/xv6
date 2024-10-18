//Addison Wurtz
//This file contains the userprogram for the time command

#ifdef CS333_P2
#include "types.h"
#include "user.h"


int
main(int argc, char *argv[])
{
  uint starttime, elapsedtime;
  uint secs, msecs;
  uint child;

  argv++;
  starttime = uptime();
  
  child = fork();
  if(fork < 0)
    printf(1, "\nError: fork failed.\n");
  else if(child == 0) //child
  {
    exec(*argv, argv);
    exit();
  }
  else
  {
    if(wait() < 0)
      printf(1, "Error: wait failed.");
      
    elapsedtime = uptime() - starttime;
  }
  secs = elapsedtime / 1000;
  msecs = elapsedtime % 1000;

  printf(1, "%s ran in %d.", *argv, secs);
  if(msecs < 10)
    printf(1, "0");
  if(msecs < 100)
    printf(1, "0");
  printf(1, "%d seconds.\n", msecs);

  exit();
}

#endif //CS333_p2

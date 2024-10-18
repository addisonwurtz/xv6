#ifdef CS333_P4
#include "types.h"
#include "user.h"

int
main(int argc, char *argv[])
{
  int pid, prio, rc;

  printf(2, "setpriority() test: \n");
  printf(2, "MAXPRIO is %d\n", MAXPRIO);
  printf(2,"The current process is: %d\n", getpid());
  printf(2, "getpriority(%d) = %d\n", getpid(), getpriority(getpid()));

  if (argc == 1) {
    pid = getpid();
    prio = 0;
  }
  else {
    if (argc != 3) {
      printf(2, "Error: invalid pid or priority\n");
      printf(2, "Usage: %s [<pid> <prio>]\n",argv[0]);
      exit();
    }
    else {
      pid = atoi(argv[1]);
      prio = atoi(argv[2]);
    }
  }

  printf(2, "Initial Priority: getpriority(%d) = %d\n", pid, getpriority(pid));

  rc = setpriority(pid, prio);
  if (rc == -1) {
      printf(2, "Error: invalid pid\n");
      printf(2, "Usage: %s [<pid> <prio>]\n",argv[0]);
      printf(2, "getpriority(%d) = %d\n", pid, getpriority(pid));
  }
  else if (rc == -2) {
      printf(2, "Error: invalid priority\n");
      printf(2, "Usage: %s [<pid> <prio>]\n",argv[0]);
  }
  else {
    printf(2, "setpriority() was successful!\n");
    printf(2, "Updated Priority: getpriority(%d) = %d\n", pid, getpriority(pid));
  }
  
  exit();
}
#endif

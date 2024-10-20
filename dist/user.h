struct stat;
struct rtcdate;
struct uproc;

// system calls
int fork(void);
int exit(void) __attribute__((noreturn));
int wait(void);
int pipe(int*);
int write(int, void*, int);
int read(int, void*, int);
int close(int);
int kill(int);
int exec(char*, char**);
int open(char*, int);
int mknod(char*, short, short);
int unlink(char*);
int fstat(int fd, struct stat*);
int link(char*, char*);
int mkdir(char*);
int chdir(char*);
int dup(int);
int getpid(void);
char* sbrk(int);
int sleep(int);
int uptime(void);
int halt(void);
#ifdef CS333_P1
int date(struct rtcdate*);
#endif //CS333_P1
#ifdef CS333_P2
uint getuid(void);  //UID of the current process
uint getgid(void);  //GID of the current process
uint getppid(void);  //process ID of the parent process
int setuid(uint);   //set UID
int setgid(uint);   //set GID
int getprocs(uint max, struct uproc* table);
#endif //CS333_P2
#ifdef CS333_P4
int setpriority(int pid, int priority);
int getpriority(int pid);
#endif //CS333_P4

// ulib.c
int stat(char*, struct stat*);
char* strcpy(char*, char*);
void *memmove(void*, void*, int);
char* strchr(const char*, char c);
int strcmp(const char*, const char*);
void printf(int, char*, ...);
char* gets(char*, int max);
uint strlen(char*);
void* memset(void*, int, uint);
void* malloc(uint);
void free(void*);
int atoi(const char*);
#ifdef PDX_XV6
int atoo(const char*);
int strncmp(const char*, const char*, uint);
#endif // PDX_XV6


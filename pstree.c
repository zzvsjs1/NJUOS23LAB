#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <dirent.h>
#include <ctype.h>
#include <errno.h>

#define PROC_DIR "/proc"
#define ARR_LEN(ARR) sizeof(ARR) / sizeof(ARR[0])

// The process stuct
typedef struct
{

} Process;

bool safeToInt(const char* str, int* num)
{
    const int save = errno;
    const int ret = strtol(str, NULL, 10);

    if (errno == ERANGE)
    {
        errno = save;
        num = NULL;
        return false;
    }

    *num = ret;
    return true; 
}

bool isPid(const char* s)
{
    assert(s);

    for (; *s; ++s)
    {
        if (!isdigit((unsigned) *s)) 
        {
            return false;
        }
    }

    return true;
}

int main(void)
{
    // DIR *dir = opendir(PROC_DIR);

    // if (!dir) 
    // {
    //     perror("opendir() error");
    //     return 1;
    // }

    // struct dirent *entry;
    // while ((entry = readdir(dir)) != NULL) 
    // {
    //     if (isPid(entry->d_name))
    //     {
    //         fopen()
    //     }
    // }

    // closedir(dir);

    FILE *f = fopen("/proc/1/stat", "r");

    int processID = 0;
    int pProcessID = 0;

    fscanf(f, "%d %*s %*c %d", &processID, &pProcessID);

    printf("%d -- %d\n", processID, pProcessID);

    return 0;
}
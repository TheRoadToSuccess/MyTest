#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/time.h> 
#include <string.h>

int getCurTime()
{
//    time_t timep;
//    time (&timep);
//    // printf(“%s”,asctime(gmtime(&timep)));
//    return asctime(gmtime(&timep));

    struct timeval start;
    gettimeofday(&start, NULL );
    // printf("start : %d.%d\n", start.tv_sec, start.tv_usec);
    return start.tv_sec * 1000 + start.tv_usec / 1000;
}



int main (int argc, char *argv[])
{
    struct stat sb;
    off_t len;
    char *p, *pold;
    int fd;

    if (argc < 2) {
        fprintf (stderr, "usage: %s <file>\n", argv[0]);
        return 1;
    }

    printf("[%d], Test Mmap %s Begin === \n", getpid(), argv[1]);

    printf("[%d], begin open time: %u  \n", getpid(), getCurTime());
    fd = open (argv[1], O_RDONLY);
    if (-1 == fd) {
        perror ("open");
        return 1;
    }
    printf("[%d], end open time: %u  \n", getpid(), getCurTime());

    if (-1 == fstat (fd, &sb)) {
        perror ("fstat");
        return 1;
    }
    else {
        printf("[%d], file[%s], size[%d] \n", getpid(), argv[1], sb.st_size);
    }

    if (!S_ISREG (sb.st_mode)) {
        fprintf (stderr, "%s is not a file\n", argv[1]);
        return 1;
    }


    printf("[%d], begin mmap time: %u  \n", getpid(), getCurTime());
    p = (char *)mmap (NULL, sb.st_size, PROT_READ, MAP_SHARED, fd, 0);
    if (p == MAP_FAILED) {
        perror ("mmap");
        return 1;
    }
    pold = p;
    printf("[%d], end mmap time: %u , point [%p] \n", getpid(), getCurTime(), p);


    printf("[%d], read mmap time: %u begin  \n", getpid(), getCurTime());
    char tmp[4096] = { '\0' };
    unsigned int size = sb.st_size / 4096;
    ++size;
    printf("size = %u \n", size);
    for (unsigned int i = 0; i < size; i++) {
        memcpy(tmp, p, 4096);
        p += 4096;
        // printf("i[%d]=[%c]", i, p[i]);
    }
    printf("[%d], read mmap time: %u begin  \n", getpid(), getCurTime());

    printf("[%d], begin sleep time: %u  \n", getpid(), getCurTime());
    sleep(100);
    printf("[%d], end sleep time: %u  \n", getpid(), getCurTime());

    printf("[%d], begin close time: %u  \n", getpid(), getCurTime());
    if (-1 == close (fd)) {
        perror ("close");
        return 1;
    }
    printf("[%d], end close time: %u  \n", getpid(), getCurTime());

    printf("[%d], begin munmap time: %u  \n", getpid(), getCurTime());
    if (-1 == munmap (pold, sb.st_size)) {
        perror ("munmap");
        return 1;
    }
    printf("[%d], end munmap time: %u  \n", getpid(), getCurTime());

    printf("[%d], Test Mmap %u End === \n", getpid(), argv[1]);
    return 0;
}

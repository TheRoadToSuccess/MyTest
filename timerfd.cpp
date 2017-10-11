#include <sys/timerfd.h>
#include <sys/epoll.h>
#include <sys/time.h>
#include <unistd.h>
#include <iostream>
#include <errno.h>
#include <string.h>
#include <stdio.h>

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


int main()
{
    int fd = timerfd_create (CLOCK_MONOTONIC, TFD_NONBLOCK);
    if (-1 == fd) {
        std::cerr << strerror (errno);
        return 1;
    }

    const int size = 10;
    int epollfd = epoll_create (size);
    if (-1 == epollfd) {
        std::cerr << strerror (errno) << "\n";
        return 1;
    }

    epoll_event event;
    epoll_event events[size];

    // add timer to reactor
    event.events = EPOLLIN; // notification is a read event
    event.data.fd = fd; // user data
    int r = epoll_ctl (epollfd, EPOLL_CTL_ADD, fd, &event);
    if (-1 == r) {
        std::cerr << strerror (errno) << "\n";
        close (epollfd);
        close (fd);
        return 1;
    }

    // add event to be triggered
    int flags = 0;
    itimerspec new_timer;
    // 1-second periodic timer
    new_timer.it_interval.tv_sec = 2;
    new_timer.it_interval.tv_nsec = 0;
    new_timer.it_value.tv_sec = 2;
    new_timer.it_value.tv_nsec = 0;
    itimerspec old_timer;

    printf("timerfd_settime 2s [%u] \n", getCurTime());
    int i = timerfd_settime (fd, flags, &new_timer, &old_timer);
    if (-1 == i) {
        std::cerr << strerror (errno) << "\n";
        close (epollfd);
        close (fd);
        return 1;
    }

    // watch possibly other fds
    // ...

    while (true) {

        printf("sleep 2s \n");
        sleep(5);

        printf("reset timerfd_settime 2s time[%u]\n", getCurTime());
        int re = timerfd_settime (fd, flags, &new_timer, NULL);

        const int infinity = -1;
        // and wait for events
        int r = epoll_wait (epollfd, events, size, infinity);
        printf("trigger time [%u] \n", getCurTime());
        if (-1 == r) {
            close (epollfd);
            close (fd);
            return 1;
        }

        // demultiplex events
        int i = 0;
        while (i < r) {
            if (events[i].data.fd == fd) {
                // timer is triggered
                size_t s = 0;
                int i = read (fd, &s, sizeof (s));
                if (i != -1) {
                    std::cout << "Timer triggered (" << s << ")\n";
                    // handle_event();
                }
            }
            ++i;
        }
    }
    close(epollfd);
    close (fd);
    return 0;
}

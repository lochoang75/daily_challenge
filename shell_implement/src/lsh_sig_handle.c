#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

#include "log.h"

void sig_handler(int signum)
{
    switch (signum)
    {
    case SIGINT: 
        log_error("Signal interrupt, Exit");
        exit(0);
        break;
    
    default:
        log_info("Signal not handle %d", signum);
        break;
    }
}

void signal_handler_init(void)
{
    signal(SIGINT, sig_handler);
}
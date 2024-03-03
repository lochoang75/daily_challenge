#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "log.h"

#include "lsh_errors.h"
#include "lsh_main_helper.h"

lsh_errors_t lsh_loop(void)
{
    lsh_errors_t ret = kSUCCESS;
    struct lsh_command_args *cmd_args = NULL;
    char *input_cmd = malloc(sizeof(char) * 100);
    memset(input_cmd, 0, sizeof(char) * 100);
    int size = 100;
    do {
        ret = lsh_read_line(&input_cmd, &size);
        if (ret != kSUCCESS)
        {
            log_error("Error when read command discard, ignore");
            continue;
        }

        ret = lsh_command_parse(input_cmd, &cmd_args);
        if (ret != kSUCCESS)
        {
            log_error("Error when parse command %s", input_cmd);
            continue;
        }

        ret = lsh_execute_cmd(cmd_args);
        if (ret != kSUCCESS)
        {
            log_error("Error when execute command %s", input_cmd);
            continue;
        }
    } while (true);
}

extern void signal_handler_init(void);

int main()
{
    log_debug("Shell start");
    signal_handler_init();
    lsh_executor_init();
    lsh_loop();
    log_debug("Shell exit");
    return 0;
}
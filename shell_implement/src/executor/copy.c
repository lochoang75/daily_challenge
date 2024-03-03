#include "lsh_command.h"
#include "log.h"

#include "stdlib.h"

static int execute_copy(struct lsh_command_args *args);
static struct lsh_command copy_executor = {
    .execute_command = execute_copy,
    .shell_command = "copy",
};

const struct lsh_command *get_copy_executor(void)
{
    return &copy_executor;
}

static int execute_copy(struct lsh_command_args *args)
{
    log_debug("Execute copy command");
    return 0;
}

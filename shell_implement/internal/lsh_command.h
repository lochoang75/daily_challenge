#ifndef LSH_COMMAND_H
#define LSH_COMMAND_H

#define MAX_COMMAND_ARGS 100

struct lsh_command_args {
    int num_arg;
    char *arg[MAX_COMMAND_ARGS];
    char args_pool[0];
};

struct lsh_command {
    const char *shell_command;
    int (*execute_command)(struct lsh_command_args *args);
};

int lsh_command_add(const struct lsh_command* cmd);
int lsh_command_remove(const char *command);
const struct lsh_command *lsh_command_find(const char *command);
#endif /*LSH_COMMAND_H*/
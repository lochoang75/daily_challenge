#ifndef LSH_MAIN_HELPER_H
#define LSH_MAIN_HELPER_H
#include "lsh_errors.h"
#include "lsh_command.h"

lsh_errors_t lsh_read_line(char **output_cmd, int *size);
lsh_errors_t lsh_command_parse(char *cmd, struct lsh_command_args **output_cmd);
lsh_errors_t lsh_execute_cmd(struct lsh_command_args *args);
lsh_errors_t lsh_executor_init(void);
#endif /*LSH_MAIN_HELPER_H*/
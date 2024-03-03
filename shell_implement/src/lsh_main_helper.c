#include "lsh_main_helper.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "log.h"
#include "lsh_command.h"

lsh_errors_t lsh_read_line(char **output_cmd, int *size)
{
    int ret_code = 0;
    int buffer_size = 0;
    char input_char = '\0';
    char *ref = *output_cmd;
    printf("> ");
    do
    {
        input_char = getchar();
        ref[buffer_size ++] = input_char;
        if (buffer_size == *size)
        {
            char *temp = malloc(sizeof(char) * (*size + 100));
            if (temp == NULL)
            {
                log_error("Unable to allocate new memory");
                return kNO_MEM;
            }
            memset(temp, 0, *size + 100);
            memcpy(temp, ref, *size);
            free(ref);
            *output_cmd = temp;
            ref = temp;
            *size = *size + 100;
        }
    } while (input_char != '\n' && input_char != EOF);
    return kSUCCESS;
}

lsh_errors_t lsh_command_parse(char *cmd, struct lsh_command_args **output)
{
    log_info("Execute parse");
    int num_args = 1;
    struct lsh_command_args *output_args = NULL;
    for (int i = 0; i < strlen(cmd); i++)
    {
        if (cmd[i] == ' ')
        {
            num_args ++;
        }

        if (cmd[i] == '\r' || cmd[i] == '\n')
        {
            cmd[i] = '\0';
        }
    }

    if (num_args > MAX_COMMAND_ARGS)
    {
        log_error("Number of args over max args");
        return kFAILED;
    }

    output_args = (struct lsh_command_args *)malloc(sizeof(struct lsh_command_args) 
                                                    +strlen(cmd));
    if (output_args == NULL)
    {
        log_error("Unable to allocate memory");
        return kFAILED;
    }
    output_args->num_arg = num_args;

    int arg_count = 0;
    int pool_address = 0;
    char *save_ptr = NULL;
    char *arg = strtok_r(cmd, " ", &save_ptr);
    while (arg != NULL)
    {
        log_debug("Parse args %s", arg);
        output_args->arg[arg_count] = &output_args->args_pool[pool_address];
        memcpy(output_args->arg[arg_count], arg, strlen(arg));
        arg_count ++;
        pool_address += strlen(arg);
        arg = strtok_r(NULL, " ", &save_ptr);
    }
    *output = output_args;
    return kSUCCESS;
}

lsh_errors_t lsh_execute_cmd(struct lsh_command_args *cmd_args)
{
    log_info("Find command, %s", cmd_args->arg[0]);
    struct lsh_command *exec_cmd = lsh_command_find(cmd_args->arg[0]);
    if (exec_cmd != NULL)
    {
        log_info("Execute command");
        exec_cmd->execute_command(cmd_args);
    } else
    {
        log_error("Command not found");
    }
    return kSUCCESS;
}

extern const struct lsh_command *get_copy_executor(void);

lsh_errors_t lsh_executor_init(void)
{
    const struct lsh_command *copy_executor = get_copy_executor();
    lsh_command_add(copy_executor);
}
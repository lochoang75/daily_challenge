#include <stdlib.h>
#include <string.h>

#include "lsh_command.h"
#include "linked_list.h"
#include "log.h"

struct command_entry {
    struct list_node node;
    const struct lsh_command *cmd;
};

struct list_node command_head = {.container = NULL, .next = &command_head, .prev = &command_head};

int lsh_command_add(const struct lsh_command *cmd)
{
    struct command_entry *entry = (struct command_entry*)malloc(sizeof(struct command_entry));
    if (entry == NULL)
    {
        log_error("Unable to allocate memory for entry");
        return -1;
    }
    entry->node.container = entry;
    entry->cmd = cmd;
    log_debug("Add command %s", cmd->shell_command);

    list_add_tail(&command_head, &entry->node);
    return 0;
}

int lsh_command_remove(const char *cmd_name)
{
    return 0;
}

const struct lsh_command *lsh_command_find(const char *cmd_name)
{
    struct list_node *node = NULL;
    struct list_node *head = &command_head;
    FOR_EACH_NODE(node, head)
    {
        struct command_entry *container = (struct command_entry*) node->container;
        if (!strcmp(container->cmd->shell_command, cmd_name))
        {
            return container->cmd;
        }
    }

    return NULL;
}
class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left =left
        self.right = right
    pass


def serialize(node: Node) -> str:
    ret_str = node.val
    if node.left is None:
        ret_str += ", "
    else:
        ret_str += "," + serialize(node.left)

    if node.right is None:
        ret_str += ", "
    else:
        ret_str += "," + serialize(node.right)

    return ret_str

def deserialize(sentences: str) -> Node:
    node_array = sentences.split(",")
    print(node_array)
    node_list = []
    root = Node(node_array[0])
    node_list.append([root, 2])
    current_node = 0
    for i in range (1, len(node_array)):
        if node_array[i] != ' ':
            new_node = Node(node_array[i])
            if node_list[current_node][1] == 2:
                node_list[current_node][1] = 1
                node_list[current_node][0].left = new_node
                current_node = -1
                node_list.append([new_node, 2])
            elif node_list[current_node][1] == 1:
                node_list[current_node][0].right = new_node
                node_list[current_node][1] = 0
                node_list.append([new_node, 2])
                for j in range (len(node_list) - 1, -1, -1):
                    if node_list[j][1] > 0:
                        current_node = j
                        break
        if node_array[i] == ' ':
            node_list[current_node][1] -= 1
            if node_list[current_node][1] == 0:
                for j in range (len(node_list) - 1, -1, -1):
                    if node_list[j][1] > 0:
                        current_node = j
                        break
    return root

if __name__ == "__main__":
    node = Node('root', Node('left', Node('left.left'), Node("left.right")), Node('right'))
    print((serialize(deserialize(serialize(node)))).split(","))


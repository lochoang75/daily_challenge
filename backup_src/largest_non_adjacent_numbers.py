import sys

def convert_argv_to_int_list(argv_list: list)-> list:
    number_list = []
    for number in range (1, len(argv_list)):
        number_list.append(int(sys.argv[number]))
    return number_list


def find_largest_sum(num_list: list) -> int:
    n = len(num_list)
    if n == 0:
        return 0
    if n == 1:
        return num_list[0]
    stack = [None] * n
    stack[0] = num_list[0]
    stack[1] = num_list[1]
    for i in range(2, n):
        stack[i] = max(stack[i-1], stack[i-2] + num_list[i])
        stack[i] = max(stack[i], num_list[i])
    return stack[-1]

def find_largest_sum_no_extra_space(num_list: list) -> int:
    n = len(num_list)
    if n == 0:
        return 0
    if n == 1:
        return num_list[0]
    prev = num_list[0]
    max_cur = max(num_list[0], num_list[1])
    for i in range(2, n):
        max_temp = max(max_cur, prev + num_list[i])
        max_temp = max(max_temp, max_cur)
        prev = max_cur
        max_cur = max_temp
    return max_cur


if __name__ == "__main__":
    list_number = convert_argv_to_int_list(sys.argv)
    print("Largest sum is: ", find_largest_sum_no_extra_space(list_number))

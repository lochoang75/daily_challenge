import sys

def is_decode_able(test_num: int) -> bool:
    if (test_num > 1) and (test_num < 27):
        return True
    else:
        return False

def iterate_string(test_str: str) -> int:
    number_of_decodes = 0
    is_contain_zero = False
    for i in range(1, len(test_str)):
        number = int(test_str[i - 1: i + 1], base=10)
        if number  < 11:
            is_contain_zero = True
        if is_decode_able(number):
            number_of_decodes += 1
    if not is_contain_zero:
        number_of_decodes += 1
    return number_of_decodes


if __name__ == "__main__":
    print("Number of decodes: ", iterate_string(sys.argv[1]))


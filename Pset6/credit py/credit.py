from cs50 import get_string


def main():
    card = get_string("Number: ")
    check = check_format(card)
    if (check):
        is_valid = valid(card)
        if (is_valid):
            card_type(card)
        else:
            print("INVALID\n")
    else:
        print("INVALID\n")


def check_format(s):
    if len(s) != 13 and len(s) != 15 and len(s) != 16:
        return False
    else:
        return s.isdigit()


def valid(s):
    sum = 0
    N = len(s)
    s = int(s)
    for i in range(N):
        digit = s % 10
        if i % 2 == 0:
            sum += digit
            # print(sum)
        else:
            digit *= 2
            sum += (digit // 10 + digit % 10)
            # print(sum)
        s //= 10
    if sum % 10 == 0:
        return True
    else:
        return False
        
        
def card_type(s):
    first2 = s[0: 2]
    if len(s) == 13 and s.index(0) == "4":
        print("VISA\n")
    elif len(s) == 15 and (first2 == "37" or first2 == "37"):
        print("AMEX\n")
    elif len(s) == 16:
        if s[0] == "4":
            print("VISA\n")
        elif first2 in ["51", "52", "53", "54", "55"]:
            print("MASTERCARD\n")
    else:
        print("INVALID\n")


main()
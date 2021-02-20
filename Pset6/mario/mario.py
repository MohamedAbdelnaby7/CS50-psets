from cs50 import get_int

while True:
    h = get_int("Height: ")
    if h > 0 and h <= 8:
        break

for i in range(1, h + 1):
    hashes = i
    spaces = h - hashes
    print(" " * spaces, end="")
    print("#" * hashes, end="")
    print(" " * 2, end="")
    print("#" * hashes, end="")
    print()
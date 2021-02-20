from cs50 import get_float

while True:
    cash = get_float("cash owed: ")
    if cash > 0:
        cash = round(cash * 100)
        coins = 0
        while cash > 0:
            if cash / 25 >= 1:
                cash -= 25
            elif cash / 10 >= 1:
                cash -= 10
            elif cash / 5 >= 1:
                cash -= 5
            else:
                cash -= 1
            coins += 1
        print(coins)
        break

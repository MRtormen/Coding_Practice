#!/usr/bin/python3

def parse_int(string):
    string = string.replace("-", " ")
    list = string.split()
    small_numbers = {"zero": 0, "one": 1, "two": 2, "three": 3, "four": 4, "five": 5, "six": 6,\
                     "seven": 7, "eight": 8, "nine": 9, "ten": 10, "eleven": 11, "twelve": 12, "thirteen": 13,\
                     "fourteen": 14, "fifteen": 15, "sixteen": 16, "seventeen": 17, "eighteen": 18, "nineteen": 19,\
                     "twenty": 20, "thirty": 30, "forty": 40, "fifty": 50, "sixty": 60, "seventy": 70, "eighty": 80,\
                     "ninety": 90}
    big_numbers = {"hundred": 100, "thousand": 1000, "million": 1000000}
    total = 0
    n = 0
    for word in list:
        if word in small_numbers:
            n += small_numbers[word]
        elif word in big_numbers:
            x = n * big_numbers[word]
            if total < x:
                total = total * big_numbers[word] + x
            elif n == 0:
                total = total * big_numbers[word]
            else:
                total += x
            n = 0
    total += n
    return total

import csv
import sys
import operator


def main():
    # check if there are three terminal arguments
    if len(sys.argv) != 3:
        print("usage error, dna.py sequence.txt database.csv")
        exit(1)

    # opens the dna file for someone and save it in a string dna
    with open(sys.argv[2]) as dnatxt:
        dna = dnatxt.readline()
        # print (dna)

    STRS = {}
    # taking the STRS names in the first row of the csv file
    with open(sys.argv[1]) as dbcsv:
        dbreader = csv.reader(dbcsv)
        for row in dbreader:
            strs = row
            # removing the fist item "name"
            strs.pop(0)
            break
            # print(strs)

    # making a dicitionary where STRs are the keys
    for item in strs:
        STRS[item] = 1
        # print(STRS)
        
    # check for series of the same STR individually
    # by taking each STR and search for equality substring in the dna
    for STR in STRS:
        temp = STRmax = 0
        l = len(STR)
        
        # for the ith character + the key length chechs for equality
        for i in range(len(dna)):
            temp = 0
            
            # if true continue to check if the size of key before it is similar
            if dna[i: i + l] == STR:
                while dna[i - l: i] == dna[i: i + l]:
                    # for each eqality add one and incease the size of the key
                    i += l
                    temp += 1
                # if already the found pattern is larger than the stored sequence overwrite it
                if temp > STRmax:
                    STRmax = temp
                    
        STRS[STR] += STRmax

    with open(sys.argv[1], newline='') as dbcsv:
        persons = csv.DictReader(dbcsv)
        for person in persons:
            likely = 0
            for dna in STRS:
                if STRS[dna] == int(person[dna]):
                    likely += 1
            if likely == len(STRS):
                print(person['name'])
                exit(1)
                
    print("No match")


if __name__ == "__main__":
    main()

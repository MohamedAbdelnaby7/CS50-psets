from cs50 import get_string 


def main():
    text = get_string("Text: ")
    letters, words, sentences = counting(text)
    degree = calculate_Degree(letters, words, sentences)
    if degree >= 1 and degree <= 16:
        print(f"Grade {degree}")
    elif degree < 1:
        print("Before Grade 1")
    else:
        print("Grade 16+")

    
def counting(s):
    words = 1
    letters = sentences = 0
    for c in s:
        if c.isalpha():
            letters += 1
        elif c in [" "]:
            words += 1
        elif c in ["!", ".", "?"]:
            sentences += 1
    #print(letters, words, sentences)
    return letters, words, sentences

 
def calculate_Degree(l, w, s):
    l = 100 * l / w
    s = 100 * s / w
    #print(l, w, s)
    return round(0.0588 * l - 0.296 * s - 15.8)
    
    
if __name__ == "__main__":
    main()
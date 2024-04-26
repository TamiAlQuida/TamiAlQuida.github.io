name = input("you say that you're in the beatles, what's your name?".capitalize()).capitalize()
beatle = False
beatles = {"Georgie", "Paulie", "Johny", "Ringie"}
beatle = name in beatles
# Onödigt att ha 2 false egentligen

if (name == "Ringo" or
    name == "John" or
    name == "Paul" or
    name == "George" or
    name in beatles):
    beatle = True
else:
    beatle = False

print("I knew it was", beatle)



a = True
b = False
print(type(b))
name = "Muad"
if name:
    print("the name is {}".capitalize().format(name))
else:
    print('name is missing')

if 3 >= len(name) > 0:
    print('it has got more than 0 letters, less than 3')
elif len(name) > 3:
    print("it has got more than 3 letters, %s" % name)
else:
    print('no letters'.capitalize())

# nästa del är lite klurig

score = int(input("how much did you score?"))

print(type(score))

if 85 < score <= 100:
    grade = "A"
if 60 < score <= 85:
    grade = "B"
print(grade)




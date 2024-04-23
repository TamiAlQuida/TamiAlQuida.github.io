status = "off"
wattage = "120 watt"
print(status)
print(wattage)
incadecent = wattage
wattage = "25 watt"
print(wattage, incadecent)

pi = 3.1495
r = 10
print(float((r ** 2) * pi))

b = 10
h = 2
print(b * 2 + h * 2)

b = 6
print(b * 2 + h * 2)

print(id(b))

print(type(pi))

names = ['fred']
print(id(names))
print(names)
names.append("Fred")
print(names)
print(id(names))

print(dir())

knopolle = 1.852
print(type(knopolle))
print(id(knopolle))
print(knopolle == 1.852)
if knopolle > 0:
    print('yahoooooooooooo')
else:
    print('naahiiii')

knopolle = knopolle + 20
print(type(knopolle))
print(id(knopolle))
print(knopolle == 1.852)

print(dir())

mph = [3]
print(mph)
print(type(mph))
print(id(mph))
mph.append(16)
print(mph)
print(type(mph))
print(id(mph))

print('num: %s' % 2)

print(int(3.9))
print(float(6))

print((6.2 + 7 + 8 + 5 + 6.5 + 7.1 + 8.5) / 7)
print(297 / 3)
print(297 % 3)
print(298 % 3)
print(299 % 3)
print(2 ** 10)

year = int(input('what years is a leap year?'))
no = "no It isn't"
nope = str(no.replace('no ', 'nooope ').lower().capitalize())
if year % 4 == 0 and year % 100 != 0:
    print("%s %s %d" % ('yes', 'it is', 3))

elif year % 400 == 0:
    print("%s %s %d" % ('yes', nope, 3))


else:
    print(nope)

    print(dir('year'))
    print(type(year))

    print('Naah, ''{} {} {}'.format(
        'my',
        'man,',
        nope
    ))

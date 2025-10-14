
import locale

print(locale.getpreferredencoding(False))

x_sq = 'x\u00b2'
print(x_sq.encode('utf-8'))
print(x_sq.encode('ascii', errors='ignore'))
print(x_sq.encode('ascii', errors='replace'))

print(b'x\xc2\xb2'.decode('cp1026')) # Turkish
print(b'x\xc2\xb2'.decode('cp949'))  # Korean
print(b'x\xc2\xb2'.decode('shift_jis_2004'))  # Japanese


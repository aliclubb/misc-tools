import sys
c = 0
while (c != 10):
	c = ord(sys.stdin.read(1))
	if ((c >= 78 and c < 92) or (c >= 110)):
		t = 0
		while ((c >= 78 and c < 92) or (c >= 110)):
			c = c - 1
			t = t + 1
		if (c > 92):
			sys.stdout.write(chr(96 + t))
		else:
			sys.stdout.write(chr(64 + t))
	elif (c != 32 and c > 60):
		sys.stdout.write(chr(c + 13))
	elif (c == 32):
		sys.stdout.write(chr(c))
	elif (c >= 53):
		t = 0
		while (c >= 54):
			c = c - 1
			t = t + 1
		sys.stdout.write(chr(48 + t))
	else:
		sys.stdout.write(chr(c + 5))
#!/usr/bin/python

def main():
	for i in range ( 1, 100 ):
		if ( i % 5 == 0 ) and ( i % 3 == 0 ):
			print "FizzBuzz";
		elif ( i % 3 == 0 ):
			print "Fizz";
		elif ( i % 5 == 0 ):
			print "Buzz";
		else:
			print i;

if __name__ == '__main__':
        main()



strtest: DEVISE.c
	gcc DEVISE.c -o devise

clean:
	rm *~

run: strtest
	./devise

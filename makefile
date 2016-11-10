sigtest: main.c
	gcc main.c -o sigtest

run: sigtest
	./sigtest

clean:
	rm sigtest
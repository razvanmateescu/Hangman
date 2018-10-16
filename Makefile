build: hangman.c
	gcc -g -Wall -o hangman hangman.c
run: hangman
	./hangman
clean: 
	$(RM) hangman



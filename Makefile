build:
	clang -o main -Wall -Wextra ./main.c ./list.c 
run: 
	clang -o main -Wall -Wextra ./main.c ./list.c  && ./main

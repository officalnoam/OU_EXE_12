magic: magic.exe

magic.exe: magic/magic.o magic/string_utils.o magic/input_utils.o magic/sort_utils.o magic/validation.o magic/matrix.o
	gcc -ansi -Wall -pedantic -o magic.exe magic/magic.o magic/string_utils.o magic/input_utils.o magic/sort_utils.o magic/validation.o magic/matrix.o

magic/magic.o: magic/magic.c magic/magic.h magic/string_utils.h magic/input_utils.h magic/validation.h magic/matrix.h
	gcc -ansi -Wall -pedantic -c magic/magic.c -o magic/magic.o

magic/string_utils.o: magic/string_utils.c magic/string_utils.h magic/boolean.h
	gcc -ansi -Wall -pedantic -c magic/string_utils.c -o magic/string_utils.o

magic/input_utils.o: magic/input_utils.c magic/input_utils.h
	gcc -ansi -Wall -pedantic -c magic/input_utils.c -o magic/input_utils.o

magic/sort_utils.o: magic/sort_utils.c magic/sort_utils.h
	gcc -ansi -Wall -pedantic -c magic/sort_utils.c -o magic/sort_utils.o

magic/validation.o: magic/validation.c magic/validation.h magic/boolean.h magic/sort_utils.h magic/input_utils.h magic/string_utils.h
	gcc -ansi -Wall -pedantic -c magic/validation.c -o magic/validation.o

magic/matrix.o: magic/matrix.c magic/matrix.h magic/boolean.h magic/input_utils.h
	gcc -ansi -Wall -pedantic -c magic/matrix.c -o magic/matrix.o

cleanup:
	rm magic/*.o

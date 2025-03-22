magic: magic.exe

magic.exe: magic/magic.o magic/string_utils.o magic/input_utils.o
	gcc -ansi -Wall -pedantic -o magic.exe magic/magic.o magic/string_utils.o magic/input_utils.o

magic/magic.o: magic/magic.c magic/string_utils.h magic/input_utils.h
	gcc -ansi -Wall -pedantic -c magic/magic.c -o magic/magic.o

magic/string_utils.o: magic/string_utils.c magic/string_utils.h magic/boolean.h
	gcc -ansi -Wall -pedantic -c magic/string_utils.c -o magic/string_utils.o

magic/input_utils.o: magic/input_utils.c magic/input_utils.h
	gcc -ansi -Wall -pedantic -c magic/input_utils.c -o magic/input_utils.o

cleanup:
	rm magic/*.o

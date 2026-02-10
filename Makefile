# Makefile is the text file the make utility will look for

# main is the target
# main.cc is the prerequisite
# if main is out of date (doesn't exist or has been updated)

# $@ = the target
# $< = the first prerequisite
# $^ = all prerequisites

compiler = g++
flags = -Wall -std=c++17
link = $(compiler) $(flags)
compile = $(compiler) $(flags) -c

main : main.o nishant_functions.o braden_functions.o
	$(link) $^ -o $@
	./$@

main.o : main.cc nishant_functions.h braden_functions.h
	$(compile) $<

nishant_functions.o : nishant_functions.cc nishant_functions.h
	$(compile) $<

braden_functions.o : braden_functions.cc braden_functions.h
	$(compile) $<

clean :
	rm *.o main
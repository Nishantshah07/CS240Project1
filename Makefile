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

main : main.o helper_functions.o
	$(link) $^ -o $@
	./$@

main.o : main.cc helper_functions.h
	$(compile) $<

helper_functions.o : helper_functions.cc helper_functions.h
	$(compile) $<

clean :
	rm *.o main
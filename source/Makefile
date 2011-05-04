CPP=g++
FLAGS=-Wall -Wextra -pedantic -g
FILES=parser/*.h parser/*.cpp elementaryMath/*.cpp elementaryMath/*.h

main: $(FILES)
	$(CPP) $(FLAGS) -I elementaryMath/ $? -o $@

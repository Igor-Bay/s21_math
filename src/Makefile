CC=gcc
BUILDFLAGS=-std=c11 -Wall -Wextra -Werror
CFLAGS=$(BUILDFLAGS) -c

LINUXFLAGS:=
ifeq ($(shell uname -s),Linux)
	LINUXFLAGS += -lm -lrt -lsubunit 
# -lstdc++
endif

HEADERS=s21_math.h
SOURCES=$(addprefix s21_math_functions/,s21_math_basic_functions.c s21_math_trigonometric_functions.c s21_math_inv_trig_functions.c s21_math_power_functions.c)
OBJECTS=$(SOURCES:.c=.o)

FILES_TO_CHECK=$(SOURCES) $(HEADERS)

all: s21_math.a

%.out: %.o $(OBJECTS)
	$(CC) $^ -o $@
	
%.o: %.c
	$(CC) $(CFLAGS) $(LINUXFLAGS) $^ -o $@ 

s21_math.a:  $(OBJECTS)
	ar rcs s21_math.a $^
	ranlib s21_math.a

main: clean s21_math.a
	$(CC) -o main.out $(BUILDFLAGS) main.c s21_math.a

clean: 
	@rm -rf  $(OBJECTS) 
# $(SPRINT_OBJECTS) $(SSCAN_OBJECTS) $(GCDA_FILES) $(GCNO_FILES) $(GCOV_FILES) 
	@rm -rf report/ s21_math.a *.gcda *.gcno *.gcov *.out *.info *.o coverage.txt *.dSYM

.clang-format:
	@cp ../materials/linters/.clang-format .
	
stylecheck: .clang-format
	@clang-format -n $(FILES_TO_CHECK)
	
fmt: .clang-format
	@clang-format -i $(FILES_TO_CHECK) main.c
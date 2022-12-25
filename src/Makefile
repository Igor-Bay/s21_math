CC=gcc
BUILDFLAGS=-std=c11 -Wall -Wextra -Werror
CFLAGS=$(BUILDFLAGS) -c

TESTFLAGS:=
ifeq ($(shell uname -s),Linux)
	TESTFLAGS += -lm -lrt -lsubunit
endif

TESTFLAGS += -lcheck -lpthread -pthread

GCOVFLAGS = -fprofile-arcs -ftest-coverage

LINUXFLAGS:=
ifeq ($(shell uname -s),Linux)
	LINUXFLAGS += -lm -lrt -lsubunit 
# -lstdc++
endif

HEADERS=s21_math.h
SOURCES=$(addprefix s21_math_functions/,s21_math_basic_functions.c s21_math_trigonometric_functions.c s21_math_inv_trig_functions.c s21_math_power_functions.c s21_math_round_functions.c s21_math_fmod.c)
OBJECTS=$(SOURCES:.c=.o)
TESTS_SOURCES=test.c

FILES_TO_CHECK=$(SOURCES) $(HEADERS)

.PHONY: test rebuild clean stylecheck fmt
.SECONDARY: $(OBJECTS)


all: s21_math.a

%.out: %.o $(OBJECTS)
	$(CC) $^ -o $@
	
%.o: %.c
	$(CC) $(CFLAGS) $(LINUXFLAGS) $^ -o $@ 

s21_math.a:  $(OBJECTS)
	ar rcs s21_math.a $^
	ranlib s21_math.a

gcov_report: test
	lcov -t test.out -o test.info -c -d .
	genhtml -o report test.info
	open report/index.html

report_nolcov:
	gcov *gcno > coverage.txt
	open coverage.txt

test: test_s21_math.a
	$(CC) $(TESTS_SOURCES) $(TESTFLAGS) $(GCOVFLAGS) -L. s21_math.a -o test.out
	./test.out

test_s21_math.a: all_functions
	ar rcs s21_math.a *.o
	ranlib s21_math.a

all_functions: $(SOURCES)
	$(CC) $(CFLAGS) $^ $(GCOVFLAGS)

rebuild: clean all

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
	@clang-format -i $(FILES_TO_CHECK) main.c check_test.check
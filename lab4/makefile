CC = gcc
OUT = parser
OBJ = lex.yy.c y.tab.c ast.c Semantic.c
SCANNER = scanner.l
PARSER = parser.y

build: $(OUT)

run: $(OUT)
	./$(OUT) < test.c

clean:
	rm -f *.o lex.yy.c y.tab.c y.tab.h y.output $(OUT)

$(OUT): $(OBJ)
	$(CC) -g $(OBJ) -o $(OUT)

lex.yy.c: $(SCANNER)
	flex $<

y.tab.c: $(PARSER)
	bison -vdty $<

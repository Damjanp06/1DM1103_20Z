DEPS=mymatlab.o mat.o inout.o

mymatlab: $(DEPS)
	cc $(DEPS) -o $@ -lm
%.o:%c
	cc -c $^ -o $@ -lm

clean:
	rm -f mymatlab
	rm -f *.o

norm: mymatlab
	./mymatlab norm A.txt

multiply: mymatlab
	./mymatlab multiply A.txt 5

sum: mymatlab
	./mymatlab sum A.txt x.txt

subtract: mymatlab
	./mymatlab subtract A.txt x.txt

prod: zad6
	./mymatlab prod A.txt x.txt

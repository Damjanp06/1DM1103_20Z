DEPS=zad5.o studenci.o dziekanat.o

zad5: $(DEPS)
	cc $(DEPS) -o $@
%.o:%c
	cc -c $^ -o $@

clean:
	rm -f zad5
	rm -f *.o

studenci: zad5
	./zad5 studenci.txt studenci

przedmioty: zad5
	./zad5 studenci.txt przedmioty




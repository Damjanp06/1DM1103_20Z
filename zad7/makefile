all:
	cc baza.c main.c -o mydb -Wall --pedantic

test: all
	./mydb baza.csv list_all

test-ile: all
	./mydb baza.csv count_students

test-add_student: all
	./mydb baza.csv add_student Adam Zajac 444222 zaj@c.pl

test-add_course: all
	./mydb baza.csv add_course 1DE2103 "Metody numeryczne" 2020Z

test-add_student_to_course: all
	./mydb baza.csv add_student_to_course 123456 1DE1203


test-memory: all
	valgrind ./mydb baza.csv count_students
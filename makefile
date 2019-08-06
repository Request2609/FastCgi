main:post.o fcgi.o 
	clang++ -std=c++11  post.o fcgi.o  -o main
main.o:fcgi.h
	clang++ -std=c++11 -c  main.cpp
fcgi.o:fcgi.h
	clang++ -std=c++11 -c fcgi.cpp
.PHONY:clean
clean:
	rm *.o main

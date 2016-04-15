# Make file

net367: host.o utilities.o link.o man.o main.o net.o switch.o table.o queue.o
	gcc -o net367 host.o utilities.o link.o man.o main.o net.o switch.o table.o queue.o

main.o: main.c
	gcc -c main.c

host.o: host.c 
	gcc -c host.c  

switch.o: switch.c
	gcc -c switch.c

man.o:  man.c
	gcc -c man.c

net.o:  net.c
	gcc -c net.c

utilities.o: utilities.c
	gcc -c utilities.c

link.o:  link.c
	gcc -c link.c

table.o: table.c
	gcc -c table.c

queue.o: queue.c
	gcc -c queue.c

clean:
	rm -f *.o

real_clean: clean
	rm -f net367

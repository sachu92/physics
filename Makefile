
all : 
	for f in Makefile.*;do make -f $f;done
clean: 
	rm -rf *.o
	rm -rf *.dat
	rm -rf $(EXEC)

slr : parsing_table.o reduce.o slr.o tokenize.o reduce_by_product1.o \
		reduce_by_product2.o reduce_by_product3.o reduce_by_product4.o \
		reduce_by_product5.o reduce_by_product6.o
		g++ -o slr parsing_table.o reduce.o slr.o tokenize.o \
		reduce_by_product1.o reduce_by_product2.o reduce_by_product3.o \
		reduce_by_product4.o reduce_by_product5.o reduce_by_product6.o

parsing_table.o : parsing_table.cpp header.h
		g++ -c parsing_table.cpp

reduce.o : reduce.cpp header.h
		g++ -c reduce.cpp

slr.o : slr.cpp header.h
		g++ -c slr.cpp

tokenize.o : tokenize.cpp header.h
		g++ -c tokenize.cpp

reduce_by_product1.o : reduce_by_product/reduce_by_product1.cpp header.h
		g++ -c reduce_by_product/reduce_by_product1.cpp

reduce_by_product2.o : reduce_by_product/reduce_by_product2.cpp header.h
		g++ -c reduce_by_product/reduce_by_product2.cpp

reduce_by_product3.o : reduce_by_product/reduce_by_product3.cpp header.h
		g++ -c reduce_by_product/reduce_by_product3.cpp

reduce_by_product4.o : reduce_by_product/reduce_by_product4.cpp header.h
		g++ -c reduce_by_product/reduce_by_product4.cpp

reduce_by_product5.o : reduce_by_product/reduce_by_product5.cpp header.h
		g++ -c reduce_by_product/reduce_by_product5.cpp

reduce_by_product6.o : reduce_by_product/reduce_by_product6.cpp header.h
		g++ -c reduce_by_product/reduce_by_product6.cpp

clean : 
		rm slr *.o

#预处理
CPPFLAGS=
CFLAGS=-I./include/
#优化
OFLAGS=-O
#debug
DGFLAGS=-g
LDFLAGS=-L./lib
LIBS=-lutils -lpthread
#编译
MYCFLAGS=$(CPPFLAGS) $(CFLAGS) $(OFLAGS) $(DGFLAGS)
#库路径
LIBDIR=./lib

#模式规则
%.o : %.c
	$(CC) -c $(MYCFLAGS) $< -o $@

all:
	#TODO

libutils.a: $(LIBDIR)/utils.o
	$(AR) rcs $(LIBDIR)/$@ $<

#FIXME
e-4-1.out: libutils.a

e-4-1.out: e-4-1.o
	#FIXME: the order of $<
	$(CC) $(MYCFLAGS) $(LDFLAGS) $< $(LIBS) -o $@


clean:
	rm -rf *.o *.out lib/*.o lib/*.a

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
#*: libutils.a

# need an auto mode
e-4-1.out: e-4-1.o
	$(CC) $(MYCFLAGS) $(LDFLAGS) $< $(LIBS) -o $@

s-4-2.out: s-4-2.o
	$(CC) $(MYCFLAGS) $(LDFLAGS) $< $(LIBS) -o $@

e-4-2.out: e-4-2.o
	$(CC) $(MYCFLAGS) $(LDFLAGS) $< $(LIBS) -o $@

clean:
	rm -rf *.o *.out lib/*.o lib/*.a

.PHONY: clean

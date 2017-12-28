#头文件及库路径
CFLAGS=-I./include/ -L./lib
#优化
OFLAGS=-O
#调试
DGFLAGS=-g
#警告
WARNFLGS=-Wall -Werror -Wfatal-errors

#库路径
LIBDIR=./lib
#函数库
LIBS=-lutils -lpthread

#编译
MYCFLAGS=$(CFLAGS) $(WARNFLGS) $(DGFLAGS) $(OFLAGS)

#模式规则
%.o : %.c
	$(CC) -c $(MYCFLAGS) $< -o $@

all:
	#TODO

libutils.a: $(LIBDIR)/utils.o
	$(AR) rcs $(LIBDIR)/$@ $<

# need an auto mode
e-4-1.out: e-4-1.o
	$(CC) $(MYCFLAGS) $< $(LIBS) -o $@

s-4-2.out: s-4-2.o
	$(CC) $(MYCFLAGS) $< $(LIBS) -o $@

e-4-2.out: e-4-2.o
	$(CC) $(MYCFLAGS) $< $(LIBS) -o $@

clean:
	rm -rf *.o *.out lib/*.o lib/*.a

.PHONY: clean

#头文件路径
HDPATHS = -I./include
#库路径
LBPATHS = -L./lib
#优化
OFLAGS = -O0
#调试
DGFLAGS = -g -DDEBUG
#警告
WARNFLGS = -Wall -Werror

#函数库
LIBS = -lutils -lpthread

#编译
CPFLAGS = $(HDPATHS) $(WARNFLGS) $(DGFLAGS) $(OFLAGS)
#链接
LKFLAGS = $(LBPATHS) $(LIBS) $(WARNFLGS) $(DGFLAGS) $(OFLAGS)

#模式规则
%.o : %.c
	$(CC) -c $(CPFLAGS) $< -o $@

all:

libutils.a: lib/utils.o
	$(AR) rcs lib/$@ $<

list := s-4-2 e-4-2 s-6-5 s-6-3
#TODO
#list ?= s-4-2 e-4-2 s-6-5 s-6-3
#list = s-4-2 e-4-2 s-6-5 s-6-3

define pattern
$(1).out: libutils.a $(1).o
	$(CC) $(LKFLAGS) $(1).o $(LIBS) -o $(1).out
endef

#$(foreach file, $(list), $(warning $(call pattern, $(file))))
$(foreach file, $(list), $(eval $(call pattern, $(file))))

clean:
	rm -rf *.o *.out lib/*.o lib/*.a

#TODO
.PHONY: clean

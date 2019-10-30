DESTDIR = /home/bjorn/sandbox/kernel/sdm845/test-extras/usr
CC := aarch64-linux-gnu-gcc

OUT := schedlooper

CFLAGS := -Wall -g -O2
LDFLAGS := 

SRCS := schedlooper.c

OBJS := $(SRCS:.c=.o)

$(OUT): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

install: $(OUT)
	install -D -m 755 $< $(DESTDIR)$(prefix)/bin/$<

clean:
	rm -f $(OUT) $(OBJS)

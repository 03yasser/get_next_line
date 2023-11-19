SRCS = get_next_line_utils.c get_next_line.c
all : $(SRCS)
	rm -rf a.out
	cc -W -W -W $(SRCS) -g -fsanitize=address
	./a.out

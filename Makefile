SRC = src/main.c

# `-Wall` and `-Wextra` show useful warnings.
all:
	cc -Wall -Wextra $(SRC) -o sysmonitor;

clean:
	rm -f sysmonitor;

# Makefile Projet Algo Akinator

# https://caiorss.github.io/C-Cpp-Notes/compiler-flags-options.html
# https://gcc.gnu.org/onlinedocs/gcc/Debugging-Options.html
# https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html

all: options

options:
	@echo ========== UTILISATION ==========
	@echo "make release" : Compiler un executable en mode Release
	@echo "make debug" : Compiler un executable en mode Debug
	@echo =================================

release:
	gcc -std=c17 -Wall -Wextra -O2 -s -DNDEBUG src/*.c -o bin/Akinator -I include -m64

debug:
	gcc -std=c17 -Wall -Wextra -Og -g3 src/*.c -o bin/Akinator -I include -m64

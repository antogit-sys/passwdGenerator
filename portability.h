
#define C 100

#if __linux__	//se è un sistema linux dichiara
#	define	USE	"\t./namefile [name] [nchar] --opts [n]"
#	define USEXAMPLE	"\t./passwdGenerator instagram 32 --opts 1\n"
#elif __APPLE__ //altrimenti se è un sistema apple dichiara
#	define USE	"\t./namefile [name] [nchar] --opts [n]"
#	define USEXAMPLE	"\t./passwdGenerator instagram 32 --opts 1\n"
#elif _WIN32 || _WIN64 || __CYGWIN__ || __CYGWIN32__ //altrimenti se è un sistema winzzoz dichiara
#	define USE	"\tnamefile.exe [name] [nchar] --opts [n]"
#	define USEXAMPLE	"\tpasswdGenerator.exe instagram 32 --opts 1\n"
#endif

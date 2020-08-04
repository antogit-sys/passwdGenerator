**{ PasswdGenerator }**

tool programmato in C con licenza gplv3,è in grado di generare una password pseudocasuale facendo uso di diversi parametri;alla prima esecuzione verra creato un file chiamato filePass.txt in cui sono contenuti tutti i futuri nomi e le corrispettive password associate.



**1)compiled Linux:**

```shell
./make.sh
```

**2)compiled Winzzoz:** 

*32bit*

```batch
gcc -m32 mainPasswd.c passwdFunc.c -o passGenerator 
```

*64 bit*

```batch
gcc mainPasswd.c passwdFunc.c -o passGenerator 
```

**=================================**

**instruction**

```shell
./passGenerator
```

or

```shell
./passGenerator --h
```

or

```shell
./passGenerator help
```

or

```shell
./passGenerator --help
```

or

```shell
./passGenerator -h
```



*output:*

```shell
+----------------------+
|    passwdGenerator   |
+----------------------+

USE:

	./passwdGenerator [name] [nchar] --opts [n]

NUMBER OPTIONS:

	 --opts 1	caratteri completi
	 --opts 2	solo lettere minuscole
	 --opts 3	solo lettere MAIUSCOLE
	 --opts 4	solo numeri(pin)

USE EXAMPLE:

	./passwdGenerator instagram 32 --opts 1

```

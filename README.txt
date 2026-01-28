 ft_isalpha     int ft_isalpha(int c)
	Comprueba si c es un carácter alfabético, devuelve 1 si lo es o 0 si no lo es. Da igual mayúsculas que minúsculas. Puede recibir un char porque lo transforma a int según la tabla Ascii.

ft_isdigit      int ft_isdigit(int c)
	Comprueba si c es un carácter numérico, devuelve 1 si lo es o 0 si no lo es. Puede recibir un char porque lo transforma a int según la tabla Ascii, sino, introducir el número correspondiento según Ascii, entre 48 siendo 0 y 57 siendo el 9.

ft_isalnum      int	ft_isalnum(int c)
	Comprueba si c es alfanumérico, devuelve 1 si lo es y 0 si no es.  Puede recibir un char porque lo transforma a int según la tabla Ascii, sino, introducir el número correspondiento según Ascii.

ft_isascii      int	ft_isascii(int c)
	Comprueba si c es un carácter ASCII, devuelve 1 si lo es y 0 si no es. Un caracter de la tablas ASCII es cualquiera entre 0 y 127, ambos incluidos. Puede recibir un char porque lo transforma a int según la tabla Ascii, sino, introducir el número correspondiento según Ascii.

ft_isprint      int	ft_isprint(int c)
	 Comprueba si c es un carácter imprimible según ASCII, devuelve 1 si lo es y 0 si no es. Un caracter IMPRIMIBLE de la tabla ASCII es cualquiera entre 32 y 127, ambos incluidos. Puede recibir un char porque lo transforma a int según la tabla Ascii, sino, introducir el número correspondiento según Ascii.

ft_strlen       size_t	ft_strlen(char *s)
	Mide el largo de una cadena de texto y devuelve el largo. No cuenta el nulo. Se utiliza size_t para adaptar a sistemas de 32 y 64 bits. Porque no usar unsogned_int?¿? En un sistema de 32 bits, un unsigned int puede almacenar valores hasta aproximadamente 4 mil millones (2³² - 1). Esto parece suficiente, ¿verdad? Pero en un sistema de 64 bits, puedes tener cadenas de texto (strings) que ocupen más de 4 GB de memoria (2⁶⁴ - 1). size_t se adapta automáticamente al sistema.

ft_memset       void    *ft_memset(void *ptr, int x, size_t len)
	memory set -> rellena un bloque de memoria con un valor específico, byte por byte.
		void *ptr: Puntero al inicio de la memoria que quieres rellenar.
		int x: El valor (byte) con el que quieres rellenar.
		size_t len: Número de bytes que quieres rellenar.
	Los usos más comunes son:
		Inicializar memoria a cero:
			int array[10];
			ft_memset(array, 0, sizeof(array)); // Pone todos los bytes a 0
		Limpiar buffers:
			char buffer[100];
			ft_memset(buffer, '\0', 100); // Limpia el buffer
		Rellenar con un valor específico:
			char str[20];
			ft_memset(str, 'A', 10); // Rellena los primeros 10 bytes con 'A'
	El manual de C (POSIX y el estándar ANSI) especifica que las funciones que manipulan memoria (como memset, memcpy, memmove) deben tratar la memoria como si fuera un array de unsigned char.

ft_bzero        void    ft_bzero(void *ptr, size_t len)
	El nombre viene de "Byte Zero"
	Su función principal es poner a cero (escribir el byte \0) una porción de memoria. Es básicamente una versión simplificada de memset donde el valor que escribes siempre es 0.
	Recuerda, recibe void *ptr, luego hay que asignarle unsigned char. al igual que memset, pasar asignar byte por byte ya que no definimos su tamaño al ser void. "Casteor"

ft_memcpy       void    *ft_memcpy(void *dst, const void *src, size_t n)
	Copia n bytes desde la memoria apuntada por src hacia la memoria apuntada por dst.
	Es como un "copiar-pegar"
		dst: Destino donde se copiarán los bytes.
		src: Origen desde donde se copian los bytes (marcado como const porque no se modifica).
		n: Número de bytes a copiar.
	Devuelve dst

ft_memmove      void	*ft_memmove(void *str, const void *src, size_t n)
	Copia len bytes de la memoria de src a str. La memoria pueden superponerse. Primero, los bytes en src se copian en una matriz temporal y luego en str
		src = Es mi dato a leer y utilizar.
		str = desde dónde escribo.
		Pueden apuntar al mismo bloque, pero a posiciones distintas str + 2(empieza en posicion 2 a concatenar 'n' bytes de src)

ft_strlcpy      size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize)
	Copia la cadena a la que apunta src, incluido el byte nulo de terminación ('\0'), al búfer señalado por dst.
	dstsize SIEMPRE tiene que ser el tamaño real del array dst. ¿Qué pasa si miento en dstsize? -->	Buffer overflow. Segfault.
	¿Qué devuelve strlcpy?	Siempre el largo de src.

ft_strlcat      size_t strlcat(char dest, const char *restrict src, size_t destsize);
	Pega la cadena src al final de la cadena dst, asegurándose de no pasarse del tamaño total dstsize y de que el resultado siempre termine en un nulo (\0).
	Devuelve la longitud teórica de la frase que intentaste crear: la suma de la longitud inicial de dst más la longitud de src.
		dest = Es una caja que ya tiene algo dentro.    dst[10] = "Hola";
		src = Es lo que quieres añadir al final de la caja. src[8] = " mundo"
		dstsize = Es el tamaño TOTAL de la caja dst.    dst[10], sería 10.

	En strlcpy: Borrabas lo que había y escribías desde el principio.
	En strlcat: Respetas lo que hay, buscas el final, y añades a continuación sin pasarte del límite dstsize.

ft_toupper      ft_toupper(int c)
	Convierte un carácter de minúscula a MAYÚSCULA basándose en la tabla ASCII (entre 97 para 'a' y 122 para 'z'), devuelve el número correspondiente a la MAYÚSCULA (restando 32). Si no es una minúscula, devuelve c tal cual.

ft_tolower      int ft_tolower(int c)
	Convierte un carácter de MAYÚSCULA a minúscula basándose en la tabla ASCII (entre 65 para 'A' y 90 para 'Z'), devuelve el número correspondiente a la minúscula (restando 32). Si no es una MAYÚSCULA, devuelve c tal cual.

ft_strchr       char *strchr(const char *s, int c);
	Busca la primera aparición del carácter c en la cadena s. Recorre la cadena byte por byte hasta encontrar el carácter buscado (casteado a char) o llegar al final.
	Devuelve un puntero a la posición donde encontró el carácter. Si no lo encuentra, devuelve NULL.
	Importante: El carácter nulo \0 se considera parte de la cadena, por lo que si buscas \0, la función devolverá un puntero al final de la cadena (no NULL).

t_strrchr       char *strrchr(const char *s, int c);
	La r de strrchr viene de "Reverse" (al revés). Su misión es encontrar la última aparición.
	Busca la ultima aparición del carácter c en la cadena s. Recorre la cadena byte por byte hasta encontrar el carácter buscado (casteado a char) o llegar al principio.
	Devuelve un puntero a la posición donde encontró el carácter. Si no lo encuentra, devuelve NULL.
	Importante: El carácter nulo '\0' se considera parte de la cadena, por lo que si buscas \0, la función devolverá un puntero al final de la cadena (no NULL).

ft_strncmp      int ft_strncmp(const char *s1, const char *s2, size_t n)
	Compara los primeros n caracteres de dos cadenas de texto (s1 y s2). Recorre ambas cadenas byte por byte hasta encontrar una diferencia, llegar al final de alguna cadena (\0), o haber comparado n caracteres.
	Siemrpe es s1 - s2.
	Importante: La comparación debe hacerse casteando a unsigned char para manejar correctamente caracteres extendidos de ASCII (valores > 127).
	A diferencia de strcmp, esta versión es más segura porque le pones un límite de bytes a comparar, evitando leer memoria que no te pertenece o desbordamientos.

ft_memchr       void *memchr(const void *s, int c, size_t n)
	Buscamos 'c' en *s, esta búsqueda del c se basa según si *s llega a '\0' o si el contador llega a n 

ft_memcmp       int memcmp(const void *s1, const void *s2, size_t n)
	Compara *s1 y *s2 en cada posición hasta 'n', pero si n se el da valor 0, el return es 0.
	Tiene que recorrer s1 y s2 hasta 'n'
	Devuelve -1 si la resta es negativa, 0 si es igual todo, y 1 si es positivo.

ft_strnstr		char	*ft_strnstr(const char *big, const char *little, size_t len)
	 Es un buscador, busca dentro de big la primera aparición de una subcadena (little), pero limitando la búsqueda a un número máximo de caracteres (n) ?
	 si little está vacía, devuelve big.
	 Si little está despues de 'len' en 'Big', pilla a medias de la posicion 'len' o no se completa devuelve NULL.
	 Si no se encuentra little, devuelve 'NULL'.

ft_atoi			int	atoi(const char *nptr)
	Esta es una función de C que convierte una representación de cadena de un número entero 'char' en un valor entero 'int'.
	los espacios = 32 o del 9 al 13 includo, avanza, si tiene un signo, uno solo ó '+' ó '-' se guarda con 1 o -1.
	Se convierte de char a int, si hay letrs u otras cosas despues de los números se ignora y se para.
	No se mira desbordamiento del número máximo, se trabaja con un int.

ft_calloc		void *calloc(size_t nmemb, size_t size);
	ft_calloc busca crear memoria para el tipo de dato, para ello utiliza malloc, calcula el numero de datos por el tipo, un char, ocupa un byte, 1 direccion de memoria, un int ocupa 4 bytes, 4 direcciones de memoria.
	Despues de calcular, el espacio, lo crea, y lo rellena de 0 con ft_bzero.
	Una vez asignada la memoria retorna, devuelve la direccióon del primer puntero.

ft_strdup		char *ft_strdup(const char *s);
	Crea un duplicado de *s.
	Si luego modificamos nuestro nueva copia, veriamos como solo se modifica lo nuevo y no *s.

ft_substr		char	*ft_substr(char const *s, unsigned int start, size_t len);
	Reserva memoria (con malloc(3)) y devuelve una subcadena de caracteres de la cadena ‘s’. La subcadena comienza en el índice ‘start ’ y tiene una longitud máxima ‘len ’.
	La subcadena de caracteres resultante. NULL si falla la reserva de memoria.


test2

ft_substr       char *ft_substr(char const *s, unsigned int start, size_t len);
	s: La cadena original desde la que se crea la subcadena.
	start: El índice del carácter en ‘s’ desde el que empieza la subcadena.
	len: La longitud máxima de la subcadena.
	Crea una copia (con malloc) de un fragmento de la cadena s. Empieza en la posición start y copia como máximo len caracteres.
		Si start es mayor que el largo de s, devuelve una cadena vacía ("") con malloc.
		Si len es más grande que lo que queda de cadena desde start, se recorta para no leer memoria fuera de s.
		Retorno: La nueva subcadena terminada en \0 o NULL si falla el malloc.


ft_strjoin      char *ft_strjoin(char const *s1, char const *s2);
	Reserva memoria y devuelve una nueva cadena formada por la concatenación de s1 y s2.
	Mide el largo de ambas cadenas, reserva len(s1) + len(s2) + 1 bytes, copia s1, luego s2, y añade el \0 final.
	Las cadenas originales no se modifican. Es responsabilidad del usuario liberar la memoria devuelta.
	Retorno: Puntero a la nueva cadena o NULL si malloc falla.


ft_strtrim      char *ft_strtrim(char const *s1, char const *set);
	Elimina todos los caracteres de la cadena set desde el principio y el final de s1.
	Devuelve una nueva cadena (con malloc) con los caracteres indeseados recortados.
	Busca el primer carácter de s1 que no esté en set (inicio), luego busca el último carácter de s1 que no esté en set (final), y copia solo esa porción en una nueva cadena y la devuelve.
	Si s1 está completamente formada por caracteres de set, devuelve una cadena vacía ("").
	Retorno: La nueva cadena recortada terminada en \0, o NULL si falla la reserva de memoria.

ft_split        char **ft_split(char const *s, char c);
		Un char * es un puntero a una cadena (un array de caracteres).
		Un char ** es un puntero a un array de punteros a cadenas. Es decir, un array de strings es un char **
	Recibe una cadena s y un carácter delimitador c.
	Divide la cadena s en subcadenas separadas por el carácter c.
	Devuelve un array de punteros a cadenas (cada puntero apunta a una subcadena).
	El array termina con un puntero NULL para indicar el final.
		Cuenta cuántas subcadenas.
		Reserva memoria para el array de punteros (tamaño = número de subcadenas + 1 para el NULL).
		Si falla alguna reserva, libera todo lo reservado hasta ese momento
		Devuelve el array con todas las subcadenas y un NULL al final .

ft_itoa     char *ft_itoa(int n);
	Recibe un int. La función gestiona conbertir de int a char reservando memoria para el char. Para poder manejar extremos de un int, es decir sus limitaciones, cremoas una variable para transformarla de int a long. Creamso con malloc el tamaño del puntero y guardamos numero por número.
Retorna un char *.

ft_strmapi		char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
	strmapi gestiona una función dentro de otra función. y devulve un nuevo puntero.Aplica la función ‘f’ a cada carácter de la cadena ‘s’, pasando su índice como primer argumento y el propio carácter como segundo argumento. Se crea una nueva cadena (utilizando malloc(3)) para almacenar los resultados de las sucesivas aplicaciones de ‘f’.
Debe devolver el puntero creado.

ft_striteri		void ft_striteri(char *s, void (*f)(unsigned int, char*));
	muy parecido a strmapi, pero en este caso en vez de enviar el char, y agregarlo a una segunda cadena lo modifiquemos o no, en este caso enviamos la direccion de &s[i] iteramos directamente sobre la cadena y la modificamos directamente, no retornamos nada. 

ft_putchar_fd		void ft_putchar_fd(char c, int fd);
	ESta funcion imprime un write, de 1 byte.
	write(fd, &c, 1);
	fd = (file descriptor ) :
		0	STDIN_FILENO	Standard Input	Lo que escribes con el teclado (ej. scanf).
		1	STDOUT_FILENO	Standard Output	Lo que ves en la pantalla (ej. printf).
		2	STDERR_FILENO	Standard Error	Los mensajes de error (también salen en pantalla, pero por otro "tubo").
	&c = la dirección de c. El manual de instrucciones dice que el segundo parámetro debe ser una dirección de memoria (un puntero).
	1 = imprimimos 1byte en este caso, sería el numero de bytes a imprimir
	Entonces, en 1 stdout lo que sería fd, le decimos ve a la dirección &c y llévate solo el primer bloque que encuentres.

ft_putstr_fd		void ft_putstr_fd(char *s, int fd);
	recorre el largo de cadena e impre la cadena entera en con write en vez de un caracter. REcibe el fd, el puntero, y el número de bytes.

ft_putendl_fd.c		void ft_putendl_fd(char *s, int fd)
	recorre el largo de cadena e impre la cadena entera en con write en vez de un caracter. REcibe el fd, el puntero, y el número de bytes. Añade un salto de línea al final de frase


ft_putnbr_fd		void ft_putnbr_fd(int n, int fd);
	imprimir numeros negativos y positivos con el write. Utiliza putchar para imprimir caracteres. Retroalimentación de la función.

gcc -Wall -Wextra -Werror ft_xxxx.c -o test_xxxx && ./test_xxxx


3 PARTE

CREAMOS EL libft.h
	Este archivo es el "índice" de la librería. Aquí van los prototipos de todas las funciones y la estructura de las listas.
	#ifndef LIBFT_H? Se llaman "Header Guards". Evitan que, si incluyes la librería dos veces por error, el compilador se vuelva loco. Es obligatorio por Norma.
	Incluye el armado de las listas.


¿Qué es el Makefile?
	El Makefile es un archivo de instrucciones para que la terminal trabaje para nosotros. En lugar de escribir cc ft_*.c... cada vez, solo escribiremos    *make*
	el objetivo no es crear un programa ejecutable (como a.out), sino un archivo de librería llamado libft.a
	El archivo ha de guardarse la primera letra en *MAYÚCULA*   --> Makefile
	¿Qué hace un Makefile en la Libft?
		Compila los .c a .o con las flags obligatorias (-Wall -Wextra -Werror) usando cc.
		Agrupa los .o en una librería estática libft.a usando ar.

	# Herramientas
		AR      = ar rcs             # comando para crear/actualizar la librería
		CC      = cc                # usa cc para cumplir la norma de 42 (no clang)
		FLAGS   = -Wall -Wextra -Werror

Como crear la librería
	Vé a la terminal y situate dentro de la carpeta del proyecto.
	Escribe y ejecuta
		make
	Si no falla, verás libft.a y el archivo libft.a en la carpeta.
	Para limpiar:
		make clean  --> Mensaje: Objetos eliminados.                #eliminamos los objetos
		make fclean     --> Mensaje: Objeto y librería eliminado.   #eliminamos objetos y la librería libft.a
	Si quieres reconstruir todo:
		make re

	¿Qué diferencia hay entre utilizar make y make re?
		make -->        Usa make para compilar normalmente y solo recompilar lo que cambió.
			Ejecutar solo make compila y crea el archivo (libft.a) solo si no existe o si alguno de los archivos .o o .c ha cambiado desde la última compilación.
			Si ya tienes todo compilado y no has modificado ningún .c, make no hará nada (no recompila ni recrea la librería).
		make re -->     Usa make re cuando quieras limpiar todo y compilar desde cero, por ejemplo si tienes errores extraños o quieres asegurarte de que todo está fresco. 
			make re es una abreviatura para "rebuild" (reconstruir).
			Ejecuta primero make fclean (borra todos los .o y la librería libft.a).
			Luego ejecuta make para compilar todo desde cero.


	para compilar
		utilizaremos --> cc -Wall -Wextra -Werror main.c libft.a -o test
			cc -->  Es el compilador de C
			-Wall -Wextra -Werror --> Son flags (opciones) que controlan las advertencias del compilador
			main.c -->  Es el archivo de código fuente que quieres compilar. Contiene la función main y el código que usará las funciones de tu librería.
			libft.a --> Es tu librería estática, un archivo que contiene todas las funciones que hemos implementado
			-o test --> Especifica el nombre del archivo ejecutable que quieres crear. Si no pones esta opción, el compilador crea un ejecutable llamado a.out por defecto.
		Luego ejecutaremos el programa:
			./test
3 PARTE
	listas
	para que sirven las listas¿?
		Si solo haces un nodo y lo liberas en el main, efectivamente no sirve para nada. Es como comprar un solo eslabón de una cadena y tirarlo.
		La magia de las listas enlazadas aparece cuando quieres guardar datos que no sabes cuántos son de antemano.
		La lista puede crecer hasta que se acabe la memoria del ordenador. Es importante liberar memoria free

	Las variables de la estructura t_list son:
		• content: los datos contenidos en el nodo. Usar void * permite almacenar cualquier tipo de dato.
		• next: la dirección del siguiente nodo, o NULL si el nodo actual es el último de la lista

ft_lstnew.c      t_list *ft_lstnew(void *content);
	Crea un nuevo nodo para una lista enlazada. Reserva memoria con malloc para el nodo.
		content es un puntero al contenido que se guardará en el nodo (puede ser cualquier tipo de dato).
		El puntero content del nodo se asigna con el valor del parámetro. El puntero next se inicializa a NULL, indicando que no apunta a otro nodo
	Retorno: Puntero al nuevo nodo creado, o NULL si falla la reserva de memoria.

ft_lstadd_front     void ft_lstadd_front(t_list **lst, t_list *new);
	Esta función sirve para añadir un nuevo nodo al principio de una lista enlazada. Imagina que tienes una lista de nodos, y quieres poner uno nuevo justo al inicio, para que sea el primero. Eso es lo que hace ft_lstadd_front.
	La función engancha el nuevo nodo al principio de la lista y actualiza la variable head del main para que ahora apunte a este nuevo nodo.

								INICIO (Lista con A)        |           PASO 1                          |           PASO 2
															|       new->next = *lst;                   |         *lst = new;
															|                                           |
							  lst (cabeza)                  |       lst (cabeza)    new (B)             |       lst (cabeza)
								  |                         |           |              |                |           |
								  v                         |           v              v                |           v
							  +-------+    +-------+        |       +-------+      +-------+            |       +-------+    +-------+    +-------+
							  |   A   | -> | NULL  |        |       |   A   | <--- |   B   |            |       |   B   | -> |   A   | -> | NULL  |
							  +-------+    +-------+        |       +-------+      +-------+            |       +-------+    +-------+    +-------+
															|           |                               |
															|           v                               |
															|       +-------+                           |
															|       | NULL  |                           |
															|       +-------+                           |
															|                                           |
															| 	(B se conecta a A, pero la cabeza       | 		(La cabeza ahora apunta a B,
															|  	todavía apunta a A)                     |  			y la lista empieza por B)


ft_lstsize		int ft_lstsize(t_list *lst)
	Esta función cuenta el número de nodos en una lista enlazada.
	Recorre la lista nodo por nodo avanzando con lst = lst->next hasta que lst sea NULL.
	Devuelve el numero de nodos contados.


ft_lstlast		t_list *ft_lstlast(t_list *lst);
	Esta función devuelve el último nodo de una lista enlazada.
	lst es un puntero al primer nodo de la lista. Retorna un puntero al último nodo, o NULL si la lista está vacía. Puede usarse para añadir un nodo nuevo al final de una lista, antes de Null por ejemplo.


ft_lstadd_back		void ft_lstadd_back(t_list **lst, t_list *new);
	Esta función es igual que ft_lstadd_front pero añadiendo un nuevo nodo al final de la lista.
	Si la lista está vacía (*lst == NULL), el nuevo nodo se convierte en el primero.


ft_lstdelone		void ft_lstdelone(t_list *lst, void (*del)(void*));
	Libera un único nodo de una lista enlazada, incluyendo su contenido.
		- lst: Puntero al nodo que se quiere eliminar.
		- del: Puntero a una función que se encarga de liberar la memoria del contenido del nodo (ej: free).
	Si el nodo no es NULL, llama a la función del pasándole el contenido (lst->content) para liberarlo.
	Luego libera la memoria del nodo en sí con free(lst).


ft_lstclear			void ft_lstclear(t_list **lst, void (*del)(void*));
	Elimina y libera todos los nodos de una lista enlazada.
		- lst: Dirección del puntero al primer nodo de la lista.
		- del: Puntero a una función que libera la memoria del contenido de cada nodo.
	En cada nodo, llama a del para liberar su contenido.
	Diferencia con ft_lstdelone: Esta borra toda la lista, no solo un nodo.


ft_lstiter			void ft_lstiter(t_list *lst, void (*f)(void *));
	Recorre una lista enlazada nodo por nodo mientras haya nodos (lst != NULL), y aplica una función a cada nodo.
	Avanza al siguiente nodo con lst = lst->next


ft_lstmap			t_list *ft_lstmap(t_list *lst, void *(*f)(void *),void (*del)(void *));
	Crea una nueva lista aplicando una función a cada nodo de la lista original.
		- lst: Puntero al primer nodo de la lista original.
		- f: Puntero a una función que transforma el contenido de cada nodo.
		- del: Puntero a una función para liberar memoria en caso de fallo.
	Retorna un puntero a la nueva lista creada, o NULL si falla.









Definiciones en una frase

char: Es el tipo de dato más pequeño, diseñado para almacenar un solo carácter o un número entero pequeño (generalmente de 8 bits).

int: Es el tipo de dato estándar para representar números enteros (positivos o negativos) que se ajustan al tamaño de palabra natural del procesador.

float: Es un tipo de dato utilizado para representar números reales con decimales mediante precisión simple.

double: Es similar al float pero con el doble de precisión, ideal para cálculos matemáticos que requieren exactitud decimal.
unsigned int: Es una variante del entero que solo permite valores positivos, duplicando así el rango máximo de números que puede alcanzar hacia arriba.

size_t: Es un tipo entero sin signo especializado para representar tamaños de objetos y asegurar que el código sea compatible entre sistemas de 32 y 64 bits.

short: Es un tipo de entero de tamaño reducido, ideal para optimizar el uso de memoria cuando se manejan rangos numéricos pequeños.

long: Es un entero de rango extendido que asegura una capacidad igual o superior a la de un int estándar.

long long: Es el tipo de entero con mayor capacidad en C, diseñado para almacenar números extremadamente grandes de hasta 64 bits.

long double: Es el tipo de punto flotante con la máxima precisión disponible, superando al double en cálculos decimales complejos.

void: Es un tipo especial que representa la ausencia total de valor o un tipo de dato genérico no especificado.

bool: Es un tipo de dato lógico que solo puede tomar dos valores: verdadero (true) o falso (false).

uint8_t / int32_t (Ancho fijo): Son tipos de datos que garantizan tener exactamente el mismo número de bits en cualquier procesador o sistema operativo.

const void *src: Cuando pones const delante de un puntero, le estás diciendo al compilador y a otros programadores: "Voy a leer los datos que hay en esta dirección de memoria, pero prometo que no los voy a cambiar".


¿Para qué se utiliza cada una?

char
	Se utiliza principalmente para manejar texto (letras, símbolos, dígitos como caracteres) y para manipular datos a nivel de bytes individuales. También es útil para ahorrar memoria si sabes que tus números siempre estarán entre -128 y 127.

int
	Es el "todoterreno". Se usa para contadores simples, variables de control, estados lógicos (donde 0 es falso y distinto de 0 es verdadero) y cualquier cálculo matemático con números enteros que no sea extremadamente grande.

float y double
	Se usan cuando necesitas trabajar con fracciones o decimales. El float se prefiere en sistemas con memoria limitada o gráficos (donde la velocidad importa más que la precisión extrema), mientras que el double es el estándar para ingeniería y ciencia.

unsigned int
	Se utiliza cuando tienes la certeza absoluta de que el valor nunca será negativo. Es muy común en la programación de sistemas, manejo de registros de hardware o cuando necesitas contar cosas donde un valor negativo no tendría sentido físico.

size_t
	Su uso es obligatorio para cualquier cosa relacionada con la gestión de memoria. Se usa para índices de arreglos (especialmente si son muy grandes), para recibir el resultado de sizeof y como argumento en funciones como malloc (para pedir memoria) o strlen (para contar letras en una frase). Usar size_t evita que tu programa falle al pasar de una computadora vieja a una moderna.

short
	Se utiliza principalmente en sistemas con memoria muy limitada (como microcontroladores) o cuando tienes arreglos de millones de números y sabes que ninguno superará el rango de -32,768 a 32,767.

long y long long
	El long se usa para asegurar compatibilidad en sistemas donde el int podría ser muy pequeño. El long long es indispensable para cronómetros de alta precisión (milisegundos desde 1970), cálculos financieros de grandes cantidades o IDs de bases de datos masivas.

long double
	Su uso es casi exclusivo de la computación científica, astronomía o física de partículas, donde un error en el decimal número 15 podría arruinar todo un experimento.

void
	Tiene dos usos estrella:
		En funciones: Para indicar que una función "hace algo" pero no "devuelve nada" (como imprimir un mensaje).
		Como puntero (void *): Para crear funciones universales que pueden recibir cualquier tipo de dato (como la función que ordena listas).

bool (usando <stdbool.h>)
	Se utiliza para mejorar la legibilidad del código. En lugar de usar 0 y 1 (que pueden confundirse con cantidades), usas true y false para banderas de estado, como estaConectado o esValido.

Tipos de ancho fijo (uint8_t, int16_t, etc.)
	Son los favoritos de los programadores profesionales hoy en día. Se usan para:
		Protocolos de red: Para asegurar que un dato enviado desde un PC de 64 bits llegue correctamente a un móvil de 32 bits.
		Archivos binarios: Para que la estructura de un archivo (como una imagen o un audio) sea siempre idéntica sin importar dónde se cree.

const void *src:
	Seguridad: Si por error intentas hacer src[i] = 'A'; dentro de tu función, el compilador te dará un error y te dirá: "Oye, dijiste que esto era constante, no puedes cambiarlo". Esto evita bugs accidentales.



TEST PACO

c1r11s2% paco
╔═══════════════════════════════════════════════════════════
═══════════════════╗
║                Welcome to Francinette, a 42 tester 
framework!                ║
╚═══════════════════════╦══════════════════════════════╦════
═══════════════════╝
                        ║             libft            ║
                        ╚══════════════════════════════╝
✔ Preparing framework
✖ Executing: norminette
Setting locale to en_US
ft_lstiter.c: Error!
Error: SPACE_BEFORE_FUNC    (line:  15, col:   5):	Found space when expecting tab before function name
Error: SPACE_AFTER_KW       (line:  18, col:   9):	Missing space after keyword
Error: LINE_TOO_LONG        (line:  50, col:   1):	line too long
ft_lstlast.c: Error!
Error: LINE_TOO_LONG        (line:  25, col:   1):	line too long
Error: LINE_TOO_LONG        (line:  75, col:   1):	line too long
ft_lstmap.c: Error!
Error: SPACE_BEFORE_FUNC    (line:  15, col:  12):	Found space when expecting tab before function name
Error: CONSECUTIVE_SPC      (line:  17, col:  11):	Two or more consecutives spaces
Error: SPACE_REPLACE_TAB    (line:  17, col:  11):	Found space when expecting tab
Error: CONSECUTIVE_SPC      (line:  18, col:  11):	Two or more consecutives spaces
Error: SPACE_REPLACE_TAB    (line:  18, col:  11):	Found space when expecting tab
Error: SPACE_EMPTY_LINE     (line:  19, col:   1):	Space on empty line
Error: SPACE_AFTER_KW       (line:  21, col:   9):	Missing space after keyword
Error: SPACE_AFTER_KW       (line:  39, col:   5):	Missing space after keyword
Error: SPC_BFR_PAR          (line:  39, col:   7):	Missing space before parenthesis (brace/bracket)
Error: CONSECUTIVE_SPC      (line:  46, col:  14):	Two or more consecutives spaces
Error: SPACE_BEFORE_FUNC    (line:  46, col:  16):	Found space when expecting tab before function name
Error: SPACE_BEFORE_FUNC    (line:  55, col:  12):	Found space when expecting tab before function name
Error: CONSECUTIVE_SPC      (line:  57, col:  11):	Two or more consecutives spaces
Error: SPACE_REPLACE_TAB    (line:  57, col:  11):	Found space when expecting tab
Error: SPACE_EMPTY_LINE     (line:  58, col:   1):	Space on empty line
Error: SPACE_AFTER_KW       (line:  60, col:   9):	Missing space after keyword
Error: SPACE_AFTER_KW       (line:  65, col:   9):	Missing space after keyword
Error: SPACE_BEFORE_FUNC    (line:  72, col:   7):	Found space when expecting tab before function name
Error: SPC_AFTER_OPERATOR   (line:  72, col:  50):	missing space after operator
Error: CONSECUTIVE_SPC      (line:  74, col:  11):	Two or more consecutives spaces
Error: SPACE_REPLACE_TAB    (line:  74, col:  11):	Found space when expecting tab
Error: CONSECUTIVE_SPC      (line:  75, col:  11):	Two or more consecutives spaces
Error: SPACE_REPLACE_TAB    (line:  75, col:  11):	Found space when expecting tab
Error: CONSECUTIVE_SPC      (line:  76, col:   9):	Two or more consecutives spaces
Error: SPACE_REPLACE_TAB    (line:  76, col:   9):	Found space when expecting tab
Error: SPACE_EMPTY_LINE     (line:  77, col:   1):	Space on empty line
Error: SPACE_AFTER_KW       (line:  78, col:   5):	Missing space after keyword
Error: SPC_BFR_PAR          (line:  78, col:   7):	Missing space before parenthesis (brace/bracket)
Error: SPACE_AFTER_KW       (line:  81, col:   5):	Missing space after keyword
Error: SPC_BFR_PAR          (line:  81, col:  10):	Missing space before parenthesis (brace/bracket)
Error: CONSECUTIVE_SPC      (line:  93, col:  23):	Two or more consecutives spaces
Error: SPC_BEFORE_NL        (line:  93, col:  23):	Space before newline
Error: LINE_TOO_LONG        (line: 156, col:   1):	line too long
ft_lstnew.c: Error!
Error: SPACE_AFTER_KW       (line:  20, col:   5):	Missing space after keyword
Error: SPC_BFR_PAR          (line:  20, col:   7):	Missing space before parenthesis (brace/bracket)
ft_lstsize.c: Error!
Error: SPACE_BEFORE_FUNC    (line:  15, col:   4):	Found space when expecting tab before function name
Error: CONSECUTIVE_SPC      (line:  17, col:   8):	Two or more consecutives spaces
Error: SPACE_REPLACE_TAB    (line:  17, col:   8):	Found space when expecting tab
Error: LINE_TOO_LONG        (line:  67, col:   1):	line too long
ft_memchr.c: OK!
ft_memcmp.c: Error!
Error: LINE_TOO_LONG        (line:  68, col:   1):	line too long
Error: LINE_TOO_LONG        (line:  86, col:   1):	line too long
ft_memcpy.c: OK!
ft_memset.c: Error!
Error: LINE_TOO_LONG        (line:  31, col:   1):	line too long
ft_putchar_fd.c: Error!
Error: LINE_TOO_LONG        (line:  32, col:   1):	line too long
ft_putnbr_fd.c: Error!
Error: LINE_TOO_LONG        (line:  76, col:   1):	line too long
ft_split.c: Error!
Error: NEWLINE_PRECEDES_FUNC (line:  64, col:   1):	Functions must be separated by a newline
ft_strchr.c: OK!
ft_strdup.c: OK!
ft_strjoin.c: OK!
ft_strlcat.c: Error!
Error: LINE_TOO_LONG        (line:  39, col:   1):	line too long
Error: LINE_TOO_LONG        (line:  41, col:   1):	line too long
ft_strlen.c: OK!
ft_strmapi.c: OK!
ft_strnstr.c: OK!
ft_strrchr.c: OK!
ft_substr.c: Error!
Error: CONSECUTIVE_SPC      (line:  27, col:   9):	Two or more consecutives spaces
Error: SPACE_REPLACE_TAB    (line:  27, col:   9):	Found space when expecting tab
Error: TOO_FEW_TAB          (line:  28, col:   1):	Missing tabs for indent level
Error: SPACE_REPLACE_TAB    (line:  28, col:   5):	Found space when expecting tab
Error: CONSECUTIVE_SPC      (line:  28, col:  11):	Two or more consecutives spaces
Error: SPACE_REPLACE_TAB    (line:  28, col:  11):	Found space when expecting tab
Error: TOO_FEW_TAB          (line:  29, col:   1):	Missing tabs for indent level
Error: SPACE_REPLACE_TAB    (line:  29, col:   5):	Found space when expecting tab
Error: CONSECUTIVE_SPC      (line:  29, col:  11):	Two or more consecutives spaces
Error: SPACE_REPLACE_TAB    (line:  29, col:  11):	Found space when expecting tab
Error: TOO_FEW_TAB          (line:  31, col:   1):	Missing tabs for indent level
Error: SPACE_REPLACE_TAB    (line:  31, col:   5):	Found space when expecting tab
Error: TOO_FEW_TAB          (line:  32, col:   1):	Missing tabs for indent level
Error: SPACE_REPLACE_TAB    (line:  32, col:   5):	Found space when expecting tab
Error: TOO_FEW_TAB          (line:  33, col:   1):	Missing tabs for indent level
Error: SPACE_EMPTY_LINE     (line:  33, col:   5):	Space on empty line
Error: TOO_FEW_TAB          (line:  34, col:   1):	Missing tabs for indent level
Error: SPACE_REPLACE_TAB    (line:  34, col:   9):	Found space when expecting tab
Error: TOO_FEW_TAB          (line:  35, col:   1):	Missing tabs for indent level
Error: SPACE_REPLACE_TAB    (line:  35, col:   9):	Found space when expecting tab
Error: TOO_FEW_TAB          (line:  36, col:   1):	Missing tabs for indent level
Error: SPACE_REPLACE_TAB    (line:  36, col:  13):	Found space when expecting tab
Error: TOO_FEW_TAB          (line:  37, col:   1):	Missing tabs for indent level
Error: SPACE_REPLACE_TAB    (line:  37, col:   9):	Found space when expecting tab
Error: TOO_FEW_TAB          (line:  38, col:   1):	Missing tabs for indent level
Error: SPACE_REPLACE_TAB    (line:  38, col:   9):	Found space when expecting tab
Error: CONSECUTIVE_SPC      (line:  38, col:  22):	Two or more consecutives spaces
Error: WRONG_SCOPE_COMMENT  (line:  38, col:  24):	Comment is invalid in this scope
Error: WRONG_SCOPE_COMMENT  (line:  38, col:  24):	Comment is invalid in this scope
Error: TOO_FEW_TAB          (line:  39, col:   1):	Missing tabs for indent level
Error: SPACE_EMPTY_LINE     (line:  39, col:   5):	Space on empty line
Error: TOO_FEW_TAB          (line:  40, col:   1):	Missing tabs for indent level
Error: SPACE_REPLACE_TAB    (line:  40, col:   5):	Found space when expecting tab
Error: TOO_FEW_TAB          (line:  41, col:   1):	Missing tabs for indent level
Error: SPACE_REPLACE_TAB    (line:  41, col:   9):	Found space when expecting tab
Error: TOO_FEW_TAB          (line:  42, col:   1):	Missing tabs for indent level
Error: SPACE_REPLACE_TAB    (line:  42, col:   5):	Found space when expecting tab
Error: TOO_FEW_TAB          (line:  43, col:   1):	Missing tabs for indent level
Error: SPACE_REPLACE_TAB    (line:  43, col:   5):	Found space when expecting tab
Error: TOO_FEW_TAB          (line:  44, col:   1):	Missing tabs for indent level
Error: SPACE_REPLACE_TAB    (line:  44, col:   9):	Found space when expecting tab
Error: TOO_FEW_TAB          (line:  45, col:   1):	Missing tabs for indent level
Error: SPACE_REPLACE_TAB    (line:  45, col:   5):	Found space when expecting tab
Error: TOO_FEW_TAB          (line:  46, col:   1):	Missing tabs for indent level
Error: SPACE_REPLACE_TAB    (line:  46, col:   5):	Found space when expecting tab
Error: TOO_FEW_TAB          (line:  47, col:   1):	Missing tabs for indent level
Error: SPACE_REPLACE_TAB    (line:  47, col:   9):	Found space when expecting tab
Error: TOO_FEW_TAB          (line:  48, col:   1):	Missing tabs for indent level
Error: SPACE_REPLACE_TAB    (line:  48, col:   5):	Found space when expecting tab
Error: TOO_FEW_TAB          (line:  49, col:   1):	Missing tabs for indent level
Error: SPACE_REPLACE_TAB    (line:  49, col:   5):	Found space when expecting tab
ft_tolower.c: OK!
libft.h: OK!
ft_atoi.c: OK!
ft_bzero.c: OK!
ft_calloc.c: OK!
ft_isalnum.c: OK!
ft_isalpha.c: OK!
ft_isascii.c: OK!
ft_isdigit.c: OK!
ft_isprint.c: OK!
ft_itoa.c: Error!
Error: CONSECUTIVE_SPC      (line:  20, col:  21):	Two or more consecutives spaces
Error: WRONG_SCOPE_COMMENT  (line:  20, col:  24):	Comment is invalid in this scope
Error: WRONG_SCOPE_COMMENT  (line:  20, col:  24):	Comment is invalid in this scope
Error: CONSECUTIVE_SPC      (line:  36, col:  25):	Two or more consecutives spaces
Error: WRONG_SCOPE_COMMENT  (line:  36, col:  27):	Comment is invalid in this scope
Error: WRONG_SCOPE_COMMENT  (line:  36, col:  27):	Comment is invalid in this scope
Error: EMPTY_LINE_FUNCTION  (line:  44, col:   1):	Empty line in function
Error: SPACE_BEFORE_FUNC    (line:  47, col:   5):	Found space when expecting tab before function name
Error: CONSECUTIVE_SPC      (line:  49, col:   9):	Two or more consecutives spaces
Error: SPACE_REPLACE_TAB    (line:  49, col:   9):	Found space when expecting tab
Error: CONSECUTIVE_SPC      (line:  50, col:   9):	Two or more consecutives spaces
Error: SPACE_REPLACE_TAB    (line:  50, col:   9):	Found space when expecting tab
Error: CONSECUTIVE_SPC      (line:  51, col:   8):	Two or more consecutives spaces
Error: SPACE_REPLACE_TAB    (line:  51, col:   8):	Found space when expecting tab
Error: CONSECUTIVE_SPC      (line:  52, col:   8):	Two or more consecutives spaces
Error: SPACE_REPLACE_TAB    (line:  52, col:   8):	Found space when expecting tab
Error: SPACE_AFTER_KW       (line:  57, col:   5):	Missing space after keyword
Error: NO_SPC_AFR_PAR       (line:  57, col:   7):	Extra space after parenthesis (brace/bracket)
Error: SPC_BFR_PAR          (line:  57, col:   7):	Missing space before parenthesis (brace/bracket)
Error: BRACE_SHOULD_EOL     (line:  62, col:   6):	Expected newline after brace
Error: TOO_FEW_TAB          (line:  62, col:   7):	Missing tabs for indent level
Error: TOO_MANY_INSTR       (line:  62, col:   7):	Too many instructions on a single line
Error: CONSECUTIVE_SPC      (line:  64, col:  46):	Two or more consecutives spaces
Error: WRONG_SCOPE_COMMENT  (line:  64, col:  49):	Comment is invalid in this scope
Error: WRONG_SCOPE_COMMENT  (line:  64, col:  49):	Comment is invalid in this scope
ft_lstadd_back.c: Error!
Error: CONSECUTIVE_SPC      (line:  15, col:  14):	Two or more consecutives spaces
Error: SPACE_BEFORE_FUNC    (line:  15, col:  16):	Found space when expecting tab before function name
Error: SPACE_BEFORE_FUNC    (line:  24, col:   5):	Found space when expecting tab before function name
Error: CONSECUTIVE_SPC      (line:  26, col:  11):	Two or more consecutives spaces
Error: SPACE_REPLACE_TAB    (line:  26, col:  11):	Found space when expecting tab
Error: SPACE_EMPTY_LINE     (line:  27, col:   1):	Space on empty line
Error: SPACE_AFTER_KW       (line:  29, col:   9):	Missing space after keyword
Error: SPACE_AFTER_KW       (line:  34, col:   9):	Missing space after keyword
Error: LINE_TOO_LONG        (line:  83, col:   1):	line too long
ft_lstadd_front.c: Error!
Error: LINE_TOO_LONG        (line:  39, col:   1):	line too long
Error: LINE_TOO_LONG        (line:  56, col:   1):	line too long
ft_lstclear.c: Error!
Error: SPACE_BEFORE_FUNC    (line:  15, col:   5):	Found space when expecting tab before function name
Error: CONSECUTIVE_SPC      (line:  17, col:  11):	Two or more consecutives spaces
Error: SPACE_REPLACE_TAB    (line:  17, col:  11):	Found space when expecting tab
Error: CONSECUTIVE_SPC      (line:  18, col:  11):	Two or more consecutives spaces
Error: SPACE_REPLACE_TAB    (line:  18, col:  11):	Found space when expecting tab
Error: SPACE_EMPTY_LINE     (line:  19, col:   1):	Space on empty line
Error: SPACE_AFTER_KW       (line:  21, col:   9):	Missing space after keyword
Error: LINE_TOO_LONG        (line:  73, col:   1):	line too long
ft_lstdelone.c: Error!
Error: SPACE_BEFORE_FUNC    (line:  15, col:   5):	Found space when expecting tab before function name
Error: TOO_FEW_TAB          (line:  17, col:   1):	Missing tabs for indent level
Error: SPACE_REPLACE_TAB    (line:  17, col:   5):	Found space when expecting tab
Error: TOO_FEW_TAB          (line:  18, col:   1):	Missing tabs for indent level
Error: SPACE_AFTER_KW       (line:  18, col:   9):	Missing space after keyword
Error: SPACE_REPLACE_TAB    (line:  18, col:   9):	Found space when expecting tab
Error: TOO_FEW_TAB          (line:  19, col:   1):	Missing tabs for indent level
Error: SPACE_REPLACE_TAB    (line:  19, col:   5):	Found space when expecting tab
Error: TOO_FEW_TAB          (line:  20, col:   1):	Missing tabs for indent level
Error: SPACE_REPLACE_TAB    (line:  20, col:   5):	Found space when expecting tab
Error: LINE_TOO_LONG        (line:  56, col:   1):	line too long
ft_memmove.c: Error!
Error: SPACE_EMPTY_LINE     (line:  20, col:   1):	Space on empty line
Error: TOO_FEW_TAB          (line:  22, col:   1):	Missing tabs for indent level
Error: TOO_FEW_TAB          (line:  29, col:   1):	Missing tabs for indent level
Error: LINE_TOO_LONG        (line:  46, col:   1):	line too long
Error: LINE_TOO_LONG        (line:  47, col:   1):	line too long
ft_putendl_fd.c: Error!
Error: LINE_TOO_LONG        (line:  45, col:   1):	line too long
ft_putstr_fd.c: Error!
Error: LINE_TOO_LONG        (line:  44, col:   1):	line too long
ft_striteri.c: OK!
ft_strlcpy.c: Error!
Error: LINE_TOO_LONG        (line:  36, col:   1):	line too long
ft_strncmp.c: Error!
Error: LINE_TOO_LONG        (line:  64, col:   1):	line too long
Error: LINE_TOO_LONG        (line:  82, col:   1):	line too long
ft_strtrim.c: Error!
Error: CONSECUTIVE_NEWLINES (line: 106, col:   1):	Consecutive newlines
Error: CONSECUTIVE_NEWLINES (line: 107, col:   1):	Consecutive newlines
Error: CONSECUTIVE_NEWLINES (line: 108, col:   1):	Consecutive newlines
Error: CONSECUTIVE_NEWLINES (line: 109, col:   1):	Consecutive newlines
Error: CONSECUTIVE_NEWLINES (line: 110, col:   1):	Consecutive newlines
Error: CONSECUTIVE_NEWLINES (line: 111, col:   1):	Consecutive newlines
Error: CONSECUTIVE_NEWLINES (line: 112, col:   1):	Consecutive newlines
Error: EMPTY_LINE_EOF       (line: 112, col:   1):	Empty line at end of file
ft_toupper.c: OK!

✔ Executing: make fclean all bonus
ℹ Executing: libft-war-machine (https://github.com/y3ll0w42/libft-war-machine)
--------------------------------------------------------------------------------
|                              COMPILING LIBFT             |
--------------------------------------------------------------------------------
rules:
all        $(NAME)       fclean       re           clean   bonus                                                       libft.a
ok         ok            ok           ok           ok      ok                                                          found

FUNCTION         TESTS                RESULT
ft_isalpha       ✓✓✓✓✓✓✓              OK
ft_isdigit       ✓✓✓✓✓✓✓              OK
ft_isalnum       ✓✓✓✓✓✓✓              OK
ft_isascii       ✓✓✓✓✓✓✓✓             OK
ft_isprint       ✓✓✓✓✓✓✗              KO
ft_strlen        ✓✓✓✓✓✓               OK
ft_memset        ✓✓✓✓                 OK
ft_bzero         ✓✓                   OK
ft_memcpy        ✓✓✓                  OK
ft_memmove       ✓✓✓✗✓                KO
ft_strlcpy       ✓✗✓✓✓                KO
ft_strlcat       ✓✓✓✓✓✓✓✓✓            OK
ft_toupper       ✓✓✓✓✓✓✓              OK
ft_tolower       ✓✓✓✓✓✓✓              OK
ft_strchr        ✓✓✓✓✓✓               OK
ft_strrchr       ✓✓✓✓✓✓✓✓             OK
ft_strncmp       ✓✓✓✓✓✓✓✓✓✓✓          OK
ft_memchr        ✓✓✓✓✓✗               KO
ft_memcmp        ✓✓✓✓✓✓✓✓✓            OK
ft_strnstr       ✓✓✓✓✓✓✓✓✓✓           OK
ft_atoi          ✓✓✓✓✓✓✓✓✓✓✓✓✓✓✓✓✓✓✓  OK
ft_calloc        ✓                    OK
ft_strdup        ✓                    OK
ft_substr        ✓✓✓✓✓                OK
ft_strjoin       ✓✓✓✓                 OK
ft_strtrim       ✓✓✓✓✓                OK
ft_split         ✓✓✓✓✓✓               OK
ft_itoa          ✓✓✓✓✓✓✓✓✓✓           OK
ft_strmapi       ✗                    KO
ft_striteri      ✓                    OK
ft_putchar_fd    ✓✓✓✓✓✓✓              OK
ft_putstr_fd     ✓✓✓✓                 OK
ft_putendl_fd    ✓✓✓✓                 OK
ft_putnbr_fd     ✓✓✓✓✓✓✓✓✓            OK
ft_lstnew        ✓✓✓                  OK
ft_lstadd_front  ✓                    OK
ft_lstsize       ✓                    OK
ft_lstlast       ✓                    OK
ft_lstadd_back   ✓                    OK
ft_lstdelone     ✓                    OK
ft_lstclear      ✓                    OK
ft_lstiter       ✓                    OK
ft_lstmap        ✓                    OK

Abort: A  Bus error: B  Segmentation fault: S  Timeout: T

More information in: /home/aitorres/francinette/temp/libft/war-machine/deepthought

Errors in isprint: /home/aitorres/francinette/temp/libft/war-machine/tests/Part1_functions/ft_isprint
Test 7:
    i = 123;
    while (i <= 127)
    {
        ft_print_result(ft_isprint(i));
        i++;
    }
Expected (cat -e test07.output):
11110
Your result (cat -e user_output_test07):
11111
Errors in memmove: /home/aitorres/francinette/temp/libft/war-machine/tests/Part1_functions/ft_memmove
Test 4:
    if (src != ft_memmove(src, dest, 8))
        write(1, "dest's adress was not returned\n", 31);
    write(1, dest, 22);
Expected (cat -e test04.output):
rem ipssum dolor sit a
Your result (cat -e user_output_test04):
orem ipsum dolor sit a
Errors in strlcpy: /home/aitorres/francinette/temp/libft/war-machine/tests/Part1_functions/ft_strlcpy
Test 2:
    ft_print_result(ft_strlcpy(dest, "", 15));
    write(1, "\n", 1);
    write(1, dest, 15);
Expected (cat -e test02.output):
0$
^@rrrrr^@^@^@^@^@^@^@^@^@
Your result (cat -e user_output_test02):
0$
^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@
Errors in memchr: /home/aitorres/francinette/temp/libft/war-machine/tests/Part1_functions/ft_memchr
Test 6:
    int tab[7] = {-49, 49, 1, -1, 0, -2, 2};
    printf("%s", (char *)ft_memchr(tab, -1, 7));
Expected (cat -e test06.output):
M-^?M-^?M-^?1
Your result (cat -e user_output_test06):
(null)
Errors in strmapi: /home/aitorres/francinette/temp/libft/war-machine/tests/Part2_functions/ft_strmapi
Test 1:
    strcpy(str, "LoReM iPsUm");
    strmapi = ft_strmapi(str, &mapi);
    ft_print_result(strmapi);
    if (strmapi == str)
        ft_print_result("\nA new string was not returned");
    if (strmapi[11] != '\0')
        ft_print_result("\nString is not null terminated");
Expected (cat -e test01.output):
...

File too large. To see full report open: /home/aitorres/francinette/temp/libft/war-machine/errors.log

✔ Compiling tests: libftTester (https://github.com/Tripouille/libftTester)
ℹ Testing:
ft_isalpha	: 1.OK 2.OK 3.OK 4.OK 5.OK 6.OK 7.OK 8.OK 
ft_isdigit	: 1.OK 2.OK 3.OK 4.OK 
ft_isalnum	: 1.OK 2.OK 3.OK 4.OK 5.OK 6.OK 7.OK 8.OK 9.OK 10.OK 11.OK 12.OK 
ft_isascii	: 1.OK 2.OK 3.OK 4.OK 
ft_isprint	: 1.OK 2.OK 3.KO 4.OK 
ft_strlen	: 1.OK 2.OK 
ft_memset	: 1.OK 2.OK 
ft_bzero	: 1.OK 2.OK 3.OK 
ft_memcpy	: 1.OK 2.OK 3.OK 
ft_memmove	: 1.KO 2.OK 3.KO 4.OK 
ft_strlcpy	: 1.OK 2.OK 3.OK 4.KO 5.OK 6.OK 7.OK 8.OK 9.OK 
10.SIGSEGV
ft_strlcat	: 1.OK 2.OK 3.OK 4.OK 5.OK 6.OK 7.OK 8.OK 9.OK 10.OK 11.OK 12.OK 13.OK 14.OK 15.OK 16.OK 17.OK 
ft_toupper	: 1.OK 2.OK 3.OK 4.OK 
ft_tolower	: 1.OK 2.OK 3.OK 4.OK 
ft_strchr	: 1.OK 2.OK 3.OK 4.OK 5.KO 
ft_strrchr	: 1.OK 2.OK 3.OK 4.OK 5.OK 6.KO 7.OK 8.OK 
ft_strncmp	: 1.OK 2.OK 3.OK 4.OK 5.OK 6.OK 7.OK 8.OK 9.OK 10.OK 11.OK 12.OK 13.OK 14.OK 15.OK 16.OK 
ft_memchr	: 1.OK 2.KO 3.KO 4.OK 5.KO 
ft_memcmp	: 1.OK 2.OK 3.OK 4.OK 5.OK 
ft_strnstr	: 1.OK 2.OK 3.OK 4.OK 5.OK 6.OK 7.OK 8.OK 9.OK 10.OK 11.OK 12.OK 13.OK 14.OK 
ft_atoi		: 1.OK 2.OK 3.OK 4.OK 5.OK 6.OK 7.OK 8.OK 9.OK 10.OK 11.OK 12.OK 13.OK 14.OK 15.OK 16.OK 17.OK 
ft_calloc	: 1.OK 2.MOK 
ft_strdup	: 1.OK 2.MOK 3.OK 4.MOK 
ft_substr	: 1.OK 2.MOK 3.OK 4.MOK 5.OK 6.MOK 7.OK 8.MOK 9.OK 10.MOK 11.OK 12.MOK 13.OK 14.MOK 15.OK 16.MOK 
ft_strjoin	: 1.OK 2.MOK 3.OK 4.MOK 5.OK 6.MOK 7.OK 8.MOK 
ft_strtrim	: 1.OK 2.MOK 3.OK 4.MOK 5.OK 6.MOK 7.SIGSEGV
ft_split	: 1.MOK 2.OK 3.MOK 4.OK 5.MOK 6.OK 7.OK 8.OK 9.OK 10.OK 11.MOK 12.OK 13.OK 14.MOK 15.OK 16.MOK 17.OK 18.OK 19.MOK 20.OK 21.OK 22.MOK 23.OK 24.OK 25.MOK 26.OK 27.MOK 28.OK 29.MOK 30.OK 31.MOK 32.OK 33.MOK 34.OK 35.MOK 36.OK 37.MOK 38.OK 39.MOK 40.OK 41.MOK 42.OK 
ft_itoa		: 1.OK 2.MOK 3.OK 4.MOK 5.OK 6.MOK 7.OK 8.MOK 9.OK 10.MOK 11.OK 12.MOK 
ft_strmapi	: 1.OK 2.MOK 3.OK 4.MOK 
ft_striteri	: 1.OK 2.OK 3.OK 
ft_putchar_fd	: 1.OK 
ft_putstr_fd	: 1.OK 
ft_putendl_fd	: 1.OK 
ft_putnbr_fd	: 1.OK 2.OK 3.OK 4.OK 5.OK 
ft_lstnew	: 1.OK 2.OK 3.MOK 
ft_lstadd_front	: 1.OK 2.OK 3.OK 4.OK 5.OK 
ft_lstsize	: 1.OK 2.OK 3.OK 
ft_lstlast	: 1.OK 2.OK 3.OK 4.OK 
ft_lstadd_back	: 1.OK 2.OK 3.OK 4.OK 5.OK 6.OK 7.OK 8.OK 9.SIGSEGV
ft_lstdelone	: 
ft_lstclear	: 1.OK 
ft_lstiter	: 1.OK 2.OK 3.OK 4.OK 
ft_lstmap	: 1.OK 2.OK 3.OK 4.OK 5.OK 6.OK 7.OK 8.OK 


Errors in:

For /home/aitorres/francinette/tests/libft/Tripouille/tests/ft_isprint_test.cpp:
KO  20: 	/* 3 */ check(!ft_isprint('~' + 1)); showLeaks();

For /home/aitorres/francinette/tests/libft/Tripouille/tests/ft_memmove_test.cpp:
KO  24: 	/* 1 */ check(ft_memmove(s0, s, 7) == s0 && !memcmp(s, s0, 7)); showLeaks(); //Post 0
KO  26: 	/* 3 */ check(ft_memmove(s, s + 2, 2) == s && !memcmp(s, sResult, 7)); showLeaks(); //forward

For /home/aitorres/francinette/tests/libft/Tripouille/tests/ft_strlcpy_test.cpp:
KO  23: 	/* 4 */ check(ft_strlcpy(dest, src, -1) == strlen(src) && !strcmp(src, dest) && dest[strlen(src) + 1] == 'A'); showLeaks(); memset(dest, 'A', 10);

For /home/aitorres/francinette/tests/libft/Tripouille/tests/ft_strchr_test.cpp:
KO  22: 	/* 5 */ check(ft_strchr(s, 't' + 256) == s); showLeaks();

For /home/aitorres/francinette/tests/libft/Tripouille/tests/ft_strrchr_test.cpp:
KO  25: 	/* 6 */ check(ft_strrchr(s, 't' + 256) == s); showLeaks();

For /home/aitorres/francinette/tests/libft/Tripouille/tests/ft_memchr_test.cpp:
KO  20: 	/* 2 */ check(ft_memchr(s, 0, 1) == s); showLeaks();
KO  21: 	/* 3 */ check(ft_memchr(s, 2, 3) == s + 2); showLeaks();
KO  23: 	/* 5 */ check(ft_memchr(s, 2 + 256, 3) == s + 2); showLeaks(); //Cast check

For /home/aitorres/francinette/tests/libft/Tripouille/tests/ft_strtrim_test.cpp:
SIGSEGV 31: 	/* 7 */ check(!strcmp(s, ""));

For /home/aitorres/francinette/tests/libft/Tripouille/tests/ft_lstadd_back_test.cpp:
SIGSEGV 36: 	/* 9 */ check(((t_list *)((t_list *)(((t_list *)(l->next))->next))->next)->content == (void*)4);

✔ Compiling tests: libft-unit-test (https://github.com/alelievr/libft-unit-test)
ℹ Testing:
ft_isalpha      : [OK] 
ft_isdigit      : [OK] 
ft_isalnum      : [OK] 
ft_isascii      : [OK] 
ft_isprint      : [FAILED] 
[fail]: your isprint just doesn't work, REALLY ?!

ft_strlen       : [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] 
ft_memset       : [OK] [OK] [OK] [OK] [OK] [OK] [OK] 
ft_bzero        : [OK] [OK] [OK] [OK] 
ft_memcpy       : [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [CRASH] 
[crash]: your memcpy does not behave well with NULL as both params with size

ft_memmove      : [OK] [OK] [OK] [FAILED] [OK] [FAILED] [OK] [OK] [OK] [NO CRASH] [OK] [OK] [OK] [OK] 
[fail]: your memmove does not work with integers copy
[fail]: your memmove does not support the overlap (test 2)
[no crash]: your memmove does not segfault when null params is sent

ft_strlcpy      : [OK] [OK] [FAILED] [OK] [FAILED] [OK] [OK] 
[fail]: your strlcpy overflow the dest
[fail]: your strlcpy does not works with 0-length string

ft_strlcat      : [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] 
ft_toupper      : [OK] 
ft_tolower      : [OK] 
ft_strchr       : [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] 
ft_strrchr      : [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] 
ft_strncmp      : [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] 
ft_memchr       : [OK] [FAILED] [OK] [OK] [OK] [OK] [FAILED] [OK] 
[fail]: your memchr does not cast in unsigned the memory
[fail]: your memchr failed to find a \0

ft_memcmp       : [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] 
ft_strnstr      : [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [NO CRASH] 
[no crash]: your strnstr does not segfault when null parameter is sent

ft_atoi         : [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] 
ft_calloc       : [OK] [OK] [OK] [OK] [OK] 
ft_strdup       : [OK] [OK] [OK] [OK] [OK] [OK] [OK] 
ft_substr       : [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] 
ft_strjoin      : [OK] [OK] [OK] [OK] [OK] 
ft_strtrim      : [OK] [OK] [OK] [CRASH] [OK] [OK] [OK] [OK] [OK] 
[crash]: your strtrim does not work with full blank input

ft_split        : [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] 
ft_itoa         : [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] 
ft_strmapi      : [OK] [OK] [FAILED] [OK] [OK] 
[fail]: your strmapi did not set \0 at the end of the string

ft_striteri     : [OK] [OK] 
ft_putchar_fd   : [OK] [OK] 
ft_putstr_fd    : [OK] [OK] 
ft_putendl_fd   : [OK] [OK] 
ft_putnbr_fd    : [OK] [OK] [OK] [OK] [OK] 
ft_lstnew       : [OK] [OK] [OK] [OK] 
ft_lstadd_front : [OK] [OK] [OK] 
ft_lstsize      : [OK] [OK] 
ft_lstlast      : [OK] [OK] 
ft_lstadd_back  : [OK] [OK] [OK] 
ft_lstdelone    : [OK] 
ft_lstclear     : [OK] [OK] [OK] 
ft_lstiter      : [OK] 
ft_lstmap       : [OK] 

[fail]: your isprint just doesn't work, REALLY ?!
 Test code:
 	int i;
 
 	i = -1;
 	while (i < 530)
 	{
 		if (!!ft_isprint(i) != !!((*__ctype_b_loc ())[(int) ((i))] & (unsigned short int) _ISprint))
 		{
 			exit(TEST_FAILED);
 		}
 		i++;
 	}
 	exit(TEST_SUCCESS);
 
 Diffs:
      isprint: |0|
   ft_isprint: |1|
 param: (127)
 
 [crash]: your memcpy does not behave well with NULL as both params with size
 Test code:
 	ft_memcpy(((void*)0), ((void*)0), 3);
 
 
 [fail]: your memmove does not work with integers copy
 Test code:
 	unsigned long src = 0xdeadbeef;
 	int size = sizeof(src);
 
 	unsigned long dst1;
 	unsigned long dst2;
 	memmove(&dst1, &src, size);
 	ft_memmove(&dst2, &src, size);
 	if (!memcmp(&dst1, &dst2, size))
 		exit(TEST_SUCCESS);
 	exit(TEST_FAILED);
 
 Diffs:
 
 
 [fail]: your memmove does not support the overlap (test 2)
 Test code:
 	char dst1[0xF0];
 	char dst2[0xF0];
 	char *data = "thi\xc3\x9f \xc3\x9f\xde\xad\xbe\xeftri\xc3\xb1g will be \xc3\xb8v\xc3\xa9rlap\xc3\xa9d !\r\n";
 	int size = 0xF0 - 0xF;
 
 	memset(dst1, 'A', sizeof(dst1));
 	memset(dst2, 'A', sizeof(dst2));
...

File too large. To see full report open: /home/aitorres/francinette/temp/libft/alelievr/result.log

✔ Compiling tests: fsoares (my own)
ℹ Testing:
ft_isalpha      : OK
ft_isdigit      : OK
ft_isalnum      : OK
ft_isascii      : OK
ft_isprint      : KO
ft_strlen       : OK
ft_memset       : OK
ft_bzero        : OK
ft_memcpy       : OK
ft_memmove      : KO
ft_strlcpy      : KO
ft_strlcat      : OK
ft_toupper      : OK
ft_tolower      : OK
ft_strchr       : KO
ft_strrchr      : KO
ft_strncmp      : OK
ft_memchr       : KO
ft_memcmp       : OK
ft_strnstr      : OK
ft_atoi         : OK
ft_calloc       : OK
ft_strdup       : OK
ft_substr       : OK
ft_strjoin      : OK
ft_strtrim      : OK
ft_split        : OK
ft_itoa         : OK
ft_strmapi      : KO
ft_striteri     : OK
ft_putchar_fd   : OK
ft_putstr_fd    : OK
ft_putendl_fd   : OK
ft_putnbr_fd    : OK
ft_lstnew       : OK
ft_lstadd_front : OK
ft_lstsize      : OK
ft_lstlast      : OK
ft_lstadd_back  : OK
ft_lstdelone    : OK
ft_lstclear     : OK
ft_lstiter      : OK
ft_lstmap       : OK

Errors found:
For ft_isprint, in /home/aitorres/francinette/tests/libft/fsoares/test_isprint.c:

fn_isprint(127: '\177'): std: 0, yours: 1

For ft_memmove, in /home/aitorres/francinette/tests/libft/fsoares/test_memmove.c:

Error in test 1: ft_memmove(0x7ffc605a9160, 0x7ffc605a9162: "123456", 4): different memory
expected:
0000: 3132 3334 3334 3536 0011 1111 1111 1111 ->  12343456........
yours:
0000: 1111 3132 3334 3536 0011 1111 1111 1111 ->  ..123456........


For ft_strlcpy, in /home/aitorres/francinette/tests/libft/fsoares/test_strlcpy.c:

Error in test 5: ft_strlcpy(dest, "aasdjj;s;sa", 100): different memory
expected:
0000: 6161 7364 6a6a 3b73 3b73 6100 1111 1111 ->  aasdjj;s;sa.....
yours:
0000: 6161 7364 6a6a 3b73 3b73 6100 6674 5f73 ->  aasdjj;s;sa.ft_s
0010: 7472 6c63 7079 0025 2d31 3673 3a20 0077 ->  trlcpy.%-16s: .w
0020: 0065 7272 6f72 735f 7374 726c 6370 792e ->  .errors_strlcpy.
0030: 6c6f 6700 1b5b 303b 3331 6d4b 4f1b 5b30 ->  log..[0;31mKO.[0
0040: 6d00 1b5b 303b 3332 6d4f 4b1b 5b30 6d00 ->  m..[0;32mOK.[0m.
0050: 0000 0000 0000 0059 6f75 2061 7265 2074 ->  .......You are t
0060: 7279 6900 1111 1111 1111 1111 1111 1111 ->  ryi.............


For ft_strchr, in /home/aitorres/francinette/tests/libft/fsoares/test_strchr.c:

Error in test 5: ft_strchr(0x55b2cf6210a6: "teste", 357: 'e'): expected: 0x55b2cf6210a7, yours: (nil)
Error in test 6: ft_strchr(0x55b2cf6210a6: "teste", 1024: '\0'): expected: 0x55b2cf6210ab, yours: (nil)

For ft_strrchr, in /home/aitorres/francinette/tests/libft/fsoares/test_strrchr.c:

Error in test 5: ft_strrchr(0x563eae8990a7: "teste", 1125: 'e'): expected: 0x563eae8990ab, yours: (nil)
Error in test 6: ft_strrchr(0x563eae8990a7: "teste", 1024: '\0'): expected: 0x563eae8990ac, yours: (nil)

For ft_memchr, in /home/aitorres/francinette/tests/libft/fsoares/test_memchr.c:

Error in test 18: ft_memchr(0x7ffee59fffc0, 635(7b): '{', 46): expected: 0x7ffee59fffcf, yours: (nil)
Memory content:
at 0x0x7ffee59fffc0: b906 d7e8 313f a570 7cd4 948b 173e 687b ->  ....1?.p|....>h{
at 0x0x7ffee59fffd0: 073d b726 93bf 9354 d3e1 d052 55fe cd0e ->  .=.&...T...RU...
at 0x0x7ffee59fffe0: 05a5 f636 e49b a760 703b eb87 7a54 0281 ->  ...6...`p;..zT..


For ft_strmapi, in /home/aitorres/francinette/tests/libft/fsoares/test_strmapi.c:

Error in test 1: ft_strmapi("", {(i, c) => i + c}): expected: "", got: "\021"
...

File too large. To see full report open: /home/aitorres/francinette/temp/libft/fsoares/error.log


Summary: 

Norminette Errors: ft_lstiter.c, ft_lstlast.c, ft_lstmap.c, ft_lstnew.c, ft_lstsize.c, ft_memcmp.c, ft_memset.c, ft_putchar_fd.c, ft_putnbr_fd.c, ft_split.c, ft_strlcat.c, ft_substr.c, ft_itoa.c, ft_lstadd_back.c, ft_lstadd_front.c, ft_lstclear.c, ft_lstdelone.c, ft_memmove.c, ft_putendl_fd.c, ft_putstr_fd.c, ft_strlcpy.c, ft_strncmp.c, ft_strtrim.c

Failed tests: strtrim, strchr, ft_strtrim, memchr, ft_memmove, ft_strlcpy, memmove, ft_lstadd_back, strlcpy, ft_strrchr, strnstr, strrchr, ft_isprint, isprint, strmapi, ft_strchr, ft_memchr, memcpy

Passed tests: isalpha, isdigit, isalnum, isascii, strlen, memset, bzero, strlcat, toupper, tolower, strncmp, memcmp, atoi, calloc, strdup, substr, strjoin, split, itoa, striteri, putchar_fd, putstr_fd, putendl_fd, putnbr_fd, lstnew, lstadd_front, lstsize, lstlast, lstadd_back, lstdelone, lstclear, lstiter, lstmap
c1r11s2% ls
es.subject-1.pdf  ft_isalnum.c	ft_isprint.c	   ft_lstclear.c   ft_lstmap.c	 ft_memcmp.c   ft_putchar_fd.c	ft_split.c     ft_strjoin.c  ft_strmapi.c  ft_strtrim.c  libft.h     test
ft_atoi.c	  ft_isalpha.c	ft_itoa.c	   ft_lstdelone.c  ft_lstnew.c	 ft_memcpy.c   ft_putendl_fd.c	ft_strchr.c    ft_strlcat.c  ft_strncmp.c  ft_substr.c	 Makefile
ft_bzero.c	  ft_isascii.c	ft_lstadd_back.c   ft_lstiter.c    ft_lstsize.c  ft_memmove.c  ft_putnbr_fd.c	ft_strdup.c    ft_strlcpy.c  ft_strnstr.c  ft_tolower.c  README.md
ft_calloc.c	  ft_isdigit.c	ft_lstadd_front.c  ft_lstlast.c    ft_memchr.c	 ft_memset.c   ft_putstr_fd.c	ft_striteri.c  ft_strlen.c   ft_strrchr.c  ft_toupper.c  README.txt
c1r11s2% 
c1r11s2% 







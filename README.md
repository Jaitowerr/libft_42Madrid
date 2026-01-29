*Este proyecto ha sido creado como parte del currículo de 42 por '<'aitorres>'*


# Descripción
`libft` es una biblioteca en lenguaje C cuyo objetivo es recrear una colección de funciones y otras utilidades básicas del lenguaje.
Este proyecto sirve como base para todos los futuros proyectos de 42, permitiendo trabajar con funciones propias, totalmente implementadas, entendiendo en profundidad:

* Manejo de memoria
* Conversión de tipos
* Manipulación de cadenas
* Punteros
* Implementación de funciones de bajo nivel

La librería generada es libft.a, que puede enlazarse en cualquier proyecto en C.
<br><br><br>
## Lista de funcciones

<br>
PARTE 1

Estas funciones son réplicas de la librería estándar de C (libc).

Funciones de clasificación de caracteres    | Funciones de manipulación de memoria        | Funciones de cadenas de texto               | Conversión y memoria dinámica
:-----------:                               | :-----------:                               | :-----------:                               | :-----------:
[ft_isalpha](#ft_isalpha)		                |[ft_memset](#ft_memset)                      | [ft_strlen](#ft_strlen)                     | [ft_atoi](#ft_atoi) 
[ft_isdigit](#ft_isdigit)		                |[ft_bzero](#ft_bzero)                        | [ft_strlcpy](#ft_strlcpy)                   | [ft_calloc](#ft_calloc) 
[ft_isalnum](#ft_isalnum)	                  |[ft_memcpy](#ft_memcpy)                      | [ft_strlcat](#ft_strlcat)                   |  
[ft_isascii](#ft_isascii)                   |[ft_memmove](#ft_memmove)                    | [ft_strchr](#ft_strchr)                     | 
[ft_isprint](#ft_isprint)                   |[ft_memchr](#ft_memchr)                      | [ft_strrchr](#ft_strrchr)                   |
[ft_toupper](#ft_toupper)		                |[ft_memcmp](#ft_memcmp)                      | [ft_strncmp](#ft_strncmp)                   | 
[ft_tolower](#ft_tolower)	                  |                                             | [ft_strnstr](#ft_strnstr)                   | 
[ft_tolower](#ft_tolower)	                  |                                             | [ft_strdup](#ft_strdup)                     | 


<br><br>
PARTE 2

Estas funciones no pertenecen a la librería estándar de C o están modificadas. Se centran principalmente en la manipulación avanzada de strings y la salida de datos por descriptores de archivo (file descriptors).
Manipulación de String                      | Conversion y memoria                     | Salida por FD (File Descriptor)
:-----------:                               | :-----------:                            | :-----------:
[ft_substr](#ft_substr)		                   |[ft_itoa](#ft_itoa)                       | [ft_putchar_fd](#ft_putchar_fd)
[ft_strjoin](#ft_strjoin)		                 |[ft_split](#ft_split)                     | [ft_putstr_fd](#ft_putstr_fd)
[ft_strtrim](#ft_strtrim)	                  |                                          | [ft_putendl_fd](#ft_putendl_fd)
 [ft_strmapi](#ft_strmapi)                  |                                          | [ft_putnbr_fd](#ft_putnbr_fd)
[ft_striteri](#ft_striteri)                 |                                          | 




<br><br>
PARTE 3

Estas funciones utilizan la estructura t_list. Son fundamentales para aprender a gestionar memoria dinámica y punteros de forma avanzada.
Creación y Adición                          | Navegación y Tamaño                      | Borrado y Modificación
:-----------:                               | :-----------:                            | :-----------:
[ft_lstnew](#ft_lstnew)		                |[ft_lstsize](#ft_lstsize)                 | [ft_lstdelone](#ft_lstdelone)
[ft_lstadd_front](#ft_lstadd_front)		    |[ft_lstlast](#ft_lstlast)                 | [ft_lstclear](#ft_lstclear)
[ft_lstadd_back](#ft_lstadd_back)	        |                                          | [ft_lstiter](#ft_lstiter)
 |	 ||	 [ft_lstmap](#ft_lstmap)




### Si quieres saber que realiza cada función, que parámetros utiliza cada una desliza a la zona inferior "Descripción" o haz click sobre el nombre d ela función de las tablas superiores..

<br><br><br>

# Instrucciones

Encontrarás un arcivo **Makefield**, este archivo es importante no borrarlo, dado que es quien maneja los comandos anteriores gestionando toda la librería. En esencia, un *makefile* sirve para autocompilar un proyecto en lugar de hacerlo manualmente.

Para compilar esta librería y conseguir el archivo .a, puedes utilizar los siguientes comandos desde la consola:
* make     		--> Compila todo
* make clean  	--> Borra objetos
* make fclean 	--> Borra objetos y librería .a
* make re     	--> Limpia y recompila de nuevo

<br>
Si deseas ejecutar un main dentro de un mismo archivo utiliza:
							
	cc -Wall -Wextra -Werror ft_xxxx.c -o test_xxxx && ./test_xxxx
Sustituye las xxxx por el nombre d ela función, es posible que te toque proteger los main con #ifdef TEST antes del main y terminarlo con #endif y ejecutar:

	cc -Wall -Wextra -Werror -DTEST ft_xxxx.c ft_xxxxxx.c -o test_xxxx && ./test_xxxx

<br><br><br>

# Recursos

Esta lista de funciones a parte del uso de la librería `man` para ciertas funciones, se ha utilizado la ayuda de compañeros, a parte, se han utilizado recursos externos como páginas de https://pythontutor.com/render.html# para ver como se mueve el código dentro de las funciones y partes de peor comprensión, se ha utilizado la propia consola para compilar y también páginas como https://www.programiz.com/c-programming/online-compiler/ que permite compilar al momento y hacer cambios rápidos.
El uso de la IA ha sido para comprender fallos de comprensión en el funcionamiento de ciertas funciones que por mas búsquedas en internet o la explicación de compañeros no he sido capaz de captar. También tras no encontrar el error tras pelearse con el código le he pedido ayuda para ver donde falla, y sobre todo sin pedir el código, por qué falla mi código, a la vez de hemos pedido ciertas pruebas que colocar en lso main para probarlas en caso extremo. Aun así al pasar el programa Paco que contiene varios test, hemos visto varios fallos que hemos solucionado antes de entregar el proyecto.

<br><br><hr>
<br><br><br>

## Descripción de la librería, función por función:
<br>

### [ft_isalpha](/ft_isalpha.c) 
    int ft_isalpha(int c)
Comprueba si c es un carácter alfabético, devuelve 1 si lo es o 0 si no lo es.
Da igual mayúsculas que minúsculas.
Puede recibir un char porque lo transforma a int según la tabla ASCII.
<br><br>
### [ft_isdigit](/ft_isdigit.c)
    int ft_isdigit(int c)
Comprueba si c es un carácter numérico, devuelve 1 si lo es o 0 si no lo es. Puede recibir un char porque lo transforma a int según la tabla Ascii, sino, introducir el número correspondiento según Ascii, entre 48 siendo 0 y 57 siendo el 9.
<br><br>
### [ft_isalnum](/ft_isalnum.c)
    int	ft_isalnum(int c)
Comprueba si c es alfanumérico, devuelve 1 si lo es y 0 si no es.  Puede recibir un char porque lo transforma a int según la tabla Ascii, sino, introducir el número correspondiento según Ascii.
<br><br>
### [ft_isascii](/ft_isascii.c)
    int	ft_isascii(int c)
Comprueba si c es un carácter ASCII, devuelve 1 si lo es y 0 si no es. Un caracter de la tablas ASCII es cualquiera entre 0 y 127, ambos incluidos. Puede recibir un char porque lo transforma a int según la tabla Ascii, sino, introducir el número correspondiento según Ascii.
<br><br>
### [ft_isprint](/ft_isprint.c)
    int	ft_isprint(int c)
Comprueba si c es un carácter imprimible según ASCII, devuelve 1 si lo es y 0 si no es. Un caracter IMPRIMIBLE de la tabla ASCII es cualquiera entre 32 y 127, ambos incluidos. Puede recibir un char porque lo transforma a int según la tabla Ascii, sino, introducir el número correspondiento según Ascii.
<br>
### [ft_strlen](/ft_strlen.c)
    size_t	ft_strlen(char *s)
Mide el largo de una cadena de texto y devuelve el largo. No cuenta el nulo. Se utiliza size_t para adaptar a sistemas de 32 y 64 bits. Porque no usar unsogned_int?¿? En un sistema de 32 bits, un unsigned int puede almacenar valores hasta aproximadamente 4 mil millones (2³² - 1). Esto parece suficiente, ¿verdad? Pero en un sistema de 64 bits, puedes tener cadenas de texto (strings) que ocupen más de 4 GB de memoria (2⁶⁴ - 1). size_t se adapta automáticamente al sistema.
<br>
### [ft_memset](/ft_memset.c)       
    void *ft_memset(void *ptr, int x, size_t len)
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
<br>
### [ft_bzero](/ft_bzero.c)
    void ft_bzero(void *ptr, size_t len)
El nombre viene de "Byte Zero"
	Su función principal es poner a cero (escribir el byte \0) una porción de memoria. Es básicamente una versión simplificada de memset donde el valor que escribes siempre es 0.
	Recuerda, recibe void *ptr, luego hay que asignarle unsigned char. al igual que memset, pasar asignar byte por byte ya que no definimos su tamaño al ser void. "Casteor"
<br>
### [ft_memcpy](/ft_memcpy.c)
    void *ft_memcpy(void *dst, const void *src, size_t n)
Copia n bytes desde la memoria apuntada por src hacia la memoria apuntada por dst.
Es como un "copiar-pegar"
		dst: Destino donde se copiarán los bytes.
		src: Origen desde donde se copian los bytes (marcado como const porque no se modifica).
		n: Número de bytes a copiar.
	Devuelve dst
<br>
### [ft_memmove](/ft_memmove.c)
    void	*ft_memmove(void *str, const void *src, size_t n)
Copiar n bytes desde la dirección src a la dirección dest, , manejando correctamente el caso en que las áreas de memoria se solapen
Trata la memoria como unsigned char para copiar byte a byte.
			src = Es mi dato a leer y utilizar.
			str = desde dónde escribo.
Pueden apuntar al mismo bloque, pero a posiciones distintas str + 2(empieza en posicion 2 a concatenar 'n' bytes de src)
<br>
### [ft_strlcpy](/ft_strlcpy.c)
    size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize)
Copia la cadena a la que apunta src, incluido el byte nulo de terminación ('\0'), al búfer señalado por dst.
dstsize SIEMPRE tiene que ser el tamaño real del array dst. ¿Qué pasa si miento en dstsize? -->	Buffer overflow. Segfault.
¿Qué devuelve strlcpy?	Siempre el largo de src.
<br>
### [ft_strlcat](/ft_strlcat.c)
    size_t strlcat(char dest, const char *restrict src, size_t destsize);
Pega la cadena src al final de la cadena dst, asegurándose de no pasarse del tamaño total dstsize y de que el resultado siempre termine en un nulo (\0).
Devuelve la longitud teórica de la frase que intentaste crear: la suma de la longitud inicial de dst más la longitud de src.
		dest = Es una caja que ya tiene algo dentro.    dst[10] = "Hola";
		src = Es lo que quieres añadir al final de la caja. src[8] = " mundo"
		dstsize = Es el tamaño TOTAL de la caja dst.    dst[10], sería 10.

En strlcpy: Borrabas lo que había y escribías desde el principio.
En strlcat: Respetas lo que hay, buscas el final, y añades a continuación sin pasarte del límite dstsize.
<br>
### [ft_toupper](/ft_toupper.c)
    ft_toupper(int c)
Convierte un carácter de minúscula a MAYÚSCULA basándose en la tabla ASCII (entre 97 para 'a' y 122 para 'z'), devuelve el número correspondiente a la MAYÚSCULA (restando 32). Si no es una minúscula, devuelve c tal cual.
<br>
### [ft_tolower](/ft_tolower.c)
    int ft_tolower(int c)
Convierte un carácter de MAYÚSCULA a minúscula basándose en la tabla ASCII (entre 65 para 'A' y 90 para 'Z'), devuelve el número correspondiente a la minúscula (restando 32). Si no es una MAYÚSCULA, devuelve c tal cual.
<br>
### [ft_strchr](/ft_strchr.c)
    char *strchr(const char *s, int c);
Busca la primera aparición del carácter c en la cadena s. Recorre la cadena byte por byte hasta encontrar el carácter buscado (casteado a char) o llegar al final.
Devuelve un puntero a la posición donde encontró el carácter. Si no lo encuentra, devuelve NULL.
Importante: El carácter nulo \0 se considera parte de la cadena, por lo que si buscas \0, la función devolverá un puntero al final de la cadena (no NULL).
<br>
### [t_strrchr](/t_strrchr.c)
    char *strrchr(const char *s, int c);
La r de strrchr viene de "Reverse" (al revés). Su misión es encontrar la última aparición.
Busca la ultima aparición del carácter c en la cadena s. Recorre la cadena byte por byte hasta encontrar el carácter buscado (casteado a char) o llegar al principio.
	Devuelve un puntero a la posición donde encontró el carácter. Si no lo encuentra, devuelve NULL.
	Importante: El carácter nulo '\0' se considera parte de la cadena, por lo que si buscas \0, la función devolverá un puntero al final de la cadena (no NULL).
<br>
### [ft_strncmp](/ft_strncmp.c)
    int ft_strncmp(const char *s1, const char *s2, size_t n)
Compara los primeros n caracteres de dos cadenas de texto (s1 y s2). Recorre ambas cadenas byte por byte hasta encontrar una diferencia, llegar al final de alguna cadena (\0), o haber comparado n caracteres.
	Siemrpe es s1 - s2.
	Importante: La comparación debe hacerse casteando a unsigned char para manejar correctamente caracteres extendidos de ASCII (valores > 127).
	A diferencia de strcmp, esta versión es más segura porque le pones un límite de bytes a comparar, evitando leer memoria que no te pertenece o desbordamientos.
<br>
### [ft_memchr](/ft_memchr.c)
    void *memchr(const void *s, int c, size_t n)
Buscamos 'c' en *s, esta búsqueda del c se basa según si *s llega a '\0' o si el contador llega a n 
<br>
### [ft_memcmp](/ft_memcmp.c)
    int memcmp(const void *s1, const void *s2, size_t n)
Compara *s1 y *s2 en cada posición hasta 'n', pero si n se el da valor 0, el return es 0.
	Tiene que recorrer s1 y s2 hasta 'n'
	Devuelve -1 si la resta es negativa, 0 si es igual todo, y 1 si es positivo.
<br>
### [ft_strnstr](/ft_strnstr.c)
    char	*ft_strnstr(const char *big, const char *little, size_t len)
Es un buscador, busca dentro de big la primera aparición de una subcadena (little), pero limitando la búsqueda a un número máximo de caracteres (len) ?
	 si little está vacía, devuelve big.
	 Si little está despues de 'len' en 'Big', pilla a medias de la posicion 'len' o no se completa devuelve NULL.
	 Si no se encuentra little, devuelve 'NULL'.
<br>
### [ft_atoi](/ft_atoi.c)
    int	atoi(const char *nptr)
Esta es una función de C que convierte una representación de cadena de un número entero 'char' en un valor entero 'int'.
	los espacios = 32 o del 9 al 13 includo, avanza, si tiene un signo, uno solo ó '+' ó '-' se guarda con 1 o -1.
	Se convierte de char a int, si hay letrs u otras cosas despues de los números se ignora y se para.
	No se mira desbordamiento del número máximo, se trabaja con un int.
<br>
### [ft_calloc](/ft_calloc.c)
    void *calloc(size_t nmemb, size_t size);
ft_calloc busca crear memoria para el tipo de dato, para ello utiliza malloc, calcula el numero de datos por el tipo, un char, ocupa un byte, 1 direccion de memoria, un int ocupa 4 bytes, 4 direcciones de memoria.
	Despues de calcular, el espacio, lo crea, y lo rellena de 0 con ft_bzero.
	Una vez asignada la memoria retorna, devuelve la direccióon del primer puntero.
<br>
### [ft_strdup](/ft_strdup.c)
    char *ft_strdup(const char *s);
Crea un duplicado de *s.
Si luego modificamos nuestro nueva copia, veriamos como solo se modifica lo nuevo y no *s.
<br>
### [ft_substr](/ft_substr.c)
    char	*ft_substr(char const *s, unsigned int start, size_t len);
Reserva memoria (con malloc(3)) y devuelve una subcadena de caracteres de la cadena ‘s’. La subcadena comienza en el índice ‘start ’ y tiene una longitud máxima ‘len ’.
	La subcadena de caracteres resultante. NULL si falla la reserva de memoria.
<br><br>

PARTE 2

### [ft_substr](/ft_substr.c)
    char *ft_substr(char const *s, unsigned int start, size_t len);
 - s: La cadena original desde la que se crea la subcadena.
 - start: El índice del carácter en ‘s’ desde el que empieza la subcadena.
 - len: La longitud máxima de la subcadena.
Crea una copia (con malloc) de un fragmento de la cadena s. Empieza en la posición start y copia como máximo len caracteres.
	Si start es mayor que el largo de s, devuelve una cadena vacía ("") con malloc.
	Si len es más grande que lo que queda de cadena desde start, se recorta para no leer memoria fuera de s.
	Retorno: La nueva subcadena terminada en \0 o NULL si falla el malloc.
<br>

### [ft_strjoin](/ft_strjoin.c)
    char *ft_strjoin(char const *s1, char const *s2);
Reserva memoria y devuelve una nueva cadena formada por la concatenación de s1 y s2.
Mide el largo de ambas cadenas, reserva len(s1) + len(s2) + 1 bytes, copia s1, luego s2, y añade el \0 final.
Las cadenas originales no se modifican. Es responsabilidad del usuario liberar la memoria devuelta.
 Retorno: Puntero a la nueva cadena o NULL si malloc falla.
<br>

### [ft_strtrim](/ft_strtrim.c)
    char *ft_strtrim(char const *s1, char const *set);
Elimina todos los caracteres set de la cadena desde el principio y el final de s1.
Devuelve una nueva cadena (con malloc) con los caracteres indeseados recortados.
Busca el primer carácter de s1 que no esté en set (inicio), luego busca el último carácter de s1 que no esté en set (final), y copia solo esa porción en una nueva cadena y la devuelve.
Si s1 está completamente formada por caracteres de set, devuelve una cadena vacía ("").
Retorno: La nueva cadena recortada terminada en \0, o NULL si falla la reserva de memoria.
<br>

### [ft_split](/ft_split.c)
    char **ft_split(char const *s, char c);
 - Un char * es un puntero a una cadena (un array de caracteres).
 - Un char ** es un puntero a un array de punteros a cadenas. Es decir, un array de strings es un char **
Recibe una cadena s y un carácter delimitador c.
Divide la cadena s en subcadenas separadas por el carácter c.
Devuelve un array de punteros a cadenas (cada puntero apunta a una subcadena).
El array termina con un puntero NULL para indicar el final.
		Cuenta cuántas subcadenas.
		Reserva memoria para el array de punteros (tamaño = número de subcadenas + 1 para el NULL).
		Si falla alguna reserva, libera todo lo reservado hasta ese momento
		Devuelve el array con todas las subcadenas y un NULL al final .
<br>

### [ft_itoa](/ft_itoa.c)
    char *ft_itoa(int n);
Recibe un int. La función gestiona conbertir de int a char reservando memoria para el char. Para poder manejar extremos de un int, es decir sus limitaciones, cremoas una variable para transformarla de int a long. Creamso con malloc el tamaño del puntero y guardamos numero por número.
Retorna un char *.
<br>

### [ft_strmapi](/ft_strmapi.c)
    char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
strmapi gestiona una función dentro de otra función. y devulve un nuevo puntero.
Aplica la función ‘f’ a cada carácter de la cadena ‘s’, pasando su índice como primer argumento y el propio carácter como segundo argumento. 
Se crea una nueva cadena (utilizando malloc(3)) para almacenar los resultados de las sucesivas aplicaciones de ‘f’.
Debe devolver el puntero creado.
<br>

### [ft_striteri](/ft_striteri.c)
    void ft_striteri(char *s, void (*f)(unsigned int, char*));
muy parecido a strmapi, pero en este caso en vez de enviar el char, y agregarlo a una segunda cadena lo modifiquemos o no, en este caso enviamos la direccion de &s[i] iteramos directamente sobre la cadena y la modificamos directamente, no retornamos nada. 
<br>

### [ft_putchar_fd](/ft_putchar_fd.c)
    void ft_putchar_fd(char c, int fd);
ESta funcion imprime un write, de 1 byte.
	write(fd, &c, 1);
 -	fd = (file descriptor ) :
		 - 0	STDIN_FILENO	Standard Input	Lo que escribes con el teclado (ej. scanf).
		 - 1	STDOUT_FILENO	Standard Output	Lo que ves en la pantalla (ej. printf).
		 - 2	STDERR_FILENO	Standard Error	Los mensajes de error (también salen en pantalla, pero por otro "tubo").
	- &c = la dirección de c. El manual de instrucciones dice que el segundo parámetro debe ser una dirección de memoria (un puntero).
 - 1 = imprimimos 1byte en este caso, sería el numero de bytes a imprimir
Entonces, en 1 stdout lo que sería fd, le decimos ve a la dirección &c y llévate solo el primer bloque que encuentres.
<br>

### [ft_putstr_fd](/ft_putstr_fd.c)
    void ft_putstr_fd(char *s, int fd);
recorre el largo de cadena e impre la cadena entera en con write en vez de un caracter. REcibe el fd, el puntero, y el número de bytes.
<br>

### [ft_putendl_fd](/ft_putendl_fd.c)
    void ft_putendl_fd(char *s, int fd)
recorre el largo de cadena e impre la cadena entera en con write en vez de un caracter. REcibe el fd, el puntero, y el número de bytes. Añade un salto de línea al final de frase
<br>

### [ft_putnbr_fd](/ft_putnbr_fd.c)
    void ft_putnbr_fd(int n, int fd);
imprimir numeros negativos y positivos con el write. Utiliza putchar para imprimir caracteres. Retroalimentación de la función.
<br><br>

3 PARTE

listas, para que sirven las listas¿?
* Si solo haces un nodo y lo liberas en el main, efectivamente no sirve para nada. Es como comprar un solo eslabón de una cadena y tirarlo.
* La magia de las listas enlazadas aparece cuando quieres guardar datos que no sabes cuántos son de antemano.
* La lista puede crecer hasta que se acabe la memoria del ordenador. Es importante liberar memoria free

Las variables de la estructura t_list son:
	* content: los datos contenidos en el nodo. Usar void * permite almacenar cualquier tipo de dato.
	* next: la dirección del siguiente nodo, o NULL si el nodo actual es el último de la lista
<br>

### [ft_lstnew](/ft_lstnew.c)	
    t_list *ft_lstnew(void *content);
Crea un nuevo nodo para una lista enlazada. Reserva memoria con malloc para el nodo.
  content es un puntero al contenido que se guardará en el nodo (puede ser cualquier tipo de dato).
El puntero content del nodo se asigna con el valor del parámetro. El puntero next se inicializa a NULL, indicando que no apunta a otro nodo
Retorno: Puntero al nuevo nodo creado, o NULL si falla la reserva de memoria.
<br>

### [ft_lstadd_front](/ft_lstadd_front.c)
    void ft_lstadd_front(t_list **lst, t_list *new);
Esta función sirve para añadir un nuevo nodo al principio de una lista enlazada. Imagina que tienes una lista de nodos, y quieres poner uno nuevo justo al inicio, para que sea el primero. Eso es lo que hace ft_lstadd_front.
La función engancha el nuevo nodo al principio de la lista y actualiza la variable head del main para que ahora apunte a este nuevo nodo.
<br>

### [ft_lstsize](/ft_lstsize.c)
    int ft_lstsize(t_list *lst)
Esta función cuenta el número de nodos en una lista enlazada.
Recorre la lista nodo por nodo avanzando con lst = lst->next hasta que lst sea NULL.
Devuelve el numero de nodos contados.
<br>

### [ft_lstlast](/ft_lstlast.c)
    t_list *ft_lstlast(t_list *lst);
Esta función devuelve el último nodo de una lista enlazada.
	lst es un puntero al primer nodo de la lista. Retorna un puntero al último nodo, o NULL si la lista está vacía. Puede usarse para añadir un nodo nuevo al final de una lista, antes de Null por ejemplo.
<br>

### [ft_lstadd_back](/ft_lstadd_back.c)
    void ft_lstadd_back(t_list **lst, t_list *new);
Esta función es igual que ft_lstadd_front pero añadiendo un nuevo nodo al final de la lista.
Si la lista está vacía (*lst == NULL), el nuevo nodo se convierte en el primero.
<br>

### [ft_lstdelone](/ft_lstdelone.c)
    void ft_lstdelone(t_list *lst, void (*del)(void*));
Libera un único nodo de una lista enlazada, incluyendo su contenido.
		- lst: Puntero al nodo que se quiere eliminar.
		- del: Puntero a una función que se encarga de liberar la memoria del contenido del nodo (ej: free).
	Si el nodo no es NULL, llama a la función del pasándole el contenido (lst->content) para liberarlo.
	Luego libera la memoria del nodo en sí con free(lst).
<br>

### [ft_lstclear](/ft_lstclear.c)
    void ft_lstclear(t_list **lst, void (*del)(void*));
Elimina y libera todos los nodos de una lista enlazada.
		- lst: Dirección del puntero al primer nodo de la lista.
		- del: Puntero a una función que libera la memoria del contenido de cada nodo.
	En cada nodo, llama a del para liberar su contenido.
	Diferencia con ft_lstdelone: Esta borra toda la lista, no solo un nodo.
<br>

### [ft_lstiter](/ft_lstiter.c)
    void ft_lstiter(t_list *lst, void (*f)(void *));
Recorre una lista enlazada nodo por nodo mientras haya nodos (lst != NULL), y aplica una función a cada nodo.
	Avanza al siguiente nodo con lst = lst->next
<br>

### [ft_lstmap(](/ft_lstmap.c)
    t_list *ft_lstmap(t_list *lst, void *(*f)(void *),void (*del)(void *));
Crea una nueva lista aplicando una función a cada nodo de la lista original.
		- lst: Puntero al primer nodo de la lista original.
		- f: Puntero a una función que transforma el contenido de cada nodo.
		- del: Puntero a una función para liberar memoria en caso de fallo.
	Retorna un puntero a la nueva lista creada, o NULL si falla.
<br>


















gcc -Wall -Wextra -Werror ft_xxxx.c -o test_xxxx && ./test_xxxx


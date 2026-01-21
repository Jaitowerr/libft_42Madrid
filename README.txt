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

ft_memmove      void	*ft_memmove(void *dest, const void *src, size_t n)
    Copia len bytes de la memoria de src a dst. La memoria pueden superponerse. Primero, los bytes en src se copian en una matriz temporal y luego en dst
        src = Es mi dato a leer y utilizar.
        dest = desde dónde escribo.
        Pueden apuntar al mismo bloque, pero a posiciones distintas dest + 2(empieza en posicion 2 a concatenar 'n' bytes de src)

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








gcc -Wall -Wextra -Werror ft_xxxx.c -o test_xxxx && ./test_xxxx
















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






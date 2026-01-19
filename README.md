*Este proyecto ha sido creado como parte del currículo de 42 por '<'aitorres>'*

# Descripción
`libft` es una biblioteca en lenguaje C cuyo objetivo es recrear una colección de funciones y otras utilidades básicas del lenguaje.
El propósito del proyecto es profundizar en el manejo de memoria, punteros, arrays, conversión de tipos, y comprensión de funciones fundamentales del ecosistema C.

Esta librería sirve como base para futuros proyectos de 42, permitiendo utilizar funciones propias implementadas desde cero.

## Lista de funcciones



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

---

| PARTE 2 | 
Funciones de clasificación de caracteres    | Funciones de manipulación de memoria        | 
:-----------:                               | :-----------:                               | 
[ft_isalpha](#ft_isalpha)		                |[ft_memset](#ft_memset)                      | 
[ft_isdigit](#ft_isdigit)		                |[ft_bzero](#ft_bzero)                        | 
[ft_isalnum](#ft_isalnum)	                  |[ft_memcpy](#ft_memcpy)                      | 
[ft_isascii](#ft_isascii)                   |[ft_memmove](#ft_memmove)                    | 
[ft_isprint](#ft_isprint)                   |[ft_memchr](#ft_memchr)                      | 
[ft_toupper](#ft_toupper)		                |[ft_memcmp](#ft_memcmp)                      |
[ft_tolower](#ft_tolower)	                  |                                             |
[ft_tolower](#ft_tolower)	                  |                                             |

# Instrucciones

## Compilación
```
make
```
### ¿Que es [Makefile](/Makefile) y como hacerlo?
#### ¿Que es [Makefile](/Makefile) y como hacerlo?
##### ¿Que es [Makefile](/Makefile) y como hacerlo?

Un archivo del tipo *makefile* es un archivo que hace uso de la utilidad `make`. Esta utilidad determina que partes de un programa deben de compilarse, y les manda comandos para hacerlo. En esencia, un *makefile* sirve para autocompilar un proyecto en lugar de hacerlo manualmente.

Para poder hacer uso de `make`, en primer lugar debe crearse un archivo del tipo *makefile*. Para ello basta con crear uno con nombre "Makefile".


---


Otros comandos:
```
make clean        # Elimina archivos .o
make fclean       # Elimina .o y libft.a
make re           # Limpia y recompila todo
```

## Uso
```
#include "libft.h"
```

gcc tu_codigo.c -L. -lft

---

# Descripción de la librería
### Lista de funcciones

<br>

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





# Recursos
Manual POSIX
ASCII Table
cplusplus reference

# Uso de IA


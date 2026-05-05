_Este proyecto ha sido creado como parte del currículo de 42 por scamlett._

# libft

## Descripción

`libft` es una librería en C que reimplementa funciones base de `libc` y añade utilidades para strings, memoria, escritura en [descriptor de archivo](https://es.wikipedia.org/wiki/Descriptor_de_archivo) y listas enlazadas.

Su objetivo es disponer de una librería personal y reutilizable para los siguientes proyectos del cursus, con código propio, legible y compatible con la norma.

He decidido redactar este README en español para poder explicar la funcionalidad del código de la forma más clara y natural posible. Así, cualquier compañero o evaluador de 42 Málaga que necesite una explicación detallada podrá comprenderla fácilmente. 

## Instrucciones

Compilación de la libreria:

```bash
make
```

Limpieza de objetos:

```bash
make clean
```

Limpieza completa (objetos + librería):

```bash
make fclean
```

Recompilación completa:

```bash
make re
```

La salida del proyecto es el archivo `libft.a` en la raíz del repositorio.

## Recursos

1. Manuales del sistema para funciones estandar de C (glibc).
2. PDF oficial de 42 con la norma y criterios de evaluacion del proyecto libft.
3. https://man7.org/linux/man-pages/index.html (manual online de Linux)
4. https://github.com/openbsd/src (repositorio oficial de código fuente de openbsd)
5. https://makefiletutorial.com/ & https://docs.redhat.com/es/documentation/red_hat_enterprise_linux/8/html/developing_c_and_cpp_applications_in_rhel_8/example-building-a-c-program-using-a-makefile_managing-more-code-with-make (Makefile)
6. https://www.learn-c.org/en/Linked_lists (listas enlazadas)
7. https://pythontutor.com/c.html# (debugger online)
8. https://www.boot.dev/ (curso online de manejo de memoria en C, estructuras de datos y algoritmos)
9. https://cs50.harvard.edu/x/ (CS50’s Introduction to Computer Science)

 Se ha hecho un uso limitado y responsable de la IA para formatear este README.md, refactorizar líneas de código en acorde con la norma y [DRY (Don't Repeat Yourself)](https://www.arsys.es/blog/dont-repeat-yourself-en-programacion), y para aclarar dudas relacionadas con la implementación y funcionalidad de los archivos .c y asegurarme que he entendido el código.

Todo el código final se ha verificado con `make` y `norminette`.

# Documentación Completa de Libft

1. [Índice](#índice)
2. [Funciones de Libc ](#1-funciones-de-libc)
3. [Funciones Adicionales](#2-funciones-adicionales)
4. [Listas Enlazadas](#3-listas-enlazadas)
5. [Cómo crear un Makefile](#cómo-crear-un-makefile)
6. [Conceptos Clave](#conceptos-clave)

---

## Índice

Esta biblioteca contiene **43 funciones** en total, algunas de cuáles reimplementan funciones estándar de C, más algunas funciones adicionales útiles para proyectos futuros.

## 1. Funciones de Libc

1. [`ft_isalpha.c`](#ft_isalpha)
2. [`ft_isdigit.c`](#ft_isdigit)
3. [`ft_isalnum.c`](#ft_isalnum)
4. [`ft_isascii.c`](#ft_isascii)
5. [`ft_isprint.c`](#ft_isprint)
6. [`ft_strlen.c`](#ft_strlen)
7. [`ft_memset.c`](#ft_memset)
8. [`ft_bzero.c`](#ft_bzero)
9. [`ft_memcpy.c`](#ft_memcpy)
10. [`ft_memmove.c`](#ft_memmove)
11. [`ft_strlcpy.c`](#ft_strlcpy)
12. [`ft_strlcat.c`](#ft_strlcat)
13. [`ft_toupper.c`](#ft_toupper)
14. [`ft_tolower.c`](#ft_tolower)
15. [`ft_strchr.c`](#ft_strchr)
16. [`ft_strrchr.c`](#ft_strrchr)
17. [`ft_strncmp.c`](#ft_strncmp)
18. [`ft_memchr.c`](#ft_memchr)
19. [`ft_memcmp.c`](#ft_memcmp)
20. [`ft_strnstr.c`](#ft_strnstr)
21. [`ft_atoi.c`](#ft_atoi)
22. [`ft_calloc.c`](#ft_calloc)
23. [`ft_strdup.c`](#ft_strdup)

## 2. Funciones Adicionales

1. [`ft_substr.c`](#ft_substr)
2. [`ft_strjoin.c`](#ft_strjoin)
3. [`ft_strtrim.c`](#ft_strtrim)
4. [`ft_split.c`](#ft_split)
5. [`ft_itoa.c`](#ft_itoa)
6. [`ft_strmapi.c`](#ft_strmapi)
7. [`ft_striteri.c`](#ft_striteri)
8. [`ft_putchar_fd.c`](#ft_putchar_fd)
9. [`ft_putstr_fd.c`](#ft_putstr_fd)
10. [`ft_putendl_fd.c`](#ft_putendl_fd)
11. [`ft_putnbr_fd.c`](#ft_putnbr_fd)

## 3. Listas Enlazadas

1. [`ft_lstnew.c`](#ft_lstnew)
2. [`ft_lstadd_front.c`](#ft_lstadd_front)
3. [`ft_lstsize.c`](#ft_lstsize)
4. [`ft_lstlast.c`](#ft_lstlast)
5. [`ft_lstadd_back.c`](#ft_lstadd_back)
6. [`ft_lstdelone.c`](#ft_lstdelone)
7. [`ft_lstclear.c`](#ft_lstclear)
8. [`ft_lstiter.c`](#ft_lstiter)
9. [`ft_lstmap.c`](#ft_lstmap)

---


### ft_isalpha

**Archivo:** `ft_isalpha.c`

**¿Qué hace?**  
Verifica si un carácter es una letra del alfabeto (A-Z o a-z).

**¿Cómo funciona el código?**

```c
int ft_isalpha(int c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        return (1);
    return (0);
}
```

- Comprueba si `c` está en el rango ASCII de 'A' a 'Z' (65-90)
- O si está en el rango de 'a' a 'z' (97-122)
- Devuelve 1 (verdadero) si es una letra, 0 en caso contrario

**Ejemplo:**

```c
#include <stdio.h>

int	main(void)
{
	printf("ft_isalpha('A') = %d\n", ft_isalpha('A'));
	printf("ft_isalpha('1') = %d\n", ft_isalpha('1'));
	return (0);
}
```

---

### ft_isdigit

**Archivo:** `ft_isdigit.c`

**¿Qué hace?**  
Verifica si un carácter es un dígito numérico (0-9).

**¿Cómo funciona el código?**

```c
int ft_isdigit(int c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}
```

- Comprueba si `c` está entre '0' (ASCII 48) y '9' (ASCII 57)
- Devuelve 1 si es un dígito, 0 si no lo es

**Ejemplo:**

```c
#include <stdio.h>

int	main(void)
{
	printf("ft_isdigit('9') = %d\n", ft_isdigit('9'));
	printf("ft_isdigit('x') = %d\n", ft_isdigit('x'));
	return (0);
}
```

---

### ft_isalnum

**Archivo:** `ft_isalnum.c`

**¿Qué hace?**  
Verifica si un carácter es alfanumérico (letra o número).

**¿Cómo funciona el código?**

```c
int ft_isalnum(int c)
{
    if (ft_isalpha(c) || ft_isdigit(c))
        return (1);
    return (0);
}
```

- Utiliza las funciones `ft_isalpha` y `ft_isdigit` ya definidas
- Si el carácter pasa cualquiera de las dos pruebas, devuelve 1

**Ejemplo:**

```c
#include <stdio.h>

int	main(void)
{
	printf("ft_isalnum('B') = %d\n", ft_isalnum('B'));
	printf("ft_isalnum('@') = %d\n", ft_isalnum('@'));
	return (0);
}
```

---

### ft_isascii

**Archivo:** `ft_isascii.c`

**¿Qué hace?**  
Verifica si un valor está dentro del rango ASCII válido (0-127).

**¿Cómo funciona el código?**

```c
int ft_isascii(int c)
{
    if (c >= 0 && c <= 127)
        return (1);
    return (0);
}
```

- El rango ASCII estándar incluye valores de 0 a 127
- Devuelve 1 si el valor está en este rango

**Ejemplo:**

```c
#include <stdio.h>

int	main(void)
{
	printf("ft_isascii(65) = %d\n", ft_isascii(65));
	printf("ft_isascii(200) = %d\n", ft_isascii(200));
	return (0);
}
```

---

### ft_isprint

**Archivo:** `ft_isprint.c`

**¿Qué hace?**  
Verifica si un carácter es imprimible (visible en pantalla).

**¿Cómo funciona el código?**

```c
int ft_isprint(int c)
{
    if (c >= 32 && c <= 126)
        return (1);
    return (0);
}
```

- Los caracteres imprimibles van del 32 (espacio) al 126 (~)
- Excluye caracteres de control (como '\n', '\t', etc.)
- Devuelve 1 si es imprimible, 0 si no lo es

**Ejemplo:**

```c
#include <stdio.h>

int	main(void)
{
	printf("ft_isprint(32) = %d\n", ft_isprint(32));
	printf("ft_isprint(10) = %d\n", ft_isprint(10));
	return (0);
}
```

---

### ft_toupper

**Archivo:** `ft_toupper.c`

**¿Qué hace?**  
Convierte una letra minúscula a mayúscula.

**¿Cómo funciona el código?**

```c
int ft_toupper(int c)
{
    if (c >= 'a' && c <= 'z')
        return (c - 32);
    return (c);
}
```

- En ASCII, las mayúsculas están 32 posiciones antes que las minúsculas
- Si `c` es minúscula ('a' a 'z'), resta 32 para obtener la mayúscula
- Si no es minúscula, devuelve el carácter sin cambios

**Ejemplo:**

```c
#include <stdio.h>

int	main(void)
{
	printf("ft_toupper('a') = %c\n", ft_toupper('a'));
	printf("ft_toupper('Z') = %c\n", ft_toupper('Z'));
	return (0);
}
```

---

### ft_tolower

**Archivo:** `ft_tolower.c`

**¿Qué hace?**  
Convierte una letra mayúscula a minúscula.

**¿Cómo funciona el código?**

```c
int ft_tolower(int c)
{
    if (c >= 'A' && c <= 'Z')
        return (c + 32);
    return (c);
}
```

- Si `c` es mayúscula ('A' a 'Z'), suma 32 para obtener la minúscula
- Si no es mayúscula, devuelve el carácter sin cambios

**Ejemplo:**

```c
#include <stdio.h>

int	main(void)
{
	printf("ft_tolower('A') = %c\n", ft_tolower('A'));
	printf("ft_tolower('z') = %c\n", ft_tolower('z'));
	return (0);
}
```

---

### ft_strlen

**Archivo:** `ft_strlen.c`

**¿Qué hace?**  
Calcula la longitud de una cadena (número de caracteres antes del '\0').

**¿Cómo funciona el código?**

```c
size_t ft_strlen(const char *str)
{
    size_t i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}
```

- Inicializa un contador `i` en 0
- Recorre la cadena incrementando `i` hasta encontrar el carácter nulo '\0'
- Devuelve el número de caracteres contados

**Ejemplo:**

```c
#include <stdio.h>

int	main(void)
{
	printf("ft_strlen(\"Hola\") = %zu\n", ft_strlen("Hola"));
	printf("ft_strlen(\"\") = %zu\n", ft_strlen(""));
	return (0);
}
```

---

### ft_strchr

**Archivo:** `ft_strchr.c`

**¿Qué hace?**  
Busca la primera aparición de un carácter en una cadena.

**¿Cómo funciona el código?**

```c
char *ft_strchr(const char *s, int c)
{
    while (*s)
    {
        if (*s == (char)c)
            return ((char *)s);
        s++;
    }
    if (*s == (char)c)
        return ((char *)s);
    return (NULL);
}
```

- Recorre la cadena `s` carácter por carácter
- Compara cada carácter con `c` (convertido a char)
- Si encuentra coincidencia, devuelve un puntero a esa posición
- Importante: también verifica el '\0' final (permite buscar el nulo)
- Si no encuentra el carácter, devuelve NULL

**Ejemplo:**

```c
#include <stdio.h>

int	main(void)
{
	char	*res;

	res = ft_strchr("libft", 'f');
	printf("Resultado: %s\n", res);
	return (0);
}
```

---

### ft_strrchr

**Archivo:** `ft_strrchr.c`

**¿Qué hace?**  
Busca la última aparición de un carácter en una cadena.

**¿Cómo funciona el código?**

```c
char *ft_strrchr(const char *s, int c)
{
    int i;

    i = (int)ft_strlen(s);
    while (i >= 0)
    {
        if (s[i] == (char)c)
            return ((char *)&s[i]);
        i--;
    }
    return (NULL);
}
```

- Calcula primero la longitud de la cadena con `ft_strlen`
- Comienza desde el final de la cadena (en la posición de longitud)
- Recorre hacia atrás buscando el carácter
- Devuelve puntero a la última aparición encontrada
- Si no lo encuentra, devuelve NULL

**Ejemplo:**

```c
#include <stdio.h>

int	main(void)
{
	char	*res;

	res = ft_strrchr("banana", 'a');
	printf("Resultado: %s\n", res);
	return (0);
}
```

---

### ft_strncmp

**Archivo:** `ft_strncmp.c`

**¿Qué hace?**  
Compara dos cadenas hasta un máximo de `n` caracteres.

**¿Cómo funciona el código?**

```c
int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i;

    if (n == 0)
        return (0);
    i = 0;
    while (i < n - 1 && s1[i] && s2[i] && s1[i] == s2[i])
    {
        i++;
    }
    return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
```

- Si `n` es 0, devuelve 0 directamente
- Recorre ambas cadenas mientras sean iguales y queden posiciones por comparar
- Cuando encuentra diferencia (o final de alguna cadena), devuelve la resta de los bytes como `unsigned char`
- El casting a unsigned char es importante para comparaciones correctas

**Ejemplo:**

```c
#include <stdio.h>

int	main(void)
{
	printf("cmp1: %d\n", ft_strncmp("abc", "abc", 3));
	printf("cmp2: %d\n", ft_strncmp("abc", "abd", 3));
	return (0);
}
```

---

### ft_strnstr

**Archivo:** `ft_strnstr.c`

**¿Qué hace?**  
Busca una subcadena dentro de otra cadena, limitando la búsqueda a `len` bytes.

**¿Cómo funciona el código?**

```c
char *ft_strnstr(const char *big, const char *little, size_t len)
{
    size_t i;
    size_t j;

    if (little[0] == '\0')
        return ((char *)big);
    i = 0;
    while (big[i] && i < len)
    {
        j = 0;
        while (big[i + j] && little[j] && (i + j) < len && big[i + j] == little[j])
        {
            j++;
        }
        if (little[j] == '\0')
            return ((char *)&big[i]);
        i++;
    }
    return (NULL);
}
```

- Si `little` está vacía, devuelve `big` inmediatamente
- Usa dos bucles: uno externo recorre `big`, uno interno verifica coincidencias
- Para cada posición en `big`, intenta hacer coincidir toda la `little`
- Respeta el límite `len` en ambos bucles
- Devuelve puntero al inicio de la coincidencia o NULL

**Ejemplo:**

```c
#include <stdio.h>

int	main(void)
{
	char	*res;

	res = ft_strnstr("hola mundo", "mundo", 10);
	printf("Resultado: %s\n", res);
	return (0);
}
```

---

### ft_memchr

**Archivo:** `ft_memchr.c`

**¿Qué hace?**  
Busca un byte específico en un bloque de memoria.

**¿Cómo funciona el código?**

```c
void *ft_memchr(const void *s, int c, size_t n)
{
    size_t                  i;
    const unsigned char     *str;

    i = 0;
    str = (const unsigned char *)s;
    while (i < n)
    {
        if (str[i] == (unsigned char)c)
            return ((void *)(str + i));
        i++;
    }
    return (NULL);
}
```

- Convierte el puntero `s` a `unsigned char *` para trabajar byte a byte
- Recorre `n` bytes buscando el valor `c`
- Compara cada byte con `c` (convertido a unsigned char)
- Devuelve puntero al primer byte que coincide
- Si no encuentra coincidencia en `n` bytes, devuelve NULL

**Ejemplo:**

```c
#include <stdio.h>

int	main(void)
{
	char	str[] = "hola";
	char	*res;

	res = ft_memchr(str, 'l', 4);
	printf("Resultado: %s\n", res);
	return (0);
}
```

---

Estas funciones crean nuevas cadenas o modifican las existentes.

### ft_strdup

**Archivo:** `ft_strdup.c`

**¿Qué hace?**  
Duplica una cadena creando una copia en memoria dinámica.

**¿Cómo funciona el código?**

```c
char *ft_strdup(const char *s1)
{
    size_t  len;
    char    *dup;
    size_t  i;

    len = ft_strlen(s1);
    dup = (char *)malloc((len + 1) * sizeof(char));
    if (!dup)
        return (NULL);
    i = 0;
    while (i < len)
    {
        dup[i] = s1[i];
        i++;
    }
    dup[i] = '\0';
    return (dup);
}
```

- Calcula la longitud de `s1` con `ft_strlen`
- Reserva memoria para `len + 1` caracteres (el +1 es para el '\0')
- Si `malloc` falla, devuelve NULL
- Copia carácter por carácter de `s1` a `dup`
- Añade el terminador nulo al final
- Devuelve el puntero a la nueva cadena

**Importante:** El usuario debe liberar la memoria con `free()` cuando termine de usar la cadena.

**Ejemplo:**

```c
#include <stdio.h>

int	main(void)
{
	char	*dup;

	dup = ft_strdup("hola");
	if (!dup)
		return (1);
	printf("dup: %s\n", dup);
	free(dup);
	return (0);
}
```

---

### ft_strlcpy

**Archivo:** `ft_strlcpy.c`

**¿Qué hace?**  
Copia una cadena a un buffer con un tamaño máximo, garantizando terminación nula.

**¿Cómo funciona el código?**

```c
size_t ft_strlcpy(char *dst, const char *src, size_t size)
{
    size_t i;

    if (size != 0)
    {
        i = 0;
        while (src[i] && i < (size - 1))
        {
            dst[i] = src[i];
            i++;
        }
        dst[i] = '\0';
    }
    return (ft_strlen(src));
}
```

- Calcula primero la longitud total de `src`
- Si `size` es 0, no copia nada pero devuelve la longitud de `src`
- Copia hasta `size - 1` caracteres (deja espacio para '\0')
- Siempre añade el terminador nulo
- **Importante:** Devuelve la longitud de `src`, NO los bytes copiados
- Esto permite detectar si hubo truncamiento (si retorno >= size)

**Ejemplo:**

```c
#include <stdio.h>

int	main(void)
{
	char	dst[6];
	size_t	len;

	len = ft_strlcpy(dst, "abcdef", sizeof(dst));
	printf("dst: %s | len: %zu\n", dst, len);
	return (0);
}
```

---

### ft_strlcat

**Archivo:** `ft_strlcat.c`

**¿Qué hace?**  
Concatena una cadena al final de otra con límite de tamaño de buffer.

**¿Cómo funciona el código?**

```c
size_t ft_strlcat(char *dst, const char *src, size_t size)
{
    size_t i;
    size_t dlen;
    size_t slen;

    dlen = 0;
    slen = ft_strlen(src);
    while (dst[dlen] && dlen < size)
    {
        dlen++;
    }
    if (dlen == size)
    {
        return (size + slen);
    }
    i = 0;
    while (src[i] && (dlen + i + 1) < size)
    {
        dst[dlen + i] = src[i];
        i++;
    }
    dst[dlen + i] = '\0';
    return (dlen + slen);
}
```

- Calcula `slen` con `ft_strlen(src)`
- Busca el final de `dst` sin leer fuera del límite `size`
- Si no encuentra terminador en ese límite, devuelve `size + slen`
- Añade caracteres de `src` al final de `dst` hasta llenar el buffer
- Siempre termina con '\0'
- Devuelve la longitud total que habría tenido (`dlen + slen`)

**Ejemplo:**

```c
#include <stdio.h>

int	main(void)
{
	char	dst[12] = "Hola";
	size_t	len;

	len = ft_strlcat(dst, "42", sizeof(dst));
	printf("dst: %s | len: %zu\n", dst, len);
	return (0);
}
```

---

### ft_substr

**Archivo:** `ft_substr.c`

**¿Qué hace?**  
Extrae una subcadena desde una posición específica con una longitud determinada.

**¿Cómo funciona el código?**

```c
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if ((size_t)start >= slen)
		return (ft_strdup(""));
	if (len > slen - start)
		len = slen - start;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_memcpy(str, s + start, len);
	str[len] = '\0';
	return (str);
}
```

- Si `s` es NULL, devuelve NULL
- Si `start` está fuera de la cadena, devuelve cadena vacía con `ft_strdup("")`
- Ajusta `len` si excede el final de la cadena 
- Reserva memoria para `len + 1` caracteres
- Copia `len` caracteres desde la posición `start` usando `ft_memcpy`
- Añade terminador nulo y devuelve la nueva subcadena

**Ejemplo:**

```c
#include <stdio.h>

int	main(void)
{
	char	*sub;

	sub = ft_substr("abcdef", 2, 3);
	if (!sub)
		return (1);
	printf("sub: %s\n", sub);
	free(sub);
	return (0);
}
```

---

### ft_strjoin

**Archivo:** `ft_strjoin.c`

**¿Qué hace?**  
Concatena dos cadenas en una nueva cadena reservada en memoria dinámica.

**¿Cómo funciona el código?**

```c
char *ft_strjoin(char const *s1, char const *s2)
{
    char   *str;
    size_t len;

    if (!s1 || !s2)
        return (NULL);
    len = ft_strlen(s1) + ft_strlen(s2) + 1;
    str = (char *)malloc(len * sizeof(char));
    if (!str)
        return (NULL);
    ft_strlcpy(str, s1, len);
    ft_strlcat(str, s2, len);
    return (str);
}
```

- Verifica que ambas cadenas no sean NULL
- Calcula las longitudes de ambas cadenas
- Reserva memoria para la suma de ambas longitudes + 1
- Usa `ft_strlcpy` para copiar `s1` primero
- Usa `ft_strlcat` para añadir `s2` al final
- Devuelve la nueva cadena concatenada

**Ejemplo:**

```c
#include <stdio.h>

int	main(void)
{
	char	*join;

	join = ft_strjoin("hola", "42");
	if (!join)
		return (1);
	printf("join: %s\n", join);
	free(join);
	return (0);
}
```

---

### ft_strtrim

**Archivo:** `ft_strtrim.c`

**¿Qué hace?**  
Elimina caracteres específicos del principio y final de una cadena.

**¿Cómo funciona el código?**

```c
static int ft_isinset(char c, char const *set)
{
    while (*set)
    {
        if (c == *set)
            return (1);
        set++;
    }
    return (0);
}

char *ft_strtrim(char const *s1, char const *set)
{
    size_t start;
    size_t end;

    if (!s1 || !set)
        return (NULL);
    start = 0;
    while (s1[start] && ft_isinset(s1[start], set))
        start++;
    end = ft_strlen(s1);
    while (end > start && ft_isinset(s1[end - 1], set))
        end--;
    return (ft_substr(s1, start, end - start));
}
```

- Función helper `ft_isinset`: verifica si un carácter está en el conjunto `set`
- Encuentra el índice `start` avanzando desde el inicio mientras los caracteres estén en `set`
- Encuentra el índice `end` retrocediendo desde el final mientras los caracteres estén en `set`
- Usa `ft_substr` para extraer la parte central (sin los caracteres del set)

**Ejemplo:**

```c
#include <stdio.h>

int	main(void)
{
	char	*trim;

	trim = ft_strtrim("--hola--", "-");
	if (!trim)
		return (1);
	printf("trim: %s\n", trim);
	free(trim);
	return (0);
}
```

---

### ft_split

**Archivo:** `ft_split.c`

**¿Qué hace?**  
Divide una cadena en múltiples subcadenas usando un delimitador, devolviendo un array de cadenas.

**¿Cómo funciona el código?**

Usa 3 funciones auxiliares, además de la función principal:

1. **`ft_count_words`**: Cuenta cuántas palabras hay.

```c
static int ft_count_words(char const *s, char c)
{
    int count;
    int i;

    count = 0;
    i = 0;
    while (s[i])
    {
        while (s[i] && s[i] == c)
            i++;
        if (!s[i])
            break ;
        count++;
        while (s[i] && s[i] != c)
            i++;
    }
    return (count);
}
```

- Salta delimitadores
- Cuando encuentra un carácter que no es delimitador, incrementa el contador
- Salta la palabra completa
- Repite hasta el final

2. **`ft_free_words`**: Libera memoria en caso de error

```c
static void ft_free_words(char **split, int used)
{
    int i;

    i = 0;
    while (i < used)
        free(split[i++]);
    free(split);
}
```

- Libera cada cadena ya creada del array
- Finalmente libera el array de punteros

3. **`ft_fill_words`**: Recorre la cadena y rellena el array

```c
static int ft_fill_words(char **split, char const *s, char c)
{
    int i;
    int j;
    int len;

    i = 0;
    j = 0;
    while (s[j])
    {
        while (s[j] && s[j] == c)
            j++;
        if (!s[j])
            break ;
        len = 0;
        while (s[j + len] && s[j + len] != c)
            len++;
        split[i] = ft_substr(s, j, len);
        if (!split[i])
            return (ft_free_words(split, i), -1);
        i++;
        j += len;
    }
    return (0);
}
```

- Salta delimitadores iniciales
- Calcula la longitud de cada palabra con un índice auxiliar
- Guarda cada palabra con `ft_substr`
- Si una reserva falla, libera lo ya creado y devuelve `-1`

4. **`ft_split`**:

```c
char **ft_split(char const *s, char c)
{
    char    **split;

    if (!s)
        return (NULL);
    split = malloc((ft_count_words(s, c) + 1) * sizeof(char *));
    if (!split)
        return (NULL);
    if (ft_fill_words(split, s, c) < 0)
        return (NULL);
    split[ft_count_words(s, c)] = NULL;
    return (split);
}
```

- Cuenta las palabras para saber cuántos punteros necesita
- Reserva array de punteros (+1 para NULL final)
- Rellena el array con `ft_fill_words`
- Si falla una reserva, libera todo con `ft_free_words`
- Devuelve el array o NULL si hubo error

**Ejemplo:**

```c
#include <stdio.h>

int	main(void)
{
	char	**arr;
	int		i;

	arr = ft_split("uno dos tres", ' ');
	if (!arr)
		return (1);
	i = 0;
	while (arr[i])
	{
		printf("arr[%d]: %s\n", i, arr[i]);
		free(arr[i]);
		i++;
	}
	free(arr);
	return (0);
}
```

---

### ft_strmapi

**Archivo:** `ft_strmapi.c`

**¿Qué hace?**  
Crea una nueva cadena aplicando una función a cada carácter de la cadena original.

**¿Cómo funciona el código?**

```c
char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char           *str;
    unsigned int   i;

    if (!s || !f)
        return (NULL);
    str = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
    if (!str)
        return (NULL);
    i = 0;
    while (s[i])
    {
        str[i] = f(i, s[i]);
        i++;
    }
    str[i] = '\0';
    return (str);
}
```

- Verifica que `s` y `f` no sean NULL
- Reserva memoria para la nueva cadena
- Aplica la función `f` a cada carácter: `f(índice, carácter)`
- Devuelve la nueva cadena transformada

**Ejemplo:**

```c
#include <stdio.h>

static char	to_upper_even(unsigned int i, char c)
{
	if (i % 2 == 0 && c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

int	main(void)
{
	char	*res;

	res = ft_strmapi("abcdef", to_upper_even);
	if (!res)
		return (1);
	printf("strmapi: %s\n", res);
	free(res);
	return (0);
}
```

---

### ft_memset

**Archivo:** `ft_memset.c`

**¿Qué hace?**  
Rellena un bloque de memoria con un valor específico.

**¿Cómo funciona el código?**

```c
void *ft_memset(void *s, int c, size_t n)
{
    size_t i;

    i = 0;
    while (i < n)
    {
        ((unsigned char *)s)[i] = (unsigned char)c;
        i++;
    }
    return (s);
}
```

- Recorre `n` bytes del bloque apuntado por `s`
- Asigna el valor `c` (convertido a unsigned char) a cada byte
- Devuelve el puntero original `s`

**Ejemplo:**

```c
#include <stdio.h>

int	main(void)
{
	char	str[20] = "abcdef";

	ft_memset(str, 'X', 3);
	printf("Resultado: %s\n", str);
	return (0);
}
```

---

### ft_bzero

**Archivo:** `ft_bzero.c`

**¿Qué hace?**  
Rellena un bloque de memoria con ceros (inicializa a 0).

**¿Cómo funciona el código?**

```c
void ft_bzero(void *s, size_t n)
{
    ft_memset(s, 0, n);
}
```

- Simplemente llama a `ft_memset` con el valor 0
- Es una función wrapper para conveniencia
- Útil para limpiar/inicializar buffers

**Ejemplo:**

```c
#include <stdio.h>

int	main(void)
{
	char	str[] = "Hello, World!";

	printf("Antes: %s\n", str);
	ft_bzero(str, 5);
	printf("Despues: %s\n", str);
	return (0);
}
```

---

### ft_memcpy

**Archivo:** `ft_memcpy.c`

**¿Qué hace?**  
Copia un bloque de memoria de origen a destino (no maneja solapamiento).

**¿Cómo funciona el código?**

```c
void *ft_memcpy(void *dest, const void *src, size_t n)
{
    size_t       i;
    unsigned char *d;
    const unsigned char *s;

    if (!dest && !src)
        return (NULL);
    d = (unsigned char *)dest;
    s = (const unsigned char *)src;
    i = 0;
    while (i < n)
    {
        d[i] = s[i];
        i++;
    }
    return (dest);
}
```

- Si ambos punteros son NULL, devuelve NULL
- Convierte ambos punteros a `unsigned char*`
- Copia byte a byte de `src` a `dest`
- **Importante:** No maneja solapamiento correctamente (usar `ft_memmove` para eso)
- Devuelve el puntero `dest`

**Ejemplo:**

```c
#include <stdio.h>

int	main(void)
{
	char	src[] = "12345";
	char	dst[10];

	ft_memcpy(dst, src, 6);
	printf("Copia: %s\n", dst);
	return (0);
}
```

---

### ft_memmove

**Archivo:** `ft_memmove.c`

**¿Qué hace?**  
Copia un bloque de memoria manejando correctamente el solapamiento de origen y destino.

**¿Cómo funciona el código?**

```c
static void ft_copy_forward(char *d, const char *s, size_t len)
{
    size_t i;

    i = 0;
    while (i < len)
    {
        d[i] = s[i];
        i++;
    }
}

static void ft_copy_backward(char *d, const char *s, size_t len)
{
    while (len > 0)
    {
        len--;
        d[len] = s[len];
    }
}

void *ft_memmove(void *dest, const void *src, size_t len)
{
    char       *d;
    const char *s;

    if (!dest && !src)
        return (NULL);
    d = (char *)dest;
    s = (const char *)src;
    if (s < d && (s + len) > d)
        ft_copy_backward(d, s, len);
    else
        ft_copy_forward(d, s, len);
    return (dest);
}
```

- **Clave**: Detecta si las regiones realmente se solapan antes de copiar hacia atrás
- Si `src` está antes que `dest` y el rango de `src` alcanza `dest`, copia hacia atrás
- En cualquier otro caso, copia hacia adelante
- Esto previene corrupción cuando las áreas de memoria se solapan

**Ejemplo de solapamiento:**

```c
char buffer[] = "Hola mundo";
ft_memmove(buffer + 2, buffer, 5);
// Sin manejo de solapamiento: resultado impredecible
// Con manejo correcto: "HoHola ndo"
```

---

### ft_memcmp

**Archivo:** `ft_memcmp.c`

**¿Qué hace?**  
Compara dos bloques de memoria byte a byte.

**¿Cómo funciona el código?**

```c
int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    size_t              i;
    const unsigned char *str1;
    const unsigned char *str2;

    str1 = (const unsigned char *)s1;
    str2 = (const unsigned char *)s2;
    i = 0;
    while (i < n)
    {
        if (str1[i] != str2[i])
            return (str1[i] - str2[i]);
        i++;
    }
    return (0);
}
```

- Convierte ambos punteros a `unsigned char*`
- Compara los primeros `n` bytes
- Si encuentra diferencia, devuelve la resta (positivo, negativo o cero)
- Si todos los `n` bytes son iguales, devuelve 0

**Ejemplo:**

```c
#include <stdio.h>

int	main(void)
{
	printf("cmp1: %d\n", ft_memcmp("abc", "abc", 3));
	printf("cmp2: %d\n", ft_memcmp("abc", "abd", 3));
	return (0);
}
```

---

### ft_calloc

**Archivo:** `ft_calloc.c`

**¿Qué hace?**  
Reserva memoria para un array e inicializa todos los bytes a cero.

**¿Cómo funciona el código?**

```c
void *ft_calloc(size_t count, size_t size)
{
    unsigned char *ptr;

    if (size != 0 && count > ((size_t)-1) / size)
        return (NULL);
    ptr = malloc(count * size);
    if (!ptr)
        return (NULL);
    ft_bzero(ptr, count * size);
    return (ptr);
}
```

- **Protección contra overflow**: Verifica que `count * size` no desborde
  - Si `size != 0` y `count > SIZE_MAX / size`, hay overflow → devuelve NULL
- Si `count` o `size` es 0, `malloc` recibe 0 bytes
- Reserva `count * size` bytes con `malloc`
- Inicializa todo a cero con `ft_bzero`
- **Importante para seguridad**: La verificación de overflow previene vulnerabilidades

**Ejemplo:**

```c
#include <stdio.h>

int	main(void)
{
	int	*arr;

	arr = ft_calloc(4, sizeof(int));
	if (!arr)
		return (1);
	printf("arr[0]=%d arr[3]=%d\n", arr[0], arr[3]);
	free(arr);
	return (0);
}
```

---

### ft_atoi

**Archivo:** `ft_atoi.c`

**¿Qué hace?**  
Convierte una cadena a un número entero (ASCII to Integer).

**¿Cómo funciona el código?**

```c
int ft_atoi(const char *str)
{
    int i;
    int sign;
    int result;

    i = 0;
    sign = 1;
    result = 0;
    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return (result * sign);
}
```

- **Paso 1**: Salta espacios en blanco y caracteres de control (9-13 son '\t', '\n', '\v', '\f', '\r')
- **Paso 2**: Detecta el signo opcional ('+' o '-')
- **Paso 3**: Convierte dígito a dígito:
  - Multiplica el resultado actual por 10 (desplaza posiciones)
  - Suma el nuevo dígito (convierte char a int restando '0')
- **Paso 4**: Aplica el signo y devuelve el resultado

**Ejemplo:**

```c
#include <stdio.h>

int	main(void)
{
	const char	*str = "   -12345abc";
	int			result;

	result = ft_atoi(str);
	printf("%d\n", result);
	return (0);
}
```

---

### ft_itoa

**Archivo:** `ft_itoa.c`

**¿Qué hace?**  
Convierte un número entero a cadena (Integer to ASCII).

**¿Cómo funciona el código?**

Usa dos funciones helper:

1. **`ft_num_len`**: Calcula cuántos caracteres necesita el número

```c
static int ft_num_len(long n)
{
    int len;

    len = 0;
    if (n <= 0)
    {
        len++;  // Para el signo '-' o el '0'
        n = -n;
    }
    while (n > 0)
    {
        len++;
        n /= 10;
    }
    return (len);
}
```

- Si el número es negativo o cero, suma 1 (para '-' o '0')
- Cuenta dígitos dividiendo por 10 repetidamente

2. **`ft_fill_num`**: Rellena la cadena con los dígitos

```c
static void ft_fill_num(char *str, long nb, int len)
{
    while (nb > 0)
    {
        str[--len] = (nb % 10) + '0';
        nb /= 10;
    }
}
```

- Rellena desde el final hacia el principio
- Extrae cada dígito con módulo 10
- Convierte dígito a char sumando '0'

3. **`ft_itoa`**: Función principal

```c
char *ft_itoa(int n)
{
    char *str;
    long nb;
    int  len;

    nb = (long)n;  // Convertir a long para manejar INT_MIN
    len = ft_num_len(nb);
    str = (char *)malloc((len + 1) * sizeof(char));
    if (!str)
        return (NULL);
    str[len] = '\0';
    if (nb == 0)
    {
        str[0] = '0';
        return (str);
    }
    if (nb < 0)
    {
        str[0] = '-';
        nb = -nb;
    }
    ft_fill_num(str, nb, len);
    return (str);
}
```

- Convierte `n` a `long` para manejar INT_MIN (-2147483648)
  - INT_MIN no puede negarse como int sin overflow
- Calcula longitud necesaria
- Reserva memoria
- Caso especial: si es 0, devuelve "0"
- Si es negativo, pone '-' al inicio y trabaja con valor positivo
- Llena los dígitos con `ft_fill_num`

**Ejemplo:**

```c
#include <stdio.h>

int	main(void)
{
	char	*s;

	s = ft_itoa(-42);
	printf("itoa: %s\n", s);
	free(s);
	return (0);
}
```

---

### ft_striteri

**Archivo:** `ft_striteri.c`

**¿Qué hace?**  
Aplica una función a cada carácter de una cadena, modificando la cadena original.

**¿Cómo funciona el código?**

```c
void ft_striteri(char *s, void (*f)(unsigned int, char *))
{
    unsigned int i;

    if (!s || !f)
        return;
    i = 0;
    while (s[i])
    {
        f(i, &s[i]);
        i++;
    }
}
```

- Verifica que `s` y `f` no sean NULL
- Recorre cada carácter de la cadena
- Llama a la función `f` pasando el índice y un puntero al carácter
- La función `f` puede modificar el carácter directamente (recibe puntero)

**Ejemplo:**

```c
#include <stdio.h>

static void	to_upper_even(unsigned int i, char *c)
{
	if (i % 2 == 0 && *c >= 'a' && *c <= 'z')
		*c -= 32;
}

int	main(void)
{
	char	str[] = "abcdef";

	ft_striteri(str, to_upper_even);
	printf("striteri: %s\n", str);
	return (0);
}
```

---


### ft_putchar_fd

**Archivo:** `ft_putchar_fd.c`

**¿Qué hace?**  
Escribe un solo carácter en el descriptor de archivo especificado.

**¿Cómo funciona el código?**

```c
void ft_putchar_fd(char c, int fd)
{
    write(fd, &c, 1);
}
```

- Usa la llamada al sistema `write(fd, buffer, count)`
- `fd`: descriptor de archivo (0=stdin, 1=stdout, 2=stderr, o archivo abierto)
- `&c`: dirección del carácter a escribir
- `1`: número de bytes a escribir

**Ejemplo:**

```c
#include <stdio.h>

int	main(void)
{
	printf("Salida esperada: Z\n");
	ft_putchar_fd('Z', 1);
	ft_putchar_fd('\n', 1);
	return (0);
}
```

---

### ft_putstr_fd

**Archivo:** `ft_putstr_fd.c`

**¿Qué hace?**  
Escribe una cadena completa en el descriptor de archivo especificado.

**¿Cómo funciona el código?**

```c
void ft_putstr_fd(char *s, int fd)
{
    if (!s)
        return;
    while (*s)
    {
        write(fd, s, 1);
        s++;
    }
}
```

- Verifica que `s` no sea NULL
- Recorre la cadena carácter por carácter
- Escribe cada carácter usando `write()`
- Alternativa más eficiente sería escribir toda la cadena de una vez

**Ejemplo:**

```c
#include <stdio.h>

int	main(void)
{
	printf("Salida esperada: hola\n");
	ft_putstr_fd("hola", 1);
	ft_putchar_fd('\n', 1);
	return (0);
}
```

---

### ft_putendl_fd

**Archivo:** `ft_putendl_fd.c`

**¿Qué hace?**  
Escribe una cadena seguida de un salto de línea en el descriptor de archivo.

**¿Cómo funciona el código?**

```c
void ft_putendl_fd(char *s, int fd)
{
    if (!s)
        return;
    ft_putstr_fd(s, fd);
    ft_putchar_fd('\n', fd);
}
```

- Verifica que `s` no sea NULL
- Llama a `ft_putstr_fd` para escribir la cadena
- Luego llama a `ft_putchar_fd` para escribir '\n'

**Ejemplo:**

```c
#include <stdio.h>

int	main(void)
{
	printf("Salida esperada: linea\n");
	ft_putendl_fd("linea", 1);
	return (0);
}
```

---

### ft_putnbr_fd

**Archivo:** `ft_putnbr_fd.c`

**¿Qué hace?**  
Escribe un número entero en el descriptor de archivo.

**¿Cómo funciona el código?**

```c
void ft_putnbr_fd(int n, int fd)
{
    long nb;

    nb = (long)n;
    if (nb < 0)
    {
        ft_putchar_fd('-', fd);
        nb = -nb;
    }
    if (nb >= 10)
        ft_putnbr_fd((int)(nb / 10), fd);
    ft_putchar_fd((char)(nb % 10 + '0'), fd);
}
```

- Convierte a `long` para manejar INT_MIN correctamente
- Si es negativo, escribe '-' y convierte a positivo
- **Recursión**: Si el número tiene más de un dígito:
  - Llama recursivamente con `nb / 10` (dígitos superiores)
  - Escribe el último dígito con `nb % 10`
- Convierte dígito a char sumando '0'

**Ejemplo de traza recursiva para 12345:**

```
ft_putnbr_fd(12345, 1)
  → ft_putnbr_fd(1234, 1)
    → ft_putnbr_fd(123, 1)
      → ft_putnbr_fd(12, 1)
        → ft_putnbr_fd(1, 1)
          → escribe '1'
        → escribe '2'
      → escribe '3'
    → escribe '4'
  → escribe '5'
```

**Ejemplo:**

```c
#include <stdio.h>

int	main(void)
{
	printf("Salida esperada: -1234\n");
	ft_putnbr_fd(-1234, 1);
	ft_putchar_fd('\n', 1);
	return (0);
}
```

---

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}                   t_list;
```

### ft_lstnew

**Archivo:** `ft_lstnew.c`

**¿Qué hace?**  
Crea un nuevo nodo de lista.

**¿Cómo funciona el código?**

```c
t_list *ft_lstnew(void *content)
{
    t_list *new_node;

    new_node = (t_list *)malloc(sizeof(t_list));
    if (!new_node)
        return (NULL);
    new_node->content = content;
    new_node->next = NULL;
    return (new_node);
}
```

- Reserva memoria para un nodo `t_list`
- Si `malloc` falla, devuelve NULL
- Inicializa `content` con el valor pasado
- Inicializa `next` a NULL (será el último nodo por ahora)
- Devuelve el nuevo nodo

**Ejemplo:**

```c
#include <stdio.h>

int	main(void)
{
	t_list	*node;

	node = ft_lstnew("hola");
	if (!node)
		return (1);
	printf("content: %s\n", (char *)node->content);
	free(node);
	return (0);
}
```

---

### ft_lstadd_front

**Archivo:** `ft_lstadd_front.c`

**¿Qué hace?**  
Añade un nodo al principio de la lista.

**¿Cómo funciona el código?**

```c
void ft_lstadd_front(t_list **lst, t_list *new)
{
    if (!lst || !new)
        return;
    new->next = *lst;
    *lst = new;
}
```

- Verifica que `lst` y `new` no sean NULL
- Hace que `new->next` apunte al antiguo primer nodo (`*lst`)
- Actualiza `*lst` para que apunte a `new` (ahora es el primero)

**Visualización:**

```
Antes:  lst → [A] → [B] → NULL
        new → [C]

Después: lst → [C] → [A] → [B] → NULL
```

**Ejemplo:**

```c
#include <stdio.h>

int	main(void)
{
	t_list	*lst;
	t_list	*new;

	lst = ft_lstnew("mundo");
	new = ft_lstnew("hola");
	ft_lstadd_front(&lst, new);
	printf("primero: %s\n", (char *)lst->content);
	free(new);
	free(lst);
	return (0);
}
```

---

### ft_lstadd_back

**Archivo:** `ft_lstadd_back.c`

**¿Qué hace?**  
Añade un nodo al final de la lista.

**¿Cómo funciona el código?**

```c
void ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list *last;

    if (!lst || !new)
        return;
    if (!*lst)
    {
        *lst = new;
        return;
    }
    last = ft_lstlast(*lst);
    last->next = new;
}
```

- Verifica que `lst` y `new` no sean NULL
- **Caso especial**: Si la lista está vacía (`*lst == NULL`), `new` se convierte en el primer nodo
- Si no, usa `ft_lstlast` para encontrar el último nodo
- Hace que el `next` del último nodo apunte a `new`

**Visualización:**

```
Antes:  lst → [A] → [B] → NULL
        new → [C]

Después: lst → [A] → [B] → [C] → NULL
```

**Ejemplo:**

```c
#include <stdio.h>

int	main(void)
{
	t_list	*a;
	t_list	*b;

	a = ft_lstnew("a");
	b = ft_lstnew("b");
	ft_lstadd_back(&a, b);
	printf("last: %s\n", (char *)ft_lstlast(a)->content);
	free(b);
	free(a);
	return (0);
}
```

---

### ft_lstlast

**Archivo:** `ft_lstlast.c`

**¿Qué hace?**  
Devuelve el último nodo de la lista.

**¿Cómo funciona el código?**

```c
t_list *ft_lstlast(t_list *lst)
{
    if (!lst)
        return (NULL);
    while (lst->next)
        lst = lst->next;
    return (lst);
}
```

- Si la lista está vacía, devuelve NULL
- Recorre la lista siguiendo los punteros `next`
- Se detiene cuando encuentra un nodo cuyo `next` es NULL
- Devuelve ese último nodo

**Ejemplo:**

```c
#include <stdio.h>

int	main(void)
{
	t_list	*a;
	t_list	*b;

	a = ft_lstnew("a");
	b = ft_lstnew("b");
	a->next = b;
	printf("last: %s\n", (char *)ft_lstlast(a)->content);
	free(b);
	free(a);
	return (0);
}
```

---

### ft_lstsize

**Archivo:** `ft_lstsize.c`

**¿Qué hace?**  
Cuenta el número de nodos en la lista.

**¿Cómo funciona el código?**

```c
int ft_lstsize(t_list *lst)
{
    int count;

    count = 0;
    while (lst)
    {
        count++;
        lst = lst->next;
    }
    return (count);
}
```

- Inicializa un contador en 0
- Recorre la lista siguiendo los punteros `next`
- Incrementa el contador por cada nodo
- Devuelve el total

**Ejemplo:**

```c
#include <stdio.h>

int	main(void)
{
	t_list	*a;
	t_list	*b;

	a = ft_lstnew("a");
	b = ft_lstnew("b");
	a->next = b;
	printf("size: %d\n", ft_lstsize(a));
	free(b);
	free(a);
	return (0);
}
```

---

### ft_lstdelone

**Archivo:** `ft_lstdelone.c`

**¿Qué hace?**  
Elimina un solo nodo, liberando su contenido y el nodo mismo.

**¿Cómo funciona el código?**

```c
void ft_lstdelone(t_list *lst, void (*del)(void *))
{
    if (!lst || !del)
        return;
    del(lst->content);
    free(lst);
}
```

- Verifica que `lst` y `del` no sean NULL
- Llama a la función `del` para liberar el contenido del nodo
  - `del` es una función que sabe cómo liberar el tipo de contenido específico
- Libera el nodo mismo con `free`
- **Importante**: NO actualiza punteros de otros nodos

**Ejemplo:**

```c
void delete_content(void *content)
{
    free(content);
}
t_list *nodo = ft_lstnew(malloc(sizeof(int)));
ft_lstdelone(nodo, delete_content);
```

---

### ft_lstclear

**Archivo:** `ft_lstclear.c`

**¿Qué hace?**  
Elimina y libera toda la lista.

**¿Cómo funciona el código?**

```c
void ft_lstclear(t_list **lst, void (*del)(void *))
{
    t_list *temp;

    if (!lst || !del)
        return;
    while (*lst)
    {
        temp = (*lst)->next;  // Guarda el siguiente
        ft_lstdelone(*lst, del);  // Elimina el actual
        *lst = temp;  // Avanza al siguiente
    }
    *lst = NULL;
}
```

- Verifica que `lst` y `del` no sean NULL
- Recorre la lista:
  - Guarda el puntero al siguiente nodo en `temp`
  - Elimina el nodo actual con `ft_lstdelone`
  - Avanza al siguiente nodo
- Al final, pone `*lst` en NULL (lista vacía)

**Visualización:**

```
Inicial: lst → [A] → [B] → [C] → NULL

Iteración 1: temp = [B], elimina [A], lst = [B]
Iteración 2: temp = [C], elimina [B], lst = [C]
Iteración 3: temp = NULL, elimina [C], lst = NULL

Final: lst → NULL
```

**Ejemplo:**

```c
#include <stdio.h>

static void	del(void *p)
{
	free(p);
}

int	main(void)
{
	t_list	*a;
	t_list	*b;

	a = ft_lstnew(ft_strdup("a"));
	b = ft_lstnew(ft_strdup("b"));
	a->next = b;
	ft_lstclear(&a, del);
	printf("Lista limpia: %p\n", (void *)a);
	return (0);
}
```

---

### ft_lstiter

**Archivo:** `ft_lstiter.c`

**¿Qué hace?**  
Itera sobre la lista aplicando una función a cada contenido (sin modificar la estructura).

**¿Cómo funciona el código?**

```c
void ft_lstiter(t_list *lst, void (*f)(void *))
{
    if (!f)
        return;
    while (lst)
    {
        f(lst->content);
        lst = lst->next;
    }
}
```

- Verifica que `f` no sea NULL
- Recorre la lista
- Aplica la función `f` al contenido de cada nodo
- No modifica la estructura de la lista (punteros `next`)
- La función `f` puede modificar el contenido o solo usarlo

**Ejemplo:**

```c
#include <stdio.h>

static void	print_node(void *p)
{
	printf("%s\n", (char *)p);
}

int	main(void)
{
	t_list	*a;
	t_list	*b;

	a = ft_lstnew("uno");
	b = ft_lstnew("dos");
	a->next = b;
	ft_lstiter(a, print_node);
	free(b);
	free(a);
	return (0);
}
```

---

### ft_lstmap

**Archivo:** `ft_lstmap.c`

**¿Qué hace?**  
Crea una nueva lista aplicando una función de transformación a cada contenido de la lista original.

**¿Cómo funciona el código?**

```c
t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list *new_list;
    t_list *new_node;
    void   *content;

    if (!f || !del)
        return (NULL);
    new_list = NULL;
    while (lst)
    {
        content = f(lst->content);
        new_node = ft_lstnew(content);
        if (!new_node)
        {
            del(content);
            ft_lstclear(&new_list, del);
            return (NULL);
        }
        ft_lstadd_back(&new_list, new_node);
        lst = lst->next;
    }
    return (new_list);
}
```

- Verifica que `f` y `del` no sean NULL
- Recorre cada nodo de la lista original y transforma su contenido con `f`
- Crea un nodo nuevo con `ft_lstnew` y lo añade con `ft_lstadd_back`
- Si falla la creación de nodo:
    - Libera el contenido recién creado con `del`
    - Limpia la lista parcial con `ft_lstclear`
    - Devuelve NULL
- Devuelve la nueva lista completa

**Ejemplo:**

```c
void *duplicate_string(void *content)
{
    return (ft_strdup((char *)content));
}

void delete_string(void *content)
{
    free(content);
}

t_list *original = /* lista de strings */;
t_list *copia = ft_lstmap(original, duplicate_string, delete_string);
// copia es una nueva lista con copias de los strings
```

 ---


## Cómo crear un Makefile

Para que un `Makefile` funcione correctamente necesitas:

1. Un **objetivo principal** (en este caso `libft.a`).
2. Variables con herramientas y flags (`CC`, `CFLAGS`, `AR`, `ARFLAGS`).
3. La lista de fuentes (`SRCS`) y su transformación a objetos (`OBJS`).
4. Reglas con dependencias claras (`all`, `clean`, `fclean`, `re`).

Este Makefile está compuesto así:

- `NAME = libft.a`: nombre de la librería final.
- `CC = cc`: dsesigna el nombre del compilador de C que vamos a utilizar.
- `CFLAGS = -Wall -Wextra -Werror`: activa avisos y trata warnings como error.
- `AR = ar` y `ARFLAGS = rcs`: herramienta y flags para crear la librería estática.
- `SRCS = ...`: lista de todos los `.c` del proyecto.
- `OBJS = $(SRCS:.c=.o)`: convierte automáticamente cada `.c` en `.o`.
- `all: $(NAME)`: objetivo por defecto; al hacer `make`, construye `$(NAME)`.
- `$(NAME): $(OBJS)`: define que la librería depende de todos los objetos.
- `$(AR) $(ARFLAGS) $(NAME) $(OBJS)`: empaqueta los `.o` dentro de `libft.a`.
- `clean:` + `rm -f $(OBJS)`: borra solo archivos objeto.
- `fclean: clean` + `rm -f $(NAME)`: borra objetos y librería.
- `re: fclean all`: reconstrucción completa desde cero.
- `.PHONY: all clean fclean re`: exclusión explícita de archivos que contengan esos nombres para evitar conflictos con los comandos del Makefile.

---

## Conceptos Clave

### 1. **Protección contra NULL**

Casi todas las funciones verifican punteros NULL antes de usarlos para evitar segfault.

### 2. **Protección contra overflow**

Las funciones `ft_itoa` y `ft_putnbr_fd` convierten `int` a `long` para evitar int overflow.

`ft_calloc` verifica que `count * size` no desborde antes de hacer malloc.

### 3.  **Casting a unsigned char**

En funciones de comparación (`memcmp`, `strncmp`) se usa unsigned char para comparaciones correctas de bytes.

### 4.  **Liberar toda la memoria asignada dinámicamente**

Cada malloc/calloc debe ir acompañado al final por su correspondiente free() para evitar leaks de memoria. Se puede comprobar usando **valgrind.**

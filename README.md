*This project has been created as part of the 42 curriculum by scamlett and lupalomi*

# push_swap

## Description section that clearly presents the project, including its goal and a brief overview.

## Instructions section containing any relevant information about compilation, installation, and/or execution.

## Resources section listing classic references related to the topic (documentation, articles, tutorials, etc.), as well as a description of how AI was used specifying for which tasks and which parts of the project.

## A detailed explanation and justification of the algorithms selected for this project must also be included.

Susana 04/05 = 
- creo esqueleto de archivos
- implemento función grado de desorden de array
- creo struct de nodo

Susana 05/05 = 
- añado libft para poder usar ft_printf
- reimplemento lstlast de libft en utils.c para poder usarlo en nuestro struct de nodo. Se tiene que reimplementar porque libft usa void * content, y nuestro nodo usa int value.
- implemento funciones swap, push, rotate y reverse

Luis 07/05 - 10/05 =
- Implementación de funciones estáticas en el archivo 'push_swap.c': Creación e inicialización de pilas de números.
- Implementación de la función 'ft_strcmp' que compara dos cadenas de texto completamente.
- Manejo de flags dentro de la variable t_stack
- Manejo de errores dentro de la entrada: Actualmente, se permite el uso de dos flags de estrategia, aplicandose únicamente la última puesta (Esto lo debemos hablar porque se puede manejar como error, aunque no parece que sea obligatorio).
- Liberación de recursos al cerrar el programa

Luis 13/05 =
- Implementación de un nuevo parser: Ahora se aceptan y gestionan correctamente cadenas de números en un mismo string y números separados, PERO NO UNA COMBINACIÓN DE AMBOS (El ejercicio tampoco dice nada al respecto).

Luis 14/05 =
- Implementación del algoritmo simple minimun extraction: Consiste en buscar el minimo y ordenar la lista de manera inversa en el stack b. Al hacer esto, haciendo recursivamente push B, logramos conseguir la lista ordenada. Solo funciona con la flag --simple o si el disorder es de 0,20 (20%)
- Corrección de las funciones de movimientos. Todas usaban los nodos como referencia en lugar de los propios stacks.
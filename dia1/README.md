# **DIA 1**

## *PARTE 1*
Primero separamos los números de la izquierda y los de la izquierda en dos vectores de string. A continuación, los ordenamos con la función sort. Mediante un bucle for conseguimos sacar las diferencias entre las distancias más pequeñas y las distancias más grandes. 

Este código para dos de nosotros fue la primera vez que hicimos un CodeOfAdvent y nos gustó el cómo te hacen pensar estos problemas y nos hacen pensar en métodos aplicados en mayor medida a algo que puede ser la vida laboral. Varios de nosotros empezamos a comprender mejor cómo programar este tipo de ejercicios.

Para compilar, descargar el input en un archivo (input.in), compilar mediante "g++ -o dia1 dia1parte1", y seguidamente "./dia1 < input.in".

## *PARTE 2*
Utilizamos el mismo sistema que en la parte pero dentro de este usamos otro bucle for para comparar los dos valores de nuestros vectores de int. Cuando el nº de la izquierda era igual al de la derecha sumamos uno al contador de nº de veces que se repite el número en la columna de la derecha. Cuando ya ha acabado con ese número multiplicamos el valor de la columna de la izquierda con el nº de veces que se repite en la columna de la derecha y se mira el siguiente número.

Para compilar, descargar el input en un archivo (input.in), compilar mediante "g++ -o dia1 dia1parte2", y seguidamente "./dia1 < input.in".

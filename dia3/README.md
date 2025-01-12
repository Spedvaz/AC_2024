# **DIA 3**
Para este día utilizamos la librería regex que nos recomendaste 

## *PARTE 1*

En el main tomamos las lineas del input y lo introducimos en un vector de string. Luego definimos el patrón para identificar cuando multiplicar. 
Extraemos los números que hay entre medias de mul(' ', ' ') y los multiplicamos entre ellos para conseguir el resultado del problema

## *PARTE 2*

Para la segunda parte vimos que el primer código era muy lioso. Entonces registramos los 3 patrones, mul, do y don't, y finalmente uno que englobase todo. Si el match coincide y el bool está en true con el patrón de multiplicar los multiplica y los añade al total. En caso de coincidir con el patrón de do activa el bool a true y si es el de don't descativa el bool a false.

Este día nos pareció bastante interesante, ya que la librería regex era algo que realmente nunca habíamos usado ni escuchado nada al respecto. Hemos visto, que es una herramienta bastante útil para inputs en el que necesites buscar un patrón específico. Al recomendarnos está librería nos informamos sobre las funciones de search, iterator, match que iban a ser las que más nos iban a ayudar.

Para compilar la parte nº 2, descargar el input en un archivo (input.in), compilar mediante "g++ -o dia2 dia2parte2.cpp", y seguidamente "./dia3parte2 < input.in".

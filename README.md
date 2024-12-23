# AC_2024
DIA 1 <br>
DIA 2 
  <br>
En la parte 1, lo sacamos mediante un árbol, en el que usamos nuestro BSTree creado en las prácticas. Introducimos cada línea a comparar en el árbol. Luego ya dentro del árbol introducido, miramos dependiendo si es orden creciente o decreciente, si el número es mayor o menor por más de 3 unidades, en caso de ser así devolvemos directamente que es unsafe, sino volvemos a llamar a la función con el root de la derecha o izquierda dependiendo cuál estuviese ocupado.
  <br>
DIA 3
DIA 4
DIA 5 
<br>
DIA 6
<br>
En este caso utilazamos un mapa de char, en el que obtenemos el input con una función que lee el mapa. Luego aplicamos un método recursivo, mediante el cuál hace los movimientos en las 4 direcciones hasta que llegue a un "#" que sería un obstáculo o cuando se saldría     del mapa que nos devolvería los movimientos que ha necesitado hasta salirse pasando por posiciones distintas. Esto lo conseguimos añadiendo cada vez que pisase un zona que no estuviese marcada por "X" que lo cambiase por este mismo carácter. El código simplemente   consigue el   mapa y repite los 4 movimientos en distintas direcciones girando hacia la derecha recursiva hasta que se sale del mapa.

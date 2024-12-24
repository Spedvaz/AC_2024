# AC_2024
DIA 1 
<br>
<br><br>
DIA 2 
  <br>
En la parte 1, lo sacamos mediante un árbol, en el que usamos nuestro BSTree creado en las prácticas. Introducimos cada línea a comparar en el árbol. Luego ya dentro del árbol introducido, miramos dependiendo si es orden creciente o decreciente, si el número es mayor o menor por más de 3 unidades, en caso de ser así devolvemos directamente que es unsafe, sino volvemos a llamar a la función con el root de la derecha o izquierda dependiendo cuál estuviese ocupado.
  <br><br>
DIA 3
<br>
a
<br><br>
DIA 4
<br>
a
<br><br>
DIA 5 
<br>
Hemos resuelto la primera parte con grafos. Para la estructura del grafo, usamos unordered_map de un int con un vector de ints. Con cada linea de la primera parte del input, el primer numero es la clave y el segundo se mete en el vector. Despues, a la hora de comparar, se verifica que la clave exista, y despues de obtiene el vector asociado a ese valor y se verifica que todos los numeros que vienen despues se encuentren en este vector.
<br><br>
DIA 6
<br>
En este caso utilazamos un mapa de char, en el que obtenemos el input con una función que lee el mapa. Luego aplicamos un método recursivo, mediante el cuál hace los movimientos en las 4 direcciones hasta que llegue a un "#" que sería un obstáculo o cuando se saldría     del mapa que nos devolvería los movimientos que ha necesitado hasta salirse pasando por posiciones distintas. Esto lo conseguimos añadiendo cada vez que pisase un zona que no estuviese marcada por "X" que lo cambiase por este mismo carácter. El código simplemente   consigue el   mapa y repite los 4 movimientos en distintas direcciones girando hacia la derecha recursiva hasta que se sale del mapa.
<br><br>

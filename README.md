# AC_2024
DIA 1 
<br>
<br><br>
DIA 2 
  <br>
  En la parte 1, usamos la estructura del árbol BSTREE que hicimos en las prácticas. Introducimos cada línea a comparar en el árbol. Dentro del árbol, comprobamos si el orden es creciente o decreciente y seguidamente si el siguiente número es mayor/menor por más de 3 unidades. En caso de ser así devolvemos que es unsafe. Sino, volvemos a llamar a la función con el root de la derecha o izqierda dependiendo cuál estuviese ocupado. 
Usamos esta estructura en este problema ya que no nos parecio complicado ni descabellado implementarlo, aunque luego nos surgieron problemas con la parte 2 y tuvimos que rehacerlo de una manera más óptima, por lo tanto tenemos dos soluciones válidas. Aprendimos a utilizar el trabajo realizado en clase, a entender mejor los arboles y cuando no es necesario usarlos. 
Como conclusión, si tuviesemos que volver a hacerlo, no forzariamos tanto usar una estructura solo para "quitarnosla de encima", porque aunque el problema incial planteado si que se podia resolver asi, nos dimos cuenta de que no era una solución muy generalizada ya que no pudimos sacar la segunda parte de esta manera. 
  <br><br>
DIA 3
<br>
Hemos usado la librería regex
<br>
La segunda parte vimos que el primer código era muy lioso para poder hacer la segunda parte. Entonces registramos los 3 patrones, mul, do y don't, finlamente uno que englobase todo. Si el match coincide y el bool está en true con el patrón de multiplicar los multiplica y los añade al total. En caso de coincidir con el patrón de do activa el bool a true y si es el de don't descativa el bool a false.
<br><br>
DIA 4
<br>
a
<br><br>
DIA 5 
<br>
Resolvimos sin muchas complicaciones el problema el dia que salio, aprendiendo que existian los "pairs". Nos parecia una solución buena, pero como no teniamos muchos y veiamos que el nivel se complicaba y no ibamos a saber hacer muchos mas, decidimos hacer otra solución y la implementamos con grafos. El funcionamiento es el mismo en los dos codigos, solo cambia la estructura y la manera de leer el input. Para poder resolverlo con grafos, aprendimos a usar la libreria de unordered_map con videos de youtube. Luego tenemos una función que verifica si el orden propuesto es válido. No conseguimos reducir el tiempo necesario ya que en las dos soluciones tenemos una complejidad de tiempo similar ya que recorremos dos bucles del tamaño del input. Nos hubiese gustado reducir la complejidad con los grafos pero no hemos sido capaces. 
Nuestra solución es sencilla, ir recorriendo el vector e ir comprobando que el para cada número, los siguientes estan en su grafo. Utilizamos copias para no usar memoria innecesaria. En caso de que no este, la función tiene un bool que pone a false y más tarde hace un return. 
Como conclusión, estamos un poco defraudados ya que solo hemos cambiado la estructura para hacerlo válido pero como tal no ha mejorado nada. Además, estuvimos un montón de tiempo la primera vez que lo hicimos y luego volver a ponernos para buscar otra solución con una estructura que nos sirviese para la entrega nos costo un poco. 
<br><br>
DIA 6
<br>
En este caso utilazamos un mapa de char, en el que obtenemos el input con una función que lee el mapa. Luego aplicamos un método recursivo, mediante el cuál hace los movimientos en las 4 direcciones hasta que llegue a un "#" que sería un obstáculo o cuando se saldría     del mapa que nos devolvería los movimientos que ha necesitado hasta salirse pasando por posiciones distintas. Esto lo conseguimos añadiendo cada vez que pisase un zona que no estuviese marcada por "X" que lo cambiase por este mismo carácter. El código simplemente   consigue el   mapa y repite los 4 movimientos en distintas direcciones girando hacia la derecha recursiva hasta que se sale del mapa.
<br><br>

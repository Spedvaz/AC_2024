# AC_2024
DIA 1 
<br>
<br><br>
DIA 2 
  <br>
  En la parte 1, usamos la estructura del árbol BSTREE que hicimos en las prácticas. Introducimos cada línea a comparar en el árbol. Dentro del árbol, comprobamos si el orden es creciente o decreciente y seguidamente si el siguiente número es mayor/menor por más de 3 unidades. En caso de ser así devolvemos que es unsafe. Sino, volvemos a llamar a la función con el root de la derecha o izquierda dependiendo cuál estuviese ocupado. 
Usamos esta estructura en este problema ya que no nos parecio complicado ni descabellado implementarlo, aunque luego nos surgieron problemas con la parte 2 y tuvimos que rehacerlo de una manera más óptima, por lo tanto tenemos dos soluciones válidas. Aprendimos a utilizar el trabajo realizado en clase, a entender mejor los arboles y cuando no es necesario usarlos. 
Como conclusión, si tuviesemos que volver a hacerlo, no forzariamos tanto usar una estructura solo para "quitarnosla de encima", porque aunque el problema incial planteado si que se podia resolver asi, nos dimos cuenta de que no era una solución muy generalizada ya que no pudimos sacar la segunda parte de esta manera. 
  <br><br>
DIA 3
<br>
Hemos usado la librería regex
<br>
Para la segunda parte vimos que el primer código era muy lioso. Entonces registramos los 3 patrones, mul, do y don't, finlamente uno que englobase todo. Si el match coincide y el bool está en true con el patrón de multiplicar los multiplica y los añade al total. En caso de coincidir con el patrón de do activa el bool a true y si es el de don't descativa el bool a false.
<br><br>
DIA 4
<br>
a
<br><br>
DIA 5 
<br>
Resolvimos sin muchas complicaciones el problema el dia que salio, aprendiendo que existian los "pairs", y usándolos. Nos parecía una solución buena y funcional, pero como no teníamos muchos problmeas resueltos mediante estructuras/técnicas y veiamos que el nivel se complicaba y no ibamos a saber hacer muchos mas, decidimos hacer otra solución y la implementamos con grafos. El funcionamiento es el mismo en los dos codigos, solo cambia la estructura y la manera de leer el input. Para poder resolverlo con grafos, aprendimos a usar la libreria de unordered_map con videos de youtube. Luego, implementamos una función que verifica si el orden propuesto dentro del grafo es válido. No conseguimos reducir el tiempo necesario ya que en las dos soluciones tenemos una complejidad de tiempo similar ya que recorremos dos bucles del tamaño del input. Nos hubiese gustado reducir la complejidad con los grafos pero no hemos sido capaces. 
Nuestra solución es sencilla, ir recorriendo el grafo e ir comprobando que para cada número, los siguientes estan en su grafo. Utilizamos copias para no usar memoria innecesaria. En caso de que no este, la función tiene un bool que pone a false y más tarde hace un return. 
Como conclusión, estamos un poco defraudados ya que solo hemos cambiado la estructura para hacerlo válido para la entrega pero como tal no ha mejorado nada. Además, estuvimos un montón de tiempo la primera vez que lo hicimos y luego volver a ponernos para buscar otra solución con una estructura que nos sirviese para la entrega nos costo un poco. 
<br><br>
DIA 6
<br>
Este fue el último problema que pudimos resolver por nuestra cuenta sin mirar soluciones para obtener ideas de como hacerlo.
En este caso utilazamos una matriz bidimensional de chars. Obtenemos el input con una función que lee el mapa y lo introduce en la matriz. Luego aplicamos un método recursivo, mediante el cuál hace los movimientos en las 4 direcciones hasta que llegue a un "#" que sería un obstáculo o cuando se salga del mapa. La función nos devuelve el número de movimientos que ha necesitado hasta que se ha salido pasando por posiciones distintas. Esto lo conseguimos añadiendo cada vez que pisase una posición de la matriz una "X", y en caso de que hubiese "X", no sumase un movimiento más. Consideramos que la solución és válida y te la explicamos en clase, pero, como te comentamos, a un miembro de nuestro grupo, con su input, la llamada recursiva le daba un desbordamiento del stack. Por ello, probamos a cambiar las llamadas recursivas por bucles, pero seguía sin obtener el resultado en dicho input. 
<br><br>

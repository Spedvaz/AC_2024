DIA 2 
  <br>
  En la parte 1, usamos la estructura del árbol BSTREE que hicimos en las prácticas. Introducimos cada línea a comparar en el árbol. Dentro del árbol, comprobamos si el orden es creciente o decreciente y seguidamente si el siguiente número es mayor/menor por más de 3 unidades. En caso de ser así devolvemos que es unsafe. Sino, volvemos a llamar a la función con el root de la derecha o izquierda dependiendo cuál estuviese ocupado. 
Usamos esta estructura en este problema ya que no nos parecio complicado ni descabellado implementarlo, aunque luego nos surgieron problemas con la parte 2 y tuvimos que rehacerlo de una manera más óptima, por lo tanto tenemos dos soluciones válidas. Aprendimos a utilizar el trabajo realizado en clase, a entender mejor los arboles y cuando no es necesario usarlos. 
Como conclusión, si tuviesemos que volver a hacerlo, no forzariamos tanto usar una estructura solo para "quitarnosla de encima", porque aunque el problema incial planteado si que se podia resolver asi, nos dimos cuenta de que no era una solución muy generalizada ya que no pudimos sacar la segunda parte de esta manera. 
  <br>
Para compilar, descargar el input en un archivo (input.in), compilar mediante "g++ -o dia2 dia2parte1.cpp", y seguidamente "./dia2 < input.in".

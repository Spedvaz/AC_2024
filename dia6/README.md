# **DIA 6**
<br>
Este fue el último problema que pudimos resolver por nuestra cuenta sin mirar soluciones para obtener ideas de como hacerlo.
En este caso utilazamos una matriz bidimensional de chars. Obtenemos el input con una función que lee el mapa y lo introduce en la matriz. Luego aplicamos un método recursivo, mediante el cuál hace los movimientos en las 4 direcciones hasta que llegue a un "#" que sería un obstáculo o cuando se salga del mapa. La función nos devuelve el número de movimientos que ha necesitado hasta que se ha salido pasando por posiciones distintas. Esto lo conseguimos añadiendo cada vez que pisase una posición de la matriz una "X", y en caso de que hubiese "X", no sumase un movimiento más. Consideramos que la solución és válida y te la explicamos en clase, pero, como te comentamos, a un miembro de nuestro grupo, con su input, la llamada recursiva le daba un desbordamiento del stack. Por ello, probamos a cambiar las llamadas recursivas por bucles, pero seguía sin obtener el resultado en dicho input. 
<br><br>
Para compilar, descargar el input en un archivo (input.in), compilar mediante "g++ -o dia6 dia6parte1.cpp", y seguidamente "./dia6 < input.in".

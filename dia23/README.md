# **DIA 23**
<br><br>
Después de haber estudiado para el examen de PRA, se me ha ocurrido echarle un vistazo a los últimos y hemos visto que este era muy similar al ejercicio del examen de ejemplo de los enlaces con aviones, por
lo tanto he decidido hacerlo con grafos. 
Primero, como es bidireccional, inserto el enlace en los dos grafos. Es decir, para a-b, inserto a en el grafo de b y viceversa. Más tarde he tenido problemas porque no estaba verificando cuales habia visitado 
ya y los estaba contando repetidos.
<br><br>
Luego, en la función de comprobar_vecinos, tengo un triple bucle que, para cada nodo, considerando cada vecino como nodo, para cada vecino2, busca la conexión nodo-vecino2 (que es la única sin verificar aún), 
los ordena para evitar contar repetidas veces y marca ese ciclo como visitado en el grafo ciclosContados. Se verifica que uno de ellos tenga la "t" que requiere el problema (también he tenido problema con esto
ya que pensaba que también podía ser la segunda "t" y estaba verificando de esta manera: nodo.find('t') != string::npos), y en caso de que la tenga, se suma 1 al total. 
<br><br>
Este problema nos ha gustado porque he aprendido lo usado en clase, y no pensaba que ibamos a poder sacar uno tan alto. Ha sido reconfortante saber que algo estamos aprendiendo. 
<br><br>
Para compilar, descargar el input en un archivo (input.in), compilar mediante "g++ -o dia23 dia23parte1_grafos.cpp", y seguidamente "./dia25 < input.in".
<br><br>

DIA 23
<br>
Después de haber estudiado para el examen de PRA, se me ha ocurrido echarle un vistazo a los últimos y hemos visto que este era muy similar al ejercicio del examen de ejemplo de los enlaces con aviones, por
lo tanto he decidido hacerlo con grafos. 
Primero, como es bidireccional, inserto el enlace en los dos grafos. Es decir, para a-b, inserto a en el grafo de b y viceversa. Más tarde he tenido problemas porque no estaba verificando cuales habia visitado 
ya y los estaba contando repetidos.
Luego, en la función de comprobar_vecinos, tengo un triple bucle que, para cada nodo, considerando cada vecino como nodo, para cada vecino2, busca la conexión nodo-vecino2 (que es la única sin verificar aún), 
los ordena para evitar contar repetidas veces y marca ese ciclo como visitado en el grafo ciclosContados. Se verifica que uno de ellos tenga la "t" que requiere el problema (también he tenido problema con esto
ya que pensaba que también podía ser la segunda "t" y estaba verificando de esta manera: nodo.find('t') != string::npos), y en caso de que la tenga, se suma 1 al total. 
<br>
Este problema me ha gustado porque he aprendido lo usado en clase, y no pensaba que iba a poder sacar uno tan alto. Ha sido reconfortante saber que algo estoy aprendiendo. 
<br>
Para compilar, 
<br><br>

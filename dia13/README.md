DIA 13
<br>
Vimos que podiamos resolver esta facilmente con recursividad (aunque sin mejorar la eficiendcia del codigo). Lo resolvimos rapido pero tuvimos muchisimos problemas con el input, ya que no sabiamos como 
extraerlo. Las lineas vacias tambien fueron un problema porque intentamos usar la funcion if(!input.empty()){ejecutar codigo} y no iba bien.
<br><b>
El código se basa en mantener a lo mas pequeño posible e ir probando en la ecuacion con todos los valores de b (de menor a mayor) para ver si se consigue los resultados esperados. En caso de que sea así, se devuelve el valor b y el
a lo tenemos pasado por referencia.  Sumamos al total el número de créditos que nos ha costado (3 por cada ticket de A y 1 por cada ticket de B), a un valor que se le ha pasado por referencia a la funcion de get_input().
<br>
La funcion de ecuacion simplemente es comprobar que ax*a + bx*b == tx y que ay*a + by*b == ty
son ciertas en un rango del 0 al 100 en la b con el valor mas bajo posible de a, menor a 101 (hasta 100).
Es un poco chapuza hacerlo todo a la vez pero no queria tener que almacenarme todo el input, para luego ponerme a calcuilar, y he preferido hacerlo sobre la marcha.
<br><br>
En conclusión, uno de los problemas que mas me ha gustado, por el input y por la parte de la ecuacion, que hacia tiempo que no pensaba en ellas ni hacia ninguna.
<br><br>
Para compilar. descargar el input en el archivo input.in y compilar el código mediante "g++ dia13parte1.cpp" y a continuacion, "./a.out < input.in"
<br><br>

# proyecto-micro
Configuración inicial:
Se establece la comunicación serial a 9600 baudios.
Se inicializan los sensores y el servo motor.
Se configura el LCD para mostrar la temperatura, humedad y luz.
Se establecen los pines de entrada y salida para el fotoresistor y el LED, respectivamente.
Bucle principal (loop):
Se espera un tiempo de 2 segundos antes de realizar las mediciones nuevamente.
Se leen los valores de temperatura y humedad utilizando el sensor DHT11.
Se lee la intensidad de luz a través del fotoresistor.
Se verifica si las lecturas son válidas (si no son NaN, es decir, no son valores inválidos).
Se muestran los valores de temperatura, humedad y luz en el LCD y se imprimen por el puerto serial para fines de depuración.
Se controla la velocidad del ventilador en base a la temperatura:
Si la temperatura es mayor o igual al umbral alto, se establece la velocidad del ventilador al máximo (255).
Si la temperatura está entre el umbral bajo y el umbral alto, se establece la velocidad del ventilador a la mitad de su capacidad (127).
Si la temperatura es menor que el umbral bajo, se apaga el ventilador (0).
Se controla el servo motor para abrir o cerrar la ventana según la temperatura:
Si la temperatura es mayor o igual al umbral alto, se abre la ventana (posición 180 grados).
Si la temperatura está entre el umbral bajo y el umbral alto, se cierra la ventana (posición 90 grados).
Si las lecturas no son válidas, se muestra un mensaje de error en el LCD y se imprime un mensaje por el puerto serial.
Se controla la intensidad del LED en función de la lectura del fotoresistor:
Si la intensidad de luz es mayor que 380, se apaga el LED.
Si la intensidad de luz es menor o igual a 380, se ajusta la intensidad del LED según el valor leído del fotoresistor.






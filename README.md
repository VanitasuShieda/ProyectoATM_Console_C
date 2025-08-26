# ProyectoATM_Console_C
Requerimientos: 
1. Buena presentación en pantalla del sistema. 
2. Uso de color, sonido, gotoxy 
3. Uso de funciones en cualquiera de sus 4 combinaciones, que les ayuden a estructurar el sistema. 
4. Presentar los menús del sistema con estilo y presentar algún marco en pantalla que simule el 
cajero automático. 
Entrega del proyecto: 
1. El código fuente del proyecto se entrega en un CD, etiquetado con EXCELENTE PRESENTACION y 
datos de integrantes del equipo, materia, profesor, fecha, nombre del sistema 
Revisión del proyecto  
1. El proyecto será revisado conforme a los requerimientos de este documento.  
2. La revisión del proyecto se realiza por equipo previa calendarización que les daré a conocer. Es 
necesaria la presencia de todos los integrantes del equipo, si algún miembro del equipo no se 
presenta tiene CERO en el proyecto final.   
MENU PRINCIPAL 
1. Modo administrador 
2. Modo cliente 
3. Salir 
Para entrar el modo administrador debes capturar ANTES una contraseña que solo el administrador 
conoce, para esa captura debe verse un * por cada carácter capturado. Si la contraseña es correcta 
muestra el menú Modo Administrador, si no es correcta muestra de nuevo el menú principal. 
Menú Modo Administrador 
1. Inicializar arreglos (cuentas, password, saldo y nombre para 10 clientes)  
2. Reporte de clientes  
3. Inicializar contadores de billetes de cada denominación 
4. Reporte de cuantos billetes hay por denominación 
5. Mostrar saldo del cajero 
6. Regreso al menú principal 
Explicación de las opciones de Modo Administrador 
1. Inicializar arreglos (cuentas, password, saldo y nombre para 10 clientes)  
En esta opción NO VAS a capturar la información de los arreglos, en su lugar utiliza inicialización 
manual, es decir asignando directamente los datos, trabaja una función CASO 3 (recibe los 
arreglos) para este proceso. 
2. Reporte de clientes  
En formato tabular imprime los datos de todos los clientes, el reporte debe incluir un 
encabezado    que indique nombre, cuenta, password y saldo. 
3. Inicializar contadores de billetes de cada denominación 
El cajero tiene billetes de $50, $100, $200 y $500 captura la cantidad de billetes con los que 
inicia el cajero cada denominación.  Estos contadores los vas a declarar de manera global Y 
junto con el saldo del cajero SERA LO UNICO GLOBAL permitido en el sistema. 
El saldo del cajero se obtiene a partir de la suma de las MULTIPLICACIONES de la cantidad de 
billetes de cada denominación. 
4. Reporte de cuantos billetes hay por denominación 
Imprimir cada uno de los contadores de billetes de las diferentes denominaciones 
5. Mostrar saldo del cajero 
Imprime el sado del cajero hasta el momento. 
Menú Modo Cliente 
Para entrar al modo cliente debes capturar ANTES una cuenta y contraseña que debes validar contra la 
información que tienes en los arreglos. Para la captura del password debes considerar las siguientes 
validaciones. 
a) Durante la captura del password debe verse en pantalla un * por cada carácter que teclees. 
b) El password debe tener una longitud EXACTA de 6 caracteres. 
c) Se tienen 3 oportunidades para teclear el password correctamente.   
d) Considera todas las situaciones en las que pudieras imprimir estos mensajes. 
“La cuenta no existe” 
“La cuenta existe, pero password incorrecto” 
“Error el password tiene una longitud diferente de 6 caracteres” o “error en el password” 
“Bienvenido (nombre del cliente) al Sistema” 
“Agotaste los tres intentos para ingresar al sistema.” 
Una vez ingresando al sistema presentar en pantalla el nombre del cliente, su saldo y el siguiente menú:  
Menu: Modo cliente 
1. Retirar   
2. Depositar 
3. Cambiar password 
4. Salir 
Explicación de las opciones de Modo Cliente 
1. Retirar. Solicitar una cantidad a retirar, la cual debe VALIDAR lo siguiente: 
Que sea múltiplo de la denominación del billete más chico que hasta el momento tenga el cajero, no 
exceda los 4000 pesos, que existan suficientes fondos en la cuenta y que el cajero tenga suficiente dinero 
para permitir el retiro. Mensajes a considerar: 
“cantidad a retirar invalida”, o porque se pasó del límite superior o está por debajo del limite inferior. 
“Tu cuenta no tiene el saldo suficiente para el retiro” 
“Lo sentimos por el momento el cajero no tienen fondos. Regrese más tarde.” 
Si el retiro pasa todas las validaciones imprimir en pantalla cuantos billetes de cada denominación entrega 
el cajero, proceder a disminuir contadores de billetes, actualizar saldo del cajero y a restar del saldo del 
cliente la cantidad retirada. 
SE PIDE LA VALIDACION CON RESPECTO A LOS CONTADORES DE BILLETES, es decir antes de entregar los 
billetes de cada denominación, valida los contadores para revisar si quedan los suficientes, de no ser así 
tienes que considerar un proceso para dar esa cantidad con otro tipo de denominación. 
Si la cantidad a retirar no cumple alguna de las validaciones volver a presentar el menú.  
Menu: Modo cliente 
1. Retirar   
2. Depositar 
3. Cambiar password 
4. Regresar al menú principal 
2. Depositar. Pedir la cantidad a depositar. Imprimir el nombre del cliente su saldo anterior y su 
saldo actualizado y volver a presentar el menú   
Menú: Modo cliente 
1. Retirar   
2. Depositar 
3. Cambiar password 
4. Regresar al menú principal 
3. Cambiar pasword: El nuevo password debe cumplir los siguientes requisitos 
 Tener una longitud EXACTA de 6 caracteres 
 Iniciar con alguna letra mayúscula o minúscula 
 A partir del segundo carácter puede ser otra letra o carácter o _  o digito 
 Debe tener al menos UN digito (0,1,2,3,4,5,6,7,8,9) 
Si no cumplen todas las validaciones INDICARLE al cliente en que se equivocó y volver a preguntar el 
nuevo password hasta que lo ingrese correctamente. 
Considerar los posibles mensajes de error. 
“No cumples con la longitud son 6 caracteres” 
“No inicias con una letra” 
“No cumples con tener al menos 1 digito” 
“El password contiene caracteres inválidos, solo se autorizan letras, dígitos y _  “

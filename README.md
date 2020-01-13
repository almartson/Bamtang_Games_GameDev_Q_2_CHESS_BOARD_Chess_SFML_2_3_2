# Bamtang_Games_GameDev_Q_2_CHESS_BOARD_Chess_SFML_2_3_2
Bamtang Games Game Dev Exam Answer to: Question #2 (CHESS BOARD)

## Question number 2.
## 2. CHESS BOARD

[Spanish original Question:]

###### Implementar una función que dibuje un tablero de ajedrez con la posición de las piezas pasada como parámetro.

El parámetro a pasar será una cadena compuesta solamente de los siguientes caracteres:
p, r, b, n, q, k, /, 1, 2, 3, 4, 5, 6, 7, 8

Donde cada pieza es representada por una carácter, siendo las negras caracteres en minúscula y las blancas caracteres en mayúsculas. 
Los caracteres son:
p = peón
r = torre
b = alfil
n = caballo
q = reina
k = rey

Para separar las filas dentro de la cadena se emplea el carácter "/", existen exactamente 8 filas en la cadena.
Para indicar espacios vacíos en la fila se colocan los números del 1 al 8.
Por ejemplo la fila "4p3" esta compuesta por 4 celdas vacías, un peón y finalmente tres celdas vacías.
El numero de celdas por fila debe ser siempre 8.

##### Así por ejemplo la posición inicial de ajedrez se representa por:
##### "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR"

#### Implementar la función: drawChessBoard( initPosition )

### NOTAS:

* Usa cualquier imagen para las piezas así como la librería gráfica que prefieras, pero debes cargar y mostrar imágenes BMP, PNG o JPG en tu programa.
* No se considerará válidas soluciones que sólo usen la consola de texto.
* Verifica que las imágenes estén ubicadas correctamente para que no hayan problemas al ejecutar tu proyecto.

<p align="center">
   
   <img src="ReadmeImgs/ChessBoard_1_1.png?raw=true">
   
   <font size="2">
      <p align="center">
         <figcaption"> Chess Board with Input: 7q/2rP4/2Pn4/P2RP3/p2n4/b1K5/2pPrQ2/3k2N1
         </figcaption>
      </p>
   </font>
</p>

*******************************************************************************
Source Code By:	 Alejandro E. Almarza Martín
*******************************************************************************

## Requirements: 

### A)	For Executing the program:

1-	Download 'SFML-2.3.2 - 32 bit' for Visual Studio C++ 2010, from:	https://www.sfml-dev.org/files/SFML-2.3.2-windows-vc10-32-bit.zip
(Main Download Page: https://www.sfml-dev.org/download/sfml/2.3.2/ )
   
2-	Copy the '...\bin''s Folder content.

3-	Paste it in the same Folder as this Code's Executable (.exe).

4-	Have all images in the same Folder as in step (3).


### B)	For Developing (Windows 7, VS C++ 2010):

1-	Install & Configure Visual Studio C++ 2010.
   
2-	Follow Step (A - (1)): Download 'SFML-2.3.2 - 32 bit' for Visual Studio C++ 2010:  https://www.sfml-dev.org/download/sfml/2.3.2/

3-	Configure Visual Studio C++ 2010 to Develop C++ Games using SFML >= 2.0 (Read: (Steps in:  https://www.sfml-dev.org/tutorials/2.3/start-vc.php ) )

2-	Copy this Script Contents inside the Project.

3-	Decide: [Dynamic Linked Libraries (DLL) vs. Static/Shared Libraries], and set the IDE Configuration. (Steps in:  https://www.sfml-dev.org/tutorials/2.3/start-vc.php )

4-	Happy Coding.

*******************************************************************************
Source Code By:	 Alejandro E. Almarza Martín
*******************************************************************************
### (5 PUNTOS)

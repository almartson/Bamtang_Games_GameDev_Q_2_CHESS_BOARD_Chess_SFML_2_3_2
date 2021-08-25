# Bamtang_Games_GameDev_Q_2_CHESS_BOARD_Chess_SFML_2_3_2
Simple C++ algorithm that draws a chess board with the position of the pieces passed as function parameters - My Answer to the Bamtang Games' [Game Programmer Exam (originally published in 2018)](README_QuestionDetails/BAMTANG_ExamCpp_2018.pdf):

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
El número de celdas por fila debe ser siempre 8.

##### Así por ejemplo la posición inicial del tablero de ajedrez se representa así:
##### "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR"

#### Implementar la función: drawChessBoard( initPosition )

### NOTAS:

* Usa cualquier imagen para las piezas así como la librería gráfica que prefieras, pero debes cargar y mostrar imágenes BMP, PNG o JPG en tu programa.
* No se considerarán válidas las soluciones que solo usen la consola de texto.
* Verifica que las imágenes estén ubicadas correctamente para que no hayan problemas al ejecutar tu proyecto.

<p align="center">
   
   <img src="ReadmeImgs/ChessBoard_1_1.png?raw=true">
   
   <font size="2">
      <p align="center">
         <figcaption"> Chess Board with Input: <strong>7q/2rP4/2Pn4/P2RP3/p2n4/b1K5/2pPrQ2/3k2N1</strong>
         </figcaption>
      </p>
   </font>
</p>

*******************************************************************************

### (5 PUNTOS)

*******************************************************************************
Source Code By:	 Alejandro E. Almarza Martín
*******************************************************************************

## Requirements: 

### A)	For Executing the program:

1-	Download 'SFML-2.3.2 - 32 bit' for Visual Studio C++ 2010, from:	https://www.sfml-dev.org/files/SFML-2.3.2-windows-vc10-32-bit.zip
(Main Download Page: https://www.sfml-dev.org/download/sfml/2.3.2/ )
   
2-	Copy the '...\bin''s Folder content.

3-	Look for a folder called 'Release'. Check if it has some SFML files, such as: sfml-graphics-2.dll, sfml-system-2.dll, sfml-window-2.dll, etc. 

     In case those are missing:

     Paste all the files copied in step (2) into that folder.

4-	Have all images in the same Folder as in step (3).

5-  Look for the .exe file and run it.


### B)	For Developing (Windows 7, VS C++ 2010):

1-	Install & Configure Visual Studio C++ 2010.
   
2-	Follow Step (A - (1)): Download 'SFML-2.3.2 - 32 bit' for Visual Studio C++ 2010:  https://www.sfml-dev.org/download/sfml/2.3.2/

3-	Configure Visual Studio C++ 2010 to Develop C++ Games using SFML >= 2.0 (Read: (Steps in:  https://www.sfml-dev.org/tutorials/2.3/start-vc.php ) )

4-	Decide: [Dynamic Linked Libraries (DLL) vs. Static/Shared Libraries], and set the IDE Configuration. (Steps in:  https://www.sfml-dev.org/tutorials/2.3/start-vc.php )

5-	Make sure you add to the solution the main.cpp Script, which is in the 'source' folder.

6-  Happy Coding.

*******************************************************************************

#### Notes:

#### 1- [Download: Game Programmer Exam Questions (originally published in 2018) in PDF format](README_QuestionDetails/BAMTANG_ExamCpp_2018.pdf).

#### 2- [Bamtang Games' current Game Programmer Exam, as reference (it might have changed)](https://www.bamtang.com/jobs/game-programmer).

*******************************************************************************

MIT License

Copyright (c) 2020 AlMartson

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

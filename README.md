# Sistema de matriculas

Un sistema de matriculas en c++ usando ncurses para la consola, y sqlite para guardar la
información.

## Instalación para linux

Para poder compilar este proyecto deberias tener instalado 3 dependencias que son: 

1. ncurses
2. sqlite
3. boost

Si se desea comprobar que todas librerias estan instaladas, ejecute todos los comandos:

	ls /usr/include/ncurses.h
	ls /usr/include/menu.h
	ls /usr/include/sqlite3.h
	ls /usr/include/boost/format.hpp

Si todos los comandos le devolvieron la ubicacion del archivo, la instalacion de las 
dependencias esta completa, si no es el caso, deberia consultar en "Google" como 
instalar las 3 dependencias correctamente en su distribución.

## Compilación

	g++ *.cc -o binary -lcurses -lmenu -lsqlite3

## Ejecución

	rm data.db
	touch data.db
	sqlite3 data.db < sqlite3.sql

Los comandos anteriores solo se deberan ejecutar una vez, ya que la información se almacena
en "data.db". Lo menciono por que puede haber alguien que los ejecute en cada lanzamiento de
la aplicación.

	./binary

Todo esto deberia de hacerse en la misma carpeta del proyecto, si desea mover el binario
deberia de hacerlo junto con "data.db".

## Instalación para Windows

El unico problema ahora para que funcione en Windows, es la libreria ncurses que por lo
que he investigado no tiene soporte. Bueno si, pero se deberia instalar MSYS2 para poder 
compilarlo y ejecutarlo.

Proximamente video para la instalación en Windows ... 

## Agregados opcionales

Si desean agregar un login al sistema, pues solo revicen el codigo es facil implementarlo
usando la clase "Form".


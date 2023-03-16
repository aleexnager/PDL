# Compilador de JavaScript-PdL

## Compilador programado en C

### Autores:
- Alejandro Náger Fernández-Calvo (a.nager@alumnos.upm.es)
- Diego Vignerón Olmos (d.vigneron@alumnos.upm.es)
- Marco Ciccalè Baztán (m.ciccale@alumnos.upm.es)

## Estructura:
- ***Analizador Léxico***
- ***Analizador Sintáctico***
- ***Analizador Semántico***
- ***Tabla de Símbolos***

## Manual de usuario:
[Manual de usuario](/docs/TS2006%20-%20Manual%20de%20usuario.pdf)  
Para hacer uso del Makefile es importante crear los directorios; `bin, build, lib`
```
$ mkdir bin build lib
```

## Ejecución:
Con el script program.sh podemos ejecutar el programa con cualquier fichero del directorio `./data/input`
```
$ ./program.sh file
```
## Ver los resultados de la ejecución
Con el script cat.sh podremos ver cualquiera de los ficheros del directorio `./data/output/`
```
$ ./cat.sh token.txt
$ ./cat.sh ts.txt
$ ./cat.sh error.txt
$ ./cat.sh parse.txt
```

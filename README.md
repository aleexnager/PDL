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
[Manual de usuario](/docs/TS2006 - Manual de usuario.pdf)
```
$ git pull https://github.com/mciccale/pdl-project.git
$ mkdir bin build lib
```

## Ejecución:
```
$ ./bin/run ./data/input/[your-file]
```
## Ver los resultados de la ejecución
```
$ cat ./data/output/token.txt
$ cat ./data/output/tabla_simbolos.txt
$ cat ./data/output/error.txt
```

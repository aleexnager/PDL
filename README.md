# Compilador de JavaScript-PdL

## Compilador programado en C

### Autores:
- Alejandro Nager Fernandez-Calvo (a.nager@alumnos.upm.es)
- Diego Vignerón Olmos (d.vigneron@alumnos.upm.es)
- Marco Ciccalè Baztán (m.ciccale@alumnos.upm.es)

## Estructura:
- ***Analizador Léxico***
- ***Analizador Sintáctico***
- ***Analizador Semántico***
- ***Tabla de Símbolos***

## Manual de usuario:
1. git pull https://github.com/mciccale/pdl-project.git
2. mkdir bin build

## Ejecución:
1. ./bin/run ./data/input/[your-file]
2. Para ver los resultados de la ejecución
	1. cat ./data/output/token.txt
	2. cat ./data/output/tabla_simbolos.txt
	3. cat ./data/output/error.txt

# Clang
# Introducción a clang-AST

## RIASC Universidad de León.
Flavio Rodrigues Dias.
Camino Fernández Llamas.
Gonzalo Esteban Costales.
Razvan Raducu. 

Este proyecto contiene dos ejemplos diferentes sobre cómo utilizar clang: dos con LibTooling. En los dos casos el ejemplo imprime cierta información (número de línea y de columna) cada vez que se realiza una llamada a una función denominada "doSomething". Todos los ejemplos se pueden compilar de dos maneras: (1) utilizando CMake o (2) compilando manualmente el ejemplo.

## Tutorial: libToolingRecursiveASTVisitor/example2 

http://clang.llvm.org/docs/RAVFrontendAction.html

## Compilación

### CMake

En el caso de usar CMake es necesario modificar el fichero *CMakeLists.txt* para sustituir, en las líneas correspondientes, el fichero que se desea compilar. A continuación se deberán introducir los siguientes comandos:

```
export CXX=/usr/local/bin/clang++
cd src/libToolingASTMatchers/example1
mkdir -p build
cd build
cmake ..
make
```

### Compilación manual

En todos los casos habrá que sustituir *nombre_fichero_ejemplo* por el fichero correspondiente. Previamente, crearemos un directorio para almacenar los ficheros ejecutables:

```
mkdir -p bin
```

#### LibTooling

```
clang++ $(llvm-config --cxxflags --ldflags) nombre_fichero_ejemplo.cpp \
-lclangTooling -lclangFrontendTool -lclangFrontend -lclangDriver \
-lclangSerialization -lclangParse -lclangSema -lclangStaticAnalyzerCheckers \
-lclangStaticAnalyzerCore -lclangAnalysis -lclangRewriteFrontend -lclangEdit \
-lclangASTMatchers -lclangAST -lclangLex -lclangBasic -lclang \
$(llvm-config --libs --system-libs) -o ./bin/nombre_fichero_ejemplo
```

#### LibClang

```
clang++ nombre_fichero_ejemplo.cpp -std=c++11 -g \
-I/usr/local/include/llvm -L/usr/local/lib -lclang \
-o ./bin/nombre_fichero_ejemplo
```

### Ejecución

src/libToolingASTMatchers/example1  
src/libToolingRecursiveASTVisitor/example1
```
../bin/nombre_fichero_ejemplo ../../../../input/example_2.cpp

```
src/libToolingRecursiveASTVisitor/example2

```
../bin/nombre_fichero_ejemplo "namespace n { namespace m { class C {}; } }"

```

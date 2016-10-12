#ifndef GLOBALS_H
#define GLOBALS_H

QT_BEGIN_NAMESPACE
class QString;
class QStringList;
QT_END_NAMESPACE


/* Variable que almacena la primera linea de un filtro en txt y es la que me define que tipo
 * de filtro es, es decir, si la primera linea contiene la palabra average, puedo concluir que es
 * un filtro promedio
 */
extern QString firstLineFilterTxt;

/* Variables de tipo QStringList que contiene los valores por defecto
 * del filtro promedio y el filtro gaussiano
 */
extern QStringList listAverage;
extern QStringList listGaussiano;
/* Variables de tipo matriz que me van a almacenar los datos que tenga un archivo
 * txt correspondiente para cada matriz 3x3 5x5 7x7 9x9
 */
extern int kernelThree [3][3];
extern int kernelFive  [5][5];
extern int kernelSeven [7][7];
extern int kernelNine  [9][9];
/* variable que cambia al seleccionar un kernel por default,
 * esta variable controla el estado de la aplicacion respecto al manejo de filtros,
 * ya que por medio de esta, sé que filtro aplico
 */
extern int selectFilter;

// Almaceno el tamano del kernel, si es 0 trabaja con el kernel default de [3][3]
extern int sizeList;

// Almaceno el numero sigma que ingresa el usuario
extern int numberSigma;

// Arreglo que contiene los valores del histograma
extern int histogramaT[];
extern int histogramaR[];
extern int histogramaG[];
extern int histogramaB[];

// variable que me almacena el canal del histrograma que quiero que me muestre
extern int selectChannelHistograma;

// variable que me almacena la constante para poder aplicar las operaciones elementales del histograma
extern double numberOperationsHistograma;

#endif // GLOBALS_H

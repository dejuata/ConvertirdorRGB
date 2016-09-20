#ifndef GLOBALS_H
#define GLOBALS_H

QT_BEGIN_NAMESPACE
class QString;
//class QStringList;
QT_END_NAMESPACE

/* QString que contiene por defecto los valores del kernel promedio
 * y el kernel gaussiano, estos son posteriormente convertidos en variables de
 * tipo QStringList para poder imprimir los valores en la cuadricula de la ventana
 * settingfilter.ui, para aplicar cada kernel estos QStringList son convertidos en una matriz
 * de 3x3 por medio de la función createMatriz que se encuentra en el archivo filter.h
 */

extern QString demo;

//extern QStringList listAverage;
//extern QStringList listgaussiano;

/* variable que cambia al seleccionar un kernel por default,
 * esta variable controla el estado de la aplicacion respecto al manejo de filtros,
 * ya que por medio de esta, sé que filtro aplico
 */
//extern int selectFilter = 0;



#endif // GLOBALS_H

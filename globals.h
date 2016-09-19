#ifndef GLOBALS_H
#define GLOBALS_H

// ALL THE GLOBAL DECLARATIONS

// don't use #include <QString> here, instead do this:
//#include <QImage>;
QT_BEGIN_NAMESPACE
class QImage;
QT_END_NAMESPACE

// Note the important use of extern!
extern QImage imageT;
//extern QString g_some_string;

#endif // GLOBALS_H

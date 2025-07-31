#include <QDebug>
#include "cppclass.hpp"

CppClass::CppClass(QObject *parent): QObject{parent} {
    _vector.append("One");
    _vector.append("Two");
    _vector.append("Three");
    _vector.append("Four");
}

void CppClass::qmlArrayToCpp(const QVector<QString> &vec) {
    foreach (const QString &elem, vec) {
        qDebug() << elem;
    }
}

QVector<QString> CppClass::retrieveStrings() const {
    return _vector;
}

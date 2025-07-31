#ifndef CPPCLASS_HPP
#define CPPCLASS_HPP

#include <QString>
#include <QVector>
#include <QObject>
#include <QtQml/qqmlregistration.h>

class CppClass : public QObject
{
    Q_OBJECT
public:
    explicit CppClass(QObject *parent = nullptr);

    Q_INVOKABLE void qmlArrayToCpp(const QVector<QString> &vec);
    Q_INVOKABLE QVector<QString> retrieveStrings() const;
signals:

private:
    QVector<QString> _vector;
};

#endif // CPPCLASS_HPP

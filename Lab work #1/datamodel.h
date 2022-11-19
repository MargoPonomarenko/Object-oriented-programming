#ifndef DATAMODEL_H
#define DATAMODEL_H

#include <QObject>

class DataModel : public QObject
{
    Q_OBJECT

    int value = 0;

public:
    explicit DataModel(QObject *parent = nullptr);

    void setValue(int newValue);

signals:
    void valueChanged(int value);

};

#endif // DATAMODEL_H

#include "datamodel.h"

void DataModel::setValue(int newValue)
{
    value = newValue;
    emit valueChanged(value);
}

DataModel::DataModel(QObject *parent)
    : QObject{parent}
{

}

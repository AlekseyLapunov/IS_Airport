#include "databases.h"

DataBases::DataBases()
{
    dataBasesFolder.exists();
}

void DataBases::checkForDir()
{
    if(!dataBasesFolder.exists("Data Bases"))
    {
        this->makeDir();
        return;
    }
    else return;
}

bool DataBases::find(string login, string password, User *user)
{
    return true;
}

void DataBases::makeDir()
{
    // Создаёт папку с базами данных
    dataBasesFolder.mkdir("Data Bases");
}

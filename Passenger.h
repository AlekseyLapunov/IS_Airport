#ifndef PASSENGER_H
#define PASSENGER_H

#include <string>
#include <User.h>
#include <QString>

/*!
 * \brief Класс Пассажира
 *
 * Содержит информацию: ФИО, Паспортные данные
 * Является наследником класса User
 */
class Passenger : public User
{
private:
    //! Поле ФИО
    QString fullName;
    //! Поле паспорта
    string passportInfo;

public:
    Passenger();
    //! Специализированный конструктор
    Passenger(QString sFullName, string sPassportInfo, int ID);
    //! Функция возвращает исправленную строку ФИО (сопоставление регистров)
    static QString fixFullName(QString sFullName);
    //! Функция возвращает ФИО пассажира
    QString getFullName();
    //! Функция возвращает паспортные данные пассажира
    QString getPassport();
    /*!
     * \brief Функция устанавливает логин для пассажира
     * \param sLogin Устанавливаемый логин
     */
    void setLogin(std::string sLogin);
    /*!
     * \brief Функция устанавливает пароль для пассажира
     * \param sPassword Устанавливаемый пароль
     */
    void setPassword(std::string sPassword);
};

#endif // PASSENGER_H

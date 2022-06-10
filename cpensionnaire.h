#ifndef CPENSIONNAIRE_H
#define CPENSIONNAIRE_H

#include <QMainWindow>

class CPensionnaire {
    private:
        int m_Id;
        QString m_Type;
        QString m_Race;
        int m_Portee;
        int m_Puce;
        QString m_Photo;
        QString m_Vermifuge;
        QString m_Date;
        QString m_Name;
        int m_Vaccins;
        double m_Prix;

    public:
        CPensionnaire() {}
        ~CPensionnaire() {}

        CPensionnaire(int Id, QString Type, QString Race, int Portee, int Puce, QString Photo, QString Vermifuge, QString Date, QString Name, int Vaccins, double Prix) {
            this->m_Id = Id;
            this->m_Type = Type;
            this->m_Race = Race;
            this->m_Portee = Portee;
            this->m_Puce = Puce;
            this->m_Photo = Photo;
            this->m_Vermifuge = Vermifuge;
            this->m_Date = Date;
            this->m_Name = Name;
            this->m_Vaccins = Vaccins;
            this->m_Prix = Prix;
        }

        int GetId() {
            return (this->m_Id);
        }

        QString GetType() {
            return (this->m_Type);
        }

        QString GetRace() {
            return (this->m_Race);
        }

        int GetPortee() {
            return (this->m_Portee);
        }

        int GetPuce() {
            return (this->m_Puce);
        }

        QString GetPhoto() {
            return (this->m_Photo);
        }

        QString GetVermifuge() {
            return (this->m_Vermifuge);
        }

        QString GetDate() {
            return (this->m_Date);
        }

        QString GetName() {
            return (this->m_Name);
        }

        int GetVaccins() {
            return (this->m_Vaccins);
        }

        double GetPrix() {
            return (this->m_Prix);
        }

        void SetId(int Id) {
            this->m_Id = Id;
        }

        void SetType(QString Type) {
            this->m_Type = Type;
        }

        void SetRace(QString Race) {
            this->m_Race = Race;
        }

        void SetPortee(int Portee) {
            this->m_Portee = Portee;
        }

        void SetPuce(int Puce) {
            this->m_Puce = Puce;
        }

        void SetPhoto(QString Photo) {
            this->m_Photo = Photo;
        }

        void SetVermifuge(QString Vermifuge) {
            this->m_Vermifuge = Vermifuge;
        }

        void SetDate(QString Date) {
            this->m_Date = Date;
        }

        void SetName(QString Name) {
            this->m_Name = Name;
        }

        void SetVaccins(int Vaccins) {
            this->m_Vaccins = Vaccins;
        }

        void SetPrix(double Prix) {
            this->m_Prix = Prix;
        }
};

#endif // CPENSIONNAIRE_H

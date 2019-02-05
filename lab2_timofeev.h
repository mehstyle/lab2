#ifndef LAB2_TIMOFEEV_H
#define LAB2_TIMOFEEV_H
#include <QMainWindow>
#include"country.h"
#include <windows.h>


namespace Ui {
class lab2_Timofeev;
}

class lab2_Timofeev : public QMainWindow
{
    Q_OBJECT

public:
    explicit lab2_Timofeev(QWidget *parent = 0);
    ~lab2_Timofeev();

    //Создаем массив объектов стран
    Country countries[100];
    bool isEditing=false;
    bool isNewRecord=false;
    bool isReverseSort=false;


public slots:
    void on_btnSave_clicked();

    void on_btnCancel_clicked();

public:
    Ui::lab2_Timofeev *ui;
    int counter;
    int idCounter;
    void doBrowser();
    void doSort();
    void SetGrpboxEnabled();
    void SetGrpboxDisabled();
    void doReverseSort();


    void LoadFromFile();
    void SaveToFile();
    void WriteQString(HANDLE file, QString what);
    int qstrToChar(QString source, char res[100]);
    void ReadQString(HANDLE file, QString &what);


private slots:


    void on_rdbEurope_clicked();
    void on_rdbAsia_clicked();
    void on_rdbAfrica_clicked();
    void on_rdbAustralia_clicked();
    void on_rdbN_Am_clicked();
    void on_rdbS_Am_clicked();
    void on_spnPopulation_valueChanged();
    void on_btnDelete_clicked();
    void on_btnCreate_clicked();
    void on_btnEdit_clicked();
    void on_btn_fill_clicked();

    void on_tbl_browser_itemSelectionChanged();

    void on_btnReverse_clicked();
};



#endif // LAB2_TIMOFEEV_H

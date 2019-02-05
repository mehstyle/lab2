#include "lab2_timofeev.h"
#include "ui_lab2_timofeev.h"
#include "country.h"
#include "val_capital.h"
#include "val_name.h"
#include <QObject>
#include "qdatetimeedit.h"
#include <windows.h>

lab2_Timofeev::lab2_Timofeev(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::lab2_Timofeev)
{
    QValidator *val_n=new val_name();
    QValidator *val_c=new val_capital();

    ui->setupUi(this);

    ui->txtName->setValidator(val_n);
    ui->txtCapital->setValidator(val_c);
    ui->dtMembership->setMaximumDate(QDate::currentDate());
    ui->rdbEurope->setChecked(true);
    counter=0;
    idCounter=0;

    LoadFromFile();
    doBrowser();

}

lab2_Timofeev::~lab2_Timofeev()
{
    SaveToFile();
    delete ui;
}



//Временная переменная для хранения значения из радио баттонов
Country::World temp_rdb=Country::undefined;

void lab2_Timofeev::on_rdbEurope_clicked()
{
    temp_rdb=Country::Europe;
}

void lab2_Timofeev::on_rdbAsia_clicked()
{
    temp_rdb=Country::Asia;
}

void lab2_Timofeev::on_rdbAfrica_clicked()
{
   temp_rdb=Country::Africa;
}

void lab2_Timofeev::on_rdbAustralia_clicked()
{
   temp_rdb=Country::Australia;
}

void lab2_Timofeev::on_rdbN_Am_clicked()
{
   temp_rdb=Country::North_America;
}

void lab2_Timofeev::on_rdbS_Am_clicked()
{
    temp_rdb=Country::South_America;
}





void lab2_Timofeev::on_spnPopulation_valueChanged()
{
    if(this->ui->spnPopulation->value() > 999999)
    {
        this->ui->spnSize->setMinimum(1000);
    }
    else
    {
        this->ui->spnSize->setMinimum(10);
    }
}





void lab2_Timofeev::on_btnSave_clicked()
{
    //Сохраняем значения, полученные из полей ввода в переменные объектов
    countries[ui->tbl_browser->currentRow()].NameOfCountry = this->ui->txtName->text();
    countries[ui->tbl_browser->currentRow()].NameOfCapital = this->ui->txtCapital->text();
    countries[ui->tbl_browser->currentRow()].Population = this->ui->spnPopulation->value();
    countries[ui->tbl_browser->currentRow()].Area = this->ui->spnSize->value();

    countries[ui->tbl_browser->currentRow()].continents=temp_rdb;

    //Если установлена галочка в поле "член ООН", активируем поля с датой и т.д
    if(this->ui->grpbox_UN->isChecked())
    {
        countries[ui->tbl_browser->currentRow()].isUN=true;
        countries[ui->tbl_browser->currentRow()].MembershipDate=this->ui->dtMembership->date();
        countries[ui->tbl_browser->currentRow()].isConstUN=this->ui->checkIsConst->isChecked();
    }
    else
    {
          countries[ui->tbl_browser->currentRow()].isUN=false;
          countries[ui->tbl_browser->currentRow()].isConstUN=false;
    }
    SetGrpboxDisabled();
    doSort();
    doBrowser();
    isEditing=false;
    isNewRecord=false;
}

void lab2_Timofeev::on_btnCancel_clicked()
{
   if(isNewRecord)
   {
       counter--;
       doSort();
       doBrowser();
   }
   else
   {
       on_tbl_browser_itemSelectionChanged();
   }
   isEditing=false;
   isNewRecord=false;
   SetGrpboxDisabled();
}

void lab2_Timofeev::on_btnDelete_clicked()
{
    int tmpSelectedRow=ui->tbl_browser->currentRow();
    for(int i=tmpSelectedRow; i<99;i++)
    {
        if(i>=0){
            countries[i].NameOfCountry=countries[i+1].NameOfCountry;
            countries[i].NameOfCapital= countries[i+1].NameOfCapital;
            countries[i].Population=countries[i+1].Population;
            countries[i].Area=countries[i+1].Area;
            countries[i].continents=countries[i+1].continents;
            countries[i].isUN=countries[i+1].isUN;
            countries[i].isConstUN=countries[i+1].isConstUN;
            countries[i].MembershipDate=countries[i+1].MembershipDate;
            countries[i].id=countries[i+1].id;
        }
    }
    if(counter != 0){
        counter--;
    }
    doBrowser();
    ui->tbl_browser->selectRow(tmpSelectedRow);

}

void lab2_Timofeev::on_btnCreate_clicked()
{
    isNewRecord=true;
    countries[counter].id=idCounter;
    idCounter++;
    counter++;
    doBrowser();
    ui->tbl_browser->selectRow(counter-1);
    on_btnEdit_clicked();


}

void lab2_Timofeev::on_btnEdit_clicked()
{
    if(!isEditing)
      {
        isEditing=true;
        if(ui->tbl_browser->currentRow()>=0)
        {
            SetGrpboxEnabled();
        }
      }
}

void lab2_Timofeev::on_btn_fill_clicked()
{

    for(int i=0; i<10; i++)
    {
        QString tmp1;
        tmp1.setNum(counter);
        tmp1="Страна "+tmp1;

        QString tmp2;
        tmp2.setNum(counter);
        tmp2="Столица "+tmp2;

        countries[counter].NameOfCountry=tmp1;
        countries[counter].NameOfCapital=tmp2;
        countries[counter].Population=rand()% 4000;
        countries[counter].Area=rand()% 100000;
        switch (rand()% 6)
             {
                case 0:
                   countries[counter].continents=Country::Europe;
                   break;
                case 1:
                   countries[counter].continents=Country::Asia;
                   break;
                case 2:
                   countries[counter].continents=Country::Africa;
                   break;
                case 3:
                   countries[counter].continents=Country::Australia;
                   break;
                case 4:
                   countries[counter].continents=Country::North_America;
                   break;
                case 5:
                   countries[counter].continents=Country::South_America;
                   break;
            }
        if(rand()%2==0)
        {
            countries[counter].isUN=true;
        }
        else
        {
            countries[counter].isUN=false;
        }
        if(countries[counter].isUN)
        {
            QDate temp(rand()% 50 + 1945,rand()% 7 + 1,rand()% 15 + 1);
            countries[counter].MembershipDate=temp;
            if(rand()%2==1)
            {
                countries[counter].isConstUN=true;
            }

        }
       countries[counter].id=idCounter;
       counter++;
       idCounter++;
    }
    doSort();
    doBrowser();

}







void lab2_Timofeev::doBrowser ()
{
    ui->tbl_browser->setColumnCount(6);
    ui->tbl_browser->setColumnHidden(0,1);
   // ui->tbl_browser->setColumnHidden(5,1);
    if(counter!=0)
    {
        ui->tbl_browser->setRowCount(counter);
        for(int i=0; i<=counter; i++)
        {
            QString temp;
            temp.setNum(countries[i].Population);
            QString temp2;
            temp2.setNum(countries[i].Area);
            QString temp3;
            temp3.setNum(countries[i].id);
            ui->tbl_browser->setItem(i,0,new QTableWidgetItem(temp3));
            ui->tbl_browser->setItem(i,1,new QTableWidgetItem(countries[i].NameOfCountry));
            ui->tbl_browser->setItem(i,2,new QTableWidgetItem(countries[i].NameOfCapital));
            ui->tbl_browser->setItem(i,3,new QTableWidgetItem(temp + " т.ч."));
            ui->tbl_browser->setItem(i,4,new QTableWidgetItem(temp2 + " кв.км."));
            QString tmp;
            tmp.setNum(countries[i].continents);
            ui->tbl_browser->setItem(i,5,new QTableWidgetItem(tmp));
        }
    }
    else
    {
        ui->tbl_browser->clear();
    }
 }

void lab2_Timofeev::on_tbl_browser_itemSelectionChanged()
{
    int tmpID = ui->tbl_browser->currentRow();
    ui->txtName->setText(countries[tmpID].NameOfCountry);
    ui->txtCapital->setText(countries[tmpID].NameOfCapital);
    ui->spnPopulation->setValue(countries[tmpID].Population);
    ui->spnSize->setValue(countries[tmpID].Area);

    //Устанавливаем значение радио баттона, сохранённое в памяти
    switch ( countries[tmpID].continents )
         {
            case Country::Europe:
               this->ui->rdbEurope->setChecked(true);
               break;
            case Country::Asia:
               this->ui->rdbAsia->setChecked(true);
               break;
            case Country::Africa:
               this->ui->rdbAfrica->setChecked(true);
               break;
            case Country::Australia:
               this->ui->rdbAustralia->setChecked(true);
               break;
            case Country::North_America:
               this->ui->rdbN_Am->setChecked(true);
               break;
            case Country::South_America:
               this->ui->rdbS_Am->setChecked(true);
               break;
            case Country::undefined:
               break;
        }

    //Устанавливаем значение для галки "членство в ООН", сохранённое в памяти
    if(countries[tmpID].isUN)
    {
        this->ui->grpbox_UN->setChecked(true);
        //Выставляем дату
        this->ui->dtMembership->setDate(countries[tmpID].MembershipDate);
        //Выставляем или убираем галку постоянного члена совбеза оон
        if(countries[tmpID].isConstUN)
        {
            this->ui->checkIsConst->setChecked(true);
        }
        else
        {
            this->ui->checkIsConst->setChecked(false);
        }
    }
    else
    {
        this->ui->grpbox_UN->setChecked(false);
        QDate asd;
        asd.setDate(2000,01,01);
        this->ui->dtMembership->setDate(asd);
        this->ui->checkIsConst->setChecked(false);
    }

    if(isEditing)
       {
           SetGrpboxDisabled();
           isEditing=false;
       }
}

void lab2_Timofeev::SetGrpboxDisabled()
{
    ui->grpbox_names->setEnabled(false);
    ui->grpbox_cnt->setEnabled(false);
    ui->grpbox_btns->setEnabled(false);
    ui->grpbox_UN->setEnabled(false);
}

void lab2_Timofeev::SetGrpboxEnabled()
{
    ui->grpbox_names->setEnabled(true);
    ui->grpbox_cnt->setEnabled(true);
    ui->grpbox_btns->setEnabled(true);
    ui->grpbox_UN->setEnabled(true);
}

void lab2_Timofeev::doSort()
{
   Country temp;
   bool ischanged=true;
   while(ischanged)
   {
        ischanged=false;
        for(int i=0; i < counter-1;i++)
        {
        if(countries[i+1] > countries[i])
        {
            temp.NameOfCountry=countries[i].NameOfCountry;
            temp.NameOfCapital= countries[i].NameOfCapital;
            temp.Population=countries[i].Population;
            temp.Area=countries[i].Area;
            temp.continents=countries[i].continents;
            temp.isUN=countries[i].isUN;
            temp.isConstUN=countries[i].isConstUN;
            temp.MembershipDate=countries[i].MembershipDate;
            temp.id=countries[i].id;

            countries[i].NameOfCountry=countries[i+1].NameOfCountry;
            countries[i].NameOfCapital= countries[i+1].NameOfCapital;
            countries[i].Population=countries[i+1].Population;
            countries[i].Area=countries[i+1].Area;
            countries[i].continents=countries[i+1].continents;
            countries[i].isUN=countries[i+1].isUN;
            countries[i].isConstUN=countries[i+1].isConstUN;
            countries[i].MembershipDate=countries[i+1].MembershipDate;
            countries[i].id=countries[i+1].id;

            countries[i+1].NameOfCountry=temp.NameOfCountry;
            countries[i+1].NameOfCapital= temp.NameOfCapital;
            countries[i+1].Population=temp.Population;
            countries[i+1].Area=temp.Area;
            countries[i+1].continents=temp.continents;
            countries[i+1].isUN=temp.isUN;
            countries[i+1].isConstUN=temp.isConstUN;
            countries[i+1].MembershipDate=temp.MembershipDate;
            countries[i+1].id=temp.id;

            ischanged=true;
        }
        }
    }
   isReverseSort=false;
}

void lab2_Timofeev::doReverseSort()
{
   Country temp;
   bool ischanged=true;
   while(ischanged)
   {
        ischanged=false;
        for(int i=0; i < counter-1;i++)
        {
        if(countries[i+1] < countries[i])
        {
            temp.NameOfCountry=countries[i].NameOfCountry;
            temp.NameOfCapital= countries[i].NameOfCapital;
            temp.Population=countries[i].Population;
            temp.Area=countries[i].Area;
            temp.continents=countries[i].continents;
            temp.isUN=countries[i].isUN;
            temp.isConstUN=countries[i].isConstUN;
            temp.MembershipDate=countries[i].MembershipDate;
            temp.id=countries[i].id;

            countries[i].NameOfCountry=countries[i+1].NameOfCountry;
            countries[i].NameOfCapital= countries[i+1].NameOfCapital;
            countries[i].Population=countries[i+1].Population;
            countries[i].Area=countries[i+1].Area;
            countries[i].continents=countries[i+1].continents;
            countries[i].isUN=countries[i+1].isUN;
            countries[i].isConstUN=countries[i+1].isConstUN;
            countries[i].MembershipDate=countries[i+1].MembershipDate;
            countries[i].id=countries[i+1].id;

            countries[i+1].NameOfCountry=temp.NameOfCountry;
            countries[i+1].NameOfCapital= temp.NameOfCapital;
            countries[i+1].Population=temp.Population;
            countries[i+1].Area=temp.Area;
            countries[i+1].continents=temp.continents;
            countries[i+1].isUN=temp.isUN;
            countries[i+1].isConstUN=temp.isConstUN;
            countries[i+1].MembershipDate=temp.MembershipDate;
            countries[i+1].id=temp.id;

            ischanged=true;
        }
        }
    }
   isReverseSort=true;
}

void lab2_Timofeev::on_btnReverse_clicked()
{
    if(isReverseSort){
        doSort();
        doBrowser();
    }
    else{
        doReverseSort();
        doBrowser();
    }
}



void lab2_Timofeev::LoadFromFile() // загрузка файла при открытии
{
    //открыть файл с заданым именем, удалив предыдущее содержимое
    DWORD dwCreate = OPEN_ALWAYS; // в переменную dwCreate передается значение ВСЕГДА ОТКРЫВАТЬ, а не создавать новый
    DWORD bytesWrited; // перменная в которую записывается количество байт, которое было записанно функцией writeFile()
    HANDLE CountriesData = CreateFile(L"Countries.txt", GENERIC_READ | GENERIC_WRITE, NULL, NULL, dwCreate, FILE_ATTRIBUTE_NORMAL, NULL);

    //Считать из файла текущее кол-во записей в базе
    ReadFile(CountriesData,&counter,sizeof(int),&bytesWrited,0);

    // Считываем  все записи из  нашего файла в форму qt
    for (int i = 0; i < counter; i++)
    {
        // Теперь записываем в тектосвый файл все возможные поля нашей ЗАПИСИ. НЕ МОЖЕМ ЗАПИСАТЬ QSTRING пока что
        ReadFile(CountriesData, &countries[i].Population, sizeof(int), &bytesWrited, 0);
        ReadFile(CountriesData, &countries[i].Area, sizeof(int), &bytesWrited, 0);
        ReadFile(CountriesData, &countries[i].isUN, sizeof(bool), &bytesWrited, 0);
        ReadFile(CountriesData, &countries[i].isConstUN, sizeof(bool), &bytesWrited, 0);

        // Чтобы записать QString в файл нужно сначала преобразовать его в char* and -> and -> length(and) -> and
        ReadQString(CountriesData, countries[i].NameOfCountry); // Название препарата
        ReadQString(CountriesData, countries[i].NameOfCapital); // Название препарата

        // Записать QDate в файл  : 1. QDate преобразуем в QString. 2. QString записываем в текстовый файл и
        QString buf;//
        ReadQString(CountriesData, buf);
        countries[i].MembershipDate = QDate::fromString(buf);
    }

    CloseHandle(CountriesData); // После отработки ФУНКЦИИ мы закрываем файл
}

void lab2_Timofeev::SaveToFile()
{
    //открыть файл с заданым именем, удалив предыдущее содержимое
        DWORD dwCreate = OPEN_ALWAYS; // в переменную dwCreate передается значение ВСЕГДА ОТКРЫВАТЬ, а не создавать новый
        DWORD bytesWrited; // перменная в которую записывается количество байт, которое было записанно функцией writeFile()
        HANDLE CountriesData = CreateFile(L"Countries.txt", GENERIC_READ | GENERIC_WRITE, NULL, NULL, dwCreate, FILE_ATTRIBUTE_NORMAL, NULL);

        //записать в файл текущее кол-во записей в базе
        WriteFile(CountriesData,&counter,sizeof(int),&bytesWrited,0);

        // Записываем все записи в наш файл
        for (int i = 0; i < counter; i++)
        {
            // Теперь записываем в тектосвый файл все возможные поля нашей ЗАПИСИ. 
            WriteFile(CountriesData, &countries[i].Population, sizeof(int), &bytesWrited, 0);
            WriteFile(CountriesData, &countries[i].Area, sizeof(int), &bytesWrited, 0);
            WriteFile(CountriesData, &countries[i].isUN, sizeof(bool), &bytesWrited, 0);
            WriteFile(CountriesData, &countries[i].isConstUN, sizeof(bool), &bytesWrited, 0);


            // Чтобы записать QString в файл нужно сначала преобразовать его в char* and -> and -> length(and) -> and
            WriteQString(CountriesData, countries[i].NameOfCountry); 
            WriteQString(CountriesData, countries[i].NameOfCapital); 

            // Записать QDate в файл  : 1. QDate преобразуем в QString. 2. QString записываем в текстовый файл и
            WriteQString(CountriesData, countries[i].MembershipDate.toString());
         }

        CloseHandle(CountriesData); //после выгрузки информации в тектовый файл мы закрываем его
}





// Функция записывающая тип QString в текстовый файл
/*
file - куда записываем
what - что записываем
*/
void lab2_Timofeev::WriteQString(HANDLE file, QString what)
{
    DWORD dwCreate=CREATE_ALWAYS; // в переменную dwCreate передается значение ВСЕГДА ОТКРЫВАТЬ, а не создавать новый
    DWORD bytesWrited; // перменная в которую записывается количество байт, которое было записанно функцией writeFile()
    char bufStr[1000]; // промежуточная перменная В которую мы будем записывать наш QString , преобразованный в char*
    int length; // длина
    length = qstrToChar(what,bufStr); // Преобразовываем кьюСтринг в чар и эта функция возвращает количество символов в строке
    WriteFile(file,&length,sizeof(int),&bytesWrited,0); // Записываем это количество символов в файл
    WriteFile(file,&bufStr,length,&bytesWrited,0); // Записываем непосредственно сами символы в файл
}

/*
source  - исходная строка типа QSting
res - результирующая строка в формате char*
*/
int lab2_Timofeev::qstrToChar(QString source, char res[100])
{
    /* в перменную res копируем содиржимое другого аргумента фуннкции : перменную типа QString преобразовать в
    классичесикй тип STD::String при помощи метода .toStdString(), далее из этого типа преобразовываем в тип char* при помощи метода c_str()*/
    strcpy(res,source.toStdString().c_str());
    return strlen(res) + 1; // Возвращаем длину строки + 1 (тк нулевой символ)
}



// Функция считывающий  тип char* из текстового  файла в виде  QString в нашу формочку
/*
file - куда записываем
what - что записываем
*/

void lab2_Timofeev::ReadQString(HANDLE file, QString &what)
{
    int length; // длина
    DWORD bytesRead; // перменная в которую записывается количество байт, которое было считано функцией ReadFile()
    char bufStr[1000]; // промежуточная перменная В которую мы будем записывать наш char* , преобразованный в QString
    ReadFile(file,&length,sizeof(int),&bytesRead,0); // Считываем количетсво символов находящееся в файле и помещаем их в переменную length
    ReadFile(file,&bufStr,length,&bytesRead,0); // Считываем  непосредственно сами символы в файл

    // Вызываем конструктор QString
    QString buf(bufStr); // Преобразовали bufStr в QString: Счиатли стр с чариками и подали в конструктор КьюСтринга - Это преобразовало в кьюстринг
    what = buf; // Передали в вот наши кьюстринги
}







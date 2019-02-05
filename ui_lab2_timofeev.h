/********************************************************************************
** Form generated from reading UI file 'lab2_timofeev.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LAB2_TIMOFEEV_H
#define UI_LAB2_TIMOFEEV_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_lab2_Timofeev
{
public:
    QWidget *centralWidget;
    QGroupBox *grpbox_UN;
    QLabel *lbl_date_UN;
    QDateEdit *dtMembership;
    QCheckBox *checkIsConst;
    QGroupBox *grpbox_names;
    QLabel *lblArea;
    QLabel *lblCapital;
    QLineEdit *txtCapital;
    QLabel *lblPopulation;
    QLineEdit *txtName;
    QLabel *lblName;
    QSpinBox *spnPopulation;
    QSpinBox *spnSize;
    QGroupBox *grpbox_cnt;
    QRadioButton *rdbN_Am;
    QRadioButton *rdbAfrica;
    QRadioButton *rdbAsia;
    QRadioButton *rdbEurope;
    QLabel *lblWorld;
    QRadioButton *rdbAustralia;
    QRadioButton *rdbS_Am;
    QGroupBox *grpbox_btns;
    QPushButton *btnSave;
    QPushButton *btnCancel;
    QTableWidget *tbl_browser;
    QPushButton *btnCreate;
    QPushButton *btnEdit;
    QPushButton *btnDelete;
    QPushButton *btn_fill;
    QPushButton *btnReverse;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *lab2_Timofeev)
    {
        if (lab2_Timofeev->objectName().isEmpty())
            lab2_Timofeev->setObjectName(QStringLiteral("lab2_Timofeev"));
        lab2_Timofeev->setWindowModality(Qt::NonModal);
        lab2_Timofeev->resize(915, 526);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lab2_Timofeev->sizePolicy().hasHeightForWidth());
        lab2_Timofeev->setSizePolicy(sizePolicy);
        lab2_Timofeev->setCursor(QCursor(Qt::ArrowCursor));
        lab2_Timofeev->setMouseTracking(false);
        lab2_Timofeev->setFocusPolicy(Qt::NoFocus);
        lab2_Timofeev->setAutoFillBackground(false);
        centralWidget = new QWidget(lab2_Timofeev);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        grpbox_UN = new QGroupBox(centralWidget);
        grpbox_UN->setObjectName(QStringLiteral("grpbox_UN"));
        grpbox_UN->setEnabled(false);
        grpbox_UN->setGeometry(QRect(580, 250, 290, 91));
        grpbox_UN->setAutoFillBackground(true);
        grpbox_UN->setFlat(true);
        grpbox_UN->setCheckable(true);
        grpbox_UN->setChecked(false);
        lbl_date_UN = new QLabel(grpbox_UN);
        lbl_date_UN->setObjectName(QStringLiteral("lbl_date_UN"));
        lbl_date_UN->setGeometry(QRect(10, 30, 121, 21));
        dtMembership = new QDateEdit(grpbox_UN);
        dtMembership->setObjectName(QStringLiteral("dtMembership"));
        dtMembership->setGeometry(QRect(170, 30, 110, 27));
        dtMembership->setDateTime(QDateTime(QDate(2000, 1, 2), QTime(0, 0, 0)));
        dtMembership->setCalendarPopup(false);
        dtMembership->setTimeSpec(Qt::LocalTime);
        checkIsConst = new QCheckBox(grpbox_UN);
        checkIsConst->setObjectName(QStringLiteral("checkIsConst"));
        checkIsConst->setGeometry(QRect(10, 60, 261, 21));
        grpbox_names = new QGroupBox(centralWidget);
        grpbox_names->setObjectName(QStringLiteral("grpbox_names"));
        grpbox_names->setEnabled(false);
        grpbox_names->setGeometry(QRect(550, 0, 361, 81));
        grpbox_names->setAutoFillBackground(false);
        lblArea = new QLabel(grpbox_names);
        lblArea->setObjectName(QStringLiteral("lblArea"));
        lblArea->setGeometry(QRect(0, 60, 121, 17));
        lblCapital = new QLabel(grpbox_names);
        lblCapital->setObjectName(QStringLiteral("lblCapital"));
        lblCapital->setGeometry(QRect(0, 20, 67, 17));
        txtCapital = new QLineEdit(grpbox_names);
        txtCapital->setObjectName(QStringLiteral("txtCapital"));
        txtCapital->setGeometry(QRect(170, 20, 191, 21));
        lblPopulation = new QLabel(grpbox_names);
        lblPopulation->setObjectName(QStringLiteral("lblPopulation"));
        lblPopulation->setGeometry(QRect(0, 40, 131, 17));
        txtName = new QLineEdit(grpbox_names);
        txtName->setObjectName(QStringLiteral("txtName"));
        txtName->setGeometry(QRect(170, 0, 191, 21));
        lblName = new QLabel(grpbox_names);
        lblName->setObjectName(QStringLiteral("lblName"));
        lblName->setGeometry(QRect(0, 0, 121, 21));
        spnPopulation = new QSpinBox(grpbox_names);
        spnPopulation->setObjectName(QStringLiteral("spnPopulation"));
        spnPopulation->setGeometry(QRect(170, 40, 191, 21));
        spnPopulation->setMinimum(1);
        spnPopulation->setMaximum(900000000);
        spnPopulation->setSingleStep(1000);
        spnPopulation->setDisplayIntegerBase(10);
        spnSize = new QSpinBox(grpbox_names);
        spnSize->setObjectName(QStringLiteral("spnSize"));
        spnSize->setGeometry(QRect(170, 60, 191, 21));
        spnSize->setMinimum(10);
        spnSize->setMaximum(20000000);
        spnSize->setSingleStep(10000);
        grpbox_cnt = new QGroupBox(centralWidget);
        grpbox_cnt->setObjectName(QStringLiteral("grpbox_cnt"));
        grpbox_cnt->setEnabled(false);
        grpbox_cnt->setGeometry(QRect(640, 90, 171, 142));
        rdbN_Am = new QRadioButton(grpbox_cnt);
        rdbN_Am->setObjectName(QStringLiteral("rdbN_Am"));
        rdbN_Am->setGeometry(QRect(10, 100, 161, 22));
        rdbN_Am->setCursor(QCursor(Qt::PointingHandCursor));
        rdbN_Am->setAutoExclusive(true);
        rdbAfrica = new QRadioButton(grpbox_cnt);
        rdbAfrica->setObjectName(QStringLiteral("rdbAfrica"));
        rdbAfrica->setGeometry(QRect(10, 60, 91, 21));
        rdbAfrica->setCursor(QCursor(Qt::PointingHandCursor));
        rdbAfrica->setAutoExclusive(true);
        rdbAsia = new QRadioButton(grpbox_cnt);
        rdbAsia->setObjectName(QStringLiteral("rdbAsia"));
        rdbAsia->setGeometry(QRect(10, 40, 71, 21));
        rdbAsia->setCursor(QCursor(Qt::PointingHandCursor));
        rdbAsia->setAutoExclusive(true);
        rdbEurope = new QRadioButton(grpbox_cnt);
        rdbEurope->setObjectName(QStringLiteral("rdbEurope"));
        rdbEurope->setGeometry(QRect(10, 20, 91, 21));
        rdbEurope->setCursor(QCursor(Qt::PointingHandCursor));
        rdbEurope->setAutoExclusive(true);
        lblWorld = new QLabel(grpbox_cnt);
        lblWorld->setObjectName(QStringLiteral("lblWorld"));
        lblWorld->setGeometry(QRect(0, 0, 91, 17));
        rdbAustralia = new QRadioButton(grpbox_cnt);
        rdbAustralia->setObjectName(QStringLiteral("rdbAustralia"));
        rdbAustralia->setGeometry(QRect(10, 80, 101, 21));
        rdbAustralia->setCursor(QCursor(Qt::PointingHandCursor));
        rdbAustralia->setAutoExclusive(true);
        rdbS_Am = new QRadioButton(grpbox_cnt);
        rdbS_Am->setObjectName(QStringLiteral("rdbS_Am"));
        rdbS_Am->setGeometry(QRect(10, 120, 151, 22));
        rdbS_Am->setCursor(QCursor(Qt::PointingHandCursor));
        rdbS_Am->setAutoExclusive(true);
        grpbox_btns = new QGroupBox(centralWidget);
        grpbox_btns->setObjectName(QStringLiteral("grpbox_btns"));
        grpbox_btns->setEnabled(false);
        grpbox_btns->setGeometry(QRect(620, 350, 221, 31));
        btnSave = new QPushButton(grpbox_btns);
        btnSave->setObjectName(QStringLiteral("btnSave"));
        btnSave->setGeometry(QRect(0, 0, 99, 27));
        btnCancel = new QPushButton(grpbox_btns);
        btnCancel->setObjectName(QStringLiteral("btnCancel"));
        btnCancel->setGeometry(QRect(120, 0, 99, 27));
        tbl_browser = new QTableWidget(centralWidget);
        tbl_browser->setObjectName(QStringLiteral("tbl_browser"));
        tbl_browser->setGeometry(QRect(20, 0, 411, 321));
        tbl_browser->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tbl_browser->setSelectionMode(QAbstractItemView::SingleSelection);
        tbl_browser->setSelectionBehavior(QAbstractItemView::SelectRows);
        tbl_browser->setColumnCount(0);
        tbl_browser->horizontalHeader()->setVisible(false);
        tbl_browser->horizontalHeader()->setHighlightSections(false);
        tbl_browser->verticalHeader()->setVisible(false);
        tbl_browser->verticalHeader()->setHighlightSections(false);
        btnCreate = new QPushButton(centralWidget);
        btnCreate->setObjectName(QStringLiteral("btnCreate"));
        btnCreate->setGeometry(QRect(80, 350, 99, 27));
        btnEdit = new QPushButton(centralWidget);
        btnEdit->setObjectName(QStringLiteral("btnEdit"));
        btnEdit->setGeometry(QRect(140, 380, 131, 27));
        btnDelete = new QPushButton(centralWidget);
        btnDelete->setObjectName(QStringLiteral("btnDelete"));
        btnDelete->setGeometry(QRect(240, 350, 99, 27));
        btn_fill = new QPushButton(centralWidget);
        btn_fill->setObjectName(QStringLiteral("btn_fill"));
        btn_fill->setGeometry(QRect(160, 420, 99, 27));
        btnReverse = new QPushButton(centralWidget);
        btnReverse->setObjectName(QStringLiteral("btnReverse"));
        btnReverse->setGeometry(QRect(400, 370, 91, 61));
        lab2_Timofeev->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(lab2_Timofeev);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 915, 25));
        lab2_Timofeev->setMenuBar(menuBar);
        mainToolBar = new QToolBar(lab2_Timofeev);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        lab2_Timofeev->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(lab2_Timofeev);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        lab2_Timofeev->setStatusBar(statusBar);

        retranslateUi(lab2_Timofeev);

        QMetaObject::connectSlotsByName(lab2_Timofeev);
    } // setupUi

    void retranslateUi(QMainWindow *lab2_Timofeev)
    {
        lab2_Timofeev->setWindowTitle(QApplication::translate("lab2_Timofeev", "lab2_Timofeev", Q_NULLPTR));
        grpbox_UN->setTitle(QApplication::translate("lab2_Timofeev", "\320\247\320\273\320\265\320\275\321\201\321\202\320\262\320\276 \320\262 \320\236\320\236\320\235", Q_NULLPTR));
        lbl_date_UN->setText(QApplication::translate("lab2_Timofeev", "\320\224\320\260\321\202\320\260 \320\262\321\201\321\202\321\203\320\277\320\273\320\265\320\275\320\270\321\217", Q_NULLPTR));
        checkIsConst->setText(QApplication::translate("lab2_Timofeev", "\320\237\320\276\321\201\321\202\320\276\321\217\320\275\320\275\321\213\320\271 \321\207\320\273\320\265\320\275 \321\201\320\276\320\262\320\261\320\265\320\267\320\260 \320\236\320\236\320\235", Q_NULLPTR));
        grpbox_names->setTitle(QString());
        lblArea->setText(QApplication::translate("lab2_Timofeev", "\320\237\320\273\320\276\321\211\320\260\320\264\321\214 \321\201\321\202\321\200\320\260\320\275\321\213", Q_NULLPTR));
        lblCapital->setText(QApplication::translate("lab2_Timofeev", "\320\241\321\202\320\276\320\273\320\270\321\206\320\260", Q_NULLPTR));
        lblPopulation->setText(QApplication::translate("lab2_Timofeev", "\320\235\320\260\321\201\320\265\320\273\320\265\320\275\320\270\320\265 \321\201\321\202\321\200\320\260\320\275\321\213", Q_NULLPTR));
        txtName->setText(QString());
        lblName->setText(QApplication::translate("lab2_Timofeev", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \321\201\321\202\321\200\320\260\320\275\321\213", Q_NULLPTR));
        spnPopulation->setSuffix(QApplication::translate("lab2_Timofeev", " \321\202\321\213\321\201.\321\207\320\265\320\273\320\276\320\262\320\265\320\272", Q_NULLPTR));
        spnSize->setSuffix(QApplication::translate("lab2_Timofeev", " \320\272\320\262.\320\272\320\274", Q_NULLPTR));
        grpbox_cnt->setTitle(QString());
        rdbN_Am->setText(QApplication::translate("lab2_Timofeev", "\320\241\320\265\320\262\320\265\321\200\320\275\320\260\321\217 \320\220\320\274\320\265\321\200\320\270\320\272\320\260", Q_NULLPTR));
        rdbAfrica->setText(QApplication::translate("lab2_Timofeev", "\320\220\321\204\321\200\320\270\320\272\320\260", Q_NULLPTR));
        rdbAsia->setText(QApplication::translate("lab2_Timofeev", "\320\220\320\267\320\270\321\217", Q_NULLPTR));
        rdbEurope->setText(QApplication::translate("lab2_Timofeev", "\320\225\320\262\321\200\320\276\320\277\320\260", Q_NULLPTR));
        lblWorld->setText(QApplication::translate("lab2_Timofeev", "\320\247\320\260\321\201\321\202\321\214 \321\201\320\262\320\265\321\202\320\260", Q_NULLPTR));
        rdbAustralia->setText(QApplication::translate("lab2_Timofeev", "\320\220\320\262\321\201\321\202\321\200\320\260\320\273\320\270\321\217", Q_NULLPTR));
        rdbS_Am->setText(QApplication::translate("lab2_Timofeev", "\320\256\320\266\320\275\320\260\321\217 \320\220\320\274\320\265\321\200\320\270\320\272\320\260", Q_NULLPTR));
        grpbox_btns->setTitle(QString());
        btnSave->setText(QApplication::translate("lab2_Timofeev", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", Q_NULLPTR));
        btnCancel->setText(QApplication::translate("lab2_Timofeev", "\320\236\321\202\320\274\320\265\320\275\320\260", Q_NULLPTR));
        btnCreate->setText(QApplication::translate("lab2_Timofeev", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214", Q_NULLPTR));
        btnEdit->setText(QApplication::translate("lab2_Timofeev", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214", Q_NULLPTR));
        btnDelete->setText(QApplication::translate("lab2_Timofeev", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", Q_NULLPTR));
        btn_fill->setText(QApplication::translate("lab2_Timofeev", "\320\227\320\260\320\277\320\276\320\273\320\275\320\270\321\202\321\214", Q_NULLPTR));
        btnReverse->setText(QApplication::translate("lab2_Timofeev", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \n"
" \320\277\320\276\321\200\321\217\320\264\320\276\320\272\n"
"\321\201\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\272\320\270", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class lab2_Timofeev: public Ui_lab2_Timofeev {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAB2_TIMOFEEV_H

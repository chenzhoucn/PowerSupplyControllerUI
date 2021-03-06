#include "cusdialog.h"
#include "ui_cusdialog.h"

CusDialog::CusDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CusDialog)
{
    ui->setupUi(this);
}

CusDialog::CusDialog(QString msg,int type,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CusDialog)
{
    ui->setupUi(this);
    ui->label->setText(msg);
    ui->label->setAlignment(Qt::AlignCenter);
    this->setWindowFlags(Qt::Tool | Qt::WindowStaysOnTopHint |Qt::X11BypassWindowManagerHint);
    this->move(192,144);

    if(type == 1){
        ui->doneButton->setVisible(false);
        ui->rejectButton->setVisible(false);
        ui->okayButton->setVisible(true);
    }else if(type ==0 ){
        ui->doneButton->setVisible(true);
        ui->rejectButton->setVisible(true);
        ui->okayButton->setVisible(false);
    }else if(type == 3 ){
        ui->doneButton->setVisible(false);
        ui->rejectButton->setVisible(false);
        ui->okayButton->setVisible(false);
    }

    connect(ui->doneButton, SIGNAL(clicked()),this, SLOT(doneExit()));
    connect(ui->okayButton, SIGNAL(clicked()),this, SLOT(doneExit()));
    connect(ui->rejectButton, SIGNAL(clicked()),this, SLOT(rejectExit()));
}

void CusDialog::changeStyle(QString msg, int type)
{
    if(type == 1){
        ui->doneButton->setVisible(false);
        ui->rejectButton->setVisible(false);
        ui->okayButton->setVisible(true);
    }else if(type ==2 ){
        ui->doneButton->setVisible(true);
        ui->rejectButton->setVisible(true);
        ui->okayButton->setVisible(false);
    }else if(type == 3 ){
        ui->doneButton->setVisible(false);
        ui->rejectButton->setVisible(false);
        ui->okayButton->setVisible(false);
    }
    ui->label->setText(msg);
}

void CusDialog::doneExit()
{
    done(0);
}

void CusDialog::rejectExit()
{
    done(-1);
}

CusDialog::~CusDialog()
{
    delete ui;
}

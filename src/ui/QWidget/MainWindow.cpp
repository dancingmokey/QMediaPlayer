#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_bIsPlay(false),
    m_bIsPause(false)
{
    this->InitEnv();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::InitEnv(void)
{
    /** Initialize Class Members */
    this->m_bIsPlay = false;
    this->m_bIsPause = false;

    /** Initialize Class UI */
    this->ui->setupUi(this);
}

void MainWindow::on_PlayCtrlBtn_clicked()
{
    if (m_bIsPlay == true)
    {
        m_bIsPlay = false;
        this->ui->PlayCtrlBtn->setText(QString("Play"));
        m_bIsPause = true;
        this->ui->PauseCtrlBtn->setText(QString("Pause"));
    }
    else
    {
        m_bIsPlay = true;
        this->ui->PlayCtrlBtn->setText(QString("Stop"));
        m_bIsPause = true;
        this->ui->PauseCtrlBtn->setText(QString("Pause"));
    }
}

void MainWindow::on_PauseCtrlBtn_clicked()
{
    if (m_bIsPlay == true)
    {
        if (m_bIsPause == true)
        {
            m_bIsPause = false;
            this->ui->PauseCtrlBtn->setText(QString("Confinue"));
        }
        else
        {
            m_bIsPause = true;
            this->ui->PauseCtrlBtn->setText(QString("Pause"));
        }
    }
}

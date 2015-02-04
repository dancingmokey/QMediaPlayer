#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();



    /** Custom Functions */
private:
    /** Initialize Enviroment */
    /**
     * @brief InitEnv
     * @desc  Initialize Enviroment
     */
    void InitEnv(void);

    /** MainWindow UI Slots */
private slots:
    /**
     * @brief on_PlayCtrlBtn_clicked
     */
    void on_PlayCtrlBtn_clicked();

    /**
     * @brief on_PauseCtrlBtn_clicked
     */
    void on_PauseCtrlBtn_clicked();










    /** Media Player Control Variables */
private:
    /** Pause Control Variables */
    bool m_bIsPause;
    /** Play Control Variables */
    bool m_bIsPlay;








    /** MainWindow UI */
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

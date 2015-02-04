#include "ui/QWidget/MainWindow.h"
#include <QApplication>
#include <QTextCodec>
#include <QDebug>

#ifdef _ARCH_ARM
    #include <QWSDisplay>
#endif

#include "include/TestPlay.h"


int main(int argc, char *argv[])
{
    /** Start Application */
    QApplication a(argc, argv);

    /** Set Text Codec */
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());


    TestPlay* p = new TestPlay();

#ifdef _UI_WIDGET
    /** Show Main Windown */
    MainWindow w;

#ifdef _ARCH_ARM
    /** Set Mouse inVisible in Touch Screen */
    QWSServer::setCursorVisible(FALSE);

    /** Set no Top Bar Mode */
    w.setWindowFlags(w.windowFlags() & ~Qt::WindowMaximizeButtonHint & ~Qt::WindowMinimizeButtonHint & Qt::WindowCloseButtonHint);
    w.showFullScreen();
#else
    /** Show Main Window */
    w.show();
#endif
#else
    /** When UI in QML Mode, Do Noting for Now */
#endif



    return a.exec();
}

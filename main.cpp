#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}




//#include <QWebEngineView>
//#include <QEventLoop>
//#include <QVector>
//
//#include <QDebug>
//
//MainWindow::MainWindow(QWidget *parent) :
//    QMainWindow(parent),
//    ui(new Ui::MainWindow)
//{
//    ui->setupUi(this);
//    QWebEngineSettings::defaultSettings()->setAttribute(QWebEngineSettings::PluginsEnabled, true);
//
//    QWebEngineView* &view = ui->widget;
//    QWebEngineProfile *profile = QWebEngineProfile::defaultProfile();
//    page = new QWebEnginePage(profile, view);
//    view->setPage(page);
//
//    // Load page
//    this->loadPage(QUrl("http://ilcorsaronero.info/"));
//
//    ui->input_js->setText("(new XMLSerializer()).serializeToString(document.querySelector(\"\"))");
//    ui->input_search->setText("theory");
//}
//
//MainWindow::~MainWindow()
//{
//    delete ui;
//}
//
//void MainWindow::loadPage(QUrl url)
//{
//    page->setUrl(url);
//
//    // Await load url
//    QEventLoop loop;
//    connect(page, &QWebEnginePage::loadFinished, &loop, &QEventLoop::quit);
//    loop.exec();
//}
//
//QString MainWindow::runJavaScript(const QString& script)
//{
//     QString result;
//     page->runJavaScript(script, [this, &result](const QVariant &v)
//     {
//         result = v.toString();
//         emit notifyRanJavaScript();
//     });
//     QEventLoop loop_js;
//     connect(this, &MainWindow::notifyRanJavaScript, &loop_js, &QEventLoop::quit);
//     loop_js.exec();
//
//     return result;
//}
//
//QString MainWindow::serialize(QString query, int index)
//{
//    QString css = QString("document.querySelectorAll(\"%1\")[%2]").arg(query).arg(index);
//    QString cmd = QString("(new XMLSerializer()).serializeToString(%1)").arg(css);
//    return runJavaScript(cmd);
//}
//
//QString MainWindow::textContent(QString query, int index)
//{
//    QString css = QString("document.querySelectorAll(\"%1\")[%2]").arg(query).arg(index);
//    QString cmd = QString("%1.textContent").arg(css);
//    return runJavaScript(cmd);
//}
//
//void MainWindow::on_button_search_clicked()
//{
//    // Edit search-box
//    //QString search = ui->input_search->text();
//    //qDebug() << runJavaScript(page, QString ("document.getElementsByName(\"search\")[0].value = \"%1\"").arg(search));
//
//    // Simulation button click
//    //qDebug() << runJavaScript(page, QString ("document.getElementById(\"call\").getElementsByTagName(\"input\")[1].click()"));
//
//    QVector<QString> list;
//    for (int n_page = 0; true; n_page++)
//    {
//        QString url = QString("https://ilcorsaronero.info/advsearch.php?search=%1&page=%2").arg(ui->input_search->text()).arg(n_page);
//        loadPage(QUrl(url));
//        qDebug() << "-------------------" << url;
//
//        for (int element = 0; true; element++)
//        {
//            QString query = QString("document.querySelectorAll(\".odd, .odd2\")[%1]").arg(element);
//            QString info = runJavaScript(query + "querySelector(\".tab\").textContent");
//            if(info == "") break;
//            qDebug() << "Title : " << info;
//        }
//
//        QString next = serialize("#left p b a");
//        if (next == "") break;
//    }
//}
//
//void MainWindow::on_button_js_clicked()
//{
//    QString text = ui->input_js->text();
//    qDebug() << runJavaScript(QString(text));
//}

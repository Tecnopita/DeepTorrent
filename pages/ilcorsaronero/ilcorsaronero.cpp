#include "ilcorsaronero.h"

ilcorsaronero::ilcorsaronero()
{

}

void ilcorsaronero::search()
{
    QVector<QString> list;
    for (int n_page = 0; true; n_page++)
    {
        QString url = QString("https://ilcorsaronero.info/advsearch.php?search=%1&page=%2").arg(ui->input_search->text()).arg(n_page);
        loadPage(QUrl(url));
        qDebug() << "-------------------" << url;

        for (int element = 0; true; element++)
        {
            QString query = QString("document.querySelectorAll(\".odd, .odd2\")[%1]").arg(element);
            QString info = runJavaScript(query + "querySelector(\".tab\").textContent");
            if(info == "") break;
            qDebug() << "Title : " << info;
        }

        QString next = serialize("#left p b a");
        if (next == "") break;
    }
}

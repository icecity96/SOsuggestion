#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSet>
#include <QLabel>
#include <QJsonDocument>
#include <QPair>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    QJsonDocument grammarCheck(QString text);
    QPair<QString, bool> removeMd(QString text);
    double readAbility(QString text);

    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QAction *runAction;
    QAction *checkAction;

    QLabel *ResultTitle;
    QLabel *ResultQuestion;
    QLabel *synaxCheck;

    QSet<QString> key_words;

    QString APIKEY;


public slots:
    void showHeader();
    void showQuestion();
    void showCheck();

signals:


};

#endif // MAINWINDOW_H

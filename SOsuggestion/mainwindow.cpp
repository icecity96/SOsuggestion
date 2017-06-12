#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QAction>
#include <QToolBar>
#include <iostream>
#include <iostream>
#include <QtNetwork>
#include <QRegExp>
#include <QUrl>
#include <QMap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    APIKEY="OzZbpSjxGSJPdDfo";

    //初始化关键词
    key_words = {"can", "could", "help", "I", "you", "favor", "do", "question", "ask", "me",
                 "solve", "work", "out", "tell", "happend", "it", "see", "make", "good", "better", "answer", "someone", "somebody", "anyone", "have",
                 "if", "able", "a", "one"};


    //设置菜单栏格式
    this->setStyleSheet(""
                        "QMenuBar{"
                        "background-color:#EEEEE0;"
                        "}"

                        "QMenu::item{"
                        "background-color:blue;"
                        "color:black;"
                        "}");

    //全局字体
    QFont font("Source Code Pro", 9);

    //结果Label
    ResultTitle = new QLabel("just for test", this);
    ResultTitle->setFont(font);
    ResultTitle->setGeometry(QRect(QPoint(410,80), QSize(280,50)));
    ResultTitle->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;background-color:#FFE7BA;");
    ResultTitle->hide();

    ResultQuestion = new QLabel("just for test", this);
    ResultQuestion->setFont(font);
    ResultQuestion->setGeometry(QRect(QPoint(430,100), QSize(250,270)));
    ResultQuestion->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;background-color:#EEEED1;");
    ResultQuestion->hide();

    //设置工具栏格式
    runAction = new QAction(QIcon(":/images/play.png"), tr("run"), this);
    ui->toolBar->addAction(runAction);

    //输入框格式
    ui->EditTitle->setPlaceholderText("What's your questions? Be specific.");
    ui->EditQuestion->setPlaceholderText("Write your question in detail.");
    ui->EditTag->setPlaceholderText("Recommend ...");

    //连接
    connect(ui->ActionExit, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->EditTitle, SIGNAL(textChanged(QString)), this, SLOT(showHeader()));
    connect(runAction, SIGNAL(triggered(bool)), this, SLOT(showQuestion()));
    connect(ui->ActionRun, SIGNAL(triggered(bool)), this, SLOT(showQuestion()));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::showHeader() {
    ResultQuestion->hide();
    ResultTitle->show();

    QString Title = ui->EditTitle->text();
    quint32 weight = 0;
    QStringList title_list = Title.trimmed().split(" ");

    if(Title.size() < 15)
        ResultTitle->setText("Title must be at least 15 character!");
    else {
        for(QString str : title_list) {
            if(key_words.contains(str))
                weight ++;
        }

        if(weight > 3)
            ResultTitle->setText("Not specific enough!");
        else
            ResultTitle->setText("Qualified Title.");
    }

}



void MainWindow::showQuestion() {
    ResultTitle->hide();
    ResultQuestion->show();

    qint32 grammer_score = 0, offset, length;
    QMap<qint32, qint32> error_map;
    QString question = ui->EditQuestion->toPlainText();

    QJsonDocument jsonDocument = grammarCheck(question);

    //解析json
    QVariantMap single_reply;
    if (jsonDocument.isObject()) {
        QVariantMap result = jsonDocument.toVariant().toMap();

        foreach (QVariant plugin, result["errors"].toList()) {
            single_reply = plugin.toMap();
            offset = single_reply["offset"].toInt();
            length = single_reply["length"].toInt();

            if(!error_map.contains(offset))
                error_map.insert(offset, length);
            else if(error_map[offset] < length)
                error_map[offset] = length;
        }

        grammer_score = result["score"].toInt();
    }

    /*
    QMap<qint32, qint32>::iterator it;
    for(it = error_map.begin(); it != error_map.end(); ++it) {
        std::cout << it.key() << " " << it.value() << std::endl;
    }

    std::cout << grammer_score << std::endl;
    */

}

QJsonDocument MainWindow::grammarCheck(QString text) {
    QNetworkAccessManager *nwam = new QNetworkAccessManager(this);

    //查询网站
    QUrl url("https://api.textgears.com/check.php");

    //参数设置
    QUrlQuery query;
    query.addQueryItem("text",text);
    query.addQueryItem("key",APIKEY);
    url.setQuery(query.query());

    QNetworkRequest request(url);


    QNetworkReply *reply = nwam->get(request);


    //wait for the response from server

    while(!reply->isFinished()){
        qApp->processEvents();
    }

    QByteArray responseData = reply->readAll();

    QJsonDocument json = QJsonDocument::fromJson(responseData);

    //clean up the reply object

    reply->deleteLater();

    std::cout << ((QString) responseData).toStdString() << std::endl;

    return json;
}

QPair<QString, bool> MainWindow::removeMd(QString text) {
    QRegExp codeReg("```[a-z]*\n[\\s\\S]*\n```\n");

    if(codeReg.indexIn(text,0) != -1){

        text.replace(codeReg,"");
        //std::cout << text.toStdString() << std::endl;
        return QPair<QString, bool>(text, true);

    }

    return QPair<QString,bool>(text, false);
}

double MainWindow::readAbility(QString text) {
    QRegularExpression spe("[.!?,\\s]");
    QRegularExpression spe2("[.!?]");
    QStringList wordList = text.split(spe);

    QStringList sentenceList = text.split(spe2);

    if(wordList.length() < 50){
        return -1;
    }

    qint64 charCount = 0;

    for(QString word : wordList){
        charCount += word.length();
    }

    double source = 4.71*charCount/wordList.size();

    source += 0.5*wordList.size()/sentenceList.size() - 21.34;

    return source;
}

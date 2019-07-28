#include <QCoreApplication>
#include <QQueue>
#include <QDebug>
#include <iostream>
#include <QDateTime>

#include <QFile>
#include <QTextStream>
#include <QTextCodec>
#include <QDir>
#include <QString>
#include <QStack>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // 队列 先进先出 -- “FIFO”
     QQueue<int> queue;
     queue.enqueue(1);
     queue.enqueue(2);
     queue.enqueue(3);

     qInfo() << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss zzz") << QStringLiteral("Queue的header:" )<< queue.head();

     while (!queue.isEmpty())
//         std::cout << queue.dequeue(); // 显示到标准输出流（不是Creator集成的控制台）
         qDebug() << queue.dequeue();


     //堆栈 先进后出 -- “FILO”
     QStack<int> stack;
     stack.push(1);
     stack.push(2);
     stack.push(3);

     qInfo() << QString::fromLocal8Bit("stack的header:") << stack.top();

     while (!stack.isEmpty())
         qDebug() << stack.pop();

    return a.exec();
}



void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QByteArray localMsg = msg.toLocal8Bit();
    switch (type) {
    case QtDebugMsg:
        fprintf(stderr, "Debug: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        break;
    case QtInfoMsg:
        fprintf(stderr, "Info: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        break;
    case QtWarningMsg:
        fprintf(stderr, "Warning: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        break;
    case QtCriticalMsg:
        fprintf(stderr, "Critical: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        break;
    case QtFatalMsg:
        fprintf(stderr, "Fatal: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        break;
    }

    QString formatMsg = qFormatLogMessage( type, context, msg );
        if( type < 0 ) {
            return;
        }

    QDir myDir;
    QTextStream outstream;
    QFile file;
    file.setFileName( "a.txt" );
    file.open( QIODevice::WriteOnly | QIODevice::Append );
    outstream.setDevice( &file );
    outstream.setCodec( QTextCodec::codecForName("UTF-8") );

    QString absolutePath = myDir.absoluteFilePath(context.file);
    outstream << formatMsg.toLocal8Bit() << QDir::toNativeSeparators(absolutePath) << ",Line:" << context.line  << ":" << context.function << "\r\n";
    outstream.flush();
}



#if 0
//日志打印
//打印位置：控制台或者指定到文件
//实现方法有二
int main(int argc, char *argv[])
{
    qInstallMessageHandler( myMessageOutput );//方法一

//    qSetMessagePattern( "[%{time yyyyMMdd h:mm:ss.zzz t} %{if-debug}D%{endif}%{if-info}I%{endif}%{if-warning}W%{endif}%{if-critical}C%{endif}%{if-fatal}F%{endif}] %{file}:%{line} - %{message}" );//方法二
#ifdef QT_MESSAGE_PATTERN
    qSetMessagePattern(QT_MESSAGE_PATTERN);
#else
    qSetMessagePattern( "[%{time yyyyMMdd h:mm:ss.zzz t} %{if-debug}D%{endif}%{if-info}I%{endif}%{if-warning}W%{endif}%{if-critical}C%{endif}%{if-fatal}F%{endif}] %{file}:%{line} - %{message}" );
#endif

    //同时使用方法一和方法二，方法二会失效
    QCoreApplication a(argc, argv);
    QObject dobj;

    dobj.setObjectName( "Debug Test" );
    qDebug() << dobj.objectName();
    QObject wobj;
    wobj.setObjectName( "Warning Test" );
    qWarning() << wobj.objectName();
    QObject cobj;
    cobj.setObjectName( "Critical Test" );
    qCritical() << cobj.objectName();
    QObject iobj;
    iobj.setObjectName( "Info Test" );
    qInfo() << iobj.objectName();

    return a.exec();
}

#endif

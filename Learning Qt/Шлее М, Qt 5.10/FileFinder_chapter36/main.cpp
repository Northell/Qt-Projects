//Листинг 36.1-36.4 Просмотр содержимого каталога
/*
#include <QtWidgets>
#include "filefinder.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FileFinder fnd;

    fnd.show();

    return a.exec();
}
*/

//Листинг 36.5-36.7 Программа отображает изменения в каталогах, если они были во время ее работы
//Хз, мб робит, мб нет, не нашел ту самую командную строку, в которую нужно передавать пути файлов
#include <QtWidgets>
#include "viewer.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QFileSystemWatcher watcher;
    Viewer             viewer;

    QStringList args = app.arguments();
    args.removeFirst();

    watcher.addPaths(args);

    viewer.append("Watching files: " + watcher.files().join(";"));
    viewer.append("Watching dirs: "  + watcher.directories().join(";"));
    viewer.show();

    QObject::connect(&watcher, SIGNAL(directoryChanged(const QString&)),
                     &viewer,  SLOT  (slotDirectoryChanged(const QString&)));

    QObject::connect(&watcher, SIGNAL(fileChanged(const QString&)),
                     &viewer,  SLOT  (slotFileChanged(const QString&)));


    return app.exec();
}

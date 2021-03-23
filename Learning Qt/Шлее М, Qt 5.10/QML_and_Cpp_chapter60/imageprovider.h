#ifndef IMAGEPROVIDER_H
#define IMAGEPROVIDER_H

#include <QObject>
#include <QImage>
#include <QQuickImageProvider>

class ImageProvider: public QQuickImageProvider
{
private:
    QImage brightess( const QImage& imgOrig, int n);
public:
    ImageProvider();
    QImage requestImage(const QString&, QSize*, const QSize&);
};

#endif // IMAGEPROVIDER_H

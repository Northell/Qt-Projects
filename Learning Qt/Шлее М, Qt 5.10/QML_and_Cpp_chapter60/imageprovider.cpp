#include "imageprovider.h"

QImage ImageProvider::brightess(const QImage &imgOrig, int n)
{
    QImage imgTemp = imgOrig;
    quint32 nHeight = imgTemp.height();
    quint32 nWidth = imgTemp.width();

    for(quint32 y = 0; y<nHeight; ++y)
    {
        QRgb* tempLine = reinterpret_cast<QRgb*>(imgTemp.scanLine(y));
        for(quint32 x = 0; x<nWidth; ++x)
        {
            int r = qRed(*tempLine)+n;
            int g = qGreen(*tempLine) +n;
            int b = qBlue (*tempLine) + n;
            int a = qAlpha(*tempLine);

            * tempLine++ = qRgba(r>255?255:r<0?0:r,
                                 g>255?255:g<0?0:g,
                                 b>255?255:b<0?0:b,
                                 a);
        }
    }
    return imgTemp;
}

ImageProvider::ImageProvider():QQuickImageProvider(QQuickImageProvider::Image)
{

}

QImage ImageProvider::requestImage(const QString &strId, QSize *ps, const QSize &)
{QStringList lst = strId.split(";");
    bool bOk = false;
    int nBrightness = lst.last().toInt(&bOk);
    QImage img = brightess(QImage(":/" + lst.first()), nBrightness);

    if(ps)
    {
        *ps = img.size();
    }
    return img;

}

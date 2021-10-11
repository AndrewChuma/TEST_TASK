#ifndef ANIMATELABEL_H
#define ANIMATELABEL_H

#include <QObject>
#include <QLabel>
class AnimateLabel : public QLabel
{
    Q_OBJECT
    Q_PROPERTY(QColor backColor READ backColor WRITE setBackColor)
public:
    AnimateLabel(QWidget * parent = nullptr);
    QColor backColor()
    {
        return Qt::black;
    }
    void setBackColor(QColor color)
    {
        setStyleSheet(QString("background-color: rgb(%1, %2, %3);").arg(color.red()).arg(color.green()).arg(color.blue()));
    }

};

#endif // ANIMATELABEL_H

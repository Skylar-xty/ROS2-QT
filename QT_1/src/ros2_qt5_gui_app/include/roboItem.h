#ifndef ROBOITEM_H
#define ROBOITEM_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
class roboItem :public QObject,public QGraphicsItem
{
    Q_OBJECT
public:
    roboItem();
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget=nullptr) override;
    QRectF boundingRect() const override;
    void updateImage(QImage img);
    void updatePoints(QPolygonF points);
    void updateLines(QLine line);
private:
    QImage m_images;
    QPolygonF m_points;
    QLineF m_lines;
private:
    void drawLine(QPainter *painter);
};

#endif // ROBOITEM_H

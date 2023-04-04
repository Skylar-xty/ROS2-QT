#include "roboItem.h"
#include "QDebug"
roboItem::roboItem()
{

}

void roboItem::paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget){
    qDebug()<<"我被调用啦！！";
    painter->drawImage(0,0,m_images);

    painter->setPen(QPen(QColor(0,0,255),5));
    painter->drawPoints(m_points);

    drawLine(painter);
}

QRectF roboItem::boundingRect() const{

}
void roboItem::drawLine(QPainter *painter){
    painter->setPen(QPen(QColor(255,0,0),3));
    painter->drawLine(m_lines);
}
void roboItem::updatePoints(QPolygonF points){
    m_points = points;
    update();
}
void roboItem::updateImage(QImage img){
    m_images = img;
    update();
}
void roboItem::updateLines(QLine line){
    m_lines = line;
    update();
}
